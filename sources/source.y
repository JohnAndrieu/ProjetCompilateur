%{
    #include<stdio.h>
    #include <stdlib.h>

    int yydebug = 1;

    int yylex();

    int yyerror(char *e) {
        printf("err: %s\n", e);
        exit(2);
        return 1;
    }
%}

%token tNUMBER tMAIN tVOID tOB tOP tCB tCP tPV tVIRGULE tPOINT tINT tFLOAT tBOOL tPRINTF tIF tWHILE tFOR tRETURN tCOMPARE tAFFECT tADD tMUL tSUB tDIV tMODULO tVAR;
%token tDOUBLE tSHORT tLONG tSIGNED tUNSIGNED tSTATIC tTRUE tFALSE;
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
    | tVAR tAFFECT OPERATION tPV {printf("C'est une affectation\n");}
    ;

OPERATION: T1 tADD T1 {printf("C'est une Add\n");}
    | T1 tMUL T1 {printf("C'est une Mul\n");}
    | T1 tDIV T1 {printf("C'est une Div\n");}
    | T1 tSUB T1 {printf("C'est un Sub\n");}
    ;

T1: tOP T1 tCP {printf("Creation de parentheses\n");}
    | tNUMBER {printf("C'est un Nombre\n");}
    | tVAR {printf("C'est une Var\n");}
    | OPERATION {printf("C'est une Operation\n");}
    ;

%%

int main () {
    yyparse();
    return 0;
}