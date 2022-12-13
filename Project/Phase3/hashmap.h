#ifndef _MY_HASHMAP
#define _MY_HASHMAP
#include "ut/uthash.h"
typedef struct hashmap
{
    char* key;
    char* value;
    UT_hash_handle hh;
} Hashmap;

//void initializeHashmap();

void insertHashmap(char* key, char* value);

Hashmap* findHashmap(const char* key);

void deleteHashmap(const char* key);

#endif