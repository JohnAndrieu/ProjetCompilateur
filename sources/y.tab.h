/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tNUMBER = 258,
     tVAR = 259,
     tMAIN = 260,
     tVOID = 261,
     tOB = 262,
     tOP = 263,
     tCB = 264,
     tCP = 265,
     tPV = 266,
     tVIRGULE = 267,
     tPOINT = 268,
     tINT = 269,
     tFLOAT = 270,
     tBOOL = 271,
     tPRINTF = 272,
     tIF = 273,
     tWHILE = 274,
     tFOR = 275,
     tRETURN = 276,
     tCOMPARE = 277,
     tAFFECT = 278,
     tADD = 279,
     tMUL = 280,
     tSUB = 281,
     tDIV = 282,
     tMODULO = 283,
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
#define tVAR 259
#define tMAIN 260
#define tVOID 261
#define tOB 262
#define tOP 263
#define tCB 264
#define tCP 265
#define tPV 266
#define tVIRGULE 267
#define tPOINT 268
#define tINT 269
#define tFLOAT 270
#define tBOOL 271
#define tPRINTF 272
#define tIF 273
#define tWHILE 274
#define tFOR 275
#define tRETURN 276
#define tCOMPARE 277
#define tAFFECT 278
#define tADD 279
#define tMUL 280
#define tSUB 281
#define tDIV 282
#define tMODULO 283
#define tDOUBLE 284
#define tSHORT 285
#define tLONG 286
#define tSIGNED 287
#define tUNSIGNED 288
#define tSTATIC 289
#define tTRUE 290
#define tFALSE 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "source2.y"
{
    int nb;
    char * var;
}
/* Line 1529 of yacc.c.  */
#line 126 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

