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
#line 1 "c.y"

    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    
    #include "config.h"
    #include "utils.h"

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 


#line 85 "c.tab.c"

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
#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
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
    C_FLOAT = 259,
    ARRAY = 260,
    CLASS = 261,
    VOID = 262,
    FUNCTION = 263,
    FLOAT = 264,
    STRING = 265,
    WHILE = 266,
    BTRUE = 267,
    BFALSE = 268,
    BOOL = 269,
    IF = 270,
    ELSE = 271,
    BEGINP = 272,
    ENDP = 273,
    CONST = 274,
    FOR = 275,
    RET = 276,
    TYPEOF = 277,
    EVAL = 278,
    CHAR = 279,
    ID = 280,
    EQ = 281,
    NEQ = 282,
    LEQ = 283,
    GEQ = 284,
    OR = 285,
    AND = 286,
    LT = 287,
    GT = 288,
    C_CHAR = 289,
    C_STRING = 290,
    C_INT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "c.y"

    int intval;
    char* strval;
    struct AstNode *astNode;
    struct NodeInfo *nodeVal;

#line 181 "c.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */



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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


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
      41,    42,    39,    37,    45,    38,    49,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    47,    48,    49,    52,    53,    54,    57,
      60,    65,    70,    75,    80,    87,    88,    94,    95,   104,
      94,   115,   118,   118,   121,   124,   133,   151,   154,   160,
     160,   162,   163,   164,   167,   171,   170,   176,   175,   182,
     185,   185,   190,   195,   195,   203,   218,   218,   231,   237,
     237,   245,   251,   250,   263,   269,   276,   283,   290,   297,
     304,   322,   329,   337,   345,   349,   353,   358,   363,   367,
     371,   375,   379,   383,   387,   391,   395,   399,   403,   407,
     413,   427,   436,   445,   445,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   462,   463,   465,
     475,   476,   478,   479,   483,   482,   495,   496,   497,   498,
     501,   502,   505,   506,   510,   509,   523,   530,   522,   537,
     536,   547,   550
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "C_FLOAT", "ARRAY", "CLASS",
  "VOID", "FUNCTION", "FLOAT", "STRING", "WHILE", "BTRUE", "BFALSE",
  "BOOL", "IF", "ELSE", "BEGINP", "ENDP", "CONST", "FOR", "RET", "TYPEOF",
  "EVAL", "CHAR", "ID", "EQ", "NEQ", "LEQ", "GEQ", "OR", "AND", "LT", "GT",
  "C_CHAR", "C_STRING", "C_INT", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "','", "'['", "']'", "';'", "'.'", "'='", "$accept", "s",
  "declaratii", "declarare", "type", "primitive_type", "return_type",
  "func_decl", "$@1", "$@2", "$@3", "param_list", "$@4", "param",
  "is_const", "class_decl", "$@5", "class_content", "class_method_call",
  "var_decl", "$@6", "$@7", "array_list", "$@8", "array_var", "$@9",
  "array_content", "$@10", "var_list", "$@11", "variable", "$@12",
  "atomic_value", "expression_value", "operator", "var_assignment",
  "class_assignment", "array_assignment", "main", "$@13", "scope_body",
  "func_arguments", "function_call", "typeof_call", "eval_call",
  "repetitive_loop", "for_loop", "$@14", "for_init", "for_condition",
  "for_step", "while_loop", "$@15", "if_statement", "$@16", "$@17",
  "else_statement", "$@18", "return_statement", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47,    40,    41,   123,   125,    44,    91,    93,    59,    46,
      61
};
# endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,   -11,    -7,  -188,  -188,    27,   101,  -188,  -188,  -188,
      19,  -188,  -188,   -12,  -188,   119,  -188,  -188,  -188,  -188,
      11,  -188,  -188,  -188,  -188,  -188,  -188,     2,    -6,  -188,
    -188,    15,   222,    -9,     6,    -3,    24,    12,  -188,  -188,
    -188,  -188,   195,    26,    36,   113,    33,    79,    35,    37,
      38,    73,    45,    55,    62,    79,  -188,  -188,    79,    63,
      65,  -188,    71,  -188,    76,    75,    12,    84,    91,    93,
      99,  -188,  -188,  -188,   177,  -188,  -188,  -188,   195,  -188,
    -188,   328,  -188,   195,   195,   195,   106,   123,   195,    79,
    -188,    79,    79,    79,  -188,    79,    79,    79,  -188,  -188,
    -188,   195,    11,   125,    12,  -188,  -188,    20,   195,   195,
     181,   108,   126,   243,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   195,   260,   277,   223,
     110,   114,   -29,  -188,   328,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,   328,  -188,   120,   121,   128,  -188,   -11,   139,
     129,   130,   294,   311,   163,    11,   328,  -188,   133,   135,
     146,  -188,   328,  -188,  -188,   195,  -188,   148,   195,   150,
    -188,   151,   156,  -188,  -188,   158,   167,   168,  -188,   195,
    -188,  -188,   195,   328,   171,   125,   183,   178,    20,   116,
     116,   328,   176,   328,   143,  -188,   185,   116,  -188,   184,
     190,   200,   191,   193,   214,   202,  -188,  -188,   198,  -188,
     215,  -188,   213,  -188,  -188,   248,   216,   143,  -188,  -188,
     116,  -188,   224,   221,   116,  -188,   233,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    28,     0,    17,    27,     0,    28,     4,    35,     7,
       0,     8,     6,     0,    29,     0,     1,    83,     3,     2,
       0,    10,    11,    13,    12,    14,     9,     0,     0,    16,
      15,     0,    28,    51,     0,    48,     0,    28,    18,   114,
     116,   104,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,    28,   102,   103,    28,     0,
       0,    36,     0,    37,     0,     0,    28,     0,     0,     0,
       0,    55,    57,    56,    60,    58,    59,    54,     0,    64,
      65,   122,    61,     0,     0,     0,     0,     0,     0,    28,
      85,    28,    28,    28,    84,    28,    28,    28,    94,    95,
      93,     0,     0,     0,    28,    30,    31,    28,     0,     0,
     109,     0,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    68,    69,    70,    71,     0,     0,     0,    97,
       0,     0,     0,    34,    80,    89,    90,    91,    92,    86,
      87,    88,    53,    50,    42,     0,    39,    32,    28,     0,
       0,    21,     0,     0,    60,     0,   107,   108,     0,     0,
      62,    67,    66,   100,   101,     0,    99,     0,     0,     0,
      38,     0,     0,    25,    19,     0,     0,     0,   106,   111,
      63,    98,     0,    81,     0,     0,     0,     0,    28,    28,
      28,   110,     0,    82,     0,    41,     0,    28,    23,     0,
       0,   113,     0,    45,     0,     0,   115,   117,     0,   112,
       0,    44,     0,    26,    20,   121,     0,     0,   119,   118,
      28,    47,     0,     0,    28,   105,     0,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,   272,     1,   -14,  -188,    10,  -188,  -188,
    -188,    78,  -188,  -188,  -188,  -188,  -188,   -60,   -23,    13,
    -188,  -188,    94,  -188,  -188,  -188,    67,  -188,   -97,  -188,
    -188,  -188,  -187,     4,  -188,  -106,  -188,  -188,  -188,  -188,
     -44,   131,   -32,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    26,    31,    64,    15,    67,
     187,   150,   175,   151,    10,    11,    28,    65,    79,    47,
      20,   103,   145,   171,   146,   169,   202,   212,    34,    62,
      35,    60,    80,   129,   126,    48,    49,    50,    19,    32,
      51,   130,    82,    53,    54,    55,    56,    70,   158,   192,
     210,    57,    68,    58,    69,   215,   219,   222,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    30,    13,    90,   157,   143,   106,   203,     4,    46,
       9,    98,    85,    12,    99,    52,     9,     1,    14,    12,
       3,   168,    21,    52,    46,   148,    52,    16,    22,    23,
     203,     4,    46,    24,    27,    46,    33,    37,    36,     4,
      38,   -52,   -49,    25,   147,   135,    81,   136,   137,   138,
      66,   139,   140,   141,    61,   133,   -33,    52,   178,    52,
      52,    52,   -24,    52,    52,    52,    46,    83,    46,    46,
      46,    63,    46,    46,    46,     1,     2,    84,     3,    66,
     133,    89,   113,    91,     1,    92,    93,   127,   128,     4,
      39,    94,   134,    95,    40,   209,   155,   -96,     4,    41,
      42,    43,    44,    96,    45,   142,     1,     2,   149,     3,
      97,   100,   152,   153,   156,   101,   102,    66,    17,   105,
       4,     1,    21,   -96,   104,   107,    29,    39,    22,    23,
     162,    40,   108,    24,   109,     4,    41,    42,    43,    44,
     110,    45,   131,    25,   159,   199,   200,    71,   132,   172,
     144,   160,   166,   205,    85,    72,    73,    52,    52,    86,
     -96,   167,    87,    88,   173,    52,    46,    46,    74,   170,
     -43,   174,   183,   -40,    46,   -22,   223,    75,    76,    77,
     226,   179,   180,   191,    21,    71,   193,    85,    52,   149,
      22,    23,    52,    72,    73,    24,   185,    46,   182,    71,
     184,    46,   186,   188,    85,    25,   154,    72,    73,   111,
     189,   190,   112,    88,   194,    75,    76,    77,    85,   196,
      74,   197,    78,   111,   201,   208,   112,     1,   206,    75,
      76,    77,   204,    39,   207,   211,    78,    40,   -46,   213,
     -96,     4,    41,    42,    43,    44,   214,    45,    88,   114,
     115,   116,   117,   118,   119,   120,   121,   216,   217,   220,
     122,   123,   124,   125,   218,   225,   198,   224,   165,   114,
     115,   116,   117,   118,   119,   120,   121,   227,    18,   195,
     122,   123,   124,   125,   221,   161,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,   181,   122,   123,   124,
     125,     0,   163,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,     0,   122,   123,   124,   125,     0,   164,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,   122,   123,   124,   125,     0,   176,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   122,   123,
     124,   125,     0,   177,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,     0,   122,   123,   124,   125
};

static const yytype_int16 yycheck[] =
{
      32,    15,     1,    47,   110,   102,    66,   194,    19,    32,
       0,    55,    41,     0,    58,    47,     6,     5,    25,     6,
       8,    50,     3,    55,    47,     5,    58,     0,     9,    10,
     217,    19,    55,    14,    46,    58,    25,    43,    36,    19,
      25,    50,    45,    24,   104,    89,    42,    91,    92,    93,
      37,    95,    96,    97,    48,    87,    44,    89,   155,    91,
      92,    93,    42,    95,    96,    97,    89,    41,    91,    92,
      93,    47,    95,    96,    97,     5,     6,    41,     8,    66,
     112,    48,    78,    48,     5,    48,    48,    83,    84,    19,
      11,    18,    88,    48,    15,   201,   110,    18,    19,    20,
      21,    22,    23,    48,    25,   101,     5,     6,   107,     8,
      48,    48,   108,   109,   110,    50,    45,   104,    17,    44,
      19,     5,     3,    44,    48,    41,     7,    11,     9,    10,
     126,    15,    41,    14,    41,    19,    20,    21,    22,    23,
      41,    25,    36,    24,    36,   189,   190,     4,    25,   148,
      25,    25,    42,   197,    41,    12,    13,   189,   190,    46,
      44,    47,    49,    50,    25,   197,   189,   190,    25,    48,
      50,    42,   168,    45,   197,    45,   220,    34,    35,    36,
     224,    48,    47,   179,     3,     4,   182,    41,   220,   188,
       9,    10,   224,    12,    13,    14,    45,   220,    50,     4,
      50,   224,    46,    45,    41,    24,    25,    12,    13,    46,
      43,    43,    49,    50,    43,    34,    35,    36,    41,    36,
      25,    43,    41,    46,    48,    25,    49,     5,    44,    34,
      35,    36,    47,    11,    44,    44,    41,    15,    45,    25,
      18,    19,    20,    21,    22,    23,    44,    25,    50,    26,
      27,    28,    29,    30,    31,    32,    33,    42,    45,    43,
      37,    38,    39,    40,    16,    44,   188,    43,    45,    26,
      27,    28,    29,    30,    31,    32,    33,    44,     6,   185,
      37,    38,    39,    40,   217,    42,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,   165,    37,    38,    39,
      40,    -1,    42,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    42,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    42,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    42,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     8,    19,    52,    53,    54,    55,    58,
      65,    66,    70,    55,    25,    59,     0,    17,    54,    89,
      71,     3,     9,    10,    14,    24,    56,    46,    67,     7,
      56,    57,    90,    25,    79,    81,    36,    43,    25,    11,
      15,    20,    21,    22,    23,    25,    69,    70,    86,    87,
      88,    91,    93,    94,    95,    96,    97,   102,   104,   109,
      82,    48,    80,    47,    58,    68,    70,    60,   103,   105,
      98,     4,    12,    13,    25,    34,    35,    36,    41,    69,
      83,    84,    93,    41,    41,    41,    46,    49,    50,    48,
      91,    48,    48,    48,    18,    48,    48,    48,    91,    91,
      48,    50,    45,    72,    48,    44,    68,    41,    41,    41,
      41,    46,    49,    84,    26,    27,    28,    29,    30,    31,
      32,    33,    37,    38,    39,    40,    85,    84,    84,    84,
      92,    36,    25,    93,    84,    91,    91,    91,    91,    91,
      91,    91,    84,    79,    25,    73,    75,    68,     5,    55,
      62,    64,    84,    84,    25,    56,    84,    86,    99,    36,
      25,    42,    84,    42,    42,    45,    42,    47,    50,    76,
      48,    74,    55,    25,    42,    63,    42,    42,    79,    48,
      47,    92,    50,    84,    50,    45,    46,    61,    45,    43,
      43,    84,   100,    84,    43,    73,    36,    43,    62,    91,
      91,    48,    77,    83,    47,    91,    44,    44,    25,    86,
     101,    44,    78,    25,    44,   106,    42,    45,    16,   107,
      43,    77,   108,    91,    43,    44,    91,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    54,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    59,    60,    61,
      58,    62,    63,    62,    62,    64,    64,    65,    65,    67,
      66,    68,    68,    68,    69,    71,    70,    72,    70,    73,
      74,    73,    75,    76,    75,    77,    78,    77,    79,    80,
      79,    81,    82,    81,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    87,    88,    90,    89,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    93,
      94,    95,    96,    96,    98,    97,    99,    99,    99,    99,
     100,   100,   101,   101,   103,   102,   105,   106,   104,   108,
     107,   107,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
      12,     1,     0,     4,     0,     2,     6,     1,     0,     0,
       6,     2,     3,     0,     3,     0,     4,     0,     8,     1,
       0,     4,     1,     0,     6,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     6,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     0,     1,     3,     4,
       4,     4,     1,     1,     0,    12,     2,     1,     1,     0,
       1,     0,     1,     0,     0,     8,     0,     0,    10,     0,
       5,     0,     2
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
#line 44 "c.y"
                    { printf("cod sintactic corect! ;) \n"); }
#line 1551 "c.tab.c"
    break;

  case 10:
#line 60 "c.y"
                     {
                  if(isFunction) 
                    currentFunction.returnType = 0;
                  else currentVariable.typeInfo.typeName = 0;
               }
#line 1561 "c.tab.c"
    break;

  case 11:
#line 65 "c.y"
                       {
                  if(isFunction) 
                    currentFunction.returnType = 2;
                  else currentVariable.typeInfo.typeName = 2;
               }
#line 1571 "c.tab.c"
    break;

  case 12:
#line 70 "c.y"
                      {
                  if(isFunction) 
                    currentFunction.returnType = 1;
                  else currentVariable.typeInfo.typeName = 1;
               }
#line 1581 "c.tab.c"
    break;

  case 13:
#line 75 "c.y"
                        {
                  if(isFunction) 
                    currentFunction.returnType = 4;
                  else currentVariable.typeInfo.typeName = 4;
               }
#line 1591 "c.tab.c"
    break;

  case 14:
#line 80 "c.y"
                      {
                  if(isFunction) 
                    currentFunction.returnType = 3;
                  else currentVariable.typeInfo.typeName = 3;
               }
#line 1601 "c.tab.c"
    break;

  case 16:
#line 88 "c.y"
                   {
              currentFunction.returnType = 5;
            }
#line 1609 "c.tab.c"
    break;

  case 17:
#line 94 "c.y"
                     {isFunction = 1;}
#line 1615 "c.tab.c"
    break;

  case 18:
#line 95 "c.y"
          {
            strncpy(currentFunction.scope, currentScope, MAX_SCOPE_LEN);
            strncpy(currentFunction.name, (yyvsp[0].strval), MAX_VAR_LEN);
            add_scope((yyvsp[0].strval), 0); 
            init_varList(&currentFunction.parameters); 
            currentFunction.line = yylineno;
            isFunction = 0;
          }
#line 1628 "c.tab.c"
    break;

  case 19:
#line 104 "c.y"
          {
            insert_func(&allFunctions, &currentFunction);
            clear_varList(&currentFunction.parameters);
          }
#line 1637 "c.tab.c"
    break;

  case 20:
#line 109 "c.y"
          {
            remove_from_scope(); 
          }
#line 1645 "c.tab.c"
    break;

  case 21:
#line 115 "c.y"
                   {
              insert_var(&currentFunction.parameters, &currentVariable);
           }
#line 1653 "c.tab.c"
    break;

  case 22:
#line 118 "c.y"
                   {
              insert_var(&currentFunction.parameters, &currentVariable);
           }
#line 1661 "c.tab.c"
    break;

  case 25:
#line 124 "c.y"
                {
        currentVariable.value[0] = 0; 
        // initialized with 0
        currentVariable.typeInfo.isArray = 0;
        currentVariable.typeInfo.arrayLen = 1;
        currentVariable.line = yylineno;
        strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
#line 1675 "c.tab.c"
    break;

  case 26:
#line 133 "c.y"
                                    {
        currentVariable.typeInfo.isArray = 1;
        if((yyvsp[-2].intval) > MAX_ARRAY_LEN) {
          printf("Array elements limit exceeded on line %d\n", yylineno);
        }
        
        currentVariable.typeInfo.arrayLen = min((yyvsp[-2].intval), MAX_ARRAY_LEN);
        for(int i = 0; i < currentVariable.typeInfo.arrayLen; ++i) {
          currentVariable.value[i] = 0;
          // whole array initialized with 0
        }

        currentVariable.line = yylineno;
        strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
#line 1696 "c.tab.c"
    break;

  case 27:
#line 151 "c.y"
                 {
            currentVariable.typeInfo.isConst = 1;
         }
#line 1704 "c.tab.c"
    break;

  case 28:
#line 154 "c.y"
           {
            currentVariable.typeInfo.isConst = 0;
         }
#line 1712 "c.tab.c"
    break;

  case 29:
#line 160 "c.y"
                      {add_scope((yyvsp[0].strval), 1);}
#line 1718 "c.tab.c"
    break;

  case 30:
#line 160 "c.y"
                                                                {remove_from_scope();}
#line 1724 "c.tab.c"
    break;

  case 35:
#line 171 "c.y"
         {
            currentVariable.typeInfo.isArray = 0;
            currentVariable.typeInfo.arrayLen = 1;
         }
#line 1733 "c.tab.c"
    break;

  case 37:
#line 176 "c.y"
         {
            currentVariable.typeInfo.isArray = 1;
            currentVariable.typeInfo.arrayLen = (yyvsp[-1].intval);
         }
#line 1742 "c.tab.c"
    break;

  case 39:
#line 182 "c.y"
                       {
              insert_var(&allVariables, &currentVariable);
           }
#line 1750 "c.tab.c"
    break;

  case 40:
#line 185 "c.y"
                       {
              insert_var(&allVariables, &currentVariable);
           }
#line 1758 "c.tab.c"
    break;

  case 42:
#line 190 "c.y"
               {
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          }
#line 1768 "c.tab.c"
    break;

  case 43:
#line 195 "c.y"
               {
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
              arrayInitPos = 0;
          }
#line 1779 "c.tab.c"
    break;

  case 45:
#line 203 "c.y"
                             {
                if(arrayInitPos >= currentVariable.typeInfo.arrayLen) {
                  printf("Array length excedeed when initializing on line %d. Array Length is %d, while initialization list length is %d.\n", 
                  yylineno, currentVariable.typeInfo.arrayLen, arrayInitPos + 1);
                }
                else {
                  if((yyvsp[0].nodeVal)->nodeType == 2 && (yyvsp[0].nodeVal)->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi((yyvsp[0].nodeVal)->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              }
#line 1799 "c.tab.c"
    break;

  case 46:
#line 218 "c.y"
                             {
                if(arrayInitPos < currentVariable.typeInfo.arrayLen) {
                  if((yyvsp[0].nodeVal)->nodeType == 2 && (yyvsp[0].nodeVal)->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi((yyvsp[0].nodeVal)->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              }
#line 1815 "c.tab.c"
    break;

  case 48:
#line 231 "c.y"
                    {
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
              insert_var(&allVariables, &currentVariable);
            }
         }
#line 1826 "c.tab.c"
    break;

  case 49:
#line 237 "c.y"
                    {
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
              insert_var(&allVariables, &currentVariable);
            }
         }
#line 1837 "c.tab.c"
    break;

  case 51:
#line 245 "c.y"
              {
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
         }
#line 1847 "c.tab.c"
    break;

  case 52:
#line 251 "c.y"
         {
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
          }
#line 1857 "c.tab.c"
    break;

  case 53:
#line 257 "c.y"
          {
            // the case where the variable is initialized + assigned to an expression:))
            insert_declVar_AstList(allAssign, (yyvsp[-3].strval), currentScope, (yyvsp[0].astNode), yylineno, currentVariable.typeInfo.typeName);
          }
#line 1866 "c.tab.c"
    break;

  case 54:
#line 263 "c.y"
                     {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 0;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%d", (yyvsp[0].intval));
             }
#line 1877 "c.tab.c"
    break;

  case 55:
#line 270 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 2;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "float");
             }
#line 1888 "c.tab.c"
    break;

  case 56:
#line 277 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 1;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "false");
             }
#line 1899 "c.tab.c"
    break;

  case 57:
#line 284 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 1;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "true");
             }
#line 1910 "c.tab.c"
    break;

  case 58:
#line 291 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 3;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 1921 "c.tab.c"
    break;

  case 59:
#line 298 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 4;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 1932 "c.tab.c"
    break;

  case 60:
#line 305 "c.y"
             {
                int parameter = 1;
                int ret = check_var_parameter(&allFunctions, (yyvsp[0].strval), currentScope);
                if(ret) {
                  parameter = 0;
                  ret = check_var_defined(&allVariables, (yyvsp[0].strval), currentScope, yylineno);
                }
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 1;
                if(parameter) {
                  (yyval.nodeVal)->dataType = extract_param_type(&allFunctions, (yyvsp[0].strval), currentScope);
                }
                else {
                  (yyval.nodeVal)->dataType = extract_variable_type(&allVariables, (yyvsp[0].strval), currentScope);
                }
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 1954 "c.tab.c"
    break;

  case 61:
#line 323 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = (yyvsp[0].nodeVal)->nodeType;
                (yyval.nodeVal)->dataType = (yyvsp[0].nodeVal)->dataType;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].nodeVal)->value);
             }
#line 1965 "c.tab.c"
    break;

  case 62:
#line 330 "c.y"
             {
               check_class_var(&allVariables, (yyvsp[0].strval), (yyvsp[-2].strval), yylineno);
               (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               (yyval.nodeVal)->nodeType = 1;
               (yyval.nodeVal)->dataType = extract_class_varType(&allVariables, (yyvsp[0].strval), (yyvsp[-2].strval));
               snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval));
             }
#line 1977 "c.tab.c"
    break;

  case 63:
#line 338 "c.y"
             {
               check_array_defined(&allVariables, (yyvsp[-3].strval), currentScope, (yyvsp[-1].intval), yylineno);
               (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               (yyval.nodeVal)->nodeType = 1;
               (yyval.nodeVal)->dataType = extract_variable_type(&allVariables, (yyvsp[-3].strval), currentScope);
               snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s[%d]", (yyvsp[-3].strval), (yyvsp[-1].intval));
             }
#line 1989 "c.tab.c"
    break;

  case 65:
#line 349 "c.y"
                              {
                    (yyval.astNode) = init_Ast((yyvsp[0].nodeVal)->nodeType, (yyvsp[0].nodeVal)->dataType, (yyvsp[0].nodeVal)->value);
                 }
#line 1997 "c.tab.c"
    break;

  case 66:
#line 353 "c.y"
                                                            {
                  //   printf("last operator %s\n", $2);
                    (yyval.astNode) = build_Ast((yyvsp[-1].strval), (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                    free((yyvsp[-1].strval));
                 }
#line 2007 "c.tab.c"
    break;

  case 67:
#line 358 "c.y"
                                            {
                    (yyval.astNode) = (yyvsp[-1].astNode);
                 }
#line 2015 "c.tab.c"
    break;

  case 68:
#line 363 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%c", '+');
         }
#line 2024 "c.tab.c"
    break;

  case 69:
#line 367 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%c", '-');
         }
#line 2033 "c.tab.c"
    break;

  case 70:
#line 371 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%c", '*');
         }
#line 2042 "c.tab.c"
    break;

  case 71:
#line 375 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%c", '/');
         }
#line 2051 "c.tab.c"
    break;

  case 72:
#line 379 "c.y"
              {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2060 "c.tab.c"
    break;

  case 73:
#line 383 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2069 "c.tab.c"
    break;

  case 74:
#line 387 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2078 "c.tab.c"
    break;

  case 75:
#line 391 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2087 "c.tab.c"
    break;

  case 76:
#line 395 "c.y"
              {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2096 "c.tab.c"
    break;

  case 77:
#line 399 "c.y"
               {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2105 "c.tab.c"
    break;

  case 78:
#line 403 "c.y"
              {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2114 "c.tab.c"
    break;

  case 79:
#line 407 "c.y"
              {
            (yyval.strval) = (char *) malloc(MAX_VAR_LEN);
            snprintf((yyval.strval), MAX_VAR_LEN, "%s", (yyvsp[0].strval));
         }
#line 2123 "c.tab.c"
    break;

  case 80:
#line 414 "c.y"
               {
                  int parameter = 1;
                  int ret = check_var_parameter(&allFunctions, (yyvsp[-2].strval), currentScope);
                  if(ret) {
                    parameter = 0;
                    ret = check_var_defined(&allVariables, (yyvsp[-2].strval), currentScope, yylineno);
                  }
                  if(!ret) {
                    insert_var_AstList(allAssign, (yyvsp[-2].strval), currentScope, (yyvsp[0].astNode), yylineno, parameter);
                  }
               }
#line 2139 "c.tab.c"
    break;

  case 81:
#line 428 "c.y"
                 {
                    int ret = check_class_var(&allVariables, (yyvsp[-2].strval), (yyvsp[-4].strval), yylineno);
                    if(!ret) {
                     insert_classVar_AstList(allAssign, (yyvsp[-2].strval), (yyvsp[-4].strval), currentScope, (yyvsp[0].astNode), yylineno);
                    }
                 }
#line 2150 "c.tab.c"
    break;

  case 82:
#line 437 "c.y"
                 {
                    int ret = check_array_defined(&allVariables, (yyvsp[-5].strval), currentScope, (yyvsp[-3].intval), yylineno);
                    if(!ret) {
                     insert_arrayElem_AstList(allAssign, (yyvsp[-5].strval), (yyvsp[-3].intval), currentScope, (yyvsp[0].astNode), yylineno);
                    }
                 }
#line 2161 "c.tab.c"
    break;

  case 83:
#line 445 "c.y"
              {add_scope("~", 0);}
#line 2167 "c.tab.c"
    break;

  case 84:
#line 445 "c.y"
                                                   {remove_from_scope();}
#line 2173 "c.tab.c"
    break;

  case 99:
#line 466 "c.y"
              {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                check_func_defined(&allFunctions, (yyvsp[-3].strval), yylineno);
                (yyval.nodeVal)->nodeType = 3;
                (yyval.nodeVal)->dataType = extract_func_return(&allFunctions, (yyvsp[-3].strval));
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "func");
              }
#line 2185 "c.tab.c"
    break;

  case 104:
#line 483 "c.y"
         {
            forCounter++; 
            char newScope[MAX_VAR_LEN];
            snprintf(newScope, MAX_VAR_LEN, "for_%d", forCounter);
            add_scope(newScope, 0);
         }
#line 2196 "c.tab.c"
    break;

  case 105:
#line 490 "c.y"
         {
            remove_from_scope();
         }
#line 2204 "c.tab.c"
    break;

  case 114:
#line 510 "c.y"
            {
              whileCounter++; 
              char newScope[MAX_VAR_LEN];
              snprintf(newScope, MAX_VAR_LEN, "while_%d", whileCounter);
              add_scope(newScope, 0);
            }
#line 2215 "c.tab.c"
    break;

  case 115:
#line 517 "c.y"
            {
              remove_from_scope();
            }
#line 2223 "c.tab.c"
    break;

  case 116:
#line 523 "c.y"
             {
                ifCounter++; 
                char newScope[MAX_VAR_LEN];
                snprintf(newScope, MAX_VAR_LEN, "if_%d", ifCounter);
                add_scope(newScope, 0);
             }
#line 2234 "c.tab.c"
    break;

  case 117:
#line 530 "c.y"
             {
              remove_from_scope();
             }
#line 2242 "c.tab.c"
    break;

  case 119:
#line 537 "c.y"
               {
                  elseCounter++; 
                  char newScope[MAX_VAR_LEN];
                  snprintf(newScope, MAX_VAR_LEN, "else_%d", elseCounter);
                  add_scope(newScope, 0);
               }
#line 2253 "c.tab.c"
    break;

  case 120:
#line 544 "c.y"
               {
                  remove_from_scope();
               }
#line 2261 "c.tab.c"
    break;


#line 2265 "c.tab.c"

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
#line 552 "c.y"


void yyerror(char *s)
{
  printf("eroare: %s la linia:%d\n", s, yylineno);
}

int main(int argc, char** argv)
{
  yyin = fopen(argv[1],"r");

  init_varList(&allVariables);
  init_funcList(&allFunctions);
  
  // information about every assignation (varName, scope and AstTree coresponding to some Id)
  allAssign = (AstList *) malloc(MAX_VAR_NUM * sizeof(AstList));

  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();

  for(int i = 0; i < cntAssign; ++i) {
    printf("The variable %s on scope %s with type %d has the following AST: \n", allAssign[i].varName, allAssign[i].scope, allAssign[i].varType);
    dfs(allAssign[i].Ast);
    int expType = check_AstTypes(allAssign[i].Ast, allAssign[i].line);
    if(expType == -1) {
      continue;
    }
    if(allAssign[i].varType != expType) {
      printf("The left side of the assignment on line %d has a different type than the right side!\n", allAssign[i].line);
      printf("    The type of left side is '%s' while the type of right side is '%s'\n", decodeType[allAssign[i].varType], decodeType[expType]);
      continue;
    }

    int astResult = computeAst(allAssign[i].Ast, allAssign[i].scope, allAssign[i].line);
    printf("%d\n", astResult);
    /* if(ambigExpr) {
      printf("The expression from the right side on line %d is ambiguous. There are operands that have different types.\n", allAssign[i].Ast->line);
      continue;
    }

    // expression was okay :)
    short isArray = (strchr(allAssign[i].varName, '[') != NULL);  
    short isObjVar = (strchtr(allAssign[i].varName, '.') != NULL);
    
    if(!isArray && !isObjVar) {
      // normal variable 
      //update_var_value(allAssign[i].varName, allAssign[i].scope, );
    }  */
    
  }

  create_symbol_table();
  create_function_table();

  free(allAssign);

  clear_varList(&allVariables);
  clear_funcList(&allFunctions);
} 
