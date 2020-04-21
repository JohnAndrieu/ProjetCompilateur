#include "symbol.h"

int push_symbol(char *id)
{
    printf("symbol : %s à l'addresse : %d\n",id,idSymbol);
    char * new = &(symbolTable[idSymbol].id[0]);
    strcpy(new, id);
    idSymbol++;
    return 0;
}

void pop_symbol() {
    idSymbol--;
}

int get_address(char * id, int cons, int depth)
{
    for(int i=0 ; i < idSymbol ; i++)
    {
        struct symbol *current_symbol = &(symbolTable[i]);
        if(current_symbol->depth == depth){
            if(!strcmp(current_symbol->id, id)){
                return i;
            } 
        }
    }
    /* inexistent symbol */
    exit(-2);  
}

int is_initialized(char * id, int depth)
{
    int addr = get_address(id, depth);
    return symbolTable[addr].init;
}

void set_initialized(char * id, int depth)
{
    int addr = get_address(id, depth);
    stack.entries[addr].init = 1;
}

//int push_symbol(char *);
//void pop_symbol();
int push_tmp_symbol(char *, int, int);
void clear_tmp_symbol(int);
//int get_address(char *, int);
void set_initialized(char *, int);
//int is_initialized(char *, int);