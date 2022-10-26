#include "node.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// #include "syntax.tab.c"

char *NDtypes[] = {"TYPE", "INT", "FLOAT", "CHAR", "ID","STRUCT", "IF", "WHILE", "ELSE", "RETURN",
        "DOT", "SEMI", "COMMA", "ASSIGN", "LT",
        "LE", "GT", "GE", "NE", "EQ", "AND",
        "OR", "NOT", "PLUS", "MINUS", "MUL",
        "DIV", "LP", "RP", "LB", "RB",
        "LC", "RC","Program", "ExtDefList",
        "ExtDef", "Specifier", "ExtDecList", "StructSpecifier",
        "VarDec", "FunDec", "VarList", "ParamDec",
        "CompSt", "StmtList", "Stmt", "DefList",
        "Def", "DecList", "Dec", "Args", "Exp"
};

void setNode(struct node *prt, struct node *nds[], int number) {
    prt->number = number;
    int min = 2147483647;
    for (int i = 0; i < number; i++) {
        prt->children[i] = nds[i];
        if(nds[i] != NULL && nds[i]->line > 0){
            min = min < nds[i]->line ? min : nds[i]->line;
        }
    }
    prt->line = min < prt->line?min:prt->line;
}

struct node *newNodeNL(int type, int line, char *content) {
    struct node *nd = (struct node *) malloc(sizeof(struct node));
    nd->line = line;
    nd->type = type;
    nd->number = 0;
    nd->value = (char *) malloc(sizeof(char) * strlen(content));
    strcpy(nd->value, content);
    return nd;
}

struct node *newNodeTER(int type, int line) {
    struct node *nd = (struct node *) malloc(sizeof(struct node));
    nd->line = line;
    nd->type = type;
    nd->number = 0;
    nd->value = NULL;
    return nd;
}

struct node *newNodeNTER(int type, int line) {
    struct node *nd = (struct node *) malloc(sizeof(struct node));
    nd->line = line;
    nd->type = type;
    nd->number = 0;
    nd->value = NULL;
    return nd;
}

void nodePrint(struct node *nd, int space) {
    if (nd == NULL)
        return;
    for (int i = 0; i < space; ++i)
        printf(" ");
    if (nd->value == NULL) {
        if (nd->type >= 33) {
            printf("%s (%d)\n", NDtypes[nd->type], nd->line);
        } else {
            printf("%s\n", NDtypes[nd->type]);
        }
    } else {
        printf("%s: %s\n", NDtypes[nd->type], nd->value);
    }
    for (int i = 0; i < nd->number; ++i) {
        nodePrint(nd->children[i], space + 2);
    }
}

void treePrint(struct node* nd) {
    nodePrint(nd, 0);
}

