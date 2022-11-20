#include "uthash.h"
#include "symbol.h"

Symbol* symbolTable = NULL;

void insertSymbolEntry(const char* identifier, const Type* type){
    Symbol * symbol = (Symbol *)malloc(sizeof(Symbol));
    symbol->identifier = identifier;
    symbol->type = type;
    HASH_ADD_STR(symbolTable, identifier, symbol);
}


Symbol* findSymbolEntry(const char *identifier){
    Symbol * symbol;
    HASH_FIND_STR(symbolTable, key, symbol);
    return symbol;
}


void freeSymbolEntry(const char *identifier){
    Symbol * symbol = findSymbolEntry(identifier);
    HASH_DEL(symbolTable, symbol);
    free(symbol);
}

void freeSymbolTable(){
    HASH_CLEAR(hh, symbolTable);
}