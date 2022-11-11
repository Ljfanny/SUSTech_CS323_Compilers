/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    TYPE = 262,
    STRUCT = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    RETURN = 267,
    CONST = 268,
    NOT = 269,
    SEMI = 270,
    COMMA = 271,
    ASSIGN = 272,
    PLUS_ASSIGN = 273,
    MINUS_ASSIGN = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    LT = 278,
    LE = 279,
    GT = 280,
    GE = 281,
    NE = 282,
    EQ = 283,
    QUESTION_MARK = 284,
    COLON = 285,
    PLUS = 286,
    MINUS = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    DOUBLE_PLUS = 291,
    DOUBLE_MINUS = 292,
    OR = 293,
    AND = 294,
    LP = 295,
    RP = 296,
    LB = 297,
    RB = 298,
    DOT = 299,
    LC = 300,
    RC = 301,
    ERROR = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef struct node* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
