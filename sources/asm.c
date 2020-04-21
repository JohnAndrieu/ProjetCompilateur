#include "asm.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int add_asm(char * inst,int id1,int id2, int id3){
    tab_asm * new_line = &(assembly[nb_line_asm]);
     strcpy(new_line->ope, inst);
     new_line->var1 = id1;
     new_line->var2 = id2;
     new_line->var3 = id3;
     nb_line_asm ++;
     return nb_line_asm-1;
}