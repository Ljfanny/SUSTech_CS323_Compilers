#ifndef _SEMANTIC_ANALYSIS
#define _SEMANTIC_ANALYSIS

#include "node.h"
#include "type.h"

typedef struct FuncParamLinkNode {
    char* tag;
    struct FuncParamLinkNode* prev;
    struct FuncParamLinkNode* next;
} FuncParamLinkNode;

typedef struct node *Node;

void parseProgram(Node program);
void parseExtDefList(Node extDefList);
void parseExtDef(Node extDef);
Type *parseSpecifier(Node specifier);
FieldList *parseDefList(Node defList);
FieldList *parseDef(Node def);
FieldList *parseDecList(Node decList, Type *type);
FieldList *parseDec(Node dec, Type *type);
FieldList *parseVarDec(int isFuncParam, Node varDec, Type *type);
FieldList *parseVarList(Node varList);
FieldList *parseParamDec(Node paramDec);
Type* parseFunDec(Node funDec, Type *type);
Type *parseExp(Node exp);
void parseCompSt(Node prev, Node compSt, Type* returnValType);
void parseStmtList(Node prev, Node stmtList, Type* returnValType);
void parseStmt(Node prev, Node stmt, Type * returnValType);
void parseExtDecList(Node extDecList, Type* type);
int typecmp(Type *type1, Type *type2);
void addReadFunc();
void addWriteFunc();
char* itoa(int num,char* str,int radix);
int countLength(int num);

#endif