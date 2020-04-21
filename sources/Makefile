all: comp

comp: y.tab.o lex.yy.o symbol.o
	gcc -v -Wall y.tab.c lex.yy.c symbol.c -o comp

y.tab.c: source2.y
	yacc --verbose --debug -d source2.y

lex.yy.c: source2.l
	lex source2.l

symbol.o: symbol.c
	gcc -c -v symbol.c
