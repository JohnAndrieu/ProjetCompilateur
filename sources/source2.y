%union
{
    int nb;
    char * var;
}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "asm.h"

    int yydebug = 0;
    int depth = 0;
    int constante = 0;
    char buffer[50];

    int yylex();

    int yyerror(char *e) {
        printf("error: %s\n", e);
        exit(2);
        return 1;
    }

    //Nettoyer le fichier asm.txt
    void clean_assembly () {
        FILE * file_descriptor = fopen("./asm.txt","w");
        fputs("",file_descriptor);
        fclose(file_descriptor);
    }

    //Gérer les affectations 
    void affectation(char * var,int tmpAddr){
        int varAddr  = get_var_address(var,depth);
        asm_add("COP",varAddr,tmpAddr,-1);
        set_initialized(var, depth);
    }

    //Gérer les expressions
    int expression(int addr1,char * op,int addr2){
        sprintf(buffer,"%d",get_indice_temp());
        int addr_return = push_var_temp(buffer,constante,depth);
        asm_add(op,addr_return,addr1,addr2);
        return addr_return;
    }

    //Gérer les affectations temporaires
    int affectation_tmp(int nb){ 
        sprintf(buffer,"%d",get_indice_temp());
        int tmp_addr = push_var_temp(buffer,constante,depth);
        asm_add("AFC",tmp_addr,nb,-1);
        return tmp_addr;
    }

%}


%token tMAIN tVOID tOB tOP tCB tCP tPV tVIRGULE tPOINT tINT tFLOAT tMUL tINF tELSE;
%token tBOOL tPRINTF tIF tWHILE tFOR tRETURN tCOMPARE tAFFECT tADD tMODULO tSUP;
%token tDOUBLE tSHORT tLONG tSIGNED tUNSIGNED tSTATIC tTRUE tFALSE tSUB tDIV tCONST;

%token <var> tVAR;
%token <nb> tNUMBER;

%type <nb> tIF;
%type <nb> IFBLOCK;
%type <nb> IFBLOCK1;
%type <nb> tELSE;
%type <nb> WHILEBLOCK;
%type <nb> WHILEBLOCK1;
%type <nb> tWHILE;
%type <nb> Affectation;
%type <nb> EXPRESSION;

%right '='
%left tADD tSUB
%left tMUL tDIV

%start S

%%

S: {clean_assembly();} tINT tMAIN tOP tCP tOB {depth++;} BODY tRETURN INT tPV tCB {depth--; write_print_asm(); clearUseless(depth);};

INT: tVAR
    | tNUMBER
    ;

BODY: CreateVAR BODY {}
    | Affectation BODY {}
    | tPRINTF tOP tVAR tCP tPV BODY {}
    | IFBLOCK BODY
    | WHILEBLOCK BODY
    | {}
    ;

TYPE: tINT {constante = 0;} 
    | tBOOL {constante = 0;} 
    | tFLOAT {constante = 0;} 
    | tDOUBLE {constante = 0;} 
    | tCONST {constante = 1;}
    ;

CreateVAR: TYPE tVAR tPV { push_var($2,constante,depth); }
    | TYPE tVAR tAFFECT tNUMBER tPV { push_var($2,constante,depth); affectation($2,$4); }  
    | TYPE tVAR { push_var($2,constante,depth); } tVIRGULE SuiteVar
    ;

SuiteVar: tVAR { push_var($1,constante,depth); } tVIRGULE SuiteVar 
    | tVAR tPV { push_var($1,constante,depth); }
    ;

Affectation: tVAR tAFFECT EXPRESSION tPV 
                { 
                    affectation($1,$3); 
                    clear_var_temp();
                }
                ;

IFBLOCK:
    IFBLOCK1
        {
            modify_asm_jmf_at_line($1, get_next_line()); // on veut que JMF saute ici, la fin de if-(sans else)
        }
    | IFBLOCK1 tELSE
        {
            $2 = asm_add("JMP", -1, -1, -1);                     // la fin de if, on veut sauter à la fin de else (ligneY)
            modify_asm_jmf_at_line($1, get_next_line()+1);  // ligneX, le début de else, on veut que JMF saute ici.
        }
    tOB BODY tCB
        {
            modify_asm_jmp_at_line($2, get_next_line()+1); // ligneY, la fin de else
        }
    ;

IFBLOCK1:
    tIF tOP EXPRESSION
        {
            $1 = asm_add("JMF", $3,-1, -1);     // on renvoie la ligne JMF; on veut sauter à la fin de if (ligneX)
        }
    tCP tOB BODY tCB
        {
            $$ = $1; // on ne peut qu’affecter $$ à la fin d'une règle
        }
    ;

WHILEBLOCK: WHILEBLOCK1 
            {asm_add("JMP", $1, -1, -1);    // la fin du while, on veut sauter au début du while (ligneY)
            modify_asm_jmf_at_line($1, get_next_line()+1);  // ligneX, la suite du programme, on veut que JMF saute ici.
            }
            ;

WHILEBLOCK1:tWHILE tOP EXPRESSION 
                {$1 = asm_add("JMF", $3,-1, -1);     // on renvoie la ligne JMF; on veut sauter au début du while (ligneX)
                }
            tCP tOB BODY tCB
                {$$ = $1; // on ne peut qu’affecter $$ à la fin d'une règle
                }
            ;

EXPRESSION: tOP EXPRESSION tCP 
                {
                    $$ = $2;
                }
    |EXPRESSION tADD EXPRESSION
                {
                    $$ = expression($1,"ADD",$3);
                }

    |EXPRESSION tMUL EXPRESSION 
                {
                    $$ = expression($1,"MUL",$3);
                }

    |EXPRESSION tDIV EXPRESSION
                {
                    $$ = expression($1,"DIV",$3);
                } 

    |EXPRESSION tSUB EXPRESSION 
                {
                    $$ = expression($1,"DIFF",$3);
                }
    |EXPRESSION tINF EXPRESSION  
                {
                    $$ = expression($1,"INF",$3);
                }
    |EXPRESSION tSUP EXPRESSION  
                {
                    $$ = expression($1,"SUP",$3);
                }
    |EXPRESSION tCOMPARE EXPRESSION
                {
                    $$ = expression($1,"EQU",$3);
                }
    | tNUMBER   { 
                    int addr_var_tmp = affectation_tmp($1);
                    $$ = addr_var_tmp; 
                } 
    | tVAR      { 
                    $$ = get_var_address($1, depth); 
                }
    ;

%%

int main () { 
    yyparse();
    return 0;
}
