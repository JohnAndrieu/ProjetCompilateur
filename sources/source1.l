%%

#include<[a-z]*.[a-z]*> printf("token include lib trouve\n");

[0-9]+ printf("token nombre trouve\n");

main printf("token main trouve\n");
void printf("token void trouve\n");

"{" printf("token open bracket trouve\n");
"(" printf("token parenthese ouvrante trouve\n");
"}" printf("token close bracket trouve\n");
")" printf("token parenthese fermante trouve\n");
";" printf("token point virgule trouve\n");
"," printf("token virgule trouve\n");
"." printf("token point trouve\n");

int printf("token int trouve\n");
float printf("token float trouve\n");
boolean printf("token boolean trouve\n");
double printf("token double trouve\n");
short printf("token short trouve\n");
long printf("token long trouve\n");
signed printf("token signed trouve\n");
unsigned printf("token unsigned trouve\n");
static printf("token static trouve\n");
true printf("token true trouve\n");
false printf("token false trouve\n");

printf printf("token printf trouve\n");
if printf("token if trouve\n");
while printf("token while trouve\n");
for printf("token for trouve\n");
return printf("token return trouve\n");

"%"d printf("token percent d trouve\n");
"%"f printf("token percent f trouve\n");
"%"s printf("token percent s trouve\n");

"==" printf("token comparaison trouve\n");
"=" printf("token affectation trouve\n");
"+" printf("token add trouve\n");
"*" printf("token mul trouve\n");
"-" printf("token sub trouve\n");
"/" printf("token div trouve\n");
"%" printf("token modulo trouve\n");

[A-z][A-z]* printf("token variable trouve\n");

%%

int yywrap(void){}

int main(void){
    printf("Debut\n");
    yylex();
    return 0;
}



