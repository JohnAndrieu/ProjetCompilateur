#ifndef ASM_H
#define ASM_H

//Création de la structure contenant le code asm
struct struct_asm
{
    char ope[50];
    int var1;
    int var2;
    int var3;
};

typedef struct struct_asm tab_asm;

//Déclaration des fonctions
int asm_add(char *, int, int, int);
void modify_asm_jmp_at_line(int , int );
void modify_asm_jmf_at_line(int , int );
int get_next_line();
void write_print_asm();

#endif