%{
    #include "node.h"
    #include <string.h>
    #include "syntax.tab.h"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    enum ND_TYPE {
        TYPe = 0,
        INt,
        FLOAt,
        CHAr,
        Id,
        STRUCt, If, WHILe, ELSe, RETURn,
        DOt,
        SEMi,
        COMMa,
        ASSIGn,
        Lt, Le, Gt, Ge,
        Ne,
        Eq,
        ANd,
        Or,
        NOt,
        PLUs, MINUs, MUl, DIv,
        Lp, Rp, Lb, Rb,
        Lc, Rc
    };
    // int yycolumn = 1;
    int lines = 1;
    // int charPos = 1;
    // int spc = 5;
    // int ter = 33;
    // int non_ter = 52;
    // typeA-0, typeB-1
    // int errorType = -1;
    // void adjust(void);
    // #define YY_USER_ACTION 
    //     yylloc->begin.line = yylloc->end.line = yylineno; \
    //     yylloc->begin.column = yycolumn; yylloc->end.column = yycolumn+yyleng-1; \
    //     yycolumn += yyleng;
%}
/* %option yylineno */
%option yylineno
LETTER [a-zA-Z]
LETTER_ {LETTER}|_
DIGIT [0-9]
DIGIT_HEX [0-9A-Fa-f]
INT32_DEC 0|([1-9]{DIGIT}*)
INT32_HEX 0[xX]{DIGIT_HEX}+
FLOAT32 {DIGIT}+\.{DIGIT}+

CHAR '(([ -~])|(\\x[0-9a-fA-F]{2}))'
ID {LETTER_}({LETTER_}|{DIGIT}){0,31}
INT_HEX_ERROR [+-]?0x[0-9a-zA-Z]+
CHAR_ERROR '\\x[0-9a-zA-Z]*'
ID_ERROR [_a-zA-Zs0-9]*

TEST [$@&'|']+

/* INT_LEADING0 0{DIGIT}+
INT_INVALID_HEX 0[xX]{DIGIT_HEX}*[g-zG-Z]+{DIGIT_HEX}*
CHAR_DOUBLE0S '\\[xX]00'
CHAR_MORE_HEX '\\[xX]{DIGIT_HEX}{3,}'
CHAR_INVALID_HEX '\\[xX]{DIGIT_HEX}*[^0-9a-fA-F]+{DIGIT_HEX}*' */

/* ID_INVALID {DIGIT}+{LETTER_}+{DIGIT}* */

%%

"//".* {}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {}
[ \t\r]+ {}
"\n" {lines++;}

"int" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}
"float" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}
"char" {yylval = newNodeNL(TYPe,yylineno,yytext); return TYPE;}

"struct" {yylval = newNodeTER(STRUCt,yylineno); return STRUCT;}
"if" {yylval = newNodeTER(If,yylineno); return IF;}
"else" {yylval = newNodeTER(ELSe,yylineno); return ELSE;}
"while" {yylval = newNodeTER(WHILe,yylineno); return WHILE;}
"return" {yylval = newNodeTER(RETURn,yylineno); return RETURN;}

"." {yylval = newNodeTER(DOt,yylineno); return DOT;}
";" {yylval = newNodeTER(SEMi,yylineno); return SEMI;}
"," {yylval = newNodeTER(COMMa,yylineno); return COMMA;}
"=" {yylval = newNodeTER(ASSIGn,yylineno); return ASSIGN;}
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

{TEST} {
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    // errorType = 0;
    return ERROR;
}

{CHAR_ERROR} {
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    // errorType = 0;
    return ERROR;
}

{ID} {
    yylval = newNodeNL(Id,yylineno,yytext);
    return ID;
}

{ID_ERROR} {
    printf("Error type A at Line %d: unknown lexeme %s\n", yylineno, yytext);
    yylval = newNodeNL(-1, yylineno, yytext);
    // errorType = 0;
    return ERROR;
}

%%

/* int main(int argc, char **argv){
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        yylex();
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
} */

/* void adjust(void){
    EM_tokPos=charPos;
    charPos+=yyleng;
} */