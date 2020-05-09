#include "asm.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ligne_asm = 0;

//Tableau de structures struct_asm
tab_asm asm_table[2048];

//Ajouter une instruction assembleur
//Creation d'une nouvelle stucture dans notre tableau de structure
int asm_add(char * inst,int id1,int id2, int id3){
    tab_asm * new_line = &(asm_table[ligne_asm]);
     strcpy(new_line->ope, inst);
     new_line->var1 = id1;
     new_line->var2 = id2;
     new_line->var3 = id3;
     ligne_asm ++;
     return ligne_asm-1;
}

//Patch JMP
void modify_asm_jmp_at_line(int indice, int new_line){
    tab_asm * line = &(asm_table[indice]);
    line -> var1 = new_line;
}

//Patch JMF
void modify_asm_jmf_at_line(int indice, int new_line){
    tab_asm * line = &(asm_table[indice]);
    line -> var2 = new_line;
}

//Recuperer la ligne courante pour écrire
int get_next_line(){
    return ligne_asm;
}

//Affiche le contenu du tableau de structures et écriture dans le fichier
void write_print_asm(){
    FILE * file_descriptor = fopen("./asm.txt","w");
    if(file_descriptor != NULL){
        printf("On affiche le code assembleur\n");
        for(int i = 0; i < ligne_asm; i++){
            char * assembly_code = malloc(100 * sizeof(char));
            sprintf(assembly_code,"%s %d %d %d\n",asm_table[i].ope,asm_table[i].var1,asm_table[i].var2,asm_table[i].var3);
            fputs(assembly_code, file_descriptor);
            printf("%d : %s %d %d %d\n",i+1,asm_table[i].ope,asm_table[i].var1,asm_table[i].var2,asm_table[i].var3);
        }
    }
    fclose(file_descriptor);
}