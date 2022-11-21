#ifndef _SYMBOL_TABLE_H
#define _SYMBOL_TABLE_H

#include "type.h"
#include "uthash/uthash.h"

typedef struct Symbol
{
    char *identifier; /*key*/
    Type *type;
    UT_hash_handle hh; /*makes the structure hashable*/
} Symbol;

void insertSymbolEntry(char *identifier, Type* type);

Symbol *findSymbolEntry(const char *identifier);

void freeSymbolEntry(const char *identifier);

// void freeSymbolTable();

#endif