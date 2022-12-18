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
FieldList *parseDefList(int isStructDef, Node defList, Type* stc);
FieldList *parseDef(int isStructDef, Node def);
FieldList *parseDecList(int isStructDef, Node decList, Type *type);
FieldList *parseDec(int isStructDef, Node dec, Type *type);
FieldList *parseVarDec(int isStructDef, int isFuncParam, Node varDec, Type *type);
FieldList *parseVarList(Node varList);
FieldList *parseParamDec(Node paramDec);
Type* parseFunDec(Node funDec, Type *type);
Type *parseExp(int isAss, Node exp);
void parseCompSt(Node prev, Node compSt, Type* returnValType, char* ttag, char* ftag);
void parseStmtList(Node prev, Node stmtList, Type* returnValType, char* ttag, char* ftag);
void parseStmt(Node prev, Node stmt, Type * returnValType, char* ttag, char* ftag);
void parseExtDecList(Node extDecList, Type* type);
int typecmp(Type *type1, Type *type2);
void addReadFunc();
void addWriteFunc();
char* itoa(int num,char* str,int radix);
int countLength(int num);

#endif