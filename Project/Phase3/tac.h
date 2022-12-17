#ifndef _TAC
#define _TAC

typedef struct tac
{
    enum { FUNC = 0, READ, WRITE, LABEL, GOTO, IF, ASS, OPER, RETURN, PARAM, ARG, DEC} title;
    char* target;
    char* op;
    char* arg1;
    char* arg2;
    struct tac* next;
} Tac;

Tac * newTac(char* target, char* op, char* arg1, char* arg2);

void printTacs(Tac* head);

char* generateV(int v);

char* generateT(int t);

char* generateLabel(int lbl);

#endif