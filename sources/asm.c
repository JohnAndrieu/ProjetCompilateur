#include "asm.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int nb_line_asm = 0;

//Tableau de structures struct_asm
tab_asm assembly[2048];

//Ajouter une instruction assembleur
//Creation d'une nouvelle stucture dans notre tableau de structure
int asm_add(char * inst,int id1,int id2, int id3){
    tab_asm * new_line = &(assembly[nb_line_asm]);
     strcpy(new_line->ope, inst);
     new_line->var1 = id1;
     new_line->var2 = id2;
     new_line->var3 = id3;
     nb_line_asm ++;
     return nb_line_asm-1;
}

//Patch JMP
void modify_asm_jmp_at_line(int indice, int new_line){
    tab_asm * line = &(assembly[indice]);
    line -> var1 = new_line;
}

//Patch JMF
void modify_asm_jmf_at_line(int indice, int new_line){
    tab_asm * line = &(assembly[indice]);
    line -> var2 = new_line;
}

//Recuperer la ligne courante pour écrire
int get_next_line(){
    return nb_line_asm;
}

//Affiche le contenu du tableau de structures et écriture dans le fichier
void write_print_asm(){
    FILE * file_descriptor = fopen("./asm.txt","w");
    if(file_descriptor != NULL){
        printf("On affiche le code assembleur\n");
        for(int i = 0; i < nb_line_asm; i++){
            char * assembly_code = malloc(100 * sizeof(char));
            sprintf(assembly_code,"%s %d %d %d\n",assembly[i].ope,assembly[i].var1,assembly[i].var2,assembly[i].var3);
            fputs(assembly_code, file_descriptor);
            printf("%d : %s %d %d %d\n",i+1,assembly[i].ope,assembly[i].var1,assembly[i].var2,assembly[i].var3);
        }
    }
    fclose(file_descriptor);
}