#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// #include "node.h"
#include "semantic.h"
// #include "type.h"
#include "symbol.h"

char *NDtypes[] = {"TYPE", "INT", "FLOAT", "CHAR", "ID",
                    "STRUCT", "IF", "WHILE", "ELSE", "RETURN",
                    "DOT", "SEMI", "COMMA", "ASSIGN",
                    "LT", "LE", "GT", "GE", "NE", "EQ",
                    "AND", "OR", "NOT",
                    "PLUS", "MINUS", "MUL", "DIV",
                    "LP", "RP", "LB", "RB", "LC", "RC",
                    "Program", "ExtDefList",
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
    parseExtDef(extDefList->children[0]);
    parseExtDefList(extDefList->children[1]);
}

void parseExtDef(Node extDef) {
    // ExtDef -> Specifier ExtDecList SEMI
    //          |Specifier SEMI
    //          |Specifier FunDec CompSt
    Node specifier = extDef->children[0];
    // if (specifier == NULL) {
    //     return;
    // }
    Type *type = parseSpecifier(specifier);
    printf("parseExtDef(): %d\n", type->category);
    if (type == NULL) {
        return;
    }
    if(extDef->number == 2){
        return;
    }
    Node extDecList = extDef->children[1];
    // if (extDef->number == 2 && !strcmp(NDtypes[extDecList->type],"SEMI")) {
    //     return;
    // }
    if (!strcmp(NDtypes[extDecList->type], "ExtDecList")) {
        parseExtDecList(extDecList, type);
    } else if (!strcmp(NDtypes[extDecList->type], "FunDec")) {
        // TODO: parse FunDec
        Node funDec = extDecList;
        Node compSt = extDef->children[2];
        printf("extDecList: %s\n", NDtypes[extDecList->type]);
        Type *funDecType = parseFunDec(funDec, type);
        // if (funDecType == NULL) {
        //     return;
        // }
        char* funName = funDecType->structure->name;
        Symbol* funSymbol = findSymbolEntry(funName);
        if(funSymbol == NULL){
            insertSymbolEntry(funName, funDecType);
            parseCompSt(compSt, type);
        }else{
            printf("Error type 4 at Line %d: function is redefined %s\n",
            funDec->line, funSymbol->identifier);
        }
    } else {
        // SEMI
    }
}

Type *parseSpecifier(Node specifier) {
    //Specifier: TYPE
    //          |StructSpecifier
    // if (!strcmp(NDtypes[specifier->type], "Specifier")) {
    //     return NULL;
    // }
    // Type *type = (Type *) malloc(sizeof(Type));
    printf("parseSpecifier()...%s...\n", NDtypes[specifier->children[0]->type]);
    Type * type = NULL;
    Node leftmost = specifier->children[0];
    if (!strcmp(NDtypes[leftmost->type], "TYPE")) {
        type = (Type *) malloc(sizeof(Type));
        type->category = PRIMITIVE;
        if (!strcmp(leftmost->value, "int")) {
            type->primitive = TINT;
            // printf("Specifier: INT\n");
        } else if (!strcmp(leftmost->value, "float")) {
            type->primitive = TFLOAT;
        } else {
            type->primitive = TCHAR;
        }
    } else if (!strcmp(NDtypes[leftmost->type], "StructSpecifier")) {
        Node _struct = leftmost->children[0];
        Node _structId = leftmost->children[1];
        char *identifier = _structId->value;
        Symbol *symbol = findSymbolEntry(identifier);
        if (leftmost->number == 2) { 
            // STRUCT ID
            if (symbol == NULL) {
                printf("Error type 15-2 at Line %d: struct is used without definition %s\n",
                _structId->line, identifier);
                return NULL;
            }
            if (symbol->type->category != STRUCTURE) {
                printf("Error type 15-3 at Line %d: %s is not a struct\n",
                _structId->line, identifier);
                return NULL;
            }
            type = symbol->type;
        } else { 
            // STRUCT ID LC DefList RC
            if (symbol != NULL) {
                printf("Error type 15-1 at Line %d: redefine the same structure type %s\n",
                _structId->line, identifier);
            }
            type = (Type *) malloc(sizeof(Type));
            type->category = STRUCTURE;
            type->structure = parseDefList(leftmost->children[3]);
            insertSymbolEntry(identifier, type);
        }
    }
    return type;
}

FieldList *parseDefList(Node defList) {
    // DefList -> Def DefList
    //           |NULL
    printf("parseDefList()......\n");
    if (defList == NULL) {
        return NULL;
    }
    Node def = defList->children[0];
    Node _defList = defList->children[1];
    FieldList *defFieldList = parseDef(def);
    FieldList *tmpDefFieldList = defFieldList;
    while (_defList != NULL) {
        def = _defList->children[0];
        _defList = _defList->children[1];
        tmpDefFieldList->next = parseDef(def);
        tmpDefFieldList =tmpDefFieldList->next;
    }
    return defFieldList;
}

FieldList *parseDef(Node def) {
    // Def: Specifier DecList SEMI
    // if (def->number != 3){
        // error
        // return NULL;
    // }
    printf("parseDef()......\n");
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
    printf("parseDecList()............\n");
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
    printf("parseDec()............\n");
    Node varDec = dec->children[0];
    FieldList *fieldList = parseVarDec(varDec, type);
    if (dec->number == 3) {
        Node exp = dec->children[2];
        Type *expType = parseExp(exp);
        if (!typecmp(type, expType)) {
            printf("Error type 5 at Line %d: unmatching types on both sides of assignment operator\n",
            dec->line);
        }
    }
    return fieldList;
}

FieldList *parseVarDec(Node varDec, Type *type) {
    //VarDec -> VarDec LB INT RB (array)
    //         |ID
    printf("parseVarDec().....%s.....\n", NDtypes[varDec->children[0]->type]);
    Node tempNode = varDec;
    FieldList *field = (FieldList *) malloc(sizeof(FieldList));
    Type *endType = type;
    while (!strcmp(NDtypes[tempNode->type], "VarDec") && tempNode->number == 4) {
        Type *arrayType = (Type *) malloc(sizeof(Type));
        arrayType->category = ARRAY;
        arrayType->array = (Array *) malloc(sizeof(Array));
        int sz = atoi(tempNode->children[2]->value);
        arrayType->array->size = sz;
        arrayType->array->base = endType;
        endType = arrayType;
        tempNode = tempNode->children[0];
    }
    // ID
    tempNode = tempNode->children[0];
    Symbol *symbol = findSymbolEntry(tempNode->value);
    field->name = tempNode->value;
    field->type = endType;
    field->next = NULL;
    if (symbol != NULL) {
        printf("Error type 3 at Line %d: redefine variable: %s\n",
        tempNode->line, symbol->identifier);
    }else{
        insertSymbolEntry(field->name, field->type);
    }
    return field;
}


FieldList *parseVarList(Node varList) {
    //VarList -> ParamDec COMMA VarList
    //          |ParamDec
    Node paramDec = varList->children[0];
    FieldList *varFieldList = parseParamDec(paramDec);
    if (varList->number == 1){
        // ParamDec
        return varFieldList;
    }
    FieldList *tmpFieldList = varFieldList;
    Node _varList = NULL;
    if (varList->number == 3) {
        // ParamDec COMMA VarList
        _varList = varList->children[2];
        while (_varList->number == 3 && tmpFieldList != NULL) {
            paramDec = _varList->children[0];
            _varList = _varList->children[2];
            tmpFieldList->next = parseParamDec(paramDec);
            tmpFieldList = tmpFieldList->next;
        }
    }
    // ParamDec
    paramDec = _varList->children[0];
    tmpFieldList->next = parseParamDec(paramDec);
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
    // printf("funDec: %d\n", funDec->number);
    if (funDec->number == 3) {
        // ID LP RP
        funDecType->structure->next = NULL;
    } else {
        Node varList = funDec->children[2];
        funDecType->structure->next = parseVarList(varList);
    }
    return funDecType;
}

Type *parseExp(Node exp) {
    Node leftmost = exp->children[0];
    Type *result = NULL;
    // Leftmost is Exp
    if (!strcmp(NDtypes[leftmost->type], "Exp")) {
        Node operator = exp->children[1];
        Node rightmost = exp->children[2];
        // Exp ASSIGN Exp
        if (!strcmp(NDtypes[operator->type], "ASSIGN")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            int lvalue1 = leftmost->number == 1 && !strcmp(NDtypes[leftmost->children[0]->type], "ID");
            int lvalue2 = leftmost->number == 4 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                        !strcmp(NDtypes[leftmost->children[1]->type], "LB");
            int lvalue3 = leftmost->number == 3 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                        !strcmp(NDtypes[leftmost->children[1]->type], "DOT");
            if (!(lvalue1 || lvalue2 || lvalue3)) {
                printf("Error type 6 at Line %d: rvalue on the left side of assignment operator\n",
                leftmost->line);
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
            if (!typecmp(leftmostType, rightmostType) && leftmostType->category == PRIMITIVE && leftmostType->primitive == TINT){
                printf("Error type 7 at Line %d: unmatching operands (different types)\n", leftmost->line);
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
            printf("LT|LE|GT|GE|NE|EQ|PLUS|MINUS|MUL|DIV:....\n");
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            // if (leftmostType == NULL){
                // printf("Error type 1 at Line %d: undefined variable (leftmost): %s \n",
                // leftmost->line, leftmost->value);
            // }else if(rightmostType == NULL){
                // printf("Error type 1 at Line %d: undefined variable (rightmost): %s \n",
                // rightmost->line, rightmost->value);
            // }else{
            if(!typecmp(leftmostType,rightmostType) && leftmostType->category == PRIMITIVE
            && (leftmostType->primitive == TINT || leftmostType->primitive == TFLOAT)){
                printf("Error type 7 at Line %d: unmatching operands\n",
                leftmost->line);
            }else{
                result = leftmostType;
            }
            // }
        }else if(!strcmp(NDtypes[operator->type], "LB")){
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if (leftmostType->category != ARRAY){
                printf("Error type 10 at Line %d: applying indexing operator on non-array type variables\n", leftmost->line);
            }else if(!(rightmostType->category == PRIMITIVE && rightmostType->primitive == TINT)){
                printf("Error type 12 at Line %d: array indexing with non-integer type expression\n", leftmost->line);
                result = leftmostType->array->base;
            }else{
                result = leftmostType->array->base;
            }
        }else if(!strcmp(NDtypes[operator->type], "DOT")){
            Type *leftmostType = parseExp(leftmost);
            if (leftmostType->category != STRUCTURE){
                printf("Error type 13 at Line %d: accessing member of non-structure variable\n",
                leftmost->line);
            }else{
                FieldList* tmp = leftmostType->structure;
                while(tmp != NULL){
                    if(!strcmp(tmp->name, rightmost->value)){
                        break;
                    }
                    tmp = tmp->next;
                }
                if (tmp == NULL){
                    printf("Error type 14 at Line %d: accessing an undefined structure member %s\n", 
                    leftmost->line, rightmost->value);
                }else{
                    result = tmp->type;
                }
            }
        }
    }    // LP Exp RP
    else if(!strcmp(NDtypes[leftmost->type],"LP")){
        result = parseExp(exp->children[1]);
    }
    // MINUS Exp
    else if(!strcmp(NDtypes[leftmost->type],"MINUS")){
        Type *leftmostType = parseExp(exp->children[1]);
        if (leftmostType->category != PRIMITIVE){
            printf("Error type 7 at Line %d: unmatching operands\n", 
            leftmost->line);
        }else{
            result = leftmostType;
        }
    }
    // NOT Exp
    else if(!strcmp(NDtypes[leftmost->type],"NOT")){
        Type *leftmostType = parseExp(exp->children[1]);
        if (leftmostType->category != PRIMITIVE && leftmostType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands\n",
            leftmost->line);
        }else{
            result = (Type*)malloc(sizeof(Type));
            result->category = PRIMITIVE;
            result->primitive = TINT;
        }
    }
    // ID LP Args RP
    // ID LP RP
    else if(!strcmp(NDtypes[leftmost->type],"ID")){
        Symbol* tmp = findSymbolEntry(leftmost->value);
        if(exp->number >= 3){
            if (tmp == NULL){
                printf("Error type 2 at Line %d: undefined function: %s\n",
                leftmost->line, leftmost->value);
                return NULL;
            }else if(tmp->type->category != FUNCTION){
                printf("Error type 11 at Line %d: applying function invocation operator on non-function names: %s\n",
                leftmost->line, leftmost->value);
                return NULL;
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
                printf("Error type 1 at Line %d: undefined variable: %s\n",
                leftmost->line, leftmost->value);
            }else{
                result = tmp->type;
            }
        }
    }else if(!strcmp(NDtypes[leftmost->type], "INT")){
        // INT
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TINT;
    }else if(!strcmp(NDtypes[leftmost->type], "FLOAT")){
        // FLOAT
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TFLOAT;
    }else if(!strcmp(NDtypes[leftmost->type], "CHAR")){
        // CHAR
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TCHAR;
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
    parseStmtList(stmtList->children[1], returnValType);
}

void parseStmt(Node stmt, Type * returnValType){
    // Stmt: Exp SEMI
    //      |CompSt
    //      |RETURN Exp SEMI
    Node leftmost = stmt->children[0];
    if (!strcmp(NDtypes[leftmost->type],"Exp")){
        parseExp(leftmost);
    }else if(!strcmp(NDtypes[leftmost->type],"CompSt")){
        parseCompSt(leftmost, returnValType);
    }else if(!strcmp(NDtypes[leftmost->type],"RETURN")){
        Node exp = stmt->children[1];
        Type* expType = parseExp(exp);
        if(expType == NULL){
            return;
        }
        if(!typecmp(expType, returnValType)){
            printf("Error type 8 at Line %d: the function's return value type mismatches the declared type\n",
            leftmost->line);
        }
    }else if(!strcmp(NDtypes[leftmost->type],"IF")){
        // |IF LP Exp RP Stmt
        // |IF LP Exp RP Stmt ELSE Stmt
        Node exp = stmt->children[2];
        Type* expType = parseExp(exp);
        if (expType == NULL){
            return;
        }
        // TODO: what type of expType is legal?
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands\n", exp->line);
        }else{
            parseStmt(stmt->children[4], returnValType);
            if (stmt->number == 7){
                parseStmt(stmt->children[6], returnValType);
            }
        }
    }else if(!strcmp(NDtypes[leftmost->type],"WHILE")){
        // |WHILE LP Exp RP Stmt
        Node exp = stmt->children[2];
        Type* expType = parseExp(exp);
        if (expType == NULL){
            return;
        }
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands\n", exp->line);
        }else{
            parseStmt(stmt->children[4], returnValType);
        }
    }
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
    if (type1 == NULL || type2 == NULL){
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