CC=gcc
FLEX=flex
BISON=bison
splc:
	$(BISON) -d syntax.y
	$(FLEX) lex.l
	$(CC) syntax.tab.c node.c -lfl -ly -o splc.out
clean: 
	@rm -f lex.yy.c syntax.tab.c syntax.tab.h *.out
.PHONY: clean
