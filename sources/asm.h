#ifndef ASM_H
#define ASM_H

struct struct_asm
{
    char ope[50];
    int var1;
    int var2;
    int var3;
};

typedef struct struct_asm tab_asm;

int add_asm(char *, int, int, int);
void patch_JMP(int , int );
void patch_JMF(int , int );
int get_nb_line_asm();
void print_assembly();

#endif