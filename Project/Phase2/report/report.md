# Project Phase 2 Report

| SID      | Name   | Rate |
| -------- | ------ | ---- |
| 11911202 | 袁恒宸 | 1/3  |
| 12011543 | 林洁芳 | 1/3  |
| 12011906 | 汤奕飞 | 1/3  |

## Basic

//basic有啥好说的吗~感觉贴点代码就超了

## Bonus

### Different scopes

Revoke Assumption 6, thus variables in different scopes can share the same identifier, and variables defined in the outer scope will be shadowed by the inner variables with the same identifier

//这个在哪儿实现的呀QAQ

### Structural equivalence for struct

Revoke Assumption 7, then two struct is equivalent if they have the same number of each attribute

```c
else{
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
```

### Recognization continue and break

in lex.l

```c
"break" {yylval = newNodeTER(BREAk,yylineno); return BREAK;}
"continues" {yylval = newNodeTER(CONTINUEs,yylineno); return CONTINUES;}
```

in syntax.y

```c
Stmt: Exp SEMI
    ...
    | BREAK SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2;
    setNode($$, tmpcld, tmpnum);}
    | CONTINUES SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2;
    setNode($$, tmpcld, tmpnum);}
    | BREAK error
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
    | CONTINUES error
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
	...
    ;
```

in semantic.c

```c
else if(!strcmp(NDtypes[leftmost->type],"WHILE")){
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
```

### ...? ...: ...

Similar as phase1, we support ternary operator

```c
else if(!strcmp(NDtypes[operator->type],"QM")){
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
}
```

### Multidimensional nested array

//这个也不知道在哪

### Comparison of basic data types

//这个咋描述

```c
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
```

### Rules of +-*/

When there are no non-primitive types on either side of the operator symbol, float will be returned if there is a float, and int will be returned if both are int

```c
// Exp PLUS|MINUS|MUL|DIV Exp
else if(!strcmp(NDtypes[operator->type],"PLUS") || !strcmp(NDtypes[operator->type],"MINUS")
        || !strcmp(NDtypes[operator->type],"MUL") || !strcmp(NDtypes[operator->type],"DIV")) {
    Type *leftmostType = parseExp(leftmost);
    Type *rightmostType = parseExp(rightmost);
    if(leftmostType == NULL || rightmostType == NULL
       || leftmostType->category != PRIMITIVE || rightmostType->category != PRIMITIVE){
        printf("Error type 7 at Line %d: unmatching operands: %s\n",
               leftmost->line, NDtypes[operator->type]);
    }else{
        result = (Type*)malloc(sizeof(Type));
        result->category = PRIMITIVE;
        if(leftmostType->primitive == TFLOAT || rightmostType->primitive == TFLOAT){
            result->primitive = TFLOAT;
        }else{
            result->primitive = TINT
        }
    }
}
```

### 4 more error types

#### type 16

using a non-structure variable as struct

#### type 17

using struct without defination

```c
else if (!strcmp(NDtypes[leftmost->type], "StructSpecifier")) {
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
```

#### type 18

using break without loop

#### type 19

using continues without loop

```c
else if (!strcmp(NDtypes[leftmost->type],"BREAK")){
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
```

