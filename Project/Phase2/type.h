#ifndef _TYPE_DEFINITION
#define _TYPE_DEFINITION

typedef struct Type {
    char* name;
    enum { PRIMITIVE, ARRAY, STRUCTURE, FUNCTION} category;
    union {
        enum { INT, FLOAT, CHAR } primitive;
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

#endif
