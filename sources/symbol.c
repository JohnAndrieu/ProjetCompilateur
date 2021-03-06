#include "symbol.h"

//Ajouter un symbole
int push_var(char *id, int cons, int depth)
{
    printf("symbol : %s à l'addresse : %d\n",id,idSymbol);
    struct symbol * new_symbol = &(symbolTable[idSymbol]);
    strcpy(new_symbol->id, id);
    new_symbol->constant = cons;
    new_symbol->init = 0;
    new_symbol->depth = depth;
    idSymbol++;
    return idSymbol-1;
}

//Ajouter un symbole
int push_var_temp(char * id, int cons, int depth)
{
    struct symbol * new_symbol = &(symbolTable[idSymbolTemp]);
    strcpy(new_symbol->id, id);
    new_symbol->constant = cons;
    new_symbol->init = 0;
    new_symbol->depth = depth;
    printf("ajout symbole temporaire à l'@ : %d \n",idSymbolTemp);
    idSymbolTemp--;
    return idSymbolTemp+1;
}

//Supprimer le dernier symbole temporaire ajouté
void pop_var_temp() {
    idSymbol--;
}

//Supprimer entièrement les symboles temporaires
void clear_var_temp(){
    idSymbolTemp = 255;
}

//Récupérer l'adresse d'un symbole
int get_var_address(char * id, int depth)
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

//Tester l'initialisation d'un symbole
int is_initialized(char * id, int depth)
{
    int addr = get_var_address(id, depth);
    return symbolTable[addr].init;
}

//Signalé un symbole initialisé
void set_initialized(char * id, int depth)
{
    int addr = get_var_address(id, depth);
    symbolTable[addr].init = 1;
}

//Supprimer les symboles inutiles si on change de profondeur
void clearUseless(int depth)
{
    struct symbol * last = &(symbolTable[idSymbol]);
    int a = 0;
    while( a == 0 ) {
        if( last->depth > depth) {
            pop_var_temp();
            last = &(symbolTable[idSymbol]);
        }
        else {
            a++;
        }
    }
}

//Récupérer l'indice courant des symboles temporaires
int get_indice_temp(){
    return idSymbolTemp;
}

//Récupérer l'indice courant des symboles
int get_indice(){
    return idSymbolTemp;
}