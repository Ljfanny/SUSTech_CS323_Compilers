%{
    #include "lex.yy.c"
    #include "node.h"
    #include <stdio.h>
    #include <stdlib.h>
    // #define YYSTYPE struct node*
    struct node* tmpcld[10];
    int tmpnum;
    enum myYYTYPE{
        PROGRAm = 33, 
        EXTDEFLISt,
        EXTDEf, SPECIFIEr, EXTDECLISt, STRUCTSPECIFIEr,
        VARDEc, FUNDEc, VARLISt, PARAMDEc,
        COMPSt, STMTLISt, STMt, DEFLISt,
        DEf, DECLISt, DEc, ARGs, EXp
    };

    void yyerror(const char*);
    int getLine();
    int yylex();
%}
%define api.value.type {struct node*}

%nonassoc PREFIX_IF_ELSE
%token ELSE
%token TYPE STRUCT IF WHILE RETURN
%token INT FLOAT CHAR
%token ID
%token ASSIGN
%token OR
%token AND
%token LT LE GT GE NE EQ
%nonassoc MINUS_EXP
%token PLUS MINUS
%token MUL DIV
%token NOT
%token LP RP LB RB DOT
%token SEMI COMMA
%token LC RC
%%
Program: ExtDefList 
    {$$= newNodeNTER(PROGRAm, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum); treePrint($$);}
    ;   

ExtDefList: ExtDef ExtDefList 
    {$$= newNodeNTER(EXTDEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    | {$$=NULL;}
    ;

ExtDef: Specifier ExtDecList SEMI 
    {$$= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Specifier SEMI 
    {$$= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    | Specifier FunDec CompSt 
    {$$= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    ;

ExtDecList: VarDec 
    {$$= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | VarDec COMMA ExtDecList 
    {$$= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    ;

Specifier: TYPE
    {$$= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    |StructSpecifier
    {$$= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;

StructSpecifier: STRUCT ID LC DefList RC  
    {$$= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 5;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4; tmpcld[4] = $5; setNode($$, tmpcld, tmpnum);}
    | STRUCT ID 
    {$$= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    ;

VarDec: ID 
    {$$= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | VarDec LB INT RB 
    {$$= newNodeNTER(VARDEc, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4;
    setNode($$, tmpcld, tmpnum);}
    ;

FunDec: ID LP VarList RP 
    {$$= newNodeNTER(FUNDEc, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4; setNode($$, tmpcld, tmpnum);}
    | ID LP RP 
    {$$= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    ;

VarList: ParamDec COMMA VarList 
    {$$= newNodeNTER(VARLISt, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | ParamDec
    {$$= newNodeNTER(VARLISt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;

ParamDec: Specifier VarDec 
        {$$= newNodeNTER(PARAMDEc, getLine()); tmpnum = 2;
        tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    ;


CompSt: LC DefList StmtList RC 
        {$$= newNodeNTER(COMPSt, getLine()); tmpnum = 4;
        tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4;
        setNode($$, tmpcld, tmpnum);}
    ;

StmtList: Stmt StmtList 
    {$$= newNodeNTER(STMTLISt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    |{$$ = NULL;}
    ;

Stmt: Exp SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    | CompSt
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | RETURN Exp SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | IF LP Exp RP Stmt %prec PREFIX_IF_ELSE 
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4; tmpcld[4] = $5;
    setNode($$, tmpcld, tmpnum);}
    | IF LP Exp RP Stmt ELSE Stmt 
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 7;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4; tmpcld[4] = $5;
    tmpcld[5] = $6; tmpcld[6] = $7; setNode($$, tmpcld, tmpnum);}
    | WHILE LP Exp RP Stmt
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4; tmpcld[4] = $5;
    setNode($$, tmpcld, tmpnum);}
    ;


DefList: Def DefList
    {$$= newNodeNTER(DEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    |{$$ = NULL;}
    ;

Def: Specifier DecList SEMI
    {$$= newNodeNTER(DEf, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    ;

DecList: Dec
    {$$= newNodeNTER(DECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | Dec COMMA DecList
    {$$= newNodeNTER(DECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    setNode($$, tmpcld, tmpnum);}
    ;

Dec: VarDec
    {$$= newNodeNTER(DEc, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | VarDec ASSIGN Exp
    {$$= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    setNode($$, tmpcld, tmpnum);}
    ;


Exp: Exp ASSIGN Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp AND Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp OR Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp LT Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp LE Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp GT Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp GE Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp NE Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp EQ Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp PLUS Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp MINUS Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp MUL Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp DIV Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | LP Exp RP
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | MINUS Exp %prec MINUS_EXP
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    | NOT Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    | ID LP Args RP
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    tmpcld[3] = $4; setNode($$, tmpcld, tmpnum);}
    | ID LP RP
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp LB Exp RB
    {$$ = newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    tmpcld[3] = $4; setNode($$, tmpcld, tmpnum);}
    | Exp DOT ID
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | ID
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | INT
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | FLOAT
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | CHAR
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;
Args: Exp COMMA Args
    {$$= newNodeNTER(ARGs, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp
    {$$= newNodeNTER(ARGs, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;
%%
void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int getLine(){
    return yylineno;
}
int main(){
    yyparse();
    return 0;
}