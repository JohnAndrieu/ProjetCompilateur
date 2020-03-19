/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    tNUMBER = 258,
    tMAIN = 259,
    tVOID = 260,
    tOB = 261,
    tOP = 262,
    tCB = 263,
    tCP = 264,
    tPV = 265,
    tVIRGULE = 266,
    tPOINT = 267,
    tINT = 268,
    tFLOAT = 269,
    tBOOL = 270,
    tPRINTF = 271,
    tIF = 272,
    tWHILE = 273,
    tFOR = 274,
    tRETURN = 275,
    tCOMPARE = 276,
    tAFFECT = 277,
    tADD = 278,
    tMUL = 279,
    tSUB = 280,
    tDIV = 281,
    tMODULO = 282,
    tVAR = 283,
    tDOUBLE = 284,
    tSHORT = 285,
    tLONG = 286,
    tSIGNED = 287,
    tUNSIGNED = 288,
    tSTATIC = 289,
    tTRUE = 290,
    tFALSE = 291
  };
#endif
/* Tokens.  */
#define tNUMBER 258
#define tMAIN 259
#define tVOID 260
#define tOB 261
#define tOP 262
#define tCB 263
#define tCP 264
#define tPV 265
#define tVIRGULE 266
#define tPOINT 267
#define tINT 268
#define tFLOAT 269
#define tBOOL 270
#define tPRINTF 271
#define tIF 272
#define tWHILE 273
#define tFOR 274
#define tRETURN 275
#define tCOMPARE 276
#define tAFFECT 277
#define tADD 278
#define tMUL 279
#define tSUB 280
#define tDIV 281
#define tMODULO 282
#define tVAR 283
#define tDOUBLE 284
#define tSHORT 285
#define tLONG 286
#define tSIGNED 287
#define tUNSIGNED 288
#define tSTATIC 289
#define tTRUE 290
#define tFALSE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
