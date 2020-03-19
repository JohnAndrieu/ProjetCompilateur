all: comp

comp: y.tab.o lex.yy.o
	gcc -Wall y.tab.o lex.yy.o -o comp

y.tab.c: source.y
	yacc --verbose --debug -d source.y

lex.yy.c: source2.l
	lex source2.l
