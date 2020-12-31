/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/main.y"

    #include "common.h"
    #define YYSTYPE TreeNode * 
    TreeNode* root;
    extern int lineno;
    layerNode* currentNode;
    layerNode* layer_root;
    int yylex();
    int yyerror( char const * );
    list<string*> *str_list;
    list<TreeNode*> func_def_list;//存储了所有函数定义的列表

#line 83 "src/main.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    TRUE = 263,
    FALSE = 264,
    ASSIGN = 265,
    ADD_ASSIGN = 266,
    SUB_ASSIGN = 267,
    MUL_ASSIGN = 268,
    DIV_ASSIGN = 269,
    EQ = 270,
    NEQ = 271,
    GQT = 272,
    LQT = 273,
    GT = 274,
    LT = 275,
    ADD = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    MODE = 280,
    INC = 281,
    DEC = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    PRINTF = 286,
    SCANF = 287,
    REFERENCE = 288,
    CONST = 289,
    SEMICOLON = 290,
    COMMA = 291,
    LP = 292,
    RP = 293,
    LC = 294,
    RC = 295,
    WHILE = 296,
    ELSE = 297,
    IF = 298,
    RETURN = 299,
    FOR = 300,
    CONTINUE = 301,
    BREAK = 302,
    IDENTIFIER = 303,
    INTEGER = 304,
    CHAR = 305,
    BOOL = 306,
    STRING = 307,
    UMINUS = 308,
    UADD = 309,
    LOWER_THEN_ELSE = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    50,    51,    55,    59,    60,    63,    64,
      67,    70,    71,    72,    73,    76,    82,    99,   117,   137,
     166,   174,   183,   192,   205,   214,   227,   309,   315,   321,
     328,   337,   343,   378,   384,   419,   420,   427,   440,   451,
     465,   466,   473,   474,   475,   479,   485,   488,   502,   505,
     519,   522,   533,   547,   550,   561,   572,   583,   597,   608,
     619,   630,   641,   655,   658,   669,   683,   686,   697,   708,
     722,   727,   730,   740,   750,   763,   766,   776,   789,   792,
     795,   801,   805,   809,   813,   820,   821,   822,   823,   824
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_VOID", "TRUE", "FALSE", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "EQ", "NEQ", "GQT", "LQT", "GT", "LT", "ADD",
  "SUB", "MUL", "DIV", "MODE", "INC", "DEC", "AND", "OR", "NOT", "PRINTF",
  "SCANF", "REFERENCE", "CONST", "SEMICOLON", "COMMA", "LP", "RP", "LC",
  "RC", "WHILE", "ELSE", "IF", "RETURN", "FOR", "CONTINUE", "BREAK",
  "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING", "UMINUS", "UADD",
  "LOWER_THEN_ELSE", "$accept", "program", "statements", "statement",
  "function_Call", "function_Definition", "compound_Stmt", "if_else",
  "iteration_Stmt", "jump_Stmt", "printf", "scanf", "io_list",
  "declaration", "id_list", "expr", "condition_expr", "logical_or_expr",
  "logical_and_expr", "equality_expr", "relation_expr", "assignment_expr",
  "additive_expr", "mult_expr", "cast_expr", "unary_expr", "postfix_expr",
  "primary_expr", "paperConst", "T", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     232,   -27,   -27,   -27,   -27,   -27,   333,   333,   -22,   -19,
     333,   -27,   288,   132,    -2,    53,    56,    55,    32,    61,
      60,   -27,   -27,   -27,   -27,    22,   232,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,    67,    68,   -26,    74,    69,     5,
     -27,   -27,   -20,   -27,   -27,   -27,   -27,   338,   343,   -27,
      34,    77,   -27,    87,    70,    41,    33,   -27,    63,    20,
     -27,    69,    71,   -27,   182,   288,   288,   -27,    82,   288,
     -27,   -27,   -24,   -27,   -27,   -27,   -27,   -27,    72,   -27,
     333,   333,   333,   333,   333,   -27,   -27,     9,    85,    80,
      86,    94,   -27,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   114,   -27,    95,    96,
     -27,   105,   -27,   -27,   -13,   -27,    63,    63,    63,    63,
      63,   333,    35,   288,   -27,   288,   -27,    70,    41,    33,
      33,    63,    63,    63,    63,    20,    20,   -27,   -27,   -27,
     102,   102,   288,    97,   -27,    63,   102,    -9,    38,   -27,
      39,   -27,   101,   109,   -27,   -27,   102,   288,   -27,   -27,
     102,   282,   -27,   -27,   -27,   102,   110,   -27,   102,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    86,    85,    88,    87,    89,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    81,    82,    84,    83,     0,     2,     3,    15,    14,
      11,     8,     9,    10,     0,     0,     0,     0,     0,    71,
      75,    79,     0,    78,    72,    70,    73,     0,     0,    74,
      44,     0,    42,    45,    46,    48,    50,    43,    53,    63,
      66,    70,     0,    21,     0,     0,     0,    30,     0,     0,
      27,    28,     0,     1,     4,    12,    13,     6,     0,     7,
       0,     0,     0,     0,     0,    76,    77,    39,    83,     0,
      83,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    20,     0,     0,
      29,     0,    17,    40,     0,    38,    58,    59,    60,    61,
      62,     0,     0,     0,    31,     0,    33,    47,    49,    51,
      52,    57,    55,    56,    54,    64,    65,    67,    68,    69,
       0,     0,     0,     0,    16,    37,     0,     0,     0,    35,
       0,    24,    22,     0,    41,    19,     0,     0,    32,    34,
       0,     0,    18,    36,    23,     0,     0,    26,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   134,   -15,   -27,   -27,   256,   -27,   -27,   -27,
     -27,   -27,    24,     4,   -27,   -11,   -27,   -27,    59,    62,
      -8,     7,    30,    -7,    -4,     0,   -27,   -27,   -27,     8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   148,    50,   114,   149,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    45,    39,    40,    41,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    51,    44,    46,    36,    68,    49,    37,    42,    77,
      78,    74,    61,    38,   112,    47,    61,    36,    48,   121,
      37,    42,    73,   143,   113,   144,    38,    78,    87,   156,
      36,    85,    86,    37,    42,    65,    89,    91,     1,     2,
       3,     4,     5,   103,   104,   105,   122,    61,    61,    74,
      97,    98,    99,   100,   108,   109,    95,    96,   111,     1,
       2,     3,     4,     5,    38,    61,    61,    70,    36,    61,
      78,    37,    42,   146,   157,   157,   158,   159,     6,    80,
      81,    82,    83,    84,   101,   102,     7,   129,   130,    10,
      66,    67,    69,    12,   135,   136,    71,    72,    94,   137,
     138,   139,    75,    76,    43,    21,    22,    23,    24,    79,
     116,   117,   118,   119,   120,    92,    93,   110,   124,   106,
     115,   123,   125,    61,   121,    61,   147,   131,   132,   133,
     134,   153,   126,   140,   141,     1,     2,     3,     4,     5,
     142,    13,    61,   160,   161,   154,   163,    64,   168,   150,
     166,   145,   127,     0,     6,     0,   128,    61,     0,     0,
       0,    61,     7,     8,     9,    10,     0,    11,     0,    12,
       0,    13,    63,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    11,     0,    12,
       0,    13,   107,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    11,     0,    12,
       0,    13,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     1,     2,     3,     4,     5,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       6,     0,     7,     0,     0,    10,     0,     0,     7,    12,
     165,    10,     0,     0,     0,    12,     0,     0,     0,     0,
      43,    21,    22,    23,    24,     0,    43,    21,    22,    23,
      24,     1,     2,     3,     4,     5,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       6,     0,     0,     7,     0,     6,    10,     0,     7,     0,
      12,    10,     0,     7,     0,    12,    10,     0,     0,     0,
      12,    43,    21,    22,    23,    24,    43,    21,    22,    23,
      88,    43,    21,    22,    23,    90,   151,   152,     0,     0,
       0,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   164,     0,     0,     0,
       0,   167,     0,     0,   169
};

static const yytype_int16 yycheck[] =
{
       0,    12,     6,     7,     0,    16,    10,     0,     0,    35,
      36,    26,    12,    13,    38,    37,    16,    13,    37,    10,
      13,    13,     0,    36,    48,    38,    26,    36,    48,    38,
      26,    26,    27,    26,    26,    37,    47,    48,     3,     4,
       5,     6,     7,    23,    24,    25,    37,    47,    48,    64,
      17,    18,    19,    20,    65,    66,    15,    16,    69,     3,
       4,     5,     6,     7,    64,    65,    66,    35,    64,    69,
      36,    64,    64,    38,    36,    36,    38,    38,    22,    10,
      11,    12,    13,    14,    21,    22,    30,    95,    96,    33,
      37,    35,    37,    37,   101,   102,    35,    37,    28,   103,
     104,   105,    35,    35,    48,    49,    50,    51,    52,    35,
      80,    81,    82,    83,    84,    38,    29,    35,    38,    48,
      48,    36,    36,   123,    10,   125,   122,    97,    98,    99,
     100,   142,    38,    38,    38,     3,     4,     5,     6,     7,
      35,    39,   142,    42,    35,    48,   157,    13,    38,   125,
     161,   121,    93,    -1,    22,    -1,    94,   157,    -1,    -1,
      -1,   161,    30,    31,    32,    33,    -1,    35,    -1,    37,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    -1,    37,
      -1,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    -1,    37,
      -1,    39,    -1,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     3,     4,     5,     6,     7,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    30,    -1,    -1,    33,    -1,    -1,    30,    37,
      38,    33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,    48,    49,    50,    51,
      52,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    30,    -1,    22,    33,    -1,    30,    -1,
      37,    33,    -1,    30,    -1,    37,    33,    -1,    -1,    -1,
      37,    48,    49,    50,    51,    52,    48,    49,    50,    51,
      52,    48,    49,    50,    51,    52,   140,   141,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,   165,    -1,    -1,   168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    22,    30,    31,    32,
      33,    35,    37,    39,    41,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    69,    77,    81,    82,
      83,    84,    85,    48,    80,    81,    80,    37,    37,    80,
      69,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    85,    40,    58,    37,    37,    35,    71,    37,
      35,    35,    37,     0,    59,    35,    35,    35,    36,    35,
      10,    11,    12,    13,    14,    26,    27,    48,    52,    71,
      52,    71,    38,    29,    28,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    48,    40,    71,    71,
      35,    71,    38,    48,    70,    48,    78,    78,    78,    78,
      78,    10,    37,    36,    38,    36,    38,    74,    75,    76,
      76,    78,    78,    78,    78,    79,    79,    80,    80,    80,
      38,    38,    35,    36,    38,    78,    38,    69,    68,    71,
      68,    62,    62,    71,    48,    62,    38,    36,    38,    38,
      42,    35,    62,    71,    62,    38,    71,    62,    38,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      70,    70,    71,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    78,    79,    79,    79,    79,
      80,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     3,     6,     5,
       3,     2,     5,     7,     5,     9,     8,     2,     2,     3,
       2,     4,     6,     4,     6,     1,     3,     4,     3,     2,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     2,     2,     2,     1,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 43 "src/main.y"
             {
    root = new TreeNode(0, NODE_PROG); 
    root->addChild(yyvsp[0]);
    root->layer_node=currentNode;}
#line 1534 "src/main.tab.cpp"
    break;

  case 3:
#line 50 "src/main.y"
             {yyval=yyvsp[0];}
#line 1540 "src/main.tab.cpp"
    break;

  case 4:
#line 51 "src/main.y"
                        {yyval=yyvsp[-1]; yyval->addSibling(yyvsp[0]);}
#line 1546 "src/main.tab.cpp"
    break;

  case 5:
#line 55 "src/main.y"
             {
    yyval = new TreeNode(yyvsp[0]->lineno, NODE_STMT); 
    yyval->stype = STMT_SKIP;
    yyval->layer_node=currentNode;}
#line 1555 "src/main.tab.cpp"
    break;

  case 6:
#line 59 "src/main.y"
                        {yyval = yyvsp[-1];}
#line 1561 "src/main.tab.cpp"
    break;

  case 7:
#line 60 "src/main.y"
                           {
    yyval = yyvsp[-1];
}
#line 1569 "src/main.tab.cpp"
    break;

  case 8:
#line 63 "src/main.y"
          {yyval = yyvsp[0];}
#line 1575 "src/main.tab.cpp"
    break;

  case 9:
#line 64 "src/main.y"
                {
    yyval=yyvsp[0];
}
#line 1583 "src/main.tab.cpp"
    break;

  case 10:
#line 67 "src/main.y"
            {
    yyval=yyvsp[0];
}
#line 1591 "src/main.tab.cpp"
    break;

  case 11:
#line 70 "src/main.y"
                {yyval=yyvsp[0];}
#line 1597 "src/main.tab.cpp"
    break;

  case 12:
#line 71 "src/main.y"
                   {yyval=yyvsp[-1];}
#line 1603 "src/main.tab.cpp"
    break;

  case 13:
#line 72 "src/main.y"
                  {yyval=yyvsp[-1];}
#line 1609 "src/main.tab.cpp"
    break;

  case 14:
#line 73 "src/main.y"
                     {
    yyval=yyvsp[0];
}
#line 1617 "src/main.tab.cpp"
    break;

  case 15:
#line 76 "src/main.y"
               {
    yyval=yyvsp[0];
}
#line 1625 "src/main.tab.cpp"
    break;

  case 16:
#line 82 "src/main.y"
                          {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_FUNC_CALL); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->func_name=yyvsp[-3];
    node->func_info->arg_list=yyvsp[-1];
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-1]);
    setSymbolType(currentNode->section,yyvsp[-3],SYMBOL_FUNC);
    yyvsp[-3]->type=TYPE_FUNC;
    node->func_info->func_def_loc=findFuncDef(yyvsp[-3]->var_name,func_def_list);//将函数调用节点的指向定义的指针指向该函数的定义节点
    if(node->func_info->func_def_loc==nullptr)//定义前引用
    {
        cout<<"function called before define at line"<<yyvsp[-3]->lineno<<endl;
    }
    yyval=node;
}
#line 1647 "src/main.tab.cpp"
    break;

  case 17:
#line 99 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_FUNC_CALL); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->func_name=yyvsp[-2];
    node->addChild(yyvsp[0]);
    setSymbolType(currentNode->section,yyvsp[-2],SYMBOL_FUNC);
    yyvsp[-2]->type=TYPE_FUNC;
    node->func_info->func_def_loc=findFuncDef(yyvsp[-2]->var_name,func_def_list);//将函数调用节点的指向定义的指针指向该函数的定义节点
    if(node->func_info->func_def_loc==nullptr)//定义前引用
    {
        cout<<"function called before define at line"<<yyvsp[-2]->lineno<<endl;
    }
    yyval=node;
}
#line 1667 "src/main.tab.cpp"
    break;

  case 18:
#line 117 "src/main.y"
                                              {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno, NODE_FUNC_DEF); 
    node->layer_node=currentNode;
    node->func_info=new funcInfo;
    node->func_info->return_value=yyvsp[-5];
    node->func_info->func_name=yyvsp[-4];
    node->func_info->decl_list=yyvsp[-2];
    node->func_info->func_body=yyvsp[0];
    node->func_info->func_def_loc=node;
    node->addChild(yyvsp[-5]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    setProperty(currentNode->section,yyvsp[-4],PROPERTY_DEF);
    setSymbolType(currentNode->section,yyvsp[-4],SYMBOL_FUNC);
    yyvsp[-4]->type=TYPE_FUNC;
    yyvsp[0]->change_field.is_func_field=1;//用来将对应的layernode标识为函数体
    func_def_list.push_back(node);//将这个函数定义节点放入func_def_list
    yyval=node;
}
#line 1692 "src/main.tab.cpp"
    break;

  case 19:
#line 137 "src/main.y"
                                  {
    TreeNode* node;
    if(yyvsp[-3]->var_name=="main"){
        node = new TreeNode(yyvsp[-3]->lineno, NODE_MAIN);
        node->layer_node=currentNode;
        node->addChild(yyvsp[-4]);
        node->addChild(yyvsp[0]);
    }
    else {
        node = new TreeNode(yyvsp[-3]->lineno, NODE_FUNC_DEF);
        node->layer_node=currentNode;
        node->addChild(yyvsp[-4]);
        node->addChild(yyvsp[-3]);
        node->addChild(yyvsp[0]);
        node->func_info=new funcInfo;
        node->func_info->return_value=yyvsp[-4];
        node->func_info->func_name=yyvsp[-3];
        node->func_info->func_body=yyvsp[0];
        setProperty(currentNode->section,yyvsp[-3],PROPERTY_DEF);
        setSymbolType(currentNode->section,yyvsp[-3],SYMBOL_FUNC);
        yyvsp[-3]->type=TYPE_FUNC;
        yyvsp[0]->change_field.is_func_field=1;//用来将对应的layernode标识为函数体
        func_def_list.push_back(node);//将这个函数定义节点放入func_def_list
    }
    yyval=node; 
}
#line 1723 "src/main.tab.cpp"
    break;

  case 20:
#line 166 "src/main.y"
                  {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_BLOCK); 
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1736 "src/main.tab.cpp"
    break;

  case 21:
#line 174 "src/main.y"
       {
    TreeNode* node = new TreeNode(lineno, NODE_BLOCK);
    node->layer_node=currentNode; 
    node->stype = STMT_SKIP;
    yyval=node;
}
#line 1747 "src/main.tab.cpp"
    break;

  case 22:
#line 183 "src/main.y"
                                                    {
    TreeNode *node=new TreeNode(yyvsp[-2]->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->check_type();
    yyval=node;
}
#line 1761 "src/main.tab.cpp"
    break;

  case 23:
#line 192 "src/main.y"
                                                 {
    TreeNode *node=new TreeNode(yyvsp[-4]->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->check_type();
    yyval=node;
}
#line 1776 "src/main.tab.cpp"
    break;

  case 24:
#line 205 "src/main.y"
                                 {
    TreeNode *node=new TreeNode(yyvsp[-2]->lineno,NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->check_type();
    yyval=node;
}
#line 1790 "src/main.tab.cpp"
    break;

  case 25:
#line 214 "src/main.y"
                                                             {
    TreeNode *node=new TreeNode(yyvsp[-6]->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    node->check_type();
    yyval = node;
}
#line 1808 "src/main.tab.cpp"
    break;

  case 26:
#line 227 "src/main.y"
                                                        {
    TreeNode *node=new TreeNode(yyvsp[-5]->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild(yyvsp[-5]);
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->change_field.accessTime=currentNode->accessTime-1;
    node->change_field.needChange=1;
    node->check_type();
    yyval = node;
}
#line 1825 "src/main.tab.cpp"
    break;

  case 27:
#line 309 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_CONTINUE;
    node->layer_node=currentNode;
    yyval=node;
}
#line 1836 "src/main.tab.cpp"
    break;

  case 28:
#line 315 "src/main.y"
                 {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_BREAK;
    node->layer_node=currentNode;
    yyval=node;
}
#line 1847 "src/main.tab.cpp"
    break;

  case 29:
#line 321 "src/main.y"
                       {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->layer_node=currentNode;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1859 "src/main.tab.cpp"
    break;

  case 30:
#line 328 "src/main.y"
                  {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->layer_node=currentNode;
    yyval=node;
}
#line 1870 "src/main.tab.cpp"
    break;

  case 31:
#line 337 "src/main.y"
                    {
    TreeNode *node=new TreeNode(yyvsp[-1]->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1881 "src/main.tab.cpp"
    break;

  case 32:
#line 343 "src/main.y"
                                    {
    TreeNode *node=new TreeNode(yyvsp[-3]->lineno,NODE_STMT);
    node->stype=STMT_PRINTF;
    node->addChild(yyvsp[-3]);
    string str = yyvsp[-3]->str_val;
    char t[10];
    int i = 0;
    int num = 0;
    while(i<(int)str.length())
    {
        if(str[i]=='%')
        {
            if(str[i+1]=='d' || str[i+1]=='s')
            {
                t[num] = str[i+1];
                num++;
            }
        }
        i++;
    }
    i = 0;
    while(i<num)
    {
        TreeNode* node_c = new TreeNode(lineno, NODE_CONST);
        node_c->type = TYPE_CHAR;
        node_c->ch_val = t[i];
        node->addChild(node_c);
        i++;
    }
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1918 "src/main.tab.cpp"
    break;

  case 33:
#line 378 "src/main.y"
                   {
    TreeNode *node=new TreeNode(yyvsp[-1]->lineno,NODE_STMT);
    node->stype=STMT_SCANF;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1929 "src/main.tab.cpp"
    break;

  case 34:
#line 384 "src/main.y"
                                   {
    TreeNode *node=new TreeNode(yyvsp[-3]->lineno,NODE_STMT);
    node->stype=STMT_SCANF;
    node->addChild(yyvsp[-3]);
    string str = yyvsp[-3]->str_val;
    char t[10];
    int i = 0;
    int num = 0;
    while(i<(int)str.length())
    {
        if(str[i]=='%')
        {
            if(str[i+1]=='d' || str[i+1]=='s')
            {
                t[num] = str[i+1];
                num++;
            }
        }
        i++;
    }
    i = 0;
    while(i<num)
    {
        TreeNode* node_c = new TreeNode(lineno, NODE_CONST);
        node_c->type = TYPE_CHAR;
        node_c->ch_val = t[i];
        node->addChild(node_c);
        i++;
    }
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1966 "src/main.tab.cpp"
    break;

  case 35:
#line 419 "src/main.y"
       {yyval=yyvsp[0];}
#line 1972 "src/main.tab.cpp"
    break;

  case 36:
#line 420 "src/main.y"
                     {
    yyval = yyvsp[-2];
    yyval->addSibling(yyvsp[0]);
}
#line 1981 "src/main.tab.cpp"
    break;

  case 37:
#line 427 "src/main.y"
                                   {  // declare and init
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    setProperty(currentNode->section,yyvsp[-2],PROPERTY_DEF);
    yyvsp[-2]->type=yyvsp[-3]->type;
    node->type=yyvsp[-3]->type;
    node->check_type();
    yyval = node;   
}
#line 1999 "src/main.tab.cpp"
    break;

  case 38:
#line 440 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    setProperty(currentNode->section,yyvsp[0],PROPERTY_DEF);
    yyvsp[0]->type=yyvsp[-2]->type;
    node->type=yyvsp[-2]->type;
    yyval = node;   
}
#line 2015 "src/main.tab.cpp"
    break;

  case 39:
#line 451 "src/main.y"
              {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    setProperty(currentNode->section,yyvsp[0],PROPERTY_DEF);
    yyvsp[0]->type=yyvsp[-1]->type;
    node->type=yyvsp[-1]->type;
    yyval = node;   
}
#line 2031 "src/main.tab.cpp"
    break;

  case 40:
#line 465 "src/main.y"
             {yyval=yyvsp[0];setProperty(currentNode->section,yyvsp[0],PROPERTY_DEF);}
#line 2037 "src/main.tab.cpp"
    break;

  case 41:
#line 466 "src/main.y"
                          {
    yyval=yyvsp[-2];
    yyval->addSibling(yyvsp[0]);
    yyval->layer_node=currentNode;
}
#line 2047 "src/main.tab.cpp"
    break;

  case 42:
#line 473 "src/main.y"
                 {yyval=yyvsp[0];}
#line 2053 "src/main.tab.cpp"
    break;

  case 43:
#line 474 "src/main.y"
                  {yyval=yyvsp[0];}
#line 2059 "src/main.tab.cpp"
    break;

  case 44:
#line 475 "src/main.y"
              {yyval=yyvsp[0];}
#line 2065 "src/main.tab.cpp"
    break;

  case 45:
#line 479 "src/main.y"
                 {
    yyval=yyvsp[0];
}
#line 2073 "src/main.tab.cpp"
    break;

  case 46:
#line 485 "src/main.y"
                  {
    yyval=yyvsp[0];
}
#line 2081 "src/main.tab.cpp"
    break;

  case 47:
#line 488 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_OR;
    node->exprtype=EXPR_LOGICAL;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2097 "src/main.tab.cpp"
    break;

  case 48:
#line 502 "src/main.y"
               {
    yyval=yyvsp[0];
}
#line 2105 "src/main.tab.cpp"
    break;

  case 49:
#line 505 "src/main.y"
                                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR );
    node->exprtype=EXPR_LOGICAL;
    node->optype=OP_AND;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2121 "src/main.tab.cpp"
    break;

  case 50:
#line 519 "src/main.y"
               {
    yyval=yyvsp[0];
}
#line 2129 "src/main.tab.cpp"
    break;

  case 51:
#line 522 "src/main.y"
                                 {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_EQ;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2145 "src/main.tab.cpp"
    break;

  case 52:
#line 533 "src/main.y"
                                  {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR );
    node->optype=OP_NEQ;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2161 "src/main.tab.cpp"
    break;

  case 53:
#line 547 "src/main.y"
               {
    yyval=yyvsp[0];
}
#line 2169 "src/main.tab.cpp"
    break;

  case 54:
#line 550 "src/main.y"
                                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR );
    node->optype=OP_LT;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2185 "src/main.tab.cpp"
    break;

  case 55:
#line 561 "src/main.y"
                                 {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_LQT;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2201 "src/main.tab.cpp"
    break;

  case 56:
#line 572 "src/main.y"
                                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_GT;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2217 "src/main.tab.cpp"
    break;

  case 57:
#line 583 "src/main.y"
                                 {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_GQT;
    node->exprtype=EXPR_RELATION;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_BOOL;
    node->check_type();
    yyval = node;
}
#line 2233 "src/main.tab.cpp"
    break;

  case 58:
#line 597 "src/main.y"
                                 {//有可能需要函数如 a=func()
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_ASSIGN;
    node->exprtype=EXPR_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_VOID;
    node->check_type();
    yyval = node;
}
#line 2249 "src/main.tab.cpp"
    break;

  case 59:
#line 608 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_ADD_ASSIGN;
    node->exprtype=EXPR_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_VOID;
    node->check_type();
    yyval = node;
}
#line 2265 "src/main.tab.cpp"
    break;

  case 60:
#line 619 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_SUB_ASSIGN;
    node->exprtype=EXPR_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_VOID;
    node->check_type();
    yyval = node;
}
#line 2281 "src/main.tab.cpp"
    break;

  case 61:
#line 630 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_MUL_ASSIGN;
    node->exprtype=EXPR_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_VOID;
    node->check_type();
    yyval = node;
}
#line 2297 "src/main.tab.cpp"
    break;

  case 62:
#line 641 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node->optype=OP_DIV_ASSIGN;
    node->exprtype=EXPR_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=TYPE_VOID;
    node->check_type();
    yyval = node;
}
#line 2313 "src/main.tab.cpp"
    break;

  case 63:
#line 655 "src/main.y"
           {
    yyval=yyvsp[0];
}
#line 2321 "src/main.tab.cpp"
    break;

  case 64:
#line 658 "src/main.y"
                             {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_ADD;
    node->exprtype=EXPR_ADDITIVE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-2]->type;
    node->check_type();
    yyval = node;
}
#line 2337 "src/main.tab.cpp"
    break;

  case 65:
#line 669 "src/main.y"
                             {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->exprtype=EXPR_ADDITIVE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-2]->type;
    node->check_type();
    yyval = node;
}
#line 2353 "src/main.tab.cpp"
    break;

  case 66:
#line 683 "src/main.y"
           {
    yyval=yyvsp[0];
}
#line 2361 "src/main.tab.cpp"
    break;

  case 67:
#line 686 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_MUL;
    node->exprtype=EXPR_ADDITIVE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-2]->type;
    node->check_type();
    yyval = node;
}
#line 2377 "src/main.tab.cpp"
    break;

  case 68:
#line 697 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_DIV;
    node->exprtype=EXPR_ADDITIVE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-2]->type;
    node->check_type();
    yyval = node;
}
#line 2393 "src/main.tab.cpp"
    break;

  case 69:
#line 708 "src/main.y"
                          {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->optype=OP_MODE;
    node->exprtype=EXPR_ADDITIVE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-2]->type;
    node->check_type();
    yyval = node;
}
#line 2409 "src/main.tab.cpp"
    break;

  case 70:
#line 722 "src/main.y"
            {
    yyval=yyvsp[0];
}
#line 2417 "src/main.tab.cpp"
    break;

  case 71:
#line 727 "src/main.y"
              {
    yyval=yyvsp[0];//增加这一层是为了方便以后扩充
}
#line 2425 "src/main.tab.cpp"
    break;

  case 72:
#line 730 "src/main.y"
               {
    TreeNode* node=new TreeNode(yyvsp[-1]->lineno,NODE_EXPR);
    node->optype=OP_SUB;
    node->exprtype=EXPR_UNARY;
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[0]->type;
    node->check_type();
    yyval=node;
}
#line 2440 "src/main.tab.cpp"
    break;

  case 73:
#line 740 "src/main.y"
               {
    TreeNode* node=new TreeNode(yyvsp[-1]->lineno,NODE_EXPR);
    node->optype=OP_NOT;
    node->exprtype=EXPR_UNARY;
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[0]->type;
    node->check_type();
    yyval=node;
}
#line 2455 "src/main.tab.cpp"
    break;

  case 74:
#line 750 "src/main.y"
                     {
    TreeNode* node=new TreeNode(yyvsp[-1]->lineno,NODE_EXPR);
    node->optype=OP_REF;
    node->exprtype=EXPR_UNARY;
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[0]->type;
    node->check_type();
    yyval=node;
}
#line 2470 "src/main.tab.cpp"
    break;

  case 75:
#line 763 "src/main.y"
              {
    yyval=yyvsp[0];
}
#line 2478 "src/main.tab.cpp"
    break;

  case 76:
#line 766 "src/main.y"
                  {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno,NODE_EXPR);
    node->optype=OP_INC;
    node->exprtype=EXPR_POSTFIX;
    node->addChild(yyvsp[-1]);
    node->layer_node=currentNode;
    node->type=yyvsp[-1]->type;
    node->check_type();
    yyval=node;
}
#line 2493 "src/main.tab.cpp"
    break;

  case 77:
#line 776 "src/main.y"
                  {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno,NODE_EXPR);
    node->optype=OP_DEC;
    node->exprtype=EXPR_POSTFIX;
    node->addChild(yyvsp[0]);
    node->layer_node=currentNode;
    node->type=yyvsp[-1]->type;
    node->check_type();
    yyval=node;
}
#line 2508 "src/main.tab.cpp"
    break;

  case 78:
#line 789 "src/main.y"
             {
    yyval = yyvsp[0];
}
#line 2516 "src/main.tab.cpp"
    break;

  case 79:
#line 792 "src/main.y"
            {
    yyval=yyvsp[0];
}
#line 2524 "src/main.tab.cpp"
    break;

  case 80:
#line 795 "src/main.y"
            {
    yyval=yyvsp[-1];
}
#line 2532 "src/main.tab.cpp"
    break;

  case 81:
#line 801 "src/main.y"
          {
    yyval = yyvsp[0];

}
#line 2541 "src/main.tab.cpp"
    break;

  case 82:
#line 805 "src/main.y"
       {
    yyval = yyvsp[0];

}
#line 2550 "src/main.tab.cpp"
    break;

  case 83:
#line 809 "src/main.y"
         {
    yyval = yyvsp[0];

}
#line 2559 "src/main.tab.cpp"
    break;

  case 84:
#line 813 "src/main.y"
       {
    yyval=yyvsp[0];

}
#line 2568 "src/main.tab.cpp"
    break;

  case 85:
#line 820 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_INT;yyval->layer_node=currentNode;}
#line 2574 "src/main.tab.cpp"
    break;

  case 86:
#line 821 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_CHAR;yyval->layer_node=currentNode;}
#line 2580 "src/main.tab.cpp"
    break;

  case 87:
#line 822 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_BOOL;yyval->layer_node=currentNode;}
#line 2586 "src/main.tab.cpp"
    break;

  case 88:
#line 823 "src/main.y"
           {yyval = new TreeNode(lineno,NODE_TYPE); yyval->type = TYPE_STRING;yyval->layer_node=currentNode;}
#line 2592 "src/main.tab.cpp"
    break;

  case 89:
#line 824 "src/main.y"
         {yyval = new TreeNode(lineno,NODE_TYPE); yyval->type = TYPE_VOID;yyval->layer_node=currentNode;}
#line 2598 "src/main.tab.cpp"
    break;


#line 2602 "src/main.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 827 "src/main.y"


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
