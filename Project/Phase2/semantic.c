#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "semantic.h"
#include "symbol.h"

char *NDtypes[] = {"TYPE", "INT", "FLOAT", "CHAR", "ID",
                    "STRUCT", "IF", "WHILE", "ELSE", "RETURN", "BREAK", "CONTINUES",
                    "DOT", "SEMI", "COMMA", "ASSIGN", "QM", "COLON",
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
    initializeScope();
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
    Type *type = parseSpecifier(specifier);
    if (type == NULL) {
        return;
    }
    if(extDef->number == 2){
        return;
    }
    Node extDecList = extDef->children[1];
    if (!strcmp(NDtypes[extDecList->type], "ExtDecList")) {
        parseExtDecList(extDecList, type);
    } else if (!strcmp(NDtypes[extDecList->type], "FunDec")) {
        Node funDec = extDecList;
        Node compSt = extDef->children[2];
        addLinkNode();
        Type *funDecType = parseFunDec(funDec, type);
        char* funName = funDecType->structure->name;
        Symbol* funSymbol = findGlobalSymbolEntry(funName);
        if(funSymbol == NULL){
            parseCompSt(NULL, compSt, funDecType->structure->type);
            freeLinkNode();
            insertSymbolEntry(funName, funDecType);
        }else{
            printf("Error type 4 at Line %d: redefine function: %s\n",
            funDec->line, funSymbol->identifier);
        }
    } else {
        // SEMI
    }
}

Type *parseSpecifier(Node specifier) {
    //Specifier: TYPE
    //          |StructSpecifier
    Type * type = NULL;
    Node leftmost = specifier->children[0];
    if (!strcmp(NDtypes[leftmost->type], "TYPE")) {
        type = (Type *) malloc(sizeof(Type));
        type->category = PRIMITIVE;
        if (!strcmp(leftmost->value, "int")) {
            type->primitive = TINT;
        } else if (!strcmp(leftmost->value, "float")) {
            type->primitive = TFLOAT;
        } else {
            type->primitive = TCHAR;
        }
    } else if (!strcmp(NDtypes[leftmost->type], "StructSpecifier")) {
        Node _struct = leftmost->children[0];
        Node _structId = leftmost->children[1];
        char *identifier = _structId->value;
        Symbol *symbol = findGlobalSymbolEntry(identifier);
        if (leftmost->number == 2) { 
            // STRUCT ID
            if (symbol == NULL) {
                printf("Error type 17 at Line %d: struct is used without definition: %s\n",
                _structId->line, identifier);
                return NULL;
            }
            if (symbol->type->category != STRUCTURE) {
                printf("Error type 16 at Line %d: %s is not a struct\n",
                _structId->line, identifier);
                return NULL;
            }
            type = symbol->type;
        } else { 
            // STRUCT ID LC DefList RC
            if (symbol != NULL) {
                printf("Error type 15 at Line %d: redefine the same structure type: %s\n",
                _structId->line, identifier);
            }
            type = (Type *) malloc(sizeof(Type));
            type->category = STRUCTURE;
            addLinkNode();
            type->structure = parseDefList(leftmost->children[3]);
            freeLinkNode();
            insertSymbolEntry(identifier, type);
        }
    }
    return type;
}

FieldList *parseDefList(Node defList) {
    // DefList -> Def DefList
    //           |NULL
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
            printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n",
            exp->line);
        }
    }
    return fieldList;
}

FieldList *parseVarDec(Node varDec, Type *type) {
    //VarDec -> VarDec LB INT RB (array)
    //         |ID
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
    Symbol *symbol = findLocalSymbolEntry(tempNode->value);
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
    funDecType->structure = (FieldList *) malloc(sizeof(FieldList));
    Node id = funDec->children[0];
    funDecType->category = FUNCTION;
    funDecType->structure->name = id->value;
    funDecType->structure->type = type;
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
            if (!((leftmost->number == 1 && !strcmp(NDtypes[leftmost->children[0]->type], "ID")) 
            || (leftmost->number == 3 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                !strcmp(NDtypes[leftmost->children[1]->type], "DOT"))
            || (leftmost->number == 4 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                !strcmp(NDtypes[leftmost->children[1]->type], "LB")))) {
                printf("Error type 6 at Line %d: left side in assignment is rvalue\n",
                leftmost->line);
            } else if (!typecmp(leftmostType, rightmostType)) {
                printf("Error type 5 at Line %d: unmatching types on both sides of assignment\n",
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
            if (typecmp(leftmostType, rightmostType) && leftmostType->category == PRIMITIVE && leftmostType->primitive == TINT){
                result = leftmostType;
            }else{
                printf("Error type 7 at Line %d: unmatching operands: %s\n", leftmost->line, NDtypes[operator->type]);
            }
        }
        // Exp LT|LE|GT|GE|NE|EQ Exp
        else if(!strcmp(NDtypes[operator->type],"LT") || !strcmp(NDtypes[operator->type],"LE")
            || !strcmp(NDtypes[operator->type],"GT") || !strcmp(NDtypes[operator->type],"GE") 
            || !strcmp(NDtypes[operator->type],"NE") || !strcmp(NDtypes[operator->type],"EQ")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if( leftmostType == NULL || rightmostType == NULL ||
            leftmostType->category != PRIMITIVE || rightmostType->category != PRIMITIVE){
                printf("Error type 7 at Line %d: unmatching operands: %s\n",
                leftmost->line, NDtypes[operator->type]);
            }else{
                result = (Type*)malloc(sizeof(Type));
                result->category = PRIMITIVE;
                result->primitive = TINT;
            }
        }
        // Exp PLUS|MINUS|MUL|DIV Exp
        else if(!strcmp(NDtypes[operator->type],"PLUS") || !strcmp(NDtypes[operator->type],"MINUS")
            || !strcmp(NDtypes[operator->type],"MUL") || !strcmp(NDtypes[operator->type],"DIV")) {
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if(leftmostType == NULL || rightmostType == NULL ||
            leftmostType->category != PRIMITIVE || rightmostType->category != PRIMITIVE){
                printf("Error type 7 at Line %d: unmatching operands: %s\n",
                leftmost->line, NDtypes[operator->type]);
            }else{
                result = (Type*)malloc(sizeof(Type));
                result->category = PRIMITIVE;
                if(leftmostType->primitive == TFLOAT || rightmostType->primitive == TFLOAT){
                    result->primitive = TFLOAT;
                }else{
                    result->primitive = TINT;
                }
            }
        }else if(!strcmp(NDtypes[operator->type],"QM")){
            // Exp QM Exp COLON Exp
            Type *leftType = parseExp(leftmost);
            Type *midType = parseExp(rightmost);
            Type *rightType = parseExp(exp->children[4]);
            result = midType;
            if (leftType == NULL || leftType->category != PRIMITIVE || leftType->primitive != TINT){
                printf("Error type 7 at Line %d: unmatching operands: ..error.. ? ... : ...\n", leftmost->line);
                result = NULL;
            }
            if (!typecmp(midType, rightType) || midType->category == FUNCTION || midType->category == ARRAY){
                printf("Error type 7 at Line %d: unmatching operands in sides of \':\'\n", leftmost->line);
                result = NULL;
            }
        }else if(!strcmp(NDtypes[operator->type], "LB")){
            //Exp LB Exp RB
            Type *leftmostType = parseExp(leftmost);
            Type *rightmostType = parseExp(rightmost);
            if (leftmostType->category != ARRAY){
                printf("Error type 10 at Line %d: indexing on non-array variable\n", leftmost->line);
            }else if(!(rightmostType->category == PRIMITIVE && rightmostType->primitive == TINT)){
                printf("Error type 12 at Line %d: index by non-integer\n", leftmost->line);
            }else{
                result = leftmostType->array->base;
            }
        }else if(!strcmp(NDtypes[operator->type], "DOT")){
            // Exp DOT ID
            Type *leftmostType = parseExp(leftmost);
            if (leftmostType->category != STRUCTURE){
                printf("Error type 13 at Line %d: accessing with non-structure variable\n",
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
                    printf("Error type 14 at Line %d: no such member: %s\n", 
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
            printf("Error type 7 at Line %d: unmatching operands: MINUS\n", 
            leftmost->line);
        }else{
            result = leftmostType;
        }
    }
    // NOT Exp
    else if(!strcmp(NDtypes[leftmost->type],"NOT")){
        Type *leftmostType = parseExp(exp->children[1]);
        if (leftmostType->category != PRIMITIVE || leftmostType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands: NOT\n",
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
        Symbol* tmp = findGlobalSymbolEntry(leftmost->value);
        if(exp->number >= 3){
            if (tmp == NULL){
                printf("Error type 2 at Line %d: undefined function: %s\n",
                leftmost->line, leftmost->value);
                return NULL;
            }else if(tmp->type->category != FUNCTION){
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n",
                leftmost->line, leftmost->value);
                return NULL;
            }
            Type* tmpFuncType = tmp->type;
            if (exp->number == 4){
                Node args = exp->children[2];
                FieldList * tmpFuncVariablesList = tmpFuncType->structure->next;
                if (tmpFuncVariablesList == NULL){
                    printf("Error type 9 at Line %d: more the function %s's arguments than the declared parameters\n",
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
                            printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters since type\n",
                                    leftmost->line, leftmost->value);
                            break;
                        }else{
                            tmpFuncVariablesList = tmpFuncVariablesList->next;
                            if (tmpFuncVariablesList == NULL && args->number == 1){
                                result = tmpFuncType->structure->type;
                                break;
                            }else if(tmpFuncVariablesList == NULL && args->number == 3){
                                printf("Error type 9 at Line %d: more the function %s's arguments than the declared parameters\n",
                                        leftmost->line, leftmost->value);
                                break;
                            }else if(tmpFuncVariablesList != NULL && args->number == 1){
                                printf("Error type 9 at Line %d: fewer the function %s's arguments than the declared parameters\n",
                                        leftmost->line, leftmost->value);
                                break;
                            }
                            args = args->children[2];
                            argsExp = args->children[0];
                        }
                    }
                }
            }else{
                if (tmpFuncType->structure->next == NULL){
                    result = tmpFuncType->structure->type;
                }else{
                    printf("Error type 9 at Line %d: fewer the function %s's arguments than the declared parameters\n",
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

void parseCompSt(Node prev, Node compSt, Type* returnValType){
    //CompSt: LC DefList StmtList RC
    // addLinkNode();
    FieldList * defListFieldList = parseDefList(compSt->children[1]);
    parseStmtList(prev, compSt->children[2], returnValType);
    // freeLinkNode();
}

void parseStmtList(Node prev, Node stmtList, Type* returnValType){
    // StmtList: Stmt StmtList
    //          |NULL
    if(stmtList == NULL){
        return;
    }
    parseStmt(prev, stmtList->children[0], returnValType);
    parseStmtList(prev, stmtList->children[1], returnValType);
}

void parseStmt(Node prev, Node stmt, Type * returnValType){
    // Stmt: Exp SEMI
    //      |CompSt
    //      |RETURN Exp SEMI
    //      |BREAK SEMI
    //      |CONTINUES SEMI
    Node leftmost = stmt->children[0];
    if (!strcmp(NDtypes[leftmost->type],"Exp")){
        parseExp(leftmost);
    }else if(!strcmp(NDtypes[leftmost->type],"CompSt")){
        parseCompSt(prev, leftmost, returnValType);
    }else if(!strcmp(NDtypes[leftmost->type],"RETURN")){
        Node exp = stmt->children[1];
        Type* expType = parseExp(exp);
        if(expType == NULL){
            return;
        }else if(expType->category == FUNCTION){
            expType = expType->structure->type;
        }
        if(!typecmp(expType, returnValType)){
            printf("Error type 8 at Line %d: incompatiable return type\n",
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
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands in if() or else if()\n", exp->line);
        }
        addLinkNode();
        parseStmt(prev, stmt->children[4], returnValType);
        freeLinkNode();
        if (stmt->number == 7){
            addLinkNode();
            parseStmt(prev, stmt->children[6], returnValType);
            freeLinkNode();
        }
    }else if(!strcmp(NDtypes[leftmost->type],"WHILE")){
        // |WHILE LP Exp RP Stmt
        Node exp = stmt->children[2];
        Type* expType = parseExp(exp);
        if (expType == NULL){
            return;
        }
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands in while()\n", exp->line);
        }
        addLinkNode();
        parseStmt(leftmost, stmt->children[4], returnValType);
        // printf("%s\n", NDtypes[leftmost->type]);
        freeLinkNode();
    }else if (!strcmp(NDtypes[leftmost->type],"BREAK")){
        //BREAK SEMI
        if (prev == NULL || strcmp(NDtypes[prev->type],"WHILE")){
            printf("Error type 18 at Line %d: improper break\n", leftmost->line);
        }
    }else if (!strcmp(NDtypes[leftmost->type],"CONTINUES")){
        //CONTINUES SEMI
        if (prev == NULL || strcmp(NDtypes[prev->type],"WHILE")){
            printf("Error type 19 at Line %d: improper continues\n", leftmost->line);
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
        } else if (type1->category == FUNCTION) {
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
        }else{
            //bonus: structure -> have the same variables' type
            FieldList * itm1 = type1->structure;
            FieldList * itm2 = type2->structure;
            int cnt1 = 0;
            int cnt2 = 0;
            while (itm1 != NULL){
                itm1 = itm1->next;
                cnt1++;
            }
            while (itm2 != NULL){
                itm2 = itm2->next;
                cnt2++;
            }
            if (cnt1 != cnt2){
                return 0;
            }
            itm1 = type1->structure;
            itm2 = NULL;
            int idx2 = 0;
            int matches = 0;
            int * isMatched = (int *)malloc((sizeof(int)) * cnt2);
            memset(isMatched, 0, cnt2);
            while (itm1 != NULL){
                itm2 = type2->structure;
                idx2 = 0;
                while (itm2 != NULL){
                    if(typecmp(itm1->type, itm2->type) && isMatched[idx2] == 0){
                        isMatched[idx2] = 1;
                        matches++;
                        break;
                    }
                    itm2 = itm2->next;
                    idx2++;
                }
                itm1 = itm1->next;
            }
            if (matches == cnt1){
                return 1;
            }
        }
    }
    return 0;
}