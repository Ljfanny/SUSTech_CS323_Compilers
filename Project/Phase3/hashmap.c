#include "hashmap.h"

Hashmap* hashmap = NULL;

Hashmap *findHashmap(const char* key){
    Hashmap* item = NULL;
    HASH_FIND_STR(hashmap, key, item);
    return item;
}

void deleteHashmap(const char* key){
    Hashmap* item = findHashmap(key);
    if(item != NULL){
        HASH_DEL(hashmap, item);
    }
}

void insertHashmap(char* key, char* value){
    deleteHashmap(key);
    Hashmap* item = (Hashmap*)malloc(sizeof(Hashmap));
    item->key = key;
    item->value = value;
    HASH_ADD_STR(hashmap, key, item);
}

// void initializeHashmap(){
//     insertHashmap("#0", "t0");
//     insertHashmap("#1", "t1");
// }