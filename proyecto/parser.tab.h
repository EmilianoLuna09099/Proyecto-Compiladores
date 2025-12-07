/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LIT = 258,                 /* INT_LIT  */
    FLOAT_LIT = 259,               /* FLOAT_LIT  */
    STRING_LIT = 260,              /* STRING_LIT  */
    ID = 261,                      /* ID  */
    KW_VAR = 262,                  /* KW_VAR  */
    KW_FUNC = 263,                 /* KW_FUNC  */
    KW_RETURN = 264,               /* KW_RETURN  */
    TYPE_INT = 265,                /* TYPE_INT  */
    TYPE_FLOAT = 266,              /* TYPE_FLOAT  */
    TYPE_BOOL = 267,               /* TYPE_BOOL  */
    TYPE_STRING = 268,             /* TYPE_STRING  */
    TYPE_VOID = 269,               /* TYPE_VOID  */
    TYPE_ARRAY = 270,              /* TYPE_ARRAY  */
    KW_IF = 271,                   /* KW_IF  */
    KW_ELSE = 272,                 /* KW_ELSE  */
    KW_WHILE = 273,                /* KW_WHILE  */
    KW_FOR = 274,                  /* KW_FOR  */
    KW_PRINT = 275,                /* KW_PRINT  */
    KW_DRAW = 276,                 /* KW_DRAW  */
    KW_INPUT = 277,                /* KW_INPUT  */
    KW_READ = 278,                 /* KW_READ  */
    KW_NEW_ARRAY = 279,            /* KW_NEW_ARRAY  */
    KW_PUSH = 280,                 /* KW_PUSH  */
    KW_LENGTH = 281,               /* KW_LENGTH  */
    ASSIGN = 282,                  /* ASSIGN  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    MULT = 285,                    /* MULT  */
    DIV = 286,                     /* DIV  */
    MOD = 287,                     /* MOD  */
    POW = 288,                     /* POW  */
    EQ = 289,                      /* EQ  */
    NEQ = 290,                     /* NEQ  */
    LT = 291,                      /* LT  */
    GT = 292,                      /* GT  */
    LTE = 293,                     /* LTE  */
    GTE = 294,                     /* GTE  */
    LPAREN = 295,                  /* LPAREN  */
    RPAREN = 296,                  /* RPAREN  */
    LBRACE = 297,                  /* LBRACE  */
    RBRACE = 298,                  /* RBRACE  */
    LBRACKET = 299,                /* LBRACKET  */
    RBRACKET = 300,                /* RBRACKET  */
    SEMICOLON = 301,               /* SEMICOLON  */
    COMMA = 302                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "parser.y"

    char* sval;

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
