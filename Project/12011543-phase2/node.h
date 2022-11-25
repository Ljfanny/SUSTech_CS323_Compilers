#ifndef _NODE_TYPE
#define _NODE_TYPE

struct node {
    int type;
    int line;
    char *value;
    int number;
    struct node *children[10];
};

void setNode(struct node *prt, struct node *nds[], int number);

struct node *newNodeNL(int type, int line, char *content);

struct node *newNodeTER(int type, int line);

struct node *newNodeNTER(int type, int line);

#endif

