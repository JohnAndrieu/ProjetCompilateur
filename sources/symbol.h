#ifndef SYMBOL_H
#define SYMBOL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Définition table des symboles symétrique
int idSymbol=0; //id symboles
int idSymbolTemp = 255; //id symboles temporaires

struct symbol {
  int constant;
  int init;
  int depth;
  char id [256];
};

struct symbol symbolTable [256];

//Déclaration des fonctions
int push_var(char *, int , int);
void pop_var_temp();
int push_var_temp(char *, int, int);
void clear_var_temp();
int get_var_address(char *, int);
void set_initialized(char *, int);
int is_initialized(char *, int);
void clearUseless(int);
int get_indice_temp();
int get_indice();

#endif