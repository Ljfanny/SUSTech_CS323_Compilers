%{
    #include "node.h"
    #include <string.h>
    #include "syntax.tab.h"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    enum ND_TYPE {
        TYPe = 0,
        INt, FLOAt, CHAr, Id,
        STRUCt, If, WHILe, ELSe, RETURn, BREAk, CONTINUEs,
        DOt, SEMi, COMMa, ASSIGn, Qm, COLOn,
        Lt, Le, Gt, Ge, Ne, Eq,
        ANd, Or, NOt,
        PLUs, MINUs, MUl, DIv,
        Lp, Rp, Lb, Rb, Lc, Rc
    };
%}
/* %option yylineno */
%option yylineno
LETTER [a-zA-Z]
LETTER_ {LETTER}|_
DIGIT [0-9]
DIGIT_HEX [0-9A-Fa-f]
INT32_DEC {DIGIT}+
INT32_HEX 0[xX]{DIGIT_HEX}+
FLOAT32 {DIGIT}+\.{DIGIT}+

CHAR '(([ -~·])|(\\x[0-9a-fA-F]{2}))'
ID {LETTER_}({LETTER_}|{DIGIT}){0,31}
INT_HEX_ERROR [+-]?0[xX][0-9a-zA-Z]+
CHAR_ERROR '\\x[0-9a-zA-Z]*'
%%

"//".* {}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {}
[ \t\r]+ {}
"\n" {}

"int" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}
"float" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}
"char" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}
"void" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}

"struct" {yylval = newNodeTER(STRUCt,yylineno); return STRUCT;}
"if" {yylval = newNodeTER(If,yylineno); return IF;}
"else" {yylval = newNodeTER(ELSe,yylineno); return ELSE;}
"while" {yylval = newNodeTER(WHILe,yylineno); return WHILE;}
"return" {yylval = newNodeTER(RETURn,yylineno); return RETURN;}
"break" {yylval = newNodeTER(BREAk,yylineno); return BREAK;}
"continues" {yylval = newNodeTER(CONTINUEs,yylineno); return CONTINUES;}

"." {yylval = newNodeTER(DOt,yylineno); return DOT;}
";" {yylval = newNodeTER(SEMi,yylineno); return SEMI;}
"," {yylval = newNodeTER(COMMa,yylineno); return COMMA;}
"=" {yylval = newNodeTER(ASSIGn,yylineno); return ASSIGN;}
"?" {yylval = newNodeTER(Qm,yylineno); return QM;}
":" {yylval = newNodeTER(COLOn,yylineno); return COLON;}

"<" {yylval = newNodeTER(Lt,yylineno); return LT;}
"<=" {yylval = newNodeTER(Le,yylineno); return LE;}
">" {yylval = newNodeTER(Gt,yylineno); return GT;}
">=" {yylval = newNodeTER(Ge,yylineno); return GE;}
"!=" {yylval = newNodeTER(Ne,yylineno); return NE;}
"==" {yylval = newNodeTER(Eq,yylineno); return EQ;}
"&&" {yylval = newNodeTER(ANd,yylineno); return AND;}
"||" {yylval = newNodeTER(Or,yylineno); return OR;}
"!" {yylval = newNodeTER(NOt,yylineno); return NOT;}
"+" {yylval = newNodeTER(PLUs,yylineno); return PLUS;}
"-" {yylval = newNodeTER(MINUs,yylineno); return MINUS;}
"*" {yylval = newNodeTER(MUl,yylineno); return MUL;}
"/" {yylval = newNodeTER(DIv,yylineno); return DIV;}

"(" {yylval = newNodeTER(Lp,yylineno); return LP;}
")" {yylval = newNodeTER(Rp,yylineno); return RP;}
"[" {yylval = newNodeTER(Lb,yylineno); return LB;}
"]" {yylval = newNodeTER(Rb,yylineno); return RB;}
"{" {yylval = newNodeTER(Lc,yylineno); return LC;}
"}" {yylval = newNodeTER(Rc,yylineno); return RC;}

{ID} {
    yylval = newNodeNL(Id,yylineno,yytext);
    return ID;
}

{INT32_DEC} {
    yylval = newNodeNL(INt,yylineno,yytext);
    return INT;
}

{INT32_HEX} {
    yylval = newNodeNL(INt,yylineno,yytext);
    return INT;
}

{FLOAT32} {
    yylval = newNodeNL(FLOAt,yylineno,yytext);
    return FLOAT;
}

{INT_HEX_ERROR} {
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    return ERROR;
}

{CHAR} {
    yylval = newNodeNL(CHAr,yylineno,yytext);
    return CHAR;
}

{CHAR_ERROR} {
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    // errorType = 0;
    return ERROR;
}

[^0-9a-zA-Z_'\\\(\)\[\]\{\}\;\,\+\-\*\/] {
    printf("Error type A at Line %d: unknown lexeme %s\n",yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    return ERROR;
}

[0-9]*{ID} {
    printf("Error type A at Line %d: unknown lexeme %s\n",yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    return ERROR;
}

%%