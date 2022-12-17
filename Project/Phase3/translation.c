#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "translation.h"
#include "hashmap.h"
#include "symbol.h"
#include "tac.h"
#include "type.h"

Tac* head = NULL;
Tac* curTac = NULL;
int errorCnt, labelCnt, vCnt, tCnt;
char* NDtypes[] = { "TYPE", "INT", "FLOAT", "CHAR", "ID",
                    "STRUCT", "IF", "WHILE", "ELSE", "RETURN",
                    "BREAK", "CONTINUE",
                    "DOT", "SEMI", "COMMA", "ASSIGN", "QM", "COLON",
                    "LT", "LE", "GT", "GE", "NE", "EQ",
                    "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", "DIV",
                    "LP", "RP", "LB", "RB", "LC", "RC",
                    "Program", "ExtDefList", "ExtDef", "Specifier",
                    "ExtDecList", "StructSpecifier",
                    "VarDec", "FunDec", "VarList", "ParamDec",
                    "CompSt", "StmtList", "Stmt", "DefList",
                    "Def", "DecList", "Dec", "Args", "Exp" };

void parseProgram(Node program) {
    errorCnt = 0;
    labelCnt = 0;
    vCnt = 0;
    tCnt = 0;
    initializeScope();
    //initializeHashmap();
    addReadFunc();
    addWriteFunc();
    head = newTac(NULL, NULL, NULL, NULL);
    curTac = head;
    parseExtDefList(program->children[0]);
    if(!errorCnt){
        printTacs(head);
    } 
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
    //ExtDef: Specifier ExtDecList SEMI
    //       |Specifier SEMI
    //       |Specifier FunDec CompSt
    Node specifier = extDef->children[0];
    Type *type = parseSpecifier(specifier);
    if (type == NULL || extDef->number == 2) {
        return;
    }
    Node extDecList = extDef->children[1];
    if (!strcmp(NDtypes[extDecList->type], "ExtDecList")) {
        parseExtDecList(extDecList, type);
    } else if (!strcmp(NDtypes[extDecList->type], "FunDec")) {
        Node funDec = extDecList;
        Node compSt = extDef->children[2];
        Type *funDecType = parseFunDec(funDec, type);
        char* funName = funDecType->structure->name;
        Symbol* funSymbol = findGlobalSymbolEntry(funName);
        if(funSymbol == NULL){
            insertSymbolEntry(funName, funDecType);
            addLinkNode();
            parseCompSt(NULL, compSt, funDecType->structure->type);
            freeLinkNode();
        }else{
            printf("Error type 4 at Line %d: redefine function: %s\n",
            funDec->line, funSymbol->identifier);
            errorCnt++;
        }
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
            type->dec = 4;
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
        //STRUCT ID
        if (leftmost->number == 2) { 
            if (symbol == NULL) {
                printf("Error type 17 at Line %d: struct is used without definition: %s\n",
                _structId->line, identifier);
                errorCnt++;
                return NULL;
            }
            if (symbol->type->category != STRUCTURE) {
                printf("Error type 16 at Line %d: %s is not a struct\n",
                _structId->line, identifier);
                errorCnt++;
                return NULL;
            }
            type = symbol->type;
            //printf("%s\n", type->name);
        } 
        //STRUCT ID LC DefList RC
        else {
            if (symbol != NULL) {
                printf("Error type 15 at Line %d: redefine the same structure type: %s\n",
                _structId->line, identifier);
                errorCnt++;
                return NULL;
            }
            type = (Type *) malloc(sizeof(Type));
            type->category = STRUCTURE;
            type->name = (char*)malloc(sizeof(char)*strlen(identifier));
            strcpy(type->name, identifier);
            addLinkNode();
            type->structure = parseDefList(1, leftmost->children[3], type);
            freeLinkNode();
            insertSymbolEntry(identifier, type);
        }
    }
    return type;
}

FieldList *parseDefList(int isStructDef, Node defList, Type* stc) {
    //DefList: Def DefList
    //        |NULL
    if (defList == NULL) {
        return NULL;
    }
    Node def = defList->children[0];
    Node _defList = defList->children[1];
    FieldList *defFieldList = parseDef(isStructDef, def);
    FieldList *tmpDefFieldList = defFieldList;
    int isOver = 0;
    int totalDec = defFieldList->type->dec;
    while (_defList != NULL) {
        def = _defList->children[0];
        _defList = _defList->children[1];
        FieldList* itemFieldList = parseDef(isStructDef, def);
        if(itemFieldList == NULL){
            isOver = 1;
        }
        if (!isOver){
            totalDec += itemFieldList->type->dec;
            tmpDefFieldList->next = itemFieldList;
            tmpDefFieldList = tmpDefFieldList->next;
        }
    }
    if (stc != NULL){
        stc->dec = totalDec;
    }
    return defFieldList;
}

FieldList *parseDef(int isStructDef, Node def) {
    //Def: Specifier DecList SEMI
    Type *type = parseSpecifier(def->children[0]);
    if (type == NULL) {
        return NULL;
    }
    Node decList = def->children[1];
    if (strcmp(NDtypes[decList->type], "DecList")) {
        return NULL;
    }
    FieldList *decListFieldList = parseDecList(isStructDef, decList, type);
    return decListFieldList;
}

FieldList *parseDecList(int isStructDef, Node decList, Type *type) {
    //DecList: Dec COMMA DecList
    //        |Dec
    Node dec = decList->children[0];
    FieldList *decFieldList = parseDec(isStructDef, dec, type);
    if (decFieldList == NULL){
        return decFieldList;
    }
    FieldList *tmpDecFieldList = decFieldList;
    if (decList->number == 3) {
        Node _decList = decList->children[2];
        while (_decList->number == 3 && tmpDecFieldList != NULL) {
            dec = _decList->children[0];
            _decList = _decList->children[2];
            tmpDecFieldList->next = parseDec(isStructDef, dec, type);
            tmpDecFieldList = tmpDecFieldList->next;
        }
        tmpDecFieldList->next = parseDec(isStructDef, _decList->children[0], type);
    }
    return decFieldList;
}

FieldList *parseDec(int isStructDef, Node dec, Type *type) {
    //Dec: VarDec ASSIGN Exp
    //    |VarDec
    Node varDec = dec->children[0];
    FieldList *fieldList = parseVarDec(isStructDef, 0, varDec, type);
    if (dec->number == 3) {
        Node exp = dec->children[2];
        Type *expType = parseExp(0, exp);
        if (!typecmp(type, expType)) {
            printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n",
            exp->line);
            errorCnt++;
        }else{
            Hashmap* item = findHashmap(fieldList->name);
            if (item != NULL)
            {
                curTac->next = newTac(item->value, NULL, expType->tag, NULL);
                curTac = curTac->next;
                curTac->title = ASS;
            }
        }
    }
    if (isStructDef){
        fieldList->type->dec = type->dec;
    }
    return fieldList;
}

FieldList *parseVarDec(int isStructDef, int isFuncParam, Node varDec, Type *type) {
    //VarDec: VarDec LB INT RB (Array)
    //       |ID
    Node tempNode = varDec;
    FieldList *field = (FieldList *) malloc(sizeof(FieldList));
    Type *endType = (Type*)malloc(sizeof(Type));
    int success = deepcopyType(endType, type);
    if (!success){
        free(endType);
        endType = NULL;
    }
    int decs = 0;
    int unit = type->dec;
    while (!strcmp(NDtypes[tempNode->type], "VarDec") && tempNode->number == 4) {
        Type *arrayType = (Type *) malloc(sizeof(Type));
        arrayType->category = ARRAY;
        arrayType->array = (Array *) malloc(sizeof(Array));
        int sz = atoi(tempNode->children[2]->value);
        arrayType->array->size = sz;
        arrayType->array->base = endType;
        arrayType->array->base->dec = unit;
        decs = unit * sz;
        unit = decs;
        endType = arrayType;
        tempNode = tempNode->children[0];
    }
    //ID
    endType->dec = unit;
    tempNode = tempNode->children[0];
    field->name = tempNode->value;
    field->type = endType;
    field->next = NULL;
    Symbol *symbol = findLocalSymbolEntry(tempNode->value);
    //printf("%s\n", tempNode->value);
    if (symbol != NULL) {
        printf("Error type 3 at Line %d: redefine variable: %s\n",
        tempNode->line, symbol->identifier);
        errorCnt++;
    }else{
        if (!isStructDef){
            char* vtg = generateV(vCnt);
            vCnt++;
            if(isFuncParam){
                field->type->tag = vtg;
                curTac->next = newTac(vtg, NULL, NULL, NULL);
                curTac = curTac->next;
                curTac->title = PARAM;
            }else{
                if (type->category == STRUCTURE || type->category == ARRAY){
                    int len = countLength(field->type->dec);
                    char* arg2 = (char*)malloc(sizeof(char)*len);
                    itoa(field->type->dec, arg2, 10);
                    field->type->tag = (char*)malloc(sizeof(char)*(strlen(vtg)+1));
                    strcat(field->type->tag, "&");
                    strcat(field->type->tag, vtg);
                    curTac-> next = newTac(NULL, NULL, vtg, arg2);
                    curTac = curTac->next;
                    curTac->title = DEC;
                }else{
                    field->type->tag = vtg;
                }
            }
            insertHashmap(field->name, field->type->tag);
            //printf("%s, %s\n", field->name, field->type->tag);
        }    
        insertSymbolEntry(field->name, field->type);
    }
    return field;
}

FieldList *parseVarList(Node varList) {
    //VarList: ParamDec COMMA VarList
    //        |ParamDec
    Node paramDec = varList->children[0];
    FieldList *varFieldList = parseParamDec(paramDec);
    //ParamDec
    if (varList->number == 1){
        return varFieldList;
    }
    FieldList *tmpFieldList = varFieldList;
    Node _varList = NULL;
    int isOver = 0;
    //ParamDec COMMA VarList
    if (varList->number == 3) {
        _varList = varList->children[2];
        while (_varList->number == 3 && tmpFieldList != NULL) {
            paramDec = _varList->children[0];
            _varList = _varList->children[2];
            FieldList* itemFieldList = parseParamDec(paramDec);
            if (itemFieldList == NULL){
                isOver = 1;
            }
            if(!isOver){
                tmpFieldList->next = itemFieldList;
                tmpFieldList = tmpFieldList->next;
            }
        }
    }
    //ParamDec
    if (!isOver){
        paramDec = _varList->children[0];
        tmpFieldList->next = parseParamDec(paramDec);
    }
    return varFieldList;
}

FieldList *parseParamDec(Node paramDec) {
    //ParamDec: Specifier VarDec
    Type *type = parseSpecifier(paramDec->children[0]);
    FieldList *paramFieldList = NULL;
    if (type != NULL) {
        paramFieldList = parseVarDec(0, 1, paramDec->children[1], type);
    }
    return paramFieldList;
}

Type* parseFunDec(Node funDec, Type *type) {
    //type: function's returning type
    //FunDec: ID LP VarList Rp
    //       |ID LP RP
    Type *funDecType = (Type *) malloc(sizeof(Type));
    funDecType->structure = (FieldList *) malloc(sizeof(FieldList));
    Node id = funDec->children[0];
    funDecType->category = FUNCTION;
    funDecType->structure->name = id->value;
    funDecType->structure->type = type;
    //FUNCTION ID
    curTac->next = newTac(id->value, NULL, NULL, NULL);
    curTac->next->title = FUNC;
    curTac = curTac->next;
    if (funDec->number == 3) {
        //ID LP RP
        funDecType->structure->next = NULL;
    } else {
        Node varList = funDec->children[2];
        funDecType->structure->next = parseVarList(varList);
    }
    return funDecType;
}

Type *parseExp(int isAss, Node exp) {
    Node leftmost = exp->children[0];
    Type *result = NULL;
    //leftmost is Exp
    if (!strcmp(NDtypes[leftmost->type], "Exp")) {
        Node operator = exp->children[1];
        Node rightmost = exp->children[2];
        //Exp ASSIGN Exp
        if (!strcmp(NDtypes[operator->type], "ASSIGN")) {
            Type *leftmostType = parseExp(1, leftmost);
            Type *rightmostType = parseExp(0, rightmost);
            if (!((leftmost->number == 1 && !strcmp(NDtypes[leftmost->children[0]->type], "ID")) 
            || (leftmost->number == 3 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                !strcmp(NDtypes[leftmost->children[1]->type], "DOT"))
            || (leftmost->number == 4 && !strcmp(NDtypes[leftmost->children[0]->type], "Exp") &&
                !strcmp(NDtypes[leftmost->children[1]->type], "LB")))) {
                printf("Error type 6 at Line %d: left side in assignment is rvalue\n",
                leftmost->line);
                errorCnt++;
            } else if (!typecmp(leftmostType, rightmostType)) {
                printf("Error type 5 at Line %d: unmatching types on both sides of assignment\n",
                leftmost->line);
                errorCnt++;
            } else {
                result = leftmostType;
                char* target = leftmostType->tag;
                Hashmap* itml = findHashmap(leftmostType->tag);
                if (itml != NULL){
                    target = itml->value;
                }
                curTac->next = newTac(target, NULL, rightmostType->tag, NULL);
                curTac = curTac->next;
                curTac->title = ASS;
            }
        }
        //Exp AND Exp
        //Exp OR Exp
        else if (!strcmp(NDtypes[operator->type],"AND") || !strcmp(NDtypes[operator->type],"OR")) {
            Type *leftmostType = parseExp(0, leftmost);
            Type *rightmostType = parseExp(0, rightmost);
            if (typecmp(leftmostType, rightmostType) && leftmostType->category == PRIMITIVE && leftmostType->primitive == TINT){
                result = leftmostType;
            }else{
                printf("Error type 7 at Line %d: unmatching operands: %s\n", leftmost->line, NDtypes[operator->type]);
                errorCnt++;
            }
        }
        //Exp LT|LE|GT|GE|NE|EQ Exp
        else if(!strcmp(NDtypes[operator->type],"LT") || !strcmp(NDtypes[operator->type],"LE")
            || !strcmp(NDtypes[operator->type],"GT") || !strcmp(NDtypes[operator->type],"GE") 
            || !strcmp(NDtypes[operator->type],"NE") || !strcmp(NDtypes[operator->type],"EQ")) {
            Type *leftmostType = parseExp(0, leftmost);
            Type *rightmostType = parseExp(0, rightmost);
            if( leftmostType == NULL || rightmostType == NULL ||
            leftmostType->category != PRIMITIVE || rightmostType->category != PRIMITIVE){
                printf("Error type 7 at Line %d: unmatching operands: %s\n",
                leftmost->line, NDtypes[operator->type]);
                errorCnt;
            }else{
                result = (Type*)malloc(sizeof(Type));
                result->category = PRIMITIVE;
                result->primitive = TINT;
                int len = strlen(leftmostType->tag) + strlen(rightmostType->tag);
                char* oper = NULL;
                if(!strcmp(NDtypes[operator->type],"LT")){
                    len += 3;
                    oper = " < ";
                }else if (!strcmp(NDtypes[operator->type],"LE")){
                    len += 4;
                    oper = " <= ";
                }else if (!strcmp(NDtypes[operator->type],"GT")){
                    len += 3;
                    oper = " > ";
                }else if (!strcmp(NDtypes[operator->type],"GE")){
                    len += 4;
                    oper = " >= ";
                }else if (!strcmp(NDtypes[operator->type],"NE")){
                    len += 4;
                    oper = " != ";
                }else{
                    len += 4;
                    oper = " == ";
                }
                result->tag = (char*)malloc(sizeof(char) * len);
                strcat(result->tag, leftmostType->tag);
                strcat(result->tag, oper);
                strcat(result->tag, rightmostType->tag);
                printf("%s\n", result->tag);
            }
        }
        //Exp PLUS|MINUS|MUL|DIV Exp
        else if(!strcmp(NDtypes[operator->type],"PLUS") || !strcmp(NDtypes[operator->type],"MINUS")
            || !strcmp(NDtypes[operator->type],"MUL") || !strcmp(NDtypes[operator->type],"DIV")) {
            Type *leftmostType = parseExp(0, leftmost);
            Type *rightmostType = parseExp(0, rightmost);
            if(leftmostType == NULL || rightmostType == NULL ||
            leftmostType->category != PRIMITIVE || rightmostType->category != PRIMITIVE){
                printf("Error type 7 at Line %d: unmatching operands: %s\n",
                leftmost->line, NDtypes[operator->type]);
                errorCnt++;
            }else{
                result = (Type*)malloc(sizeof(Type));
                result->category = PRIMITIVE;
                if(leftmostType->primitive == TFLOAT || rightmostType->primitive == TFLOAT){
                    result->primitive = TFLOAT;
                }else{
                    result->primitive = TINT;
                }
                char* oper = NULL;
                if (!strcmp(NDtypes[operator->type],"PLUS")){
                    oper = "+";
                }else if (!strcmp(NDtypes[operator->type],"MINUS")){
                    oper =  "-";
                }else if (!strcmp(NDtypes[operator->type],"MUL")){
                    oper = "*";
                }else{
                    oper = "/";
                }
                char* key = (char*)malloc(sizeof(char) * (strlen(leftmostType->tag) + strlen(rightmostType->tag) + 1));
                strcat(key, leftmostType->tag);
                strcat(key, oper);
                strcat(key, rightmostType->tag);
                Hashmap* item = findHashmap(key);
                if(item == NULL){
                    result->tag = generateT(tCnt);
                    curTac-> next = newTac(result->tag, oper, leftmostType->tag, rightmostType->tag);
                    curTac = curTac->next;
                    curTac->title = OPER;
                    insertHashmap(key, result->tag);
                    tCnt++;
                }else{
                    result->tag = item->value;
                }
                printf("%s, %s\n", result->tag, key);
            }
        }else if(!strcmp(NDtypes[operator->type],"QM")){
            //Exp QM Exp COLON Exp
            Type *leftType = parseExp(0, leftmost);
            Type *midType = parseExp(0, rightmost);
            Type *rightType = parseExp(0, exp->children[4]);
            result = midType;
            if (leftType == NULL || leftType->category != PRIMITIVE || leftType->primitive != TINT){
                printf("Error type 7 at Line %d: unmatching operands: ..error.. ? ... : ...\n", leftmost->line);
                errorCnt++;
                result = NULL;
            }
            if(midType == NULL){
                printf("Error type 1 at Line %d: undefined variable: %s\n",
                rightmost->line, rightmost->value);
                errorCnt++;
                result = NULL;
            }else if(rightType == NULL){
                printf("Error type 1 at Line %d: undefined variable: %s\n",
                exp->children[4]->line, exp->children[4]->value);
                errorCnt++;
                result = NULL;
            }
            if (!typecmp(midType, rightType) || midType->category == FUNCTION || midType->category == ARRAY){
                printf("Error type 7 at Line %d: unmatching operands in sides of \':\'\n", leftmost->line);
                errorCnt++;
                result = NULL;
            }
        }else if(!strcmp(NDtypes[operator->type], "LB")){
            //Exp LB Exp RB
            Type *leftmostType = parseExp(0, leftmost);
            Type *rightmostType = parseExp(0, rightmost);
            if (leftmostType == NULL || leftmostType->category != ARRAY){
                printf("Error type 10 at Line %d: indexing on non-array variable\n", leftmost->line);
                errorCnt++;
                return NULL;
            }else if(rightmostType == NULL || rightmostType->category != PRIMITIVE || rightmostType->primitive != TINT){
                printf("Error type 12 at Line %d: index by non-integer\n", leftmost->line);
                errorCnt++;
                return NULL;
            }else{
                int unit = leftmostType->array->base->dec;
                // t? := unit * INT
                char* decs = generateT(tCnt);
                tCnt++;
                char num[10] = {0};
                char mrk[10] = "#";
                int len = countLength(unit) + 1;
                itoa(unit, num, 10);
                strcat(mrk, num);
                char* ost = (char*)malloc(sizeof(char)*len);
                strncpy(ost, mrk, len);
                curTac->next = newTac(decs, "*", rightmostType->tag, ost);
                curTac = curTac->next;
                curTac->title = OPER;
                // t? := addr + decs
                char* addr = generateT(tCnt);
                tCnt++;
                curTac->next = newTac(addr, "+", leftmostType->tag, decs);
                curTac = curTac->next;
                curTac->title = OPER;
                // t? := *addr
                if(leftmostType->array->base->category == ARRAY){
                    leftmostType->array->base->tag = addr;
                }else{
                    leftmostType->array->base->tag = generateT(tCnt);
                    tCnt++;
                    char* val = (char*)malloc(sizeof(char)*(strlen(addr) + 1));
                    strcat(val, "*");
                    strcat(val, addr);
                    insertHashmap(leftmostType->array->base->tag, val);
                    if (!isAss) {
                        curTac->next = newTac(leftmostType->array->base->tag, NULL, val, NULL);
                        curTac = curTac->next;
                        curTac->title = ASS;
                    }
                }
                result = leftmostType->array->base;
            }
        }else if(!strcmp(NDtypes[operator->type], "DOT")){
            //Exp DOT ID
            Type *leftmostType = parseExp(0, leftmost);
            if (leftmostType == NULL || leftmostType->category != STRUCTURE){
                printf("Error type 13 at Line %d: accessing with non-structure variable\n",
                leftmost->line);
                errorCnt++;
                return NULL;
            }else{
                FieldList* tmp = leftmostType->structure;
                int isError = 0;
                int offset = 0;
                while(tmp != NULL){
                    if(!strcmp(tmp->name, rightmost->value)){
                        isError = 1;
                        char* addr = NULL;
                        if (tmp->type->tag == NULL || strlen(tmp->type->tag) == 0){
                            if (offset > 0){
                                char num[10] = {0};
                                char mrk[10] = "#";
                                int len = countLength(offset) + 1;
                                itoa(offset, num, 10);
                                strcat(mrk, num);
                                char* ost = (char*)malloc(sizeof(char)*len);
                                strncpy(ost, mrk, len);
                                // t? := addr + offset;
                                addr = generateT(tCnt);
                                tCnt++;
                                curTac->next = newTac(addr, "+", leftmostType->tag, ost);
                                curTac = curTac->next;
                                curTac->title = OPER;
                            }else if (leftmostType->tag[0] == '&'){
                                // t? := &v?;
                                addr = generateT(tCnt);
                                tCnt++;
                                curTac->next = newTac(addr, NULL, leftmostType->tag, NULL);
                                curTac = curTac->next;
                                curTac->title = ASS;
                            }else{
                                // v?;
                                addr = leftmostType->tag;
                            }
                            // t? := *addr
                            if (tmp->type->category == STRUCTURE){
                                tmp->type->tag = addr;
                            }else{
                                tmp->type->tag = generateT(tCnt);
                                tCnt++;
                                char* val = (char*)malloc(sizeof(char)*(strlen(addr) + 1));
                                strcat(val, "*");
                                strcat(val, addr);
                                insertHashmap(tmp->type->tag, val);
                                if (!isAss) {
                                    curTac->next = newTac(tmp->type->tag, NULL, val, NULL);
                                    curTac = curTac->next;
                                    curTac->title = ASS;
                                }
                            }
                        }
                        break;
                    }
                    offset += tmp->type->dec;
                    printf("offset: %d\n", offset);
                    tmp = tmp->next;
                }
                if (!isError){
                    printf("Error type 14 at Line %d: no such member: %s\n", 
                    leftmost->line, rightmost->value);
                    errorCnt++;
                }else{
                    result = tmp->type;
                }
            }
        }
    }
    //LP Exp RP
    else if(!strcmp(NDtypes[leftmost->type],"LP")){
        result = parseExp(0, exp->children[1]);
    }
    //MINUS Exp
    else if(!strcmp(NDtypes[leftmost->type],"MINUS")){
        Type *leftmostType = parseExp(0, exp->children[1]);
        if (leftmostType == NULL || leftmostType->category != PRIMITIVE){
            printf("Error type 7 at Line %d: unmatching operands: MINUS\n", 
            leftmost->line);
            errorCnt++;
        }else{
            result = (Type*)malloc(sizeof(Type));
            result->category = PRIMITIVE;
            result->primitive = leftmostType->primitive;
            char* key = (char*)malloc(sizeof(char) * (strlen(leftmostType->tag) + 3));
            strcat(key, "#0");
            strcat(key, "-");
            strcat(key, leftmostType->tag);
            Hashmap* item = findHashmap(key);
            if (item == NULL){
                result->tag = generateT(tCnt);
                curTac-> next = newTac(result->tag, "-", "#0", leftmostType->tag);
                curTac = curTac->next;
                curTac->title = OPER;
                insertHashmap(key, result->tag);
                tCnt++;
            }else{
                result->tag = item->value;
            }
        }
    }
    //NOT Exp
    else if(!strcmp(NDtypes[leftmost->type],"NOT")){
        Type *leftmostType = parseExp(0, exp->children[1]);
        if (leftmostType == NULL || leftmostType->category != PRIMITIVE || leftmostType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands: NOT\n",
            leftmost->line);
            errorCnt++;
        }else{
            result = leftmostType;
        }
    }
    //ID LP Args RP
    //ID LP RP
    else if(!strcmp(NDtypes[leftmost->type],"ID")){
        Symbol* tmp = findGlobalSymbolEntry(leftmost->value);
        if(exp->number >= 3){
            if (tmp == NULL){
                printf("Error type 2 at Line %d: undefined function: %s\n",
                leftmost->line, leftmost->value);
                errorCnt++;
                return NULL;
            }else if(tmp->type == NULL || tmp->type->category != FUNCTION){
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n",
                leftmost->line, leftmost->value);
                errorCnt++;
                return NULL;
            }
            Type* tmpFuncType = tmp->type;
            if (exp->number == 4){
                Node args = exp->children[2];
                FieldList * tmpFuncVariablesList = tmpFuncType->structure->next;
                if (tmpFuncVariablesList == NULL){
                    printf("Error type 9 at Line %d: more the function %s's arguments than the declared parameters\n",
                            leftmost->line, leftmost->value);
                    errorCnt++;
                }else{
                    //Args: Exp COMMA Args
                    //     |Exp
                    Node argsExp = args->children[0];
                    FuncParamLinkNode* fir = (FuncParamLinkNode*)malloc(sizeof(FuncParamLinkNode));
                    fir->prev = NULL;
                    fir->next = NULL;
                    while(1){
                        Type* argsExpType = parseExp(0, argsExp);
                        if(argsExpType == NULL){
                            break;
                        }
                        if (!typecmp(argsExpType, tmpFuncVariablesList->type)){
                            printf("Error type 9 at Line %d: the function %s's arguments mismatch the declared parameters since type\n",
                                    leftmost->line, leftmost->value);
                            errorCnt++;
                            break;
                        }else{
                            fir->tag = (char*)malloc(sizeof(char) * strlen(argsExpType->tag));
                            strncpy(fir->tag, argsExpType->tag, strlen(argsExpType->tag));
                            fir->next = (FuncParamLinkNode*)malloc(sizeof(FuncParamLinkNode));
                            FuncParamLinkNode* tmp = fir;
                            fir = fir->next;
                            fir->prev = tmp;
                            tmpFuncVariablesList = tmpFuncVariablesList->next;
                            if (tmpFuncVariablesList == NULL && args->number == 1){
                                result = (Type*)malloc(sizeof(Type));
                                int success = deepcopyType(result, tmpFuncType->structure->type);
                                if (!success){
                                    free(result);
                                    result = NULL;
                                }
                                fir = fir->prev;
                                break;
                            }else if(tmpFuncVariablesList == NULL && args->number == 3){
                                printf("Error type 9 at Line %d: more the function %s's arguments than the declared parameters\n",
                                        leftmost->line, leftmost->value);
                                errorCnt++;
                                break;
                            }else if(tmpFuncVariablesList != NULL && args->number == 1){
                                printf("Error type 9 at Line %d: fewer the function %s's arguments than the declared parameters\n",
                                        leftmost->line, leftmost->value);
                                errorCnt++;
                                break;
                            }
                            args = args->children[2];
                            argsExp = args->children[0];
                        }
                    }
                    if(!strcmp(tmpFuncType->structure->name, "write")){
                        curTac->next = newTac(fir->tag, NULL, NULL, NULL);
                        curTac = curTac->next;
                        curTac->title = WRITE;
                    }else{
                        while (fir != NULL){
                            curTac->next = newTac(fir->tag, NULL, NULL, NULL);
                            curTac = curTac->next;
                            curTac->title = ARG;
                            fir = fir->prev;
                        }
                        result->tag = generateT(tCnt);
                        int calllen = strlen(tmpFuncType->structure->name) + 5;
                        char* arg1 = (char*)malloc(sizeof(char)*calllen);
                        strcat(arg1, "CALL ");
                        strcat(arg1, tmpFuncType->structure->name);
                        curTac->next = newTac(result->tag, NULL, arg1, NULL);
                        curTac = curTac->next;
                        curTac->title = ASS;
                        printf("%s, %s\n", result->tag, arg1);
                        tCnt++;
                    }
                }
            }else{
                if (tmpFuncType->structure->next == NULL){
                    result = (Type*)malloc(sizeof(Type));
                    int success = deepcopyType(result, tmpFuncType->structure->type);
                    if (!success){
                        free(result);
                        result = NULL;
                    }
                    if (!strcmp(tmpFuncType->structure->name, "read")){
                        result->tag = generateT(tCnt);
                        curTac->next = newTac(result->tag, NULL, NULL, NULL);
                        curTac = curTac->next;
                        curTac->title = READ;
                        tCnt++;
                    }
                }else{
                    printf("Error type 9 at Line %d: fewer the function %s's arguments than the declared parameters\n",
                    leftmost->line, leftmost->value);
                    errorCnt++;
                }
            }
        }else{
            //ID
            if (tmp == NULL){
                printf("Error type 1 at Line %d: undefined variable: %s\n",
                leftmost->line, leftmost->value);
                errorCnt++;
            }else{
                result = tmp->type;
            }
        }
    }else if(!strcmp(NDtypes[leftmost->type], "INT")){
        //INT
        char arg1[10] = "#";
        strcat(arg1, leftmost->value);
        char* key = (char*)malloc(sizeof(char) * (strlen(leftmost->value) + 1));
        strncpy(key, arg1, (strlen(leftmost->value) + 1));
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TINT;
        Hashmap* item = findHashmap(arg1);
        if (item == NULL){
            result->tag = generateT(tCnt);
            curTac->next = newTac(result->tag, NULL, key, NULL);
            curTac = curTac->next;
            curTac->title = ASS;
            insertHashmap(key, result->tag);
            printf("%s, %s\n", arg1, result->tag);
            tCnt++;
        }else{
            result->tag = item->value;
            printf("%s, %s\n", arg1, result->tag);
        }
    }else if(!strcmp(NDtypes[leftmost->type], "FLOAT")){
        //FLOAT
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TFLOAT;
    }else if(!strcmp(NDtypes[leftmost->type], "CHAR")){
        //CHAR
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        result->primitive = TCHAR;
    }
    return result; 
}

void parseCompSt(Node prev, Node compSt, Type* returnValType){
    //CompSt: LC DefList StmtList RC
    FieldList * defListFieldList = parseDefList(0, compSt->children[1], NULL);
    parseStmtList(prev, compSt->children[2], returnValType);
}

void parseStmtList(Node prev, Node stmtList, Type* returnValType){
    //StmtList: Stmt StmtList
    //         |NULL
    if(stmtList == NULL){
        return;
    }
    parseStmt(prev, stmtList->children[0], returnValType);
    parseStmtList(prev, stmtList->children[1], returnValType);
}

void parseStmt(Node prev, Node stmt, Type * returnValType){
    //Stmt: Exp SEMI
    //     |CompSt
    //     |RETURN Exp SEMI
    //     |BREAK SEMI
    //     |CONTINUE SEMI
    Node leftmost = stmt->children[0];
    if (!strcmp(NDtypes[leftmost->type],"Exp")){
        parseExp(0, leftmost);
    }else if(!strcmp(NDtypes[leftmost->type],"CompSt")){
        parseCompSt(prev, leftmost, returnValType);
    }else if(!strcmp(NDtypes[leftmost->type],"RETURN")){
        Node exp = stmt->children[1];
        Type* expType = parseExp(0, exp);
        if(expType == NULL){
            return;
        }else if(expType->category == FUNCTION){
            expType = expType->structure->type;
        }
        if(!typecmp(expType, returnValType)){
            printf("Error type 8 at Line %d: incompatiable return type\n",
            leftmost->line);
            errorCnt++;
        }else{
            curTac->next = newTac(expType->tag, NULL, NULL, NULL);
            curTac = curTac->next;
            curTac->title = RETURN;
        }
    }else if(!strcmp(NDtypes[leftmost->type],"IF")){
        //|IF LP Exp RP Stmt
        //|IF LP Exp RP Stmt ELSE Stmt
        Node exp = stmt->children[2];
        Type* expType = parseExp(0, exp);
        if (expType == NULL){
            return;
        }
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands in if statement\n", exp->line);
            errorCnt++;
        }
        int trueLabel = labelCnt;
        int falseLabel = labelCnt + 1;
        int len = 0;
        labelCnt += 2;
        //true condition
        char* trueTag = generateLabel(trueLabel);
        curTac->next = newTac(trueTag, NULL, expType->tag, NULL);
        curTac = curTac->next;
        curTac->title = IF;
        //false condition
        char* falseTag = generateLabel(falseLabel);
        curTac->next = newTac(falseTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = GOTO;
        //true label
        curTac->next = newTac(trueTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = LABEL;
        addLinkNode();
        parseStmt(prev, stmt->children[4], returnValType);
        //false label
        curTac->next = newTac(falseTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = LABEL;
        freeLinkNode();
        if (stmt->number == 7){
            addLinkNode();
            parseStmt(prev, stmt->children[6], returnValType);
            freeLinkNode();
        }
    }else if(!strcmp(NDtypes[leftmost->type],"WHILE")){
        //|WHILE LP Exp RP Stmt
        Node exp = stmt->children[2];
        Type* expType = parseExp(0, exp);
        if (expType == NULL){
            return;
        }
        if(expType->category != PRIMITIVE || expType->primitive != TINT){
            printf("Error type 7 at Line %d: unmatching operands in while statement\n", exp->line);
            errorCnt++;
        }

        int firstLabel = labelCnt;
        int trueLabel = labelCnt + 1;
        int falseLabel = labelCnt + 2;
        int len = 0;
        labelCnt += 3;
        //先来个标签

        char* firstTag = generateLabel(firstLabel);
        curTac->next = newTac(firstTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = LABEL;

        char* trueTag = generateLabel(trueLabel);
        curTac->next = newTac(trueTag, NULL, expType->tag, NULL);
        curTac = curTac->next;
        curTac->title = IF;

        char* falseTag = generateLabel(falseLabel);
        curTac->next = newTac(falseTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = GOTO;

        curTac->next = newTac(trueTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = LABEL;
        addLinkNode();
        parseStmt(leftmost, stmt->children[4], returnValType);

        curTac->next = newTac(firstTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = GOTO;

        curTac->next = newTac(falseTag, NULL, NULL, NULL);
        curTac = curTac->next;
        curTac->title = LABEL;
        freeLinkNode();
    }else if (!strcmp(NDtypes[leftmost->type],"BREAK")){
        //BREAK SEMI
        if (prev == NULL || strcmp(NDtypes[prev->type],"WHILE")){
            printf("Error type 18 at Line %d: improper break\n", leftmost->line);
            errorCnt++;
        }
    }else if (!strcmp(NDtypes[leftmost->type],"CONTINUE")){
        //CONTINUE SEMI
        if (prev == NULL || strcmp(NDtypes[prev->type],"WHILE")){
            printf("Error type 19 at Line %d: improper continue\n", leftmost->line);
            errorCnt++;
        }
    }
}

void parseExtDecList(Node extDecList, Type* type){
    //ExtDecList: VarDec 
    //           |VarDec COMMA ExtDecList
    Node varDec = extDecList->children[0];
    parseVarDec(0, 0, varDec, type);
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

void addReadFunc(){
    Type* readFunc = (Type*)malloc(sizeof(Type));
    readFunc->category = FUNCTION;
    readFunc->structure = (FieldList*)malloc(sizeof(FieldList));
    readFunc->structure->name = "read";
    readFunc->structure->type = (Type*)malloc(sizeof(Type));
    readFunc->structure->type->category = PRIMITIVE;
    readFunc->structure->type->primitive = TINT;
    readFunc->structure->next = NULL;
    insertSymbolEntry("read", readFunc);
}

void addWriteFunc(){
    Type* writeFunc = (Type*)malloc(sizeof(Type));
    writeFunc->category = FUNCTION;
    writeFunc->structure = (FieldList*)malloc(sizeof(FieldList));
    writeFunc->structure->name = "write";
    writeFunc->structure->type = NULL;
    writeFunc->structure->next = (FieldList*)malloc(sizeof(FieldList));
    writeFunc->structure->next->next = NULL;
    writeFunc->structure->next->type = (Type*)malloc(sizeof(Type));
    writeFunc->structure->next->type->category = PRIMITIVE;
    writeFunc->structure->next->type->primitive = TINT;
    insertSymbolEntry("write", writeFunc);
}

char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned unum;
    int i=0,j,k;
    if(radix==10&&num<0){
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
 
    }while(unum);
    str[i]='\0';
    if(str[0]=='-') k=1;
    else k=0;
    char temp;
    for(j=k;j<=(i-1)/2;j++){
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}

int countLength(int num){
    int cnt = 0;
    while (num > 0)
    {
        cnt++;
        num /= 10;
    }
    return cnt == 0 ? 1 : cnt;
}