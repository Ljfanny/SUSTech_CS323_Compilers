#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "symbol.h"

Symbol* symbolTable = NULL;

void insertSymbolEntry(char* identifier, Type* type){
    Symbol * symbol = (Symbol *)malloc(sizeof(Symbol));
    char * _identifier = (char *)malloc(sizeof(char) * strlen(identifier));
    strcpy(_identifier, identifier);
    symbol->identifier = _identifier;
    symbol->type = type;
    HASH_ADD_STR(symbolTable, identifier, symbol);
}


Symbol* findSymbolEntry(const char *identifier){
    Symbol * symbol;
    HASH_FIND_STR(symbolTable, identifier, symbol);
    return symbol;
}


void freeSymbolEntry(const char *identifier){
    Symbol * symbol = findSymbolEntry(identifier);
    HASH_DEL(symbolTable, symbol);
    free(symbol);
}

// void freeSymbolTable(){
//     HASH_CLEAR(hh, symbolTable);
// }