#ifndef _SYMBOL_TABLE_H
#define _SYMBOL_TABLE_H

#include "type.h"
#include "ut/uthash.h"

typedef struct Symbol
{
    char *identifier; /*key*/
    Type *type;
    UT_hash_handle hh; /*makes the structure hashable*/
} Symbol;

typedef struct LinkNode
{
    int number;
    Symbol *table;
    struct LinkNode* prev; 
    struct LinkNode* next;
} LinkNode;

void initializeScope();

void insertSymbolEntry(char *identifier, Type* type);

Symbol *findGlobalSymbolEntry(const char *identifier);

Symbol *findLocalSymbolEntry(const char *identifier);

void deleteSymbolEntry(const char *identifier);

void freeLinkNode();

void addLinkNode();

void printCurrTable(char* nm);

#endif