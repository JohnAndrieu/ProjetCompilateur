%union
{
    int nb;
    char * var;
}

%{
    #include <stdio.h>
    #include <stdlib.h>

    int yydebug = 0;
    int depth = 0;

    int yylex();

    int yyerror(char *e) {
        printf("err: %s\n", e);
        exit(2);
        return 1;
    }

    void insert_file(char * code_assembleur){
        FILE * fichier = fopen("./asm.txt","a");
        if(fichier != NULL){
            fputs(code_assembleur, fichier);
            fclose(fichier);
        }
    }

    void affectation(char * var,int tmpAddr){
        int varAddr  = get_address(var);
        char * ops = malloc(50 * sizeof(char));
        sprintf(ops,"COP @%d @%d\n",varAddr,tmpAddr);
        insert_file(ops);
    }

    int operation(int addr1,char * op,int addr2){
        sprintf(Buffer,"%d",get_end_pointer());
        int addr_return = add_tmp_symbol(Buffer,constante,depth);
        printf("%s @ret : %d @exp1 : %d @exp2 : %d\n",op,addr_return,addr1,addr2);

        char * assembly = malloc(100 * sizeof(char));
        sprintf(assembly,"%s @%d @%d @%d\n",op,addr_return,addr1,addr2);

        insert_file(assembly);
        add_asm(op,addr_return,addr1,addr2);
        return addr_return;
    }

%}


%token tMAIN tVOID tOB tOP tCB tCP tPV tVIRGULE tPOINT tINT tFLOAT tMUL tINF;
%token tBOOL tPRINTF tIF tWHILE tFOR tRETURN tCOMPARE tAFFECT tADD tMODULO tSUP;
%token tDOUBLE tSHORT tLONG tSIGNED tUNSIGNED tSTATIC tTRUE tFALSE tSUB tDIV;

%token <var> tVAR;
%token <nb> tNUMBER ;

%type <nb> Affectation;
%type <nb> EXPRESSION;
%type <nb> OPE;

%left tADD tSUB
%left tMUL tDIV

%start S

%%

S: tINT tMAIN tOP tCP tOB {depth++;} BODY tRETURN INT tPV tCB {depth--;};

INT: tVAR
    | tNUMBER
    ;

BODY: CreateVAR BODY {}
    | Affectation BODY {}
    | tPRINTF tOP tVAR tCP tPV BODY {}
    | {}
    ;

TYPE: tINT {}
    | tBOOL {}
    | tFLOAT {}
    | tDOUBLE {}
    ;

CreateVAR: TYPE tVAR tPV { push_symbol($2); }
    | TYPE tVAR { push_symbol($2); } tAFFECT tNUMBER tPV {}
    | TYPE tVAR { push_symbol($2); } tVIRGULE SuiteVar
    ;

SuiteVar: tVAR { push_symbol($1); } tVIRGULE SuiteVar 
    | tVAR tPV { push_symbol($1); }
    ;

Affectation: tVAR tAFFECT EXPRESSION tPV { affectation($1,$3); //clear var temp + reset idSymbolTemp}
    ;

EXPRESSION: tOP EXPRESSION tCP {}
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
                    $$ = get_address($1); 
                }
    ;

%%

int main () { 
    yyparse();
    return 0;
}
