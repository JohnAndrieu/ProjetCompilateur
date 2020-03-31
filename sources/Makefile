all: comp

comp: y.tab.o lex.yy.o
	gcc -Wall y.tab.c lex.yy.c -o comp

y.tab.c: source2.y
	yacc --verbose --debug -d source2.y

lex.yy.c: source2.l
	lex source2.l
