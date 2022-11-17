#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "semantic.h"
#include "type.h"
#include "symbol.h"

/*
Node {
    int type;
    int line;
    char *value;
    int number;
    Node *children[10];
};
*/
typedef struct node *Node;
int nter_idx = 46;
char *NDtypes[] = {"TYPE", "INT", "FLOAT", "CHAR", "ID", "STRUCT", "IF", "WHILE", "ELSE", "RETURN",
                   "EXTERN", "STATIC", "CONST", "QUESTION_MARK", "COLON",
                   "DOT", "SEMI", "COMMA", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
                   "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
                   "LT", "LE", "GT", "GE", "NE", "EQ", "AND",
                   "OR", "NOT", "PLUS", "MINUS", "DOUBLE_PLUS", "DOUBLE_MINUS", "MUL",
                   "DIV", "MOD", "LP", "RP", "LB", "RB",
                   "LC", "RC", "Program", "ExtDefList",
                   "ExtDef", "Specifier", "ExtDecList", "StructSpecifier",
                   "VarDec", "FunDec", "VarList", "ParamDec",
                   "CompSt", "StmtList", "Stmt", "DefList",
                   "Def", "DecList", "Dec", "Args", "Exp"};

void parseProgram(Node program)
{
    parseExtDefList(program->children[0]);
}

void parseExtDefList(Node extDefList)
{
    Node extDef = extDefList->children[0];
    Node leftList = extDefList->children[1];
    parseExtDef(extDef);
    parseExtDefList(leftList);
}

void parseExtDef(Node extDef)
{
    Node specifier = extDef->children[0];
    if (strcmp(NDtypes[specifier->type], "Specifier"))
    {
        return;
    }
    Type *type = parseSpecifier(specifier);
}

/*
typedef struct Type {
    char name[32];
    enum { PRIMITIVE, ARRAY, STRUCTURE, FUNCTION} category;
    union {
        enum { INt, FLOAt, CHAr } primitive;
        struct Array *array;
        struct FieldList *structure;
    };
} Type;

typedef struct Array {
    struct Type *base;
    int size;
} Array;

typedef struct FieldList {
    char* name;
    struct Type *type;
    struct FieldList *next;
} FieldList;
*/
Type *parseSpecifier(Node specifier)
{
    Type *type = (Type *)malloc(sizeof(Type));
    Node def = specifier->children[0];
    if (!strcmp(NDtypes[def->type], "TYPE"))
    {
        type->category = PRIMITIVE;
        if (!strcmp(def->value, "int"))
        {
            type->primitive = INt;
        }
        else if (!strcmp(def->value, "float"))
        {
            type->primitive = FLOAt;
        }
        else
        {
            type->primitive = CHAr;
        }
    }
    else if (!strcmp(NDtypes[def->type], "StructSpecifier"))
    {
        Node struct_ = def->children[0];
        Node struct_id = def->children[1];
        char* identifier = struct_id->value;
        Symbol *symbol = findSymbolEntry(identifier);
        if (def->number==2){ // STRUCT ID
            if (symbol == NULL){
                printf("Error type 16 at Line %d: struct is used without definition \"%s\"\n",
                        struct_id->line, identifier);
                return NULL;
            }
            if (symbol->type->category !=STRUCTURE)
            {
                printf("Error type 17 at Line %d: \"%s\" is not a struct\n",
                        struct_id->line, identifier);
                return NULL;
            }
        }else{ //STRUCT ID LC DefList RC  
            if (symbol != NULL){
                 printf("Error type 15 at Line %d: redefine the same structure type \"%s\"\n",
                        struct_id->line, identifier);
            }
            type->category = STRUCTURE;
            Node defList = def->children[3];
            //TODO: Parse deflist type->structure = delist
            Symbol *struct_symbol = (Symbol *)malloc(sizeof(Symbol));
            struct_symbol->identifier = identifier;
            struct_symbol->type = type;
            insertSymbolEntry(struct_symbol);
        }
    }
    return type;
}


