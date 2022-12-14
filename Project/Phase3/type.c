#include "type.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void deepcopyType(Type* dest, Type* sour){
    if (sour == NULL){
        return;
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
    if (dest->category == PRIMITIVE){
        dest->primitive = sour->primitive;
    }else if (dest->category == ARRAY){
        dest->array = (Array*)malloc(sizeof(Array));
        dest->array->base = (Type*)malloc(sizeof(Type));
        deepcopyType(dest->array->base, sour->array->base);
        dest->array->size = sour->array->size;
    }else{
        dest->structure = (FieldList*)malloc(sizeof(FieldList));
        deepcopyFieldList(dest->structure, sour->structure);
    }
}

void deepcopyFieldList(FieldList* dest, FieldList* sour){
    if (sour->name != NULL){
        dest->name = (char*)malloc(sizeof(char) * strlen(sour->name));
        strncpy(dest->name, sour->name, strlen(sour->name));
    }
    dest->type = (Type*)malloc(sizeof(Type));
    deepcopyType(dest->type, sour->type);
    dest->next = (FieldList*)malloc(sizeof(FieldList));
    deepcopyFieldList(dest->next, sour->next);
}