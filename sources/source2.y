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
    char Buffer[50];

    int yylex();

    int yyerror(char *e) {
        printf("err: %s\n", e);
        exit(2);
        return 1;
    }

    void clean_file () {
        FILE * fichier = fopen("./asm.txt","w");
        fputs("",fichier);
        fclose(fichier);
    }

    void insert_file(char * code_assembleur){
        FILE * fichier = fopen("./asm.txt","a");
        if(fichier != NULL){
            fputs(code_assembleur, fichier);
            fclose(fichier);
        }
    }

    void affectation(char * var,int tmpAddr){
        int varAddr  = get_address(var,depth);
        char * ops = malloc(50 * sizeof(char));
        sprintf(ops,"COP @%d @%d\n",varAddr,tmpAddr);
        insert_file(ops);
        add_asm("COP",varAddr,tmpAddr,-1);
        set_initialized(var, depth);
    }

    int operation(int addr1,char * op,int addr2){
        sprintf(Buffer,"%d",get_indice_temp());
        int addr_return = push_tmp_symbol(Buffer,constante,depth);
        printf("%s @ret : %d @exp1 : %d @exp2 : %d\n",op,addr_return,addr1,addr2);

        char * ops = malloc(50 * sizeof(char));
        sprintf(ops,"%s @%d @%d @%d\n",op,addr_return,addr1,addr2);

        insert_file(ops);
        add_asm(op,addr_return,addr1,addr2);
        return addr_return;
    }

    int tmp_affec(int nb){ 
        sprintf(Buffer,"%d",get_indice_temp());
        int tmp_addr = push_tmp_symbol(Buffer,constante,depth);
        char * ops = malloc(50 * sizeof(char));
        sprintf(ops,"AFC @%d %d\n",tmp_addr,nb);
        insert_file(ops);
        add_asm("AFC",tmp_addr,nb,-1);
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

S: {clean_file();} tINT tMAIN tOP tCP tOB {depth++;} BODY tRETURN INT tPV tCB {depth--; print_assembly(); clearUseless(depth);};

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

CreateVAR: TYPE tVAR tPV { push_symbol($2,constante,depth); }
    | TYPE tVAR tAFFECT tNUMBER tPV { push_symbol($2,constante,depth); affectation($2,$4); }  
    | TYPE tVAR { push_symbol($2,constante,depth); } tVIRGULE SuiteVar
    ;

SuiteVar: tVAR { push_symbol($1,constante,depth); } tVIRGULE SuiteVar 
    | tVAR tPV { push_symbol($1,constante,depth); }
    ;

Affectation: tVAR tAFFECT EXPRESSION tPV 
                { 
                    affectation($1,$3); 
                    clear_tmp_symbol();
                }
                ;

IFBLOCK:
    IFBLOCK1
        {patch_JMF($1, get_nb_line_asm()); // on veut que JMF saute ici, la fin de if-(sans else)
        }
    | IFBLOCK1 tELSE
        {$2 = add_asm("JMP", -1, -1, -1);                     // la fin de if, on veut sauter à la fin de else (ligneY)
        patch_JMF($1, get_nb_line_asm()+1);  // ligneX, le début de else, on veut que JMF saute ici.
        }
    tOB BODY tCB
        {patch_JMP($2, get_nb_line_asm()+1); // ligneY, la fin de else
        }
    ;

IFBLOCK1:
    tIF tOP EXPRESSION
        {$1 = add_asm("JMF", $3,-1, -1);     // on renvoie la ligne JMF; on veut sauter à la fin de if (ligneX)
        }
    tCP tOB BODY tCB
        {$$ = $1; // on ne peut qu’affecter $$ à la fin d'une règle
        }
    ;

WHILEBLOCK: WHILEBLOCK1 
            {add_asm("JMP", $1, -1, -1);    // la fin du while, on veut sauter au début du while (ligneY)
            patch_JMF($1, get_nb_line_asm()+1);  // ligneX, la suite du programme, on veut que JMF saute ici.
            }
            ;

WHILEBLOCK1:tWHILE tOP EXPRESSION 
                {$1 = add_asm("JMF", $3,-1, -1);     // on renvoie la ligne JMF; on veut sauter au début du while (ligneX)
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
                    $$ = operation($1,"ADD",$3);
                }

    |EXPRESSION tMUL EXPRESSION 
                {
                    $$ = operation($1,"MUL",$3);
                }

    |EXPRESSION tDIV EXPRESSION
                {
                    $$ = operation($1,"DIV",$3);
                } 

    |EXPRESSION tSUB EXPRESSION 
                {
                    $$ = operation($1,"DIFF",$3);
                }
    |EXPRESSION tINF EXPRESSION  
                {
                    $$ = operation($1,"INF",$3);
                }
    |EXPRESSION tSUP EXPRESSION  
                {
                    $$ = operation($1,"SUP",$3);
                }
    |EXPRESSION tCOMPARE EXPRESSION 
                {
                    $$ = operation($1,"EQU",$3);
                }
    | tNUMBER   { 
                    int addr_tmp = tmp_affec($1);
                    $$ = addr_tmp; 
                } 
    | tVAR      { 
                    $$ = get_address($1, depth); 
                }
    ;

%%

int main () { 
    yyparse();
    return 0;
}
