#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "symbol.h"

LinkNode* currScope = NULL;

void initializeScope(){
    currScope= (LinkNode*)malloc(sizeof(LinkNode));
    currScope->number = 0;
    currScope->table = NULL;
    currScope->prev = NULL;
    currScope->next = NULL;
}

void insertSymbolEntry(char* identifier, Type* type){
    Symbol * symbol = (Symbol *)malloc(sizeof(Symbol));
    char * _identifier = (char *)malloc(sizeof(char) * strlen(identifier));
    strcpy(_identifier, identifier);
    symbol->identifier = _identifier;
    symbol->type = type;
    HASH_ADD_STR(currScope->table, identifier, symbol);
    /*show hashmap values*/
    printCurrTable("insert:");
}

Symbol* findGlobalSymbolEntry(const char *identifier){
    LinkNode *scope = currScope;
    Symbol *symbol = NULL;
    while (scope != NULL){
        Symbol *table = scope->table;
        HASH_FIND_STR(table, identifier, symbol);
        if(symbol != NULL){
            break;
        }
        scope = scope->prev;
    }
    /*show hashmap values*/
    printCurrTable("find global:");
    return symbol;
}


Symbol* findLocalSymbolEntry(const char *identifier){
    Symbol *symbol = NULL;
    Symbol *table = currScope->table;
    HASH_FIND_STR(table, identifier, symbol);
    /*show hashmap values*/
    printCurrTable("find local:");
    return symbol;
}


void deleteSymbolEntry(const char *identifier){
}

void freeLinkNode(){
    Symbol* table = currScope->table;
    Symbol* item;
    Symbol* temp;
    HASH_ITER(hh, table, item, temp){
        HASH_DEL(table, item);
        free(item);
    }
    currScope = currScope->prev;
    free(currScope->next);
    currScope->next = NULL;
    /*show hashmap values*/
    printCurrTable("free link node:");
}

void addLinkNode(){
    LinkNode * newScope = (LinkNode*)malloc(sizeof(LinkNode));
    newScope->number = currScope->number + 1;
    newScope->prev = currScope;
    newScope->next = NULL;
    currScope->next = newScope;
    currScope = currScope->next;
    /*show hashmap values*/
    printCurrTable("add link node:");
}

void printCurrTable(char* nm){
    // printf("%s------------------%d------------------\n", nm, currScope->number);
    // int idx = 0;
    // Symbol* item;
    // Symbol* temp;
    // HASH_ITER(hh, currScope->table, item, temp){
    //     printf("index: %d, key(identifier): %s\n", idx, item->identifier);
    // }
    // printf("-------------------------------------------------\n");
}