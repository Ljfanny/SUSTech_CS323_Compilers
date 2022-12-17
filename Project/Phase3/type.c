#include "type.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int deepcopyType(Type* dest, Type* sour){
    if (sour == NULL){
        return 0;
    }
    if (sour->name != NULL && strlen(sour->name) > 0){
        dest->name = (char*)malloc(sizeof(char) * strlen(sour->name));
        strncpy(dest->name, sour->name, strlen(sour->name));
    }
    if (sour->tag != NULL && strlen(sour->tag) > 0){
        dest->tag = (char*)malloc(sizeof(char) * strlen(sour->tag));
        strncpy(dest->tag, sour->tag, strlen(sour->tag));
    }
    dest->category = sour->category;
    dest->dec = sour->dec;
    if (dest->category == PRIMITIVE){
        dest->primitive = sour->primitive;
    }else if (dest->category == ARRAY){
        dest->array = (Array*)malloc(sizeof(Array));
        int success = deepcopyArray(dest->array, sour->array);
        if (!success){
            free(dest->array);
            dest->array = NULL;
        }
    }else{
        dest->structure = (FieldList*)malloc(sizeof(FieldList));
        int success = deepcopyFieldList(dest->structure, sour->structure);
        if (!success){
            free(dest->structure);
            dest->structure = NULL;
        }
    }
    return 1;
}

int deepcopyFieldList(FieldList* dest, FieldList* sour){
    if (sour == NULL){
        return 0;
    }
    if (sour->name != NULL && strlen(sour->name) > 0){
        dest->name = (char*)malloc(sizeof(char) * strlen(sour->name));
        strncpy(dest->name, sour->name, strlen(sour->name));
    }
    dest->type = (Type*)malloc(sizeof(Type));
    int success1 = deepcopyType(dest->type, sour->type);
    if (!success1){
        free(dest->type);
        dest->type = NULL;
    }
    dest->next = (FieldList*)malloc(sizeof(FieldList));
    int success2 = deepcopyFieldList(dest->next, sour->next);
    if (!success2){
        free(dest->next);
        dest->next = NULL;
    }
    return 1;
}

int deepcopyArray(Array* dest, Array* sour){
    if (sour == NULL){
        return 0;
    }
    dest->size = sour->size;
    dest->base = (Type*)malloc(sizeof(Type));
    int success = deepcopyType(dest->base, sour->base);     
    if (!success){
        free(dest->base);
        dest->base = NULL;
    }
}