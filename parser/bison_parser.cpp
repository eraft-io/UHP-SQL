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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs

/* First part of user prologue.  */
#line 2 "bison_parser.y"

  // clang-format on
  /**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
  /*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>

  using namespace hsql;

  int yyerror(YYLTYPE * llocp, SQLParserResult * result, yyscan_t scanner, const char* msg) {
    result->setIsValid(false);
    result->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);
    return 0;
  }
  // clang-format off

#line 107 "bison_parser.cpp"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 38 "bison_parser.y"

  // clang-format on
  // %code requires block

#include "sql_parser_result.h"
#include "statements.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION                        \
  yylloc->first_line = yylloc->last_line;     \
  yylloc->first_column = yylloc->last_column; \
  for (int i = 0; yytext[i] != '\0'; i++) {   \
    yylloc->total_column++;                   \
    yylloc->string_length++;                  \
    if (yytext[i] == '\n') {                  \
      yylloc->last_line++;                    \
      yylloc->last_column = 0;                \
    } else {                                  \
      yylloc->last_column++;                  \
    }                                         \
  }

#line 182 "bison_parser.cpp"

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_DEALLOCATE = 262,
    SQL_PARAMETERS = 263,
    SQL_INTERSECT = 264,
    SQL_TEMPORARY = 265,
    SQL_TIMESTAMP = 266,
    SQL_DISTINCT = 267,
    SQL_NVARCHAR = 268,
    SQL_RESTRICT = 269,
    SQL_TRUNCATE = 270,
    SQL_ANALYZE = 271,
    SQL_BETWEEN = 272,
    SQL_CASCADE = 273,
    SQL_COLUMNS = 274,
    SQL_CONTROL = 275,
    SQL_DEFAULT = 276,
    SQL_EXECUTE = 277,
    SQL_EXPLAIN = 278,
    SQL_INTEGER = 279,
    SQL_NATURAL = 280,
    SQL_PREPARE = 281,
    SQL_PRIMARY = 282,
    SQL_SCHEMAS = 283,
    SQL_CHARACTER = 284,
    SQL_VARYING = 285,
    SQL_REAL = 286,
    SQL_DECIMAL = 287,
    SQL_SPATIAL = 288,
    SQL_VARCHAR = 289,
    SQL_VIRTUAL = 290,
    SQL_DESCRIBE = 291,
    SQL_BEFORE = 292,
    SQL_COLUMN = 293,
    SQL_CREATE = 294,
    SQL_DELETE = 295,
    SQL_DIRECT = 296,
    SQL_DOUBLE = 297,
    SQL_ESCAPE = 298,
    SQL_EXCEPT = 299,
    SQL_EXISTS = 300,
    SQL_EXTRACT = 301,
    SQL_CAST = 302,
    SQL_FORMAT = 303,
    SQL_GLOBAL = 304,
    SQL_HAVING = 305,
    SQL_IMPORT = 306,
    SQL_INSERT = 307,
    SQL_ISNULL = 308,
    SQL_OFFSET = 309,
    SQL_RENAME = 310,
    SQL_SCHEMA = 311,
    SQL_SELECT = 312,
    SQL_SORTED = 313,
    SQL_TABLES = 314,
    SQL_UNIQUE = 315,
    SQL_UNLOAD = 316,
    SQL_UPDATE = 317,
    SQL_VALUES = 318,
    SQL_AFTER = 319,
    SQL_ALTER = 320,
    SQL_CROSS = 321,
    SQL_DELTA = 322,
    SQL_FLOAT = 323,
    SQL_GROUP = 324,
    SQL_INDEX = 325,
    SQL_INNER = 326,
    SQL_LIMIT = 327,
    SQL_LOCAL = 328,
    SQL_MERGE = 329,
    SQL_MINUS = 330,
    SQL_ORDER = 331,
    SQL_OUTER = 332,
    SQL_RIGHT = 333,
    SQL_TABLE = 334,
    SQL_UNION = 335,
    SQL_USING = 336,
    SQL_WHERE = 337,
    SQL_CALL = 338,
    SQL_CASE = 339,
    SQL_CHAR = 340,
    SQL_COPY = 341,
    SQL_DATE = 342,
    SQL_DATETIME = 343,
    SQL_DESC = 344,
    SQL_DROP = 345,
    SQL_ELSE = 346,
    SQL_FILE = 347,
    SQL_FROM = 348,
    SQL_FULL = 349,
    SQL_HASH = 350,
    SQL_HINT = 351,
    SQL_INTO = 352,
    SQL_JOIN = 353,
    SQL_LEFT = 354,
    SQL_LIKE = 355,
    SQL_LOAD = 356,
    SQL_LONG = 357,
    SQL_NULL = 358,
    SQL_PLAN = 359,
    SQL_SHOW = 360,
    SQL_TEXT = 361,
    SQL_THEN = 362,
    SQL_TIME = 363,
    SQL_VIEW = 364,
    SQL_WHEN = 365,
    SQL_WITH = 366,
    SQL_ADD = 367,
    SQL_ALL = 368,
    SQL_AND = 369,
    SQL_ASC = 370,
    SQL_END = 371,
    SQL_FOR = 372,
    SQL_INT = 373,
    SQL_KEY = 374,
    SQL_NOT = 375,
    SQL_OFF = 376,
    SQL_SET = 377,
    SQL_TOP = 378,
    SQL_AS = 379,
    SQL_BY = 380,
    SQL_IF = 381,
    SQL_IN = 382,
    SQL_IS = 383,
    SQL_OF = 384,
    SQL_ON = 385,
    SQL_OR = 386,
    SQL_TO = 387,
    SQL_ARRAY = 388,
    SQL_CONCAT = 389,
    SQL_ILIKE = 390,
    SQL_SECOND = 391,
    SQL_MINUTE = 392,
    SQL_HOUR = 393,
    SQL_DAY = 394,
    SQL_MONTH = 395,
    SQL_YEAR = 396,
    SQL_SECONDS = 397,
    SQL_MINUTES = 398,
    SQL_HOURS = 399,
    SQL_DAYS = 400,
    SQL_MONTHS = 401,
    SQL_YEARS = 402,
    SQL_INTERVAL = 403,
    SQL_TRUE = 404,
    SQL_FALSE = 405,
    SQL_TRANSACTION = 406,
    SQL_BEGIN = 407,
    SQL_COMMIT = 408,
    SQL_ROLLBACK = 409,
    SQL_EQUALS = 410,
    SQL_NOTEQUALS = 411,
    SQL_LESS = 412,
    SQL_GREATER = 413,
    SQL_LESSEQ = 414,
    SQL_GREATEREQ = 415,
    SQL_NOTNULL = 416,
    SQL_UMINUS = 417
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED
union HSQL_STYPE
{
#line 98 "bison_parser.y"

  // clang-format on
  bool bval;
  char* sval;
  double fval;
  int64_t ival;
  uintmax_t uval;

  // statements
  hsql::AlterStatement* alter_stmt;
  hsql::CreateStatement* create_stmt;
  hsql::DeleteStatement* delete_stmt;
  hsql::DropStatement* drop_stmt;
  hsql::ExecuteStatement* exec_stmt;
  hsql::ExportStatement* export_stmt;
  hsql::ImportStatement* import_stmt;
  hsql::InsertStatement* insert_stmt;
  hsql::PrepareStatement* prep_stmt;
  hsql::SelectStatement* select_stmt;
  hsql::ShowStatement* show_stmt;
  hsql::SQLStatement* statement;
  hsql::TransactionStatement* transaction_stmt;
  hsql::UpdateStatement* update_stmt;

  hsql::Alias* alias_t;
  hsql::AlterAction* alter_action_t;
  hsql::ColumnDefinition* column_t;
  hsql::ColumnSpecification column_specification_t;
  hsql::ColumnType column_type_t;
  hsql::ConstraintType column_constraint_t;
  hsql::DatetimeField datetime_field;
  hsql::DropColumnAction* drop_action_t;
  hsql::Expr* expr;
  hsql::GroupByDescription* group_t;
  hsql::ImportType import_type_t;
  hsql::JoinType join_type;
  hsql::LimitDescription* limit;
  hsql::OrderDescription* order;
  hsql::OrderType order_type;
  hsql::SetOperation* set_operator_t;
  hsql::TableConstraint* table_constraint_t;
  hsql::TableElement* table_element_t;
  hsql::TableName table_name;
  hsql::TableRef* table;
  hsql::UpdateClause* update_t;
  hsql::WithDescription* with_description_t;

  std::vector<char*>* str_vec;
  std::vector<hsql::ConstraintType>* column_constraint_vec;
  std::vector<hsql::Expr*>* expr_vec;
  std::vector<hsql::OrderDescription*>* order_vec;
  std::vector<hsql::SQLStatement*>* stmt_vec;
  std::vector<hsql::TableElement*>* table_element_vec;
  std::vector<hsql::TableRef*>* table_vec;
  std::vector<hsql::UpdateClause*>* update_vec;
  std::vector<hsql::WithDescription*>* with_description_vec;

#line 414 "bison_parser.cpp"

};
typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult* result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */



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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   886

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  180
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  302
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  549

#define YYUNDEFTOK  2
#define YYMAXUTOK   417


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   169,     2,     2,
     174,   175,   167,   165,   178,   166,   176,   168,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   177,
     158,   155,   159,   179,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   172,     2,   173,   170,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   160,   161,   162,   163,   164,   171
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   293,   293,   312,   318,   325,   329,   333,   334,   335,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     352,   353,   355,   359,   364,   368,   378,   379,   380,   382,
     382,   388,   394,   396,   400,   411,   417,   424,   439,   444,
     445,   451,   463,   464,   469,   480,   493,   501,   508,   515,
     524,   525,   527,   531,   536,   537,   539,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   559,   560,   562,   563,   564,   566,   567,   569,   573,
     578,   579,   580,   581,   583,   584,   592,   598,   604,   610,
     616,   617,   624,   630,   632,   642,   649,   660,   667,   675,
     676,   683,   690,   694,   699,   709,   713,   717,   729,   729,
     731,   732,   741,   742,   744,   754,   765,   770,   774,   778,
     783,   784,   786,   796,   797,   799,   801,   802,   804,   806,
     807,   809,   814,   816,   817,   819,   820,   822,   826,   831,
     833,   834,   835,   839,   840,   842,   843,   844,   845,   846,
     847,   852,   856,   861,   862,   864,   868,   873,   881,   881,
     881,   881,   881,   883,   884,   884,   884,   884,   884,   884,
     884,   884,   885,   885,   889,   889,   891,   892,   893,   894,
     895,   897,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   908,   909,   911,   912,   913,   914,   918,   919,
     920,   921,   923,   924,   926,   927,   929,   930,   931,   932,
     933,   934,   935,   937,   938,   940,   942,   944,   945,   946,
     947,   948,   949,   951,   952,   953,   954,   955,   956,   958,
     958,   960,   962,   964,   966,   967,   968,   969,   971,   971,
     971,   971,   971,   971,   971,   973,   975,   976,   978,   979,
     981,   983,   985,   996,  1000,  1011,  1043,  1052,  1052,  1059,
    1059,  1061,  1061,  1068,  1072,  1077,  1085,  1091,  1095,  1100,
    1101,  1103,  1103,  1105,  1105,  1107,  1108,  1110,  1110,  1116,
    1116,  1118,  1120,  1124,  1129,  1139,  1146,  1154,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1181,  1187,
    1187,  1190,  1194
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
  "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE",
  "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE",
  "EXPLAIN", "INTEGER", "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS",
  "CHARACTER", "VARYING", "REAL", "DECIMAL", "SPATIAL", "VARCHAR",
  "VIRTUAL", "DESCRIBE", "BEFORE", "COLUMN", "CREATE", "DELETE", "DIRECT",
  "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS", "EXTRACT", "CAST", "FORMAT",
  "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL", "OFFSET", "RENAME",
  "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE", "UNLOAD", "UPDATE",
  "VALUES", "AFTER", "ALTER", "CROSS", "DELTA", "FLOAT", "GROUP", "INDEX",
  "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS", "ORDER", "OUTER", "RIGHT",
  "TABLE", "UNION", "USING", "WHERE", "CALL", "CASE", "CHAR", "COPY",
  "DATE", "DATETIME", "DESC", "DROP", "ELSE", "FILE", "FROM", "FULL",
  "HASH", "HINT", "INTO", "JOIN", "LEFT", "LIKE", "LOAD", "LONG", "NULL",
  "PLAN", "SHOW", "TEXT", "THEN", "TIME", "VIEW", "WHEN", "WITH", "ADD",
  "ALL", "AND", "ASC", "END", "FOR", "INT", "KEY", "NOT", "OFF", "SET",
  "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR", "TO", "ARRAY",
  "CONCAT", "ILIKE", "SECOND", "MINUTE", "HOUR", "DAY", "MONTH", "YEAR",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "MONTHS", "YEARS", "INTERVAL",
  "TRUE", "FALSE", "TRANSACTION", "BEGIN", "COMMIT", "ROLLBACK", "'='",
  "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'",
  "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'", "','", "'?'",
  "$accept", "input", "statement_list", "statement",
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "transaction_statement", "opt_transaction_keyword", "prepare_statement",
  "prepare_target_query", "execute_statement", "import_statement",
  "file_type", "file_path", "opt_file_type", "export_statement",
  "show_statement", "create_statement", "opt_not_exists",
  "table_elem_commalist", "table_elem", "column_def", "column_type",
  "opt_time_specification", "opt_decimal_specification",
  "opt_column_constraints", "column_constraint_list", "column_constraint",
  "table_constraint", "drop_statement", "opt_exists", "alter_statement",
  "alter_action", "drop_action", "delete_statement", "truncate_statement",
  "insert_statement", "opt_column_list", "update_statement",
  "update_clause_commalist", "update_clause", "select_statement",
  "select_within_set_operation",
  "select_within_set_operation_no_parentheses", "select_with_paren",
  "select_no_paren", "set_operator", "set_type", "opt_all",
  "select_clause", "opt_distinct", "select_list", "opt_from_clause",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "opt_literal_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "case_list", "exists_expr", "comp_expr",
  "function_expr", "extract_expr", "cast_expr", "datetime_field",
  "datetime_field_plural", "duration_field", "array_expr", "array_index",
  "between_expr", "column_name", "literal", "string_literal",
  "bool_literal", "num_literal", "int_literal", "null_literal",
  "date_literal", "interval_literal", "param_expr", "table_ref",
  "table_ref_atomic", "nonjoin_table_ref_atomic", "table_ref_commalist",
  "table_ref_name", "table_ref_name_no_alias", "table_name",
  "opt_index_name", "table_alias", "opt_table_alias", "alias", "opt_alias",
  "opt_with_clause", "with_clause", "with_description_list",
  "with_description", "join_clause", "opt_join_type", "join_condition",
  "opt_semicolon", "ident_commalist", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,    61,   410,   411,    60,    62,
     412,   413,   414,   415,   416,    43,    45,    42,    47,    37,
      94,   417,    91,    93,    40,    41,    46,    59,    44,    63
};
# endif

#define YYPACT_NINF (-321)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-300)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     618,    65,    87,   127,   142,    87,   104,    68,    95,    60,
      87,   138,    87,   122,    18,   201,    51,    51,    51,   225,
      71,  -321,   126,  -321,   126,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,   -23,  -321,   246,
      74,  -321,    86,   185,  -321,   153,   153,   153,    87,   288,
      87,   170,  -321,   171,   -49,   171,   171,   171,    87,  -321,
     179,   133,  -321,  -321,  -321,  -321,  -321,  -321,   587,  -321,
     204,  -321,  -321,   189,   -23,   129,  -321,    61,  -321,   302,
      37,   314,   200,   318,    87,    87,   255,  -321,   236,   164,
     341,   308,    87,   355,   355,   358,    87,    87,  -321,   202,
     201,  -321,   214,   360,   363,   207,   219,  -321,  -321,  -321,
     -23,   290,   280,   -23,    24,  -321,  -321,  -321,  -321,   402,
    -321,   403,  -321,  -321,  -321,   233,   234,  -321,  -321,  -321,
    -321,   713,  -321,  -321,  -321,  -321,  -321,  -321,   369,  -321,
     285,   -40,   164,   326,  -321,   355,   413,    66,   262,   -46,
    -321,  -321,   328,   309,  -321,   309,  -321,  -321,  -321,  -321,
    -321,   416,  -321,  -321,   326,  -321,  -321,   345,  -321,  -321,
     129,  -321,  -321,   326,   345,   326,   160,  -321,  -321,   130,
    -321,    37,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,    87,   419,
     312,    35,   300,     8,   251,   256,   260,   230,   386,   263,
     396,  -321,   278,   -68,   449,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,   339,  -321,   121,   264,  -321,   326,   341,  -321,   399,
    -321,  -321,   391,  -321,  -321,   266,   123,  -321,   348,   269,
    -321,    19,    24,   -23,   271,  -321,   -34,    24,   -68,   397,
      17,  -321,  -321,   276,   361,  -321,   453,   335,   281,   141,
    -321,  -321,  -321,   312,     6,    12,   401,   130,   326,   326,
     109,   -43,   282,   396,   646,   326,   118,   286,   -74,   326,
     326,   396,  -321,   396,   -55,   289,   -44,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   360,    87,  -321,   457,    37,   -68,  -321,   171,
     288,    37,  -321,   416,    20,   255,  -321,   326,  -321,   459,
    -321,  -321,  -321,  -321,   326,  -321,  -321,  -321,  -321,   326,
     326,   413,   355,  -321,   434,  -321,   291,   293,  -321,  -321,
     294,  -321,  -321,  -321,  -321,   295,  -321,    22,   297,   413,
    -321,    35,  -321,  -321,   326,  -321,  -321,   303,   379,   131,
     -56,   148,   326,   326,  -321,   401,   381,    54,  -321,  -321,
    -321,   365,   593,   664,   396,   316,   278,  -321,   383,   319,
     664,   664,   664,   664,   714,   714,   714,   714,   118,   118,
      56,    56,    56,   -87,   315,  -321,  -321,   167,   491,  -321,
     168,  -321,   312,  -321,   144,  -321,   320,  -321,    28,  -321,
     427,  -321,  -321,  -321,   -68,   -68,   174,  -321,   323,   495,
    -321,   497,   498,   501,  -321,   389,  -321,  -321,   406,  -321,
      22,  -321,   413,   176,  -321,   180,  -321,   326,   453,   326,
     326,  -321,    44,    64,   336,  -321,   396,   664,   278,   337,
     182,  -321,  -321,  -321,  -321,  -321,   338,   412,  -321,  -321,
    -321,   437,   438,   440,   420,    20,   517,  -321,  -321,  -321,
     398,  -321,  -321,   516,   192,   349,   350,   351,  -321,  -321,
    -321,   199,  -321,  -321,    39,   352,   -68,   143,  -321,   326,
    -321,   646,   353,   208,  -321,  -321,    28,    20,  -321,  -321,
    -321,    20,   270,   356,   326,   357,  -321,   525,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,   -68,  -321,  -321,  -321,  -321,
      78,   413,   -24,  -321,   362,   359,   326,   209,   326,  -321,
    -321,    13,   -68,  -321,  -321,   -68,   366,   364,  -321
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    30,    30,     0,
     300,     3,    21,    19,    21,    18,     8,     9,     7,    11,
      16,    17,    13,    14,    12,    15,    10,     0,   279,     0,
     267,    96,    33,     0,    44,    51,    51,    51,     0,     0,
       0,     0,   266,    91,     0,    91,    91,    91,     0,    42,
       0,   281,   282,    29,    26,    28,    27,     1,   280,     2,
       0,     6,     5,   144,     0,   105,   106,   136,    88,     0,
     154,     0,     0,   270,     0,     0,   130,    37,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       0,     4,     0,     0,   124,     0,     0,   118,   119,   117,
       0,   121,     0,     0,   150,   268,   245,   248,   250,     0,
     251,     0,   246,   247,   256,     0,   153,   155,   238,   239,
     240,   249,   241,   242,   243,   244,    32,    31,     0,   269,
       0,     0,   100,     0,    95,     0,     0,     0,     0,   130,
     102,    90,     0,    40,    38,    40,    89,    86,    87,   284,
     283,     0,   143,   123,     0,   113,   112,   136,   109,   108,
     110,   120,   116,     0,   136,     0,     0,   114,   252,   255,
      34,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   253,    50,     0,     0,
     280,     0,     0,   234,     0,     0,     0,     0,     0,     0,
       0,   236,     0,   129,   158,   165,   166,   167,   160,   162,
     168,   161,   181,   169,   170,   171,   172,   164,   159,   174,
     175,     0,   301,     0,     0,    98,     0,     0,   101,     0,
      92,    93,     0,    36,    41,    24,     0,    22,   127,   125,
     151,   278,   150,     0,   135,   137,   142,   150,   146,   148,
     145,   254,   156,     0,     0,    47,     0,     0,     0,     0,
      52,    54,    55,   280,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,     0,   176,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   104,   103,    91,
       0,     0,    20,     0,     0,   130,   126,     0,   276,     0,
     277,   157,   107,   111,     0,   141,   140,   139,   115,     0,
       0,     0,     0,    58,     0,    63,    75,     0,    62,    60,
       0,    70,    69,    59,    67,    72,    57,    77,     0,     0,
      46,     0,    49,   213,     0,   235,   237,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,   173,   163,
     192,   193,     0,   188,     0,     0,     0,   179,     0,   191,
     190,   206,   207,   208,   209,   210,   211,   212,   183,   182,
     185,   184,   186,   187,     0,    35,   302,     0,     0,    39,
       0,    23,   280,   128,   257,   259,     0,   261,   274,   260,
     132,   152,   275,   138,   149,   147,     0,    45,     0,     0,
      61,     0,     0,     0,    68,     0,    81,    82,     0,    56,
      76,    78,     0,     0,    53,     0,   204,     0,     0,     0,
       0,   198,     0,     0,     0,   231,     0,   189,     0,     0,
       0,   180,   232,    97,    94,    25,     0,     0,   296,   288,
     294,   292,   295,   290,     0,     0,     0,   273,   265,   271,
       0,   122,    48,     0,     0,     0,     0,     0,    80,    83,
      79,     0,    85,   214,     0,     0,   202,     0,   201,     0,
     205,   233,     0,     0,   196,   194,   274,     0,   291,   293,
     289,     0,   258,   275,     0,     0,    74,     0,    64,    66,
      71,    84,   215,   216,   199,   203,   197,   195,   262,   285,
     297,     0,   134,    65,     0,     0,     0,     0,     0,   131,
      73,     0,   298,   286,   272,   133,   234,     0,   287
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -321,  -321,  -321,   475,  -321,   523,  -321,   227,  -321,    48,
    -321,  -321,  -321,  -321,   228,   -89,   409,  -321,  -321,  -321,
      42,  -321,   190,  -321,   106,  -321,  -321,  -321,  -321,   116,
    -321,  -321,   -47,  -321,  -321,  -321,  -321,  -321,  -321,   415,
    -321,  -321,   321,  -194,   -85,  -321,   125,   -73,   -42,  -321,
    -321,   -86,   292,  -321,  -321,  -321,  -136,  -321,  -321,  -106,
    -321,   238,  -321,  -321,   -11,  -260,  -321,   -27,   240,  -143,
    -191,  -321,  -321,  -321,  -321,  -321,  -321,   298,  -321,  -321,
    -321,  -321,  -321,  -150,  -321,  -321,  -321,  -321,  -321,    27,
     -60,   -91,  -321,  -321,   -92,  -321,  -321,  -321,  -321,  -321,
    -299,    67,  -321,  -321,  -321,     2,  -321,  -321,    73,   322,
    -321,  -321,  -321,  -321,   480,  -321,  -321,  -321,  -321,  -320
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    71,   246,   247,    23,    64,
      24,   137,    25,    26,    88,   153,   243,    27,    28,    29,
      83,   269,   270,   271,   357,   434,   430,   439,   440,   441,
     272,    30,    92,    31,   240,   241,    32,    33,    34,   147,
      35,   149,   150,    36,   167,   168,   169,    76,   110,   111,
     172,    77,   164,   248,   325,   326,   144,   481,   539,   114,
     254,   255,   337,   104,   177,   249,   125,   126,   250,   251,
     214,   215,   216,   217,   218,   219,   220,   281,   221,   222,
     223,   224,   225,   194,   195,   196,   226,   227,   228,   229,
     230,   128,   129,   130,   131,   132,   133,   134,   135,   413,
     414,   415,   416,   417,    51,   418,   140,   477,   478,   479,
     331,    37,    38,    61,    62,   419,   474,   543,    69,   233
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     213,   106,   154,   154,    41,   155,   265,    44,    95,    96,
      97,   162,    52,   238,    54,   365,   546,   284,   163,   286,
     127,   426,   328,    40,   170,   377,   538,   170,   174,   261,
     256,   328,   258,   260,    73,   113,   143,    58,   266,   443,
     289,   116,   117,   118,    93,   384,   289,   297,   372,   435,
      86,   449,    89,   199,   154,   335,   231,   290,   289,   387,
      98,   252,   267,   290,   280,    65,    66,   373,   257,   288,
     107,   340,   385,   374,   235,   290,   388,    59,   175,   362,
     289,   336,   436,    94,   200,   312,   141,   142,    84,    85,
      40,    39,   284,   317,   152,   268,   176,   290,   157,   158,
     382,   379,   383,   467,   445,   108,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   262,   491,    73,   119,   437,   460,   368,   253,   234,
      42,   289,   237,   289,   201,   369,   370,   112,   107,   287,
     120,   109,   438,   329,   468,    43,   380,   381,   290,   469,
     290,    74,   476,   289,   327,   470,   471,    50,   289,   535,
     498,    48,    75,   203,   116,   117,   118,   170,   333,   467,
     290,   499,   472,   108,    45,   290,   512,   473,   289,   366,
     211,   363,   274,    46,   275,   121,   122,   123,    49,   420,
     297,   256,    55,   457,   412,   290,   424,   425,   503,   105,
     263,    56,    63,   367,    60,   204,   205,   206,   536,   109,
     468,   537,   530,    47,   522,   469,   124,    53,   466,   279,
     404,   470,   471,   289,   159,    67,   311,   455,   312,   452,
     453,    57,   327,   203,   116,   117,   118,    70,   472,   450,
     290,   332,  -297,   473,   207,   289,   338,   119,    68,    78,
      79,   154,   297,   427,   532,   448,   127,   289,   373,   524,
      80,   127,   290,   120,   451,   501,   182,   183,   184,   185,
     186,   187,   408,   259,   290,   204,   205,   206,    81,    82,
     208,   203,   116,   117,   118,   308,   309,   310,   311,   407,
     312,    87,    90,   209,   410,   467,   314,    91,   322,   315,
     102,   323,   454,    99,   494,   115,   496,   497,   121,   122,
     123,   100,   103,   459,   207,   405,   360,   119,   136,   361,
     138,   139,  -263,   204,   205,   206,   210,   211,   145,   203,
     116,   117,   118,   120,   212,    73,   468,   143,   146,   124,
     279,   469,   463,   465,   148,   181,   181,   470,   471,   482,
     208,   492,   315,   151,   315,   493,   525,   505,   327,   116,
     327,   156,   207,   209,   472,   119,   118,   516,  -297,   473,
     517,   204,   205,   206,   521,   163,    74,   315,   121,   122,
     123,   120,   165,   527,   544,   502,   327,   315,   161,   203,
     116,   117,   118,   542,   166,   545,   210,   211,   208,   203,
     116,   117,   118,   171,   212,   173,   178,   179,   180,   124,
     207,   209,   181,   119,   197,   198,   232,   236,   239,   245,
     242,   112,   264,    15,   273,   276,   121,   122,   123,   120,
     277,   282,   205,   206,   278,   285,   313,   319,   316,   320,
     321,   324,   205,   206,   210,   211,   208,   327,  -264,   334,
     341,   339,   212,   342,   358,   359,   375,   124,    73,   209,
     406,   378,   422,   386,   428,   429,   291,   431,   432,   433,
     207,   442,   447,   119,   121,   122,   123,   343,   446,   289,
     207,   384,   344,   119,   345,   346,   461,   347,   462,   120,
     458,   312,   210,   211,   464,   348,   480,   483,   475,   120,
     212,   484,   292,   485,   486,   124,   283,   487,   488,   489,
     507,   500,   504,   506,   508,   509,   283,   510,   511,   209,
     513,   349,   515,   514,   518,   519,   520,   523,   526,   209,
     531,   534,   533,   541,   121,   122,   123,   540,   350,   548,
     351,   352,   275,   101,   121,   122,   123,    72,   409,   293,
     411,   444,   210,   211,   495,   353,   490,   202,   318,   354,
     212,   355,   210,   211,   244,   124,   364,   421,   547,   294,
     212,   356,   423,   330,   529,   124,   295,   296,   371,   528,
     160,     0,     0,   297,   298,     0,     0,  -299,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     0,   299,   300,   301,   302,   303,     3,
       0,   304,   305,     4,   306,   307,   308,   309,   310,   311,
       0,   312,     0,     5,     0,     1,     6,     7,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     8,     9,
       3,     0,     0,     0,     4,     0,   292,     0,     0,    10,
       0,     0,    11,     0,     5,     0,     0,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,    12,     0,     0,     0,    13,     0,     0,
      10,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,    14,   293,     0,     0,     0,     0,    15,   292,
       0,     0,     0,     0,    12,     0,     0,   456,    13,     0,
       0,     0,     0,   376,     0,     0,     0,   292,     0,     0,
       0,   296,     0,    14,     0,     0,     0,   297,   298,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,     0,     0,     0,     0,   293,     0,   299,   300,
     301,   302,   303,     0,     0,   304,   305,     0,   306,   307,
     308,   309,   310,   311,  -300,   312,   376,   292,     0,     0,
      16,    17,    18,     0,   296,     0,     0,     0,     0,     0,
     297,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,   297,  -300,
       0,   299,   300,   301,   302,   303,     0,     0,   304,   305,
       0,   306,   307,   308,   309,   310,   311,     0,   312,  -300,
    -300,  -300,   302,   303,     0,     0,   304,   305,     0,   306,
     307,   308,   309,   310,   311,     0,   312,     0,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,   297,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -300,  -300,     0,     0,  -300,  -300,     0,   306,
     307,   308,   309,   310,   311,     0,   312
};

static const yytype_int16 yycheck[] =
{
     143,    74,    93,    94,     2,    94,   200,     5,    55,    56,
      57,   103,    10,   149,    12,     3,     3,   208,    12,   210,
      80,   341,     3,     3,   110,   285,    50,   113,   113,   179,
     173,     3,   175,   176,    57,    77,    82,    19,     3,   359,
     114,     4,     5,     6,    93,   100,   114,   134,    91,    27,
      48,   107,    50,    93,   145,    89,   145,   131,   114,   103,
      58,   167,    27,   131,   207,    17,    18,   110,   174,   212,
       9,    54,   127,   116,   147,   131,   120,    59,    54,   273,
     114,   115,    60,   132,   124,   172,    84,    85,    46,    47,
       3,    26,   283,   236,    92,    60,    72,   131,    96,    97,
     291,   175,   293,    25,   364,    44,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   181,   442,    57,    87,   103,   386,   277,   170,    63,
       3,   114,   178,   114,   174,   278,   279,    76,     9,   212,
     103,    80,   120,   124,    66,     3,   289,   290,   131,    71,
     131,   174,   124,   114,   178,    77,    78,    97,   114,    81,
     116,    93,    37,     3,     4,     5,     6,   253,   253,    25,
     131,   107,    94,    44,    70,   131,   475,    99,   114,   167,
     167,   175,   174,    79,   176,   148,   149,   150,    93,   325,
     134,   334,    70,   384,   174,   131,   339,   340,   458,    74,
     198,    79,   151,   276,     3,    45,    46,    47,   130,    80,
      66,   531,   511,   109,   175,    71,   179,    79,   412,   110,
     312,    77,    78,   114,    99,     0,   170,   173,   172,   372,
     373,   109,   178,     3,     4,     5,     6,   111,    94,    91,
     131,   252,    98,    99,    84,   114,   257,    87,   177,     3,
     176,   342,   134,   342,   514,   124,   316,   114,   110,   116,
     174,   321,   131,   103,   116,   456,   136,   137,   138,   139,
     140,   141,   319,   113,   131,    45,    46,    47,    93,   126,
     120,     3,     4,     5,     6,   167,   168,   169,   170,   316,
     172,     3,   122,   133,   321,    25,   175,   126,   175,   178,
      96,   178,   375,   124,   447,     3,   449,   450,   148,   149,
     150,   178,   123,   386,    84,   313,   175,    87,     4,   178,
     120,     3,   178,    45,    46,    47,   166,   167,    92,     3,
       4,     5,     6,   103,   174,    57,    66,    82,   174,   179,
     110,    71,   175,   175,     3,   178,   178,    77,    78,   175,
     120,   175,   178,    45,   178,   175,   499,   175,   178,     4,
     178,     3,    84,   133,    94,    87,     6,   175,    98,    99,
     178,    45,    46,    47,   175,    12,   174,   178,   148,   149,
     150,   103,   175,   175,   175,   458,   178,   178,   174,     3,
       4,     5,     6,   536,   175,   538,   166,   167,   120,     3,
       4,     5,     6,   113,   174,   125,     4,     4,   175,   179,
      84,   133,   178,    87,    45,   130,     3,   155,    90,     3,
     111,    76,     3,   111,   124,   174,   148,   149,   150,   103,
     174,    45,    46,    47,   174,   172,    97,    38,   174,    48,
     174,    93,    46,    47,   166,   167,   120,   178,   178,   178,
     174,    54,   174,    92,   119,   174,   174,   179,    57,   133,
       3,   175,     3,   174,    30,   174,    17,   174,   174,   174,
      84,   174,    93,    87,   148,   149,   150,    24,   175,   114,
      84,   100,    29,    87,    31,    32,   103,    34,   173,   103,
     174,   172,   166,   167,     3,    42,    69,   174,   178,   103,
     174,     6,    53,     6,     6,   179,   120,     6,   119,   103,
      98,   175,   175,   175,    77,    77,   120,    77,    98,   133,
       3,    68,     6,   125,   175,   175,   175,   175,   175,   133,
     174,     6,   175,   174,   148,   149,   150,   175,    85,   175,
      87,    88,   176,    68,   148,   149,   150,    24,   320,   100,
     323,   361,   166,   167,   448,   102,   440,   142,   237,   106,
     174,   108,   166,   167,   155,   179,   274,   327,   541,   120,
     174,   118,   334,   251,   507,   179,   127,   128,   280,   506,
     100,    -1,    -1,   134,   135,    -1,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,   155,   156,   157,   158,   159,    22,
      -1,   162,   163,    26,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,    36,    -1,     7,    39,    40,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    51,    52,
      22,    -1,    -1,    -1,    26,    -1,    53,    -1,    -1,    62,
      -1,    -1,    65,    -1,    36,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   100,    -1,    -1,    -1,    -1,   111,    53,
      -1,    -1,    -1,    -1,    86,    -1,    -1,   114,    90,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    53,    -1,    -1,
      -1,   128,    -1,   105,    -1,    -1,    -1,   134,   135,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,   100,    -1,   155,   156,
     157,   158,   159,    -1,    -1,   162,   163,    -1,   165,   166,
     167,   168,   169,   170,   100,   172,   120,    53,    -1,    -1,
     152,   153,   154,    -1,   128,    -1,    -1,    -1,    -1,    -1,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,   134,   135,
      -1,   155,   156,   157,   158,   159,    -1,    -1,   162,   163,
      -1,   165,   166,   167,   168,   169,   170,    -1,   172,   155,
     156,   157,   158,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,   134,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     7,    15,    22,    26,    36,    39,    40,    51,    52,
      62,    65,    86,    90,   105,   111,   152,   153,   154,   181,
     182,   183,   184,   188,   190,   192,   193,   197,   198,   199,
     211,   213,   216,   217,   218,   220,   223,   291,   292,    26,
       3,   285,     3,     3,   285,    70,    79,   109,    93,    93,
      97,   284,   285,    79,   285,    70,    79,   109,    19,    59,
       3,   293,   294,   151,   189,   189,   189,     0,   177,   298,
     111,   185,   185,    57,   174,   226,   227,   231,     3,   176,
     174,    93,   126,   200,   200,   200,   285,     3,   194,   285,
     122,   126,   212,    93,   132,   212,   212,   212,   285,   124,
     178,   183,    96,   123,   243,   226,   227,     9,    44,    80,
     228,   229,    76,   228,   239,     3,     4,     5,     6,    87,
     103,   148,   149,   150,   179,   246,   247,   270,   271,   272,
     273,   274,   275,   276,   277,   278,     4,   191,   120,     3,
     286,   285,   285,    82,   236,    92,   174,   219,     3,   221,
     222,    45,   285,   195,   271,   195,     3,   285,   285,   226,
     294,   174,   274,    12,   232,   175,   175,   224,   225,   226,
     231,   113,   230,   125,   224,    54,    72,   244,     4,     4,
     175,   178,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   263,   264,   265,    45,   130,    93,
     124,   174,   219,     3,    45,    46,    47,    84,   120,   133,
     166,   167,   174,   249,   250,   251,   252,   253,   254,   255,
     256,   258,   259,   260,   261,   262,   266,   267,   268,   269,
     270,   195,     3,   299,    63,   227,   155,   178,   236,    90,
     214,   215,   111,   196,   196,     3,   186,   187,   233,   245,
     248,   249,   239,   228,   240,   241,   249,   239,   249,   113,
     249,   263,   270,   285,     3,   223,     3,    27,    60,   201,
     202,   203,   210,   124,   174,   176,   174,   174,   174,   110,
     249,   257,    45,   120,   250,   172,   250,   227,   249,   114,
     131,    17,    53,   100,   120,   127,   128,   134,   135,   155,
     156,   157,   158,   159,   162,   163,   165,   166,   167,   168,
     169,   170,   172,    97,   175,   178,   174,   249,   222,    38,
      48,   174,   175,   178,    93,   234,   235,   178,     3,   124,
     289,   290,   244,   224,   178,    89,   115,   242,   244,    54,
      54,   174,    92,    24,    29,    31,    32,    34,    42,    68,
      85,    87,    88,   102,   106,   108,   118,   204,   119,   174,
     175,   178,   223,   175,   232,     3,   167,   227,   263,   249,
     249,   257,    91,   110,   116,   174,   120,   245,   175,   175,
     249,   249,   250,   250,   100,   127,   174,   103,   120,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   274,   285,     3,   247,   212,   194,
     247,   187,   174,   279,   280,   281,   282,   283,   285,   295,
     236,   248,     3,   241,   249,   249,   299,   195,    30,   174,
     206,   174,   174,   174,   205,    27,    60,   103,   120,   207,
     208,   209,   174,   299,   202,   245,   175,    93,   124,   107,
      91,   116,   249,   249,   227,   173,   114,   250,   174,   227,
     245,   103,   173,   175,     3,   175,   223,    25,    66,    71,
      77,    78,    94,    99,   296,   178,   124,   287,   288,   289,
      69,   237,   175,   174,     6,     6,     6,     6,   119,   103,
     209,   299,   175,   175,   249,   204,   249,   249,   116,   107,
     175,   250,   227,   245,   175,   175,   175,    98,    77,    77,
      77,    98,   280,     3,   125,     6,   175,   178,   175,   175,
     175,   175,   175,   175,   116,   249,   175,   175,   288,   281,
     280,   174,   245,   175,     6,    81,   130,   299,    50,   238,
     175,   174,   249,   297,   175,   249,     3,   269,   175
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   180,   181,   182,   182,   183,   183,   183,   183,   183,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   188,   189,
     189,   190,   191,   192,   192,   193,   193,   194,   195,   196,
     196,   197,   198,   198,   198,   199,   199,   199,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   206,   206,   206,   207,   207,   208,   208,
     209,   209,   209,   209,   210,   210,   211,   211,   211,   211,
     212,   212,   213,   214,   215,   216,   217,   218,   218,   219,
     219,   220,   221,   221,   222,   223,   223,   223,   224,   224,
     225,   225,   226,   226,   227,   227,   228,   229,   229,   229,
     230,   230,   231,   232,   232,   233,   234,   234,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   240,   241,
     242,   242,   242,   243,   243,   244,   244,   244,   244,   244,
     244,   245,   245,   246,   246,   247,   247,   248,   249,   249,
     249,   249,   249,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   251,   251,   252,   252,   252,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   254,   255,   255,   255,   255,   256,   256,
     256,   256,   257,   257,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   260,   260,   261,   262,   263,   263,   263,
     263,   263,   263,   264,   264,   264,   264,   264,   264,   265,
     265,   266,   267,   268,   269,   269,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   271,   272,   272,   273,   273,
     274,   275,   276,   277,   277,   277,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   284,   285,   285,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   293,   293,   294,   295,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   297,   298,
     298,   299,   299
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     1,     3,     1,     4,     2,     2,     2,     1,
       0,     4,     1,     2,     5,     7,     5,     1,     1,     3,
       0,     5,     2,     3,     2,     8,     7,     6,     9,     7,
       3,     0,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     4,     5,     4,     1,     2,     1,
       1,     3,     0,     5,     3,     0,     1,     0,     1,     2,
       2,     1,     1,     2,     5,     4,     4,     4,     3,     4,
       2,     0,     5,     1,     4,     4,     2,     8,     5,     3,
       0,     5,     1,     3,     3,     2,     2,     6,     1,     1,
       1,     3,     3,     3,     3,     5,     2,     1,     1,     1,
       1,     0,     7,     1,     0,     1,     1,     0,     2,     2,
       0,     4,     0,     2,     0,     3,     0,     1,     3,     2,
       1,     1,     0,     2,     0,     2,     2,     4,     2,     4,
       0,     1,     3,     1,     0,     1,     3,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     5,     6,     5,     6,     4,     6,
       3,     5,     4,     5,     4,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     1,     1,     3,     1,
       1,     1,     4,     1,     3,     2,     1,     1,     3,     1,
       0,     1,     5,     1,     0,     2,     1,     1,     0,     1,
       0,     2,     1,     3,     3,     4,     6,     8,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     0,     1,     1,
       0,     1,     3
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
        yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult* result, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* IDENTIFIER  */
#line 162 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 1943 "bison_parser.cpp"
        break;

    case 4: /* STRING  */
#line 162 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 1949 "bison_parser.cpp"
        break;

    case 5: /* FLOATVAL  */
#line 160 "bison_parser.y"
                { }
#line 1955 "bison_parser.cpp"
        break;

    case 6: /* INTVAL  */
#line 160 "bison_parser.y"
                { }
#line 1961 "bison_parser.cpp"
        break;

    case 182: /* statement_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).stmt_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).stmt_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).stmt_vec));
    }
#line 1974 "bison_parser.cpp"
        break;

    case 183: /* statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 1980 "bison_parser.cpp"
        break;

    case 184: /* preparable_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).statement)); }
#line 1986 "bison_parser.cpp"
        break;

    case 185: /* opt_hints  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 1999 "bison_parser.cpp"
        break;

    case 186: /* hint_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2012 "bison_parser.cpp"
        break;

    case 187: /* hint  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2018 "bison_parser.cpp"
        break;

    case 188: /* transaction_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).transaction_stmt)); }
#line 2024 "bison_parser.cpp"
        break;

    case 190: /* prepare_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).prep_stmt)); }
#line 2030 "bison_parser.cpp"
        break;

    case 191: /* prepare_target_query  */
#line 162 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2036 "bison_parser.cpp"
        break;

    case 192: /* execute_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).exec_stmt)); }
#line 2042 "bison_parser.cpp"
        break;

    case 193: /* import_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).import_stmt)); }
#line 2048 "bison_parser.cpp"
        break;

    case 194: /* file_type  */
#line 160 "bison_parser.y"
                { }
#line 2054 "bison_parser.cpp"
        break;

    case 195: /* file_path  */
#line 162 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2060 "bison_parser.cpp"
        break;

    case 196: /* opt_file_type  */
#line 160 "bison_parser.y"
                { }
#line 2066 "bison_parser.cpp"
        break;

    case 197: /* export_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).export_stmt)); }
#line 2072 "bison_parser.cpp"
        break;

    case 198: /* show_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).show_stmt)); }
#line 2078 "bison_parser.cpp"
        break;

    case 199: /* create_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).create_stmt)); }
#line 2084 "bison_parser.cpp"
        break;

    case 200: /* opt_not_exists  */
#line 160 "bison_parser.y"
                { }
#line 2090 "bison_parser.cpp"
        break;

    case 201: /* table_elem_commalist  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).table_element_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_element_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_element_vec));
    }
#line 2103 "bison_parser.cpp"
        break;

    case 202: /* table_elem  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table_element_t)); }
#line 2109 "bison_parser.cpp"
        break;

    case 203: /* column_def  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).column_t)); }
#line 2115 "bison_parser.cpp"
        break;

    case 204: /* column_type  */
#line 160 "bison_parser.y"
                { }
#line 2121 "bison_parser.cpp"
        break;

    case 205: /* opt_time_specification  */
#line 160 "bison_parser.y"
                { }
#line 2127 "bison_parser.cpp"
        break;

    case 206: /* opt_decimal_specification  */
#line 160 "bison_parser.y"
                { }
#line 2133 "bison_parser.cpp"
        break;

    case 207: /* opt_column_constraints  */
#line 160 "bison_parser.y"
                { }
#line 2139 "bison_parser.cpp"
        break;

    case 208: /* column_constraint_list  */
#line 160 "bison_parser.y"
                { }
#line 2145 "bison_parser.cpp"
        break;

    case 209: /* column_constraint  */
#line 160 "bison_parser.y"
                { }
#line 2151 "bison_parser.cpp"
        break;

    case 210: /* table_constraint  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table_constraint_t)); }
#line 2157 "bison_parser.cpp"
        break;

    case 211: /* drop_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).drop_stmt)); }
#line 2163 "bison_parser.cpp"
        break;

    case 212: /* opt_exists  */
#line 160 "bison_parser.y"
                { }
#line 2169 "bison_parser.cpp"
        break;

    case 213: /* alter_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alter_stmt)); }
#line 2175 "bison_parser.cpp"
        break;

    case 214: /* alter_action  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alter_action_t)); }
#line 2181 "bison_parser.cpp"
        break;

    case 215: /* drop_action  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).drop_action_t)); }
#line 2187 "bison_parser.cpp"
        break;

    case 216: /* delete_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2193 "bison_parser.cpp"
        break;

    case 217: /* truncate_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).delete_stmt)); }
#line 2199 "bison_parser.cpp"
        break;

    case 218: /* insert_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).insert_stmt)); }
#line 2205 "bison_parser.cpp"
        break;

    case 219: /* opt_column_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2218 "bison_parser.cpp"
        break;

    case 220: /* update_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).update_stmt)); }
#line 2224 "bison_parser.cpp"
        break;

    case 221: /* update_clause_commalist  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).update_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).update_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).update_vec));
    }
#line 2237 "bison_parser.cpp"
        break;

    case 222: /* update_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).update_t)); }
#line 2243 "bison_parser.cpp"
        break;

    case 223: /* select_statement  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2249 "bison_parser.cpp"
        break;

    case 224: /* select_within_set_operation  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2255 "bison_parser.cpp"
        break;

    case 225: /* select_within_set_operation_no_parentheses  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2261 "bison_parser.cpp"
        break;

    case 226: /* select_with_paren  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2267 "bison_parser.cpp"
        break;

    case 227: /* select_no_paren  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2273 "bison_parser.cpp"
        break;

    case 228: /* set_operator  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2279 "bison_parser.cpp"
        break;

    case 229: /* set_type  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).set_operator_t)); }
#line 2285 "bison_parser.cpp"
        break;

    case 230: /* opt_all  */
#line 160 "bison_parser.y"
                { }
#line 2291 "bison_parser.cpp"
        break;

    case 231: /* select_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).select_stmt)); }
#line 2297 "bison_parser.cpp"
        break;

    case 232: /* opt_distinct  */
#line 160 "bison_parser.y"
                { }
#line 2303 "bison_parser.cpp"
        break;

    case 233: /* select_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2316 "bison_parser.cpp"
        break;

    case 234: /* opt_from_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2322 "bison_parser.cpp"
        break;

    case 235: /* from_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2328 "bison_parser.cpp"
        break;

    case 236: /* opt_where  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2334 "bison_parser.cpp"
        break;

    case 237: /* opt_group  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).group_t)); }
#line 2340 "bison_parser.cpp"
        break;

    case 238: /* opt_having  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2346 "bison_parser.cpp"
        break;

    case 239: /* opt_order  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2359 "bison_parser.cpp"
        break;

    case 240: /* order_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).order_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).order_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).order_vec));
    }
#line 2372 "bison_parser.cpp"
        break;

    case 241: /* order_desc  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).order)); }
#line 2378 "bison_parser.cpp"
        break;

    case 242: /* opt_order_type  */
#line 160 "bison_parser.y"
                { }
#line 2384 "bison_parser.cpp"
        break;

    case 243: /* opt_top  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2390 "bison_parser.cpp"
        break;

    case 244: /* opt_limit  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).limit)); }
#line 2396 "bison_parser.cpp"
        break;

    case 245: /* expr_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2409 "bison_parser.cpp"
        break;

    case 246: /* opt_literal_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2422 "bison_parser.cpp"
        break;

    case 247: /* literal_list  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).expr_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).expr_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).expr_vec));
    }
#line 2435 "bison_parser.cpp"
        break;

    case 248: /* expr_alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2441 "bison_parser.cpp"
        break;

    case 249: /* expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2447 "bison_parser.cpp"
        break;

    case 250: /* operand  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2453 "bison_parser.cpp"
        break;

    case 251: /* scalar_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2459 "bison_parser.cpp"
        break;

    case 252: /* unary_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2465 "bison_parser.cpp"
        break;

    case 253: /* binary_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2471 "bison_parser.cpp"
        break;

    case 254: /* logic_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2477 "bison_parser.cpp"
        break;

    case 255: /* in_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2483 "bison_parser.cpp"
        break;

    case 256: /* case_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2489 "bison_parser.cpp"
        break;

    case 257: /* case_list  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2495 "bison_parser.cpp"
        break;

    case 258: /* exists_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2501 "bison_parser.cpp"
        break;

    case 259: /* comp_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2507 "bison_parser.cpp"
        break;

    case 260: /* function_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2513 "bison_parser.cpp"
        break;

    case 261: /* extract_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2519 "bison_parser.cpp"
        break;

    case 262: /* cast_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2525 "bison_parser.cpp"
        break;

    case 263: /* datetime_field  */
#line 160 "bison_parser.y"
                { }
#line 2531 "bison_parser.cpp"
        break;

    case 264: /* datetime_field_plural  */
#line 160 "bison_parser.y"
                { }
#line 2537 "bison_parser.cpp"
        break;

    case 265: /* duration_field  */
#line 160 "bison_parser.y"
                { }
#line 2543 "bison_parser.cpp"
        break;

    case 266: /* array_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2549 "bison_parser.cpp"
        break;

    case 267: /* array_index  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2555 "bison_parser.cpp"
        break;

    case 268: /* between_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2561 "bison_parser.cpp"
        break;

    case 269: /* column_name  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2567 "bison_parser.cpp"
        break;

    case 270: /* literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2573 "bison_parser.cpp"
        break;

    case 271: /* string_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2579 "bison_parser.cpp"
        break;

    case 272: /* bool_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2585 "bison_parser.cpp"
        break;

    case 273: /* num_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2591 "bison_parser.cpp"
        break;

    case 274: /* int_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2597 "bison_parser.cpp"
        break;

    case 275: /* null_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2603 "bison_parser.cpp"
        break;

    case 276: /* date_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2609 "bison_parser.cpp"
        break;

    case 277: /* interval_literal  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2615 "bison_parser.cpp"
        break;

    case 278: /* param_expr  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2621 "bison_parser.cpp"
        break;

    case 279: /* table_ref  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2627 "bison_parser.cpp"
        break;

    case 280: /* table_ref_atomic  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2633 "bison_parser.cpp"
        break;

    case 281: /* nonjoin_table_ref_atomic  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2639 "bison_parser.cpp"
        break;

    case 282: /* table_ref_commalist  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).table_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).table_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).table_vec));
    }
#line 2652 "bison_parser.cpp"
        break;

    case 283: /* table_ref_name  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2658 "bison_parser.cpp"
        break;

    case 284: /* table_ref_name_no_alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2664 "bison_parser.cpp"
        break;

    case 285: /* table_name  */
#line 161 "bison_parser.y"
                { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2670 "bison_parser.cpp"
        break;

    case 286: /* opt_index_name  */
#line 162 "bison_parser.y"
                { free( (((*yyvaluep).sval)) ); }
#line 2676 "bison_parser.cpp"
        break;

    case 287: /* table_alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2682 "bison_parser.cpp"
        break;

    case 288: /* opt_table_alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2688 "bison_parser.cpp"
        break;

    case 289: /* alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2694 "bison_parser.cpp"
        break;

    case 290: /* opt_alias  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).alias_t)); }
#line 2700 "bison_parser.cpp"
        break;

    case 291: /* opt_with_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2706 "bison_parser.cpp"
        break;

    case 292: /* with_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2712 "bison_parser.cpp"
        break;

    case 293: /* with_description_list  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).with_description_vec)); }
#line 2718 "bison_parser.cpp"
        break;

    case 294: /* with_description  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).with_description_t)); }
#line 2724 "bison_parser.cpp"
        break;

    case 295: /* join_clause  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).table)); }
#line 2730 "bison_parser.cpp"
        break;

    case 296: /* opt_join_type  */
#line 160 "bison_parser.y"
                { }
#line 2736 "bison_parser.cpp"
        break;

    case 297: /* join_condition  */
#line 171 "bison_parser.y"
                { delete (((*yyvaluep).expr)); }
#line 2742 "bison_parser.cpp"
        break;

    case 299: /* ident_commalist  */
#line 163 "bison_parser.y"
                {
      if ((((*yyvaluep).str_vec)) != nullptr) {
        for (auto ptr : *(((*yyvaluep).str_vec))) {
          delete ptr;
        }
      }
      delete (((*yyvaluep).str_vec));
    }
#line 2755 "bison_parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 77 "bison_parser.y"
{
  // Initialize
  yylloc.first_column = 0;
  yylloc.last_column = 0;
  yylloc.first_line = 0;
  yylloc.last_line = 0;
  yylloc.total_column = 0;
  yylloc.string_length = 0;
}

#line 2873 "bison_parser.cpp"

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 293 "bison_parser.y"
                                     {
  for (SQLStatement* stmt : *(yyvsp[-1].stmt_vec)) {
    // Transfers ownership of the statement.
    result->addStatement(stmt);
  }

  unsigned param_id = 0;
  for (void* param : yyloc.param_list) {
    if (param != nullptr) {
      Expr* expr = (Expr*)param;
      expr->ival = param_id;
      result->addParameter(expr);
      ++param_id;
    }
  }
    delete (yyvsp[-1].stmt_vec);
  }
#line 3088 "bison_parser.cpp"
    break;

  case 3:
#line 312 "bison_parser.y"
                           {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyval.stmt_vec) = new std::vector<SQLStatement*>();
  (yyval.stmt_vec)->push_back((yyvsp[0].statement));
}
#line 3099 "bison_parser.cpp"
    break;

  case 4:
#line 318 "bison_parser.y"
                               {
  (yyvsp[0].statement)->stringLength = yylloc.string_length;
  yylloc.string_length = 0;
  (yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
  (yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
}
#line 3110 "bison_parser.cpp"
    break;

  case 5:
#line 325 "bison_parser.y"
                                        {
  (yyval.statement) = (yyvsp[-1].prep_stmt);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3119 "bison_parser.cpp"
    break;

  case 6:
#line 329 "bison_parser.y"
                                 {
  (yyval.statement) = (yyvsp[-1].statement);
  (yyval.statement)->hints = (yyvsp[0].expr_vec);
}
#line 3128 "bison_parser.cpp"
    break;

  case 7:
#line 333 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 3134 "bison_parser.cpp"
    break;

  case 8:
#line 334 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 3140 "bison_parser.cpp"
    break;

  case 9:
#line 335 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].export_stmt); }
#line 3146 "bison_parser.cpp"
    break;

  case 10:
#line 337 "bison_parser.y"
                                        { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 3152 "bison_parser.cpp"
    break;

  case 11:
#line 338 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 3158 "bison_parser.cpp"
    break;

  case 12:
#line 339 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 3164 "bison_parser.cpp"
    break;

  case 13:
#line 340 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3170 "bison_parser.cpp"
    break;

  case 14:
#line 341 "bison_parser.y"
                     { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 3176 "bison_parser.cpp"
    break;

  case 15:
#line 342 "bison_parser.y"
                   { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 3182 "bison_parser.cpp"
    break;

  case 16:
#line 343 "bison_parser.y"
                 { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 3188 "bison_parser.cpp"
    break;

  case 17:
#line 344 "bison_parser.y"
                  { (yyval.statement) = (yyvsp[0].alter_stmt); }
#line 3194 "bison_parser.cpp"
    break;

  case 18:
#line 345 "bison_parser.y"
                    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 3200 "bison_parser.cpp"
    break;

  case 19:
#line 346 "bison_parser.y"
                        { (yyval.statement) = (yyvsp[0].transaction_stmt); }
#line 3206 "bison_parser.cpp"
    break;

  case 20:
#line 352 "bison_parser.y"
                                        { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 3212 "bison_parser.cpp"
    break;

  case 21:
#line 353 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 3218 "bison_parser.cpp"
    break;

  case 22:
#line 355 "bison_parser.y"
                 {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 3227 "bison_parser.cpp"
    break;

  case 23:
#line 359 "bison_parser.y"
                     {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 3236 "bison_parser.cpp"
    break;

  case 24:
#line 364 "bison_parser.y"
                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[0].sval);
}
#line 3245 "bison_parser.cpp"
    break;

  case 25:
#line 368 "bison_parser.y"
                                  {
  (yyval.expr) = Expr::make(kExprHint);
  (yyval.expr)->name = (yyvsp[-3].sval);
  (yyval.expr)->exprList = (yyvsp[-1].expr_vec);
}
#line 3255 "bison_parser.cpp"
    break;

  case 26:
#line 378 "bison_parser.y"
                                                      { (yyval.transaction_stmt) = new TransactionStatement(kBeginTransaction); }
#line 3261 "bison_parser.cpp"
    break;

  case 27:
#line 379 "bison_parser.y"
                                   { (yyval.transaction_stmt) = new TransactionStatement(kRollbackTransaction); }
#line 3267 "bison_parser.cpp"
    break;

  case 28:
#line 380 "bison_parser.y"
                                 { (yyval.transaction_stmt) = new TransactionStatement(kCommitTransaction); }
#line 3273 "bison_parser.cpp"
    break;

  case 31:
#line 388 "bison_parser.y"
                                                                 {
  (yyval.prep_stmt) = new PrepareStatement();
  (yyval.prep_stmt)->name = (yyvsp[-2].sval);
  (yyval.prep_stmt)->query = (yyvsp[0].sval);
}
#line 3283 "bison_parser.cpp"
    break;

  case 33:
#line 396 "bison_parser.y"
                                                                  {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[0].sval);
}
#line 3292 "bison_parser.cpp"
    break;

  case 34:
#line 400 "bison_parser.y"
                                              {
  (yyval.exec_stmt) = new ExecuteStatement();
  (yyval.exec_stmt)->name = (yyvsp[-3].sval);
  (yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
}
#line 3302 "bison_parser.cpp"
    break;

  case 35:
#line 411 "bison_parser.y"
                                                                        {
  (yyval.import_stmt) = new ImportStatement((yyvsp[-4].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-2].sval);
  (yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3313 "bison_parser.cpp"
    break;

  case 36:
#line 417 "bison_parser.y"
                                               {
  (yyval.import_stmt) = new ImportStatement((yyvsp[0].import_type_t));
  (yyval.import_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.import_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.import_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3324 "bison_parser.cpp"
    break;

  case 37:
#line 424 "bison_parser.y"
                       {
  if (strcasecmp((yyvsp[0].sval), "csv") == 0) {
    (yyval.import_type_t) = kImportCSV;
  } else if (strcasecmp((yyvsp[0].sval), "tbl") == 0) {
    (yyval.import_type_t) = kImportTbl;
  } else if (strcasecmp((yyvsp[0].sval), "binary") == 0 || strcasecmp((yyvsp[0].sval), "bin") == 0) {
    (yyval.import_type_t) = kImportBinary;
  } else {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "File type is unknown.");
    YYERROR;
  }
  free((yyvsp[0].sval));
}
#line 3343 "bison_parser.cpp"
    break;

  case 38:
#line 439 "bison_parser.y"
                           {
  (yyval.sval) = strdup((yyvsp[0].expr)->name);
  delete (yyvsp[0].expr);
}
#line 3352 "bison_parser.cpp"
    break;

  case 39:
#line 444 "bison_parser.y"
                                      { (yyval.import_type_t) = (yyvsp[0].import_type_t); }
#line 3358 "bison_parser.cpp"
    break;

  case 40:
#line 445 "bison_parser.y"
              { (yyval.import_type_t) = kImportAuto; }
#line 3364 "bison_parser.cpp"
    break;

  case 41:
#line 451 "bison_parser.y"
                                                              {
  (yyval.export_stmt) = new ExportStatement((yyvsp[0].import_type_t));
  (yyval.export_stmt)->filePath = (yyvsp[-1].sval);
  (yyval.export_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.export_stmt)->tableName = (yyvsp[-3].table_name).name;
}
#line 3375 "bison_parser.cpp"
    break;

  case 42:
#line 463 "bison_parser.y"
                             { (yyval.show_stmt) = new ShowStatement(kShowTables); }
#line 3381 "bison_parser.cpp"
    break;

  case 43:
#line 464 "bison_parser.y"
                          {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3391 "bison_parser.cpp"
    break;

  case 44:
#line 469 "bison_parser.y"
                      {
  (yyval.show_stmt) = new ShowStatement(kShowColumns);
  (yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.show_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3401 "bison_parser.cpp"
    break;

  case 45:
#line 480 "bison_parser.y"
                                                                                         {
  (yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
  (yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
  if (strcasecmp((yyvsp[-2].sval), "tbl") != 0) {
    free((yyvsp[-2].sval));
    yyerror(&yyloc, result, scanner, "File type is unknown.");
    YYERROR;
  }
  free((yyvsp[-2].sval));
  (yyval.create_stmt)->filePath = (yyvsp[0].sval);
}
#line 3419 "bison_parser.cpp"
    break;

  case 46:
#line 493 "bison_parser.y"
                                                                      {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->setColumnDefsAndConstraints((yyvsp[-1].table_element_vec));
  delete (yyvsp[-1].table_element_vec);
}
#line 3432 "bison_parser.cpp"
    break;

  case 47:
#line 501 "bison_parser.y"
                                                             {
  (yyval.create_stmt) = new CreateStatement(kCreateTable);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-3].bval);
  (yyval.create_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3444 "bison_parser.cpp"
    break;

  case 48:
#line 508 "bison_parser.y"
                                                                                   {
  (yyval.create_stmt) = new CreateStatement(kCreateIndex);
  (yyval.create_stmt)->indexName = (yyvsp[-5].sval);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-6].bval);
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->indexColumns = (yyvsp[-1].str_vec);
}
#line 3456 "bison_parser.cpp"
    break;

  case 49:
#line 515 "bison_parser.y"
                                                                            {
  (yyval.create_stmt) = new CreateStatement(kCreateView);
  (yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
  (yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
  (yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
  (yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
  (yyval.create_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3469 "bison_parser.cpp"
    break;

  case 50:
#line 524 "bison_parser.y"
                               { (yyval.bval) = true; }
#line 3475 "bison_parser.cpp"
    break;

  case 51:
#line 525 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3481 "bison_parser.cpp"
    break;

  case 52:
#line 527 "bison_parser.y"
                                  {
  (yyval.table_element_vec) = new std::vector<TableElement*>();
  (yyval.table_element_vec)->push_back((yyvsp[0].table_element_t));
}
#line 3490 "bison_parser.cpp"
    break;

  case 53:
#line 531 "bison_parser.y"
                                      {
  (yyvsp[-2].table_element_vec)->push_back((yyvsp[0].table_element_t));
  (yyval.table_element_vec) = (yyvsp[-2].table_element_vec);
}
#line 3499 "bison_parser.cpp"
    break;

  case 54:
#line 536 "bison_parser.y"
                        { (yyval.table_element_t) = (yyvsp[0].column_t); }
#line 3505 "bison_parser.cpp"
    break;

  case 55:
#line 537 "bison_parser.y"
                   { (yyval.table_element_t) = (yyvsp[0].table_constraint_t); }
#line 3511 "bison_parser.cpp"
    break;

  case 56:
#line 539 "bison_parser.y"
                                                           {
  (yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].column_constraint_vec));
  (yyval.column_t)->setNullableExplicit();
}
#line 3520 "bison_parser.cpp"
    break;

  case 57:
#line 544 "bison_parser.y"
                  { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3526 "bison_parser.cpp"
    break;

  case 58:
#line 545 "bison_parser.y"
          { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3532 "bison_parser.cpp"
    break;

  case 59:
#line 546 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3538 "bison_parser.cpp"
    break;

  case 60:
#line 547 "bison_parser.y"
        { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3544 "bison_parser.cpp"
    break;

  case 61:
#line 548 "bison_parser.y"
                                    { (yyval.column_type_t) = ColumnType{DataType::DECIMAL, 0, (yyvsp[0].column_specification_t)}; }
#line 3550 "bison_parser.cpp"
    break;

  case 62:
#line 549 "bison_parser.y"
         { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3556 "bison_parser.cpp"
    break;

  case 63:
#line 550 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::REAL}; }
#line 3562 "bison_parser.cpp"
    break;

  case 64:
#line 551 "bison_parser.y"
                         { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3568 "bison_parser.cpp"
    break;

  case 65:
#line 552 "bison_parser.y"
                                   { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3574 "bison_parser.cpp"
    break;

  case 66:
#line 553 "bison_parser.y"
                      { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3580 "bison_parser.cpp"
    break;

  case 67:
#line 554 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3586 "bison_parser.cpp"
    break;

  case 68:
#line 555 "bison_parser.y"
                              { (yyval.column_type_t) = ColumnType{DataType::TIME, 0, (yyvsp[0].column_specification_t)}; }
#line 3592 "bison_parser.cpp"
    break;

  case 69:
#line 556 "bison_parser.y"
           { (yyval.column_type_t) = ColumnType{DataType::DATETIME}; }
#line 3598 "bison_parser.cpp"
    break;

  case 70:
#line 557 "bison_parser.y"
       { (yyval.column_type_t) = ColumnType{DataType::DATE}; }
#line 3604 "bison_parser.cpp"
    break;

  case 71:
#line 559 "bison_parser.y"
                                        { (yyval.column_specification_t) = ColumnSpecification{(yyvsp[-1].ival)}; }
#line 3610 "bison_parser.cpp"
    break;

  case 72:
#line 560 "bison_parser.y"
              { (yyval.column_specification_t) = ColumnSpecification{}; }
#line 3616 "bison_parser.cpp"
    break;

  case 73:
#line 562 "bison_parser.y"
                                                      { (yyval.column_specification_t) = ColumnSpecification{(yyvsp[-3].ival), (yyvsp[-1].ival)}; }
#line 3622 "bison_parser.cpp"
    break;

  case 74:
#line 563 "bison_parser.y"
                 { (yyval.column_specification_t) = ColumnSpecification{(yyvsp[-1].ival)}; }
#line 3628 "bison_parser.cpp"
    break;

  case 75:
#line 564 "bison_parser.y"
              { (yyval.column_specification_t) = ColumnSpecification{}; }
#line 3634 "bison_parser.cpp"
    break;

  case 76:
#line 566 "bison_parser.y"
                                                { (yyval.column_constraint_vec) = (yyvsp[0].column_constraint_vec); }
#line 3640 "bison_parser.cpp"
    break;

  case 77:
#line 567 "bison_parser.y"
              { (yyval.column_constraint_vec) = new std::vector<ConstraintType>(); }
#line 3646 "bison_parser.cpp"
    break;

  case 78:
#line 569 "bison_parser.y"
                                           {
  (yyval.column_constraint_vec) = new std::vector<ConstraintType>();
  (yyval.column_constraint_vec)->push_back((yyvsp[0].column_constraint_t));
}
#line 3655 "bison_parser.cpp"
    break;

  case 79:
#line 573 "bison_parser.y"
                                           {
  (yyvsp[-1].column_constraint_vec)->push_back((yyvsp[0].column_constraint_t));
  (yyval.column_constraint_vec) = (yyvsp[-1].column_constraint_vec);
}
#line 3664 "bison_parser.cpp"
    break;

  case 80:
#line 578 "bison_parser.y"
                                { (yyval.column_constraint_t) = ConstraintType::PrimaryKey; }
#line 3670 "bison_parser.cpp"
    break;

  case 81:
#line 579 "bison_parser.y"
         { (yyval.column_constraint_t) = ConstraintType::Unique; }
#line 3676 "bison_parser.cpp"
    break;

  case 82:
#line 580 "bison_parser.y"
       { (yyval.column_constraint_t) = ConstraintType::Null; }
#line 3682 "bison_parser.cpp"
    break;

  case 83:
#line 581 "bison_parser.y"
           { (yyval.column_constraint_t) = ConstraintType::NotNull; }
#line 3688 "bison_parser.cpp"
    break;

  case 84:
#line 583 "bison_parser.y"
                                                       { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::PrimaryKey, (yyvsp[-1].str_vec)); }
#line 3694 "bison_parser.cpp"
    break;

  case 85:
#line 584 "bison_parser.y"
                                 { (yyval.table_constraint_t) = new TableConstraint(ConstraintType::Unique, (yyvsp[-1].str_vec)); }
#line 3700 "bison_parser.cpp"
    break;

  case 86:
#line 592 "bison_parser.y"
                                                  {
  (yyval.drop_stmt) = new DropStatement(kDropTable);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3711 "bison_parser.cpp"
    break;

  case 87:
#line 598 "bison_parser.y"
                                  {
  (yyval.drop_stmt) = new DropStatement(kDropView);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
}
#line 3722 "bison_parser.cpp"
    break;

  case 88:
#line 604 "bison_parser.y"
                                {
  (yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
  (yyval.drop_stmt)->ifExists = false;
  (yyval.drop_stmt)->name = (yyvsp[0].sval);
}
#line 3732 "bison_parser.cpp"
    break;

  case 89:
#line 610 "bison_parser.y"
                                   {
  (yyval.drop_stmt) = new DropStatement(kDropIndex);
  (yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
  (yyval.drop_stmt)->indexName = (yyvsp[0].sval);
}
#line 3742 "bison_parser.cpp"
    break;

  case 90:
#line 616 "bison_parser.y"
                       { (yyval.bval) = true; }
#line 3748 "bison_parser.cpp"
    break;

  case 91:
#line 617 "bison_parser.y"
              { (yyval.bval) = false; }
#line 3754 "bison_parser.cpp"
    break;

  case 92:
#line 624 "bison_parser.y"
                                                                 {
  (yyval.alter_stmt) = new AlterStatement((yyvsp[-1].table_name).name, (yyvsp[0].alter_action_t));
  (yyval.alter_stmt)->ifTableExists = (yyvsp[-2].bval);
  (yyval.alter_stmt)->schema = (yyvsp[-1].table_name).schema;
}
#line 3764 "bison_parser.cpp"
    break;

  case 93:
#line 630 "bison_parser.y"
                           { (yyval.alter_action_t) = (yyvsp[0].drop_action_t); }
#line 3770 "bison_parser.cpp"
    break;

  case 94:
#line 632 "bison_parser.y"
                                                {
  (yyval.drop_action_t) = new DropColumnAction((yyvsp[0].sval));
  (yyval.drop_action_t)->ifExists = (yyvsp[-1].bval);
}
#line 3779 "bison_parser.cpp"
    break;

  case 95:
#line 642 "bison_parser.y"
                                                    {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
  (yyval.delete_stmt)->expr = (yyvsp[0].expr);
}
#line 3790 "bison_parser.cpp"
    break;

  case 96:
#line 649 "bison_parser.y"
                                         {
  (yyval.delete_stmt) = new DeleteStatement();
  (yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
  (yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
}
#line 3800 "bison_parser.cpp"
    break;

  case 97:
#line 660 "bison_parser.y"
                                                                                      {
  (yyval.insert_stmt) = new InsertStatement(kInsertValues);
  (yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
  (yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
}
#line 3812 "bison_parser.cpp"
    break;

  case 98:
#line 667 "bison_parser.y"
                                                         {
  (yyval.insert_stmt) = new InsertStatement(kInsertSelect);
  (yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
  (yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
  (yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
  (yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
}
#line 3824 "bison_parser.cpp"
    break;

  case 99:
#line 675 "bison_parser.y"
                                          { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3830 "bison_parser.cpp"
    break;

  case 100:
#line 676 "bison_parser.y"
              { (yyval.str_vec) = nullptr; }
#line 3836 "bison_parser.cpp"
    break;

  case 101:
#line 683 "bison_parser.y"
                                                                                        {
  (yyval.update_stmt) = new UpdateStatement();
  (yyval.update_stmt)->table = (yyvsp[-3].table);
  (yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
  (yyval.update_stmt)->where = (yyvsp[0].expr);
}
#line 3847 "bison_parser.cpp"
    break;

  case 102:
#line 690 "bison_parser.y"
                                        {
  (yyval.update_vec) = new std::vector<UpdateClause*>();
  (yyval.update_vec)->push_back((yyvsp[0].update_t));
}
#line 3856 "bison_parser.cpp"
    break;

  case 103:
#line 694 "bison_parser.y"
                                            {
  (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t));
  (yyval.update_vec) = (yyvsp[-2].update_vec);
}
#line 3865 "bison_parser.cpp"
    break;

  case 104:
#line 699 "bison_parser.y"
                                    {
  (yyval.update_t) = new UpdateClause();
  (yyval.update_t)->column = (yyvsp[-2].sval);
  (yyval.update_t)->value = (yyvsp[0].expr);
}
#line 3875 "bison_parser.cpp"
    break;

  case 105:
#line 709 "bison_parser.y"
                                                     {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 3884 "bison_parser.cpp"
    break;

  case 106:
#line 713 "bison_parser.y"
                                  {
  (yyval.select_stmt) = (yyvsp[0].select_stmt);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-1].with_description_vec);
}
#line 3893 "bison_parser.cpp"
    break;

  case 107:
#line 717 "bison_parser.y"
                                                                                                 {
  (yyval.select_stmt) = (yyvsp[-4].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-3].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-2].select_stmt);
  (yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-1].order_vec);
  (yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[0].limit);
  (yyval.select_stmt)->withDescriptions = (yyvsp[-5].with_description_vec);
}
#line 3909 "bison_parser.cpp"
    break;

  case 110:
#line 731 "bison_parser.y"
                                                           { (yyval.select_stmt) = (yyvsp[0].select_stmt); }
#line 3915 "bison_parser.cpp"
    break;

  case 111:
#line 732 "bison_parser.y"
                                                         {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-1].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[0].select_stmt);
}
#line 3928 "bison_parser.cpp"
    break;

  case 112:
#line 741 "bison_parser.y"
                                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3934 "bison_parser.cpp"
    break;

  case 113:
#line 742 "bison_parser.y"
                            { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3940 "bison_parser.cpp"
    break;

  case 114:
#line 744 "bison_parser.y"
                                                    {
  (yyval.select_stmt) = (yyvsp[-2].select_stmt);
  (yyval.select_stmt)->order = (yyvsp[-1].order_vec);

  // Limit could have been set by TOP.
  if ((yyvsp[0].limit) != nullptr) {
    delete (yyval.select_stmt)->limit;
    (yyval.select_stmt)->limit = (yyvsp[0].limit);
  }
}
#line 3955 "bison_parser.cpp"
    break;

  case 115:
#line 754 "bison_parser.y"
                                                                             {
  (yyval.select_stmt) = (yyvsp[-4].select_stmt);
  if ((yyval.select_stmt)->setOperations == nullptr) {
    (yyval.select_stmt)->setOperations = new std::vector<SetOperation*>();
  }
  (yyval.select_stmt)->setOperations->push_back((yyvsp[-3].set_operator_t));
  (yyval.select_stmt)->setOperations->back()->nestedSelectStatement = (yyvsp[-2].select_stmt);
  (yyval.select_stmt)->setOperations->back()->resultOrder = (yyvsp[-1].order_vec);
  (yyval.select_stmt)->setOperations->back()->resultLimit = (yyvsp[0].limit);
}
#line 3970 "bison_parser.cpp"
    break;

  case 116:
#line 765 "bison_parser.y"
                                {
  (yyval.set_operator_t) = (yyvsp[-1].set_operator_t);
  (yyval.set_operator_t)->isAll = (yyvsp[0].bval);
}
#line 3979 "bison_parser.cpp"
    break;

  case 117:
#line 770 "bison_parser.y"
                 {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetUnion;
}
#line 3988 "bison_parser.cpp"
    break;

  case 118:
#line 774 "bison_parser.y"
            {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetIntersect;
}
#line 3997 "bison_parser.cpp"
    break;

  case 119:
#line 778 "bison_parser.y"
         {
  (yyval.set_operator_t) = new SetOperation();
  (yyval.set_operator_t)->setType = SetType::kSetExcept;
}
#line 4006 "bison_parser.cpp"
    break;

  case 120:
#line 783 "bison_parser.y"
              { (yyval.bval) = true; }
#line 4012 "bison_parser.cpp"
    break;

  case 121:
#line 784 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4018 "bison_parser.cpp"
    break;

  case 122:
#line 786 "bison_parser.y"
                                                                                            {
  (yyval.select_stmt) = new SelectStatement();
  (yyval.select_stmt)->limit = (yyvsp[-5].limit);
  (yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
  (yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
  (yyval.select_stmt)->fromTable = (yyvsp[-2].table);
  (yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
  (yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
}
#line 4032 "bison_parser.cpp"
    break;

  case 123:
#line 796 "bison_parser.y"
                        { (yyval.bval) = true; }
#line 4038 "bison_parser.cpp"
    break;

  case 124:
#line 797 "bison_parser.y"
              { (yyval.bval) = false; }
#line 4044 "bison_parser.cpp"
    break;

  case 126:
#line 801 "bison_parser.y"
                              { (yyval.table) = (yyvsp[0].table); }
#line 4050 "bison_parser.cpp"
    break;

  case 127:
#line 802 "bison_parser.y"
              { (yyval.table) = nullptr; }
#line 4056 "bison_parser.cpp"
    break;

  case 128:
#line 804 "bison_parser.y"
                             { (yyval.table) = (yyvsp[0].table); }
#line 4062 "bison_parser.cpp"
    break;

  case 129:
#line 806 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 4068 "bison_parser.cpp"
    break;

  case 130:
#line 807 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4074 "bison_parser.cpp"
    break;

  case 131:
#line 809 "bison_parser.y"
                                          {
  (yyval.group_t) = new GroupByDescription();
  (yyval.group_t)->columns = (yyvsp[-1].expr_vec);
  (yyval.group_t)->having = (yyvsp[0].expr);
}
#line 4084 "bison_parser.cpp"
    break;

  case 132:
#line 814 "bison_parser.y"
              { (yyval.group_t) = nullptr; }
#line 4090 "bison_parser.cpp"
    break;

  case 133:
#line 816 "bison_parser.y"
                         { (yyval.expr) = (yyvsp[0].expr); }
#line 4096 "bison_parser.cpp"
    break;

  case 134:
#line 817 "bison_parser.y"
              { (yyval.expr) = nullptr; }
#line 4102 "bison_parser.cpp"
    break;

  case 135:
#line 819 "bison_parser.y"
                                { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 4108 "bison_parser.cpp"
    break;

  case 136:
#line 820 "bison_parser.y"
              { (yyval.order_vec) = nullptr; }
#line 4114 "bison_parser.cpp"
    break;

  case 137:
#line 822 "bison_parser.y"
                        {
  (yyval.order_vec) = new std::vector<OrderDescription*>();
  (yyval.order_vec)->push_back((yyvsp[0].order));
}
#line 4123 "bison_parser.cpp"
    break;

  case 138:
#line 826 "bison_parser.y"
                            {
  (yyvsp[-2].order_vec)->push_back((yyvsp[0].order));
  (yyval.order_vec) = (yyvsp[-2].order_vec);
}
#line 4132 "bison_parser.cpp"
    break;

  case 139:
#line 831 "bison_parser.y"
                                 { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 4138 "bison_parser.cpp"
    break;

  case 140:
#line 833 "bison_parser.y"
                     { (yyval.order_type) = kOrderAsc; }
#line 4144 "bison_parser.cpp"
    break;

  case 141:
#line 834 "bison_parser.y"
       { (yyval.order_type) = kOrderDesc; }
#line 4150 "bison_parser.cpp"
    break;

  case 142:
#line 835 "bison_parser.y"
              { (yyval.order_type) = kOrderAsc; }
#line 4156 "bison_parser.cpp"
    break;

  case 143:
#line 839 "bison_parser.y"
                          { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4162 "bison_parser.cpp"
    break;

  case 144:
#line 840 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4168 "bison_parser.cpp"
    break;

  case 145:
#line 842 "bison_parser.y"
                       { (yyval.limit) = new LimitDescription((yyvsp[0].expr), nullptr); }
#line 4174 "bison_parser.cpp"
    break;

  case 146:
#line 843 "bison_parser.y"
              { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4180 "bison_parser.cpp"
    break;

  case 147:
#line 844 "bison_parser.y"
                         { (yyval.limit) = new LimitDescription((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4186 "bison_parser.cpp"
    break;

  case 148:
#line 845 "bison_parser.y"
            { (yyval.limit) = new LimitDescription(nullptr, nullptr); }
#line 4192 "bison_parser.cpp"
    break;

  case 149:
#line 846 "bison_parser.y"
                        { (yyval.limit) = new LimitDescription(nullptr, (yyvsp[0].expr)); }
#line 4198 "bison_parser.cpp"
    break;

  case 150:
#line 847 "bison_parser.y"
              { (yyval.limit) = nullptr; }
#line 4204 "bison_parser.cpp"
    break;

  case 151:
#line 852 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4213 "bison_parser.cpp"
    break;

  case 152:
#line 856 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4222 "bison_parser.cpp"
    break;

  case 153:
#line 861 "bison_parser.y"
                                { (yyval.expr_vec) = (yyvsp[0].expr_vec); }
#line 4228 "bison_parser.cpp"
    break;

  case 154:
#line 862 "bison_parser.y"
              { (yyval.expr_vec) = nullptr; }
#line 4234 "bison_parser.cpp"
    break;

  case 155:
#line 864 "bison_parser.y"
                       {
  (yyval.expr_vec) = new std::vector<Expr*>();
  (yyval.expr_vec)->push_back((yyvsp[0].expr));
}
#line 4243 "bison_parser.cpp"
    break;

  case 156:
#line 868 "bison_parser.y"
                           {
  (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr));
  (yyval.expr_vec) = (yyvsp[-2].expr_vec);
}
#line 4252 "bison_parser.cpp"
    break;

  case 157:
#line 873 "bison_parser.y"
                            {
  (yyval.expr) = (yyvsp[-1].expr);
  if ((yyvsp[0].alias_t)) {
    (yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
    delete (yyvsp[0].alias_t);
  }
}
#line 4264 "bison_parser.cpp"
    break;

  case 163:
#line 883 "bison_parser.y"
                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 4270 "bison_parser.cpp"
    break;

  case 173:
#line 885 "bison_parser.y"
                                         {
  (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt));
}
#line 4278 "bison_parser.cpp"
    break;

  case 176:
#line 891 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 4284 "bison_parser.cpp"
    break;

  case 177:
#line 892 "bison_parser.y"
              { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 4290 "bison_parser.cpp"
    break;

  case 178:
#line 893 "bison_parser.y"
                 { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 4296 "bison_parser.cpp"
    break;

  case 179:
#line 894 "bison_parser.y"
                  { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 4302 "bison_parser.cpp"
    break;

  case 180:
#line 895 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 4308 "bison_parser.cpp"
    break;

  case 182:
#line 897 "bison_parser.y"
                                              { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 4314 "bison_parser.cpp"
    break;

  case 183:
#line 898 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 4320 "bison_parser.cpp"
    break;

  case 184:
#line 899 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 4326 "bison_parser.cpp"
    break;

  case 185:
#line 900 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 4332 "bison_parser.cpp"
    break;

  case 186:
#line 901 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 4338 "bison_parser.cpp"
    break;

  case 187:
#line 902 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 4344 "bison_parser.cpp"
    break;

  case 188:
#line 903 "bison_parser.y"
                       { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 4350 "bison_parser.cpp"
    break;

  case 189:
#line 904 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 4356 "bison_parser.cpp"
    break;

  case 190:
#line 905 "bison_parser.y"
                        { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 4362 "bison_parser.cpp"
    break;

  case 191:
#line 906 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 4368 "bison_parser.cpp"
    break;

  case 192:
#line 908 "bison_parser.y"
                           { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 4374 "bison_parser.cpp"
    break;

  case 193:
#line 909 "bison_parser.y"
               { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 4380 "bison_parser.cpp"
    break;

  case 194:
#line 911 "bison_parser.y"
                                       { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 4386 "bison_parser.cpp"
    break;

  case 195:
#line 912 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 4392 "bison_parser.cpp"
    break;

  case 196:
#line 913 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 4398 "bison_parser.cpp"
    break;

  case 197:
#line 914 "bison_parser.y"
                                         { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 4404 "bison_parser.cpp"
    break;

  case 198:
#line 918 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 4410 "bison_parser.cpp"
    break;

  case 199:
#line 919 "bison_parser.y"
                                    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4416 "bison_parser.cpp"
    break;

  case 200:
#line 920 "bison_parser.y"
                     { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 4422 "bison_parser.cpp"
    break;

  case 201:
#line 921 "bison_parser.y"
                               { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4428 "bison_parser.cpp"
    break;

  case 202:
#line 923 "bison_parser.y"
                                { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4434 "bison_parser.cpp"
    break;

  case 203:
#line 924 "bison_parser.y"
                                { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 4440 "bison_parser.cpp"
    break;

  case 204:
#line 926 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 4446 "bison_parser.cpp"
    break;

  case 205:
#line 927 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 4452 "bison_parser.cpp"
    break;

  case 206:
#line 929 "bison_parser.y"
                                { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4458 "bison_parser.cpp"
    break;

  case 207:
#line 930 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 4464 "bison_parser.cpp"
    break;

  case 208:
#line 931 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 4470 "bison_parser.cpp"
    break;

  case 209:
#line 932 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 4476 "bison_parser.cpp"
    break;

  case 210:
#line 933 "bison_parser.y"
                      { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 4482 "bison_parser.cpp"
    break;

  case 211:
#line 934 "bison_parser.y"
                         { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 4488 "bison_parser.cpp"
    break;

  case 212:
#line 935 "bison_parser.y"
                            { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 4494 "bison_parser.cpp"
    break;

  case 213:
#line 937 "bison_parser.y"
                                   { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 4500 "bison_parser.cpp"
    break;

  case 214:
#line 938 "bison_parser.y"
                                            { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 4506 "bison_parser.cpp"
    break;

  case 215:
#line 940 "bison_parser.y"
                                                        { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 4512 "bison_parser.cpp"
    break;

  case 216:
#line 942 "bison_parser.y"
                                             { (yyval.expr) = Expr::makeCast((yyvsp[-3].expr), (yyvsp[-1].column_type_t)); }
#line 4518 "bison_parser.cpp"
    break;

  case 217:
#line 944 "bison_parser.y"
                        { (yyval.datetime_field) = kDatetimeSecond; }
#line 4524 "bison_parser.cpp"
    break;

  case 218:
#line 945 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMinute; }
#line 4530 "bison_parser.cpp"
    break;

  case 219:
#line 946 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeHour; }
#line 4536 "bison_parser.cpp"
    break;

  case 220:
#line 947 "bison_parser.y"
      { (yyval.datetime_field) = kDatetimeDay; }
#line 4542 "bison_parser.cpp"
    break;

  case 221:
#line 948 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeMonth; }
#line 4548 "bison_parser.cpp"
    break;

  case 222:
#line 949 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeYear; }
#line 4554 "bison_parser.cpp"
    break;

  case 223:
#line 951 "bison_parser.y"
                                { (yyval.datetime_field) = kDatetimeSecond; }
#line 4560 "bison_parser.cpp"
    break;

  case 224:
#line 952 "bison_parser.y"
          { (yyval.datetime_field) = kDatetimeMinute; }
#line 4566 "bison_parser.cpp"
    break;

  case 225:
#line 953 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeHour; }
#line 4572 "bison_parser.cpp"
    break;

  case 226:
#line 954 "bison_parser.y"
       { (yyval.datetime_field) = kDatetimeDay; }
#line 4578 "bison_parser.cpp"
    break;

  case 227:
#line 955 "bison_parser.y"
         { (yyval.datetime_field) = kDatetimeMonth; }
#line 4584 "bison_parser.cpp"
    break;

  case 228:
#line 956 "bison_parser.y"
        { (yyval.datetime_field) = kDatetimeYear; }
#line 4590 "bison_parser.cpp"
    break;

  case 231:
#line 960 "bison_parser.y"
                                     { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 4596 "bison_parser.cpp"
    break;

  case 232:
#line 962 "bison_parser.y"
                                          { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 4602 "bison_parser.cpp"
    break;

  case 233:
#line 964 "bison_parser.y"
                                                   { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4608 "bison_parser.cpp"
    break;

  case 234:
#line 966 "bison_parser.y"
                         { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 4614 "bison_parser.cpp"
    break;

  case 235:
#line 967 "bison_parser.y"
                            { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 4620 "bison_parser.cpp"
    break;

  case 236:
#line 968 "bison_parser.y"
      { (yyval.expr) = Expr::makeStar(); }
#line 4626 "bison_parser.cpp"
    break;

  case 237:
#line 969 "bison_parser.y"
                     { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 4632 "bison_parser.cpp"
    break;

  case 245:
#line 973 "bison_parser.y"
                        { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 4638 "bison_parser.cpp"
    break;

  case 246:
#line 975 "bison_parser.y"
                    { (yyval.expr) = Expr::makeLiteral(true); }
#line 4644 "bison_parser.cpp"
    break;

  case 247:
#line 976 "bison_parser.y"
        { (yyval.expr) = Expr::makeLiteral(false); }
#line 4650 "bison_parser.cpp"
    break;

  case 248:
#line 978 "bison_parser.y"
                       { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 4656 "bison_parser.cpp"
    break;

  case 250:
#line 981 "bison_parser.y"
                     { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 4662 "bison_parser.cpp"
    break;

  case 251:
#line 983 "bison_parser.y"
                    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 4668 "bison_parser.cpp"
    break;

  case 252:
#line 985 "bison_parser.y"
                           {
  int day{0}, month{0}, year{0}, chars_parsed{0};
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[0].sval), "%4d-%2d-%2d%n", &day, &month, &year, &chars_parsed) != 3 || (yyvsp[0].sval)[chars_parsed] != 0) {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect date format. Expected format: YYYY-MM-DD");
    YYERROR;
  }
  (yyval.expr) = Expr::makeDateLiteral((yyvsp[0].sval));
}
#line 4683 "bison_parser.cpp"
    break;

  case 253:
#line 996 "bison_parser.y"
                                              {
  (yyval.expr) = Expr::makeIntervalLiteral((yyvsp[-1].expr)->ival, (yyvsp[0].datetime_field));
  delete (yyvsp[-1].expr);
}
#line 4692 "bison_parser.cpp"
    break;

  case 254:
#line 1000 "bison_parser.y"
                                 {
  int duration{0}, chars_parsed{0};
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[-1].sval), "%d%n", &duration, &chars_parsed) != 1 || (yyvsp[-1].sval)[chars_parsed] != 0) {
    free((yyvsp[-1].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect interval format. Expected format: INTEGER");
    YYERROR;
  }
  free((yyvsp[-1].sval));
  (yyval.expr) = Expr::makeIntervalLiteral(duration, (yyvsp[0].datetime_field));
}
#line 4708 "bison_parser.cpp"
    break;

  case 255:
#line 1011 "bison_parser.y"
                  {
  int duration{0}, chars_parsed{0};
  // 'seconds' and 'minutes' are the longest accepted interval qualifiers (7 chars) + null byte
  char unit_string[8];
  // If the whole string is parsed, chars_parsed points to the terminating null byte after the last character
  if (sscanf((yyvsp[0].sval), "%d %7s%n", &duration, unit_string, &chars_parsed) != 2 || (yyvsp[0].sval)[chars_parsed] != 0) {
    free((yyvsp[0].sval));
    yyerror(&yyloc, result, scanner, "Found incorrect interval format. Expected format: INTEGER INTERVAL_QUALIIFIER");
    YYERROR;
  }
  free((yyvsp[0].sval));

  DatetimeField unit;
  if (strcasecmp(unit_string, "second") == 0 || strcasecmp(unit_string, "seconds") == 0) {
    unit = kDatetimeSecond;
  } else if (strcasecmp(unit_string, "minute") == 0 || strcasecmp(unit_string, "minutes") == 0) {
    unit = kDatetimeMinute;
  } else if (strcasecmp(unit_string, "hour") == 0 || strcasecmp(unit_string, "hours") == 0) {
    unit = kDatetimeHour;
  } else if (strcasecmp(unit_string, "day") == 0 || strcasecmp(unit_string, "days") == 0) {
    unit = kDatetimeDay;
  } else if (strcasecmp(unit_string, "month") == 0 || strcasecmp(unit_string, "months") == 0) {
    unit = kDatetimeMonth;
  } else if (strcasecmp(unit_string, "year") == 0 || strcasecmp(unit_string, "years") == 0) {
    unit = kDatetimeYear;
  } else {
    yyerror(&yyloc, result, scanner, "Interval qualifier is unknown.");
    YYERROR;
  }
  (yyval.expr) = Expr::makeIntervalLiteral(duration, unit);
}
#line 4744 "bison_parser.cpp"
    break;

  case 256:
#line 1043 "bison_parser.y"
                 {
  (yyval.expr) = Expr::makeParameter(yylloc.total_column);
  (yyval.expr)->ival2 = yyloc.param_list.size();
  yyloc.param_list.push_back((yyval.expr));
}
#line 4754 "bison_parser.cpp"
    break;

  case 258:
#line 1052 "bison_parser.y"
                                                                        {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  auto tbl = new TableRef(kTableCrossProduct);
  tbl->list = (yyvsp[-2].table_vec);
  (yyval.table) = tbl;
}
#line 4765 "bison_parser.cpp"
    break;

  case 262:
#line 1061 "bison_parser.y"
                                                                                     {
  auto tbl = new TableRef(kTableSelect);
  tbl->select = (yyvsp[-2].select_stmt);
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 4776 "bison_parser.cpp"
    break;

  case 263:
#line 1068 "bison_parser.y"
                                       {
  (yyval.table_vec) = new std::vector<TableRef*>();
  (yyval.table_vec)->push_back((yyvsp[0].table));
}
#line 4785 "bison_parser.cpp"
    break;

  case 264:
#line 1072 "bison_parser.y"
                                           {
  (yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
  (yyval.table_vec) = (yyvsp[-2].table_vec);
}
#line 4794 "bison_parser.cpp"
    break;

  case 265:
#line 1077 "bison_parser.y"
                                            {
  auto tbl = new TableRef(kTableName);
  tbl->schema = (yyvsp[-1].table_name).schema;
  tbl->name = (yyvsp[-1].table_name).name;
  tbl->alias = (yyvsp[0].alias_t);
  (yyval.table) = tbl;
}
#line 4806 "bison_parser.cpp"
    break;

  case 266:
#line 1085 "bison_parser.y"
                                     {
  (yyval.table) = new TableRef(kTableName);
  (yyval.table)->schema = (yyvsp[0].table_name).schema;
  (yyval.table)->name = (yyvsp[0].table_name).name;
}
#line 4816 "bison_parser.cpp"
    break;

  case 267:
#line 1091 "bison_parser.y"
                        {
  (yyval.table_name).schema = nullptr;
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 4825 "bison_parser.cpp"
    break;

  case 268:
#line 1095 "bison_parser.y"
                            {
  (yyval.table_name).schema = (yyvsp[-2].sval);
  (yyval.table_name).name = (yyvsp[0].sval);
}
#line 4834 "bison_parser.cpp"
    break;

  case 269:
#line 1100 "bison_parser.y"
                            { (yyval.sval) = (yyvsp[0].sval); }
#line 4840 "bison_parser.cpp"
    break;

  case 270:
#line 1101 "bison_parser.y"
              { (yyval.sval) = nullptr; }
#line 4846 "bison_parser.cpp"
    break;

  case 272:
#line 1103 "bison_parser.y"
                                                            { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 4852 "bison_parser.cpp"
    break;

  case 274:
#line 1105 "bison_parser.y"
                                            { (yyval.alias_t) = nullptr; }
#line 4858 "bison_parser.cpp"
    break;

  case 275:
#line 1107 "bison_parser.y"
                      { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 4864 "bison_parser.cpp"
    break;

  case 276:
#line 1108 "bison_parser.y"
             { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 4870 "bison_parser.cpp"
    break;

  case 278:
#line 1110 "bison_parser.y"
                                { (yyval.alias_t) = nullptr; }
#line 4876 "bison_parser.cpp"
    break;

  case 280:
#line 1116 "bison_parser.y"
                                            { (yyval.with_description_vec) = nullptr; }
#line 4882 "bison_parser.cpp"
    break;

  case 281:
#line 1118 "bison_parser.y"
                                         { (yyval.with_description_vec) = (yyvsp[0].with_description_vec); }
#line 4888 "bison_parser.cpp"
    break;

  case 282:
#line 1120 "bison_parser.y"
                                         {
  (yyval.with_description_vec) = new std::vector<WithDescription*>();
  (yyval.with_description_vec)->push_back((yyvsp[0].with_description_t));
}
#line 4897 "bison_parser.cpp"
    break;

  case 283:
#line 1124 "bison_parser.y"
                                             {
  (yyvsp[-2].with_description_vec)->push_back((yyvsp[0].with_description_t));
  (yyval.with_description_vec) = (yyvsp[-2].with_description_vec);
}
#line 4906 "bison_parser.cpp"
    break;

  case 284:
#line 1129 "bison_parser.y"
                                                   {
  (yyval.with_description_t) = new WithDescription();
  (yyval.with_description_t)->alias = (yyvsp[-2].sval);
  (yyval.with_description_t)->select = (yyvsp[0].select_stmt);
}
#line 4916 "bison_parser.cpp"
    break;

  case 285:
#line 1139 "bison_parser.y"
                                                                     {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = kJoinNatural;
  (yyval.table)->join->left = (yyvsp[-3].table);
  (yyval.table)->join->right = (yyvsp[0].table);
}
#line 4928 "bison_parser.cpp"
    break;

  case 286:
#line 1146 "bison_parser.y"
                                                                         {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-4].join_type);
  (yyval.table)->join->left = (yyvsp[-5].table);
  (yyval.table)->join->right = (yyvsp[-2].table);
  (yyval.table)->join->condition = (yyvsp[0].expr);
}
#line 4941 "bison_parser.cpp"
    break;

  case 287:
#line 1154 "bison_parser.y"
                                                                                 {
  (yyval.table) = new TableRef(kTableJoin);
  (yyval.table)->join = new JoinDefinition();
  (yyval.table)->join->type = (JoinType)(yyvsp[-6].join_type);
  (yyval.table)->join->left = (yyvsp[-7].table);
  (yyval.table)->join->right = (yyvsp[-4].table);
  auto left_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
  if ((yyvsp[-1].expr)->alias != nullptr) left_col->alias = strdup((yyvsp[-1].expr)->alias);
  if ((yyvsp[-7].table)->getName() != nullptr) left_col->table = strdup((yyvsp[-7].table)->getName());
  auto right_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
  if ((yyvsp[-1].expr)->alias != nullptr) right_col->alias = strdup((yyvsp[-1].expr)->alias);
  if ((yyvsp[-4].table)->getName() != nullptr) right_col->table = strdup((yyvsp[-4].table)->getName());
  (yyval.table)->join->condition = Expr::makeOpBinary(left_col, kOpEquals, right_col);
  delete (yyvsp[-1].expr);
}
#line 4961 "bison_parser.cpp"
    break;

  case 288:
#line 1170 "bison_parser.y"
                      { (yyval.join_type) = kJoinInner; }
#line 4967 "bison_parser.cpp"
    break;

  case 289:
#line 1171 "bison_parser.y"
             { (yyval.join_type) = kJoinLeft; }
#line 4973 "bison_parser.cpp"
    break;

  case 290:
#line 1172 "bison_parser.y"
       { (yyval.join_type) = kJoinLeft; }
#line 4979 "bison_parser.cpp"
    break;

  case 291:
#line 1173 "bison_parser.y"
              { (yyval.join_type) = kJoinRight; }
#line 4985 "bison_parser.cpp"
    break;

  case 292:
#line 1174 "bison_parser.y"
        { (yyval.join_type) = kJoinRight; }
#line 4991 "bison_parser.cpp"
    break;

  case 293:
#line 1175 "bison_parser.y"
             { (yyval.join_type) = kJoinFull; }
#line 4997 "bison_parser.cpp"
    break;

  case 294:
#line 1176 "bison_parser.y"
        { (yyval.join_type) = kJoinFull; }
#line 5003 "bison_parser.cpp"
    break;

  case 295:
#line 1177 "bison_parser.y"
       { (yyval.join_type) = kJoinFull; }
#line 5009 "bison_parser.cpp"
    break;

  case 296:
#line 1178 "bison_parser.y"
        { (yyval.join_type) = kJoinCross; }
#line 5015 "bison_parser.cpp"
    break;

  case 297:
#line 1179 "bison_parser.y"
                       { (yyval.join_type) = kJoinInner; }
#line 5021 "bison_parser.cpp"
    break;

  case 301:
#line 1190 "bison_parser.y"
                             {
  (yyval.str_vec) = new std::vector<char*>();
  (yyval.str_vec)->push_back((yyvsp[0].sval));
}
#line 5030 "bison_parser.cpp"
    break;

  case 302:
#line 1194 "bison_parser.y"
                                 {
  (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval));
  (yyval.str_vec) = (yyvsp[-2].str_vec);
}
#line 5039 "bison_parser.cpp"
    break;


#line 5043 "bison_parser.cpp"

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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, result, scanner);
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
#line 1200 "bison_parser.y"

    // clang-format on
    /*********************************
 ** Section 4: Additional C code
 *********************************/

    /* empty */
