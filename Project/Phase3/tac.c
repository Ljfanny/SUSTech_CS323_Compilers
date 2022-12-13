#include "tac.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "hashmap.h"

char* titles[] = {"FUNC", "READ", "WRITE", "LABEL", "GOTO",
                "IF", "ASS", "OPER", "RETURN", "PARAM", "ARG", "CALL", "DEC"};

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
    //preparation: t0 := #0, t1 := #1;
    while (head != NULL){
        if(head->title == FUNC || head->title ==  READ
        || head->title ==  WRITE || head->title == LABEL
        || head->title == RETURN || head->title == PARAM
        || head->title == ARG || head->title == CALL){
            printf("%s %s\n", titles[head->title], head->target);
        }else if(head->title == GOTO){
            printf("%s %s:\n", titles[head->title], head->target);
        }else if (head->title == IF){
            printf("IF %s GOTO %s:\n", head->arg1, head->target);
        }else if(head->title == ASS) {
            printf("%s := %s\n", head->target, head->arg1);
        }else if (head->title == OPER){
            printf("%s := %s %s %s\n", head->target, head->arg1, head->op, head->arg2);
        }else if(head->title == DEC){
            
        }
        head = head->next;
    }
}