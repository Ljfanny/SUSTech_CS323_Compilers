CC=gcc
FLEX=flex
BISON=bison
splc: syntax.y lex.l node.c node.h symbol.c symbol.h type.h semantic.c semantic.h
	$(BISON) -t -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c node.c symbol.c semantic.c -lfl -ly -o bin/splc
clean: 
	@rm -f bin/splc lex.yy.c syntax.tab.c syntax.tab.h *.out
.PHONY: clean
