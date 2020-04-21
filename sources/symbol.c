#include "symbol.h"

int push_symbol(char *id, int cons, int depth)
{
    printf("symbol : %s à l'addresse : %d\n",id,idSymbol);
    struct symbol * new_symbol = &(symbolTable[idSymbol]);
    strcpy(new_symbol->id, id);

    new_symbol->constant = cons;
    new_symbol->init = 0;
    new_symbol->depth = depth;

    idSymbol++;
    return 0;
}

void pop_symbol() {
    idSymbol--;
}

int get_address(char * id, int depth)
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
    symbolTable[addr].init = 1;
}

//int push_symbol(char *);
//void pop_symbol();
int push_tmp_symbol(char *, int, int);
void clear_tmp_symbol(int);
//int get_address(char *, int);
//void set_initialized(char *, int);
//int is_initialized(char *, int);