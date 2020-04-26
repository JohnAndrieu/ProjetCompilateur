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
     tELSE = 271,
     tBOOL = 272,
     tPRINTF = 273,
     tIF = 274,
     tWHILE = 275,
     tFOR = 276,
     tRETURN = 277,
     tCOMPARE = 278,
     tAFFECT = 279,
     tADD = 280,
     tMODULO = 281,
     tSUP = 282,
     tDOUBLE = 283,
     tSHORT = 284,
     tLONG = 285,
     tSIGNED = 286,
     tUNSIGNED = 287,
     tSTATIC = 288,
     tTRUE = 289,
     tFALSE = 290,
     tSUB = 291,
     tDIV = 292,
     tCONST = 293,
     tVAR = 294,
     tNUMBER = 295
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
#define tELSE 271
#define tBOOL 272
#define tPRINTF 273
#define tIF 274
#define tWHILE 275
#define tFOR 276
#define tRETURN 277
#define tCOMPARE 278
#define tAFFECT 279
#define tADD 280
#define tMODULO 281
#define tSUP 282
#define tDOUBLE 283
#define tSHORT 284
#define tLONG 285
#define tSIGNED 286
#define tUNSIGNED 287
#define tSTATIC 288
#define tTRUE 289
#define tFALSE 290
#define tSUB 291
#define tDIV 292
#define tCONST 293
#define tVAR 294
#define tNUMBER 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "source2.y"
{
    int nb;
    char * var;
}
/* Line 1529 of yacc.c.  */
#line 134 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

