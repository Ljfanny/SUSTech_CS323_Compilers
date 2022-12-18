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
    int lines = 0;
    //preparation: t0 := #0, t1 := #1;
    while (head != NULL){
        if(head->title == FUNC || head->title ==  READ
        || head->title ==  WRITE || head->title == LABEL
        || head->title == RETURN || head->title == PARAM
        || head->title == ARG){
            if(head->title == LABEL || head->title == FUNC){
                if(head->title == FUNC && lines > 0) { printf("\n"); }
                printf("%s %s :\n", titles[head->title], head->target);
            }else{
                printf("%s %s\n", titles[head->title], head->target);
            }
        }else if(head->title == GOTO){
            printf("%s %s\n", titles[head->title], head->target);
            while (head != NULL && head->title == GOTO) {
                head = head->next;
            }
            lines++;
            continue;
        }else if (head->title == IF){
            printf("IF %s GOTO %s\n", head->arg1, head->target);
        }else if(head->title == ASS) {
            printf("%s := %s\n", head->target, head->arg1);
        }else if (head->title == OPER){
            printf("%s := %s %s %s\n", head->target, head->arg1, head->op, head->arg2);
        }else if(head->title == DEC){
            printf("%s %s %s\n", titles[head->title], head->arg1, head->arg2);
        }
        lines++;
        head = head->next;
    }
    printf("Total lines: %d\n", lines);
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