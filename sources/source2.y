%union
{
    int nb;
    char * var;
}

%{
    #include<stdio.h>
    #include <stdlib.h>
    #include "symbol.h"

    FILE * inputFile; 
    int yydebug = 1;
    
     
    char * Testsymbol [256];
    int indice = 0;

    int yylex();

    int yyerror(char *e) {
        printf("err: %s\n", e);
        exit(2);
        return 1;
    }
%}

/*int * search_symbol(int token) {
    int i;
    for(i = 0 ; i < 256 ; i++) {
        if( symbol[i] == token ) {
            return &symbol[i];
        }
        else {
            return NULL;
        }
    }
}*/

%token <nb> tNUMBER ;
%token <var> tVAR;
%token tMAIN tVOID tOB tOP tCB tCP tPV tVIRGULE tPOINT tINT tFLOAT tBOOL tPRINTF tIF tWHILE tFOR tRETURN tCOMPARE tAFFECT tADD tMUL tSUB tDIV tMODULO;
%token tDOUBLE tSHORT tLONG tSIGNED tUNSIGNED tSTATIC tTRUE tFALSE;

%type <nb> Affectation;
%type <nb> EXPRESSION;
%type <nb> OPE;

%left tADD tSUB
%left tMUL tDIV

%%

s: tINT tMAIN tOP tCP tOB BODY tRETURN INT tPV tCB;

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

CreateVAR: TYPE tVAR tPV {printf("J'ai push cceci : %c\n",$2); push($2); Testsymbol[indice] = $2; indice++;}
    | TYPE tVAR tAFFECT tNUMBER tPV {printf("J'ai push ceci : %c\n",$2); push($2); Testsymbol[indice] = $2; indice++;}
    | TYPE tVAR tVIRGULE SuiteVar {printf("J'ai push ceci : %s\n",$2); push($2); Testsymbol[indice] = $2; indice++; }
    ;

SuiteVar: tVAR tVIRGULE SuiteVar {printf("J'ai push ceci : %s\n",$1); push($1); Testsymbol[indice] = $1; indice++;}
    | tVAR tPV {printf("J'ai push ceci : %s\n",$1); push($1); Testsymbol[indice] = $1; indice++;}
    ;

Affectation: tVAR tAFFECT tNUMBER  tPV {}
    | tVAR tAFFECT EXPRESSION tPV {}
    ;

EXPRESSION: EXPRESSION OPE EXPRESSION {fprintf(inputFile,"%d %d %d %d\n",$2,$$,$1,$3);}
    | tOP EXPRESSION tCP {}
    | tNUMBER {} 
    | tVAR {}
    ;

OPE: tADD {$$=1;}
    | tMUL {$$=2;}
    | tSUB {$$=3;}
    | tDIV {$$=4;}
    ;

%%

int main () {
    printf("Debut\n");
    inputFile = fopen("asm.txt","w");
    
    if(inputFile == NULL) {
        printf("Cannot open file %s\n","ASM");
        exit(0);
    }
    else {
        yyparse();
        fclose(inputFile);
    }
    
    printf("FIN\n");

    printTab(symbol);

    printf("%%%%%%%%\n");

    printTab(Testsymbol);

    return 0;
}
