/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
FILE *outfile;
extern int yylineno;

int yylex();
void yyerror(const char *s);

// --- GENERADORES ---
int temp_count = 0;
char* gen_temp() {
    char buffer[20];
    sprintf(buffer, "_t%d", temp_count++);
    fprintf(outfile, "VAR %s\n", buffer);
    return strdup(buffer);
}

int label_count = 0;
char* gen_label() {
    char buffer[20];
    sprintf(buffer, "L%d", label_count++);
    return strdup(buffer);
}

// --- PILAS ---
struct LoopInfo {
    char *start;
    char *end;
    char *body;
    char *inc;
} loop_stack[100];
int l_top = -1;

void push_loop(char *s, char *e, char *b, char *i) {
    l_top++;
    loop_stack[l_top].start = s;
    loop_stack[l_top].end = e;
    loop_stack[l_top].body = b;
    loop_stack[l_top].inc = i;
}
void pop_loop() { l_top--; }

struct IfInfo {
    char *label_else;
    char *label_end;
} if_stack[100];
int i_top = -1;

void push_if(char *l_else, char *l_end) {
    i_top++;
    if_stack[i_top].label_else = l_else;
    if_stack[i_top].label_end = l_end;
}
void pop_if() { i_top--; }


#line 132 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LIT = 3,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 4,                  /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 5,                 /* STRING_LIT  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_KW_VAR = 7,                     /* KW_VAR  */
  YYSYMBOL_KW_FUNC = 8,                    /* KW_FUNC  */
  YYSYMBOL_KW_RETURN = 9,                  /* KW_RETURN  */
  YYSYMBOL_TYPE_INT = 10,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 11,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_BOOL = 12,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 13,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_VOID = 14,                 /* TYPE_VOID  */
  YYSYMBOL_TYPE_ARRAY = 15,                /* TYPE_ARRAY  */
  YYSYMBOL_KW_IF = 16,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 17,                   /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 18,                  /* KW_WHILE  */
  YYSYMBOL_KW_FOR = 19,                    /* KW_FOR  */
  YYSYMBOL_KW_PRINT = 20,                  /* KW_PRINT  */
  YYSYMBOL_KW_DRAW = 21,                   /* KW_DRAW  */
  YYSYMBOL_KW_INPUT = 22,                  /* KW_INPUT  */
  YYSYMBOL_KW_READ = 23,                   /* KW_READ  */
  YYSYMBOL_KW_NEW_ARRAY = 24,              /* KW_NEW_ARRAY  */
  YYSYMBOL_KW_PUSH = 25,                   /* KW_PUSH  */
  YYSYMBOL_KW_LENGTH = 26,                 /* KW_LENGTH  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_MULT = 30,                      /* MULT  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_POW = 33,                       /* POW  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NEQ = 35,                       /* NEQ  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_LTE = 38,                       /* LTE  */
  YYSYMBOL_GTE = 39,                       /* GTE  */
  YYSYMBOL_LPAREN = 40,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 41,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 42,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 43,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 44,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 45,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_statement_list = 50,            /* statement_list  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_block = 52,                     /* block  */
  YYSYMBOL_var_decl = 53,                  /* var_decl  */
  YYSYMBOL_assignment = 54,                /* assignment  */
  YYSYMBOL_for_update = 55,                /* for_update  */
  YYSYMBOL_input_stmt = 56,                /* input_stmt  */
  YYSYMBOL_input_expr = 57,                /* input_expr  */
  YYSYMBOL_print_stmt = 58,                /* print_stmt  */
  YYSYMBOL_pixel_stmt = 59,                /* pixel_stmt  */
  YYSYMBOL_if_stmt = 60,                   /* if_stmt  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_optional_else = 63,             /* optional_else  */
  YYSYMBOL_while_stmt = 64,                /* while_stmt  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_for_stmt = 67,                  /* for_stmt  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_condition = 71,                 /* condition  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_type = 75                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    89,    90,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   106,   111,   115,   119,   127,   133,
     139,   143,   144,   148,   154,   160,   165,   160,   172,   176,
     183,   187,   183,   199,   203,   215,   199,   226,   227,   228,
     229,   230,   231,   235,   236,   237,   241,   242,   243,   244,
     248,   249,   250,   251,   252,   256,   257,   258,   259,   260,
     261
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LIT", "FLOAT_LIT",
  "STRING_LIT", "ID", "KW_VAR", "KW_FUNC", "KW_RETURN", "TYPE_INT",
  "TYPE_FLOAT", "TYPE_BOOL", "TYPE_STRING", "TYPE_VOID", "TYPE_ARRAY",
  "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_PRINT", "KW_DRAW",
  "KW_INPUT", "KW_READ", "KW_NEW_ARRAY", "KW_PUSH", "KW_LENGTH", "ASSIGN",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "POW", "EQ", "NEQ", "LT", "GT",
  "LTE", "GTE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "SEMICOLON", "COMMA", "$accept", "program", "statement_list",
  "statement", "block", "var_decl", "assignment", "for_update",
  "input_stmt", "input_expr", "print_stmt", "pixel_stmt", "if_stmt", "$@1",
  "$@2", "optional_else", "while_stmt", "$@3", "$@4", "for_stmt", "$@5",
  "$@6", "$@7", "condition", "expression", "term", "factor", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      50,   -17,    95,   -27,   -18,    -7,     2,     5,    18,    24,
      50,    85,    50,   -54,   -54,   -54,   -54,   -54,    45,   -54,
     -54,   -54,   -54,   -54,    25,   -54,   -54,   -54,   -54,   -54,
     -54,    89,    25,   -54,    91,    25,    25,    93,   108,    -2,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,    25,     8,    51,
     -54,    88,    75,    65,    25,   -54,   -26,     6,    76,    77,
     -54,    46,    25,    25,   -54,    25,    25,    25,     3,   -54,
      25,    25,    25,    25,    25,    25,    78,    25,    74,    25,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    81,    79,
      34,    80,    60,    60,    60,    60,    60,    60,   -54,    82,
     -54,    32,    83,   -54,   -54,   -54,    80,   -54,    25,    84,
     106,   -54,   120,    49,   -54,    80,   -54,   100,    90,    86,
     -54,    25,   -54,   -54,    60,    80,   -54
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,    13,     5,     6,     9,     0,     7,
       8,    10,    11,    12,     0,    55,    56,    58,    57,    59,
      60,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       1,     4,    20,    52,    53,    54,    51,     0,     0,    45,
      49,     0,     0,     0,     0,    33,     0,     0,     0,     0,
      14,     0,     0,     0,    18,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,    50,    43,    44,    46,    47,    48,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    31,     0,
      23,     0,     0,    16,    15,    26,     0,    34,     0,     0,
      28,    32,     0,     0,    17,     0,    27,     0,     0,     0,
      29,     0,    35,    24,    19,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   119,    20,   -39,    99,   -54,   -54,   -54,    66,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -53,   -24,    47,   -54,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,   118,    17,    18,
      19,    20,    21,    91,   110,   116,    22,    54,   106,    23,
      77,   112,   125,    52,    53,    49,    50,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    76,    62,    63,     1,     2,    43,    44,    45,    46,
      24,    56,    57,    32,     3,    78,     4,     5,     6,     7,
       8,     9,    33,    61,    99,     8,     9,    88,    43,    44,
      45,    46,    41,    34,    62,    63,    62,    63,    83,    84,
      10,    60,    35,    47,    90,    36,    92,    93,    94,    95,
      96,    97,   105,    79,    64,   101,     1,     2,    37,    41,
      62,    63,    62,    63,    38,    47,     3,   111,     4,     5,
       6,     7,     8,     9,    62,    63,   120,    62,    63,   108,
     104,    65,    66,    67,   113,    40,   126,    82,    62,    63,
     119,    42,    10,    62,    63,    51,    58,   124,     2,    70,
      71,    72,    73,    74,    75,    25,    26,    27,    28,    29,
      30,    59,    85,    86,    87,    68,    69,    80,    81,    98,
     100,   102,    10,   115,   109,   103,   117,   121,   107,    39,
     114,   122,   123,    55,    89
};

static const yytype_int8 yycheck[] =
{
      24,    54,    28,    29,     6,     7,     3,     4,     5,     6,
      27,    35,    36,    40,    16,    41,    18,    19,    20,    21,
      22,    23,    40,    47,    77,    22,    23,    24,     3,     4,
       5,     6,    12,    40,    28,    29,    28,    29,    62,    63,
      42,    43,    40,    40,    68,    40,    70,    71,    72,    73,
      74,    75,    91,    47,    46,    79,     6,     7,    40,    39,
      28,    29,    28,    29,    40,    40,    16,   106,    18,    19,
      20,    21,    22,    23,    28,    29,   115,    28,    29,    47,
      46,    30,    31,    32,   108,     0,   125,    41,    28,    29,
      41,    46,    42,    28,    29,     6,     3,   121,     7,    34,
      35,    36,    37,    38,    39,    10,    11,    12,    13,    14,
      15,     3,    65,    66,    67,    27,    41,    41,    41,    41,
      46,    40,    42,    17,    41,    46,     6,    27,    46,    10,
      46,    41,    46,    34,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    16,    18,    19,    20,    21,    22,    23,
      42,    49,    50,    51,    52,    53,    54,    56,    57,    58,
      59,    60,    64,    67,    27,    10,    11,    12,    13,    14,
      15,    75,    40,    40,    40,    40,    40,    40,    40,    50,
       0,    51,    46,     3,     4,     5,     6,    40,    72,    73,
      74,     6,    71,    72,    65,    53,    72,    72,     3,     3,
      43,    72,    28,    29,    46,    30,    31,    32,    27,    41,
      34,    35,    36,    37,    38,    39,    71,    68,    41,    47,
      41,    41,    41,    72,    72,    73,    73,    73,    24,    57,
      72,    61,    72,    72,    72,    72,    72,    72,    41,    71,
      46,    72,    40,    46,    46,    52,    66,    46,    47,    41,
      62,    52,    69,    72,    46,    17,    63,     6,    55,    41,
      52,    27,    41,    46,    72,    70,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    53,    53,    53,    54,    55,
      56,    57,    57,    58,    59,    61,    62,    60,    63,    63,
      65,    66,    64,    68,    69,    70,    67,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     6,     8,     4,     3,
       2,     4,     4,     5,     9,     0,     0,     8,     0,     2,
       0,     0,     7,     0,     0,     0,    11,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 15: /* var_decl: KW_VAR type ID ASSIGN expression SEMICOLON  */
#line 111 "parser.y"
                                               {
        fprintf(outfile, "VAR %s\n", (yyvsp[-3].sval));
        fprintf(outfile, "ASSIGN %s %s\n", (yyvsp[-1].sval), (yyvsp[-3].sval));
    }
#line 1282 "parser.tab.c"
    break;

  case 16: /* var_decl: KW_VAR type ID ASSIGN input_expr SEMICOLON  */
#line 115 "parser.y"
                                                 { 
        fprintf(outfile, "VAR %s\n", (yyvsp[-3].sval));
        fprintf(outfile, "KEY %s %s\n", (yyvsp[-1].sval), (yyvsp[-3].sval)); 
    }
#line 1291 "parser.tab.c"
    break;

  case 17: /* var_decl: KW_VAR type ID ASSIGN KW_NEW_ARRAY LPAREN RPAREN SEMICOLON  */
#line 119 "parser.y"
                                                                 { 
        fprintf(outfile, "VAR %s\n", (yyvsp[-5].sval));
        fprintf(outfile, "ASSIGN 0 %s\n", (yyvsp[-5].sval));
    }
#line 1300 "parser.tab.c"
    break;

  case 18: /* assignment: ID ASSIGN expression SEMICOLON  */
#line 127 "parser.y"
                                   {
        fprintf(outfile, "ASSIGN %s %s\n", (yyvsp[-1].sval), (yyvsp[-3].sval));
    }
#line 1308 "parser.tab.c"
    break;

  case 19: /* for_update: ID ASSIGN expression  */
#line 133 "parser.y"
                         {
        fprintf(outfile, "ASSIGN %s %s\n", (yyvsp[0].sval), (yyvsp[-2].sval));
    }
#line 1316 "parser.tab.c"
    break;

  case 21: /* input_expr: KW_INPUT LPAREN INT_LIT RPAREN  */
#line 143 "parser.y"
                                    { (yyval.sval) = (yyvsp[-1].sval); }
#line 1322 "parser.tab.c"
    break;

  case 22: /* input_expr: KW_READ LPAREN INT_LIT RPAREN  */
#line 144 "parser.y"
                                   { (yyval.sval) = (yyvsp[-1].sval); }
#line 1328 "parser.tab.c"
    break;

  case 23: /* print_stmt: KW_PRINT LPAREN expression RPAREN SEMICOLON  */
#line 148 "parser.y"
                                                {
        fprintf(outfile, "PRINT %s\n", (yyvsp[-2].sval));
    }
#line 1336 "parser.tab.c"
    break;

  case 24: /* pixel_stmt: KW_DRAW LPAREN expression COMMA expression COMMA expression RPAREN SEMICOLON  */
#line 154 "parser.y"
                                                                                 {
        fprintf(outfile, "PIXEL %s %s %s\n", (yyvsp[-6].sval), (yyvsp[-4].sval), (yyvsp[-2].sval));
    }
#line 1344 "parser.tab.c"
    break;

  case 25: /* $@1: %empty  */
#line 160 "parser.y"
                                  {
        char *L_else = gen_label();
        char *L_end = gen_label();
        push_if(L_else, L_end);
        fprintf(outfile, "IFFALSE %s GOTO %s\n", (yyvsp[-1].sval), L_else);
    }
#line 1355 "parser.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 165 "parser.y"
            {
        fprintf(outfile, "GOTO %s\n", if_stack[i_top].label_end);
        fprintf(outfile, "LABEL %s\n", if_stack[i_top].label_else);
    }
#line 1364 "parser.tab.c"
    break;

  case 28: /* optional_else: %empty  */
#line 172 "parser.y"
                {
        fprintf(outfile, "LABEL %s\n", if_stack[i_top].label_end);
        pop_if();
    }
#line 1373 "parser.tab.c"
    break;

  case 29: /* optional_else: KW_ELSE block  */
#line 176 "parser.y"
                    {
        fprintf(outfile, "LABEL %s\n", if_stack[i_top].label_end);
        pop_if();
    }
#line 1382 "parser.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 183 "parser.y"
                    {
        char *L_start = gen_label();
        fprintf(outfile, "LABEL %s\n", L_start);
        push_loop(L_start, NULL, NULL, NULL); 
    }
#line 1392 "parser.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 187 "parser.y"
                       {
        char *L_end = gen_label();
        loop_stack[l_top].end = L_end;
        fprintf(outfile, "IFFALSE %s GOTO %s\n", (yyvsp[-1].sval), L_end);
    }
#line 1402 "parser.tab.c"
    break;

  case 32: /* while_stmt: KW_WHILE LPAREN $@3 condition RPAREN $@4 block  */
#line 191 "parser.y"
            {
        fprintf(outfile, "GOTO %s\n", loop_stack[l_top].start);
        fprintf(outfile, "LABEL %s\n", loop_stack[l_top].end);
        pop_loop();
    }
#line 1412 "parser.tab.c"
    break;

  case 33: /* $@5: %empty  */
#line 199 "parser.y"
                           {
        char *L_start = gen_label();
        fprintf(outfile, "LABEL %s\n", L_start);
        push_loop(L_start, NULL, NULL, NULL);
    }
#line 1422 "parser.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 203 "parser.y"
                          {
        char *L_end = gen_label();
        char *L_body = gen_label();
        char *L_inc = gen_label();
        
        loop_stack[l_top].end = L_end;
        loop_stack[l_top].body = L_body;
        loop_stack[l_top].inc = L_inc;

        fprintf(outfile, "IFFALSE %s GOTO %s\n", (yyvsp[-1].sval), L_end);
        fprintf(outfile, "GOTO %s\n", L_body);
        fprintf(outfile, "LABEL %s\n", L_inc);
    }
#line 1440 "parser.tab.c"
    break;

  case 35: /* $@7: %empty  */
#line 215 "parser.y"
                        { 
        fprintf(outfile, "GOTO %s\n", loop_stack[l_top].start);
        fprintf(outfile, "LABEL %s\n", loop_stack[l_top].body);
    }
#line 1449 "parser.tab.c"
    break;

  case 36: /* for_stmt: KW_FOR LPAREN var_decl $@5 condition SEMICOLON $@6 for_update RPAREN $@7 block  */
#line 218 "parser.y"
            {
        fprintf(outfile, "GOTO %s\n", loop_stack[l_top].inc);
        fprintf(outfile, "LABEL %s\n", loop_stack[l_top].end);
        pop_loop();
    }
#line 1459 "parser.tab.c"
    break;

  case 37: /* condition: expression EQ expression  */
#line 226 "parser.y"
                               { (yyval.sval)=gen_temp(); fprintf(outfile, "EQ %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1465 "parser.tab.c"
    break;

  case 38: /* condition: expression NEQ expression  */
#line 227 "parser.y"
                                { (yyval.sval)=gen_temp(); fprintf(outfile, "NEQ %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1471 "parser.tab.c"
    break;

  case 39: /* condition: expression LT expression  */
#line 228 "parser.y"
                               { (yyval.sval)=gen_temp(); fprintf(outfile, "LT %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1477 "parser.tab.c"
    break;

  case 40: /* condition: expression GT expression  */
#line 229 "parser.y"
                               { (yyval.sval)=gen_temp(); fprintf(outfile, "GT %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1483 "parser.tab.c"
    break;

  case 41: /* condition: expression LTE expression  */
#line 230 "parser.y"
                                { (yyval.sval)=gen_temp(); fprintf(outfile, "LTE %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1489 "parser.tab.c"
    break;

  case 42: /* condition: expression GTE expression  */
#line 231 "parser.y"
                                { (yyval.sval)=gen_temp(); fprintf(outfile, "GTE %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1495 "parser.tab.c"
    break;

  case 43: /* expression: expression PLUS expression  */
#line 235 "parser.y"
                               { (yyval.sval)=gen_temp(); fprintf(outfile, "ADD %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1501 "parser.tab.c"
    break;

  case 44: /* expression: expression MINUS expression  */
#line 236 "parser.y"
                                  { (yyval.sval)=gen_temp(); fprintf(outfile, "SUB %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1507 "parser.tab.c"
    break;

  case 46: /* term: term MULT term  */
#line 241 "parser.y"
                   { (yyval.sval)=gen_temp(); fprintf(outfile, "MUL %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1513 "parser.tab.c"
    break;

  case 47: /* term: term DIV term  */
#line 242 "parser.y"
                    { (yyval.sval)=gen_temp(); fprintf(outfile, "DIV %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1519 "parser.tab.c"
    break;

  case 48: /* term: term MOD term  */
#line 243 "parser.y"
                    { (yyval.sval)=gen_temp(); fprintf(outfile, "MOD %s %s %s\n", (yyvsp[-2].sval), (yyvsp[0].sval), (yyval.sval)); }
#line 1525 "parser.tab.c"
    break;

  case 50: /* factor: LPAREN expression RPAREN  */
#line 248 "parser.y"
                             { (yyval.sval) = (yyvsp[-1].sval); }
#line 1531 "parser.tab.c"
    break;

  case 51: /* factor: ID  */
#line 249 "parser.y"
         { (yyval.sval) = (yyvsp[0].sval); }
#line 1537 "parser.tab.c"
    break;

  case 52: /* factor: INT_LIT  */
#line 250 "parser.y"
              { (yyval.sval) = (yyvsp[0].sval); }
#line 1543 "parser.tab.c"
    break;

  case 53: /* factor: FLOAT_LIT  */
#line 251 "parser.y"
                { (yyval.sval) = (yyvsp[0].sval); }
#line 1549 "parser.tab.c"
    break;

  case 54: /* factor: STRING_LIT  */
#line 252 "parser.y"
                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1555 "parser.tab.c"
    break;

  case 55: /* type: TYPE_INT  */
#line 256 "parser.y"
               { (yyval.sval) = "int"; }
#line 1561 "parser.tab.c"
    break;

  case 56: /* type: TYPE_FLOAT  */
#line 257 "parser.y"
                 { (yyval.sval) = "float"; }
#line 1567 "parser.tab.c"
    break;

  case 57: /* type: TYPE_STRING  */
#line 258 "parser.y"
                  { (yyval.sval) = "string"; }
#line 1573 "parser.tab.c"
    break;

  case 58: /* type: TYPE_BOOL  */
#line 259 "parser.y"
                { (yyval.sval) = "bool"; }
#line 1579 "parser.tab.c"
    break;

  case 59: /* type: TYPE_VOID  */
#line 260 "parser.y"
                { (yyval.sval) = "void"; }
#line 1585 "parser.tab.c"
    break;

  case 60: /* type: TYPE_ARRAY  */
#line 261 "parser.y"
                 { (yyval.sval) = "array"; }
#line 1591 "parser.tab.c"
    break;


#line 1595 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 264 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en linea %d: %s\n", yylineno, s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso: %s <archivo.src>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) return 1;
    outfile = fopen("output.fis", "w");
    fprintf(outfile, "// Codigo FIS-25 generado\n");
    yyparse();
    
    printf("Compilacion exitosa! Revisa output.fis\n");
    fclose(yyin);
    fclose(outfile);
    return 0;
}
