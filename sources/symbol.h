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


int getIndice(char a)
{
  int i;
  for(i=0;i<256 ; i++)
  {
    if ( symbol[i] == a)
    {
      return i;
    }
  }
}
