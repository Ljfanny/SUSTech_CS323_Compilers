#include "type.h"

typedef struct Symbol
{
    char *identifier;
    Type *type;
} Symbol;

void insertSymbolEntry(Symbol *symbol);

Symbol *findSymbolEntry(const char *key);

void freeSymbolEntry(const char *key);