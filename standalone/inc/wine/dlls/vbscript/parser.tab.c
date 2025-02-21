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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PARSER_STYPE
#define YYLTYPE         PARSER_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs

/* First part of user prologue.  */
#line 19 "parser.y"


#include "vbscript.h"
#include "parse.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(vbscript);

static int parser_error(unsigned*,parser_ctx_t*,const char*);

static void handle_isexpression_script(parser_ctx_t *ctx, expression_t *expr);

static void source_add_statement(parser_ctx_t*,statement_t*);
static void source_add_class(parser_ctx_t*,class_decl_t*);

static void *new_expression(parser_ctx_t*,expression_type_t,size_t);
static expression_t *new_bool_expression(parser_ctx_t*,VARIANT_BOOL);
static expression_t *new_date_expression(parser_ctx_t*,DATE);
static expression_t *new_string_expression(parser_ctx_t*,const WCHAR*);
static expression_t *new_long_expression(parser_ctx_t*,expression_type_t,LONG);
static expression_t *new_double_expression(parser_ctx_t*,double);
static expression_t *new_unary_expression(parser_ctx_t*,expression_type_t,expression_t*);
static expression_t *new_binary_expression(parser_ctx_t*,expression_type_t,expression_t*,expression_t*);
static expression_t *new_new_expression(parser_ctx_t*,const WCHAR*);

static member_expression_t *new_member_expression(parser_ctx_t*,expression_t*,const WCHAR*);
static call_expression_t *new_call_expression(parser_ctx_t*,expression_t*,expression_t*);
static call_expression_t *make_call_expression(parser_ctx_t*,expression_t*,expression_t*);

static void *new_statement(parser_ctx_t*,statement_type_t,size_t,unsigned);
static statement_t *new_call_statement(parser_ctx_t*,unsigned,expression_t*);
static statement_t *new_assign_statement(parser_ctx_t*,unsigned,expression_t*,expression_t*);
static statement_t *new_set_statement(parser_ctx_t*,unsigned,expression_t*,expression_t*);
static statement_t *new_dim_statement(parser_ctx_t*,unsigned,dim_decl_t*);
static statement_t *new_redim_statement(parser_ctx_t*,unsigned,BOOL,redim_decl_t*);
static statement_t *new_while_statement(parser_ctx_t*,unsigned,statement_type_t,expression_t*,statement_t*);
static statement_t *new_forto_statement(parser_ctx_t*,unsigned,const WCHAR*,expression_t*,expression_t*,expression_t*,statement_t*);
static statement_t *new_foreach_statement(parser_ctx_t*,unsigned,const WCHAR*,expression_t*,statement_t*);
static statement_t *new_if_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*,elseif_decl_t*,statement_t*);
static statement_t *new_function_statement(parser_ctx_t*,unsigned,function_decl_t*);
static statement_t *new_onerror_statement(parser_ctx_t*,unsigned,BOOL);
static statement_t *new_const_statement(parser_ctx_t*,unsigned,const_decl_t*);
static statement_t *new_select_statement(parser_ctx_t*,unsigned,expression_t*,case_clausule_t*);
static statement_t *new_with_statement(parser_ctx_t*,unsigned,expression_t*,statement_t*);

static dim_decl_t *new_dim_decl(parser_ctx_t*,const WCHAR*,BOOL,dim_list_t*);
static dim_list_t *new_dim(parser_ctx_t*,unsigned,dim_list_t*);
static redim_decl_t *new_redim_decl(parser_ctx_t*,const WCHAR*,expression_t*);
static elseif_decl_t *new_elseif_decl(parser_ctx_t*,unsigned,expression_t*,statement_t*);
static function_decl_t *new_function_decl(parser_ctx_t*,const WCHAR*,function_type_t,unsigned,arg_decl_t*,statement_t*);
static arg_decl_t *new_argument_decl(parser_ctx_t*,const WCHAR*,BOOL);
static const_decl_t *new_const_decl(parser_ctx_t*,const WCHAR*,expression_t*);
static case_clausule_t *new_case_clausule(parser_ctx_t*,expression_t*,statement_t*,case_clausule_t*);

static class_decl_t *new_class_decl(parser_ctx_t*);
static class_decl_t *add_class_function(parser_ctx_t*,class_decl_t*,function_decl_t*);
static class_decl_t *add_dim_prop(parser_ctx_t*,class_decl_t*,dim_decl_t*,unsigned);

static statement_t *link_statements(statement_t*,statement_t*);

#define STORAGE_IS_PRIVATE    1
#define STORAGE_IS_DEFAULT    2

#define CHECK_ERROR if(((parser_ctx_t*)ctx)->hres != S_OK) YYABORT

#define PARSER_LTYPE unsigned
#define YYLLOC_DEFAULT(Cur, Rhs, N) Cur = YYRHSLOC((Rhs), (N) ? 1 : 0)


#line 149 "parser.tab.c"

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


/* Debug traces.  */
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    PARSER_EMPTY = -2,
    PARSER_EOF = 0,                /* "end of file"  */
    PARSER_error = 256,            /* error  */
    PARSER_UNDEF = 257,            /* "invalid token"  */
    tEXPRESSION = 258,             /* tEXPRESSION  */
    tNL = 259,                     /* tNL  */
    tEMPTYBRACKETS = 260,          /* tEMPTYBRACKETS  */
    tEXPRLBRACKET = 261,           /* tEXPRLBRACKET  */
    tLTEQ = 262,                   /* tLTEQ  */
    tGTEQ = 263,                   /* tGTEQ  */
    tNEQ = 264,                    /* tNEQ  */
    tSTOP = 265,                   /* tSTOP  */
    tME = 266,                     /* tME  */
    tREM = 267,                    /* tREM  */
    tDOT = 268,                    /* tDOT  */
    tTRUE = 269,                   /* tTRUE  */
    tFALSE = 270,                  /* tFALSE  */
    tNOT = 271,                    /* tNOT  */
    tAND = 272,                    /* tAND  */
    tOR = 273,                     /* tOR  */
    tXOR = 274,                    /* tXOR  */
    tEQV = 275,                    /* tEQV  */
    tIMP = 276,                    /* tIMP  */
    tIS = 277,                     /* tIS  */
    tMOD = 278,                    /* tMOD  */
    tCALL = 279,                   /* tCALL  */
    tSUB = 280,                    /* tSUB  */
    tFUNCTION = 281,               /* tFUNCTION  */
    tGET = 282,                    /* tGET  */
    tLET = 283,                    /* tLET  */
    tCONST = 284,                  /* tCONST  */
    tDIM = 285,                    /* tDIM  */
    tREDIM = 286,                  /* tREDIM  */
    tPRESERVE = 287,               /* tPRESERVE  */
    tIF = 288,                     /* tIF  */
    tELSE = 289,                   /* tELSE  */
    tELSEIF = 290,                 /* tELSEIF  */
    tEND = 291,                    /* tEND  */
    tTHEN = 292,                   /* tTHEN  */
    tEXIT = 293,                   /* tEXIT  */
    tWHILE = 294,                  /* tWHILE  */
    tWEND = 295,                   /* tWEND  */
    tDO = 296,                     /* tDO  */
    tLOOP = 297,                   /* tLOOP  */
    tUNTIL = 298,                  /* tUNTIL  */
    tFOR = 299,                    /* tFOR  */
    tTO = 300,                     /* tTO  */
    tEACH = 301,                   /* tEACH  */
    tIN = 302,                     /* tIN  */
    tSELECT = 303,                 /* tSELECT  */
    tCASE = 304,                   /* tCASE  */
    tWITH = 305,                   /* tWITH  */
    tBYREF = 306,                  /* tBYREF  */
    tBYVAL = 307,                  /* tBYVAL  */
    tOPTION = 308,                 /* tOPTION  */
    tNOTHING = 309,                /* tNOTHING  */
    tEMPTY = 310,                  /* tEMPTY  */
    tNULL = 311,                   /* tNULL  */
    tCLASS = 312,                  /* tCLASS  */
    tSET = 313,                    /* tSET  */
    tNEW = 314,                    /* tNEW  */
    tPUBLIC = 315,                 /* tPUBLIC  */
    tPRIVATE = 316,                /* tPRIVATE  */
    tNEXT = 317,                   /* tNEXT  */
    tON = 318,                     /* tON  */
    tRESUME = 319,                 /* tRESUME  */
    tGOTO = 320,                   /* tGOTO  */
    tIdentifier = 321,             /* tIdentifier  */
    tString = 322,                 /* tString  */
    tDEFAULT = 323,                /* tDEFAULT  */
    tERROR = 324,                  /* tERROR  */
    tEXPLICIT = 325,               /* tEXPLICIT  */
    tPROPERTY = 326,               /* tPROPERTY  */
    tSTEP = 327,                   /* tSTEP  */
    tInt = 328,                    /* tInt  */
    tDouble = 329,                 /* tDouble  */
    tDate = 330                    /* tDate  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 96 "parser.y"

    const WCHAR *string;
    statement_t *statement;
    expression_t *expression;
    member_expression_t *member;
    elseif_decl_t *elseif;
    dim_decl_t *dim_decl;
    dim_list_t *dim_list;
    redim_decl_t *redim_decl;
    function_decl_t *func_decl;
    arg_decl_t *arg_decl;
    class_decl_t *class_decl;
    const_decl_t *const_decl;
    case_clausule_t *case_clausule;
    unsigned uint;
    LONG integer;
    BOOL boolean;
    double dbl;
    DATE date;

#line 300 "parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined PARSER_LTYPE && ! defined PARSER_LTYPE_IS_DECLARED
typedef struct PARSER_LTYPE PARSER_LTYPE;
struct PARSER_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define PARSER_LTYPE_IS_DECLARED 1
# define PARSER_LTYPE_IS_TRIVIAL 1
#endif




int parser_parse (parser_ctx_t *ctx);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tEXPRESSION = 3,                /* tEXPRESSION  */
  YYSYMBOL_tNL = 4,                        /* tNL  */
  YYSYMBOL_tEMPTYBRACKETS = 5,             /* tEMPTYBRACKETS  */
  YYSYMBOL_tEXPRLBRACKET = 6,              /* tEXPRLBRACKET  */
  YYSYMBOL_tLTEQ = 7,                      /* tLTEQ  */
  YYSYMBOL_tGTEQ = 8,                      /* tGTEQ  */
  YYSYMBOL_tNEQ = 9,                       /* tNEQ  */
  YYSYMBOL_tSTOP = 10,                     /* tSTOP  */
  YYSYMBOL_tME = 11,                       /* tME  */
  YYSYMBOL_tREM = 12,                      /* tREM  */
  YYSYMBOL_tDOT = 13,                      /* tDOT  */
  YYSYMBOL_tTRUE = 14,                     /* tTRUE  */
  YYSYMBOL_tFALSE = 15,                    /* tFALSE  */
  YYSYMBOL_tNOT = 16,                      /* tNOT  */
  YYSYMBOL_tAND = 17,                      /* tAND  */
  YYSYMBOL_tOR = 18,                       /* tOR  */
  YYSYMBOL_tXOR = 19,                      /* tXOR  */
  YYSYMBOL_tEQV = 20,                      /* tEQV  */
  YYSYMBOL_tIMP = 21,                      /* tIMP  */
  YYSYMBOL_tIS = 22,                       /* tIS  */
  YYSYMBOL_tMOD = 23,                      /* tMOD  */
  YYSYMBOL_tCALL = 24,                     /* tCALL  */
  YYSYMBOL_tSUB = 25,                      /* tSUB  */
  YYSYMBOL_tFUNCTION = 26,                 /* tFUNCTION  */
  YYSYMBOL_tGET = 27,                      /* tGET  */
  YYSYMBOL_tLET = 28,                      /* tLET  */
  YYSYMBOL_tCONST = 29,                    /* tCONST  */
  YYSYMBOL_tDIM = 30,                      /* tDIM  */
  YYSYMBOL_tREDIM = 31,                    /* tREDIM  */
  YYSYMBOL_tPRESERVE = 32,                 /* tPRESERVE  */
  YYSYMBOL_tIF = 33,                       /* tIF  */
  YYSYMBOL_tELSE = 34,                     /* tELSE  */
  YYSYMBOL_tELSEIF = 35,                   /* tELSEIF  */
  YYSYMBOL_tEND = 36,                      /* tEND  */
  YYSYMBOL_tTHEN = 37,                     /* tTHEN  */
  YYSYMBOL_tEXIT = 38,                     /* tEXIT  */
  YYSYMBOL_tWHILE = 39,                    /* tWHILE  */
  YYSYMBOL_tWEND = 40,                     /* tWEND  */
  YYSYMBOL_tDO = 41,                       /* tDO  */
  YYSYMBOL_tLOOP = 42,                     /* tLOOP  */
  YYSYMBOL_tUNTIL = 43,                    /* tUNTIL  */
  YYSYMBOL_tFOR = 44,                      /* tFOR  */
  YYSYMBOL_tTO = 45,                       /* tTO  */
  YYSYMBOL_tEACH = 46,                     /* tEACH  */
  YYSYMBOL_tIN = 47,                       /* tIN  */
  YYSYMBOL_tSELECT = 48,                   /* tSELECT  */
  YYSYMBOL_tCASE = 49,                     /* tCASE  */
  YYSYMBOL_tWITH = 50,                     /* tWITH  */
  YYSYMBOL_tBYREF = 51,                    /* tBYREF  */
  YYSYMBOL_tBYVAL = 52,                    /* tBYVAL  */
  YYSYMBOL_tOPTION = 53,                   /* tOPTION  */
  YYSYMBOL_tNOTHING = 54,                  /* tNOTHING  */
  YYSYMBOL_tEMPTY = 55,                    /* tEMPTY  */
  YYSYMBOL_tNULL = 56,                     /* tNULL  */
  YYSYMBOL_tCLASS = 57,                    /* tCLASS  */
  YYSYMBOL_tSET = 58,                      /* tSET  */
  YYSYMBOL_tNEW = 59,                      /* tNEW  */
  YYSYMBOL_tPUBLIC = 60,                   /* tPUBLIC  */
  YYSYMBOL_tPRIVATE = 61,                  /* tPRIVATE  */
  YYSYMBOL_tNEXT = 62,                     /* tNEXT  */
  YYSYMBOL_tON = 63,                       /* tON  */
  YYSYMBOL_tRESUME = 64,                   /* tRESUME  */
  YYSYMBOL_tGOTO = 65,                     /* tGOTO  */
  YYSYMBOL_tIdentifier = 66,               /* tIdentifier  */
  YYSYMBOL_tString = 67,                   /* tString  */
  YYSYMBOL_tDEFAULT = 68,                  /* tDEFAULT  */
  YYSYMBOL_tERROR = 69,                    /* tERROR  */
  YYSYMBOL_tEXPLICIT = 70,                 /* tEXPLICIT  */
  YYSYMBOL_tPROPERTY = 71,                 /* tPROPERTY  */
  YYSYMBOL_tSTEP = 72,                     /* tSTEP  */
  YYSYMBOL_tInt = 73,                      /* tInt  */
  YYSYMBOL_tDouble = 74,                   /* tDouble  */
  YYSYMBOL_tDate = 75,                     /* tDate  */
  YYSYMBOL_76_ = 76,                       /* ':'  */
  YYSYMBOL_77_ = 77,                       /* '='  */
  YYSYMBOL_78_0_ = 78,                     /* '0'  */
  YYSYMBOL_79_ = 79,                       /* '.'  */
  YYSYMBOL_80_ = 80,                       /* ','  */
  YYSYMBOL_81_ = 81,                       /* '('  */
  YYSYMBOL_82_ = 82,                       /* ')'  */
  YYSYMBOL_83_ = 83,                       /* '-'  */
  YYSYMBOL_84_ = 84,                       /* '>'  */
  YYSYMBOL_85_ = 85,                       /* '<'  */
  YYSYMBOL_86_ = 86,                       /* '&'  */
  YYSYMBOL_87_ = 87,                       /* '+'  */
  YYSYMBOL_88_ = 88,                       /* '\\'  */
  YYSYMBOL_89_ = 89,                       /* '*'  */
  YYSYMBOL_90_ = 90,                       /* '/'  */
  YYSYMBOL_91_ = 91,                       /* '^'  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_Program = 93,                   /* Program  */
  YYSYMBOL_OptionExplicit_opt = 94,        /* OptionExplicit_opt  */
  YYSYMBOL_SourceElements = 95,            /* SourceElements  */
  YYSYMBOL_GlobalDimDeclaration = 96,      /* GlobalDimDeclaration  */
  YYSYMBOL_ExpressionNl_opt = 97,          /* ExpressionNl_opt  */
  YYSYMBOL_BodyStatements = 98,            /* BodyStatements  */
  YYSYMBOL_StatementsNl_opt = 99,          /* StatementsNl_opt  */
  YYSYMBOL_StatementsNl = 100,             /* StatementsNl  */
  YYSYMBOL_StatementNl = 101,              /* StatementNl  */
  YYSYMBOL_Statement = 102,                /* Statement  */
  YYSYMBOL_SimpleStatement = 103,          /* SimpleStatement  */
  YYSYMBOL_MemberExpression = 104,         /* MemberExpression  */
  YYSYMBOL_Preserve_opt = 105,             /* Preserve_opt  */
  YYSYMBOL_MemberDeclList = 106,           /* MemberDeclList  */
  YYSYMBOL_MemberDecl = 107,               /* MemberDecl  */
  YYSYMBOL_ReDimDecl = 108,                /* ReDimDecl  */
  YYSYMBOL_ReDimDeclList = 109,            /* ReDimDeclList  */
  YYSYMBOL_DimDeclList = 110,              /* DimDeclList  */
  YYSYMBOL_DimDecl = 111,                  /* DimDecl  */
  YYSYMBOL_DimList = 112,                  /* DimList  */
  YYSYMBOL_ConstDeclList = 113,            /* ConstDeclList  */
  YYSYMBOL_ConstDecl = 114,                /* ConstDecl  */
  YYSYMBOL_ConstExpression = 115,          /* ConstExpression  */
  YYSYMBOL_DoType = 116,                   /* DoType  */
  YYSYMBOL_Step_opt = 117,                 /* Step_opt  */
  YYSYMBOL_IfStatement = 118,              /* IfStatement  */
  YYSYMBOL_EndIf_opt = 119,                /* EndIf_opt  */
  YYSYMBOL_ElseIfs_opt = 120,              /* ElseIfs_opt  */
  YYSYMBOL_ElseIfs = 121,                  /* ElseIfs  */
  YYSYMBOL_ElseIf = 122,                   /* ElseIf  */
  YYSYMBOL_Else_opt = 123,                 /* Else_opt  */
  YYSYMBOL_CaseClausules = 124,            /* CaseClausules  */
  YYSYMBOL_Arguments = 125,                /* Arguments  */
  YYSYMBOL_ArgumentList_opt = 126,         /* ArgumentList_opt  */
  YYSYMBOL_ArgumentList = 127,             /* ArgumentList  */
  YYSYMBOL_EmptyBrackets_opt = 128,        /* EmptyBrackets_opt  */
  YYSYMBOL_ExpressionList = 129,           /* ExpressionList  */
  YYSYMBOL_Expression = 130,               /* Expression  */
  YYSYMBOL_EqvExpression = 131,            /* EqvExpression  */
  YYSYMBOL_XorExpression = 132,            /* XorExpression  */
  YYSYMBOL_OrExpression = 133,             /* OrExpression  */
  YYSYMBOL_AndExpression = 134,            /* AndExpression  */
  YYSYMBOL_NotExpression = 135,            /* NotExpression  */
  YYSYMBOL_EqualityExpression = 136,       /* EqualityExpression  */
  YYSYMBOL_ConcatExpression = 137,         /* ConcatExpression  */
  YYSYMBOL_AdditiveExpression = 138,       /* AdditiveExpression  */
  YYSYMBOL_ModExpression = 139,            /* ModExpression  */
  YYSYMBOL_IntdivExpression = 140,         /* IntdivExpression  */
  YYSYMBOL_MultiplicativeExpression = 141, /* MultiplicativeExpression  */
  YYSYMBOL_ExpExpression = 142,            /* ExpExpression  */
  YYSYMBOL_SignExpression = 143,           /* SignExpression  */
  YYSYMBOL_UnaryExpression = 144,          /* UnaryExpression  */
  YYSYMBOL_CallExpression = 145,           /* CallExpression  */
  YYSYMBOL_LiteralExpression = 146,        /* LiteralExpression  */
  YYSYMBOL_NumericLiteralExpression = 147, /* NumericLiteralExpression  */
  YYSYMBOL_IntegerValue = 148,             /* IntegerValue  */
  YYSYMBOL_PrimaryExpression = 149,        /* PrimaryExpression  */
  YYSYMBOL_ClassDeclaration = 150,         /* ClassDeclaration  */
  YYSYMBOL_ClassBody = 151,                /* ClassBody  */
  YYSYMBOL_PropertyDecl = 152,             /* PropertyDecl  */
  YYSYMBOL_FunctionDecl = 153,             /* FunctionDecl  */
  YYSYMBOL_Storage_opt = 154,              /* Storage_opt  */
  YYSYMBOL_Storage = 155,                  /* Storage  */
  YYSYMBOL_ArgumentsDecl_opt = 156,        /* ArgumentsDecl_opt  */
  YYSYMBOL_ArgumentsDecl = 157,            /* ArgumentsDecl  */
  YYSYMBOL_ArgumentDeclList = 158,         /* ArgumentDeclList  */
  YYSYMBOL_ArgumentDecl = 159,             /* ArgumentDecl  */
  YYSYMBOL_Identifier = 160,               /* Identifier  */
  YYSYMBOL_MemberIdentifier = 161,         /* MemberIdentifier  */
  YYSYMBOL_StSep_opt = 162,                /* StSep_opt  */
  YYSYMBOL_Nl_opt = 163,                   /* Nl_opt  */
  YYSYMBOL_StSep = 164                     /* StSep  */
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
         || (defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL \
             && defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  402

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
       2,     2,     2,     2,     2,     2,     2,     2,    86,     2,
      81,    82,    89,    87,    80,    83,    79,    90,    78,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,     2,
      85,    77,    84,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    88,     2,    91,     2,     2,     2,     2,     2,
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
      75
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   163,   163,   164,   167,   168,   171,   172,   174,   175,
     178,   179,   180,   181,   184,   185,   188,   189,   190,   193,
     194,   197,   198,   201,   204,   205,   206,   207,   208,   211,
     213,   214,   216,   217,   218,   219,   221,   224,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   241,   243,   245,   249,   250,   251,   255,   256,   259,
     260,   263,   264,   265,   268,   271,   272,   275,   276,   279,
     280,   281,   284,   285,   288,   289,   292,   295,   296,   299,
     300,   303,   304,   307,   309,   310,   314,   315,   318,   319,
     322,   323,   326,   330,   331,   334,   335,   336,   339,   340,
     343,   344,   347,   348,   349,   352,   353,   356,   357,   360,
     361,   364,   365,   368,   369,   372,   373,   376,   377,   380,
     381,   384,   385,   386,   387,   388,   389,   390,   391,   394,
     395,   398,   399,   400,   403,   404,   407,   408,   412,   413,
     415,   419,   420,   423,   424,   425,   428,   429,   430,   433,
     434,   435,   439,   440,   441,   442,   443,   444,   445,   446,
     449,   450,   451,   454,   455,   458,   459,   462,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   476,   478,   480,
     484,   486,   488,   490,   494,   495,   498,   499,   500,   503,
     504,   507,   508,   511,   512,   515,   516,   517,   521,   522,
     525,   526,   527,   528,   529,   532,   533,   536,   537,   541,
     542,   543,   544
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if PARSER_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tEXPRESSION", "tNL",
  "tEMPTYBRACKETS", "tEXPRLBRACKET", "tLTEQ", "tGTEQ", "tNEQ", "tSTOP",
  "tME", "tREM", "tDOT", "tTRUE", "tFALSE", "tNOT", "tAND", "tOR", "tXOR",
  "tEQV", "tIMP", "tIS", "tMOD", "tCALL", "tSUB", "tFUNCTION", "tGET",
  "tLET", "tCONST", "tDIM", "tREDIM", "tPRESERVE", "tIF", "tELSE",
  "tELSEIF", "tEND", "tTHEN", "tEXIT", "tWHILE", "tWEND", "tDO", "tLOOP",
  "tUNTIL", "tFOR", "tTO", "tEACH", "tIN", "tSELECT", "tCASE", "tWITH",
  "tBYREF", "tBYVAL", "tOPTION", "tNOTHING", "tEMPTY", "tNULL", "tCLASS",
  "tSET", "tNEW", "tPUBLIC", "tPRIVATE", "tNEXT", "tON", "tRESUME",
  "tGOTO", "tIdentifier", "tString", "tDEFAULT", "tERROR", "tEXPLICIT",
  "tPROPERTY", "tSTEP", "tInt", "tDouble", "tDate", "':'", "'='", "'0'",
  "'.'", "','", "'('", "')'", "'-'", "'>'", "'<'", "'&'", "'+'", "'\\\\'",
  "'*'", "'/'", "'^'", "$accept", "Program", "OptionExplicit_opt",
  "SourceElements", "GlobalDimDeclaration", "ExpressionNl_opt",
  "BodyStatements", "StatementsNl_opt", "StatementsNl", "StatementNl",
  "Statement", "SimpleStatement", "MemberExpression", "Preserve_opt",
  "MemberDeclList", "MemberDecl", "ReDimDecl", "ReDimDeclList",
  "DimDeclList", "DimDecl", "DimList", "ConstDeclList", "ConstDecl",
  "ConstExpression", "DoType", "Step_opt", "IfStatement", "EndIf_opt",
  "ElseIfs_opt", "ElseIfs", "ElseIf", "Else_opt", "CaseClausules",
  "Arguments", "ArgumentList_opt", "ArgumentList", "EmptyBrackets_opt",
  "ExpressionList", "Expression", "EqvExpression", "XorExpression",
  "OrExpression", "AndExpression", "NotExpression", "EqualityExpression",
  "ConcatExpression", "AdditiveExpression", "ModExpression",
  "IntdivExpression", "MultiplicativeExpression", "ExpExpression",
  "SignExpression", "UnaryExpression", "CallExpression",
  "LiteralExpression", "NumericLiteralExpression", "IntegerValue",
  "PrimaryExpression", "ClassDeclaration", "ClassBody", "PropertyDecl",
  "FunctionDecl", "Storage_opt", "Storage", "ArgumentsDecl_opt",
  "ArgumentsDecl", "ArgumentDeclList", "ArgumentDecl", "Identifier",
  "MemberIdentifier", "StSep_opt", "Nl_opt", "StSep", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-253)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-187)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   598,   -47,    56,  -253,  -253,   -35,  -253,  -253,   598,
    -253,  -253,  -253,   369,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,   598,   645,   645,  -253,  -253,
     134,    45,    23,    44,   118,  -253,    25,    67,   -43,   137,
      75,   116,    77,  -253,  -253,    43,  -253,  -253,  -253,  -253,
    -253,     9,  -253,   386,  -253,  -253,  -253,    -7,  -253,  -253,
    -253,   598,   598,   598,   598,   598,   645,   645,   645,   645,
     645,   645,   645,   645,   645,   645,   645,   645,   645,   645,
     645,  -253,   125,   493,  -253,     9,     9,  -253,  -253,  1110,
     369,   369,   164,   598,   252,   598,    16,   268,   152,   598,
     369,   165,   179,   283,   141,   711,     9,  -253,   220,   154,
    -253,   304,  -253,  -253,   190,  -253,  -253,    45,    23,    44,
     118,  -253,    67,    67,    67,    67,    67,    67,    67,   -43,
     137,   137,    75,   116,    77,    77,  -253,  -253,   493,   177,
      31,  -253,  -253,  -253,  -253,   185,   192,  -253,   194,    14,
    -253,   221,    30,  -253,  -253,  -253,  -253,  -253,     7,  -253,
    -253,   598,   873,   369,   211,   598,     7,     9,    38,   369,
     218,  -253,   369,  -253,   193,   222,  -253,  -253,  -253,  -253,
     711,   598,   493,  -253,  -253,   369,   369,  -253,  -253,   493,
     369,   206,   369,  -253,    53,   210,   214,  -253,   455,   927,
       7,   253,  -253,     9,   251,   598,     7,   981,     0,   598,
    -253,  -253,   237,   229,  -253,  -253,   279,    24,    17,    17,
    -253,  -253,    93,  -253,  -253,  -253,  -253,  -253,   228,   231,
     493,   221,   765,   219,   276,   873,   144,   765,   598,   109,
     272,   293,   369,   294,     9,     9,   126,   256,   279,  -253,
    -253,  -253,   337,   328,   819,   328,   819,  -253,  -253,    53,
     259,  -253,   298,  1035,   310,  -253,  -253,   302,   598,  -253,
       7,   598,   568,   312,   296,     9,   308,     0,     0,    -1,
       9,   286,    19,   369,   369,   285,   288,   364,   328,   819,
     344,   819,   220,   819,   354,  -253,  -253,   598,   358,  -253,
     298,   357,  -253,  -253,   279,  1089,    -3,     9,     9,    32,
     347,  -253,     0,     9,  -253,  -253,   369,   369,   369,     0,
     256,  -253,    53,   364,   364,  -253,   337,  -253,  -253,  -253,
     362,   375,  -253,   365,   376,   112,     9,   368,  -253,  -253,
     349,   598,     9,   981,  -253,   765,   598,  -253,  -253,  -253,
      20,   333,   339,  -253,  -253,   336,  -253,  -253,  -253,   396,
    -253,   397,  -253,     9,   981,   389,  -253,   279,  1089,  -253,
     272,  -253,     9,  -253,   337,   337,  -253,  -253,  -253,   765,
    -253,  -253,   366,  -253,   819,   350,   351,  -253,  -253,   390,
       9,     9,   360,   819,   819,  -253,   393,   406,   374,   377,
    -253,  -253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    14,     0,     0,     6,   166,     0,   152,   153,     0,
     159,   157,   158,     0,   200,   154,   201,   202,   203,   199,
     204,   161,   162,   155,   160,     0,     0,     0,     3,   150,
       0,   109,   111,   113,   115,   117,   119,   121,   129,   131,
     134,   136,   138,   141,   143,   147,   146,   156,   149,    54,
     198,     0,     1,   184,    56,   120,   148,     0,   144,   145,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,   151,   209,   210,     5,    46,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   188,     0,    24,     0,     8,     0,    26,
      34,   100,     9,    39,     0,   185,   165,   110,   112,   114,
     116,   118,   127,   126,   123,   128,   122,   124,   125,   130,
     133,   132,   135,   137,   139,   140,   142,    55,     0,     0,
     102,   211,   212,    30,    49,    74,     0,    32,    67,    69,
      58,     0,     0,    44,    42,    40,    41,    43,     0,    79,
      80,     0,   184,     0,     0,     0,     0,     0,     0,     0,
     201,    13,     0,    12,     0,   187,   188,    25,     7,    23,
      28,     0,     0,    29,   101,     0,     0,   104,    99,     0,
       0,     0,     0,    71,     0,     0,    65,    33,   184,   184,
       0,     0,    20,     0,     0,     0,     0,   184,   184,     0,
      11,    10,     0,     0,   186,    27,    31,     0,     0,     0,
     103,    75,     0,    76,    77,    68,   164,   163,     0,    72,
       0,     0,    19,    86,     0,   184,    38,    21,     0,     0,
      95,     0,     0,     0,   175,   169,     0,   185,    45,    47,
      48,   191,     0,   207,   184,   207,   184,    78,    70,     0,
       0,    66,    88,   184,     0,    84,    35,     0,     0,    22,
       0,     0,     0,     0,     0,   173,     0,   184,   184,     0,
     171,    59,    61,     0,     0,     0,   193,   105,   207,   184,
       0,   184,    17,   184,     0,    73,    64,     0,    93,    89,
      90,    86,    87,    36,    37,   184,    81,   205,   205,   107,
       0,    53,   184,     0,   176,   170,     0,     0,     0,   184,
       0,    63,     0,   105,   105,   192,     0,   106,   195,   208,
       0,     0,    18,     0,     0,     0,   205,     0,    91,    85,
       0,     0,     0,   184,   206,    19,     0,    52,   174,   167,
     189,     0,     0,   172,    60,     0,   196,   197,   194,     0,
     180,     0,   182,   205,   184,     0,    51,    82,   184,    96,
      95,   108,     0,   190,     0,     0,    62,   181,   183,    19,
      94,    83,     0,    97,   184,     0,     0,    92,    50,     0,
       0,     0,     0,   184,   184,   177,     0,     0,     0,     0,
     178,   179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,  -253,  -253,  -253,  -253,  -252,  -141,   213,   398,
     -51,  -161,  -253,  -253,   133,  -253,  -253,   230,   -96,  -253,
    -250,    42,  -253,  -253,   224,  -253,  -253,   162,  -253,   176,
    -253,  -253,    94,  -253,  -253,  -103,   -60,   131,     4,   417,
     418,   419,   423,    40,  -253,   403,   408,   208,   407,   412,
     207,   110,   401,   -37,   300,   270,  -253,  -253,  -253,  -120,
    -253,  -198,  -196,  -138,  -253,  -216,  -181,  -253,   -13,  -232,
    -188,  -238,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    53,   106,    28,   290,   201,   202,   291,
     292,   109,    29,   151,   280,   281,   196,   197,   147,   148,
     228,   144,   145,   223,   161,   342,   110,   265,   298,   299,
     300,   337,   273,    84,   183,   139,   328,   308,   140,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,   229,    48,   112,   243,
     244,   113,   114,   115,   372,   253,   285,   286,    49,    50,
     343,   289,   344
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   203,   108,   255,   294,    30,   171,   173,   184,   295,
     245,    85,   246,    85,    61,   282,   111,   293,    61,   193,
      85,    85,   251,    51,   321,   251,   316,   317,    61,    57,
     242,    54,    66,    67,    68,   187,  -168,   330,   203,   332,
      74,   333,    63,    81,    75,    61,   203,    69,    81,    55,
     329,    61,    61,    61,   177,   159,    52,   318,   234,   160,
     175,   176,    64,     1,   168,    62,   241,   198,   111,   341,
     247,   203,   355,    87,   203,   116,   203,   146,   149,   245,
     245,   246,   246,    86,   164,    86,   220,   167,   282,   149,
     149,   262,    86,    86,   267,   194,   225,   152,   252,   158,
     322,   252,    70,   166,   189,   121,   116,   141,   142,    71,
      72,   189,   346,     2,   245,   209,   246,    82,   162,    83,
     345,   245,    82,   246,    83,   111,   226,   260,   178,   215,
      61,   227,   389,    61,   373,    65,    58,    59,    60,   247,
     247,   396,   397,   111,   203,   358,   275,   233,   364,   363,
     204,   185,   186,    73,   271,    61,   146,   314,   315,   146,
      76,   111,   111,    77,   340,   200,    21,    22,    80,   206,
     111,    24,   218,   219,   247,   379,     5,   146,     6,   149,
     199,   247,   203,   159,   203,   216,   217,   160,   207,   208,
     136,   137,   348,   385,   386,   111,   150,   279,   111,   353,
     111,   165,   369,   203,   370,    78,    79,   203,   169,   239,
     174,   210,   301,   248,   211,   185,   186,   111,   203,   111,
       7,     8,   235,   380,   179,   237,   111,   382,   240,   149,
     180,    14,   221,    16,    17,    18,    19,    20,   387,   287,
     254,   256,   270,  -186,  -186,    14,    25,   170,    17,    18,
      19,    20,   111,   263,   111,   264,   111,   212,   213,   188,
      10,    11,    12,   356,   357,   190,   277,   278,   111,   191,
     323,   324,   304,    15,   192,   306,   309,   153,   154,    21,
      22,    23,   130,   131,    24,   134,   135,   195,   205,   222,
     214,   230,   305,   155,   231,   236,   156,   312,   238,   249,
      61,   335,   319,   350,   351,   352,   111,   250,   111,    81,
     258,   259,   172,   287,   163,     5,   266,     6,     7,     8,
       9,   272,    14,   157,    16,    17,    18,   111,    20,   274,
     276,   111,   288,   297,    14,   349,    16,    17,    18,    19,
      20,   296,   111,   302,   303,   367,   311,   111,   310,    14,
     309,    16,    17,    18,    19,    20,   111,   111,    10,    11,
      12,   287,   287,    13,   368,   313,   320,   325,   326,   327,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     331,   181,    24,    82,   138,   182,    -2,    26,   283,   284,
     334,    27,   336,   264,   384,   347,    88,     5,   359,     6,
     360,   361,   362,    14,   365,    16,    17,    18,    19,    20,
      89,   366,   393,   394,   374,    90,    91,    92,   376,    93,
     375,   377,   381,   378,    94,    95,   392,    96,   388,   398,
      97,   395,   390,   391,    98,    14,    99,    16,    17,    18,
      19,    20,   399,   100,   101,   400,   102,   103,   401,   104,
     269,   107,    14,   354,    16,    17,    18,    19,    20,   232,
     268,   261,   105,   339,   383,    88,     5,    25,     6,   122,
     123,   124,   125,   126,   127,   128,   338,   371,   117,    89,
     118,   129,   119,   132,    90,    91,    92,   120,    93,   133,
     143,   224,   257,    94,    95,     0,    96,     0,     0,    97,
       0,     0,     0,    98,     5,    99,     6,     7,     8,     9,
       0,     0,     0,   101,     0,   175,   176,     0,   104,     0,
       0,    14,     0,    16,    17,    18,    19,    20,     0,     0,
       0,   105,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,    24,     0,   138,    25,     0,    26,     0,     0,     5,
      27,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     5,
       0,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,     0,    24,     0,     0,    25,
       0,    26,    10,    11,    12,    27,     5,    13,     6,     7,
       8,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,     0,    24,     0,     0,    25,
       0,    26,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    88,     5,    24,     6,     0,    25,     0,    26,     0,
       0,     0,    27,     0,     0,    89,  -184,  -184,     0,     0,
      90,    91,    92,     0,    93,     0,     0,     0,     0,    94,
      95,     0,    96,     0,     0,    97,     0,     0,     0,    98,
       0,    99,     0,     0,     0,     0,     0,     0,     0,   101,
       0,   175,   176,     0,   104,    88,     5,    14,     6,    16,
      17,    18,    19,    20,     0,     0,     0,   105,     0,    89,
    -184,  -184,    25,     0,    90,    91,    92,     0,    93,     0,
       0,     0,     0,    94,    95,     0,    96,     0,     0,    97,
       0,     0,     0,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   101,     0,   175,   176,     0,   104,    88,
       5,    14,     6,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    89,     0,     0,    25,     0,    90,    91,
      92,     0,    93,     0,     0,   -16,     0,    94,    95,     0,
      96,     0,     0,    97,     0,     0,     0,    98,     0,    99,
       0,     0,     0,     0,     0,     0,     0,   101,     0,   175,
     176,     0,   104,    88,     5,    14,     6,    16,    17,    18,
      19,    20,     0,     0,     0,   105,     0,    89,     0,     0,
      25,     0,    90,    91,    92,     0,    93,     0,     0,     0,
       0,    94,    95,     0,    96,   -19,     0,    97,     0,     0,
       0,    98,     0,    99,     0,     0,     0,     0,     0,     0,
       0,   101,     0,   175,   176,     0,   104,    88,     5,    14,
       6,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    89,     0,     0,    25,     0,    90,    91,    92,     0,
      93,     0,     0,     0,     0,    94,    95,   -19,    96,     0,
       0,    97,     0,     0,     0,    98,     0,    99,     0,     0,
       0,     0,     0,     0,     0,   101,     0,   175,   176,     0,
     104,    88,     5,    14,     6,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    89,     0,     0,    25,     0,
      90,    91,    92,     0,    93,     0,     0,   -19,     0,    94,
      95,     0,    96,     0,     0,    97,     0,     0,     0,    98,
       0,    99,     0,     0,     0,     0,     0,     0,     0,   101,
       0,   175,   176,     0,   104,    88,     5,    14,     6,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,    89,
       0,     0,    25,     0,    90,    91,    92,     0,    93,     0,
       0,     0,     0,    94,    95,     0,    96,     0,     0,    97,
       0,     0,     0,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   101,     0,   175,   176,     0,   104,    88,
       5,    14,     6,    16,    17,    18,    19,    20,     0,     0,
       0,   105,     0,    89,     0,     0,    25,     0,    90,    91,
      92,     5,    93,     6,     7,     8,     0,    94,    95,     0,
      96,     0,     0,    97,     0,     0,     0,    98,     0,    99,
       0,     0,     0,     0,     0,     0,     0,   101,     0,   175,
     176,   -19,   104,     0,     0,    14,     0,    16,    17,    18,
      19,    20,     0,     0,    10,    11,    12,     0,     0,    13,
      25,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,    24,     0,
       0,    25
};

static const yytype_int16 yycheck[] =
{
      13,   162,    53,   219,   256,     1,   102,   103,   111,   259,
     208,     4,   208,     4,    21,   247,    53,   255,    21,     5,
       4,     4,     5,    70,     5,     5,    27,    28,    21,    25,
      30,    66,     7,     8,     9,   138,    36,   289,   199,   291,
      83,   293,    19,     5,    87,    21,   207,    22,     5,     9,
     288,    21,    21,    21,   105,    39,     0,    58,   199,    43,
      60,    61,    18,     3,   101,    20,   207,    37,   105,    72,
     208,   232,   322,    51,   235,    82,   237,    90,    91,   277,
     278,   277,   278,    76,    97,    76,   189,   100,   320,   102,
     103,   232,    76,    76,   235,    81,   192,    93,    81,    95,
      81,    81,    77,    99,    80,    65,    82,    85,    86,    84,
      85,    80,    80,    53,   312,    77,   312,    79,    96,    81,
     308,   319,    79,   319,    81,   162,    73,   230,   106,   180,
      21,    78,   384,    21,   350,    17,    26,    27,     4,   277,
     278,   393,   394,   180,   305,   326,   242,   198,   336,    37,
     163,    25,    26,    86,    45,    21,   169,   277,   278,   172,
      23,   198,   199,    88,   305,   161,    73,    74,    91,   165,
     207,    78,   185,   186,   312,   363,    11,   190,    13,   192,
     158,   319,   343,    39,   345,   181,   182,    43,   166,   167,
      80,    66,   312,   374,   375,   232,    32,    71,   235,   319,
     237,    49,   343,   364,   345,    89,    90,   368,    29,   205,
      69,   169,   263,   209,   172,    25,    26,   254,   379,   256,
      14,    15,   200,   364,     4,   203,   263,   368,   206,   242,
      76,    66,   190,    68,    69,    70,    71,    72,   379,   252,
     218,   219,   238,    25,    26,    66,    81,    68,    69,    70,
      71,    72,   289,    34,   291,    36,   293,    64,    65,    82,
      54,    55,    56,   323,   324,    80,   244,   245,   305,    77,
     283,   284,   268,    67,    80,   271,   272,    25,    26,    73,
      74,    75,    74,    75,    78,    78,    79,    66,    77,    83,
      68,    81,   270,    41,    80,    42,    44,   275,    47,    62,
      21,   297,   280,   316,   317,   318,   343,    78,   345,     5,
      82,    80,    29,   326,    46,    11,    40,    13,    14,    15,
      16,    49,    66,    71,    68,    69,    70,   364,    72,    36,
      36,   368,     4,    35,    66,   313,    68,    69,    70,    71,
      72,    82,   379,    33,    42,   341,    50,   384,    36,    66,
     346,    68,    69,    70,    71,    72,   393,   394,    54,    55,
      56,   374,   375,    59,   342,    57,    80,    82,    80,     5,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      36,    77,    78,    79,    80,    81,     0,    83,    51,    52,
      36,    87,    34,    36,   372,    48,    10,    11,    36,    13,
      25,    36,    26,    66,    36,    68,    69,    70,    71,    72,
      24,    62,   390,   391,    81,    29,    30,    31,    82,    33,
      81,    25,    33,    26,    38,    39,    36,    41,    62,    36,
      44,    71,    82,    82,    48,    66,    50,    68,    69,    70,
      71,    72,    36,    57,    58,    71,    60,    61,    71,    63,
     237,    53,    66,   320,    68,    69,    70,    71,    72,     4,
     236,   231,    76,   301,   370,    10,    11,    81,    13,    66,
      67,    68,    69,    70,    71,    72,   300,   346,    61,    24,
      62,    73,    63,    76,    29,    30,    31,    64,    33,    77,
      89,   191,   222,    38,    39,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    11,    50,    13,    14,    15,    16,
      -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    78,    -1,    80,    81,    -1,    83,    -1,    -1,    11,
      87,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    54,    55,    56,    87,    11,    59,    13,    14,
      15,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    10,    11,    78,    13,    -1,    81,    -1,    83,    -1,
      -1,    -1,    87,    -1,    -1,    24,    25,    26,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,    -1,    63,    10,    11,    66,    13,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    24,
      25,    26,    81,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,    10,
      11,    66,    13,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    81,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    -1,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    -1,    63,    10,    11,    66,    13,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    24,    -1,    -1,
      81,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    42,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    61,    -1,    63,    10,    11,    66,
      13,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    81,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,    -1,
      63,    10,    11,    66,    13,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    81,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    -1,    38,
      39,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,    -1,    63,    10,    11,    66,    13,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    81,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,    10,
      11,    66,    13,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    24,    -1,    -1,    81,    -1,    29,    30,
      31,    11,    33,    13,    14,    15,    -1,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    63,    -1,    -1,    66,    -1,    68,    69,    70,
      71,    72,    -1,    -1,    54,    55,    56,    -1,    -1,    59,
      81,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    78,    -1,
      -1,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    93,    94,    11,    13,    14,    15,    16,
      54,    55,    56,    59,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    78,    81,    83,    87,    97,   104,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   149,   160,
     161,    70,     0,    95,    66,   135,   160,   130,   143,   143,
       4,    21,    20,    19,    18,    17,     7,     8,     9,    22,
      77,    84,    85,    86,    83,    87,    23,    88,    89,    90,
      91,     5,    79,    81,   125,     4,    76,   164,    10,    24,
      29,    30,    31,    33,    38,    39,    41,    44,    48,    50,
      57,    58,    60,    61,    63,    76,    96,   101,   102,   103,
     118,   145,   150,   153,   154,   155,    82,   131,   132,   133,
     134,   135,   137,   137,   137,   137,   137,   137,   137,   138,
     139,   139,   140,   141,   142,   142,   143,    66,    80,   127,
     130,   164,   164,   144,   113,   114,   160,   110,   111,   160,
      32,   105,   130,    25,    26,    41,    44,    71,   130,    39,
      43,   116,   164,    46,   160,    49,   130,   160,   145,    29,
      68,   110,    29,   110,    69,    60,    61,   102,   164,     4,
      76,    77,    81,   126,   127,    25,    26,   127,    82,    80,
      80,    77,    80,     5,    81,    66,   108,   109,    37,   164,
     130,    99,   100,   103,   160,    77,   130,   164,   164,    77,
     113,   113,    64,    65,    68,   102,   130,   130,   160,   160,
     127,   113,    83,   115,   146,   110,    73,    78,   112,   148,
      81,    80,     4,   102,    99,   164,    42,   164,    47,   130,
     164,    99,    30,   151,   152,   153,   154,   155,   130,    62,
      78,     5,    81,   157,   164,   157,   164,   147,    82,    80,
     127,   109,    99,    34,    36,   119,    40,    99,   116,   100,
     130,    45,    49,   124,    36,   110,    36,   164,   164,    71,
     106,   107,   161,    51,    52,   158,   159,   160,     4,   163,
      98,   101,   102,   163,    98,   112,    82,    35,   120,   121,
     122,   102,    33,    42,   130,   164,   130,    34,   129,   130,
      36,    50,   164,    57,   151,   151,    27,    28,    58,   164,
      80,     5,    81,   160,   160,    82,    80,     5,   128,   163,
      98,    36,    98,    98,    36,   130,    34,   123,   121,   119,
      99,    72,   117,   162,   164,   162,    80,    48,   151,   164,
     160,   160,   160,   151,   106,   112,   128,   128,   158,    36,
      25,    36,    26,    37,   162,    36,    62,   130,   164,    99,
      99,   129,   156,   157,    81,    81,    82,    25,    26,   162,
      99,    33,    99,   124,   164,   158,   158,    99,    62,    98,
      82,    82,    36,   164,   164,    71,    98,    98,    36,    36,
      71,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   108,   109,   109,   110,   110,   111,
     111,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   123,   123,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   137,
     137,   138,   138,   138,   139,   139,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   145,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   148,   148,   149,   149,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   154,   154,   155,   155,   155,   156,
     156,   157,   157,   158,   158,   159,   159,   159,   160,   160,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   164,   164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     0,     3,     2,     2,
       3,     3,     2,     2,     0,     2,     0,     1,     2,     0,
       1,     2,     3,     2,     1,     2,     1,     3,     2,     2,
       2,     3,     2,     3,     1,     5,     6,     6,     4,     1,
       2,     2,     2,     2,     2,     4,     1,     4,     4,     2,
      10,     8,     7,     6,     1,     3,     2,     0,     1,     1,
       3,     1,     4,     2,     4,     1,     3,     1,     3,     1,
       4,     2,     1,     3,     1,     3,     3,     1,     2,     1,
       1,     0,     2,     9,     5,     7,     0,     2,     0,     1,
       1,     2,     5,     0,     3,     0,     4,     5,     1,     3,
       0,     1,     1,     3,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     2,     2,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     7,     0,     1,
       3,     2,     4,     2,     4,     1,     3,     9,    11,    11,
       7,     8,     7,     8,     0,     1,     2,     1,     1,     0,
       1,     1,     3,     1,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     2,     1,
       1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PARSER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PARSER_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF

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
#if PARSER_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser_ctx_t *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (ctx);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, parser_ctx_t *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, ctx);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, parser_ctx_t *ctx)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !PARSER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PARSER_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, parser_ctx_t *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (parser_ctx_t *ctx)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, ctx);
    }

  if (yychar <= PARSER_EOF)
    {
      yychar = PARSER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PARSER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PARSER_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = PARSER_EMPTY;
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
  case 3: /* Program: tEXPRESSION ExpressionNl_opt  */
#line 164 "parser.y"
                                            { handle_isexpression_script(ctx, (yyvsp[0].expression)); }
#line 2040 "parser.tab.c"
    break;

  case 5: /* OptionExplicit_opt: tOPTION tEXPLICIT StSep  */
#line 168 "parser.y"
                                            { ctx->option_explicit = TRUE; }
#line 2046 "parser.tab.c"
    break;

  case 7: /* SourceElements: SourceElements GlobalDimDeclaration StSep  */
#line 173 "parser.y"
                                            { source_add_statement(ctx, (yyvsp[-1].statement)); }
#line 2052 "parser.tab.c"
    break;

  case 8: /* SourceElements: SourceElements StatementNl  */
#line 174 "parser.y"
                                            { source_add_statement(ctx, (yyvsp[0].statement)); }
#line 2058 "parser.tab.c"
    break;

  case 9: /* SourceElements: SourceElements ClassDeclaration  */
#line 175 "parser.y"
                                            { source_add_class(ctx, (yyvsp[0].class_decl)); }
#line 2064 "parser.tab.c"
    break;

  case 10: /* GlobalDimDeclaration: tPRIVATE tCONST ConstDeclList  */
#line 178 "parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2070 "parser.tab.c"
    break;

  case 11: /* GlobalDimDeclaration: tPUBLIC tCONST ConstDeclList  */
#line 179 "parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2076 "parser.tab.c"
    break;

  case 12: /* GlobalDimDeclaration: tPRIVATE DimDeclList  */
#line 180 "parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2082 "parser.tab.c"
    break;

  case 13: /* GlobalDimDeclaration: tPUBLIC DimDeclList  */
#line 181 "parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2088 "parser.tab.c"
    break;

  case 14: /* ExpressionNl_opt: %empty  */
#line 184 "parser.y"
                                            { (yyval.expression) = NULL; }
#line 2094 "parser.tab.c"
    break;

  case 15: /* ExpressionNl_opt: Expression tNL  */
#line 185 "parser.y"
                                            { (yyval.expression) = (yyvsp[-1].expression); }
#line 2100 "parser.tab.c"
    break;

  case 16: /* BodyStatements: %empty  */
#line 188 "parser.y"
                                            { (yyval.statement) = NULL; }
#line 2106 "parser.tab.c"
    break;

  case 17: /* BodyStatements: Statement  */
#line 189 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2112 "parser.tab.c"
    break;

  case 18: /* BodyStatements: StatementNl BodyStatements  */
#line 190 "parser.y"
                                            { (yyval.statement) = link_statements((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 2118 "parser.tab.c"
    break;

  case 19: /* StatementsNl_opt: %empty  */
#line 193 "parser.y"
                                            { (yyval.statement) = NULL; }
#line 2124 "parser.tab.c"
    break;

  case 20: /* StatementsNl_opt: StatementsNl  */
#line 194 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2130 "parser.tab.c"
    break;

  case 21: /* StatementsNl: SimpleStatement StSep  */
#line 197 "parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2136 "parser.tab.c"
    break;

  case 22: /* StatementsNl: SimpleStatement StSep StatementsNl  */
#line 198 "parser.y"
                                            { (yyval.statement) = link_statements((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2142 "parser.tab.c"
    break;

  case 23: /* StatementNl: Statement tNL  */
#line 201 "parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2148 "parser.tab.c"
    break;

  case 24: /* Statement: ':'  */
#line 204 "parser.y"
                                            { (yyval.statement) = NULL; }
#line 2154 "parser.tab.c"
    break;

  case 25: /* Statement: ':' Statement  */
#line 205 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2160 "parser.tab.c"
    break;

  case 26: /* Statement: SimpleStatement  */
#line 206 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2166 "parser.tab.c"
    break;

  case 27: /* Statement: SimpleStatement ':' Statement  */
#line 207 "parser.y"
                                            { (yyvsp[-2].statement)->next = (yyvsp[0].statement); (yyval.statement) = (yyvsp[-2].statement); }
#line 2172 "parser.tab.c"
    break;

  case 28: /* Statement: SimpleStatement ':'  */
#line 208 "parser.y"
                                            { (yyval.statement) = (yyvsp[-1].statement); }
#line 2178 "parser.tab.c"
    break;

  case 29: /* SimpleStatement: CallExpression ArgumentList_opt  */
#line 211 "parser.y"
                                            { call_expression_t *call_expr = make_call_expression(ctx, (yyvsp[-1].expression), (yyvsp[0].expression)); CHECK_ERROR;
                                              (yyval.statement) = new_call_statement(ctx, (yyloc), &call_expr->expr); CHECK_ERROR; }
#line 2185 "parser.tab.c"
    break;

  case 30: /* SimpleStatement: tCALL UnaryExpression  */
#line 213 "parser.y"
                                            { (yyval.statement) = new_call_statement(ctx, (yyloc), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2191 "parser.tab.c"
    break;

  case 31: /* SimpleStatement: CallExpression '=' Expression  */
#line 215 "parser.y"
                                            { (yyval.statement) = new_assign_statement(ctx, (yyloc), (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2197 "parser.tab.c"
    break;

  case 32: /* SimpleStatement: tDIM DimDeclList  */
#line 216 "parser.y"
                                            { (yyval.statement) = new_dim_statement(ctx, (yyloc), (yyvsp[0].dim_decl)); CHECK_ERROR; }
#line 2203 "parser.tab.c"
    break;

  case 33: /* SimpleStatement: tREDIM Preserve_opt ReDimDeclList  */
#line 217 "parser.y"
                                            { (yyval.statement) = new_redim_statement(ctx, (yyloc), (yyvsp[-1].boolean), (yyvsp[0].redim_decl)); CHECK_ERROR; }
#line 2209 "parser.tab.c"
    break;

  case 34: /* SimpleStatement: IfStatement  */
#line 218 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2215 "parser.tab.c"
    break;

  case 35: /* SimpleStatement: tWHILE Expression StSep StatementsNl_opt tWEND  */
#line 220 "parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), STAT_WHILE, (yyvsp[-3].expression), (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2221 "parser.tab.c"
    break;

  case 36: /* SimpleStatement: tDO DoType Expression StSep StatementsNl_opt tLOOP  */
#line 222 "parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), (yyvsp[-4].boolean) ? STAT_WHILELOOP : STAT_UNTIL, (yyvsp[-3].expression), (yyvsp[-1].statement));
                                              CHECK_ERROR; }
#line 2228 "parser.tab.c"
    break;

  case 37: /* SimpleStatement: tDO StSep StatementsNl_opt tLOOP DoType Expression  */
#line 225 "parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yylsp[-2]), (yyvsp[-1].boolean) ? STAT_DOWHILE : STAT_DOUNTIL, (yyvsp[0].expression), (yyvsp[-3].statement));
                                              CHECK_ERROR; }
#line 2235 "parser.tab.c"
    break;

  case 38: /* SimpleStatement: tDO StSep StatementsNl_opt tLOOP  */
#line 227 "parser.y"
                                            { (yyval.statement) = new_while_statement(ctx, (yyloc), STAT_DOWHILE, NULL, (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2241 "parser.tab.c"
    break;

  case 39: /* SimpleStatement: FunctionDecl  */
#line 228 "parser.y"
                                            { (yyval.statement) = new_function_statement(ctx, (yyloc), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 2247 "parser.tab.c"
    break;

  case 40: /* SimpleStatement: tEXIT tDO  */
#line 229 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITDO, 0, (yyloc)); CHECK_ERROR; }
#line 2253 "parser.tab.c"
    break;

  case 41: /* SimpleStatement: tEXIT tFOR  */
#line 230 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITFOR, 0, (yyloc)); CHECK_ERROR; }
#line 2259 "parser.tab.c"
    break;

  case 42: /* SimpleStatement: tEXIT tFUNCTION  */
#line 231 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITFUNC, 0, (yyloc)); CHECK_ERROR; }
#line 2265 "parser.tab.c"
    break;

  case 43: /* SimpleStatement: tEXIT tPROPERTY  */
#line 232 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITPROP, 0, (yyloc)); CHECK_ERROR; }
#line 2271 "parser.tab.c"
    break;

  case 44: /* SimpleStatement: tEXIT tSUB  */
#line 233 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_EXITSUB, 0, (yyloc)); CHECK_ERROR; }
#line 2277 "parser.tab.c"
    break;

  case 45: /* SimpleStatement: tSET CallExpression '=' Expression  */
#line 234 "parser.y"
                                            { (yyval.statement) = new_set_statement(ctx, (yyloc), (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2283 "parser.tab.c"
    break;

  case 46: /* SimpleStatement: tSTOP  */
#line 235 "parser.y"
                                            { (yyval.statement) = new_statement(ctx, STAT_STOP, 0, (yyloc)); CHECK_ERROR; }
#line 2289 "parser.tab.c"
    break;

  case 47: /* SimpleStatement: tON tERROR tRESUME tNEXT  */
#line 236 "parser.y"
                                            { (yyval.statement) = new_onerror_statement(ctx, (yyloc), TRUE); CHECK_ERROR; }
#line 2295 "parser.tab.c"
    break;

  case 48: /* SimpleStatement: tON tERROR tGOTO '0'  */
#line 237 "parser.y"
                                            { (yyval.statement) = new_onerror_statement(ctx, (yyloc), FALSE); CHECK_ERROR; }
#line 2301 "parser.tab.c"
    break;

  case 49: /* SimpleStatement: tCONST ConstDeclList  */
#line 238 "parser.y"
                                            { (yyval.statement) = new_const_statement(ctx, (yyloc), (yyvsp[0].const_decl)); CHECK_ERROR; }
#line 2307 "parser.tab.c"
    break;

  case 50: /* SimpleStatement: tFOR Identifier '=' Expression tTO Expression Step_opt StSep StatementsNl_opt tNEXT  */
#line 240 "parser.y"
                                            { (yyval.statement) = new_forto_statement(ctx, (yyloc), (yyvsp[-8].string), (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-3].expression), (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2313 "parser.tab.c"
    break;

  case 51: /* SimpleStatement: tFOR tEACH Identifier tIN Expression StSep StatementsNl_opt tNEXT  */
#line 242 "parser.y"
                                            { (yyval.statement) = new_foreach_statement(ctx, (yyloc), (yyvsp[-5].string), (yyvsp[-3].expression), (yyvsp[-1].statement)); }
#line 2319 "parser.tab.c"
    break;

  case 52: /* SimpleStatement: tSELECT tCASE Expression StSep CaseClausules tEND tSELECT  */
#line 244 "parser.y"
                                            { (yyval.statement) = new_select_statement(ctx, (yyloc), (yyvsp[-4].expression), (yyvsp[-2].case_clausule)); }
#line 2325 "parser.tab.c"
    break;

  case 53: /* SimpleStatement: tWITH Expression StSep StatementsNl_opt tEND tWITH  */
#line 246 "parser.y"
                                            { (yyval.statement) = new_with_statement(ctx, (yyloc), (yyvsp[-4].expression), (yyvsp[-2].statement)); }
#line 2331 "parser.tab.c"
    break;

  case 54: /* MemberExpression: Identifier  */
#line 249 "parser.y"
                                            { (yyval.member) = new_member_expression(ctx, NULL, (yyvsp[0].string)); CHECK_ERROR; }
#line 2337 "parser.tab.c"
    break;

  case 55: /* MemberExpression: CallExpression '.' tIdentifier  */
#line 250 "parser.y"
                                            { (yyval.member) = new_member_expression(ctx, (yyvsp[-2].expression), (yyvsp[0].string)); CHECK_ERROR; }
#line 2343 "parser.tab.c"
    break;

  case 56: /* MemberExpression: tDOT tIdentifier  */
#line 251 "parser.y"
                                            { expression_t *dot_expr = new_expression(ctx, EXPR_DOT, sizeof(*dot_expr)); CHECK_ERROR;
                                              (yyval.member) = new_member_expression(ctx, dot_expr, (yyvsp[0].string)); CHECK_ERROR; }
#line 2350 "parser.tab.c"
    break;

  case 57: /* Preserve_opt: %empty  */
#line 255 "parser.y"
                                            { (yyval.boolean) = FALSE; }
#line 2356 "parser.tab.c"
    break;

  case 58: /* Preserve_opt: tPRESERVE  */
#line 256 "parser.y"
                                            { (yyval.boolean) = TRUE; }
#line 2362 "parser.tab.c"
    break;

  case 59: /* MemberDeclList: MemberDecl  */
#line 259 "parser.y"
                                            { (yyval.dim_decl) = (yyvsp[0].dim_decl); }
#line 2368 "parser.tab.c"
    break;

  case 60: /* MemberDeclList: MemberDecl ',' MemberDeclList  */
#line 260 "parser.y"
                                             { (yyvsp[-2].dim_decl)->next = (yyvsp[0].dim_decl); (yyval.dim_decl) = (yyvsp[-2].dim_decl); }
#line 2374 "parser.tab.c"
    break;

  case 61: /* MemberDecl: MemberIdentifier  */
#line 263 "parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[0].string), FALSE, NULL); CHECK_ERROR; }
#line 2380 "parser.tab.c"
    break;

  case 62: /* MemberDecl: MemberIdentifier '(' DimList ')'  */
#line 264 "parser.y"
                                                  { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-3].string), TRUE, (yyvsp[-1].dim_list)); CHECK_ERROR; }
#line 2386 "parser.tab.c"
    break;

  case 63: /* MemberDecl: MemberIdentifier tEMPTYBRACKETS  */
#line 265 "parser.y"
                                                  { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-1].string), TRUE, NULL); CHECK_ERROR; }
#line 2392 "parser.tab.c"
    break;

  case 64: /* ReDimDecl: tIdentifier '(' ArgumentList ')'  */
#line 268 "parser.y"
                                            { (yyval.redim_decl) = new_redim_decl(ctx, (yyvsp[-3].string), (yyvsp[-1].expression)); CHECK_ERROR; }
#line 2398 "parser.tab.c"
    break;

  case 65: /* ReDimDeclList: ReDimDecl  */
#line 271 "parser.y"
                                            { (yyval.redim_decl) = (yyvsp[0].redim_decl); }
#line 2404 "parser.tab.c"
    break;

  case 66: /* ReDimDeclList: ReDimDecl ',' ReDimDeclList  */
#line 272 "parser.y"
                                            { (yyvsp[-2].redim_decl)->next = (yyvsp[0].redim_decl); (yyval.redim_decl) = (yyvsp[-2].redim_decl); }
#line 2410 "parser.tab.c"
    break;

  case 67: /* DimDeclList: DimDecl  */
#line 275 "parser.y"
                                            { (yyval.dim_decl) = (yyvsp[0].dim_decl); }
#line 2416 "parser.tab.c"
    break;

  case 68: /* DimDeclList: DimDecl ',' DimDeclList  */
#line 276 "parser.y"
                                            { (yyvsp[-2].dim_decl)->next = (yyvsp[0].dim_decl); (yyval.dim_decl) = (yyvsp[-2].dim_decl); }
#line 2422 "parser.tab.c"
    break;

  case 69: /* DimDecl: Identifier  */
#line 279 "parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[0].string), FALSE, NULL); CHECK_ERROR; }
#line 2428 "parser.tab.c"
    break;

  case 70: /* DimDecl: Identifier '(' DimList ')'  */
#line 280 "parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-3].string), TRUE, (yyvsp[-1].dim_list)); CHECK_ERROR; }
#line 2434 "parser.tab.c"
    break;

  case 71: /* DimDecl: Identifier tEMPTYBRACKETS  */
#line 281 "parser.y"
                                            { (yyval.dim_decl) = new_dim_decl(ctx, (yyvsp[-1].string), TRUE, NULL); CHECK_ERROR; }
#line 2440 "parser.tab.c"
    break;

  case 72: /* DimList: IntegerValue  */
#line 284 "parser.y"
                                            { (yyval.dim_list) = new_dim(ctx, (yyvsp[0].uint), NULL); }
#line 2446 "parser.tab.c"
    break;

  case 73: /* DimList: IntegerValue ',' DimList  */
#line 285 "parser.y"
                                            { (yyval.dim_list) = new_dim(ctx, (yyvsp[-2].uint), (yyvsp[0].dim_list)); }
#line 2452 "parser.tab.c"
    break;

  case 74: /* ConstDeclList: ConstDecl  */
#line 288 "parser.y"
                                            { (yyval.const_decl) = (yyvsp[0].const_decl); }
#line 2458 "parser.tab.c"
    break;

  case 75: /* ConstDeclList: ConstDecl ',' ConstDeclList  */
#line 289 "parser.y"
                                            { (yyvsp[-2].const_decl)->next = (yyvsp[0].const_decl); (yyval.const_decl) = (yyvsp[-2].const_decl); }
#line 2464 "parser.tab.c"
    break;

  case 76: /* ConstDecl: Identifier '=' ConstExpression  */
#line 292 "parser.y"
                                            { (yyval.const_decl) = new_const_decl(ctx, (yyvsp[-2].string), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2470 "parser.tab.c"
    break;

  case 77: /* ConstExpression: LiteralExpression  */
#line 295 "parser.y"
                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 2476 "parser.tab.c"
    break;

  case 78: /* ConstExpression: '-' NumericLiteralExpression  */
#line 296 "parser.y"
                                            { (yyval.expression) = new_unary_expression(ctx, EXPR_NEG, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2482 "parser.tab.c"
    break;

  case 79: /* DoType: tWHILE  */
#line 299 "parser.y"
                    { (yyval.boolean) = TRUE; }
#line 2488 "parser.tab.c"
    break;

  case 80: /* DoType: tUNTIL  */
#line 300 "parser.y"
                    { (yyval.boolean) = FALSE; }
#line 2494 "parser.tab.c"
    break;

  case 81: /* Step_opt: %empty  */
#line 303 "parser.y"
                                            { (yyval.expression) = NULL;}
#line 2500 "parser.tab.c"
    break;

  case 82: /* Step_opt: tSTEP Expression  */
#line 304 "parser.y"
                                            { (yyval.expression) = (yyvsp[0].expression); }
#line 2506 "parser.tab.c"
    break;

  case 83: /* IfStatement: tIF Expression tTHEN tNL StatementsNl_opt ElseIfs_opt Else_opt tEND tIF  */
#line 308 "parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-7].expression), (yyvsp[-4].statement), (yyvsp[-3].elseif), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 2512 "parser.tab.c"
    break;

  case 84: /* IfStatement: tIF Expression tTHEN Statement EndIf_opt  */
#line 309 "parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-3].expression), (yyvsp[-1].statement), NULL, NULL); CHECK_ERROR; }
#line 2518 "parser.tab.c"
    break;

  case 85: /* IfStatement: tIF Expression tTHEN Statement tELSE Statement EndIf_opt  */
#line 311 "parser.y"
                                               { (yyval.statement) = new_if_statement(ctx, (yyloc), (yyvsp[-5].expression), (yyvsp[-3].statement), NULL, (yyvsp[-1].statement)); CHECK_ERROR; }
#line 2524 "parser.tab.c"
    break;

  case 88: /* ElseIfs_opt: %empty  */
#line 318 "parser.y"
                                            { (yyval.elseif) = NULL; }
#line 2530 "parser.tab.c"
    break;

  case 89: /* ElseIfs_opt: ElseIfs  */
#line 319 "parser.y"
                                            { (yyval.elseif) = (yyvsp[0].elseif); }
#line 2536 "parser.tab.c"
    break;

  case 90: /* ElseIfs: ElseIf  */
#line 322 "parser.y"
                                            { (yyval.elseif) = (yyvsp[0].elseif); }
#line 2542 "parser.tab.c"
    break;

  case 91: /* ElseIfs: ElseIf ElseIfs  */
#line 323 "parser.y"
                                            { (yyvsp[-1].elseif)->next = (yyvsp[0].elseif); (yyval.elseif) = (yyvsp[-1].elseif); }
#line 2548 "parser.tab.c"
    break;

  case 92: /* ElseIf: tELSEIF Expression tTHEN StSep_opt StatementsNl_opt  */
#line 327 "parser.y"
                                            { (yyval.elseif) = new_elseif_decl(ctx, (yyloc), (yyvsp[-3].expression), (yyvsp[0].statement)); }
#line 2554 "parser.tab.c"
    break;

  case 93: /* Else_opt: %empty  */
#line 330 "parser.y"
                                            { (yyval.statement) = NULL; }
#line 2560 "parser.tab.c"
    break;

  case 94: /* Else_opt: tELSE StSep_opt StatementsNl_opt  */
#line 331 "parser.y"
                                            { (yyval.statement) = (yyvsp[0].statement); }
#line 2566 "parser.tab.c"
    break;

  case 95: /* CaseClausules: %empty  */
#line 334 "parser.y"
                                                                       { (yyval.case_clausule) = NULL; }
#line 2572 "parser.tab.c"
    break;

  case 96: /* CaseClausules: tCASE tELSE StSep_opt StatementsNl_opt  */
#line 335 "parser.y"
                                                                       { (yyval.case_clausule) = new_case_clausule(ctx, NULL, (yyvsp[0].statement), NULL); }
#line 2578 "parser.tab.c"
    break;

  case 97: /* CaseClausules: tCASE ExpressionList StSep_opt StatementsNl_opt CaseClausules  */
#line 336 "parser.y"
                                                                       { (yyval.case_clausule) = new_case_clausule(ctx, (yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].case_clausule)); }
#line 2584 "parser.tab.c"
    break;

  case 98: /* Arguments: tEMPTYBRACKETS  */
#line 339 "parser.y"
                                    { (yyval.expression) = NULL; }
#line 2590 "parser.tab.c"
    break;

  case 99: /* Arguments: '(' ArgumentList ')'  */
#line 340 "parser.y"
                                    { (yyval.expression) = (yyvsp[-1].expression); }
#line 2596 "parser.tab.c"
    break;

  case 100: /* ArgumentList_opt: %empty  */
#line 343 "parser.y"
                                    { (yyval.expression) = NULL; }
#line 2602 "parser.tab.c"
    break;

  case 101: /* ArgumentList_opt: ArgumentList  */
#line 344 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2608 "parser.tab.c"
    break;

  case 102: /* ArgumentList: Expression  */
#line 347 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2614 "parser.tab.c"
    break;

  case 103: /* ArgumentList: Expression ',' ArgumentList  */
#line 348 "parser.y"
                                    { (yyvsp[-2].expression)->next = (yyvsp[0].expression); (yyval.expression) = (yyvsp[-2].expression); }
#line 2620 "parser.tab.c"
    break;

  case 104: /* ArgumentList: ',' ArgumentList  */
#line 349 "parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NOARG, 0); CHECK_ERROR; (yyval.expression)->next = (yyvsp[0].expression); }
#line 2626 "parser.tab.c"
    break;

  case 107: /* ExpressionList: Expression  */
#line 356 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2632 "parser.tab.c"
    break;

  case 108: /* ExpressionList: Expression ',' ExpressionList  */
#line 357 "parser.y"
                                    { (yyvsp[-2].expression)->next = (yyvsp[0].expression); (yyval.expression) = (yyvsp[-2].expression); }
#line 2638 "parser.tab.c"
    break;

  case 109: /* Expression: EqvExpression  */
#line 360 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2644 "parser.tab.c"
    break;

  case 110: /* Expression: Expression tIMP EqvExpression  */
#line 361 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IMP, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2650 "parser.tab.c"
    break;

  case 111: /* EqvExpression: XorExpression  */
#line 364 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2656 "parser.tab.c"
    break;

  case 112: /* EqvExpression: EqvExpression tEQV XorExpression  */
#line 365 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EQV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2662 "parser.tab.c"
    break;

  case 113: /* XorExpression: OrExpression  */
#line 368 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2668 "parser.tab.c"
    break;

  case 114: /* XorExpression: XorExpression tXOR OrExpression  */
#line 369 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_XOR, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2674 "parser.tab.c"
    break;

  case 115: /* OrExpression: AndExpression  */
#line 372 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2680 "parser.tab.c"
    break;

  case 116: /* OrExpression: OrExpression tOR AndExpression  */
#line 373 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_OR, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2686 "parser.tab.c"
    break;

  case 117: /* AndExpression: NotExpression  */
#line 376 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2692 "parser.tab.c"
    break;

  case 118: /* AndExpression: AndExpression tAND NotExpression  */
#line 377 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_AND, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2698 "parser.tab.c"
    break;

  case 119: /* NotExpression: EqualityExpression  */
#line 380 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2704 "parser.tab.c"
    break;

  case 120: /* NotExpression: tNOT NotExpression  */
#line 381 "parser.y"
                                    { (yyval.expression) = new_unary_expression(ctx, EXPR_NOT, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2710 "parser.tab.c"
    break;

  case 121: /* EqualityExpression: ConcatExpression  */
#line 384 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2716 "parser.tab.c"
    break;

  case 122: /* EqualityExpression: EqualityExpression '=' ConcatExpression  */
#line 385 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EQUAL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2722 "parser.tab.c"
    break;

  case 123: /* EqualityExpression: EqualityExpression tNEQ ConcatExpression  */
#line 386 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_NEQUAL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2728 "parser.tab.c"
    break;

  case 124: /* EqualityExpression: EqualityExpression '>' ConcatExpression  */
#line 387 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_GT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2734 "parser.tab.c"
    break;

  case 125: /* EqualityExpression: EqualityExpression '<' ConcatExpression  */
#line 388 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_LT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2740 "parser.tab.c"
    break;

  case 126: /* EqualityExpression: EqualityExpression tGTEQ ConcatExpression  */
#line 389 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_GTEQ, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2746 "parser.tab.c"
    break;

  case 127: /* EqualityExpression: EqualityExpression tLTEQ ConcatExpression  */
#line 390 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_LTEQ, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2752 "parser.tab.c"
    break;

  case 128: /* EqualityExpression: EqualityExpression tIS ConcatExpression  */
#line 391 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IS, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2758 "parser.tab.c"
    break;

  case 129: /* ConcatExpression: AdditiveExpression  */
#line 394 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2764 "parser.tab.c"
    break;

  case 130: /* ConcatExpression: ConcatExpression '&' AdditiveExpression  */
#line 395 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_CONCAT, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2770 "parser.tab.c"
    break;

  case 131: /* AdditiveExpression: ModExpression  */
#line 398 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2776 "parser.tab.c"
    break;

  case 132: /* AdditiveExpression: AdditiveExpression '+' ModExpression  */
#line 399 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_ADD, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2782 "parser.tab.c"
    break;

  case 133: /* AdditiveExpression: AdditiveExpression '-' ModExpression  */
#line 400 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_SUB, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2788 "parser.tab.c"
    break;

  case 134: /* ModExpression: IntdivExpression  */
#line 403 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2794 "parser.tab.c"
    break;

  case 135: /* ModExpression: ModExpression tMOD IntdivExpression  */
#line 404 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2800 "parser.tab.c"
    break;

  case 136: /* IntdivExpression: MultiplicativeExpression  */
#line 407 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2806 "parser.tab.c"
    break;

  case 137: /* IntdivExpression: IntdivExpression '\\' MultiplicativeExpression  */
#line 409 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_IDIV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2812 "parser.tab.c"
    break;

  case 138: /* MultiplicativeExpression: ExpExpression  */
#line 412 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2818 "parser.tab.c"
    break;

  case 139: /* MultiplicativeExpression: MultiplicativeExpression '*' ExpExpression  */
#line 414 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2824 "parser.tab.c"
    break;

  case 140: /* MultiplicativeExpression: MultiplicativeExpression '/' ExpExpression  */
#line 416 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2830 "parser.tab.c"
    break;

  case 141: /* ExpExpression: SignExpression  */
#line 419 "parser.y"
                                                { (yyval.expression) = (yyvsp[0].expression); }
#line 2836 "parser.tab.c"
    break;

  case 142: /* ExpExpression: ExpExpression '^' SignExpression  */
#line 420 "parser.y"
                                                { (yyval.expression) = new_binary_expression(ctx, EXPR_EXP, (yyvsp[-2].expression), (yyvsp[0].expression)); CHECK_ERROR; }
#line 2842 "parser.tab.c"
    break;

  case 143: /* SignExpression: UnaryExpression  */
#line 423 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2848 "parser.tab.c"
    break;

  case 144: /* SignExpression: '-' SignExpression  */
#line 424 "parser.y"
                                    { (yyval.expression) = new_unary_expression(ctx, EXPR_NEG, (yyvsp[0].expression)); CHECK_ERROR; }
#line 2854 "parser.tab.c"
    break;

  case 145: /* SignExpression: '+' SignExpression  */
#line 425 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2860 "parser.tab.c"
    break;

  case 146: /* UnaryExpression: LiteralExpression  */
#line 428 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2866 "parser.tab.c"
    break;

  case 147: /* UnaryExpression: CallExpression  */
#line 429 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2872 "parser.tab.c"
    break;

  case 148: /* UnaryExpression: tNEW Identifier  */
#line 430 "parser.y"
                                    { (yyval.expression) = new_new_expression(ctx, (yyvsp[0].string)); CHECK_ERROR; }
#line 2878 "parser.tab.c"
    break;

  case 149: /* CallExpression: PrimaryExpression  */
#line 433 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2884 "parser.tab.c"
    break;

  case 150: /* CallExpression: MemberExpression  */
#line 434 "parser.y"
                                    { (yyval.expression) = &(yyvsp[0].member)->expr; }
#line 2890 "parser.tab.c"
    break;

  case 151: /* CallExpression: CallExpression Arguments  */
#line 435 "parser.y"
                                    { call_expression_t *expr = new_call_expression(ctx, (yyvsp[-1].expression), (yyvsp[0].expression)); CHECK_ERROR;
                                      (yyval.expression) = &expr->expr; }
#line 2897 "parser.tab.c"
    break;

  case 152: /* LiteralExpression: tTRUE  */
#line 439 "parser.y"
                                    { (yyval.expression) = new_bool_expression(ctx, VARIANT_TRUE); CHECK_ERROR; }
#line 2903 "parser.tab.c"
    break;

  case 153: /* LiteralExpression: tFALSE  */
#line 440 "parser.y"
                                    { (yyval.expression) = new_bool_expression(ctx, VARIANT_FALSE); CHECK_ERROR; }
#line 2909 "parser.tab.c"
    break;

  case 154: /* LiteralExpression: tString  */
#line 441 "parser.y"
                                    { (yyval.expression) = new_string_expression(ctx, (yyvsp[0].string)); CHECK_ERROR; }
#line 2915 "parser.tab.c"
    break;

  case 155: /* LiteralExpression: tDate  */
#line 442 "parser.y"
                                    { (yyval.expression) = new_date_expression(ctx, (yyvsp[0].date)); CHECK_ERROR; }
#line 2921 "parser.tab.c"
    break;

  case 156: /* LiteralExpression: NumericLiteralExpression  */
#line 443 "parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 2927 "parser.tab.c"
    break;

  case 157: /* LiteralExpression: tEMPTY  */
#line 444 "parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_EMPTY, 0); CHECK_ERROR; }
#line 2933 "parser.tab.c"
    break;

  case 158: /* LiteralExpression: tNULL  */
#line 445 "parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NULL, 0); CHECK_ERROR; }
#line 2939 "parser.tab.c"
    break;

  case 159: /* LiteralExpression: tNOTHING  */
#line 446 "parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_NOTHING, 0); CHECK_ERROR; }
#line 2945 "parser.tab.c"
    break;

  case 160: /* NumericLiteralExpression: '0'  */
#line 449 "parser.y"
                                    { (yyval.expression) = new_long_expression(ctx, EXPR_INT, 0); CHECK_ERROR; }
#line 2951 "parser.tab.c"
    break;

  case 161: /* NumericLiteralExpression: tInt  */
#line 450 "parser.y"
                                    { (yyval.expression) = new_long_expression(ctx, EXPR_INT, (yyvsp[0].integer)); CHECK_ERROR; }
#line 2957 "parser.tab.c"
    break;

  case 162: /* NumericLiteralExpression: tDouble  */
#line 451 "parser.y"
                                    { (yyval.expression) = new_double_expression(ctx, (yyvsp[0].dbl)); CHECK_ERROR; }
#line 2963 "parser.tab.c"
    break;

  case 163: /* IntegerValue: '0'  */
#line 454 "parser.y"
                                    { (yyval.uint) = 0; }
#line 2969 "parser.tab.c"
    break;

  case 164: /* IntegerValue: tInt  */
#line 455 "parser.y"
                                    { (yyval.uint) = (yyvsp[0].integer); }
#line 2975 "parser.tab.c"
    break;

  case 165: /* PrimaryExpression: '(' Expression ')'  */
#line 458 "parser.y"
                                    { (yyval.expression) = new_unary_expression(ctx, EXPR_BRACKETS, (yyvsp[-1].expression)); }
#line 2981 "parser.tab.c"
    break;

  case 166: /* PrimaryExpression: tME  */
#line 459 "parser.y"
                                    { (yyval.expression) = new_expression(ctx, EXPR_ME, 0); CHECK_ERROR; }
#line 2987 "parser.tab.c"
    break;

  case 167: /* ClassDeclaration: tCLASS Identifier StSep ClassBody tEND tCLASS StSep  */
#line 462 "parser.y"
                                                                { (yyvsp[-3].class_decl)->name = (yyvsp[-5].string); (yyval.class_decl) = (yyvsp[-3].class_decl); }
#line 2993 "parser.tab.c"
    break;

  case 168: /* ClassBody: %empty  */
#line 465 "parser.y"
                                                  { (yyval.class_decl) = new_class_decl(ctx); }
#line 2999 "parser.tab.c"
    break;

  case 169: /* ClassBody: FunctionDecl  */
#line 466 "parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, new_class_decl(ctx), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 3005 "parser.tab.c"
    break;

  case 170: /* ClassBody: FunctionDecl StSep ClassBody  */
#line 467 "parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, (yyvsp[0].class_decl), (yyvsp[-2].func_decl)); CHECK_ERROR; }
#line 3011 "parser.tab.c"
    break;

  case 171: /* ClassBody: Storage MemberDeclList  */
#line 468 "parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, new_class_decl(ctx), (yyvsp[0].dim_decl), (yyvsp[-1].uint)); CHECK_ERROR; }
#line 3017 "parser.tab.c"
    break;

  case 172: /* ClassBody: Storage MemberDeclList StSep ClassBody  */
#line 469 "parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, (yyvsp[0].class_decl), (yyvsp[-2].dim_decl), (yyvsp[-3].uint)); CHECK_ERROR; }
#line 3023 "parser.tab.c"
    break;

  case 173: /* ClassBody: tDIM DimDeclList  */
#line 470 "parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, new_class_decl(ctx), (yyvsp[0].dim_decl), 0); CHECK_ERROR; }
#line 3029 "parser.tab.c"
    break;

  case 174: /* ClassBody: tDIM DimDeclList StSep ClassBody  */
#line 471 "parser.y"
                                                  { (yyval.class_decl) = add_dim_prop(ctx, (yyvsp[0].class_decl), (yyvsp[-2].dim_decl), 0); CHECK_ERROR; }
#line 3035 "parser.tab.c"
    break;

  case 175: /* ClassBody: PropertyDecl  */
#line 472 "parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, new_class_decl(ctx), (yyvsp[0].func_decl)); CHECK_ERROR; }
#line 3041 "parser.tab.c"
    break;

  case 176: /* ClassBody: PropertyDecl StSep ClassBody  */
#line 473 "parser.y"
                                                  { (yyval.class_decl) = add_class_function(ctx, (yyvsp[0].class_decl), (yyvsp[-2].func_decl)); CHECK_ERROR; }
#line 3047 "parser.tab.c"
    break;

  case 177: /* PropertyDecl: Storage_opt tPROPERTY tGET Identifier ArgumentsDecl_opt StSep BodyStatements tEND tPROPERTY  */
#line 477 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_PROPGET, (yyvsp[-8].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3053 "parser.tab.c"
    break;

  case 178: /* PropertyDecl: Storage_opt tPROPERTY tLET Identifier '(' ArgumentDeclList ')' StSep BodyStatements tEND tPROPERTY  */
#line 479 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-7].string), FUNC_PROPLET, (yyvsp[-10].uint), (yyvsp[-5].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3059 "parser.tab.c"
    break;

  case 179: /* PropertyDecl: Storage_opt tPROPERTY tSET Identifier '(' ArgumentDeclList ')' StSep BodyStatements tEND tPROPERTY  */
#line 481 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-7].string), FUNC_PROPSET, (yyvsp[-10].uint), (yyvsp[-5].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3065 "parser.tab.c"
    break;

  case 180: /* FunctionDecl: Storage_opt tSUB Identifier StSep BodyStatements tEND tSUB  */
#line 485 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-4].string), FUNC_SUB, (yyvsp[-6].uint), NULL, (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3071 "parser.tab.c"
    break;

  case 181: /* FunctionDecl: Storage_opt tSUB Identifier ArgumentsDecl Nl_opt BodyStatements tEND tSUB  */
#line 487 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_SUB, (yyvsp[-7].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3077 "parser.tab.c"
    break;

  case 182: /* FunctionDecl: Storage_opt tFUNCTION Identifier StSep BodyStatements tEND tFUNCTION  */
#line 489 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-4].string), FUNC_FUNCTION, (yyvsp[-6].uint), NULL, (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3083 "parser.tab.c"
    break;

  case 183: /* FunctionDecl: Storage_opt tFUNCTION Identifier ArgumentsDecl Nl_opt BodyStatements tEND tFUNCTION  */
#line 491 "parser.y"
                                    { (yyval.func_decl) = new_function_decl(ctx, (yyvsp[-5].string), FUNC_FUNCTION, (yyvsp[-7].uint), (yyvsp[-4].arg_decl), (yyvsp[-2].statement)); CHECK_ERROR; }
#line 3089 "parser.tab.c"
    break;

  case 184: /* Storage_opt: %empty  */
#line 494 "parser.y"
                                    { (yyval.uint) = 0; }
#line 3095 "parser.tab.c"
    break;

  case 185: /* Storage_opt: Storage  */
#line 495 "parser.y"
                                    { (yyval.uint) = (yyvsp[0].uint); }
#line 3101 "parser.tab.c"
    break;

  case 186: /* Storage: tPUBLIC tDEFAULT  */
#line 498 "parser.y"
                                    { (yyval.uint) = STORAGE_IS_DEFAULT; }
#line 3107 "parser.tab.c"
    break;

  case 187: /* Storage: tPUBLIC  */
#line 499 "parser.y"
                                    { (yyval.uint) = 0; }
#line 3113 "parser.tab.c"
    break;

  case 188: /* Storage: tPRIVATE  */
#line 500 "parser.y"
                                    { (yyval.uint) = STORAGE_IS_PRIVATE; }
#line 3119 "parser.tab.c"
    break;

  case 189: /* ArgumentsDecl_opt: %empty  */
#line 503 "parser.y"
                                                { (yyval.arg_decl) = 0; }
#line 3125 "parser.tab.c"
    break;

  case 190: /* ArgumentsDecl_opt: ArgumentsDecl  */
#line 504 "parser.y"
                                                { (yyval.arg_decl) = (yyvsp[0].arg_decl); }
#line 3131 "parser.tab.c"
    break;

  case 191: /* ArgumentsDecl: tEMPTYBRACKETS  */
#line 507 "parser.y"
                                                { (yyval.arg_decl) = NULL; }
#line 3137 "parser.tab.c"
    break;

  case 192: /* ArgumentsDecl: '(' ArgumentDeclList ')'  */
#line 508 "parser.y"
                                                { (yyval.arg_decl) = (yyvsp[-1].arg_decl); }
#line 3143 "parser.tab.c"
    break;

  case 193: /* ArgumentDeclList: ArgumentDecl  */
#line 511 "parser.y"
                                                { (yyval.arg_decl) = (yyvsp[0].arg_decl); }
#line 3149 "parser.tab.c"
    break;

  case 194: /* ArgumentDeclList: ArgumentDecl ',' ArgumentDeclList  */
#line 512 "parser.y"
                                                { (yyvsp[-2].arg_decl)->next = (yyvsp[0].arg_decl); (yyval.arg_decl) = (yyvsp[-2].arg_decl); }
#line 3155 "parser.tab.c"
    break;

  case 195: /* ArgumentDecl: Identifier EmptyBrackets_opt  */
#line 515 "parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), TRUE); }
#line 3161 "parser.tab.c"
    break;

  case 196: /* ArgumentDecl: tBYREF Identifier EmptyBrackets_opt  */
#line 516 "parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), TRUE); }
#line 3167 "parser.tab.c"
    break;

  case 197: /* ArgumentDecl: tBYVAL Identifier EmptyBrackets_opt  */
#line 517 "parser.y"
                                                { (yyval.arg_decl) = new_argument_decl(ctx, (yyvsp[-1].string), FALSE); }
#line 3173 "parser.tab.c"
    break;

  case 198: /* Identifier: MemberIdentifier  */
#line 521 "parser.y"
                       { (yyval.string) = (yyvsp[0].string); }
#line 3179 "parser.tab.c"
    break;

  case 199: /* Identifier: tPROPERTY  */
#line 522 "parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3185 "parser.tab.c"
    break;

  case 200: /* MemberIdentifier: tIdentifier  */
#line 525 "parser.y"
                     { (yyval.string) = (yyvsp[0].string); }
#line 3191 "parser.tab.c"
    break;

  case 201: /* MemberIdentifier: tDEFAULT  */
#line 526 "parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3197 "parser.tab.c"
    break;

  case 202: /* MemberIdentifier: tERROR  */
#line 527 "parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3203 "parser.tab.c"
    break;

  case 203: /* MemberIdentifier: tEXPLICIT  */
#line 528 "parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3209 "parser.tab.c"
    break;

  case 204: /* MemberIdentifier: tSTEP  */
#line 529 "parser.y"
                     { ctx->last_token = tIdentifier; (yyval.string) = (yyvsp[0].string); }
#line 3215 "parser.tab.c"
    break;


#line 3219 "parser.tab.c"

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
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, ctx, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, ctx);
          yychar = PARSER_EMPTY;
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != PARSER_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 546 "parser.y"


static int parser_error(unsigned *loc, parser_ctx_t *ctx, const char *str)
{
    if(ctx->error_loc == -1)
        ctx->error_loc = *loc;
    if(ctx->hres == S_OK) {
        FIXME("%s: %s\n", debugstr_w(ctx->code + *loc), debugstr_a(str));
        ctx->hres = E_FAIL;
    }else {
        WARN("%s: %08lx\n", debugstr_w(ctx->code + *loc), ctx->hres);
    }
    return 0;
}

static void source_add_statement(parser_ctx_t *ctx, statement_t *stat)
{
    if(!stat)
        return;

    /* concatenate both linked lists */
    if(ctx->stats) {
        ctx->stats_tail->next = stat;
        ctx->stats_tail = stat;
    }else {
        ctx->stats = ctx->stats_tail = stat;
    }
    /* find new tail */
    while(ctx->stats_tail->next) {
        ctx->stats_tail=ctx->stats_tail->next;
    }
}

static void source_add_class(parser_ctx_t *ctx, class_decl_t *class_decl)
{
    class_decl->next = ctx->class_decls;
    ctx->class_decls = class_decl;
}

static void handle_isexpression_script(parser_ctx_t *ctx, expression_t *expr)
{
    retval_statement_t *stat;

    if(!expr)
        return;

    stat = new_statement(ctx, STAT_RETVAL, sizeof(*stat), 0);
    if(!stat)
        return;

    stat->expr = expr;
    ctx->stats = &stat->stat;
}

static void *new_expression(parser_ctx_t *ctx, expression_type_t type, size_t size)
{
    expression_t *expr;

    expr = parser_alloc(ctx, size ? size : sizeof(*expr));
    if(expr) {
        expr->type = type;
        expr->next = NULL;
    }

    return expr;
}

static expression_t *new_bool_expression(parser_ctx_t *ctx, VARIANT_BOOL value)
{
    bool_expression_t *expr;

    expr = new_expression(ctx, EXPR_BOOL, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_string_expression(parser_ctx_t *ctx, const WCHAR *value)
{
    string_expression_t *expr;

    expr = new_expression(ctx, EXPR_STRING, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_date_expression(parser_ctx_t *ctx, DATE value)
{
    date_expression_t *expr;

    expr = new_expression(ctx, EXPR_DATE, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_long_expression(parser_ctx_t *ctx, expression_type_t type, LONG value)
{
    int_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_double_expression(parser_ctx_t *ctx, double value)
{
    double_expression_t *expr;

    expr = new_expression(ctx, EXPR_DOUBLE, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = value;
    return &expr->expr;
}

static expression_t *new_unary_expression(parser_ctx_t *ctx, expression_type_t type, expression_t *subexpr)
{
    unary_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->subexpr = subexpr;
    return &expr->expr;
}

static expression_t *new_binary_expression(parser_ctx_t *ctx, expression_type_t type, expression_t *left, expression_t *right)
{
    binary_expression_t *expr;

    expr = new_expression(ctx, type, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->left = left;
    expr->right = right;
    return &expr->expr;
}

static member_expression_t *new_member_expression(parser_ctx_t *ctx, expression_t *obj_expr, const WCHAR *identifier)
{
    member_expression_t *expr;

    expr = new_expression(ctx, EXPR_MEMBER, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->obj_expr = obj_expr;
    expr->identifier = identifier;
    return expr;
}

static call_expression_t *new_call_expression(parser_ctx_t *ctx, expression_t *expr, expression_t *arguments)
{
    call_expression_t *call_expr;

    call_expr = new_expression(ctx, EXPR_CALL, sizeof(*call_expr));
    if(!call_expr)
        return NULL;

    call_expr->call_expr = expr;
    call_expr->args = arguments;
    return call_expr;
}

static call_expression_t *make_call_expression(parser_ctx_t *ctx, expression_t *callee_expr, expression_t *arguments)
{
    call_expression_t *call_expr;

    if(callee_expr->type == EXPR_MEMBER)
        return new_call_expression(ctx, callee_expr, arguments);
    if(callee_expr->type != EXPR_CALL) {
        FIXME("Unhandled for expr type %u\n", callee_expr->type);
        ctx->hres = E_FAIL;
        return NULL;
    }
    call_expr = (call_expression_t*)callee_expr;
    if(!call_expr->args) {
        call_expr->args = arguments;
        return call_expr;
    }

    if(call_expr->args->next) {
        FIXME("Invalid syntax: invalid use of parentheses for arguments\n");
        ctx->hres = E_FAIL;
        return NULL;
    }

    call_expr->args = new_unary_expression(ctx, EXPR_BRACKETS, call_expr->args);
    if(!call_expr->args)
        return NULL;
    if(!arguments)
        return call_expr;

    if(arguments->type != EXPR_NOARG) {
        FIXME("Invalid syntax: missing comma\n");
        ctx->hres = E_FAIL;
        return NULL;
    }else {
        call_expr->args->next = arguments->next;
    }

    return call_expr;
}

static expression_t *new_new_expression(parser_ctx_t *ctx, const WCHAR *identifier)
{
    string_expression_t *expr;

    expr = new_expression(ctx, EXPR_NEW, sizeof(*expr));
    if(!expr)
        return NULL;

    expr->value = identifier;
    return &expr->expr;
}

static void *new_statement(parser_ctx_t *ctx, statement_type_t type, size_t size, unsigned loc)
{
    statement_t *stat;

    stat = parser_alloc(ctx, size ? size : sizeof(*stat));
    if(stat) {
        stat->type = type;
        stat->loc = loc;
        stat->next = NULL;
    }

    return stat;
}

static statement_t *new_call_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr)
{
    call_expression_t *call_expr = NULL;
    call_statement_t *stat;

    stat = new_statement(ctx, STAT_CALL, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    switch(expr->type) {
    case EXPR_MEMBER:
        call_expr = new_call_expression(ctx, expr, NULL);
        break;
    case EXPR_CALL:
        call_expr = (call_expression_t*)expr;
        break;
    default:
        FIXME("Unsupported expr type %u\n", expr->type);
        ctx->hres = E_NOTIMPL;
    }
    if(!call_expr)
        return NULL;

    stat->expr = call_expr;
    return &stat->stat;
}

static statement_t *new_assign_statement(parser_ctx_t *ctx, unsigned loc, expression_t *left, expression_t *right)
{
    assign_statement_t *stat;

    stat = new_statement(ctx, STAT_ASSIGN, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->left_expr = left;
    stat->value_expr = right;

    return &stat->stat;
}

static statement_t *new_set_statement(parser_ctx_t *ctx, unsigned loc, expression_t *left, expression_t *right)
{
    assign_statement_t *stat;

    stat = new_statement(ctx, STAT_SET, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->left_expr = left;
    stat->value_expr = right;

    return &stat->stat;
}

static dim_decl_t *new_dim_decl(parser_ctx_t *ctx, const WCHAR *name, BOOL is_array, dim_list_t *dims)
{
    dim_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->is_array = is_array;
    decl->dims = dims;
    decl->next = NULL;
    return decl;
}

static dim_list_t *new_dim(parser_ctx_t *ctx, unsigned val, dim_list_t *next)
{
    dim_list_t *ret;

    ret = parser_alloc(ctx, sizeof(*ret));
    if(!ret)
        return NULL;

    ret->val = val;
    ret->next = next;
    return ret;
}

static statement_t *new_dim_statement(parser_ctx_t *ctx, unsigned loc, dim_decl_t *decls)
{
    dim_statement_t *stat;

    stat = new_statement(ctx, STAT_DIM, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->dim_decls = decls;
    return &stat->stat;
}

static redim_decl_t *new_redim_decl(parser_ctx_t *ctx, const WCHAR *identifier, expression_t *dims)
{
    redim_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->identifier = identifier;
    decl->dims = dims;
    decl->next = NULL;
    return decl;
}

static statement_t *new_redim_statement(parser_ctx_t *ctx, unsigned loc, BOOL preserve, redim_decl_t *decls)
{
    redim_statement_t *stat;

    stat = new_statement(ctx, STAT_REDIM, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->preserve = preserve;
    stat->redim_decls = decls;
    return &stat->stat;
}

static elseif_decl_t *new_elseif_decl(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *stat)
{
    elseif_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->expr = expr;
    decl->stat = stat;
    decl->loc = loc;
    decl->next = NULL;
    return decl;
}

static statement_t *new_while_statement(parser_ctx_t *ctx, unsigned loc, statement_type_t type, expression_t *expr, statement_t *body)
{
    while_statement_t *stat;

    stat = new_statement(ctx, type, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_forto_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier, expression_t *from_expr,
        expression_t *to_expr, expression_t *step_expr, statement_t *body)
{
    forto_statement_t *stat;

    stat = new_statement(ctx, STAT_FORTO, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->identifier = identifier;
    stat->from_expr = from_expr;
    stat->to_expr = to_expr;
    stat->step_expr = step_expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_foreach_statement(parser_ctx_t *ctx, unsigned loc, const WCHAR *identifier, expression_t *group_expr,
        statement_t *body)
{
    foreach_statement_t *stat;

    stat = new_statement(ctx, STAT_FOREACH, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->identifier = identifier;
    stat->group_expr = group_expr;
    stat->body = body;
    return &stat->stat;
}

static statement_t *new_if_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *if_stat, elseif_decl_t *elseif_decl,
        statement_t *else_stat)
{
    if_statement_t *stat;

    stat = new_statement(ctx, STAT_IF, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->if_stat = if_stat;
    stat->elseifs = elseif_decl;
    stat->else_stat = else_stat;
    return &stat->stat;
}

static statement_t *new_select_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, case_clausule_t *case_clausules)
{
    select_statement_t *stat;

    stat = new_statement(ctx, STAT_SELECT, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->case_clausules = case_clausules;
    return &stat->stat;
}

static statement_t *new_with_statement(parser_ctx_t *ctx, unsigned loc, expression_t *expr, statement_t *body)
{
    with_statement_t *stat;

    stat = new_statement(ctx, STAT_WITH, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->expr = expr;
    stat->body = body;
    return &stat->stat;
}

static case_clausule_t *new_case_clausule(parser_ctx_t *ctx, expression_t *expr, statement_t *stat, case_clausule_t *next)
{
    case_clausule_t *ret;

    ret = parser_alloc(ctx, sizeof(*ret));
    if(!ret)
        return NULL;

    ret->expr = expr;
    ret->stat = stat;
    ret->next = next;
    return ret;
}

static statement_t *new_onerror_statement(parser_ctx_t *ctx, unsigned loc, BOOL resume_next)
{
    onerror_statement_t *stat;

    stat = new_statement(ctx, STAT_ONERROR, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->resume_next = resume_next;
    return &stat->stat;
}

static arg_decl_t *new_argument_decl(parser_ctx_t *ctx, const WCHAR *name, BOOL by_ref)
{
    arg_decl_t *arg_decl;

    arg_decl = parser_alloc(ctx, sizeof(*arg_decl));
    if(!arg_decl)
        return NULL;

    arg_decl->name = name;
    arg_decl->by_ref = by_ref;
    arg_decl->next = NULL;
    return arg_decl;
}

static function_decl_t *new_function_decl(parser_ctx_t *ctx, const WCHAR *name, function_type_t type,
        unsigned storage_flags, arg_decl_t *arg_decl, statement_t *body)
{
    function_decl_t *decl;
    BOOL is_default = FALSE;

    if(storage_flags & STORAGE_IS_DEFAULT) {
        if(type == FUNC_PROPGET || type == FUNC_FUNCTION || type == FUNC_SUB) {
            is_default = TRUE;
        }else {
            FIXME("Invalid default property\n");
            ctx->hres = E_FAIL;
            return NULL;
        }
    }

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->type = type;
    decl->is_public = !(storage_flags & STORAGE_IS_PRIVATE);
    decl->is_default = is_default;
    decl->args = arg_decl;
    decl->body = body;
    decl->next = NULL;
    decl->next_prop_func = NULL;
    return decl;
}

static statement_t *new_function_statement(parser_ctx_t *ctx, unsigned loc, function_decl_t *decl)
{
    function_statement_t *stat;

    stat = new_statement(ctx, STAT_FUNC, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->func_decl = decl;
    return &stat->stat;
}

static class_decl_t *new_class_decl(parser_ctx_t *ctx)
{
    class_decl_t *class_decl;

    class_decl = parser_alloc(ctx, sizeof(*class_decl));
    if(!class_decl)
        return NULL;

    class_decl->funcs = NULL;
    class_decl->props = NULL;
    class_decl->next = NULL;
    return class_decl;
}

static class_decl_t *add_class_function(parser_ctx_t *ctx, class_decl_t *class_decl, function_decl_t *decl)
{
    function_decl_t *iter;

    for(iter = class_decl->funcs; iter; iter = iter->next) {
        if(!wcsicmp(iter->name, decl->name)) {
            if(decl->type == FUNC_SUB || decl->type == FUNC_FUNCTION) {
                FIXME("Redefinition of %s::%s\n", debugstr_w(class_decl->name), debugstr_w(decl->name));
                ctx->hres = E_FAIL;
                return NULL;
            }

            while(1) {
                if(iter->type == decl->type) {
                    FIXME("Redefinition of %s::%s\n", debugstr_w(class_decl->name), debugstr_w(decl->name));
                    ctx->hres = E_FAIL;
                    return NULL;
                }
                if(!iter->next_prop_func)
                    break;
                iter = iter->next_prop_func;
            }

            iter->next_prop_func = decl;
            return class_decl;
        }
    }

    decl->next = class_decl->funcs;
    class_decl->funcs = decl;
    return class_decl;
}

static class_decl_t *add_dim_prop(parser_ctx_t *ctx, class_decl_t *class_decl, dim_decl_t *dim_decl, unsigned storage_flags)
{
    dim_decl_t *iter;

    if(storage_flags & STORAGE_IS_DEFAULT) {
        FIXME("variant prop can't be default value\n");
        ctx->hres = E_FAIL;
        return NULL;
    }

    iter = dim_decl;
    while(1) {
        iter->is_public = !(storage_flags & STORAGE_IS_PRIVATE);
        if (!iter->next) break;
        iter = iter->next;
    }

    iter->next = class_decl->props;
    class_decl->props = dim_decl;
    return class_decl;
}

static const_decl_t *new_const_decl(parser_ctx_t *ctx, const WCHAR *name, expression_t *expr)
{
    const_decl_t *decl;

    decl = parser_alloc(ctx, sizeof(*decl));
    if(!decl)
        return NULL;

    decl->name = name;
    decl->value_expr = expr;
    decl->next = NULL;
    return decl;
}

static statement_t *new_const_statement(parser_ctx_t *ctx, unsigned loc, const_decl_t *decls)
{
    const_statement_t *stat;

    stat = new_statement(ctx, STAT_CONST, sizeof(*stat), loc);
    if(!stat)
        return NULL;

    stat->decls = decls;
    return &stat->stat;
}

static statement_t *link_statements(statement_t *head, statement_t *tail)
{
    statement_t *iter;

    if (!head) return tail;

    for(iter = head; iter->next; iter = iter->next);
    iter->next = tail;

    return head;
}

void *parser_alloc(parser_ctx_t *ctx, size_t size)
{
    void *ret;

    ret = heap_pool_alloc(&ctx->heap, size);
    if(!ret)
        ctx->hres = E_OUTOFMEMORY;
    return ret;
}

HRESULT parse_script(parser_ctx_t *ctx, const WCHAR *code, const WCHAR *delimiter, DWORD flags)
{
    ctx->code = ctx->ptr = code;
    ctx->end = ctx->code + lstrlenW(ctx->code);

    heap_pool_init(&ctx->heap);

    ctx->hres = S_OK;
    ctx->error_loc = -1;
    ctx->last_token = tNL;
    ctx->last_nl = 0;
    ctx->stats = ctx->stats_tail = NULL;
    ctx->class_decls = NULL;
    ctx->option_explicit = FALSE;
    ctx->is_html = delimiter && !wcsicmp(delimiter, L"</script>");

    if(flags & SCRIPTTEXT_ISEXPRESSION)
        ctx->last_token = tEXPRESSION;

    parser_parse(ctx);

    return ctx->hres;
}

void parser_release(parser_ctx_t *ctx)
{
    heap_pool_free(&ctx->heap);
}
