#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "semantic.h"
#include "type.h"
#include "symbol.h"

typedef struct node *Node;
int nter_idx = 46;
char *NDtypes[] = {"TYPE", "INT", "FLOAT", "CHAR", "ID", "STRUCT", "IF", "WHILE", "ELSE", "RETURN",
                   "EXTERN", "STATIC", "CONST", "QUESTION_MARK", "COLON",
                   "DOT", "SEMI", "COMMA", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
                   "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
                   "LT", "LE", "GT", "GE", "NE", "EQ", "AND",
                   "OR", "NOT", "PLUS", "MINUS", "DOUBLE_PLUS", "DOUBLE_MINUS", "MUL",
                   "DIV", "MOD", "LP", "RP", "LB", "RB",
                   "LC", "RC", "Program", "ExtDefList",
                   "ExtDef", "Specifier", "ExtDecList", "StructSpecifier",
                   "VarDec", "FunDec", "VarList", "ParamDec",
                   "CompSt", "StmtList", "Stmt", "DefList",
                   "Def", "DecList", "Dec", "Args", "Exp"};

void parseProgram(Node program) {
    parseExtDefList(program->children[0]);
}

void parseExtDefList(Node extDefList) {
    // ExtDefList -> ExtDef ExtDefList
    //              |NULL
    if (extDefList == NULL) {
        return;
    }
    Node extDef = extDefList->children[0];
    Node leftList = extDefList->children[1];
    parseExtDef(extDef);
    parseExtDefList(leftList);
}

void parseExtDef(Node extDef) {
    // ExtDef -> Specifier ExtDecList SEMI
    //          |Specifier SEMI
    //          |Specifier FunDec CompSt
    Node specifier = extDef->children[0];
    if (specifier == NULL) {
        return;
    }
    Type *type = parseSpecifier(specifier);
    if (type == NULL) {
        return;
    }
    Node extDecList = extDef->children[1];
    if (extDecList == NULL) {
        return;
    }
    if (!strcmp(NDtypes[extDecList->type], "ExtDecList")) {
        parseExtDecList(ExtDecList, type);
    } else if (!strcmp(NDtypes[extDecList->type], "FunDec")) {
        // TODO: parse FunDec
        Node funDec = extDecList;
        Node compSt = extDef->children[2];
        Type *funDecType = parseFunDec(funDec, type);
        if (funDecType == NULL) {
            return;
        }
        char* funName = funDecType->name;
        Symbol* funSymbol = findSymbolEntry(funName);
        if(funSymbol == NULL){
            // TODO: Do function name need to hardcopy?
            insertSymbolEntry(funName, funDecType);
            parseCompSt(compSt, type);
        }else{
            printf("Error type 4 at Line %d: function is redefined \"%s\"\n",
                    funDec->line, funSymbol->name);
        }
    } else {
        // SEMI
    }
}

Type *parseSpecifier(Node specifier) {
    //Specifier: TYPE
    //          |StructSpecifier
    if (!strcmp(NDtypes[specifier->type], "Specifier")) {
        return NULL;
    }
    Type *type = (Type *) malloc(sizeof(Type));
    Node def = specifier->children[0];
    if (!strcmp(NDtypes[def->type], "TYPE")) {
        type->category = PRIMITIVE;
        if (!strcmp(def->value, "int")) {
            type->primitive = INT;
        } else if (!strcmp(def->value, "float")) {
            type->primitive = FLOAT;
        } else {
            type->primitive = CHAR;
        }
    } else if (!strcmp(NDtypes[def->type], "StructSpecifier")) {
        Node _struct = def->children[0];
        Node _structId = def->children[1];
        char *identifier = _structId->value;
        Symbol *symbol = findSymbolEntry(identifier);
        if (def->number == 2) { 
            // STRUCT ID
            if (symbol == NULL) {
                printf("Error type 15-2 at Line %d: struct is used without definition \"%s\"\n",
                       _structId->line, identifier);
                return NULL;
            }
            if (symbol->type->category != STRUCTURE) {
                printf("Error type 15-3 at Line %d: \"%s\" is not a struct\n",
                       _structId->line, identifier);
                return NULL;
            }
            type = symbol->type;
        } else { 
            // STRUCT ID LC DefList RC
            if (symbol != NULL) {
                printf("Error type 15-1 at Line %d: redefine the same structure type \"%s\"\n",
                       _structId->line, identifier);
            }
            Node defList = def->children[3];
            FieldList *defFieldList = parseDefList(defList);
            type->category = STRUCTURE;
            type->structure = defFieldList;
            insertSymbolEntry(identifier, type);
        }
    }
    return type;
}

FieldList *parseDefList(Node defList) {
    // DefList -> Def DefList
    //           |NULL
    if (decList == NULL) {
        return NULL;
    }
    Node def = defList->children[0];
    Node _defList = defList->children[1];
    FieldList *defFieldList = parseDef(def);
    FieldList *tmpDefFieldList = defFieldList;
    while (_defList != NULL) {
        def = _defList->children[0];
        _defList = _defList->children[1];
        defFieldList->next = parseDef(def);
        defFieldList = defFieldList->next;
    }
    return defFieldList;
}

FieldList *parseDef(Node def) {
    // Def: Specifier DecList SEMI
    if (def->number != 3){
        // error
        return NULL;
    }
    Type *type = parseSpecifier(def->children[0]);
    if (type == NULL) {
        return NULL;
    }
    Node decList = def->children[1];
    if (strcmp(NDtypes[decList->type], "DecList")) {
        return NULL;
    }
    FieldList *decListFieldList = parseDecList(decList, type);
    return decListFieldList;
}

FieldList *parseDecList(Node decList, Type *type) {
    // DecList -> Dec COMMA DecList
    //           |Dec
    Node dec = decList->children[0];
    FieldList *decFieldList = parseDec(dec, type);
    if (decFieldList == NULL){
        return decFieldList;
    }
    FieldList *tmpDecFieldList = decFieldList;
    if (decList->number == 3) {
        Node _decList = decList->children[2];
        while (_decList->number == 3 && tmpDecFieldList != NULL) {
            dec = _decList->children[0];
            _decList = _decList->children[2];
            tmpDecFieldList->next = parseDec(dec, type);
            tmpDecFieldList = tmpDecFieldList->next;
        }
    }
    return decFieldList;
}

FieldList *parseDec(Node dec, Type *type) {
    //Dec -> VarDec ASSIGN Exp
    //      |VarDec
    Node varDec = dec->children[0];
    FieldList *fieldList = parseVarDec(varDec, type);
    if (dec->number == 3) {
        Node exp = dec->children[2];
        Type *expType = parseExp(exp);
        if (!typecmp(type, expType)) {
            printf("Error type 5 at Line %d: unmatching types on both sides of assignment operator\n",
                   dec->line)
        }
    }
    return fieldList;
}

FieldList *parseVarDec(Node varDec, Type *type) {
    //VarDec -> VarDec LB INT RB (array)
    //         |ID
    Node tempNode = varDec->children[0];
    FieldList *field = (FieldList *) malloc(sizeof(FieldList));
    Type *endType = type;
    while (!strcmp(NDtypes[tempNode->type], "VarDec")) {
        Type *arrayType = (Type *) malloc(sizeof(Type));
        arrayType->array = (Array *) malloc(sizeof(Array));
        arrayType->category = ARRAY;
        arrayType->array->size = atoi(tempNode->children[2]->value);
        arrayType->array->base = endType;
        endType = arrayType;
        tempNode = tempNode->children[0];
    }
    // ID
    Symbol *symbol = findSymbolEntry(tempNode->value);
    if (symbol != NULL) {
        printf("Error type 3 at Line %d: variable is redefined in the same scope \"%s\"\n",
               tempNode->line, symbol->identifier);
    }
    field->name = tempNode->value;
    field->type = endType;
    insertSymbolEntry(field->name, field->type);
    return field;
}


FieldList *parseVarList(Node varList) {
    //VarList -> ParamDec COMMA VarList
    //          |ParamDec
    Node paramDec = varList->children[0];
    FieldList *varFieldList = parseParamDec(paramDec);
    FieldList *tmpFieldList = varFieldList;
    if (varList->number == 3) {
        // ParamDec COMMA VarList
        varList = varList->children[2];
        while (varList->number == 3 && tmpFieldList != NULL) {
            paramDec = varList->children[0];
            varList = varList->children[2];
            tmpFieldList->next = parseParamDec(paramDec);
            tmpFieldList = tmpFieldList->next;
        }
    }
    // ParamDec
    paramDec = varList->children[0];
    tmpFieldList->next = parseParamDec(param_dec);
    // fieldList for function variables
    return varFieldList;
}

FieldList *parseParamDec(Node paramDec) {
    // ParamDec -> Specifier VarDec
    Type *type = parseSpecifier(paramDec->children[0]);
    FieldList *paramFieldList = NULL;
    if (type != NULL) {
        paramFieldList = parseVarDec(paramDec->children[1], type);
    }
    return paramFieldList;
}


Type* parseFunDec(Node funDec, Type *type) {
    // type is function's returning type

    // FunDec -> ID LP VarList Rp
    //          |ID LP RP
    Type *funDecType = (Type *) malloc(sizeof(Type));
    // funDecType->name = funDec->value;
    funDecType->structure = (FieldList *) malloc(sizeof(FieldList));
    Node id = funDec->children[0];
    funDecType->category = FUNCTION;
    funDecType->structure->name = id->value;
    funDecType->structure->type = type;
    if (funDec->number == 3 || funDec->number == 2) {
        // ID LP RP
        funDecType->structure = NULL;
    } else {
        Node varList = funDec->children[2];
        funDecType->structure->next = parseVarList(var_list);
    }
}

Type *parseExp(Node exp) {
    Node leftmost = exp->children[0];
    Type *result = NULL;
    // Leftmost is Exp
    if (!strcmp(NDtypes[leftmost->type], "Exp")) {
        Node operator = exp->children[1];
        Node rightmost = exp->children[2];
        // Exp ASSIGN Exp
        if (!strcmp(NDtypes[operator->value], "ASSIGN")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            int lvalue1 = leftmost->number == 1 && !strcmp(NDtypes[leftmost->children[0]->type], "ID");
            int lvalue2 = leftmost->number == 4 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                          !strcmp(NDtypes[leftmost->children[1]->type], "LB");
            int lvalue3 = leftmost->number == 3 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                          !strcmp(NDtypes[leftmost->children[1]->type], "DOT");
            if (!(lvalue1 | lvalue2 | lvalue3)) {
                printf("Error type 6 at Line %d: rvalue on the left side of assignment operator\n", leftmost->line);
            } else if (!typecmp(leftmostType, rightmostType)) {
                printf("Error type 5 at Line %d: unmatching types on both sides of assignment operator\n",
                       leftmost->line);
            } else {
                result = leftmostType;
            }
        }
        // Exp AND Exp
        // Exp OR Exp
        else if (!strcmp(NDtypes[operator->type],"AND") || !strcmp(NDtypes[operator->type],"OR")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            // TODO: check what situation will cause error type 7
            if (!typecmp(leftmostType, rightmostType) && leftmostType->categroy == PRIMITIVE && leftmostType->primitive == INT){
                    printf("Error type 7 at Line %d: unmatching operands\n", leftmost->line);
                }
            }else{
                result = leftmostType;
            }
        }
        // Exp LT|LE|GT|GE|NE|EQ|PLUS|MINUS|MUL|DIV Exp
        else if(!strcmp(NDtypes[operator->type],"LT") || !strcmp(NDtypes[operator->type],"LE")
            || !strcmp(NDtypes[operator->type],"GT") || !strcmp(NDtypes[operator->type],"GE") 
            || !strcmp(NDtypes[operator->type],"NE") || !strcmp(NDtypes[operator->type],"EQ")
            || !strcmp(NDtypes[operator->type],"PLUS") || !strcmp(NDtypes[operator->type],"MINUS")
            || !strcmp(NDtypes[operator->type],"MUL") || !strcmp(NDtypes[operator->type],"DIV")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if(!typecmp(leftmostType,rightmostType) && leftmostType->category == PRIMITIVE
               && (leftmostType->primitive == INT || leftmostType->primitive == FLOAT)){
                printf("Error type 7 at Line %d: unmatching operands\n", leftmost->line);
            }else{
                result = leftmostType;
            }
        }else if(!strcmp(NDtypes[operator->type], "LB")){
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if (leftmostType->category != ARRAY){
                printf("Error type 10 at Line %d: applying indexing operator on non-array type variables\n", leftmost->line);
            }else if(!(rightmostType->category == PRIMITIVE && rightmostType->primitive == INT)){
                printf("Error type 12 at Line %d: array indexing with non-integer type expression\n", leftmost->line);
                result = leftmostType->Array->base;
            }else{
                result = leftmostType->Array->base;
            }
        }else if(!strcmp(NDtypes[operator->type], "DOT")){
            Type *leftmostType = parseExp(leftmost);
            if (leftmostType->category != STRUCTURE){
                printf("Error type 13 at Line %d: accessing member of non-structure variable\n", leftmost->line);
            }else{
                FieldList* tmp = leftmostType->structure;
                while(tmp != NULL){
                    if(!strcmp(tmp->name, rightmost->value)){
                        break;
                    }
                    tmp = tmp->next;
                }
                if (tmp == NULL){
                    printf("Error type 14 at Line %d: accessing an undefined structure member \"%s\".\n", 
                    leftmost->line, rightmost->value);
                }else{
                    result = tmp->type;
                }
            }
        }
    }
    // LP Exp RP
    else if(!strcmp(leftmost->name,"LP")){
        result = parseExp(exp->children[1]);
    }
    // MINUS Exp
    else if(!strcmp(leftmost->name,"MINUS")){
        Type *leftmostType = parseExp(leftmost);
        if (leftmostType->category != PRIMITIVE){
            fprintf(fout, "Error type 7 at Line %d: unmatching operands\n", leftmost->line);
        }else{
            result = leftmostType;
        }
    }
    // NOT Exp
    else if(!strcmp(leftmost->name,"NOT")){
        Type *leftmostType = parseExp(leftmost);
        if (leftmostType->category != PRIMITIVE && leftmostType->primitive != INT){
            fprintf(fout, "Error type 7 at Line %d: unmatching operands\n", leftmost->line);
        }else{
            result = (Type*)malloc(sizeof(Type));
            result->category = PRIMITIVE;
            result->primitive = INT;
        }
    }
    // ID LP Args RP
    // ID LP RP
    else if(!strcmp(NDtypes[leftmost->type],"ID")){
        Symbol* tmp = findSymbolEntry(leftmost->value);
        if(exp->number >= 3 && (!strcmp(NDtypes[exp->children[2]->type], "RP") || 
        (!strcmp(NDtypes[exp->children[2]->type], "Args") && !strcmp(NDtypes[exp->children[3]->type], "RP")))){
            if (tmp == NULL){
                printf("Error type 1 at Line %d: function is invoked without definition \"%s\"\n",
                leftmost->line, leftmost->value);
                // TODO: return NULL is necessary?
            }else if(tmp->type->category != FUNCTION){
                printf("Error type 11 at Line %d: applying function invocation operator on non-function names \"%s\"\n",
                        leftmost->line, leftmost->value);
            }
            Type* tmpFuncType = tmp->type;
            if (exp->number == 4){
                Node args = exp->children[2];
                FieldList * tmpFuncVariablesList = tmpFuncType->structure->next;
                if (tmpFuncVariablesList == NULL){
                    printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too many)\n",
                            leftmost->line, leftmost->value);
                }else{
                    // Args -> Exp COMMA Args
                    //        |Exp
                    Node argsExp = args->children[0];
                    while(1){
                        Type* argsExpType = parseExp(argsExp);
                        if(argsExpType == NULL){
                            break;
                        }
                        if (!typecmp(argsExpType, tmpFuncVariablesList->type)){
                            printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (type mismatch)\n",
                                    leftmost->line, leftmost->value);
                            break;
                        }else{
                            tmpFuncVariablesList = tmpFuncVariablesList->next;
                            if (tmpFuncVariablesList == NULL && argsExp->number == 1){
                                result = tmpFuncType->structure->type;
                                break;
                            }else if(tmpFuncVariablesList == NULL && argsExp->number == 3){
                                printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too many)\n",
                                        leftmost->line, leftmost->value);
                                break;
                            }else if(tmpFuncVariablesList != NULL && argsExp->number == 1){
                                printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too few)\n",
                                        leftmost->line, leftmost->value);
                                break;
                            }
                            argsExp = argsExp->children[2]->children[0];
                        }
                    }
                }
            }else{
                if (tmpFuncType->structure == NULL){
                    result = tmpFuncType;
                }else{
                    printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters (too few)\n",
                            leftmost->line, leftmost->value);
                }
            }
        }else{
            // ID
            if (tmp == NULL){
                printf("Error type 1 at Line %d: variable is used without definition \"%s\".\n",
                        leftmost->line, leftmost->value);
            }else{
                result = tmp->type;
            }
        }
    }else if(!strcmp(NDtypes[leftmost->type], "INT")){
        // INT
        result = (Type*)malloc(sizeof(type));
        result->category = PRIMITIVE;
        result->primitive = INT;
    }else if(!strcmp(NDtypes[leftmost->type], "FLOAT")){
        // FLOAT
        result = (Type*)malloc(sizeof(type));
        result->category = PRIMITIVE;
        result->primitive = FLOAT;
    }else if(!strcmp(NDtypes[leftmost->type], "CHAR")){
        // CHAR
        result = (Type*)malloc(sizeof(type));
        result->category = PRIMITIVE;
        result->primitive = CHAR;
    }
    return result;
}

void parseCompSt(Node compSt, Type* returnValType){
    //CompSt: LC DefList StmtList RC
    FieldList * defListFieldList = parseDefList(compSt->children[1]);
    parseStmtList(compSt->children[2], returnValType);
}

void parseStmtList(Node stmtList, Type* returnValType){
    // StmtList: Stmt StmtList
    //          |NULL
    if(stmtList == NULL){
        return;
    }
    Node stmt = stmtList->children[0];
    parseStmt(stmt, returnValType);
    parseStmtList(stmtList->children[1]);
}

void parStmt(Node stmt, Type * returnValType){
    // Stmt: Exp SEMI
    //      |CompSt
    //      |RETURN Exp SEMI
    //      |RETURN Exp error 
    //      |IF LP Exp RP Stmt
    //      |IF LP Exp RP Stmt ELSE Stmt 
    //      |WHILE LP Exp RP Stmt
}


void parseExtDecList(Node extDecList, Type* type){
    // ExtDecList: VarDec 
    //            |VarDec COMMA ExtDecList
    Node varDec = extDecList->children[0];
    parseVarDec(varDec, type);
    if(extDecList->number == 3){
        parseExtDecList(extDecList->children[2], type);
    }
}


int typecmp(Type *type1, Type *type2) {
    if (type1 == NULL ortype2 == NULL){
        return 0;
    }
    if (type1->category == type2->category) {
        if (type1->category == PRIMITIVE) {
            if (type1->primitive == type2->primitive) {
                return 1;
            }
        } else if (type1->category == ARRAY) {
            // ARRAY -> base, size
            if (typecmp(type1->array->base, type2->array->base) &&
                type1->array->size == type2->array->size) {
                return 1;
            }
        } else if (type1->category == STRUCTURE || type1->category == FUNCTION) {
            FieldList *fieldList1 = type1->structure;
            FieldList *fieldList2 = type2->structure;
            while (fieldList1 != NULL && fieldList2 != NULL) {
                if (!typecmp(fieldList1->type, fieldList2->type)) {
                    return 0;
                }
                fieldList1 = fieldList1->next;
                fieldList2 = fieldList2->next;
            }
            if (fieldList1 == NULL && fieldList2 == NULL) {
                return 1;
            }
            return 0;
        }
    }
    return 0;
}