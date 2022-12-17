#include "tac.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "hashmap.h"
#include "translation.h"

char* titles[] = {"FUNC", "READ", "WRITE", "LABEL", "GOTO",
                "IF", "ASS", "OPER", "RETURN", "PARAM", "ARG", "DEC"};

Tac * newTac(char* target, char* op, char* arg1, char* arg2){
    Tac* instr = (Tac *)malloc(sizeof(Tac));
    instr->target = target;
    instr->op = op;
    instr->arg1 = arg1;
    instr->arg2 = arg2;
    instr->next = NULL;
    return instr;
}

void printTacs(Tac* head){
    head = head->next;
    int line = 1;
    //preparation: t0 := #0, t1 := #1;
    while (head != NULL){
        if(head->title == FUNC || head->title ==  READ
        || head->title ==  WRITE || head->title == LABEL
        || head->title == RETURN || head->title == PARAM
        || head->title == ARG){
            if(head->title == LABEL){
                printf("%d %s %s:\n", line, titles[head->title], head->target);
            }else{
                printf("%d %s %s\n", line, titles[head->title], head->target);
                if (head->title == RETURN && head->next != NULL){ printf("\n"); }
            }
        }else if(head->title == GOTO){
            printf("%d %s %s\n", line, titles[head->title], head->target);
        }else if (head->title == IF){
            printf("%d IF %s GOTO %s\n", line, head->arg1, head->target);
        }else if(head->title == ASS) {
            printf("%d %s := %s\n", line, head->target, head->arg1);
        }else if (head->title == OPER){
            printf("%d %s := %s %s %s\n", line, head->target, head->arg1, head->op, head->arg2);
        }else if(head->title == DEC){
            printf("%d %s %s %s\n", line, titles[head->title], head->arg1, head->arg2);
        }
        head = head->next;
        line++;
    }
}

char* generateT(int t){
    char num[10] = {0};
    itoa(t, num, 10);
    char target[10] = "t";
    strcat(target, num);
    int len = countLength(t) + 1;
    char* tag = (char*)malloc(sizeof(char) * len);
    strncpy(tag, target, len);
    return tag;
}

char* generateV(int v){
    char num[10] = {0};
    itoa(v, num, 10);
    char value[10] = "v";
    strcat(value, num);
    int len = countLength(v) + 1;
    char* tag = (char*)malloc(sizeof(char) * len);
    strncpy(tag, value, len);
    return tag;
}

char* generateLabel(int lbl){
    char num[10] = {0};
    itoa(lbl, num, 10);
    char target[15] = "label";
    strcat(target, num);
    int len = countLength(lbl) + 5;
    char* tag = (char*)malloc(sizeof(char) * len);
    strncpy(tag, target, len);
    return tag;
}