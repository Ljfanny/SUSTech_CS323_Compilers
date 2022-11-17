
#include "node.h"
#include "type.h"
typedef struct node*  Node;
void parseProgram(Node program);
void parseExtDefList(Node extDefList);
void parseExtDef(Node extDef);
Type* parseSpecifier(Node specifier);