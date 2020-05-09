#include "asm.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int nb_line_asm = 0;

tab_asm assembly[2048];

int asm_add(char * inst,int id1,int id2, int id3){
    tab_asm * new_line = &(assembly[nb_line_asm]);
     strcpy(new_line->ope, inst);
     new_line->var1 = id1;
     new_line->var2 = id2;
     new_line->var3 = id3;
     nb_line_asm ++;
     return nb_line_asm-1;
}

void modify_asm_jmp_at_line(int indice, int new_line){
    tab_asm * line = &(assembly[indice]);
    line -> var1 = new_line;
}

void modify_asm_jmf_at_line(int indice, int new_line){
    tab_asm * line = &(assembly[indice]);
    line -> var2 = new_line;
}

int get_next_line(){
    return nb_line_asm;
}

void print_assembly(){
    FILE * file_descriptor = fopen("./asm.txt","w");
    if(file_descriptor != NULL){
        printf("On affiche le code assembleur\n");
        for(int i = 0; i < nb_line_asm; i++){
            char * assembly_code = malloc(100 * sizeof(char));
            sprintf(assembly_code,"%s %d %d %d\n",assembly[i].ope,assembly[i].var1,assembly[i].var2,assembly[i].var3);
            fputs(assembly_code, file_descriptor);
            printf("%s ",assembly[i].ope);
            printf("%d ",assembly[i].var1);
            printf("%d ",assembly[i].var2);
            printf("%d\n",assembly[i].var3);
        }
    }
    fclose(file_descriptor);
}