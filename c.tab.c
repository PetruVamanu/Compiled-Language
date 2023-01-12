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
    MCALL = 280,
    ID = 281,
    EQ = 282,
    NEQ = 283,
    LEQ = 284,
    GEQ = 285,
    OR = 286,
    AND = 287,
    LT = 288,
    GT = 289,
    C_CHAR = 290,
    C_STRING = 291,
    C_INT = 292
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

#line 182 "c.tab.c"

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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      42,    43,    40,    38,    46,    39,    51,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    53,    54,    55,    58,    59,    60,    63,
      66,    71,    76,    81,    86,    93,    94,   100,   104,   113,
     100,   138,   141,   141,   144,   147,   156,   175,   178,   184,
     184,   200,   201,   202,   206,   205,   212,   211,   221,   222,
     225,   239,   239,   257,   279,   279,   298,   299,   302,   317,
<<<<<<< HEAD
     316,   343,   349,   356,   363,   370,   377,   384,   423,   430,
     436,   444,   455,   459,   463,   467,   471,   475,   479,   483,
     487,   491,   495,   499,   503,   506,   511,   536,   545,   554,
     565,   565,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   583,   594,   594,   607,   607,
     639,   639,   651,   662,   673,   674,   678,   677,   690,   691,
     692,   693,   696,   697,   700,   701,   705,   704,   718,   725,
     717,   732,   731,   742,   745
=======
     316,   343,   349,   356,   363,   370,   377,   384,   402,   409,
     415,   423,   434,   438,   442,   446,   450,   454,   458,   462,
     466,   470,   474,   478,   482,   485,   490,   504,   513,   522,
     533,   533,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   551,   562,   562,   574,   576,
     576,   609,   609,   621,   632,   643,   644,   648,   647,   660,
     661,   662,   663,   666,   667,   670,   671,   675,   674,   688,
     695,   687,   702,   701,   712,   715
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
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
  "EVAL", "CHAR", "MCALL", "ID", "EQ", "NEQ", "LEQ", "GEQ", "OR", "AND",
  "LT", "GT", "C_CHAR", "C_STRING", "C_INT", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "'{'", "'}'", "','", "'['", "']'", "';'", "'='", "'.'",
  "'&'", "$accept", "s", "declaratii", "declarare", "type",
  "primitive_type", "return_type", "func_decl", "$@1", "$@2", "$@3",
  "param_list", "$@4", "param", "is_const", "class_decl", "$@5",
  "class_content", "var_decl", "$@6", "$@7", "array_list", "array_var",
  "$@8", "array_content", "$@9", "var_list", "variable", "$@10",
  "atomic_value", "expression_value", "var_assignment", "class_assignment",
  "array_assignment", "object_init", "main", "$@11", "scope_body",
  "func_arguments", "$@12", "function_call", "$@13", "class_method_call",
  "$@14", "typeof_call", "eval_call", "repetitive_loop", "for_loop",
  "$@15", "for_init", "for_condition", "for_step", "while_loop", "$@16",
  "if_statement", "$@17", "$@18", "else_statement", "$@19",
  "return_statement", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    40,    41,   123,   125,    44,    91,    93,    59,
      61,    46,    38
};
# endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,    -7,    -8,  -207,  -207,    22,   171,  -207,  -207,  -207,
     194,  -207,  -207,   -16,  -207,   157,  -207,  -207,  -207,  -207,
       9,  -207,  -207,  -207,  -207,  -207,  -207,    -1,    -6,  -207,
    -207,    13,   202,   -10,    -4,    -5,    11,     2,  -207,  -207,
    -207,  -207,     7,     6,    18,    41,    35,   135,    26,    31,
      37,    38,    82,    53,    60,    62,    73,   135,  -207,  -207,
     135,    86,    87,  -207,     9,  -207,     2,    91,     2,    97,
      99,   100,   102,  -207,  -207,  -207,    96,  -207,  -207,  -207,
       7,  -207,   367,  -207,  -207,     7,     7,  -207,   108,     7,
     122,   107,   126,  -207,   135,   135,   135,   135,  -207,   135,
     135,   135,   135,  -207,  -207,  -207,     7,  -207,   133,  -207,
    -207,  -207,    77,     7,     7,   246,   128,   142,   282,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   299,   316,   143,   124,   367,   123,     7,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,   367,   139,   129,
     146,    -7,   159,   150,   149,   333,   350,    56,     9,   367,
    -207,   147,   152,  -207,  -207,   410,   410,    75,    75,   382,
     397,    75,    75,   -14,   -14,  -207,  -207,  -207,  -207,  -207,
    -207,   161,     7,   262,   166,   162,  -207,   133,   155,  -207,
    -207,   168,   172,   183,  -207,     7,  -207,     7,   367,   185,
    -207,   189,  -207,   192,   190,    77,   221,   221,   367,   186,
     367,     7,   226,   197,   221,  -207,   201,   203,   211,  -207,
     206,   207,   231,   219,  -207,  -207,   215,  -207,   224,  -207,
     222,  -207,  -207,   253,   227,   226,  -207,  -207,   221,  -207,
     230,   232,   221,  -207,   233,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    28,     0,    17,    27,     0,    28,     4,    34,     7,
       0,     8,     6,     0,    29,     0,     1,    80,     3,     2,
       0,    10,    11,    13,    12,    14,     9,     0,     0,    16,
      15,     0,    28,    48,     0,    46,     0,    28,    18,   117,
     119,   107,     0,     0,     0,    99,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,   105,   106,
      28,     0,     0,    35,     0,    36,    28,     0,    28,     0,
       0,     0,     0,    52,    54,    53,    57,    55,    56,    51,
       0,    62,   125,    58,    59,     0,     0,   101,     0,     0,
       0,     0,     0,    82,    28,    28,    28,    28,    81,    28,
      28,    28,    28,    92,    93,    91,     0,    47,     0,    32,
      30,    31,    28,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    98,    79,    87,
      89,    90,    88,    83,    84,    85,    86,    50,    40,     0,
      38,    28,     0,     0,    21,     0,     0,    57,     0,   110,
     111,     0,     0,    60,    75,    67,    68,    69,    70,    71,
      72,    73,    74,    63,    64,    65,    66,   103,   104,    99,
     102,     0,     0,    95,     0,     0,    37,     0,     0,    25,
      19,     0,     0,     0,   109,   114,    61,     0,    77,     0,
     100,     0,    39,     0,     0,    28,    28,    28,   113,     0,
      78,    98,     0,     0,    28,    23,     0,     0,   116,    97,
       0,    43,     0,     0,   118,   120,     0,   115,     0,    42,
       0,    26,    20,   124,     0,     0,   122,   121,    28,    45,
       0,     0,    28,   108,     0,   123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,   269,     0,   -11,  -207,     8,  -207,  -207,
    -207,    71,  -207,  -207,  -207,  -207,  -207,   -36,    17,  -207,
    -207,    92,  -207,  -207,    45,  -207,   -59,  -207,  -207,  -206,
       4,  -113,  -207,  -207,  -207,  -207,  -207,   -44,    74,  -207,
     -32,  -207,   -23,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    26,    31,    66,    15,    69,
     204,   153,   191,   154,    10,    11,    28,    67,    47,    20,
     108,   149,   150,   185,   220,   230,    34,    35,    62,    81,
     183,    48,    49,    50,    51,    19,    32,    52,   184,   199,
      83,    91,    84,   133,    55,    56,    57,    58,    72,   161,
     209,   228,    59,    70,    60,    71,   233,   237,   240,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    13,   160,    93,    30,   107,   221,     1,     9,    54,
       3,    73,     4,   103,     9,    53,   104,    12,    14,    74,
      75,     4,    16,    12,    54,    53,   129,   130,    53,   221,
     109,    27,   111,    76,    54,    33,    36,    54,    37,    38,
     -49,    64,    77,    78,    79,    63,    82,   -33,    85,    80,
     139,   140,   141,   142,    68,   143,   144,   145,   146,    65,
      86,    92,    53,    53,    53,    53,    87,    53,    53,    53,
      53,    54,    54,    54,    54,    94,    54,    54,    54,    54,
      95,    87,   151,    68,   118,    68,    96,    97,    88,   131,
     132,    89,    90,   135,     1,     2,     4,     3,   -99,   194,
      98,   180,    99,   116,   158,   227,    89,   117,     4,   100,
     147,   101,   152,   127,   128,   129,   130,   155,   156,   159,
     -24,    87,   102,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   105,   110,   106,   -99,   112,
       1,   113,   114,   116,   115,   134,    39,   117,   136,   137,
      40,   188,   138,   -94,     4,    41,    42,    43,    44,   148,
      21,    45,   216,   217,    29,   162,    22,    23,   163,   179,
     223,    24,   181,   182,    53,    53,     1,     2,   186,     3,
     -94,    25,    53,    54,    54,   189,   198,    46,    17,   -41,
       4,    54,   187,   190,   241,   -22,   195,    21,   244,   208,
     196,   210,   203,    22,    23,   152,    53,     1,    24,   200,
      53,   197,   201,    39,   205,    54,   206,    40,    25,    54,
     -94,     4,    41,    42,    43,    44,     1,   207,    45,   213,
      73,   211,    39,   212,   214,   218,    40,   226,    74,    75,
       4,    41,    42,    43,    44,   222,   224,    45,   225,    21,
      73,   229,    76,   -44,    46,    22,    23,   231,    74,    75,
      24,    77,    78,    79,   232,    89,   -94,   234,   235,   236,
      25,   238,   157,    46,   242,    18,   215,   243,   245,   202,
     239,    77,    78,    79,     0,   219,     0,     0,    80,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     127,   128,   129,   130,     0,     0,     0,     0,   -96,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
     127,   128,   129,   130,     0,   164,   119,   120,   121,   122,
     123,   124,   125,   126,     0,     0,     0,   127,   128,   129,
     130,     0,   177,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,   127,   128,   129,   130,     0,   178,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,   127,   128,   129,   130,     0,   192,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,   127,   128,
     129,   130,     0,   193,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   127,   128,   129,   130,   119,
     120,   121,   122,     0,   124,   125,   126,     0,     0,     0,
     127,   128,   129,   130,   119,   120,   121,   122,     0,     0,
     125,   126,     0,     0,     0,   127,   128,   129,   130,   121,
     122,     0,     0,   125,   126,     0,     0,     0,   127,   128,
     129,   130
};

static const yytype_int16 yycheck[] =
{
      32,     1,   115,    47,    15,    64,   212,     5,     0,    32,
       8,     4,    19,    57,     6,    47,    60,     0,    26,    12,
      13,    19,     0,     6,    47,    57,    40,    41,    60,   235,
      66,    47,    68,    26,    57,    26,    37,    60,    44,    26,
      50,    46,    35,    36,    37,    49,    42,    45,    42,    42,
      94,    95,    96,    97,    37,    99,   100,   101,   102,    48,
      42,    26,    94,    95,    96,    97,    25,    99,   100,   101,
     102,    94,    95,    96,    97,    49,    99,   100,   101,   102,
      49,    25,     5,    66,    80,    68,    49,    49,    47,    85,
      86,    50,    51,    89,     5,     6,    19,     8,    42,   158,
      18,   133,    49,    47,   115,   218,    50,    51,    19,    49,
     106,    49,   112,    38,    39,    40,    41,   113,   114,   115,
      43,    25,    49,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    49,    45,    50,    42,    42,
       5,    42,    42,    47,    42,    37,    11,    51,    26,    42,
      15,   151,    26,    18,    19,    20,    21,    22,    23,    26,
       3,    26,   206,   207,     7,    37,     9,    10,    26,    26,
     214,    14,    48,    50,   206,   207,     5,     6,    49,     8,
      45,    24,   214,   206,   207,    26,   182,    52,    17,    50,
      19,   214,    46,    43,   238,    46,    49,     3,   242,   195,
      48,   197,    47,     9,    10,   205,   238,     5,    14,    43,
     242,    50,    50,    11,    46,   238,    44,    15,    24,   242,
      18,    19,    20,    21,    22,    23,     5,    44,    26,    37,
       4,    46,    11,    44,    44,    49,    15,    26,    12,    13,
      19,    20,    21,    22,    23,    48,    45,    26,    45,     3,
       4,    45,    26,    46,    52,     9,    10,    26,    12,    13,
      14,    35,    36,    37,    45,    50,    45,    43,    46,    16,
      24,    44,    26,    52,    44,     6,   205,    45,    45,   187,
     235,    35,    36,    37,    -1,   211,    -1,    -1,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    27,
      28,    29,    30,    -1,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    27,    28,    29,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     8,    19,    54,    55,    56,    57,    60,
      67,    68,    71,    57,    26,    61,     0,    17,    56,    88,
      72,     3,     9,    10,    14,    24,    58,    47,    69,     7,
      58,    59,    89,    26,    79,    80,    37,    44,    26,    11,
      15,    20,    21,    22,    23,    26,    52,    71,    84,    85,
      86,    87,    90,    93,    95,    97,    98,    99,   100,   105,
     107,   112,    81,    49,    46,    48,    60,    70,    71,    62,
     106,   108,   101,     4,    12,    13,    26,    35,    36,    37,
      42,    82,    83,    93,    95,    42,    42,    25,    47,    50,
      51,    94,    26,    90,    49,    49,    49,    49,    18,    49,
      49,    49,    49,    90,    90,    49,    50,    79,    73,    70,
      45,    70,    42,    42,    42,    42,    47,    51,    83,    27,
      28,    29,    30,    31,    32,    33,    34,    38,    39,    40,
      41,    83,    83,    96,    37,    83,    26,    42,    26,    90,
      90,    90,    90,    90,    90,    90,    90,    83,    26,    74,
      75,     5,    57,    64,    66,    83,    83,    26,    58,    83,
      84,   102,    37,    26,    43,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    43,    43,    26,
      93,    48,    50,    83,    91,    76,    49,    46,    57,    26,
      43,    65,    43,    43,    79,    49,    48,    50,    83,    92,
      43,    50,    74,    47,    63,    46,    44,    44,    83,   103,
      83,    46,    44,    37,    44,    64,    90,    90,    49,    91,
      77,    82,    48,    90,    45,    45,    26,    84,   104,    45,
      78,    26,    45,   109,    43,    46,    16,   110,    44,    77,
     111,    90,    44,    45,    90,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    59,    59,    61,    62,    63,
      60,    64,    65,    64,    64,    66,    66,    67,    67,    69,
      68,    70,    70,    70,    72,    71,    73,    71,    74,    74,
      75,    76,    75,    77,    78,    77,    79,    79,    80,    81,
      80,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    86,    87,
      89,    88,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    92,    91,    91,    94,
      93,    96,    95,    97,    98,    99,    99,   101,   100,   102,
     102,   102,   102,   103,   103,   104,   104,   106,   105,   108,
     109,   107,   111,   110,   110,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
      12,     1,     0,     4,     0,     2,     6,     1,     0,     0,
       6,     2,     2,     0,     0,     4,     0,     8,     1,     3,
       1,     0,     6,     1,     0,     4,     1,     3,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     6,     3,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     0,     1,     0,     4,     0,     0,
       5,     0,     4,     4,     4,     1,     1,     0,    12,     2,
       1,     1,     0,     1,     0,     1,     0,     0,     8,     0,
       0,    10,     0,     5,     0,     2
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
#line 43 "c.y"
                    { 
   if(!error_code)
   {
      create_symbol_table();
      create_function_table();
      printf("cod sintactic corect! ;) \n");  if(final_result){printf("\033[32m%s\033[0m\n", final_result); free(final_result);}
   }
}
#line 1584 "c.tab.c"
    break;

  case 10:
#line 66 "c.y"
                     {
                  if(isFunction) 
                    currentFunction.returnType = 0;
                  else currentVariable.typeInfo.typeName = 0;
               }
#line 1594 "c.tab.c"
    break;

  case 11:
#line 71 "c.y"
                       {
                  if(isFunction) 
                    currentFunction.returnType = 2;
                  else currentVariable.typeInfo.typeName = 2;
               }
#line 1604 "c.tab.c"
    break;

  case 12:
#line 76 "c.y"
                      {
                  if(isFunction) 
                    currentFunction.returnType = 1;
                  else currentVariable.typeInfo.typeName = 1;
               }
#line 1614 "c.tab.c"
    break;

  case 13:
#line 81 "c.y"
                        {
                  if(isFunction) 
                    currentFunction.returnType = 4;
                  else currentVariable.typeInfo.typeName = 4;
               }
#line 1624 "c.tab.c"
    break;

  case 14:
#line 86 "c.y"
                      {
                  if(isFunction) 
                    currentFunction.returnType = 3;
                  else currentVariable.typeInfo.typeName = 3;
               }
#line 1634 "c.tab.c"
    break;

  case 16:
#line 94 "c.y"
                   {
              currentFunction.returnType = 5;
            }
#line 1642 "c.tab.c"
    break;

  case 17:
#line 100 "c.y"
                     {
            isFunction = 1;
          }
#line 1650 "c.tab.c"
    break;

  case 18:
#line 104 "c.y"
          {
            strncpy(currentFunction.scope, currentScope, MAX_SCOPE_LEN);
            strncpy(currentFunction.name, (yyvsp[0].strval), MAX_VAR_LEN);
            add_scope((yyvsp[0].strval), 0); 
            init_varList(&currentFunction.parameters); 
            currentFunction.line = yylineno;
            isFunction = 0;
          }
#line 1663 "c.tab.c"
    break;

  case 19:
#line 113 "c.y"
          {
            int return_value;
            if(!isClass) {
               return_value = check_func_already(&allFunctions, currentFunction.name, &currentFunction.parameters, yylineno);
            }
            else {
               return_value = check_func_already(&classFunctions, currentFunction.name, &currentFunction.parameters, yylineno);
            }
            if(!return_value) {
               if(!isClass) {
                  insert_func(&allFunctions, &currentFunction);
               }
               else {
                  insert_func(&classFunctions, &currentFunction);
               }
            }
            clear_varList(&currentFunction.parameters);
          }
#line 1686 "c.tab.c"
    break;

  case 20:
#line 132 "c.y"
          {
            remove_from_scope(); 
          }
#line 1694 "c.tab.c"
    break;

  case 21:
#line 138 "c.y"
                   {
              insert_var(&currentFunction.parameters, &currentVariable);
           }
#line 1702 "c.tab.c"
    break;

  case 22:
#line 141 "c.y"
                   {
              insert_var(&currentFunction.parameters, &currentVariable);
           }
#line 1710 "c.tab.c"
    break;

  case 25:
#line 147 "c.y"
                {
        currentVariable.value[0] = 0; 
        // initialized with 0
        currentVariable.typeInfo.isArray = 0;
        currentVariable.typeInfo.arrayLen = 1;
        currentVariable.line = yylineno;
        strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
        strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
      }
#line 1724 "c.tab.c"
    break;

  case 26:
#line 156 "c.y"
                                    {
        currentVariable.typeInfo.isArray = 1;
        if((yyvsp[-2].intval) > MAX_ARRAY_LEN) {
          printf("\033[31mArray elements limit exceeded on line %d\n\033[0m", yylineno);
          error_code = 1;
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
#line 1746 "c.tab.c"
    break;

  case 27:
#line 175 "c.y"
                 {
            currentVariable.typeInfo.isConst = 1;
         }
#line 1754 "c.tab.c"
    break;

  case 28:
#line 178 "c.y"
           {
            currentVariable.typeInfo.isConst = 0;
         }
#line 1762 "c.tab.c"
    break;

  case 29:
#line 184 "c.y"
                      {
               isClass = 1; 
               add_scope((yyvsp[0].strval), 1);
               if(classNr >= MAX_FUNC_NUM) {
                  printf("The maximum number of classes has been reached\n");
               }
               else {
                  strncpy(classList[classNr++], (yyvsp[0].strval), MAX_VAR_NUM);
               }
            }
#line 1777 "c.tab.c"
    break;

  case 30:
#line 195 "c.y"
            {
               isClass = 0;
               remove_from_scope();
            }
#line 1786 "c.tab.c"
    break;

  case 34:
#line 206 "c.y"
         {
            currentVariable.typeInfo.isArray = 0;
            currentVariable.typeInfo.arrayLen = 1;
            currentVariable.value[0] = 0;
         }
#line 1796 "c.tab.c"
    break;

  case 36:
#line 212 "c.y"
         {
            currentVariable.typeInfo.isArray = 1;
            currentVariable.typeInfo.arrayLen = (yyvsp[-1].intval);
            for(int i = 0; i < (yyvsp[-1].intval); ++i) {
               currentVariable.value[i] = 0;
            }
         }
#line 1808 "c.tab.c"
    break;

  case 40:
#line 225 "c.y"
               {
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
              int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
              if(!returnVal) {
                  if(!isClass) {
                     insert_var(&allVariables, &currentVariable);
                  }
                  else {
                     insert_var(&classVariables, &currentVariable);
                  }
              }
          }
#line 1827 "c.tab.c"
    break;

  case 41:
#line 239 "c.y"
               {
              currentVariable.line = yylineno;
              strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
              strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
              arrayInitPos = 0;
          }
#line 1838 "c.tab.c"
    break;

  case 42:
#line 244 "c.y"
                                      {
               int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
               if(!returnVal) {
                  if(!isClass) {
                     insert_var(&allVariables, &currentVariable);
                  }
                  else {
                     insert_var(&classVariables, &currentVariable);
                  }
              }
          }
#line 1854 "c.tab.c"
    break;

  case 43:
#line 257 "c.y"
                             {
                if(arrayInitPos >= currentVariable.typeInfo.arrayLen) {
                  printf("\033[31mArray length excedeed when initializing on line %d. Array Length is %d, while initialization list length is %d. \n \033[0m", 
                  yylineno, currentVariable.typeInfo.arrayLen, arrayInitPos + 1);
                  error_code = 1;
                }
                else {

                  if((yyvsp[0].nodeVal)->dataType != currentVariable.typeInfo.typeName){
                     printf("\033[31mArray initialized with different type on line %d.\n\033[0m", yylineno);
                     error_code = 1;
                  }

                  if((yyvsp[0].nodeVal)->nodeType == 2 && (yyvsp[0].nodeVal)->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi((yyvsp[0].nodeVal)->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              }
#line 1881 "c.tab.c"
    break;

  case 44:
#line 279 "c.y"
                             {             
                if(arrayInitPos < currentVariable.typeInfo.arrayLen) {
                  
                  if((yyvsp[0].nodeVal)->dataType != currentVariable.typeInfo.typeName){
                     printf("\033[31mArray initialized with different type on line %d.\n\033[0m", yylineno);
                     error_code = 1;
                  }

                  if((yyvsp[0].nodeVal)->nodeType == 2 && (yyvsp[0].nodeVal)->dataType == 0) {
                    currentVariable.value[arrayInitPos] = atoi((yyvsp[0].nodeVal)->value);
                  }
                  else {
                    currentVariable.value[arrayInitPos] = 0;
                  }
                }
                arrayInitPos++; 
              }
#line 1903 "c.tab.c"
    break;

  case 48:
#line 302 "c.y"
              {
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
               if(!isClass) {
                  insert_var(&allVariables, &currentVariable);
               }
               else {
                  insert_var(&classVariables, &currentVariable);
               }
            }
         }
#line 1922 "c.tab.c"
    break;

  case 49:
#line 317 "c.y"
         {
            currentVariable.line = yylineno;
            strncpy(currentVariable.name, (yyvsp[0].strval), MAX_VAR_LEN);
            strncpy(currentVariable.scope, currentScope, MAX_SCOPE_LEN);
            int returnVal = check_variable_already(&allVariables, currentVariable.name, currentScope, yylineno);
            if(!returnVal) {
               if(!isClass) {
                   insert_var(&allVariables, &currentVariable);
               }
               else {
                  insert_var(&classVariables, &currentVariable);
               }
            }
          }
#line 1941 "c.tab.c"
    break;

  case 50:
#line 332 "c.y"
          {
            // the case where the variable is initialized + assigned to an expression:))
            if(!isClass) {
               do_declVar_assign(&allVariables, (yyvsp[-3].strval), currentScope, (yyvsp[0].astNode), yylineno, currentVariable.typeInfo.typeName);
            }
            else {
               do_declVar_assign(&classVariables, (yyvsp[-3].strval), currentScope, (yyvsp[0].astNode), yylineno, currentVariable.typeInfo.typeName);
            }
          }
#line 1955 "c.tab.c"
    break;

  case 51:
#line 343 "c.y"
                     {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 0;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%d", (yyvsp[0].intval));
             }
#line 1966 "c.tab.c"
    break;

  case 52:
#line 350 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 2;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "float");
             }
#line 1977 "c.tab.c"
    break;

  case 53:
#line 357 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 1;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "false");
             }
#line 1988 "c.tab.c"
    break;

  case 54:
#line 364 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 1;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", "true");
             }
#line 1999 "c.tab.c"
    break;

  case 55:
#line 371 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 3;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 2010 "c.tab.c"
    break;

  case 56:
#line 378 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 2;
                (yyval.nodeVal)->dataType = 4;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 2021 "c.tab.c"
    break;

  case 57:
#line 385 "c.y"
             {
                int parameter = 1;
                int ret;
                if(!isClass) {
                  ret = check_var_parameter(&allFunctions, (yyvsp[0].strval), currentScope);
                }
                else {
                  ret = check_var_parameter(&classFunctions, (yyvsp[0].strval), currentScope);
                }
                if(ret) {
                  parameter = 0;
                  if(!isClass) {
                     ret = check_var_defined(&allVariables, (yyvsp[0].strval), currentScope, yylineno);
                  }
                  else {
                     ret = check_var_defined(&classVariables, (yyvsp[0].strval), currentScope, yylineno);
                  }
                }
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = 1;
                if(parameter) {
                  if(!isClass) {
                     (yyval.nodeVal)->dataType = extract_param_type(&allFunctions, (yyvsp[0].strval), currentScope);
                  }
                  else {
                     (yyval.nodeVal)->dataType = extract_param_type(&classFunctions, (yyvsp[0].strval), currentScope);
                  }
                }
                else {
                  if(!isClass) {
                     (yyval.nodeVal)->dataType = extract_variable_type(&allVariables, (yyvsp[0].strval), currentScope);
                  }
                  else {
                     (yyval.nodeVal)->dataType = extract_variable_type(&classVariables, (yyvsp[0].strval), currentScope);                     
                  }
                }
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].strval));
             }
#line 2064 "c.tab.c"
    break;

  case 58:
#line 424 "c.y"
             {
                (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                (yyval.nodeVal)->nodeType = (yyvsp[0].nodeVal)->nodeType;
                (yyval.nodeVal)->dataType = (yyvsp[0].nodeVal)->dataType;
                snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].nodeVal)->value);
             }
#line 2075 "c.tab.c"
    break;

  case 59:
#line 430 "c.y"
                                 {
                  (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                  (yyval.nodeVal)->nodeType = (yyvsp[0].nodeVal)->nodeType;
                  (yyval.nodeVal)->dataType = (yyvsp[0].nodeVal)->dataType;
                  snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s", (yyvsp[0].nodeVal)->value);
               }
#line 2086 "c.tab.c"
    break;

  case 60:
#line 437 "c.y"
             {
               check_class_var(&allVariables, (yyvsp[0].strval), (yyvsp[-2].strval), yylineno);
               (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               (yyval.nodeVal)->nodeType = 1;
               (yyval.nodeVal)->dataType = extract_class_varType(&allVariables, (yyvsp[0].strval), (yyvsp[-2].strval));
               snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval));
             }
#line 2098 "c.tab.c"
    break;

  case 61:
#line 445 "c.y"
             {
               check_array_defined(&allVariables, (yyvsp[-3].strval), currentScope, (yyvsp[-1].intval), yylineno);
               (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
               (yyval.nodeVal)->nodeType = 1;
               (yyval.nodeVal)->dataType = extract_variable_type(&allVariables, (yyvsp[-3].strval), currentScope);
               snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "%s[%d]", (yyvsp[-3].strval), (yyvsp[-1].intval));
             }
#line 2110 "c.tab.c"
    break;

  case 62:
#line 455 "c.y"
                              {
                    (yyval.astNode) = init_Ast((yyvsp[0].nodeVal)->nodeType, (yyvsp[0].nodeVal)->dataType, (yyvsp[0].nodeVal)->value);
                 }
#line 2118 "c.tab.c"
    break;

  case 63:
#line 459 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("+", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2126 "c.tab.c"
    break;

  case 64:
#line 463 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("-", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2134 "c.tab.c"
    break;

  case 65:
#line 467 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("*", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2142 "c.tab.c"
    break;

  case 66:
#line 471 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("/", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2150 "c.tab.c"
    break;

  case 67:
#line 475 "c.y"
                                                      {
                    (yyval.astNode) = build_Ast("==", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2158 "c.tab.c"
    break;

  case 68:
#line 479 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("<>", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2166 "c.tab.c"
    break;

  case 69:
#line 483 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("<=", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2174 "c.tab.c"
    break;

  case 70:
#line 487 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast(">=", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2182 "c.tab.c"
    break;

  case 71:
#line 491 "c.y"
                                                      {
                    (yyval.astNode) = build_Ast("||", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2190 "c.tab.c"
    break;

  case 72:
#line 495 "c.y"
                                                       {
                    (yyval.astNode) = build_Ast("&&", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2198 "c.tab.c"
    break;

  case 73:
#line 499 "c.y"
                                                      {
                    (yyval.astNode) = build_Ast("<", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2206 "c.tab.c"
    break;

  case 74:
#line 503 "c.y"
                                                      {
                    (yyval.astNode) = build_Ast(">", (yyvsp[-2].astNode), (yyvsp[0].astNode), 0);
                 }
#line 2214 "c.tab.c"
    break;

  case 75:
#line 506 "c.y"
                                            {
                    (yyval.astNode) = (yyvsp[-1].astNode);
                 }
#line 2222 "c.tab.c"
    break;

  case 76:
#line 512 "c.y"
               {
                  int parameter = 1;
                  int ret;
                  if(!isClass) {
                     ret = check_var_parameter(&allFunctions, (yyvsp[-2].strval), currentScope);
                  } 
                  else {
                     ret = check_var_parameter(&classFunctions, (yyvsp[-2].strval), currentScope);
                  }
                  if(ret) {
                    parameter = 0;
                    if(!isClass) {
                        ret = check_var_defined(&allVariables, (yyvsp[-2].strval), currentScope, yylineno);
                    }
                    else {
                        ret = check_var_defined(&classVariables, (yyvsp[-2].strval), currentScope, yylineno);
                    }
                  }
                  if(!ret) {
                     do_var_assign((yyvsp[-2].strval), currentScope, (yyvsp[0].astNode), yylineno, parameter);
                  }
               }
#line 2249 "c.tab.c"
    break;

  case 77:
#line 537 "c.y"
                 {
                    int ret = check_class_var(&allVariables, (yyvsp[-2].strval), (yyvsp[-4].strval), yylineno);
                    if(!ret) {
                      do_classVar_assign((yyvsp[-2].strval), (yyvsp[-4].strval), currentScope, (yyvsp[0].astNode), yylineno);
                    }
                 }
#line 2260 "c.tab.c"
    break;

  case 78:
#line 546 "c.y"
                 {
                    int ret = check_array_defined(&allVariables, (yyvsp[-5].strval), currentScope, (yyvsp[-3].intval), yylineno);
                    if(!ret) {
                     do_arrayElem_assign((yyvsp[-5].strval), (yyvsp[-3].intval), currentScope, (yyvsp[0].astNode), yylineno);
                    }
                 }
#line 2271 "c.tab.c"
    break;

  case 79:
#line 554 "c.y"
                        {
   if(!checkClass((yyvsp[-1].strval))) {
      printf("The class %s used to initialize object %s on line %d has not been defined\n", (yyvsp[-1].strval), (yyvsp[0].strval), yylineno);
   }
   else {
      add_scope((yyvsp[0].strval), 1);
      from_class_to_all((yyvsp[-1].strval), currentScope);
      remove_from_scope();
   }
}
#line 2286 "c.tab.c"
    break;

  case 80:
#line 565 "c.y"
              {add_scope("~", 0);}
#line 2292 "c.tab.c"
    break;

  case 81:
#line 565 "c.y"
                                                   {remove_from_scope();}
#line 2298 "c.tab.c"
    break;

  case 95:
#line 583 "c.y"
                                  {
                  if(myStack[stackCount] >= MAX_ARGS_NR) {
                     printf("\033[31mMaximum number of arguments for a function had been reached on line %d\n\033[0m", yylineno);
                     error_code = 1;
                  }
                  else {
                     int type = check_AstTypes((yyvsp[0].astNode), yylineno);
                     // insert into the list of arguments of types for this function :))
                     funcArgTypes[myStack[stackCount]++] = type;
                  }
               }
#line 2314 "c.tab.c"
    break;

  case 96:
#line 594 "c.y"
                                  {
                  if(myStack[stackCount] >= MAX_ARGS_NR) {
                     printf("\033[31mMaximum number of arguments for a function had been reached on line %d\n\033[0m", yylineno);
                  
                     error_code = 1;
                  } 
                  else {
                     int type = check_AstTypes((yyvsp[0].astNode), yylineno);
                     // insert into the list of arguments of types for this function :))
                     funcArgTypes[myStack[stackCount]++] = type;
                  }
               }
#line 2331 "c.tab.c"
    break;

<<<<<<< HEAD
  case 98:
#line 607 "c.y"
=======
  case 99:
#line 576 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
                   {
                  stackCount++;
                  // myStack[stackCount] = 0;
                  myStack[stackCount] = 0;
              }
#line 2341 "c.tab.c"
    break;

<<<<<<< HEAD
  case 99:
#line 613 "c.y"
=======
  case 100:
#line 583 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
              {
                  (yyval.nodeVal) = (struct NodeInfo *) malloc(sizeof(struct NodeInfo));
                  if(!inObj) {
                     // it's a simple function call
                     int retValue = check_func_defined(&allFunctions, (yyvsp[-4].strval), yylineno);
                     if(!retValue){
                        check_func_arguments(&allFunctions, (yyvsp[-4].strval), funcArgTypes, myStack[stackCount], yylineno);
                     }
                     (yyval.nodeVal)->nodeType = 3;
                     (yyval.nodeVal)->dataType = extract_func_return(&allFunctions, (yyvsp[-4].strval));
                     snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "func");
                  }
                  else {
                     // It's a method from a class. The name of the class is stored in objName
                     int retValue = check_method_defined(&allFunctions, (yyvsp[-4].strval), objName,  yylineno);
                     if(!retValue) {
                        check_method_arguments(&allFunctions, (yyvsp[-4].strval), objName, funcArgTypes, myStack[stackCount], yylineno);
                     }
                     (yyval.nodeVal)->nodeType = 3;
                     (yyval.nodeVal)->dataType = extract_method_return(&allFunctions, (yyvsp[-4].strval), objName);
                     snprintf((yyval.nodeVal)->value, MAX_VAR_LEN, "method");
                  }
                  stackCount--;
              }
#line 2370 "c.tab.c"
    break;

<<<<<<< HEAD
  case 100:
#line 639 "c.y"
=======
  case 101:
#line 609 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
                             {
                     inObj = 1;
                     strncpy(objName, (yyvsp[-1].strval), MAX_VAR_LEN); 
                  }
#line 2379 "c.tab.c"
    break;

<<<<<<< HEAD
  case 101:
#line 644 "c.y"
=======
  case 102:
#line 614 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
                  {
                     (yyval.nodeVal)->nodeType = (yyvsp[0].nodeVal)->nodeType;
                     (yyval.nodeVal)->dataType = (yyvsp[0].nodeVal)->dataType;
                     strncpy((yyval.nodeVal)->value, "method", MAX_VAR_LEN);
                     inObj = 0;
                  }
#line 2390 "c.tab.c"
    break;

<<<<<<< HEAD
  case 102:
#line 651 "c.y"
=======
  case 103:
#line 621 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
                                              {
   // Third parameter is expression value, $3 -> AST coresponding to that expression
   int type = check_AstTypes((yyvsp[-1].astNode), yylineno);
   if(type != -1) {
      // printf("~The expression from the 'TypeOf()' call on line %d has the type %s\n", yylineno, decodeType[type]);
      char *p = (char*)malloc(1000* sizeof(char));
      sprintf(p, "The expression from the 'TypeOf()' call on line %d has the type %s\n", yylineno, decodeType[type]);
      final_result = concatenate_and_free(final_result, p);
   }
}
#line 2405 "c.tab.c"
    break;

<<<<<<< HEAD
  case 103:
#line 662 "c.y"
=======
  case 104:
#line 632 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
                                          {
   int type = check_AstTypes((yyvsp[-1].astNode), yylineno);
   if(type != -1) {
      int result = computeAst((yyvsp[-1].astNode), currentScope, yylineno);
      // printf("~The expression from the 'Eval()' call on line %d has the value %d\n", yylineno, result);
      char *p = (char*)malloc(1000* sizeof(char));
      sprintf(p, "The expression from the 'Eval()' call on line %d has the value %d\n", yylineno, result);
      final_result = concatenate_and_free(final_result, p);
   }
}
#line 2420 "c.tab.c"
    break;

<<<<<<< HEAD
  case 106:
#line 678 "c.y"
=======
  case 107:
#line 648 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
         {
            forCounter++; 
            char newScope[MAX_VAR_LEN];
            snprintf(newScope, MAX_VAR_LEN, "for_%d", forCounter);
            add_scope(newScope, 0);
         }
#line 2431 "c.tab.c"
    break;

<<<<<<< HEAD
  case 107:
#line 685 "c.y"
=======
  case 108:
#line 655 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
         {
            remove_from_scope();
         }
#line 2439 "c.tab.c"
    break;

<<<<<<< HEAD
  case 116:
#line 705 "c.y"
=======
  case 117:
#line 675 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
            {
              whileCounter++; 
              char newScope[MAX_VAR_LEN];
              snprintf(newScope, MAX_VAR_LEN, "while_%d", whileCounter);
              add_scope(newScope, 0);
            }
#line 2450 "c.tab.c"
    break;

<<<<<<< HEAD
  case 117:
#line 712 "c.y"
=======
  case 118:
#line 682 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
            {
              remove_from_scope();
            }
#line 2458 "c.tab.c"
    break;

<<<<<<< HEAD
  case 118:
#line 718 "c.y"
=======
  case 119:
#line 688 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
             {
                ifCounter++; 
                char newScope[MAX_VAR_LEN];
                snprintf(newScope, MAX_VAR_LEN, "if_%d", ifCounter);
                add_scope(newScope, 0);
             }
#line 2469 "c.tab.c"
    break;

<<<<<<< HEAD
  case 119:
#line 725 "c.y"
=======
  case 120:
#line 695 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
             {
              remove_from_scope();
             }
#line 2477 "c.tab.c"
    break;

<<<<<<< HEAD
  case 121:
#line 732 "c.y"
=======
  case 122:
#line 702 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
               {
                  elseCounter++; 
                  char newScope[MAX_VAR_LEN];
                  snprintf(newScope, MAX_VAR_LEN, "else_%d", elseCounter);
                  add_scope(newScope, 0);
               }
#line 2488 "c.tab.c"
    break;

<<<<<<< HEAD
  case 122:
#line 739 "c.y"
=======
  case 123:
#line 709 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76
               {
                  remove_from_scope();
               }
#line 2496 "c.tab.c"
    break;


#line 2500 "c.tab.c"

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
<<<<<<< HEAD
#line 747 "c.y"
=======
#line 717 "c.y"
>>>>>>> 23e58b1473cf5b1ed094a4747b117d80bc770f76


void yyerror(char *s)
{
  printf("eroare: %s la linia:%d\n", s, yylineno);
}

int main(int argc, char** argv)
{
  yyin = fopen(argv[1], "r");

  init_varList(&allVariables);
  init_varList(&classVariables);
  init_funcList(&allFunctions);
  init_funcList(&classFunctions);
  // information about every assignation (varName, scope and AstTree coresponding to some Id)

  strncpy(currentScope, "/", MAX_SCOPE_LEN);

  yyparse();


  clear_varList(&allVariables);
  clear_varList(&classVariables);
  clear_funcList(&allFunctions);
  clear_funcList(&classFunctions);
} 
