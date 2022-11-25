%{
    #include "lex.yy.c"
    #include "node.h"
    #include "semantic.h"
    #include <stdio.h>
    #include <stdlib.h>

    struct node* tmpcld[10];
    int tmpnum = 0;
    enum myYYTYPE{
        PROGRAm = 37, 
        EXTDEFLISt,
        EXTDEf, SPECIFIEr, EXTDECLISt, STRUCTSPECIFIEr,
        VARDEc, FUNDEc, VARLISt, PARAMDEc,
        COMPSt, STMTLISt, STMt, DEFLISt,
        DEf, DECLISt, DEc, ARGs, EXp
    };
    int errors = 0;
    void yyerror(const char*);
    int getLine();

    #define MISSING_SEMI_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing semicolon ';'\n", er->line); \
    }
    #define MISSING_RP_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n", er->line); \
    }
    #define MISSING_SPECIFIER_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing specifier\n", er->line); \
    }
    
%}
%define api.value.type {struct node*}
%token INT FLOAT CHAR
%token ID
%token TYPE
%token STRUCT IF ELSE WHILE RETURN BREAK CONTINUE
%token NOT
%token SEMI COMMA
%token ASSIGN
%token LT LE GT GE NE EQ
%token PLUS MINUS
%token MUL DIV MOD
%token OR
%token AND
%token QM COLON
%token LP RP LB RB DOT
%token LC RC
%token ERROR
%right ASSIGN
%right NOT
%left OR
%left AND
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD
%left COMMA DOT
%nonassoc LP RP LB RB LC RC
%nonassoc SEMI
%nonassoc ELSE
%%
Program: ExtDefList 
    {$$= newNodeNTER(PROGRAm, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    if(errors == 0) {parseProgram($$);}}
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
    | error FunDec CompSt 
    { $$= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = $2; tmpcld[1] = $3; setNode($$, tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR($$);}
    | Specifier error
    {$$= newNodeNTER(EXTDEf, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
    | Specifier ExtDecList error
    {$$= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($2);}
    | error SEMI
    {errors++;}
    ;

ExtDecList: VarDec 
    {$$= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | VarDec COMMA ExtDecList 
    {$$= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    ;

Specifier: 
    TYPE
    {$$= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    | StructSpecifier
    {$$= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;

StructSpecifier: 
    STRUCT ID LC DefList RC  
    {$$= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 5;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $4;
    tmpcld[4] = $5; setNode($$, tmpcld, tmpnum);}
    | STRUCT ID 
    {$$= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    ;

VarDec: ID 
    {$$= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    |ERROR
    {$$= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    errors++;}
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
    | ID LP VarList error 
    {$$= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($3);}
    | ID LP error 
    {$$= newNodeNTER(FUNDEc, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($2);}
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
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    setNode($$, tmpcld, tmpnum);}
    | BREAK SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2;
    setNode($$, tmpcld, tmpnum);}
    | CONTINUE SEMI
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2;
    setNode($$, tmpcld, tmpnum);}
    | BREAK error
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
    | CONTINUE error
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
    | RETURN Exp error 
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($2);}
    | IF LP Exp RP Stmt
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
    |Exp error
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($1);}
    | IF LP Exp error Stmt ELSE Stmt 
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 6;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $5;
    tmpcld[4] = $6; tmpcld[5] = $7; setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($3);}
    | IF LP Exp error Stmt
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $5;
    setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($3);}
    | WHILE LP Exp error Stmt
    {$$= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; tmpcld[3] = $5;
    setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($3);}
    ;


DefList: Def DefList
    {$$= newNodeNTER(DEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);}
    |{$$ = NULL;}
    ;

Def: Specifier DecList SEMI
    {$$= newNodeNTER(DEf, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    setNode($$, tmpcld, tmpnum);}
    | Specifier DecList error 
    {$$= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = $1; tmpcld[1] = $2;
    setNode($$, tmpcld, tmpnum);
    MISSING_SEMI_ERROR($2);}
    | error DecList SEMI 
    {$$= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = $2; tmpcld[1] = $3;
    setNode($$, tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR($$);}
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
    | Exp MOD Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | LP Exp RP
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | MINUS Exp
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
    | Exp QM Exp COLON Exp
    {$$ = newNodeNTER(EXp, getLine()); tmpnum = 5;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3;
    tmpcld[3] = $4; tmpcld[4] = $5; setNode($$, tmpcld, tmpnum);}
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
    | Exp ERROR Exp
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);
    errors++;}
    |ERROR
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 1; tmpcld[0] = $1;
    setNode($$, tmpcld, tmpnum); errors++;}
    | LP Exp error
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = $1;
    tmpcld[1] = $2; setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($2);}
    | ID LP Args error
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = $1;
    tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);
    MISSING_RP_ERROR($3);}
    | ID LP error 
    {$$= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = $1;
    tmpcld[1] = $2; setNode($$, tmpcld, tmpnum); 
    MISSING_RP_ERROR($2); }
    ;

Args: Exp COMMA Args
    {$$= newNodeNTER(ARGs, getLine()); tmpnum = 3;
    tmpcld[0] = $1; tmpcld[1] = $2; tmpcld[2] = $3; setNode($$, tmpcld, tmpnum);}
    | Exp
    {$$= newNodeNTER(ARGs, getLine()); tmpnum = 1;
    tmpcld[0] = $1; setNode($$, tmpcld, tmpnum);}
    ;
%%
void yyerror(const char *s) {}
int getLine(){
    return yylineno;
}
int main(){
    yyparse();
    return 0;
}