CC=gcc
FLEX=flex
BISON=bison
splc:
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c node.c -lfl -ly -o bin/splc
clean: 
	@rm -f bin/splc lex.yy.c syntax.tab.c syntax.tab.h *.out
.PHONY: clean
