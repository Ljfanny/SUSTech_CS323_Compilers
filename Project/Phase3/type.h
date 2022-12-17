#ifndef _TYPE_DEFINITION
#define _TYPE_DEFINITION

typedef struct Type {
    int dec;
    char* tag;
    char* name;
    enum { PRIMITIVE, ARRAY, STRUCTURE, FUNCTION } category;
    union {
        enum { TINT, TFLOAT, TCHAR } primitive;
        struct Array *array;
        struct FieldList *structure;
    };
} Type;

typedef struct Array {
    struct Type *base;
    int size;
} Array;

typedef struct FieldList {
    char* name;
    struct Type *type;
    struct FieldList *next;
} FieldList;

int deepcopyType(Type* dest, Type* sour);

int deepcopyFieldList(FieldList* dest, FieldList* sour);

int deepcopyArray(Array* dest, Array* sour);

#endif
