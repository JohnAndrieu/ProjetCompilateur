#include<stdio.h>
#include<stdlib.h>

int idSymbol=0;
int idSymbolTemp = 255;
char symbol [256];

void push(char a)
{
  symbol[idSymbol] = char a;
  idSymbol++;
}
  
void pushT()
{
  symbol[idSymbolTemp] = $;
  idSymbolTemp--;
}
