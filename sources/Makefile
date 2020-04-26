all: comp

comp: y.tab.o lex.yy.o symbol.o asm.o
	gcc -Wall y.tab.c lex.yy.c symbol.c asm.c -o comp

y.tab.c: source2.y
	yacc --verbose --debug -d source2.y

lex.yy.c: source2.l
	lex source2.l

symbol.o: symbol.c
	gcc -c symbol.c

asm.o: asm.c
	gcc -c asm.c
