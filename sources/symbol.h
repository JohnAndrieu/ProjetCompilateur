#ifndef SYMBOL_H
#define SYMBOL_H

#include<stdio.h>
#include<stdlib.h>

int idSymbol=0;
int idSymbolTemp = 255;

struct symbol {
  int constant;
  int init;
  int depth;
  char id [256];
};

struct symbol symbolTable [256];

int push_symbol(char *);
void pop_symbol();
int push_tmp_symbol(char *, int, int);
void clear_tmp_symbol(int);
int get_address(char *, int);
void set_initialized(char *, int);
int is_initialized(char *, int);

#endif