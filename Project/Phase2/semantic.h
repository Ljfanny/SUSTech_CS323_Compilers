
#include "node.h"
#include "type.h"
typedef struct node*  Node;
void parseProgram(Node program);
void parseExtDefList(Node extDefList);
void parseExtDef(Node extDef);
Type *parseSpecifier(Node specifier);
FieldList *parseDefList(Node defList);
FieldList *parseDef(Node def);
FieldList *parseDecList(Node decList, Type *type);
FieldList *parseDec(Node dec, Type* type);
FieldList *parseVarDec(Node varDec, Type* type);