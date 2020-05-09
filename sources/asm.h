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

int asm_add(char *, int, int, int);
void modify_asm_jmp_at_line(int , int );
void modify_asm_jmf_at_line(int , int );
int get_next_line();
void print_assembly();

#endif