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
#line 9 "spin.y"

#include "spin.h"
#include <sys/types.h>
#ifndef PC
#include <unistd.h>
#endif
#include <stdarg.h>

#define YYMAXDEPTH	20000	/* default is 10000 */
#define YYDEBUG		0
#define Stop	nn(ZN,'@',ZN,ZN)
#define PART0	"place initialized declaration of "
#define PART1	"place initialized chan decl of "
#define PART2	" at start of proctype "

static	Lextok *ltl_to_string(Lextok *);

extern  Symbol	*context, *owner;
extern	Lextok *for_body(Lextok *, int);
extern	void for_setup(Lextok *, Lextok *, Lextok *);
extern	Lextok *for_index(Lextok *, Lextok *);
extern	Lextok *sel_index(Lextok *, Lextok *, Lextok *);
extern  void    keep_track_off(Lextok *);
extern	void	safe_break(void);
extern	void	restore_break(void);
extern  int	u_sync, u_async, dumptab, scope_level;
extern	int	initialization_ok;
extern	short	has_sorted, has_random, has_enabled, has_pcvalue, has_np, has_priority;
extern	short	has_code, has_state, has_ltl, has_io;
extern	void	check_mtypes(Lextok *, Lextok *);
extern	void	count_runs(Lextok *);
extern	void	no_internals(Lextok *);
extern	void	any_runs(Lextok *);
extern	void	explain(int);
extern	void	ltl_list(char *, char *);
extern	void	validref(Lextok *, Lextok *);
extern  void	sanity_check(Lextok *);
extern	char	yytext[];

int	Mpars = 0;	/* max nr of message parameters  */
int	nclaims = 0;	/* nr of never claims */
int	ltl_mode = 0;	/* set when parsing an ltl formula */
int	Expand_Ok = 0, realread = 1, IArgs = 0, NamesNotAdded = 0;
int	in_for = 0, in_seq = 0, par_cnt = 0;
int	dont_simplify = 0;
char	*claimproc = (char *) 0;
char	*eventmap = (char *) 0;

static	char *ltl_name;
static	int  Embedded = 0, inEventMap = 0, has_ini = 0;


#line 123 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ASSERT = 258,
    PRINT = 259,
    PRINTM = 260,
    PREPROC = 261,
    C_CODE = 262,
    C_DECL = 263,
    C_EXPR = 264,
    C_STATE = 265,
    C_TRACK = 266,
    RUN = 267,
    LEN = 268,
    ENABLED = 269,
    SET_P = 270,
    GET_P = 271,
    EVAL = 272,
    PC_VAL = 273,
    TYPEDEF = 274,
    MTYPE = 275,
    INLINE = 276,
    RETURN = 277,
    LABEL = 278,
    OF = 279,
    GOTO = 280,
    BREAK = 281,
    ELSE = 282,
    SEMI = 283,
    ARROW = 284,
    IF = 285,
    FI = 286,
    DO = 287,
    OD = 288,
    FOR = 289,
    SELECT = 290,
    IN = 291,
    SEP = 292,
    DOTDOT = 293,
    ATOMIC = 294,
    NON_ATOMIC = 295,
    D_STEP = 296,
    UNLESS = 297,
    TIMEOUT = 298,
    NONPROGRESS = 299,
    ACTIVE = 300,
    PROCTYPE = 301,
    D_PROCTYPE = 302,
    HIDDEN = 303,
    SHOW = 304,
    ISLOCAL = 305,
    PRIORITY = 306,
    PROVIDED = 307,
    FULL = 308,
    EMPTY = 309,
    NFULL = 310,
    NEMPTY = 311,
    CONST = 312,
    TYPE = 313,
    XU = 314,
    NAME = 315,
    UNAME = 316,
    PNAME = 317,
    INAME = 318,
    STRING = 319,
    CLAIM = 320,
    TRACE = 321,
    INIT = 322,
    LTL = 323,
    UNION = 324,
    ASGN = 325,
    SND = 326,
    O_SND = 327,
    RCV = 328,
    R_RCV = 329,
    IMPLIES = 330,
    EQUIV = 331,
    OR = 332,
    AND = 333,
    ALWAYS = 334,
    EVENTUALLY = 335,
    UNTIL = 336,
    WEAK_UNTIL = 337,
    RELEASE = 338,
    NEXT = 339,
    EQ = 340,
    NE = 341,
    GT = 342,
    LT = 343,
    GE = 344,
    LE = 345,
    LSHIFT = 346,
    RSHIFT = 347,
    INCR = 348,
    DECR = 349,
    UMIN = 350,
    NEG = 351,
    DOT = 352
  };
#endif
/* Tokens.  */
#define ASSERT 258
#define PRINT 259
#define PRINTM 260
#define PREPROC 261
#define C_CODE 262
#define C_DECL 263
#define C_EXPR 264
#define C_STATE 265
#define C_TRACK 266
#define RUN 267
#define LEN 268
#define ENABLED 269
#define SET_P 270
#define GET_P 271
#define EVAL 272
#define PC_VAL 273
#define TYPEDEF 274
#define MTYPE 275
#define INLINE 276
#define RETURN 277
#define LABEL 278
#define OF 279
#define GOTO 280
#define BREAK 281
#define ELSE 282
#define SEMI 283
#define ARROW 284
#define IF 285
#define FI 286
#define DO 287
#define OD 288
#define FOR 289
#define SELECT 290
#define IN 291
#define SEP 292
#define DOTDOT 293
#define ATOMIC 294
#define NON_ATOMIC 295
#define D_STEP 296
#define UNLESS 297
#define TIMEOUT 298
#define NONPROGRESS 299
#define ACTIVE 300
#define PROCTYPE 301
#define D_PROCTYPE 302
#define HIDDEN 303
#define SHOW 304
#define ISLOCAL 305
#define PRIORITY 306
#define PROVIDED 307
#define FULL 308
#define EMPTY 309
#define NFULL 310
#define NEMPTY 311
#define CONST 312
#define TYPE 313
#define XU 314
#define NAME 315
#define UNAME 316
#define PNAME 317
#define INAME 318
#define STRING 319
#define CLAIM 320
#define TRACE 321
#define INIT 322
#define LTL 323
#define UNION 324
#define ASGN 325
#define SND 326
#define O_SND 327
#define RCV 328
#define R_RCV 329
#define IMPLIES 330
#define EQUIV 331
#define OR 332
#define AND 333
#define ALWAYS 334
#define EVENTUALLY 335
#define UNTIL 336
#define WEAK_UNTIL 337
#define RELEASE 338
#define NEXT 339
#define EQ 340
#define NE 341
#define GT 342
#define LT 343
#define GE 344
#define LE 345
#define LSHIFT 346
#define RSHIFT 347
#define INCR 348
#define DECR 349
#define UMIN 350
#define NEG 351
#define DOT 352

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2016

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  539

#define YYUNDEFTOK  2
#define YYMAXUTOK   352


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
       2,     2,     2,     2,     2,     2,     2,   100,    87,     2,
     107,   108,    98,    96,   114,    97,   115,    99,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   113,     2,
       2,     2,     2,     2,   116,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   109,     2,   110,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,    85,   112,   103,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      88,    89,    90,    91,    92,    93,    94,    95,   101,   102,
     104,   105,   106
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   105,   106,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   122,   125,   130,   138,
     129,   166,   167,   170,   171,   172,   177,   191,   191,   201,
     201,   207,   208,   211,   211,   226,   232,   235,   241,   244,
     244,   263,   263,   276,   276,   290,   291,   297,   297,   303,
     307,   310,   314,   318,   322,   328,   338,   350,   368,   369,
     368,   378,   379,   382,   383,   384,   385,   386,   387,   387,
     391,   394,   395,   396,   397,   400,   401,   402,   405,   406,
     409,   413,   416,   428,   429,   433,   434,   437,   438,   441,
     442,   445,   446,   449,   462,   475,   496,   504,   519,   520,
     528,   529,   547,   550,   556,   556,   560,   560,   581,   582,
     585,   586,   591,   591,   598,   599,   601,   601,   606,   606,
     612,   612,   617,   617,   621,   625,   631,   631,   638,   641,
     649,   657,   667,   672,   677,   685,   693,   694,   694,   696,
     697,   698,   699,   700,   700,   706,   706,   712,   712,   718,
     718,   725,   726,   728,   728,   735,   735,   745,   745,   751,
     752,   751,   758,   759,   758,   764,   767,   768,   771,   771,
     779,   780,   783,   784,   787,   788,   791,   792,   795,   796,
     797,   798,   799,   800,   801,   807,   815,   816,   817,   818,
     819,   820,   821,   822,   823,   824,   825,   826,   827,   828,
     829,   830,   831,   832,   833,   834,   835,   836,   838,   843,
     843,   853,   854,   855,   856,   856,   860,   860,   865,   866,
     867,   872,   873,   876,   879,   881,   883,   884,   885,   888,
     889,   892,   893,   896,   897,   898,   901,   904,   905,   906,
     907,   911,   912,   913,   914,   915,   916,   917,   918,   921,
     922,   923,   924,   927,   928,   935,   940,   941,   944,   954,
     957,   960,   961,   964,   967,   968,   971,   972,   975,   976,
     983,   988,   995,   997,   999,  1004,  1009,  1014,  1019,  1024,
    1027,  1029,  1032
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSERT", "PRINT", "PRINTM", "PREPROC",
  "C_CODE", "C_DECL", "C_EXPR", "C_STATE", "C_TRACK", "RUN", "LEN",
  "ENABLED", "SET_P", "GET_P", "EVAL", "PC_VAL", "TYPEDEF", "MTYPE",
  "INLINE", "RETURN", "LABEL", "OF", "GOTO", "BREAK", "ELSE", "SEMI",
  "ARROW", "IF", "FI", "DO", "OD", "FOR", "SELECT", "IN", "SEP", "DOTDOT",
  "ATOMIC", "NON_ATOMIC", "D_STEP", "UNLESS", "TIMEOUT", "NONPROGRESS",
  "ACTIVE", "PROCTYPE", "D_PROCTYPE", "HIDDEN", "SHOW", "ISLOCAL",
  "PRIORITY", "PROVIDED", "FULL", "EMPTY", "NFULL", "NEMPTY", "CONST",
  "TYPE", "XU", "NAME", "UNAME", "PNAME", "INAME", "STRING", "CLAIM",
  "TRACE", "INIT", "LTL", "UNION", "ASGN", "SND", "O_SND", "RCV", "R_RCV",
  "IMPLIES", "EQUIV", "OR", "AND", "ALWAYS", "EVENTUALLY", "UNTIL",
  "WEAK_UNTIL", "RELEASE", "NEXT", "'|'", "'^'", "'&'", "EQ", "NE", "GT",
  "LT", "GE", "LE", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'",
  "INCR", "DECR", "'~'", "UMIN", "NEG", "DOT", "'('", "')'", "'['", "']'",
  "'{'", "'}'", "':'", "','", "'.'", "'@'", "$accept", "program", "units",
  "unit", "l_par", "r_par", "proc", "$@1", "$@2", "proctype", "inst",
  "init", "$@3", "ltl", "$@4", "ltl_body", "claim", "$@5", "optname",
  "optname2", "events", "$@6", "utype", "$@7", "$@8", "nm", "ns", "$@9",
  "c_fcts", "cstate", "ccode", "cexpr", "body", "$@10", "$@11", "sequence",
  "step", "$@12", "vis", "asgn", "osubt", "one_decl", "decl_lst", "decl",
  "vref_lst", "var_list", "c_list", "ivar", "ch_init", "vardcl", "varref",
  "pfld", "$@13", "cmpnd", "$@14", "sfld", "stmnt", "for_pre", "$@15",
  "for_post", "Special", "$@16", "$@17", "$@18", "@19", "$@20", "Stmnt",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29",
  "$@30", "$@31", "$@32", "options", "option", "$@33", "OS", "semi", "MS",
  "aname", "const_expr", "expr", "$@34", "$@35", "$@36", "Opt_priority",
  "full_expr", "ltl_expr", "Expr", "Probe", "Opt_enabler", "oname",
  "basetype", "typ_list", "two_args", "args", "prargs", "margs", "arg",
  "rarg", "rargs", "nlst", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   124,    94,    38,   340,   341,
     342,   343,   344,   345,   346,   347,    43,    45,    42,    47,
      37,   348,   349,   126,   350,   351,   352,    40,    41,    91,
      93,   123,   125,    58,    44,    46,    64
};
# endif

#define YYPACT_NINF (-439)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-217)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1470,  -439,  -439,  -439,   -43,   -38,    43,    80,  -439,  -439,
     -68,  -439,  -439,  -439,    24,  -439,  -439,    38,    64,   153,
    -439,  -439,   137,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,   133,  -439,  -439,    41,    78,     8,    87,  -439,
    -439,    49,   -25,  -439,  -439,    47,   120,  -439,  -439,  -439,
    -439,  -439,  -439,   157,   -23,   162,   183,   205,  -439,   113,
    -439,  -439,  -439,   139,    23,    23,   154,    47,  -439,  -439,
     199,    47,     4,  -439,  -439,   217,   182,   162,    76,  -439,
     181,   226,  -439,  -439,   190,  -439,  1390,  -439,  -439,   192,
      23,    23,    23,    23,    23,  -439,  -439,  1072,  -439,  -439,
    -439,   495,  -439,    49,   228,   239,  -439,   -24,   244,   162,
    1284,   288,   194,   190,  -439,    66,    49,    49,    49,    49,
    -439,  -439,  -439,   225,    46,  1390,  1390,  1390,  1390,  1390,
    1390,  1390,  -439,   134,  -439,  -439,   232,  -439,   230,  -439,
    -439,  -439,   160,   160,  -439,  -439,  -439,   294,   495,    49,
      49,    49,   495,   284,  -439,  -439,   308,  -439,    49,    49,
     238,   245,    49,    49,    49,    49,   290,    77,  -439,  -439,
     495,  -439,   206,  -439,  -439,   201,   316,   -18,  -439,  -439,
    1690,  -439,   185,  -439,   206,   -20,  -439,  -439,   -33,   250,
     187,  -439,  -439,    23,   306,  -439,  1716,   190,  -439,   253,
    -439,  -439,  -439,   290,  1390,  1390,  1390,   257,  1390,   290,
     307,  -439,  -439,  -439,  -439,  -439,  -439,   576,  -439,  -439,
     254,  1390,  1390,  1390,  1390,  1390,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1390,  1390,  1390,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1390,  1390,  -439,  -439,   304,   136,  1390,
    -439,  -439,  -439,   339,   308,   308,  -439,   290,  -439,  -439,
     290,   290,   290,   290,  -439,   258,   696,    49,  1072,   735,
     -39,  -439,    34,   971,  1357,  -439,  -439,    40,    48,  -439,
    -439,  -439,   290,  1390,   495,   495,   495,   495,   269,  -439,
    -439,   230,  -439,  -439,  -439,  -439,  -439,   278,   268,   271,
    -439,  -439,    49,   230,  1662,  1662,  1662,  1390,  1610,  -439,
    -439,  1390,  -439,   277,   281,   290,  -439,  1792,  1792,  1815,
    1858,  1874,  1874,  1874,  1889,  1903,  1916,   691,   691,   310,
     310,   310,   310,    69,    69,   242,   242,  -439,  -439,  -439,
    -439,  -439,   230,   230,  1551,   230,  1072,  -439,  -439,   354,
     290,   280,  1072,  1072,   230,   230,   230,   230,   290,  -439,
    -439,    97,  -439,  -439,  1390,   206,  -439,   283,  -439,  -439,
    -439,  -439,  1390,  1390,    44,   309,    44,   311,  1173,   230,
    1464,  1838,   321,  1858,  -439,  1742,   321,  1768,  -439,  -439,
    -439,   377,   306,  -439,  1390,  -439,  -439,  -439,  -439,  1636,
      99,  1581,    44,    44,  -439,   297,  -439,  -439,  1390,  -439,
     206,  -439,  -439,  1390,   206,   206,  -439,  -439,  -439,  -439,
    -439,   870,   230,   303,  -439,    49,  1517,  -439,  -439,  -439,
      49,  -439,   359,    44,  -439,    -8,  -439,    44,  -439,    44,
    -439,  -439,  1390,   120,   312,  -439,   230,  -439,   290,   358,
    1390,   314,   318,  1390,   230,  1716,  -439,  1491,   317,   319,
    -439,  -439,  1390,  1390,  1390,  -439,   230,    44,    44,   329,
     330,    -9,  1662,   369,    33,   120,  -439,  -439,  1662,  -439,
    -439,  -439,  -439,  1390,  -439,  -439,  1251,   230,   230,  1662,
    -439,  -439,   230,  -439,  -439,   323,  1072,  -439,  -439,     9,
      47,  -439,   325,  -439,   322,   320,  -439,  -439,  1662,   103,
    -439,  -439,  -439,  -439,  -439,  1072,   206,    -9,  -439,   495,
    -439,   362,  -439,    33,  -439,  -439,   331,  1251,   206,   327,
    -439,   230,  -439,  -439,  -439,   334,  -439,  -439,  -439
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    15,    55,    56,     0,     0,     0,     0,   172,   173,
      24,    72,    73,    74,    35,    39,    27,    37,     0,     0,
       3,     5,     0,     6,     8,     7,     9,    11,    13,    12,
      50,    49,     0,    10,    14,     0,     0,     0,     0,    45,
      46,     0,     0,    36,    33,     0,   229,    38,    29,     1,
       4,    21,    22,     0,    75,     0,    51,    52,    43,     0,
      16,    47,   178,     0,     0,     0,     0,     0,    58,    40,
       0,     0,     0,    18,    77,     0,     0,     0,    98,    81,
      89,    93,    53,    54,    71,    41,   264,    26,   179,     0,
       0,     0,     0,     0,     0,    25,    34,     0,   230,    28,
      32,     0,    30,     0,    79,     0,    80,     0,     0,     0,
       0,    83,     0,    71,    57,     0,     0,     0,     0,     0,
     221,   222,   220,   103,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   218,   106,   102,   270,   228,     0,   265,
      17,   180,   181,   182,   183,   184,   185,    70,     0,     0,
       0,     0,     0,     0,   128,   152,     0,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   159,   157,
       0,   142,   170,    61,    63,   218,    67,     0,   110,   111,
     231,   151,   232,   241,   170,    71,    76,   280,     0,     0,
       0,    99,    90,     0,     0,    96,    95,    71,    44,     0,
     176,   177,   209,     0,     0,     0,     0,     0,     0,     0,
       0,   207,   239,   240,   238,   206,   205,     0,   214,   216,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,   141,     0,     0,     0,
     165,   129,   168,     0,   166,     0,   112,     0,   153,   155,
       0,     0,     0,     0,    64,    87,     0,     0,     0,     0,
       0,    59,   174,     0,     0,   118,   149,   116,   143,   134,
     135,    68,     0,     0,     0,     0,     0,     0,     0,   171,
      86,     0,   281,    82,   282,   101,   100,     0,    91,     0,
      84,    42,     0,     0,     0,     0,     0,     0,     0,   227,
     226,     0,   186,     0,     0,     0,   107,   236,   237,   202,
     201,   233,   235,   234,   194,   193,   192,   199,   200,   195,
     196,   197,   198,   203,   204,   187,   188,   189,   190,   191,
     271,   137,     0,     0,     0,     0,     0,   125,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
      66,   103,    65,   130,   264,   170,   242,     0,    62,   175,
     162,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   248,   201,   245,   247,   246,   244,   243,    31,
      19,     0,     0,    94,   264,   211,   212,   213,   223,     0,
       0,     0,     0,     0,   109,   266,   140,   139,     0,   136,
     170,   127,   113,     0,   170,   170,   249,   251,   250,   252,
      88,     0,     0,     0,    60,     0,   270,   119,   268,   150,
       0,   274,     0,     0,   272,   276,   117,     0,   144,     0,
      69,   122,     0,   229,     0,    92,     0,   105,     0,     0,
       0,     0,     0,     0,     0,   263,   169,     0,     0,     0,
     160,   158,   264,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,   253,     0,   229,   225,   224,     0,   215,
     217,   267,   138,     0,   154,   156,     0,     0,     0,     0,
     279,   277,     0,   146,   148,     0,     0,   123,   120,     0,
       0,   260,   256,   259,   261,     0,   210,   208,     0,   218,
     161,   163,   269,   273,   278,     0,   170,     0,   255,     0,
      20,     0,   258,     0,    97,   124,   145,     0,   170,     0,
     121,     0,   257,   262,   164,     0,   114,   254,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -439,  -439,  -439,   411,   -41,   -75,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
      55,  -439,   -65,  -439,  -439,  -260,   169,  -439,  -439,  -439,
    -439,    12,  -100,  -439,    89,   -52,    56,  -439,  -439,  -439,
      91,  -200,  -439,   135,  -439,  -439,  -251,  -439,  -439,   -66,
    -439,  -439,  -439,  -439,  -439,  -439,  -438,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,    11,
    -439,  -439,  -173,     3,  -439,  -439,   -48,   406,  -439,  -439,
    -439,  -375,   -94,  -439,  -150,  -439,  -439,  -439,  -439,   -71,
    -439,  -324,  -439,    81,  -240,  -439,  -289,  -439
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,   131,   312,    21,   103,   443,    53,
      22,    23,    46,    24,    72,   102,    25,    67,    44,    48,
      26,    45,    27,   113,    84,    41,    28,    86,    29,    30,
     171,   132,    69,    97,   367,   172,   173,   378,    32,    76,
      77,   174,   112,   291,   264,    79,   299,    80,   195,    81,
     133,   134,   207,   135,   220,   316,   176,   177,   350,   497,
     178,   374,   372,   517,   471,   255,   179,   405,   376,   375,
     377,   373,   352,   353,   268,   267,   486,   425,   527,   253,
     254,   346,   271,   272,   273,   202,    66,   180,   302,   313,
     314,    71,   181,   137,   182,   183,   500,   522,   504,   505,
     345,   138,   454,   427,   139,   435,   436,   188
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    65,    96,    34,   340,   100,    99,   184,   365,   309,
     518,   288,    33,   199,   141,   363,    88,    89,   282,   495,
     270,    35,    34,    65,    65,   106,    36,   292,    11,    12,
      13,    33,    62,    62,   501,    63,   189,   -78,   286,   287,
     422,    42,   142,   143,   144,   145,   146,    74,   510,    65,
      65,    65,    65,    65,   246,    31,   170,   192,   250,   190,
     170,   430,   185,   245,    49,  -171,    65,  -171,   473,   140,
     446,  -171,    64,    64,    31,   203,   204,   205,   206,   293,
      62,   294,    60,    60,    43,   290,   410,   438,   -85,   534,
      75,   502,   414,   415,   503,   283,   111,   300,    47,    60,
     506,   431,   496,    37,   123,    56,   467,   170,   247,   248,
     249,   170,    38,   451,   452,   101,    60,   256,   257,    58,
      64,   260,   261,   262,   263,   111,   200,   440,   201,   170,
      60,  -145,   428,   428,   382,   384,   386,   388,   487,  -147,
      39,   432,    57,    40,   466,   297,  -171,    59,   469,  -214,
     470,    60,    65,    -2,     1,   208,    60,  -216,    68,   209,
       2,     3,   210,     4,     5,   239,   240,   241,   242,   243,
     363,    70,     6,   274,     7,   276,   526,   278,   491,   492,
     371,     8,     9,    51,    52,   107,  -104,   289,   175,   108,
     266,    54,   423,   342,    55,   366,   123,   111,    10,   -23,
     -23,    11,    12,    13,   279,   280,  -104,   218,   219,   111,
     421,   -71,   448,   481,   -71,   449,   390,    73,    14,    15,
      16,    17,    78,   488,    85,   170,   364,   170,   395,   396,
     397,   398,   170,   170,     8,     9,   516,   456,    11,    12,
      13,   458,   459,   170,   170,   170,   170,    82,   476,    87,
      90,    91,    92,    93,    94,   528,    98,   265,    92,    93,
      94,   394,   286,   287,    95,   348,   349,   406,   407,    83,
     409,   274,   275,   276,   277,   278,   369,   104,   362,   416,
     417,   418,   419,    90,    91,    92,    93,    94,    90,    91,
      92,    93,    94,   105,   303,   109,   110,   296,   186,   187,
     140,   191,   279,   280,   441,   170,   198,   221,   222,   223,
     224,   170,   170,   225,   226,   227,   197,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   433,  -104,   433,  -132,   170,   140,   343,
     241,   242,   243,   529,   251,   252,   244,   460,   351,   258,
     123,   354,   355,   356,   357,   535,   259,   175,   281,   175,
     295,   433,   433,   298,   175,   301,   307,   310,   341,   315,
     347,   475,   358,   379,    90,    91,    92,    93,    94,   482,
     170,   389,   392,   393,   462,   463,   402,   411,   391,   464,
     403,   490,   433,   413,   468,   424,   433,   498,   433,   287,
     437,   444,   439,   507,   237,   238,   239,   240,   241,   242,
     243,   453,   511,   512,   513,   461,   465,   514,   477,   493,
     494,   499,   532,   474,   479,   531,   433,   433,   480,   484,
      50,   485,   524,   525,   515,   520,   523,   175,   521,   536,
    -214,   412,   368,   175,   175,   170,   538,   420,   445,   265,
     404,   530,   533,     0,   429,   170,   537,     0,   519,     0,
       0,     0,     0,     0,     0,   434,     0,   434,     0,   175,
       0,     0,     0,     0,   170,     0,     0,     0,   170,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,   136,   434,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,   115,   116,   117,
       0,   118,   175,   119,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,   434,     0,     0,     0,   434,     0,
     434,   211,   212,   213,   214,   215,   216,   217,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   122,     0,     0,   123,     0,   124,   434,   434,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   269,   509,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,   130,     0,
       0,     0,    60,     0,     0,   311,   175,     0,     0,     0,
     304,   305,   306,     0,   308,     0,     0,     0,   509,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     136,   221,   222,   223,   224,   344,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   380,
     381,   383,   385,   387,     0,     0,     0,   359,     0,   148,
     149,   150,     0,     2,     3,   114,     0,     0,   115,   116,
     117,   151,   118,   399,   119,     0,     0,   401,   152,     0,
       0,   153,   154,   155,  -131,  -131,   156,  -131,   157,  -131,
     158,   159,     0,  -131,     0,   160,     0,   161,  -131,   120,
     121,     0,     0,     0,    11,    12,    13,     0,     0,   162,
     163,   164,   165,   122,   -71,   360,   361,   -71,   124,   168,
       0,     0,     0,     0,   311,     0,     0,   125,     0,     0,
     136,     0,     0,     0,     0,   126,   127,     0,   426,   426,
     128,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   129,     0,     0,     0,     0,     0,   130,
     136,     0,     0,    60,     0,     0,     0,   169,  -131,     0,
     221,   222,   284,   285,   455,     0,   225,   226,   227,   457,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,   478,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   136,
     489,   359,     0,   148,   149,   150,     0,     2,     3,   114,
       0,     0,   115,   116,   117,   151,   118,     0,   119,   508,
       0,     0,   152,     0,     0,   153,   154,   155,  -131,  -131,
     156,  -131,   157,  -131,   158,   159,     0,  -131,     0,   160,
       0,   161,  -131,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   122,     0,     0,
     361,     0,   124,   168,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     0,   147,   130,   148,   149,   150,    60,     2,     3,
     114,   169,  -131,   115,   116,   117,   151,   118,     0,   119,
       0,     0,     0,   152,     0,     0,   153,   154,   155,     8,
       9,   156,     0,   157,     0,   158,   159,     0,     0,     0,
     160,     0,   161,     0,   120,   121,     0,     0,     0,    11,
      12,    13,     0,     0,   162,   163,   164,   165,   122,   -71,
     166,   167,   -71,   124,   168,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
     126,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,     0,     0,   147,   130,   148,   149,   150,    60,     2,
       3,   114,   169,     0,   115,   116,   117,   151,   118,     0,
     119,     0,     0,     0,   152,     0,     0,   153,   154,   155,
       0,     0,   156,     0,   157,     0,   158,   159,     0,     0,
       0,   160,     0,   161,     0,   120,   121,     0,     0,     0,
      11,    12,    13,     0,     0,   162,   163,   164,   165,   122,
     -71,   166,   167,   -71,   124,   168,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,   359,   130,   148,   149,   150,    60,
       2,     3,   114,   169,     0,   115,   116,   117,   151,   118,
       0,   119,     0,     0,     0,   152,     0,     0,   153,   154,
     155,     0,     0,   156,     0,   157,     0,   158,   159,     0,
       0,     0,   160,     0,   161,     0,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     122,     0,     0,   361,     0,   124,   168,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,   126,   127,   148,   149,   150,   128,     2,     3,
     114,     0,     0,   115,   116,   117,   151,   118,     0,   119,
     129,     0,     0,   152,     0,     0,   130,     0,   155,     0,
      60,     0,     0,     0,   169,     0,     0,     0,     0,     0,
     160,     0,   161,   114,   120,   121,   115,   116,   117,     0,
     118,     0,   119,     0,   162,   163,   164,   165,   122,     0,
       0,   123,     0,   124,   168,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,   120,   121,     0,
     126,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,   122,     0,     0,   123,     0,   124,     0,   129,     0,
       0,     0,     0,     0,   130,   125,     0,     0,    60,     0,
       0,     0,   169,   126,   127,     0,   114,     0,   128,   115,
     116,   117,     0,   118,     0,   119,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   130,     0,     0,
       0,    60,     0,   193,     0,   194,     0,     0,     0,   114,
     120,   121,   115,   116,   117,     0,   118,     0,   119,     0,
     162,   163,   164,   165,   122,     0,     0,   123,     0,   124,
     370,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,     0,   120,   121,     0,   126,   127,     0,     0,
       0,   128,     0,     0,     0,     0,     0,   122,     0,     0,
     123,     0,   124,     0,   129,     0,     0,     0,     0,     0,
     130,   125,     0,     0,    60,     0,     0,     0,     0,   126,
     127,     1,     0,     0,   128,     0,     0,     2,     3,     0,
       4,     5,     0,     0,     0,     0,     0,   129,     0,     6,
       0,     7,     0,   130,     0,     0,     0,    60,     8,     9,
       0,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,   -23,   -23,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,   -71,   483,
       0,   -71,     0,     0,     0,    14,    15,    16,    17,   221,
     222,   223,   224,     0,     0,   225,   226,   227,     0,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   221,   222,   223,   224,
       0,     0,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   221,   222,   223,   224,     0,     0,   225,   226,
     227,     0,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,    60,     0,   221,   222,   223,   224,
       0,   244,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,   221,   222,   223,   224,
       0,     0,   225,   226,   227,   408,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,   221,   222,   223,   224,     0,
       0,   225,   226,   227,   450,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   221,   222,   223,   224,     0,     0,   225,   226,   227,
     400,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   221,   222,   223,
     224,     0,     0,   225,   226,   227,   447,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,   221,   222,   284,   285,     0,
     140,   225,   226,   227,     0,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   221,   222,   223,   224,     0,     0,   225,   226,   227,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   221,   222,     0,
     285,     0,     0,   225,   226,   227,     0,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   221,   222,     0,     0,     0,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   223,
     224,     0,     0,   225,   226,   227,     0,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   224,     0,     0,   225,   226,   227,     0,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   285,     0,     0,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243
};

static const yytype_int16 yycheck[] =
{
      41,    42,    67,     0,   244,     1,    71,   101,   268,   209,
       1,   184,     0,   113,    89,   266,    64,    65,    36,    28,
     170,    64,    19,    64,    65,    77,    64,    60,    48,    49,
      50,    19,    57,    57,     1,    60,    60,    60,    77,    78,
     364,   109,    90,    91,    92,    93,    94,    70,   486,    90,
      91,    92,    93,    94,   148,     0,    97,   109,   152,   107,
     101,    17,   103,   138,     0,    31,   107,    33,   443,   108,
     394,    37,    97,    97,    19,   116,   117,   118,   119,   112,
      57,   114,   107,   107,    60,   185,   346,   376,   108,   527,
     113,    58,   352,   353,    61,   113,    84,   197,    60,   107,
     475,    57,   111,    60,    60,    64,   114,   148,   149,   150,
     151,   152,    69,   402,   403,   111,   107,   158,   159,   111,
      97,   162,   163,   164,   165,   113,    60,   378,    62,   170,
     107,    91,   372,   373,   284,   285,   286,   287,   462,    91,
      60,    97,    64,    63,   433,   193,   112,    60,   437,   109,
     439,   107,   193,     0,     1,   109,   107,   109,   111,   113,
       7,     8,   116,    10,    11,    96,    97,    98,    99,   100,
     421,    51,    19,    70,    21,    72,    73,    74,   467,   468,
     274,    28,    29,    46,    47,   109,   109,   184,    97,   113,
     113,    58,   365,    57,    61,   270,    60,   185,    45,    46,
      47,    48,    49,    50,   101,   102,   109,    73,    74,   197,
     113,    58,   113,   453,    61,   116,   291,    60,    65,    66,
      67,    68,    60,   463,   111,   266,   267,   268,   303,   304,
     305,   306,   273,   274,    28,    29,   496,   410,    48,    49,
      50,   414,   415,   284,   285,   286,   287,    64,   448,   110,
      96,    97,    98,    99,   100,   515,    57,   166,    98,    99,
     100,   302,    77,    78,   110,   254,   255,   342,   343,    64,
     345,    70,    71,    72,    73,    74,   273,    60,   266,   354,
     355,   356,   357,    96,    97,    98,    99,   100,    96,    97,
      98,    99,   100,   111,   203,   114,    70,   110,    70,    60,
     108,    57,   101,   102,   379,   346,   112,    75,    76,    77,
      78,   352,   353,    81,    82,    83,    28,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   374,   109,   376,    42,   378,   108,   248,
      98,    99,   100,   516,    60,    37,   114,   422,   257,   111,
      60,   260,   261,   262,   263,   528,   111,   266,    42,   268,
     110,   402,   403,    57,   273,   112,   109,    60,    64,   115,
      31,   446,   114,   282,    96,    97,    98,    99,   100,   454,
     421,   112,   114,   112,   425,   426,   109,    33,   110,   430,
     109,   466,   433,   113,   435,   112,   437,   472,   439,    78,
      91,    24,    91,   478,    94,    95,    96,    97,    98,    99,
     100,   114,   487,   488,   489,   112,    57,   492,    60,    90,
      90,    52,    60,   111,   110,   519,   467,   468,   110,   112,
      19,   112,   112,   508,   111,   500,   114,   346,   113,   112,
     109,   350,   273,   352,   353,   486,   112,   358,   392,   358,
     315,   517,   523,    -1,   373,   496,   531,    -1,   499,    -1,
      -1,    -1,    -1,    -1,    -1,   374,    -1,   376,    -1,   378,
      -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,   519,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,
      -1,    -1,    86,   402,   403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      -1,    16,   421,    18,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,   437,    -1,
     439,   125,   126,   127,   128,   129,   130,   131,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    60,    -1,    62,   467,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,   170,   486,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,   107,    -1,    -1,    29,   515,    -1,    -1,    -1,
     204,   205,   206,    -1,   208,    -1,    -1,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    75,    76,    77,    78,   249,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,   283,
     284,   285,   286,   287,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    -1,    -1,    12,    13,
      14,    15,    16,   307,    18,    -1,    -1,   311,    22,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    71,    -1,    -1,
     364,    -1,    -1,    -1,    -1,    79,    80,    -1,   372,   373,
      84,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
     394,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,    -1,
      75,    76,    77,    78,   408,    -1,    81,    82,    83,   413,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,   442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,   453,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,   463,
     464,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,   483,
      -1,    -1,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    -1,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,     1,   103,     3,     4,     5,   107,     7,     8,
       9,   111,   112,    12,    13,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,     1,   103,     3,     4,     5,   107,     7,
       8,     9,   111,    -1,    12,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    26,    27,
      -1,    -1,    30,    -1,    32,    -1,    34,    35,    -1,    -1,
      -1,    39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,     1,   103,     3,     4,     5,   107,
       7,     8,     9,   111,    -1,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    26,
      27,    -1,    -1,    30,    -1,    32,    -1,    34,    35,    -1,
      -1,    -1,    39,    -1,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,     3,     4,     5,    84,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      97,    -1,    -1,    22,    -1,    -1,   103,    -1,    27,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,     9,    43,    44,    12,    13,    14,    -1,
      16,    -1,    18,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    43,    44,    -1,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    60,    -1,    62,    -1,    97,    -1,
      -1,    -1,    -1,    -1,   103,    71,    -1,    -1,   107,    -1,
      -1,    -1,   111,    79,    80,    -1,     9,    -1,    84,    12,
      13,    14,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,   107,    -1,   109,    -1,   111,    -1,    -1,    -1,     9,
      43,    44,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      53,    54,    55,    56,    57,    -1,    -1,    60,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    43,    44,    -1,    79,    80,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      60,    -1,    62,    -1,    97,    -1,    -1,    -1,    -1,    -1,
     103,    71,    -1,    -1,   107,    -1,    -1,    -1,    -1,    79,
      80,     1,    -1,    -1,    84,    -1,    -1,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    97,    -1,    19,
      -1,    21,    -1,   103,    -1,    -1,    -1,   107,    28,    29,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    38,
      -1,    61,    -1,    -1,    -1,    65,    66,    67,    68,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    75,    76,    77,    78,    -1,    -1,    81,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,    75,    76,    77,    78,
      -1,   114,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,   114,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    75,    76,    77,    78,    -1,
      -1,    81,    82,    83,   113,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
     110,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,   110,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    75,    76,    77,    78,    -1,
     108,    81,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    75,    76,    77,    78,    -1,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    75,    76,    -1,
      78,    -1,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    77,
      78,    -1,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    78,    -1,    -1,    81,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    78,    -1,    -1,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    10,    11,    19,    21,    28,    29,
      45,    48,    49,    50,    65,    66,    67,    68,   118,   119,
     120,   123,   127,   128,   130,   133,   137,   139,   143,   145,
     146,   147,   155,   158,   200,    64,    64,    60,    69,    60,
      63,   142,   109,    60,   135,   138,   129,    60,   136,     0,
     120,    46,    47,   126,    58,    61,    64,    64,   111,    60,
     107,   121,    57,    60,    97,   121,   203,   134,   111,   149,
      51,   208,   131,    60,    70,   113,   156,   157,    60,   162,
     164,   166,    64,    64,   141,   111,   144,   110,   203,   203,
      96,    97,    98,    99,   100,   110,   149,   150,    57,   149,
       1,   111,   132,   124,    60,   111,   162,   109,   113,   114,
      70,   158,   159,   140,     9,    12,    13,    14,    16,    18,
      43,    44,    57,    60,    62,    71,    79,    80,    84,    97,
     103,   121,   148,   167,   168,   170,   204,   210,   218,   221,
     108,   122,   203,   203,   203,   203,   203,     1,     3,     4,
       5,    15,    22,    25,    26,    27,    30,    32,    34,    35,
      39,    41,    53,    54,    55,    56,    59,    60,    63,   111,
     121,   147,   152,   153,   158,   167,   173,   174,   177,   183,
     204,   209,   211,   212,   209,   121,    70,    60,   224,    60,
     203,    57,   162,   109,   111,   165,   204,    28,   112,   159,
      60,    62,   202,   121,   121,   121,   121,   169,   109,   113,
     116,   204,   204,   204,   204,   204,   204,   204,    73,    74,
     171,    75,    76,    77,    78,    81,    82,    83,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   114,   122,   209,   121,   121,   121,
     209,    60,    37,   196,   197,   182,   121,   121,   111,   111,
     121,   121,   121,   121,   161,   167,   113,   192,   191,   204,
     211,   199,   200,   201,    70,    71,    72,    73,    74,   101,
     102,    42,    36,   113,    77,    78,    77,    78,   199,   200,
     159,   160,    60,   112,   114,   110,   110,   203,    57,   163,
     159,   112,   205,   167,   204,   204,   204,   109,   204,   168,
      60,    29,   122,   206,   207,   115,   172,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     221,    64,    57,   167,   204,   217,   198,    31,   196,   196,
     175,   167,   189,   190,   167,   167,   167,   167,   114,     1,
      59,    60,   158,   173,   121,   152,   122,   151,   153,   200,
      63,   209,   179,   188,   178,   186,   185,   187,   154,   167,
     204,   204,   211,   204,   211,   204,   211,   204,   211,   112,
     122,   110,   114,   112,   121,   122,   122,   122,   122,   204,
     110,   204,   109,   109,   170,   184,   122,   122,   114,   122,
     152,    33,   167,   113,   152,   152,   122,   122,   122,   122,
     161,   113,   218,   199,   112,   194,   204,   220,   221,   220,
      17,    57,    97,   121,   167,   222,   223,    91,   223,    91,
     173,   122,    38,   125,    24,   163,   218,   110,   113,   116,
     113,   223,   223,   114,   219,   204,   199,   204,   199,   199,
     122,   112,   121,   121,   121,    57,   223,   114,   121,   223,
     223,   181,   204,   208,   111,   122,   168,    60,   204,   110,
     110,   221,   122,    38,   112,   112,   193,   218,   221,   204,
     122,   223,   223,    90,    90,    28,   111,   176,   122,    52,
     213,     1,    58,    61,   215,   216,   208,   122,   204,   167,
     183,   122,   122,   122,   122,   111,   152,   180,     1,   121,
     149,   113,   214,   114,   112,   122,    73,   195,   152,   199,
     176,   209,    60,   216,   183,   199,   112,   122,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   122,   124,   125,
     123,   126,   126,   127,   127,   127,   127,   129,   128,   131,
     130,   132,   132,   134,   133,   135,   135,   136,   136,   138,
     137,   140,   139,   141,   139,   142,   142,   144,   143,   145,
     145,   146,   146,   146,   146,   147,   147,   148,   150,   151,
     149,   152,   152,   153,   153,   153,   153,   153,   154,   153,
     153,   155,   155,   155,   155,   156,   156,   156,   157,   157,
     158,   158,   158,   159,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   164,   164,   165,   166,   166,
     166,   166,   167,   168,   169,   168,   171,   170,   172,   172,
     173,   173,   175,   174,   176,   176,   178,   177,   179,   177,
     180,   177,   181,   177,   177,   177,   182,   177,   177,   177,
     177,   177,   177,   183,   183,   183,   183,   184,   183,   183,
     183,   183,   183,   185,   183,   186,   183,   187,   183,   188,
     183,   183,   183,   189,   183,   190,   183,   191,   183,   192,
     193,   183,   194,   195,   183,   183,   196,   196,   198,   197,
     199,   199,   200,   200,   201,   201,   202,   202,   203,   203,
     203,   203,   203,   203,   203,   203,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   205,
     204,   204,   204,   204,   206,   204,   207,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   208,
     208,   209,   209,   210,   210,   210,   210,   210,   210,   210,
     210,   211,   211,   211,   211,   211,   211,   211,   211,   212,
     212,   212,   212,   213,   213,   213,   214,   214,   215,   215,
     215,   216,   216,   217,   218,   218,   219,   219,   220,   220,
     221,   221,   222,   222,   222,   222,   223,   223,   223,   223,
     224,   224,   224
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
      11,     1,     1,     0,     1,     4,     4,     0,     4,     0,
       4,     4,     1,     0,     4,     0,     1,     0,     1,     0,
       3,     0,     7,     0,     6,     1,     1,     0,     6,     1,
       1,     3,     3,     4,     4,     1,     1,     1,     0,     0,
       6,     1,     3,     1,     2,     3,     3,     1,     0,     4,
       1,     0,     1,     1,     1,     0,     3,     1,     0,     2,
       4,     3,     6,     1,     3,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     5,     3,     3,     7,     1,     3,
       4,     4,     1,     1,     0,     5,     0,     3,     0,     2,
       1,     1,     0,     4,     4,     5,     0,     4,     0,     4,
       0,     8,     0,     6,     8,     3,     0,     4,     1,     2,
       3,     2,     1,     3,     2,     2,     4,     0,     6,     4,
       4,     2,     1,     0,     4,     0,     6,     0,     6,     0,
       4,     1,     1,     0,     6,     0,     6,     0,     5,     0,
       0,     7,     0,     0,     9,     2,     1,     2,     0,     4,
       0,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     7,     0,
       7,     4,     4,     4,     0,     6,     0,     6,     1,     1,
       1,     1,     1,     4,     6,     6,     3,     3,     1,     0,
       2,     1,     1,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     0,     4,     2,     0,     2,     2,     1,
       1,     1,     3,     3,     0,     1,     0,     2,     1,     4,
       1,     3,     1,     4,     1,     2,     1,     3,     4,     3,
       1,     2,     2
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
#line 102 "spin.y"
                        { yytext[0] = '\0'; }
#line 2239 "y.tab.c"
    break;

  case 16:
#line 122 "spin.y"
                        { par_cnt++; }
#line 2245 "y.tab.c"
    break;

  case 17:
#line 125 "spin.y"
                        { par_cnt--; }
#line 2251 "y.tab.c"
    break;

  case 18:
#line 130 "spin.y"
                        { 
			  setptype(ZN, yyvsp[0], PROCTYPE, ZN);
			  setpname(yyvsp[0]);
			  context = yyvsp[0]->sym;
			  context->ini = yyvsp[-1]; /* linenr and file */
			  Expand_Ok++; /* expand struct names in decl */
			  has_ini = 0;
			}
#line 2264 "y.tab.c"
    break;

  case 19:
#line 138 "spin.y"
                                { Expand_Ok--;
			  if (has_ini)
			  fatal("initializer in parameter list", (char *) 0);
			}
#line 2273 "y.tab.c"
    break;

  case 20:
#line 144 "spin.y"
                        { ProcList *rl;
			  if (yyvsp[-10] != ZN && yyvsp[-10]->val > 0)
			  {	int j;
				rl = mk_rdy(yyvsp[-8]->sym, yyvsp[-5], yyvsp[0]->sq, yyvsp[-9]->val, yyvsp[-1], A_PROC);
			  	for (j = 0; j < yyvsp[-10]->val; j++)
				{	runnable(rl, yyvsp[-2]?yyvsp[-2]->val:1, 1);
					announce(":root:");
				}
				if (dumptab) yyvsp[-8]->sym->ini = yyvsp[-10];
			  } else
			  {	rl = mk_rdy(yyvsp[-8]->sym, yyvsp[-5], yyvsp[0]->sq, yyvsp[-9]->val, yyvsp[-1], P_PROC);
			  }
			  if (rl && has_ini == 1) /* global initializations, unsafe */
			  {	/* printf("proctype %s has initialized data\n",
					$3->sym->name);
				 */
				rl->unsafe = 1;
			  }
			  context = ZS;
			}
#line 2298 "y.tab.c"
    break;

  case 21:
#line 166 "spin.y"
                        { yyval = nn(ZN,CONST,ZN,ZN); yyval->val = 0; }
#line 2304 "y.tab.c"
    break;

  case 22:
#line 167 "spin.y"
                        { yyval = nn(ZN,CONST,ZN,ZN); yyval->val = 1; }
#line 2310 "y.tab.c"
    break;

  case 23:
#line 170 "spin.y"
                        { yyval = ZN; }
#line 2316 "y.tab.c"
    break;

  case 24:
#line 171 "spin.y"
                        { yyval = nn(ZN,CONST,ZN,ZN); yyval->val = 1; }
#line 2322 "y.tab.c"
    break;

  case 25:
#line 172 "spin.y"
                                    {
			  yyval = nn(ZN,CONST,ZN,ZN); yyval->val = yyvsp[-1]->val;
			  if (yyvsp[-1]->val > 255)
				non_fatal("max nr of processes is 255\n", "");
			}
#line 2332 "y.tab.c"
    break;

  case 26:
#line 177 "spin.y"
                              {
			  yyval = nn(ZN,CONST,ZN,ZN);
			  yyval->val = 0;
			  if (!yyvsp[-1]->sym->type)
				fatal("undeclared variable %s",
					yyvsp[-1]->sym->name);
			  else if (yyvsp[-1]->sym->ini->ntyp != CONST)
				fatal("need constant initializer for %s\n",
					yyvsp[-1]->sym->name);
			  else
				yyval->val = yyvsp[-1]->sym->ini->val;
			}
#line 2349 "y.tab.c"
    break;

  case 27:
#line 191 "spin.y"
                        { context = yyvsp[0]->sym; }
#line 2355 "y.tab.c"
    break;

  case 28:
#line 193 "spin.y"
                        { ProcList *rl;
			  rl = mk_rdy(context, ZN, yyvsp[0]->sq, 0, ZN, I_PROC);
			  runnable(rl, yyvsp[-1]?yyvsp[-1]->val:1, 1);
			  announce(":root:");
			  context = ZS;
        		}
#line 2366 "y.tab.c"
    break;

  case 29:
#line 201 "spin.y"
                        { ltl_mode = 1; ltl_name = yyvsp[0]->sym->name; }
#line 2372 "y.tab.c"
    break;

  case 30:
#line 202 "spin.y"
                        { if (yyvsp[0]) ltl_list(yyvsp[-2]->sym->name, yyvsp[0]->sym->name);
			  ltl_mode = 0; has_ltl = 1;
			}
#line 2380 "y.tab.c"
    break;

  case 31:
#line 207 "spin.y"
                               { yyval = ltl_to_string(yyvsp[-2]); }
#line 2386 "y.tab.c"
    break;

  case 32:
#line 208 "spin.y"
                        { yyval = NULL; }
#line 2392 "y.tab.c"
    break;

  case 33:
#line 211 "spin.y"
                        { if (yyvsp[0] != ZN)
			  {	yyvsp[-1]->sym = yyvsp[0]->sym;	/* new 5.3.0 */
			  }
			  nclaims++;
			  context = yyvsp[-1]->sym;
			  if (claimproc && !strcmp(claimproc, yyvsp[-1]->sym->name))
			  {	fatal("claim %s redefined", claimproc);
			  }
			  claimproc = yyvsp[-1]->sym->name;
			}
#line 2407 "y.tab.c"
    break;

  case 34:
#line 221 "spin.y"
                        { (void) mk_rdy(yyvsp[-3]->sym, ZN, yyvsp[0]->sq, 0, ZN, N_CLAIM);
        		  context = ZS;
        		}
#line 2415 "y.tab.c"
    break;

  case 35:
#line 226 "spin.y"
                        { char tb[32];
			  memset(tb, 0, 32);
			  sprintf(tb, "never_%d", nclaims);
			  yyval = nn(ZN, NAME, ZN, ZN);
			  yyval->sym = lookup(tb);
			}
#line 2426 "y.tab.c"
    break;

  case 36:
#line 232 "spin.y"
                        { yyval = yyvsp[0]; }
#line 2432 "y.tab.c"
    break;

  case 37:
#line 235 "spin.y"
                       { char tb[32]; static int nltl = 0;
			  memset(tb, 0, 32);
			  sprintf(tb, "ltl_%d", nltl++);
			  yyval = nn(ZN, NAME, ZN, ZN);
			  yyval->sym = lookup(tb);
			}
#line 2443 "y.tab.c"
    break;

  case 38:
#line 241 "spin.y"
                        { yyval = yyvsp[0]; }
#line 2449 "y.tab.c"
    break;

  case 39:
#line 244 "spin.y"
                        { context = yyvsp[0]->sym;
			  if (eventmap)
				non_fatal("trace %s redefined", eventmap);
			  eventmap = yyvsp[0]->sym->name;
			  inEventMap++;
			}
#line 2460 "y.tab.c"
    break;

  case 40:
#line 250 "spin.y"
                        {
			  if (strcmp(yyvsp[-2]->sym->name, ":trace:") == 0)
			  {	(void) mk_rdy(yyvsp[-2]->sym, ZN, yyvsp[0]->sq, 0, ZN, E_TRACE);
			  } else
			  {	(void) mk_rdy(yyvsp[-2]->sym, ZN, yyvsp[0]->sq, 0, ZN, N_TRACE);
			  }
        		  context = ZS;
			  inEventMap--;
			}
#line 2474 "y.tab.c"
    break;

  case 41:
#line 263 "spin.y"
                        {  if (context)
				   { fatal("typedef %s must be global",
					yyvsp[-1]->sym->name);
				   }
				   owner = yyvsp[-1]->sym;
				   in_seq = yyvsp[-3]->ln;
				}
#line 2486 "y.tab.c"
    break;

  case 42:
#line 270 "spin.y"
                                { setuname(yyvsp[-1], UNION);
				  owner = ZS;
				  in_seq = 0;
				}
#line 2495 "y.tab.c"
    break;

  case 43:
#line 276 "spin.y"
                        {  if (context)
				   { fatal("typedef %s must be global",
					yyvsp[-1]->sym->name);
				   }
				   owner = yyvsp[-1]->sym;
				   in_seq = yyvsp[-2]->ln;
				}
#line 2507 "y.tab.c"
    break;

  case 44:
#line 283 "spin.y"
                                { setuname(yyvsp[-1], STRUCT);
				  owner = ZS;
				  in_seq = 0;
				}
#line 2516 "y.tab.c"
    break;

  case 45:
#line 290 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2522 "y.tab.c"
    break;

  case 46:
#line 291 "spin.y"
                                { yyval = yyvsp[0];
				  if (IArgs)
				  fatal("invalid use of '%s'", yyvsp[0]->sym->name);
				}
#line 2531 "y.tab.c"
    break;

  case 47:
#line 297 "spin.y"
                                        { NamesNotAdded++; }
#line 2537 "y.tab.c"
    break;

  case 48:
#line 298 "spin.y"
                                { prep_inline(yyvsp[-4]->sym, yyvsp[-1]);
				  NamesNotAdded--;
				}
#line 2545 "y.tab.c"
    break;

  case 49:
#line 303 "spin.y"
                                { /* leaves pseudo-inlines with sym of
				   * type CODE_FRAG or CODE_DECL in global context
				   */
				}
#line 2554 "y.tab.c"
    break;

  case 51:
#line 310 "spin.y"
                                {
				  c_state(yyvsp[-1]->sym, yyvsp[0]->sym, ZS);
				  has_code = has_state = 1;
				}
#line 2563 "y.tab.c"
    break;

  case 52:
#line 314 "spin.y"
                                {
				  c_track(yyvsp[-1]->sym, yyvsp[0]->sym, ZS);
				  has_code = has_state = 1;
				}
#line 2572 "y.tab.c"
    break;

  case 53:
#line 318 "spin.y"
                                       {
				  c_state(yyvsp[-2]->sym, yyvsp[-1]->sym, yyvsp[0]->sym);
				  has_code = has_state = 1;
				}
#line 2581 "y.tab.c"
    break;

  case 54:
#line 322 "spin.y"
                                       {
				  c_track(yyvsp[-2]->sym, yyvsp[-1]->sym, yyvsp[0]->sym);
				  has_code = has_state = 1;
				}
#line 2590 "y.tab.c"
    break;

  case 55:
#line 328 "spin.y"
                                { Symbol *s;
				  NamesNotAdded++;
				  s = prep_inline(ZS, ZN);
				  NamesNotAdded--;
				  yyval = nn(ZN, C_CODE, ZN, ZN);
				  yyval->sym = s;
				  yyval->ln = yyvsp[0]->ln;
				  yyval->fn = yyvsp[0]->fn;
				  has_code = 1;
				}
#line 2605 "y.tab.c"
    break;

  case 56:
#line 338 "spin.y"
                                { Symbol *s;
				  NamesNotAdded++;
				  s = prep_inline(ZS, ZN);
				  NamesNotAdded--;
				  s->type = CODE_DECL;
				  yyval = nn(ZN, C_CODE, ZN, ZN);
				  yyval->sym = s;
				  yyval->ln = yyvsp[0]->ln;
				  yyval->fn = yyvsp[0]->fn;
				  has_code = 1;
				}
#line 2621 "y.tab.c"
    break;

  case 57:
#line 350 "spin.y"
                                { Symbol *s;
				  NamesNotAdded++;
				  s = prep_inline(ZS, ZN);
/* if context is 0 this was inside an ltl formula
   mark the last inline added to seqnames */
				  if (!context)
				  {	mark_last();
				  }
				  NamesNotAdded--;
				  yyval = nn(ZN, C_EXPR, ZN, ZN);
				  yyval->sym = s;
				  yyval->ln = yyvsp[0]->ln;
				  yyval->fn = yyvsp[0]->fn;
				  no_side_effects(s->name);
				  has_code = 1;
				}
#line 2642 "y.tab.c"
    break;

  case 58:
#line 368 "spin.y"
                                { open_seq(1); in_seq = yyvsp[0]->ln; }
#line 2648 "y.tab.c"
    break;

  case 59:
#line 369 "spin.y"
                                { add_seq(Stop); }
#line 2654 "y.tab.c"
    break;

  case 60:
#line 370 "spin.y"
                                { yyval->sq = close_seq(0); in_seq = 0;
				  if (scope_level != 0)
				  {	non_fatal("missing '}' ?", 0);
					scope_level = 0;
				  }
				}
#line 2665 "y.tab.c"
    break;

  case 61:
#line 378 "spin.y"
                                { if (yyvsp[0]) add_seq(yyvsp[0]); }
#line 2671 "y.tab.c"
    break;

  case 62:
#line 379 "spin.y"
                                { if (yyvsp[0]) add_seq(yyvsp[0]); }
#line 2677 "y.tab.c"
    break;

  case 63:
#line 382 "spin.y"
                                { yyval = ZN; }
#line 2683 "y.tab.c"
    break;

  case 64:
#line 383 "spin.y"
                                { setxus(yyvsp[0], yyvsp[-1]->val); yyval = ZN; }
#line 2689 "y.tab.c"
    break;

  case 65:
#line 384 "spin.y"
                                { fatal("label preceding declaration,", (char *)0); }
#line 2695 "y.tab.c"
    break;

  case 66:
#line 385 "spin.y"
                                { fatal("label preceding xr/xs claim,", 0); }
#line 2701 "y.tab.c"
    break;

  case 67:
#line 386 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2707 "y.tab.c"
    break;

  case 68:
#line 387 "spin.y"
                                { if (yyvsp[-1]->ntyp == DO) { safe_break(); } }
#line 2713 "y.tab.c"
    break;

  case 69:
#line 388 "spin.y"
                                { if (yyvsp[-3]->ntyp == DO) { restore_break(); }
				  yyval = do_unless(yyvsp[-3], yyvsp[0]);
				}
#line 2721 "y.tab.c"
    break;

  case 71:
#line 394 "spin.y"
                                { yyval = ZN; }
#line 2727 "y.tab.c"
    break;

  case 72:
#line 395 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2733 "y.tab.c"
    break;

  case 73:
#line 396 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2739 "y.tab.c"
    break;

  case 74:
#line 397 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2745 "y.tab.c"
    break;

  case 75:
#line 400 "spin.y"
                                { yyval = ZN; }
#line 2751 "y.tab.c"
    break;

  case 76:
#line 401 "spin.y"
                                { yyval = yyvsp[-1]; /* mtype decl */ }
#line 2757 "y.tab.c"
    break;

  case 77:
#line 402 "spin.y"
                                { yyval = ZN; /* mtype decl */ }
#line 2763 "y.tab.c"
    break;

  case 78:
#line 405 "spin.y"
                                { yyval = ZN; }
#line 2769 "y.tab.c"
    break;

  case 79:
#line 406 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2775 "y.tab.c"
    break;

  case 80:
#line 409 "spin.y"
                                  { setptype(yyvsp[-1], yyvsp[0], yyvsp[-2]->val, yyvsp[-3]);
				  yyvsp[0]->val = yyvsp[-2]->val;
				  yyval = yyvsp[0];
				}
#line 2784 "y.tab.c"
    break;

  case 81:
#line 413 "spin.y"
                                { setutype(yyvsp[0], yyvsp[-1]->sym, yyvsp[-2]);
				  yyval = expand(yyvsp[0], Expand_Ok);
				}
#line 2792 "y.tab.c"
    break;

  case 82:
#line 416 "spin.y"
                                     {
				  if (yyvsp[-4]->val != MTYPE)
					fatal("malformed declaration", 0);
				  setmtype(yyvsp[-3], yyvsp[-1]);
				  if (yyvsp[-5])
					non_fatal("cannot %s mtype (ignored)",
						yyvsp[-5]->sym->name);
				  if (context != ZS)
					fatal("mtype declaration must be global", 0);
				}
#line 2807 "y.tab.c"
    break;

  case 83:
#line 428 "spin.y"
                                { yyval = nn(ZN, ',', yyvsp[0], ZN); }
#line 2813 "y.tab.c"
    break;

  case 84:
#line 430 "spin.y"
                                { yyval = nn(ZN, ',', yyvsp[-2], yyvsp[0]); }
#line 2819 "y.tab.c"
    break;

  case 85:
#line 433 "spin.y"
                                { yyval = ZN; }
#line 2825 "y.tab.c"
    break;

  case 86:
#line 434 "spin.y"
                                { yyval = yyvsp[0]; }
#line 2831 "y.tab.c"
    break;

  case 87:
#line 437 "spin.y"
                                { yyval = nn(yyvsp[0], XU, yyvsp[0], ZN); }
#line 2837 "y.tab.c"
    break;

  case 88:
#line 438 "spin.y"
                                { yyval = nn(yyvsp[-2], XU, yyvsp[-2], yyvsp[0]); }
#line 2843 "y.tab.c"
    break;

  case 89:
#line 441 "spin.y"
                                { yyval = nn(yyvsp[0], TYPE, ZN, ZN); }
#line 2849 "y.tab.c"
    break;

  case 90:
#line 442 "spin.y"
                                { yyval = nn(yyvsp[-2], TYPE, ZN, yyvsp[0]); }
#line 2855 "y.tab.c"
    break;

  case 91:
#line 445 "spin.y"
                                { yyvsp[0]->ntyp = CONST; yyval = yyvsp[0]; }
#line 2861 "y.tab.c"
    break;

  case 92:
#line 446 "spin.y"
                                { yyvsp[-2]->ntyp = CONST; yyval = nn(yyvsp[-2], ',', yyvsp[-2], yyvsp[0]); }
#line 2867 "y.tab.c"
    break;

  case 93:
#line 449 "spin.y"
                                { yyval = yyvsp[0];
				  yyvsp[0]->sym->ini = nn(ZN,CONST,ZN,ZN);
				  yyvsp[0]->sym->ini->val = 0;
				  if (!initialization_ok)
				  {	Lextok *zx, *xz;
					zx = nn(ZN, NAME, ZN, ZN);
					zx->sym = yyvsp[0]->sym;
					xz = nn(zx, ASGN, zx, yyvsp[0]->sym->ini);
					keep_track_off(xz);
					/* make sure zx doesnt turn out to be a STRUCT later */
					add_seq(xz);
				  }
				}
#line 2885 "y.tab.c"
    break;

  case 94:
#line 462 "spin.y"
                                        {	/* array initialization */
				  if (!yyvsp[-4]->sym->isarray)
					fatal("%s must be an array", yyvsp[-4]->sym->name);
				  yyval = yyvsp[-4];
				  yyvsp[-4]->sym->ini = yyvsp[-1];
				  has_ini = 1;
				  yyvsp[-4]->sym->hidden |= (4|8);	/* conservative */
				  if (!initialization_ok)
				  {	Lextok *zx = nn(ZN, NAME, ZN, ZN);
					zx->sym = yyvsp[-4]->sym;
					add_seq(nn(zx, ASGN, zx, yyvsp[-1]));
				  }
				}
#line 2903 "y.tab.c"
    break;

  case 95:
#line 475 "spin.y"
                                { yyval = yyvsp[-2];	/* initialized scalar */
				  yyvsp[-2]->sym->ini = yyvsp[0];
				  if (yyvsp[0]->ntyp == CONST
				  || (yyvsp[0]->ntyp == NAME && yyvsp[0]->sym->context))
				  {	has_ini = 2; /* local init */
				  } else
				  {	has_ini = 1; /* possibly global */
				  }
				  trackvar(yyvsp[-2], yyvsp[0]);
				  if (any_oper(yyvsp[0], RUN))
				  {	fatal("cannot use 'run' in var init, saw", (char *) 0);
				  }
				  nochan_manip(yyvsp[-2], yyvsp[0], 0);
				  no_internals(yyvsp[-2]);
				  if (!initialization_ok)
				  {	Lextok *zx = nn(ZN, NAME, ZN, ZN);
					zx->sym = yyvsp[-2]->sym;
					add_seq(nn(zx, ASGN, zx, yyvsp[0]));
					yyvsp[-2]->sym->ini = 0;	/* Patrick Trentlin */
				  }
				}
#line 2929 "y.tab.c"
    break;

  case 96:
#line 496 "spin.y"
                                { yyvsp[-2]->sym->ini = yyvsp[0];	/* channel declaration */
				  yyval = yyvsp[-2]; has_ini = 1;
				  if (!initialization_ok)
				  {	non_fatal(PART1 "'%s'" PART2, yyvsp[-2]->sym->name);
				  }
				}
#line 2940 "y.tab.c"
    break;

  case 97:
#line 505 "spin.y"
                                { if (yyvsp[-5]->val)
					u_async++;
				  else
					u_sync++;
        			  {	int i = cnt_mpars(yyvsp[-1]);
					Mpars = max(Mpars, i);
				  }
        			  yyval = nn(ZN, CHAN, ZN, yyvsp[-1]);
				  yyval->val = yyvsp[-5]->val;
				  yyval->ln = yyvsp[-6]->ln;
				  yyval->fn = yyvsp[-6]->fn;
        			}
#line 2957 "y.tab.c"
    break;

  case 98:
#line 519 "spin.y"
                                { yyvsp[0]->sym->nel = 1; yyval = yyvsp[0]; }
#line 2963 "y.tab.c"
    break;

  case 99:
#line 520 "spin.y"
                                { yyvsp[-2]->sym->nbits = yyvsp[0]->val;
				  if (yyvsp[0]->val >= 8*sizeof(long))
				  {	non_fatal("width-field %s too large",
						yyvsp[-2]->sym->name);
					yyvsp[0]->val = 8*sizeof(long)-1;
				  }
				  yyvsp[-2]->sym->nel = 1; yyval = yyvsp[-2];
				}
#line 2976 "y.tab.c"
    break;

  case 100:
#line 528 "spin.y"
                                        { yyvsp[-3]->sym->nel = yyvsp[-1]->val; yyvsp[-3]->sym->isarray = 1; yyval = yyvsp[-3]; }
#line 2982 "y.tab.c"
    break;

  case 101:
#line 529 "spin.y"
                                {	/* make an exception for an initialized scalars */
					yyval = nn(ZN, CONST, ZN, ZN);
					fprintf(stderr, "spin: %s:%d, warning: '%s' in array bound ",
						yyvsp[-3]->fn->name, yyvsp[-3]->ln, yyvsp[-1]->sym->name);
					if (yyvsp[-1]->sym->ini
					&&  yyvsp[-1]->sym->ini->val > 0)
					{	fprintf(stderr, "evaluated as %d\n", yyvsp[-1]->sym->ini->val);
						yyval->val = yyvsp[-1]->sym->ini->val;
					} else
					{	fprintf(stderr, "evaluated as 1 by default (to avoid zero)\n");
						yyval->val = 1;
					}
					yyvsp[-3]->sym->nel = yyval->val;
					yyvsp[-3]->sym->isarray = 1;
					yyval = yyvsp[-3];
				}
#line 3003 "y.tab.c"
    break;

  case 102:
#line 547 "spin.y"
                                { yyval = mk_explicit(yyvsp[0], Expand_Ok, NAME); }
#line 3009 "y.tab.c"
    break;

  case 103:
#line 550 "spin.y"
                                { yyval = nn(yyvsp[0], NAME, ZN, ZN);
				  if (yyvsp[0]->sym->isarray && !in_for && !IArgs)
				  {	non_fatal("missing array index for '%s'",
						yyvsp[0]->sym->name);
				  }
				}
#line 3020 "y.tab.c"
    break;

  case 104:
#line 556 "spin.y"
                                { owner = ZS; }
#line 3026 "y.tab.c"
    break;

  case 105:
#line 557 "spin.y"
                                { yyval = nn(yyvsp[-4], NAME, yyvsp[-1], ZN); }
#line 3032 "y.tab.c"
    break;

  case 106:
#line 560 "spin.y"
                                { Embedded++;
				  if ((yyvsp[0]->sym->type == STRUCT) || (yyvsp[0]->sym->type == UNION))
					owner = yyvsp[0]->sym->Snm;
				}
#line 3041 "y.tab.c"
    break;

  case 107:
#line 564 "spin.y"
                                { yyval = yyvsp[-2]; yyval->rgt = yyvsp[0];
	  			  /* TODO STRUCT UNION - analyze the consequences of this*/
				  if (yyvsp[0] && yyvsp[-2]->sym->type != STRUCT && yyvsp[-2]->sym->type != UNION)
				  {
					printf("WARNING: Assigning STRUCT by default to %s\n", yyvsp[-2]->sym->name);
					yyvsp[-2]->sym->type = STRUCT;
				  }
				  Embedded--;
				  if (!Embedded && !NamesNotAdded
				  &&  !yyvsp[-2]->sym->type)
				   fatal("undeclared variable: %s",
						yyvsp[-2]->sym->name);
				  if (yyvsp[0]) validref(yyvsp[-2], yyvsp[0]->lft);
				  owner = ZS;
				}
#line 3061 "y.tab.c"
    break;

  case 108:
#line 581 "spin.y"
                                { yyval = ZN; }
#line 3067 "y.tab.c"
    break;

  case 109:
#line 582 "spin.y"
                                { yyval = nn(ZN, '.', yyvsp[0], ZN); }
#line 3073 "y.tab.c"
    break;

  case 110:
#line 585 "spin.y"
                                { yyval = yyvsp[0]; initialization_ok = 0; }
#line 3079 "y.tab.c"
    break;

  case 111:
#line 586 "spin.y"
                                { yyval = yyvsp[0]; initialization_ok = 0;
				  if (inEventMap) non_fatal("not an event", (char *)0);
				}
#line 3087 "y.tab.c"
    break;

  case 112:
#line 591 "spin.y"
                                { in_for = 1; }
#line 3093 "y.tab.c"
    break;

  case 113:
#line 592 "spin.y"
                                { trapwonly(yyvsp[0] /*, "for" */);
				  pushbreak(); /* moved up */
				  yyval = yyvsp[0];
				}
#line 3102 "y.tab.c"
    break;

  case 116:
#line 601 "spin.y"
                                { Expand_Ok++; }
#line 3108 "y.tab.c"
    break;

  case 117:
#line 602 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-3],  'r', yyvsp[-3], yyvsp[0]);
				  trackchanuse(yyvsp[0], ZN, 'R');
				}
#line 3117 "y.tab.c"
    break;

  case 118:
#line 606 "spin.y"
                                { Expand_Ok++; }
#line 3123 "y.tab.c"
    break;

  case 119:
#line 607 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-3], 's', yyvsp[-3], yyvsp[0]);
				  yyval->val=0; trackchanuse(yyvsp[0], ZN, 'S');
				  any_runs(yyvsp[0]);
				}
#line 3133 "y.tab.c"
    break;

  case 120:
#line 612 "spin.y"
                                                {
				  for_setup(yyvsp[-5], yyvsp[-3], yyvsp[-1]); in_for = 0;
				}
#line 3141 "y.tab.c"
    break;

  case 121:
#line 615 "spin.y"
                                { yyval = for_body(yyvsp[-7], 1);
				}
#line 3148 "y.tab.c"
    break;

  case 122:
#line 617 "spin.y"
                                        { yyval = for_index(yyvsp[-3], yyvsp[-1]); in_for = 0;
				}
#line 3155 "y.tab.c"
    break;

  case 123:
#line 619 "spin.y"
                                { yyval = for_body(yyvsp[-1], 1);
				}
#line 3162 "y.tab.c"
    break;

  case 124:
#line 621 "spin.y"
                                                         {
				  trapwonly(yyvsp[-5] /*, "select" */);
				  yyval = sel_index(yyvsp[-5], yyvsp[-3], yyvsp[-1]);
				}
#line 3171 "y.tab.c"
    break;

  case 125:
#line 625 "spin.y"
                                { yyval = nn(yyvsp[-2], IF, ZN, ZN);
        			  yyval->sl = yyvsp[-1]->sl;
				  yyval->ln = yyvsp[-2]->ln;
				  yyval->fn = yyvsp[-2]->fn;
				  prune_opts(yyval);
        			}
#line 3182 "y.tab.c"
    break;

  case 126:
#line 631 "spin.y"
                                { pushbreak(); }
#line 3188 "y.tab.c"
    break;

  case 127:
#line 632 "spin.y"
                                { yyval = nn(yyvsp[-3], DO, ZN, ZN);
        			  yyval->sl = yyvsp[-1]->sl;
				  yyval->ln = yyvsp[-3]->ln;
				  yyval->fn = yyvsp[-3]->fn;
				  prune_opts(yyval);
        			}
#line 3199 "y.tab.c"
    break;

  case 128:
#line 638 "spin.y"
                                { yyval = nn(ZN, GOTO, ZN, ZN);
				  yyval->sym = break_dest();
				}
#line 3207 "y.tab.c"
    break;

  case 129:
#line 641 "spin.y"
                                { yyval = nn(yyvsp[0], GOTO, ZN, ZN);
				  if (yyvsp[0]->sym->type != 0
				  &&  yyvsp[0]->sym->type != LABEL) {
				  	non_fatal("bad label-name %s",
					yyvsp[0]->sym->name);
				  }
				  yyvsp[0]->sym->type = LABEL;
				}
#line 3220 "y.tab.c"
    break;

  case 130:
#line 649 "spin.y"
                                { yyval = nn(yyvsp[-2], ':',yyvsp[0], ZN);
				  if (yyvsp[-2]->sym->type != 0
				  &&  yyvsp[-2]->sym->type != LABEL) {
				  	non_fatal("bad label-name %s",
					yyvsp[-2]->sym->name);
				  }
				  yyvsp[-2]->sym->type = LABEL;
				}
#line 3233 "y.tab.c"
    break;

  case 131:
#line 657 "spin.y"
                                { yyval = nn(yyvsp[-1], ':',ZN,ZN);
				  if (yyvsp[-1]->sym->type != 0
				  &&  yyvsp[-1]->sym->type != LABEL) {
				  	non_fatal("bad label-name %s",
					yyvsp[-1]->sym->name);
				  }
				  yyval->lft = nn(ZN, 'c', nn(ZN,CONST,ZN,ZN), ZN);
				  yyval->lft->lft->val = 1; /* skip */
				  yyvsp[-1]->sym->type = LABEL;
				}
#line 3248 "y.tab.c"
    break;

  case 132:
#line 667 "spin.y"
                                { yyval = nn(ZN, 'c', nn(ZN,CONST,ZN,ZN), ZN);
				  yyval->lft->val = 1; /* skip */
				}
#line 3256 "y.tab.c"
    break;

  case 133:
#line 672 "spin.y"
                                { yyval = nn(yyvsp[-2], ASGN, yyvsp[-2], yyvsp[0]);	/* assignment */
				  trackvar(yyvsp[-2], yyvsp[0]);
				  nochan_manip(yyvsp[-2], yyvsp[0], 0);
				  no_internals(yyvsp[-2]);
				}
#line 3266 "y.tab.c"
    break;

  case 134:
#line 677 "spin.y"
                                { yyval = nn(ZN,CONST, ZN, ZN); yyval->val = 1;
				  yyval = nn(ZN,  '+', yyvsp[-1], yyval);
				  yyval = nn(yyvsp[-1], ASGN, yyvsp[-1], yyval);
				  trackvar(yyvsp[-1], yyvsp[-1]);
				  no_internals(yyvsp[-1]);
				  if (yyvsp[-1]->sym->type == CHAN)
				   fatal("arithmetic on chan", (char *)0);
				}
#line 3279 "y.tab.c"
    break;

  case 135:
#line 685 "spin.y"
                                { yyval = nn(ZN,CONST, ZN, ZN); yyval->val = 1;
				  yyval = nn(ZN,  '-', yyvsp[-1], yyval);
				  yyval = nn(yyvsp[-1], ASGN, yyvsp[-1], yyval);
				  trackvar(yyvsp[-1], yyvsp[-1]);
				  no_internals(yyvsp[-1]);
				  if (yyvsp[-1]->sym->type == CHAN)
				   fatal("arithmetic on chan id's", (char *)0);
				}
#line 3292 "y.tab.c"
    break;

  case 136:
#line 693 "spin.y"
                                        { yyval = nn(ZN, SET_P, yyvsp[-1], ZN); has_priority++; }
#line 3298 "y.tab.c"
    break;

  case 137:
#line 694 "spin.y"
                                { realread = 0; }
#line 3304 "y.tab.c"
    break;

  case 138:
#line 695 "spin.y"
                                { yyval = nn(yyvsp[-3], PRINT, yyvsp[-1], ZN); realread = 1; }
#line 3310 "y.tab.c"
    break;

  case 139:
#line 696 "spin.y"
                                        { yyval = nn(ZN, PRINTM, yyvsp[-1], ZN); }
#line 3316 "y.tab.c"
    break;

  case 140:
#line 697 "spin.y"
                                        { yyval = nn(ZN, PRINTM, yyvsp[-1], ZN); }
#line 3322 "y.tab.c"
    break;

  case 141:
#line 698 "spin.y"
                                { yyval = nn(ZN, ASSERT, yyvsp[0], ZN); AST_track(yyvsp[0], 0); }
#line 3328 "y.tab.c"
    break;

  case 142:
#line 699 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3334 "y.tab.c"
    break;

  case 143:
#line 700 "spin.y"
                                { Expand_Ok++; }
#line 3340 "y.tab.c"
    break;

  case 144:
#line 701 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-3],  'r', yyvsp[-3], yyvsp[0]);
				  yyval->val = has_random = 1;
				  trackchanuse(yyvsp[0], ZN, 'R');
				}
#line 3350 "y.tab.c"
    break;

  case 145:
#line 706 "spin.y"
                                { Expand_Ok++; }
#line 3356 "y.tab.c"
    break;

  case 146:
#line 707 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-5], 'r', yyvsp[-5], yyvsp[-1]);
				  yyval->val = 2;	/* fifo poll */
				  trackchanuse(yyvsp[-1], ZN, 'R');
				}
#line 3366 "y.tab.c"
    break;

  case 147:
#line 712 "spin.y"
                                { Expand_Ok++; }
#line 3372 "y.tab.c"
    break;

  case 148:
#line 713 "spin.y"
                                { Expand_Ok--; has_io++;	/* rrcv poll */
				  yyval = nn(yyvsp[-5], 'r', yyvsp[-5], yyvsp[-1]);
				  yyval->val = 3; has_random = 1;
				  trackchanuse(yyvsp[-1], ZN, 'R');
				}
#line 3382 "y.tab.c"
    break;

  case 149:
#line 718 "spin.y"
                                { Expand_Ok++; }
#line 3388 "y.tab.c"
    break;

  case 150:
#line 719 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-3], 's', yyvsp[-3], yyvsp[0]);
				  yyval->val = has_sorted = 1;
				  trackchanuse(yyvsp[0], ZN, 'S');
				  any_runs(yyvsp[0]);
				}
#line 3399 "y.tab.c"
    break;

  case 151:
#line 725 "spin.y"
                                { yyval = nn(ZN, 'c', yyvsp[0], ZN); count_runs(yyval); }
#line 3405 "y.tab.c"
    break;

  case 152:
#line 726 "spin.y"
                                { yyval = nn(ZN,ELSE,ZN,ZN);
				}
#line 3412 "y.tab.c"
    break;

  case 153:
#line 728 "spin.y"
                                { open_seq(0); }
#line 3418 "y.tab.c"
    break;

  case 154:
#line 729 "spin.y"
                                { yyval = nn(yyvsp[-5], ATOMIC, ZN, ZN);
        			  yyval->sl = seqlist(close_seq(3), 0);
				  yyval->ln = yyvsp[-5]->ln;
				  yyval->fn = yyvsp[-5]->fn;
				  make_atomic(yyval->sl->this, 0);
        			}
#line 3429 "y.tab.c"
    break;

  case 155:
#line 735 "spin.y"
                                { open_seq(0);
				  rem_Seq();
				}
#line 3437 "y.tab.c"
    break;

  case 156:
#line 738 "spin.y"
                                { yyval = nn(yyvsp[-5], D_STEP, ZN, ZN);
        			  yyval->sl = seqlist(close_seq(4), 0);
				  yyval->ln = yyvsp[-5]->ln;
				  yyval->fn = yyvsp[-5]->fn;
        			  make_atomic(yyval->sl->this, D_ATOM);
				  unrem_Seq();
        			}
#line 3449 "y.tab.c"
    break;

  case 157:
#line 745 "spin.y"
                                { open_seq(0); }
#line 3455 "y.tab.c"
    break;

  case 158:
#line 746 "spin.y"
                                { yyval = nn(ZN, NON_ATOMIC, ZN, ZN);
        			  yyval->sl = seqlist(close_seq(5), 0);
				  yyval->ln = yyvsp[-4]->ln;
				  yyval->fn = yyvsp[-4]->fn;
        			}
#line 3465 "y.tab.c"
    break;

  case 159:
#line 751 "spin.y"
                                { IArgs++; }
#line 3471 "y.tab.c"
    break;

  case 160:
#line 752 "spin.y"
                                { initialization_ok = 0;
				  pickup_inline(yyvsp[-4]->sym, yyvsp[-1], ZN);
				  IArgs--;
				}
#line 3480 "y.tab.c"
    break;

  case 161:
#line 756 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3486 "y.tab.c"
    break;

  case 162:
#line 758 "spin.y"
                                { IArgs++; /* inline call */ }
#line 3492 "y.tab.c"
    break;

  case 163:
#line 759 "spin.y"
                                { initialization_ok = 0;
				  pickup_inline(yyvsp[-4]->sym, yyvsp[-1], yyvsp[-6]);
				  IArgs--;
				}
#line 3501 "y.tab.c"
    break;

  case 164:
#line 763 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3507 "y.tab.c"
    break;

  case 165:
#line 764 "spin.y"
                                { yyval = return_statement(yyvsp[0]); }
#line 3513 "y.tab.c"
    break;

  case 166:
#line 767 "spin.y"
                                { yyval->sl = seqlist(yyvsp[0]->sq, 0); }
#line 3519 "y.tab.c"
    break;

  case 167:
#line 768 "spin.y"
                                { yyval->sl = seqlist(yyvsp[-1]->sq, yyvsp[0]->sl); }
#line 3525 "y.tab.c"
    break;

  case 168:
#line 771 "spin.y"
                                { open_seq(0); }
#line 3531 "y.tab.c"
    break;

  case 169:
#line 772 "spin.y"
                                { yyval = nn(ZN,0,ZN,ZN);
				  yyval->sq = close_seq(6);
				  yyval->ln = yyvsp[-3]->ln;
				  yyval->fn = yyvsp[-3]->fn;
				}
#line 3541 "y.tab.c"
    break;

  case 171:
#line 780 "spin.y"
                                { /* redundant semi at end of sequence */ }
#line 3547 "y.tab.c"
    break;

  case 174:
#line 787 "spin.y"
                                { /* at least one semi-colon */ }
#line 3553 "y.tab.c"
    break;

  case 175:
#line 788 "spin.y"
                                { /* but more are okay too   */ }
#line 3559 "y.tab.c"
    break;

  case 176:
#line 791 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3565 "y.tab.c"
    break;

  case 177:
#line 792 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3571 "y.tab.c"
    break;

  case 178:
#line 795 "spin.y"
                                        { yyval = yyvsp[0]; }
#line 3577 "y.tab.c"
    break;

  case 179:
#line 796 "spin.y"
                                        { yyval = yyvsp[0]; yyval->val = -(yyvsp[0]->val); }
#line 3583 "y.tab.c"
    break;

  case 180:
#line 797 "spin.y"
                                                { yyval = yyvsp[-1]; }
#line 3589 "y.tab.c"
    break;

  case 181:
#line 798 "spin.y"
                                        { yyval = yyvsp[-2]; yyval->val = yyvsp[-2]->val + yyvsp[0]->val; }
#line 3595 "y.tab.c"
    break;

  case 182:
#line 799 "spin.y"
                                        { yyval = yyvsp[-2]; yyval->val = yyvsp[-2]->val - yyvsp[0]->val; }
#line 3601 "y.tab.c"
    break;

  case 183:
#line 800 "spin.y"
                                        { yyval = yyvsp[-2]; yyval->val = yyvsp[-2]->val * yyvsp[0]->val; }
#line 3607 "y.tab.c"
    break;

  case 184:
#line 801 "spin.y"
                                        { yyval = yyvsp[-2];
					  if (yyvsp[0]->val == 0)
					  { fatal("division by zero", (char *) 0);
					  }
					  yyval->val = yyvsp[-2]->val / yyvsp[0]->val;
					}
#line 3618 "y.tab.c"
    break;

  case 185:
#line 807 "spin.y"
                                        { yyval = yyvsp[-2];
					  if (yyvsp[0]->val == 0)
					  { fatal("attempt to take modulo of zero", (char *) 0);
					  }
					  yyval->val = yyvsp[-2]->val % yyvsp[0]->val;
					}
#line 3629 "y.tab.c"
    break;

  case 186:
#line 815 "spin.y"
                                        { yyval = yyvsp[-1]; }
#line 3635 "y.tab.c"
    break;

  case 187:
#line 816 "spin.y"
                                { yyval = nn(ZN, '+', yyvsp[-2], yyvsp[0]); }
#line 3641 "y.tab.c"
    break;

  case 188:
#line 817 "spin.y"
                                { yyval = nn(ZN, '-', yyvsp[-2], yyvsp[0]); }
#line 3647 "y.tab.c"
    break;

  case 189:
#line 818 "spin.y"
                                { yyval = nn(ZN, '*', yyvsp[-2], yyvsp[0]); }
#line 3653 "y.tab.c"
    break;

  case 190:
#line 819 "spin.y"
                                { yyval = nn(ZN, '/', yyvsp[-2], yyvsp[0]); }
#line 3659 "y.tab.c"
    break;

  case 191:
#line 820 "spin.y"
                                { yyval = nn(ZN, '%', yyvsp[-2], yyvsp[0]); }
#line 3665 "y.tab.c"
    break;

  case 192:
#line 821 "spin.y"
                                { yyval = nn(ZN, '&', yyvsp[-2], yyvsp[0]); }
#line 3671 "y.tab.c"
    break;

  case 193:
#line 822 "spin.y"
                                { yyval = nn(ZN, '^', yyvsp[-2], yyvsp[0]); }
#line 3677 "y.tab.c"
    break;

  case 194:
#line 823 "spin.y"
                                { yyval = nn(ZN, '|', yyvsp[-2], yyvsp[0]); }
#line 3683 "y.tab.c"
    break;

  case 195:
#line 824 "spin.y"
                                { yyval = nn(ZN,  GT, yyvsp[-2], yyvsp[0]); }
#line 3689 "y.tab.c"
    break;

  case 196:
#line 825 "spin.y"
                                { yyval = nn(ZN,  LT, yyvsp[-2], yyvsp[0]); }
#line 3695 "y.tab.c"
    break;

  case 197:
#line 826 "spin.y"
                                { yyval = nn(ZN,  GE, yyvsp[-2], yyvsp[0]); }
#line 3701 "y.tab.c"
    break;

  case 198:
#line 827 "spin.y"
                                { yyval = nn(ZN,  LE, yyvsp[-2], yyvsp[0]); }
#line 3707 "y.tab.c"
    break;

  case 199:
#line 828 "spin.y"
                                { yyval = nn(ZN,  EQ, yyvsp[-2], yyvsp[0]); }
#line 3713 "y.tab.c"
    break;

  case 200:
#line 829 "spin.y"
                                { yyval = nn(ZN,  NE, yyvsp[-2], yyvsp[0]); }
#line 3719 "y.tab.c"
    break;

  case 201:
#line 830 "spin.y"
                                { yyval = nn(ZN, AND, yyvsp[-2], yyvsp[0]); }
#line 3725 "y.tab.c"
    break;

  case 202:
#line 831 "spin.y"
                                { yyval = nn(ZN,  OR, yyvsp[-2], yyvsp[0]); }
#line 3731 "y.tab.c"
    break;

  case 203:
#line 832 "spin.y"
                                { yyval = nn(ZN, LSHIFT,yyvsp[-2], yyvsp[0]); }
#line 3737 "y.tab.c"
    break;

  case 204:
#line 833 "spin.y"
                                { yyval = nn(ZN, RSHIFT,yyvsp[-2], yyvsp[0]); }
#line 3743 "y.tab.c"
    break;

  case 205:
#line 834 "spin.y"
                                { yyval = nn(ZN, '~', yyvsp[0], ZN); }
#line 3749 "y.tab.c"
    break;

  case 206:
#line 835 "spin.y"
                                { yyval = nn(ZN, UMIN, yyvsp[0], ZN); }
#line 3755 "y.tab.c"
    break;

  case 207:
#line 836 "spin.y"
                                { yyval = nn(ZN, '!', yyvsp[0], ZN); }
#line 3761 "y.tab.c"
    break;

  case 208:
#line 838 "spin.y"
                                               {
				  yyval = nn(ZN,  OR, yyvsp[-3], yyvsp[-1]);
				  yyval = nn(ZN, '?', yyvsp[-5], yyval);
				}
#line 3770 "y.tab.c"
    break;

  case 209:
#line 843 "spin.y"
                                { Expand_Ok++;
				  if (!context)
				   fatal("used 'run' outside proctype", (char *) 0);
				}
#line 3779 "y.tab.c"
    break;

  case 210:
#line 848 "spin.y"
                                { Expand_Ok--;
				  yyval = nn(yyvsp[-5], RUN, yyvsp[-2], ZN);
				  yyval->val = (yyvsp[0]) ? yyvsp[0]->val : 0;
				  trackchanuse(yyvsp[-2], yyvsp[-5], 'A'); trackrun(yyval);
				}
#line 3789 "y.tab.c"
    break;

  case 211:
#line 853 "spin.y"
                                        { yyval = nn(yyvsp[-1], LEN, yyvsp[-1], ZN); }
#line 3795 "y.tab.c"
    break;

  case 212:
#line 854 "spin.y"
                                        { yyval = nn(ZN, ENABLED, yyvsp[-1], ZN); has_enabled++; }
#line 3801 "y.tab.c"
    break;

  case 213:
#line 855 "spin.y"
                                        { yyval = nn(ZN, GET_P, yyvsp[-1], ZN); has_priority++; }
#line 3807 "y.tab.c"
    break;

  case 214:
#line 856 "spin.y"
                                { Expand_Ok++; }
#line 3813 "y.tab.c"
    break;

  case 215:
#line 857 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-5], 'R', yyvsp[-5], yyvsp[-1]);
				}
#line 3821 "y.tab.c"
    break;

  case 216:
#line 860 "spin.y"
                                { Expand_Ok++; }
#line 3827 "y.tab.c"
    break;

  case 217:
#line 861 "spin.y"
                                { Expand_Ok--; has_io++;
				  yyval = nn(yyvsp[-5], 'R', yyvsp[-5], yyvsp[-1]);
				  yyval->val = has_random = 1;
				}
#line 3836 "y.tab.c"
    break;

  case 218:
#line 865 "spin.y"
                                { yyval = yyvsp[0]; trapwonly(yyvsp[0] /*, "varref" */); }
#line 3842 "y.tab.c"
    break;

  case 219:
#line 866 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3848 "y.tab.c"
    break;

  case 220:
#line 867 "spin.y"
                                { yyval = nn(ZN,CONST,ZN,ZN);
				  yyval->ismtyp = yyvsp[0]->ismtyp;
				  yyval->sym = yyvsp[0]->sym;
				  yyval->val = yyvsp[0]->val;
				}
#line 3858 "y.tab.c"
    break;

  case 221:
#line 872 "spin.y"
                                { yyval = nn(ZN,TIMEOUT, ZN, ZN); }
#line 3864 "y.tab.c"
    break;

  case 222:
#line 873 "spin.y"
                                { yyval = nn(ZN,NONPROGRESS, ZN, ZN);
				  has_np++;
				}
#line 3872 "y.tab.c"
    break;

  case 223:
#line 876 "spin.y"
                                        { yyval = nn(ZN, PC_VAL, yyvsp[-1], ZN);
				  has_pcvalue++;
				}
#line 3880 "y.tab.c"
    break;

  case 224:
#line 880 "spin.y"
                                { yyval = rem_lab(yyvsp[-5]->sym, yyvsp[-3], yyvsp[0]->sym); }
#line 3886 "y.tab.c"
    break;

  case 225:
#line 882 "spin.y"
                                { yyval = rem_var(yyvsp[-5]->sym, yyvsp[-3], yyvsp[0]->sym, yyvsp[0]->lft); }
#line 3892 "y.tab.c"
    break;

  case 226:
#line 883 "spin.y"
                                { yyval = rem_lab(yyvsp[-2]->sym, ZN, yyvsp[0]->sym); }
#line 3898 "y.tab.c"
    break;

  case 227:
#line 884 "spin.y"
                                { yyval = rem_var(yyvsp[-2]->sym, ZN, yyvsp[0]->sym, yyvsp[0]->lft); }
#line 3904 "y.tab.c"
    break;

  case 228:
#line 885 "spin.y"
                                { yyval = yyvsp[0]; /* sanity_check($1); */ }
#line 3910 "y.tab.c"
    break;

  case 229:
#line 888 "spin.y"
                                { yyval = ZN; }
#line 3916 "y.tab.c"
    break;

  case 230:
#line 889 "spin.y"
                                { yyval = yyvsp[0]; has_priority++; }
#line 3922 "y.tab.c"
    break;

  case 231:
#line 892 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3928 "y.tab.c"
    break;

  case 232:
#line 893 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3934 "y.tab.c"
    break;

  case 233:
#line 896 "spin.y"
                                { yyval = nn(ZN, UNTIL,   yyvsp[-2], yyvsp[0]); }
#line 3940 "y.tab.c"
    break;

  case 234:
#line 897 "spin.y"
                                { yyval = nn(ZN, RELEASE, yyvsp[-2], yyvsp[0]); }
#line 3946 "y.tab.c"
    break;

  case 235:
#line 898 "spin.y"
                                { yyval = nn(ZN, ALWAYS, yyvsp[-2], ZN);
				  yyval = nn(ZN, OR, yyval, nn(ZN, UNTIL, yyvsp[-2], yyvsp[0]));
				}
#line 3954 "y.tab.c"
    break;

  case 236:
#line 901 "spin.y"
                                { yyval = nn(ZN, '!', yyvsp[-2], ZN);
				  yyval = nn(ZN, OR,  yyval, yyvsp[0]);
				}
#line 3962 "y.tab.c"
    break;

  case 237:
#line 904 "spin.y"
                                { yyval = nn(ZN, EQUIV,   yyvsp[-2], yyvsp[0]); }
#line 3968 "y.tab.c"
    break;

  case 238:
#line 905 "spin.y"
                                    { yyval = nn(ZN, NEXT,  yyvsp[0], ZN); }
#line 3974 "y.tab.c"
    break;

  case 239:
#line 906 "spin.y"
                                    { yyval = nn(ZN, ALWAYS,yyvsp[0], ZN); }
#line 3980 "y.tab.c"
    break;

  case 240:
#line 907 "spin.y"
                                    { yyval = nn(ZN, EVENTUALLY, yyvsp[0], ZN); }
#line 3986 "y.tab.c"
    break;

  case 241:
#line 911 "spin.y"
                                { yyval = yyvsp[0]; }
#line 3992 "y.tab.c"
    break;

  case 242:
#line 912 "spin.y"
                                { yyval = yyvsp[-1]; }
#line 3998 "y.tab.c"
    break;

  case 243:
#line 913 "spin.y"
                                { yyval = nn(ZN, AND, yyvsp[-2], yyvsp[0]); }
#line 4004 "y.tab.c"
    break;

  case 244:
#line 914 "spin.y"
                                { yyval = nn(ZN, AND, yyvsp[-2], yyvsp[0]); }
#line 4010 "y.tab.c"
    break;

  case 245:
#line 915 "spin.y"
                                { yyval = nn(ZN, AND, yyvsp[-2], yyvsp[0]); }
#line 4016 "y.tab.c"
    break;

  case 246:
#line 916 "spin.y"
                                { yyval = nn(ZN,  OR, yyvsp[-2], yyvsp[0]); }
#line 4022 "y.tab.c"
    break;

  case 247:
#line 917 "spin.y"
                                { yyval = nn(ZN,  OR, yyvsp[-2], yyvsp[0]); }
#line 4028 "y.tab.c"
    break;

  case 248:
#line 918 "spin.y"
                                { yyval = nn(ZN,  OR, yyvsp[-2], yyvsp[0]); }
#line 4034 "y.tab.c"
    break;

  case 249:
#line 921 "spin.y"
                                        { yyval = nn(yyvsp[-1],  FULL, yyvsp[-1], ZN); }
#line 4040 "y.tab.c"
    break;

  case 250:
#line 922 "spin.y"
                                        { yyval = nn(yyvsp[-1], NFULL, yyvsp[-1], ZN); }
#line 4046 "y.tab.c"
    break;

  case 251:
#line 923 "spin.y"
                                        { yyval = nn(yyvsp[-1], EMPTY, yyvsp[-1], ZN); }
#line 4052 "y.tab.c"
    break;

  case 252:
#line 924 "spin.y"
                                        { yyval = nn(yyvsp[-1],NEMPTY, yyvsp[-1], ZN); }
#line 4058 "y.tab.c"
    break;

  case 253:
#line 927 "spin.y"
                                { yyval = ZN; }
#line 4064 "y.tab.c"
    break;

  case 254:
#line 928 "spin.y"
                                         {
				   if (!proper_enabler(yyvsp[-1]))
				   { non_fatal("invalid PROVIDED clause", (char *)0);
				     yyval = ZN;
				   } else
				   { yyval = yyvsp[-1];
				 } }
#line 4076 "y.tab.c"
    break;

  case 255:
#line 935 "spin.y"
                                 { yyval = ZN;
				   non_fatal("usage: provided ( ..expr.. )", (char *)0);
				 }
#line 4084 "y.tab.c"
    break;

  case 256:
#line 940 "spin.y"
                                { yyval = ZN; }
#line 4090 "y.tab.c"
    break;

  case 257:
#line 941 "spin.y"
                                { yyval = yyvsp[0]; }
#line 4096 "y.tab.c"
    break;

  case 258:
#line 944 "spin.y"
                                { if (yyvsp[0])
				  {	if (yyvsp[-1]->val != MTYPE)
					{	explain(yyvsp[-1]->val);
						fatal("unexpected type", (char *) 0);
				  }	}
				  yyval->sym = yyvsp[0] ? yyvsp[0]->sym : ZS;
				  yyval->val = yyvsp[-1]->val;
				  if (yyval->val == UNSIGNED)
				  fatal("unsigned cannot be used as mesg type", 0);
				}
#line 4111 "y.tab.c"
    break;

  case 259:
#line 954 "spin.y"
                                { yyval->sym = yyvsp[0]->sym;
				  yyval->val = STRUCT;
				}
#line 4119 "y.tab.c"
    break;

  case 261:
#line 960 "spin.y"
                                { yyval = nn(yyvsp[0], yyvsp[0]->val, ZN, ZN); }
#line 4125 "y.tab.c"
    break;

  case 262:
#line 961 "spin.y"
                                { yyval = nn(yyvsp[-2], yyvsp[-2]->val, ZN, yyvsp[0]); }
#line 4131 "y.tab.c"
    break;

  case 263:
#line 964 "spin.y"
                                { yyval = nn(ZN, ',', yyvsp[-2], yyvsp[0]); }
#line 4137 "y.tab.c"
    break;

  case 264:
#line 967 "spin.y"
                                { yyval = ZN; }
#line 4143 "y.tab.c"
    break;

  case 265:
#line 968 "spin.y"
                                { yyval = yyvsp[0]; }
#line 4149 "y.tab.c"
    break;

  case 266:
#line 971 "spin.y"
                                { yyval = ZN; }
#line 4155 "y.tab.c"
    break;

  case 267:
#line 972 "spin.y"
                                { yyval = yyvsp[0]; }
#line 4161 "y.tab.c"
    break;

  case 268:
#line 975 "spin.y"
                                { yyval = yyvsp[0]; }
#line 4167 "y.tab.c"
    break;

  case 269:
#line 976 "spin.y"
                                { if (yyvsp[-3]->ntyp == ',')
					yyval = tail_add(yyvsp[-3], yyvsp[-1]);
				  else
				  	yyval = nn(ZN, ',', yyvsp[-3], yyvsp[-1]);
				}
#line 4177 "y.tab.c"
    break;

  case 270:
#line 983 "spin.y"
                                { if (yyvsp[0]->ntyp == ',')
					yyval = yyvsp[0];
				  else
				  	yyval = nn(ZN, ',', yyvsp[0], ZN);
				}
#line 4187 "y.tab.c"
    break;

  case 271:
#line 988 "spin.y"
                                { if (yyvsp[-2]->ntyp == ',')
					yyval = tail_add(yyvsp[-2], yyvsp[0]);
				  else
				  	yyval = nn(ZN, ',', yyvsp[-2], yyvsp[0]);
				}
#line 4197 "y.tab.c"
    break;

  case 272:
#line 995 "spin.y"
                                { yyval = yyvsp[0]; trackvar(yyvsp[0], yyvsp[0]);
				  trapwonly(yyvsp[0] /*, "rarg" */); }
#line 4204 "y.tab.c"
    break;

  case 273:
#line 997 "spin.y"
                                { yyval = nn(ZN,EVAL,yyvsp[-1],ZN);
				  trapwonly(yyvsp[-3] /*, "eval rarg" */); }
#line 4211 "y.tab.c"
    break;

  case 274:
#line 999 "spin.y"
                                { yyval = nn(ZN,CONST,ZN,ZN);
				  yyval->ismtyp = yyvsp[0]->ismtyp;
				  yyval->sym = yyvsp[0]->sym;
				  yyval->val = yyvsp[0]->val;
				}
#line 4221 "y.tab.c"
    break;

  case 275:
#line 1004 "spin.y"
                                { yyval = nn(ZN,CONST,ZN,ZN);
				  yyval->val = - (yyvsp[0]->val);
				}
#line 4229 "y.tab.c"
    break;

  case 276:
#line 1009 "spin.y"
                                { if (yyvsp[0]->ntyp == ',')
					yyval = yyvsp[0];
				  else
				  	yyval = nn(ZN, ',', yyvsp[0], ZN);
				}
#line 4239 "y.tab.c"
    break;

  case 277:
#line 1014 "spin.y"
                                { if (yyvsp[-2]->ntyp == ',')
					yyval = tail_add(yyvsp[-2], yyvsp[0]);
				  else
				  	yyval = nn(ZN, ',', yyvsp[-2], yyvsp[0]);
				}
#line 4249 "y.tab.c"
    break;

  case 278:
#line 1019 "spin.y"
                                        { if (yyvsp[-3]->ntyp == ',')
					yyval = tail_add(yyvsp[-3], yyvsp[-1]);
				  else
				  	yyval = nn(ZN, ',', yyvsp[-3], yyvsp[-1]);
				}
#line 4259 "y.tab.c"
    break;

  case 279:
#line 1024 "spin.y"
                                        { yyval = yyvsp[-1]; }
#line 4265 "y.tab.c"
    break;

  case 280:
#line 1027 "spin.y"
                                { yyval = nn(yyvsp[0], NAME, ZN, ZN);
				  yyval = nn(ZN, ',', yyval, ZN); }
#line 4272 "y.tab.c"
    break;

  case 281:
#line 1029 "spin.y"
                                { yyval = nn(yyvsp[0], NAME, ZN, ZN);
				  yyval = nn(ZN, ',', yyval, yyvsp[-1]);
				}
#line 4280 "y.tab.c"
    break;

  case 282:
#line 1032 "spin.y"
                                { yyval = yyvsp[-1]; /* commas optional */ }
#line 4286 "y.tab.c"
    break;


#line 4290 "y.tab.c"

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
#line 1034 "spin.y"


#define binop(n, sop)	fprintf(fd, "("); recursive(fd, n->lft); \
			fprintf(fd, ") %s (", sop); recursive(fd, n->rgt); \
			fprintf(fd, ")");
#define unop(n, sop)	fprintf(fd, "%s (", sop); recursive(fd, n->lft); \
			fprintf(fd, ")");

static void
recursive(FILE *fd, Lextok *n)
{
	if (n)
	switch (n->ntyp) {
	case NEXT:
		unop(n, "X");
		break;
	case ALWAYS:
		unop(n, "[]");
		break;
	case EVENTUALLY:
		unop(n, "<>");
		break;
	case '!':
		unop(n, "!");
		break;
	case UNTIL:
		binop(n, "U");
		break;
	case WEAK_UNTIL:
		binop(n, "W");
		break;
	case RELEASE: /* see http://en.wikipedia.org/wiki/Linear_temporal_logic */
		binop(n, "V");
		break;
	case OR:
		binop(n, "||");
		break;
	case AND:
		binop(n, "&&");
		break;
	case IMPLIES:
		binop(n, "->");
		break;
	case EQUIV:
		binop(n, "<->");
		break;
	case C_EXPR:
		fprintf(fd, "c_expr { %s }", put_inline(fd, n->sym->name));
		break;
	default:
		comment(fd, n, 0);
		break;
	}
}

#ifdef __MINGW32__
extern ssize_t getline(char **, size_t *, FILE *); /* see main.c */
#endif

static Lextok *
ltl_to_string(Lextok *n)
{	Lextok *m = nn(ZN, 0, ZN, ZN);
	ssize_t retval;
	char *ltl_formula = NULL;
	FILE *tf = fopen(TMP_FILE1, "w+"); /* tmpfile() fails on Windows 7 */

	/* convert the parsed ltl to a string
	   by writing into a file, using existing functions,
	   and then passing it to the existing interface for
	   conversion into a never claim
	  (this means parsing everything twice, which is
	   a little redundant, but adds only miniscule overhead)
	 */

	if (!tf)
	{	fatal("cannot create temporary file", (char *) 0);
	}
	dont_simplify = 1;
	recursive(tf, n);
	dont_simplify = 0;
	(void) fseek(tf, 0L, SEEK_SET);

	size_t linebuffsize = 0;
	retval = getline(&ltl_formula, &linebuffsize, tf);
	fclose(tf);

	(void) unlink(TMP_FILE1);

	if (!retval)
	{	printf("%ld\n", (long int) retval);
		fatal("could not translate ltl ltl_formula", 0);
	}

	if (1) printf("ltl %s: %s\n", ltl_name, ltl_formula);

	m->sym = lookup(ltl_formula);
#ifndef __MINGW32__
	free(ltl_formula);
#endif
	return m;
}

int
is_temporal(int t)
{
	return (t == EVENTUALLY || t == ALWAYS || t == UNTIL
	     || t == WEAK_UNTIL || t == RELEASE);
}

int
is_boolean(int t)
{
	return (t == AND || t == OR || t == IMPLIES || t == EQUIV);
}

#if 0
/* flags correct formula like: ltl { true U (true U true) } */
void
sanity_check(Lextok *t)	/* check proper embedding of ltl_expr */
{
	if (!t) return;
	sanity_check(t->lft);
	sanity_check(t->rgt);

	if (t->lft && t->rgt)
	{	if (!is_boolean(t->ntyp)
		&&  (is_temporal(t->lft->ntyp)
		||   is_temporal(t->rgt->ntyp)))
		{	printf("spin: attempt to apply '");
			explain(t->ntyp);
			printf("' to '");
			explain(t->lft->ntyp);
			printf("' and '");
			explain(t->rgt->ntyp);
			printf("'\n");
	/*		non_fatal("missing parentheses?", (char *)0); */
	}	}
}
#endif

void
yyerror(char *fmt, ...)
{
	non_fatal(fmt, (char *) 0);
}
