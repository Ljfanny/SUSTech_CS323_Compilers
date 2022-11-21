#include "node.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// #include "syntax.tab.c"

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

