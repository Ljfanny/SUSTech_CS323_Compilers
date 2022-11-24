/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntax.y" /* yacc.c:339  */

    #include "lex.yy.c"
    #include "node.h"
    #include "semantic.h"
    #include <stdio.h>
    #include <stdlib.h>

    struct node* tmpcld[10];
    int tmpnum = 0;
    enum myYYTYPE{
        PROGRAm = 35, 
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
    

#line 102 "syntax.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    BREAK = 268,
    CONTINUES = 269,
    NOT = 270,
    SEMI = 271,
    COMMA = 272,
    ASSIGN = 273,
    LT = 274,
    LE = 275,
    GT = 276,
    GE = 277,
    NE = 278,
    EQ = 279,
    PLUS = 280,
    MINUS = 281,
    MUL = 282,
    DIV = 283,
    MOD = 284,
    OR = 285,
    AND = 286,
    LP = 287,
    RP = 288,
    LB = 289,
    RB = 290,
    DOT = 291,
    LC = 292,
    RC = 293,
    ERROR = 294
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

/* Copy the second part of user declarations.  */

#line 193 "syntax.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    70,    73,    76,    79,    82,    85,    89,
      93,    97,   101,   104,   110,   113,   119,   123,   128,   131,
     135,   141,   144,   147,   152,   158,   161,   166,   171,   177,
     180,   183,   186,   189,   193,   197,   201,   205,   209,   213,
     217,   221,   225,   229,   234,   239,   247,   250,   253,   257,
     262,   269,   272,   278,   281,   287,   290,   293,   296,   299,
     302,   305,   308,   311,   314,   317,   320,   323,   326,   329,
     332,   335,   338,   342,   345,   349,   352,   355,   358,   361,
     364,   368,   371,   375,   379,   385,   388
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "BREAK", "CONTINUES", "NOT",
  "SEMI", "COMMA", "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "OR", "AND", "LP", "RP", "LB", "RB", "DOT",
  "LC", "RC", "ERROR", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -48

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,    50,   -59,     3,    11,   -59,   118,    13,   -59,    -1,
     -59,    20,    27,   -59,   -59,   -59,    -1,   -59,   -59,     1,
     172,    20,    25,   211,   -59,    17,   -59,   -59,    -5,    84,
     -59,   -59,   -59,    -5,    26,    73,    -5,    -5,   257,   211,
      54,   -59,   -59,    58,    57,   -59,   -59,    53,   -11,    78,
      99,   113,   -59,   -59,   -59,    63,    66,    89,   241,   220,
     237,   241,   241,   241,   -59,   -59,    85,   257,    49,   -59,
     -59,   -59,   -59,   241,   -59,    -5,   -59,   -59,   226,   241,
     241,    81,   -59,   -59,   -59,   -59,   345,   248,   112,   -59,
     -59,   -59,   -59,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   116,   241,
     324,   -59,   -59,   -59,   280,    29,   143,   174,   -59,   -59,
     -59,   -59,   324,   402,   402,   402,   402,   402,   402,   248,
     248,   -26,   -26,   -26,   366,   387,   302,   -59,   324,   241,
     -59,   -59,   257,   257,   257,   257,   -59,   -59,   114,   117,
     -59,   -59,   257,   257,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,     0,     0,     2,     0,     0,    15,     0,
      11,     0,    17,     1,     3,     9,    18,     6,    19,     0,
      12,     0,     0,     0,     8,     0,    10,     5,     0,     0,
       7,    24,    22,     0,     0,    26,     0,     0,    30,     0,
       0,    18,    13,     0,    27,    23,    21,     0,    53,     0,
      51,     0,    77,    78,    79,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    32,     0,    30,     0,    46,
      16,    20,    25,     0,    50,     0,    49,    48,     0,     0,
       0,     0,    36,    34,    37,    35,    71,    70,     0,    28,
      29,    42,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    52,    84,    73,    86,     0,     0,     0,    38,    33,
      82,    69,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    57,    56,     0,    75,    80,     0,
      83,    72,     0,     0,     0,     0,    74,    85,    44,    39,
      45,    41,     0,     0,    43,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   122,   -59,   119,     6,   -59,    56,   142,   103,
     -59,    75,    86,   290,   203,   -59,   -21,   -59,   -58,    15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    19,    37,     8,    48,    11,    34,
      35,    65,    66,    67,    38,    39,    49,    50,    68,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    41,    26,    86,    87,    88,     7,    73,   107,    12,
     108,    13,     7,   109,    15,   110,    51,    27,    36,    16,
     114,   116,   117,    29,     2,     3,    31,    45,    33,    17,
     140,    22,     2,     3,    18,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      91,   138,    18,    33,   111,   -47,     9,    23,    32,    46,
       2,     3,   141,    20,    25,    92,    10,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   114,   118,   107,    20,   108,    24,    43,   109,    44,
      47,    29,    70,    71,    74,    78,    30,   119,    79,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   120,    76,   107,    75,   108,    -4,     1,
     109,    80,   137,    89,   152,     2,     3,   153,    14,    77,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   142,   121,   107,    42,   108,    21,
      72,   109,     0,    90,   147,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   144,   143,   107,     0,   108,
       0,     0,   109,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    29,   145,   107,     0,
     108,     0,    36,   109,   -47,   -47,   -47,   -47,     2,     3,
     -47,    82,   -47,   -47,   -47,   -47,   -47,   112,    40,    52,
      53,    54,    55,     0,     0,     0,    83,   -47,    84,     0,
       0,    61,    69,   -47,    52,    53,    54,    55,   -47,   -47,
     -47,     0,    62,    85,     0,     0,    61,     0,    63,   113,
      52,    53,    54,    55,     0,    64,    56,    62,    57,    58,
      59,    60,    61,    63,     0,   102,   103,   104,     0,     0,
      64,     0,   107,    62,   108,     0,     0,   109,     0,    63,
       0,     0,     0,     0,    23,     0,    64,   139,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,     0,   108,     0,     0,   109,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   146,   108,     0,
       0,   109,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,     0,
     108,     0,     0,   109,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   107,
       0,   108,     0,     0,   109,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   106,     0,     0,
     107,     0,   108,     0,     0,   109,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,   107,     0,   108,     0,     0,   109,   100,   101,   102,
     103,   104,   148,   149,   150,   151,   107,     0,   108,     0,
       0,   109,   154,   155
};

static const yytype_int16 yycheck[] =
{
      58,     6,     1,    61,    62,    63,     0,    18,    34,     6,
      36,     0,     6,    39,     1,    73,    37,    16,     1,     6,
      78,    79,    80,    34,     7,     8,     1,     1,    22,    16,
       1,    32,     7,     8,    39,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       1,   109,    39,    47,    75,    38,     6,    37,    33,    33,
       7,     8,    33,     7,    37,    16,    16,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   139,     1,    34,    28,    36,    11,     3,    39,    33,
      17,    34,    38,    35,    16,    32,    21,    16,    32,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     1,     1,    34,    17,    36,     0,     1,
      39,    32,     6,    38,    10,     7,     8,    10,     6,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     1,    33,    34,    28,    36,     7,
      47,    39,    -1,    67,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     1,    33,    34,    -1,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    34,    33,    34,    -1,
      36,    -1,     1,    39,     3,     4,     5,     6,     7,     8,
       9,     1,    11,    12,    13,    14,    15,     1,    25,     3,
       4,     5,     6,    -1,    -1,    -1,    16,    26,     1,    -1,
      -1,    15,    39,    32,     3,     4,     5,     6,    37,    38,
      39,    -1,    26,    16,    -1,    -1,    15,    -1,    32,    33,
       3,     4,     5,     6,    -1,    39,     9,    26,    11,    12,
      13,    14,    15,    32,    -1,    27,    28,    29,    -1,    -1,
      39,    -1,    34,    26,    36,    -1,    -1,    39,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    -1,    36,    -1,    -1,    39,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    -1,
      -1,    39,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      36,    -1,    -1,    39,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      -1,    36,    -1,    -1,    39,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      34,    -1,    36,    -1,    -1,    39,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    39,    25,    26,    27,
      28,    29,   142,   143,   144,   145,    34,    -1,    36,    -1,
      -1,    39,   152,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    41,    42,    43,    45,    46,     6,
      16,    48,     6,     0,    42,     1,     6,    16,    39,    44,
      47,    48,    32,    37,    51,    37,     1,    16,    17,    34,
      51,     1,    33,    45,    49,    50,     1,    45,    54,    55,
      54,     6,    44,     3,    47,     1,    33,    17,    47,    56,
      57,    56,     3,     4,     5,     6,     9,    11,    12,    13,
      14,    15,    26,    32,    39,    51,    52,    53,    58,    54,
      38,    35,    49,    18,    16,    17,     1,    16,    32,    32,
      32,    58,     1,    16,     1,    16,    58,    58,    58,    38,
      52,     1,    16,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    34,    36,    39,
      58,    56,     1,    33,    58,    59,    58,    58,     1,    16,
       1,    33,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,     6,    58,    17,
       1,    33,     1,    33,     1,    33,    35,    59,    53,    53,
      53,    53,    10,    10,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      47,    48,    48,    48,    48,    49,    49,    50,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       3,     2,     1,     3,     1,     1,     5,     2,     1,     1,
       4,     4,     3,     4,     3,     3,     1,     2,     4,     2,
       0,     2,     1,     3,     2,     2,     2,     2,     3,     5,
       7,     5,     2,     7,     5,     5,     2,     0,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     3,     1,     1,     1,     1,
       3,     1,     3,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 65 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(PROGRAm, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    if(errors == 0) {parseProgram((yyval));}}
#line 1432 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1439 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1445 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1452 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1459 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 83 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1466 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "syntax.y" /* yacc.c:1646  */
    { (yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR((yyval));}
#line 1474 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 90 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1482 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1490 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "syntax.y" /* yacc.c:1646  */
    {errors++;}
#line 1496 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1503 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1510 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1517 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1524 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]);
    tmpcld[4] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1532 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1539 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1546 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    errors++;}
#line 1554 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1562 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1569 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1576 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 148 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 1585 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 1593 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1600 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1607 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 167 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(PARAMDEc, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1614 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(COMPSt, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1622 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMTLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1629 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1635 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1642 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1649 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1657 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1665 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1673 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1681 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1689 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1697 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]); tmpcld[4] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1705 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 7;
    tmpcld[0] = (yyvsp[-6]); tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1713 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 222 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]); tmpcld[4] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1721 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 226 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1729 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 230 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 6;
    tmpcld[0] = (yyvsp[-6]); tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-2]);
    tmpcld[4] = (yyvsp[-1]); tmpcld[5] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-4]));}
#line 1738 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 235 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-2]));}
#line 1747 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-2]));}
#line 1756 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 248 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1763 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 250 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1769 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 254 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1777 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 258 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1786 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 263 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR((yyval));}
#line 1795 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 270 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1802 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 273 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1810 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 279 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1817 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 282 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1825 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 288 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1832 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 291 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1839 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 294 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1846 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 297 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1853 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 300 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1860 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 303 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1867 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 306 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1874 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 309 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1881 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 312 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1888 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 315 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1895 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 318 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1902 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 321 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1909 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 324 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1916 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 327 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1923 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1930 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 333 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1937 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 336 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1944 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 339 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1952 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 343 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1959 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 346 "syntax.y" /* yacc.c:1646  */
    {(yyval) = newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1967 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 350 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1974 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 353 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1981 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 356 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1988 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 359 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1995 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 362 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2002 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 365 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    errors++;}
#line 2010 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 369 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1; tmpcld[0] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum); errors++;}
#line 2017 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 372 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 2025 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 376 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-3]);
    tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 2033 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 380 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum); 
    MISSING_RP_ERROR((yyvsp[-1])); }
#line 2041 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 386 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(ARGs, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2048 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 389 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(ARGs, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2055 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2059 "syntax.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 392 "syntax.y" /* yacc.c:1906  */

void yyerror(const char *s) {}
int getLine(){
    return yylineno;
}
int main(){
    yyparse();
    return 0;
}
