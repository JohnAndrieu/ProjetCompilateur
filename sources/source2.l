%{
    #include "y.tab.h"
%}

%%

[0-9]+ {yylval.nb = atof(yytext); return tNUMBER ;};

main return tMAIN;
void return tVOID;

"{" return tOB;
"(" return tOP;
"}" return tCB;
")" return tCP;
";" return tPV;
"," return tVIRGULE;
"." return tPOINT;
\< return tINF;
\> return tSUP;

int return tINT;
float return tFLOAT;
boolean return tBOOL;
double return tDOUBLE;
short return tSHORT;
long return tLONG;
signed return tSIGNED;
unsigned return tUNSIGNED;
static return tSTATIC;
true return tTRUE;
false return tFALSE;

printf return tPRINTF;
if return tIF;
while return tWHILE;
for return tFOR;
return return tRETURN;

"==" return tCOMPARE;
"=" return tAFFECT;
"+" return tADD;
"*" return tMUL;
"-" return tSUB;
"/" return tDIV;
"%" return tMODULO;

[A-z][A-z]* { yylval.var = strdup(yytext); return tVAR;};

%%

int yywrap(void){}




