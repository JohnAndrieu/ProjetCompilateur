#include<stdio.h>
#include<stdlib.h>

int idSymbol=0;
int idSymbolTemp = 255;
char symbol [256];



void push(char * a)
{
  printf("PUSH : on a push le symbol %c\n",a);
  strcpy(symbol[idSymbol],a);
  idSymbol++;
}
  
void pushT()
{
  strcpy(symbol[idSymbolTemp],"$");
  idSymbolTemp--;
}


int getIndice(char a)
{
  int i;
  for(i=0 ; i<256 ; i++)
  {
    if ( symbol[i] == a)
    {
      return i;
    }
  }
  return -1;
}

void printTab (char * tab) {
  int i = 0;
  for(i = 0 ; i < 5 ; i++) {
    printf("Indice %d : %c\n",i,tab[i]);
  }
}
