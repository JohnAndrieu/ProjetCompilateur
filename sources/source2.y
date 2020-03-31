%union
{
    int nb;
    char * var;
}

%{
    #include<stdio.h>
    #include <stdlib.h>

    FILE * inputFile; 
    int yydebug = 1;

    int symbol [256];

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

BODY: CreateVAR BODY {printf("C'est une creation de variable suivie d'un body\n");}
    | Affectation BODY {printf("C'est une affectation suivie d'un body\n");}
    | tPRINTF tOP tVAR tCP tPV BODY {printf("C'est un printf suivi d'un body\n");}
    | {printf("Fin BODY");}
    ;

TYPE: tINT {printf("C'est un Int\n");}
    | tBOOL {printf("C'est un Bool\n");}
    | tFLOAT {printf("C'est un Float\n");}
    | tDOUBLE {printf("C'est un Double\n");}
    ;

CreateVAR: TYPE tVAR tPV {printf("C'est une VAR\n");}
    | TYPE tVAR tAFFECT tNUMBER tPV {printf("C'est une Var avec Valeur\n");}
    | TYPE tVAR tVIRGULE SuiteVar {printf("C'est une suite de creation de variable\n");}
    ;

SuiteVar: tVAR tVIRGULE SuiteVar {printf("C'est une suite de declaration\n");}
    | tVAR tPV {printf("C'est une creation de variable\n");}
    ;

Affectation: tVAR tAFFECT tNUMBER  tPV {printf("C'est une affectation directe\n");}
    | tVAR tAFFECT EXPRESSION tPV {printf("C'est une affectation\n");}
    ;

EXPRESSION: EXPRESSION OPE EXPRESSION {fprintf(inputFile,"ADD %d %d %d\n",$$,$1,$3);}
    | tOP EXPRESSION tCP {}
    | tNUMBER { } 
    | tVAR {}
    ;

OPE: 
    tADD {$$=1;}
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
        printf("FIN\n");
    }

    return 0;
}
