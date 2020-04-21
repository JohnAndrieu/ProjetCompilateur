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
     tMAIN = 258,
     tVOID = 259,
     tOB = 260,
     tOP = 261,
     tCB = 262,
     tCP = 263,
     tPV = 264,
     tVIRGULE = 265,
     tPOINT = 266,
     tINT = 267,
     tFLOAT = 268,
     tMUL = 269,
     tINF = 270,
     tBOOL = 271,
     tPRINTF = 272,
     tIF = 273,
     tWHILE = 274,
     tFOR = 275,
     tRETURN = 276,
     tCOMPARE = 277,
     tAFFECT = 278,
     tADD = 279,
     tMODULO = 280,
     tSUP = 281,
     tDOUBLE = 282,
     tSHORT = 283,
     tLONG = 284,
     tSIGNED = 285,
     tUNSIGNED = 286,
     tSTATIC = 287,
     tTRUE = 288,
     tFALSE = 289,
     tSUB = 290,
     tDIV = 291,
     tCONST = 292,
     tVAR = 293,
     tNUMBER = 294
   };
#endif
/* Tokens.  */
#define tMAIN 258
#define tVOID 259
#define tOB 260
#define tOP 261
#define tCB 262
#define tCP 263
#define tPV 264
#define tVIRGULE 265
#define tPOINT 266
#define tINT 267
#define tFLOAT 268
#define tMUL 269
#define tINF 270
#define tBOOL 271
#define tPRINTF 272
#define tIF 273
#define tWHILE 274
#define tFOR 275
#define tRETURN 276
#define tCOMPARE 277
#define tAFFECT 278
#define tADD 279
#define tMODULO 280
#define tSUP 281
#define tDOUBLE 282
#define tSHORT 283
#define tLONG 284
#define tSIGNED 285
#define tUNSIGNED 286
#define tSTATIC 287
#define tTRUE 288
#define tFALSE 289
#define tSUB 290
#define tDIV 291
#define tCONST 292
#define tVAR 293
#define tNUMBER 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "source2.y"
{
    int nb;
    char * var;
}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

