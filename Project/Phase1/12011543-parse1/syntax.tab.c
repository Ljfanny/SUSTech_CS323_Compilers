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
    #include <stdio.h>
    #include <stdlib.h>
    // #define YYSTYPE struct node*
    struct node* tmpcld[10];
    int tmpnum;
    
    enum myYYTYPE{
        PROGRAm = 46, 
        EXTDEFLISt,
        EXTDEf, SPECIFIEr, EXTDECLISt, STRUCTSPECIFIEr,
        VARDEc, FUNDEc, VARLISt, PARAMDEc,
        COMPSt, STMTLISt, STMt, DEFLISt,
        DEf, DECLISt, DEc, ARGs, EXp
    };

    #define MISSING_SEMI_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing semicolon ';'\n", er->line); \
    }

    #define MISSING_RP_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing closing parenthesis ')'\n", er->line); \
    }

    // #define MISSING_RB_ERROR(er) { \
    //     errors++; \
    //     printf("Error type B at Line %d: Missing closing parenthesis ']'\n", er->line); \
    // }

    // #define MISSING_RC_ERROR(er) { \
    //     errors++; \
    //     printf("Error type B at Line %d: Missing closing parenthesis '}'\n", er->line); \
    // }

    #define MISSING_SPECIFIER_ERROR(er) { \
        errors++; \
        printf("Error type B at Line %d: Missing specifier\n", er->line); \
    }

    int errors = 0;

    void yyerror(const char*);
    int getLine();
    int yylex();

#line 116 "syntax.tab.c" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 215 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   931

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    89,    92,    95,    98,   101,   104,   108,
     112,   116,   120,   123,   129,   132,   135,   141,   145,   155,
     158,   162,   173,   176,   179,   184,   190,   193,   198,   204,
     215,   218,   221,   224,   227,   231,   235,   239,   243,   247,
     251,   256,   261,   269,   272,   275,   279,   284,   291,   294,
     300,   303,   308,   312,   316,   320,   324,   331,   336,   339,
     342,   345,   348,   352,   355,   358,   361,   364,   367,   370,
     373,   377,   382,   387,   392,   397,   402,   407,   412,   418,
     421,   424,   427,   430,   433,   436,   439,   444,   447,   452,
     455,   460,   464,   467,   471,   474,   477,   480,   483,   491,
     495,   498,   502,   506,   512,   515
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "CONST", "NOT", "SEMI",
  "COMMA", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ",
  "QUESTION_MARK", "COLON", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "DOUBLE_PLUS", "DOUBLE_MINUS", "OR", "AND", "LP", "RP", "LB", "RB",
  "DOT", "LC", "RC", "ERROR", "$accept", "Program", "ExtDefList", "ExtDef",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     364,   101,  -158,     5,     7,    29,  -158,   364,    22,  -158,
     -28,  -158,   -13,    21,  -158,  -158,  -158,  -158,   -28,  -158,
    -158,    83,    20,   -13,   329,   287,  -158,   167,  -158,  -158,
      16,    62,  -158,  -158,  -158,    16,    30,    51,    16,    16,
     342,   287,    39,  -158,  -158,    25,    54,  -158,  -158,   116,
     727,    88,    90,   103,  -158,  -158,  -158,    80,    81,    85,
     354,   354,   354,   354,   354,   354,  -158,  -158,    82,   342,
      55,  -158,  -158,  -158,  -158,   354,   354,   354,   354,   354,
     354,  -158,    16,  -158,  -158,   303,   354,   354,   125,   728,
     278,   696,   696,   164,  -158,  -158,  -158,  -158,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,  -158,  -158,   354,   354,   354,
     121,   354,   696,   696,   696,   696,   696,   696,  -158,  -158,
    -158,   386,    59,   203,   242,  -158,  -158,  -158,  -158,   696,
     696,   696,   696,   696,   696,   795,   812,   829,   846,   863,
     880,   278,   278,   884,   884,   884,   753,   778,   417,  -158,
     696,   354,  -158,  -158,   342,   342,   342,   342,   354,   354,
     354,   354,   354,   354,   354,   354,  -158,  -158,   120,   131,
    -158,  -158,   448,   479,   510,   541,   572,   603,   634,   665,
     342,   342,   354,   354,   354,   354,   354,   354,   354,   354,
    -158,  -158,   696,   696,   696,   696,   696,   696,   696,   696
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,     0,     0,     0,     2,     0,     0,    16,
       0,    11,     0,    18,    15,     1,     3,     9,    19,     6,
      20,     0,    12,     0,     0,     0,     8,     0,    10,     5,
       0,     0,     7,    25,    23,     0,     0,    27,     0,     0,
      31,     0,     0,    19,    13,     0,    28,    24,    22,     0,
      50,     0,    48,     0,    96,    97,    98,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    33,     0,    31,
       0,    43,    17,    21,    26,     0,     0,     0,     0,     0,
       0,    47,     0,    46,    45,     0,     0,     0,     0,    86,
      85,    89,    87,     0,    29,    30,    39,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    88,     0,     0,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    49,   103,
      92,   105,     0,     0,     0,    35,    34,   101,    84,    57,
      58,    59,    60,    61,    62,    65,    66,    67,    68,    69,
      70,    79,    80,    81,    82,    83,    64,    63,     0,    94,
      99,     0,   102,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,   104,    41,    36,
      42,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    37,    73,    74,    75,    76,    77,    78,    72,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   124,  -158,   136,     6,  -158,    87,   146,   106,
    -158,    12,   102,  -157,    78,  -158,   -18,  -158,   -60,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    21,    39,     9,    50,    12,    36,
      37,    67,    68,    69,    40,    41,    51,    52,    70,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    89,    90,    91,    92,    93,     8,   178,   179,   180,
     181,    13,    24,     8,    14,   122,   123,   124,   125,   126,
     127,    53,    43,    17,    26,   131,   133,   134,    18,    15,
      35,    47,    25,   200,   201,    32,    30,    19,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    35,    96,   156,   157,   158,
     162,   160,    31,    20,   128,    45,    27,    49,    73,    20,
      97,    48,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    28,    72,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    22,    31,   119,    29,   120,
     163,   131,   121,    81,    83,    42,    82,    10,   182,   183,
     184,   185,   186,   187,   188,   189,    11,    22,    84,    71,
      85,    86,    46,     2,     3,    87,   135,   159,    94,     4,
     190,    16,   202,   203,   204,   205,   206,   207,   208,   209,
     136,   191,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    23,    74,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   137,    44,   119,    38,   120,
     177,    95,   121,     0,     2,     3,     0,     0,     0,     0,
       4,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   164,   138,   119,     0,   120,     0,
       0,   121,     0,   -44,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   166,   165,   119,     0,   120,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   167,   119,     0,   120,     0,    38,   121,
     -44,   -44,   -44,   -44,     2,     3,   -44,     0,   -44,   -44,
       4,   -44,     0,     0,   129,     0,    54,    55,    56,    57,
       0,   112,   113,   114,   115,   116,     0,    61,     0,   -44,
     119,     0,   120,   -44,   -44,   121,     0,   -44,     0,     0,
      33,     0,   -44,   -44,   -44,    62,     2,     3,     0,    63,
      64,     0,     4,    65,   130,    54,    55,    56,    57,     0,
      66,    58,     0,    59,    60,     0,    61,    54,    55,    56,
      57,     0,     0,     0,    -4,     1,     0,     0,    61,     0,
      34,     2,     3,     0,    62,     0,     0,     4,    63,    64,
       0,     0,    65,     0,     0,     0,    62,    25,     0,    66,
      63,    64,     0,     0,    65,     0,     0,     0,     0,     0,
       0,    66,   161,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,   119,     0,
     120,     0,     0,   121,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,     0,   119,
     176,   120,     0,     0,   121,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   192,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,     0,   120,     0,     0,   121,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   193,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,   119,     0,   120,     0,     0,   121,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     194,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,     0,   120,     0,     0,   121,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   195,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,   119,     0,   120,     0,     0,   121,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   196,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   119,     0,   120,     0,     0,   121,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   197,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,   119,     0,   120,     0,     0,
     121,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   198,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,   119,     0,   120,     0,
       0,   121,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   199,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,   119,     0,   120,
       0,     0,   121,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,   119,     0,
     120,     0,     0,   121,    75,    76,    77,    78,    79,    80,
       0,   104,   105,   106,   107,   108,   109,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,    31,
     119,     0,   120,     0,     0,   121,   104,   105,   106,   107,
     108,   109,   174,     0,   110,   111,   112,   113,   114,   115,
     116,     0,   118,     0,     0,   119,     0,   120,     0,     0,
     121,   104,   105,   106,   107,   108,   109,   175,     0,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     119,     0,   120,     0,   168,   121,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,   119,     0,   120,
       0,   169,   121,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   119,     0,   120,     0,   170,   121,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   119,     0,   120,     0,   171,   121,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   119,     0,
     120,     0,   172,   121,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   119,     0,   120,     0,   173,
     121,   110,   111,   112,   113,   114,   115,   116,     0,     0,
     115,   116,   119,     0,   120,     0,   119,   121,   120,     0,
       0,   121
};

static const yytype_int16 yycheck[] =
{
      60,    61,    62,    63,    64,    65,     0,   164,   165,   166,
     167,     6,    40,     7,     7,    75,    76,    77,    78,    79,
      80,    39,     6,     1,    12,    85,    86,    87,     6,     0,
      24,     1,    45,   190,   191,    23,    16,    15,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    49,     1,   117,   118,   119,
       1,   121,    42,    47,    82,     3,    45,    16,    43,    47,
      15,    41,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    46,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     8,    42,    42,    15,    44,
      41,   161,    47,    15,     1,    27,    16,     6,   168,   169,
     170,   171,   172,   173,   174,   175,    15,    30,    15,    41,
      40,    40,    35,     7,     8,    40,     1,     6,    46,    13,
      10,     7,   192,   193,   194,   195,   196,   197,   198,   199,
      15,    10,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     8,    49,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     1,    30,    42,     1,    44,
     161,    69,    47,    -1,     7,     8,    -1,    -1,    -1,    -1,
      13,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     1,    41,    42,    -1,    44,    -1,
      -1,    47,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     1,    41,    42,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    -1,    44,    -1,     1,    47,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    33,    34,    35,    36,    37,    -1,    14,    -1,    32,
      42,    -1,    44,    36,    37,    47,    -1,    40,    -1,    -1,
       1,    -1,    45,    46,    47,    32,     7,     8,    -1,    36,
      37,    -1,    13,    40,    41,     3,     4,     5,     6,    -1,
      47,     9,    -1,    11,    12,    -1,    14,     3,     4,     5,
       6,    -1,    -1,    -1,     0,     1,    -1,    -1,    14,    -1,
      41,     7,     8,    -1,    32,    -1,    -1,    13,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    32,    45,    -1,    47,
      36,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      44,    -1,    -1,    47,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    44,    -1,    -1,    47,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    44,    -1,    -1,    47,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    44,    -1,    -1,    47,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    44,    -1,    -1,    47,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    44,    -1,    -1,
      47,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    44,    -1,
      -1,    47,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    44,
      -1,    -1,    47,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      44,    -1,    -1,    47,    17,    18,    19,    20,    21,    22,
      -1,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    42,
      42,    -1,    44,    -1,    -1,    47,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    42,    -1,    44,    -1,    -1,
      47,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    29,    47,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,
      -1,    29,    47,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    29,    47,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,    29,    47,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    29,    47,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    29,
      47,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      36,    37,    42,    -1,    44,    -1,    42,    47,    44,    -1,
      -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    13,    49,    50,    51,    53,    54,
       6,    15,    56,     6,     7,     0,    50,     1,     6,    15,
      47,    52,    55,    56,    40,    45,    59,    45,     1,    15,
      16,    42,    59,     1,    41,    53,    57,    58,     1,    53,
      62,    63,    62,     6,    52,     3,    55,     1,    41,    16,
      55,    64,    65,    64,     3,     4,     5,     6,     9,    11,
      12,    14,    32,    36,    37,    40,    47,    59,    60,    61,
      66,    62,    46,    43,    57,    17,    18,    19,    20,    21,
      22,    15,    16,     1,    15,    40,    40,    40,    66,    66,
      66,    66,    66,    66,    46,    60,     1,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      44,    47,    66,    66,    66,    66,    66,    66,    64,     1,
      41,    66,    67,    66,    66,     1,    15,     1,    41,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,     6,
      66,    16,     1,    41,     1,    41,     1,    41,    29,    29,
      29,    29,    29,    29,    29,    29,    43,    67,    61,    61,
      61,    61,    66,    66,    66,    66,    66,    66,    66,    66,
      10,    10,    30,    30,    30,    30,    30,    30,    30,    30,
      61,    61,    66,    66,    66,    66,    66,    66,    66,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       3,     2,     1,     3,     1,     2,     1,     5,     2,     1,
       1,     4,     4,     3,     4,     3,     3,     1,     2,     4,
       2,     0,     2,     1,     3,     3,     5,     7,     5,     2,
       7,     5,     5,     2,     0,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     7,     7,     7,     7,     7,     7,     7,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     1,     3,
       1,     3,     4,     3,     3,     1
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
#line 84 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(PROGRAm, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    if(errors == 0) {treePrint((yyval));}}
#line 1577 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1584 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1590 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1597 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1604 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1611 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "syntax.y" /* yacc.c:1646  */
    { (yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR((yyval));}
#line 1619 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1627 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1635 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "syntax.y" /* yacc.c:1646  */
    {errors++;}
#line 1641 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1648 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXTDECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1655 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1662 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1669 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(SPECIFIEr, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1676 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]);
    tmpcld[4] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1684 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 146 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STRUCTSPECIFIEr, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1691 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1698 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    errors++;}
#line 1706 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARDEc, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1714 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 174 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1721 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 177 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1728 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 1737 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(FUNDEc, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 1745 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1752 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(VARLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1759 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(PARAMDEc, getLine()); tmpnum = 2;
        tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1766 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(COMPSt, getLine()); tmpnum = 4;
        tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); tmpcld[3] = (yyvsp[0]);
        setNode((yyval), tmpcld, tmpnum);}
#line 1774 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMTLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1781 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1787 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 222 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1794 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 225 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1801 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 228 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1809 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 232 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1817 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]); tmpcld[4] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1825 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 7;
    tmpcld[0] = (yyvsp[-6]); tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1833 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 244 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 5;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[-1]); tmpcld[4] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1841 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 248 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1849 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 6;
    tmpcld[0] = (yyvsp[-6]); tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-2]);
    tmpcld[4] = (yyvsp[-1]); tmpcld[5] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-4]));}
#line 1858 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 257 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-2]));}
#line 1867 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 262 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(STMt, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-4]); tmpcld[1] = (yyvsp[-3]); tmpcld[2] = (yyvsp[-2]); tmpcld[3] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-2]));}
#line 1876 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 270 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEFLISt, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1883 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 272 "syntax.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1889 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 276 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1897 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_SEMI_ERROR((yyvsp[-1]));}
#line 1906 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 285 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEf, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);
    MISSING_SPECIFIER_ERROR((yyval));}
#line 1915 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 292 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DECLISt, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1922 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 295 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DECLISt, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1930 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 301 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1937 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1945 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 309 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1953 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 313 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1961 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 317 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1969 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 321 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1977 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 325 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(DEc, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 1985 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 332 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1992 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 337 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 1999 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 340 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2006 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 343 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2013 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 346 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2020 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 349 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2027 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 353 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2034 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 356 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2041 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 359 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2048 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 362 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2055 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 365 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2062 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 368 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2069 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 371 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2076 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 374 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2083 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 378 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2092 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 383 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2101 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 388 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2110 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 393 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2119 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 398 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2128 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 403 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2137 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 408 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2146 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 413 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 7; tmpcld[0] = (yyvsp[-6]);
    tmpcld[1] = (yyvsp[-5]); tmpcld[2] = (yyvsp[-4]); tmpcld[3] = (yyvsp[-3]); tmpcld[4] = (yyvsp[-2]);
    tmpcld[5] = (yyvsp[-1]); tmpcld[6] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum);}
#line 2155 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 419 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2162 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 422 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2169 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 425 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2176 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 428 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2183 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 431 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2190 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 434 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2197 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 437 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2204 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 440 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2211 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 445 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2218 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 448 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2225 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 453 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2232 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 456 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2;
    tmpcld[0] = (yyvsp[-1]); tmpcld[1] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2239 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 461 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2247 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 465 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2254 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 468 "syntax.y" /* yacc.c:1646  */
    {(yyval) = newNodeNTER(EXp, getLine()); tmpnum = 4;
    tmpcld[0] = (yyvsp[-3]); tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]);
    tmpcld[3] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2262 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 472 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2269 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 475 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2276 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 478 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2283 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 481 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2290 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 484 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2297 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 492 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);
    errors++;}
#line 2305 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 496 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 1; tmpcld[0] = (yyvsp[0]);
    setNode((yyval), tmpcld, tmpnum); errors++;}
#line 2312 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 499 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 2320 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 503 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 3; tmpcld[0] = (yyvsp[-3]);
    tmpcld[1] = (yyvsp[-2]); tmpcld[2] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum);
    MISSING_RP_ERROR((yyvsp[-1]));}
#line 2328 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 507 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(EXp, getLine()); tmpnum = 2; tmpcld[0] = (yyvsp[-2]);
    tmpcld[1] = (yyvsp[-1]); setNode((yyval), tmpcld, tmpnum); 
    MISSING_RP_ERROR((yyvsp[-1])); }
#line 2336 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 513 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(ARGs, getLine()); tmpnum = 3;
    tmpcld[0] = (yyvsp[-2]); tmpcld[1] = (yyvsp[-1]); tmpcld[2] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2343 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 516 "syntax.y" /* yacc.c:1646  */
    {(yyval)= newNodeNTER(ARGs, getLine()); tmpnum = 1;
    tmpcld[0] = (yyvsp[0]); setNode((yyval), tmpcld, tmpnum);}
#line 2350 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2354 "syntax.tab.c" /* yacc.c:1646  */
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
#line 519 "syntax.y" /* yacc.c:1906  */

void yyerror(const char *s) {
    /* errorType = 1; */
    /* printf ("ERROR: Line %d, %s \"%s\"\n", yylineno, s, yytext); */
}
int getLine(){
    return yylineno;
}
int main(){
    yyparse();
    return 0;
}
