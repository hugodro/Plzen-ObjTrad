
/*  A Bison parser, made from ../gramObjc.ycc
 by  GNU Bison version 1.25
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	LITERAL_CHAR	258
#define	LITERAL_LONG	259
#define	LITERAL_INT	260
#define	LITERAL_FLOAT	261
#define	LITERAL_STRING	262
#define	IDENTIFIER_KW	263
#define	BYCOPY_KW	264
#define	CHAR_KW	265
#define	CLASS_KW	266
#define	CONST_KW	267
#define	DOUBLE_KW	268
#define	ELLIPSIS_KW	269
#define	END_KW	270
#define	FLOAT_KW	271
#define	ID_KW	272
#define	IN_KW	273
#define	INOUT_KW	274
#define	INT_KW	275
#define	INTERFACE_KW	276
#define	LONG_KW	277
#define	ONEWAY_KW	278
#define	OUT_KW	279
#define	PRIVATE_KW	280
#define	PROTOCOL_KW	281
#define	PROTECTED_KW	282
#define	PUBLIC_KW	283
#define	SHORT_KW	284
#define	SIGNED_KW	285
#define	STRUCT_KW	286
#define	UNSIGNED_KW	287
#define	VOID_KW	288
#define	VOLATILE_KW	289

#line 8 "../gramObjc.ycc"

/* On met ici les declaration et les fichiers inclus */

#include <iostream.h>
#include <akra/portableDefs.h>
#include "translator.h"
#include "typing.h"
#include "metaTypes.h"
#include "members.h"
#include "memberSupport.h"
#include "identifier.h"


#define YYDEBUG	1


extern "C" {
    extern void yyerror(char *);
    extern int yylex();
}

extern ObjcTranslator *compiler;


#line 81 "../gramObjc.ycc"
typedef union
{
	// Builtin types.
    boolean boolValue;
    char *string;
    unsigned int integerNumber;
    unsigned int longNumber[2];
    float floatNumber;
    double doubleNumber;

	// Complex types.
    Identifier *identifier;
    OAbstractType *abstractType;
    VariableDeclaration *varDecl;
    FunctionalDeclaration *interfaceDecl;
    OType *otype;
    Slot *slot;
    VariableModificator *varModif;
    Parameter *parameter;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		169
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 289 ? yytranslate[x] : 103)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
    39,    49,    45,    42,    46,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    37,    35,    40,
     2,    41,     2,    36,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    47,     2,    48,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    43,     2,    44,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     9,    11,    13,    24,    35,    43,
    44,    48,    50,    54,    55,    57,    61,    64,    66,    68,
    71,    75,    77,    79,    81,    82,    84,    86,    89,    91,
    93,    98,   100,   102,   103,   105,   111,   113,   116,   118,
   121,   125,   130,   131,   134,   136,   138,   139,   141,   143,
   145,   148,   152,   154,   158,   162,   163,   165,   167,   170,
   175,   177,   179,   181,   183,   186,   188,   193,   195,   198,
   202,   203,   205,   206,   208,   211,   215,   216,   218,   220,
   222,   224,   226,   228,   230,   232,   234,   241,   249,   250,
   252,   254,   258,   261,   265,   267,   269,   271,   273,   276,
   279,   281,   283,   285,   287,   289,   291,   293
};

static const short yyrhs[] = {    51,
     0,    50,    51,     0,    52,     0,    53,     0,    54,     0,
    82,     0,    36,    21,    75,    37,    75,    55,    57,    62,
    36,    15,     0,    36,    21,    75,    38,    75,    39,    55,
    62,    36,    15,     0,    36,    26,    75,    55,    62,    36,
    15,     0,     0,    40,    56,    41,     0,    75,     0,    56,
    42,    75,     0,     0,    58,     0,    43,    59,    44,     0,
    43,    44,     0,    76,     0,    60,     0,    59,    60,     0,
    36,    61,    76,     0,    25,     0,    27,     0,    28,     0,
     0,    63,     0,    64,     0,    63,    64,     0,    94,     0,
    65,     0,    66,    67,    69,    35,     0,    45,     0,    46,
     0,     0,    68,     0,    38,    91,    83,    89,    39,     0,
    75,     0,    70,    72,     0,    71,     0,    70,    71,     0,
    37,    67,    75,     0,    75,    37,    67,    75,     0,     0,
    42,    73,     0,    14,     0,    97,     0,     0,    75,     0,
     8,     0,    77,     0,    76,    77,     0,    83,    78,    35,
     0,    79,     0,    78,    42,    79,     0,    89,    75,    80,
     0,     0,    81,     0,    86,     0,    37,     5,     0,    36,
    11,    56,    35,     0,    75,     0,    99,     0,    84,     0,
    95,     0,    31,    85,     0,    75,     0,    74,    43,    76,
    44,     0,    87,     0,    86,    87,     0,    47,    88,    48,
     0,     0,     5,     0,     0,    90,     0,    91,    49,     0,
    90,    91,    49,     0,     0,    92,     0,    12,     0,    34,
     0,    93,     0,    18,     0,    24,     0,    19,     0,     9,
     0,    23,     0,    83,    75,    38,    96,    39,    35,     0,
    83,    38,    90,    39,    38,    96,    39,     0,     0,    97,
     0,    98,     0,    97,    42,    98,     0,    83,    89,     0,
    83,    89,    75,     0,   100,     0,   102,     0,    33,     0,
    17,     0,    32,   101,     0,    30,   101,     0,   101,     0,
    32,     0,    10,     0,    29,     0,    20,     0,    22,     0,
    16,     0,    13,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   151,   156,   162,   164,   165,   166,   172,   182,   192,   202,
   207,   212,   217,   223,   228,   231,   238,   243,   245,   249,
   255,   269,   274,   278,   284,   289,   295,   300,   306,   308,
   311,   318,   323,   329,   334,   340,   349,   354,   363,   368,
   374,   379,   385,   390,   396,   401,   407,   412,   415,   422,
   427,   433,   443,   448,   454,   461,   466,   469,   471,   477,
   484,   489,   490,   491,   494,   500,   505,   511,   516,   523,
   530,   535,   541,   546,   549,   554,   560,   565,   568,   573,
   577,   580,   585,   589,   593,   597,   603,   610,   617,   622,
   628,   633,   639,   645,   652,   654,   655,   659,   665,   671,
   675,   676,   682,   687,   691,   695,   700,   705
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","LITERAL_CHAR",
"LITERAL_LONG","LITERAL_INT","LITERAL_FLOAT","LITERAL_STRING","IDENTIFIER_KW",
"BYCOPY_KW","CHAR_KW","CLASS_KW","CONST_KW","DOUBLE_KW","ELLIPSIS_KW","END_KW",
"FLOAT_KW","ID_KW","IN_KW","INOUT_KW","INT_KW","INTERFACE_KW","LONG_KW","ONEWAY_KW",
"OUT_KW","PRIVATE_KW","PROTOCOL_KW","PROTECTED_KW","PUBLIC_KW","SHORT_KW","SIGNED_KW",
"STRUCT_KW","UNSIGNED_KW","VOID_KW","VOLATILE_KW","';'","'@'","':'","'('","')'",
"'<'","'>'","','","'{'","'}'","'+'","'-'","'['","']'","'*'","ExternalDeclarationList",
"ExternalDeclaration","ClassInterface","CategoryInterface","ProtocolDeclaration",
"ProtocolReferenceList.Opt","IdentifierList","InstanceVariables.Opt","InstanceVariables",
"ProtectedStructDeclList","ProtectedStructDecl","VisibilitySpec","InterfaceDeclarationList.Opt",
"InterfaceDeclarationList","InterfaceDeclaration","MethodDeclaration","ClassOrMethodSpec",
"ObjcType.Opt","ObjcType","MethodSelector","KeywordSelectorList","KeywordDeclarator",
"SpecialKeywordSelectors.Opt","SpecialKeywordSelectors","Identifier.Opt","Identifier",
"StructDeclarationList","StructDeclaration","VarDeclarationList","VarDeclaration",
"VarDeclSuffix.Opt","VarDeclSuffix","ClassDeclarationList","Type","StructType",
"StructTypeComponent","ArrayDeclList","ArrayDecl","Size.Opt","PointerDecl.Opt",
"PointerList","TypeQualifier.Opt","TypeQualifier","ProtocolQualifier","Declaration",
"FunctionalType","ParamDeclList.Opt","ParamDeclList","ParamDecl","PrimaryType",
"IntegerMathType","RawIntegerMathType","NonIntegerMathType", NULL
};
#endif

static const short yyr1[] = {     0,
    50,    50,    51,    51,    51,    51,    52,    53,    54,    55,
    55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
    60,    61,    61,    61,    62,    62,    63,    63,    64,    64,
    65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
    71,    71,    72,    72,    73,    73,    74,    74,    75,    76,
    76,    77,    78,    78,    79,    80,    80,    81,    81,    82,
    83,    83,    83,    83,    84,    85,    85,    86,    86,    87,
    88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
    92,    93,    93,    93,    93,    93,    94,    95,    96,    96,
    97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
   100,   100,   101,   101,   101,   101,   102,   102
};

static const short yyr2[] = {     0,
     1,     2,     1,     1,     1,     1,    10,    10,     7,     0,
     3,     1,     3,     0,     1,     3,     2,     1,     1,     2,
     3,     1,     1,     1,     0,     1,     1,     2,     1,     1,
     4,     1,     1,     0,     1,     5,     1,     2,     1,     2,
     3,     4,     0,     2,     1,     1,     0,     1,     1,     1,
     2,     3,     1,     3,     3,     0,     1,     1,     2,     4,
     1,     1,     1,     1,     2,     1,     4,     1,     2,     3,
     0,     1,     0,     1,     2,     3,     0,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     6,     7,     0,     1,
     1,     3,     2,     3,     1,     1,     1,     1,     2,     2,
     1,     1,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     1,     3,     4,     5,     6,     0,     0,     0,
     2,    49,     0,    12,     0,    10,    60,     0,     0,     0,
     0,    25,    13,    10,     0,     0,   103,   108,   107,    98,
   105,   106,   104,     0,    47,   102,    97,    32,    33,     0,
    26,    27,    30,    34,    61,     0,    63,    29,    64,    62,
    95,   101,    96,    14,    10,    11,   100,     0,    66,    65,
    99,     0,    28,    77,     0,    35,    77,     0,     0,    25,
    15,    25,     0,     9,    85,    79,    82,    84,    86,    83,
    80,     0,    78,    81,    34,     0,    43,    39,    37,    77,
     0,    89,     0,    17,     0,    19,    18,    50,    73,     0,
     0,     0,    73,     0,    31,     0,    40,    38,     0,    34,
     0,     0,    75,    73,     0,    90,    91,    22,    23,    24,
     0,    16,    20,    51,     0,    53,     0,    74,     0,     0,
    67,     0,    41,    45,    44,    46,     0,    89,    76,    93,
     0,     0,    21,    52,    73,    56,     7,     8,    36,    42,
     0,    94,    87,    92,    54,     0,    71,    55,    57,    58,
    68,    88,    59,    72,     0,    69,    70,     0,     0
};

static const short yydefgoto[] = {     2,
     3,     4,     5,     6,    22,    13,    70,    71,    95,    96,
   121,    40,    41,    42,    43,    44,    65,    66,    86,    87,
    88,   108,   135,    58,    45,    97,    98,   125,   126,   158,
   159,     7,    99,    47,    60,   160,   161,   165,   127,   128,
    91,    83,    84,    48,    49,   115,   116,   117,    50,    51,
    52,    53
};

static const short yypact[] = {   -12,
    50,     8,-32768,-32768,-32768,-32768,-32768,    10,    10,    10,
-32768,-32768,    28,-32768,    60,   -19,-32768,    10,    10,    10,
    10,    70,-32768,   -19,     0,    63,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    40,    10,    40,-32768,-32768,-32768,    15,
    70,-32768,-32768,    37,-32768,    -1,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    38,   -19,-32768,-32768,    46,    52,-32768,
-32768,    91,-32768,   231,    12,-32768,   231,    69,   117,    70,
-32768,    70,   215,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   215,-32768,-32768,    37,    73,    -2,-32768,    72,   162,
    61,   215,    66,-32768,    41,-32768,   215,-32768,     7,    75,
    76,   146,     7,    10,-32768,   189,-32768,-32768,    72,    37,
    79,    64,-32768,     7,    82,    80,-32768,-32768,-32768,-32768,
   215,-32768,-32768,-32768,    30,-32768,    10,    24,    99,   103,
-32768,    84,-32768,-32768,-32768,    80,    10,   215,-32768,    10,
    93,   215,   215,-32768,    24,   -15,-32768,-32768,-32768,-32768,
    87,-32768,-32768,-32768,-32768,   126,   130,-32768,-32768,    89,
-32768,-32768,-32768,-32768,    90,-32768,-32768,   140,-32768
};

static const short yypgoto[] = {-32768,
   139,-32768,-32768,-32768,    -9,   121,-32768,-32768,-32768,    49,
-32768,    -4,-32768,   102,-32768,-32768,   -51,-32768,-32768,-32768,
    58,-32768,-32768,-32768,    -8,   -68,   -88,-32768,     6,-32768,
-32768,-32768,   -18,-32768,-32768,-32768,    -5,-32768,   -86,    85,
   -61,-32768,-32768,-32768,-32768,    19,    54,    16,-32768,-32768,
    48,-32768
};


#define	YYLAST		265


static const short yytable[] = {    14,
    15,    16,    82,    46,   102,    12,    12,   168,   124,    23,
    24,    25,    14,   124,    54,    75,   132,    12,    76,    12,
    21,   156,    46,     1,    77,    78,    59,   140,   112,    79,
    80,   157,    75,   104,    85,    76,    67,    68,    55,   106,
    81,    77,    78,     1,    67,    72,    79,    80,    85,    27,
    62,    46,   143,    46,   124,   -77,    89,    81,   137,    31,
     8,    32,    17,   103,   144,   100,   112,   101,    33,    18,
     9,   145,   -77,   114,    64,    10,    93,    12,   109,    27,
    69,    57,    28,    61,   122,    29,    30,   114,    73,    31,
   118,    32,   119,   120,   -48,   133,    19,    20,    33,    34,
    35,    36,    37,    56,    18,    74,    92,   105,   110,   113,
   129,   130,   139,   147,    38,    39,   138,   148,   146,   114,
   141,   142,   149,   114,    12,   162,    27,   153,   150,    28,
   163,   152,    29,    30,   164,   157,    31,   167,    32,   169,
    11,    26,    63,   123,   107,    33,    34,    35,    36,    37,
   155,    90,    93,    12,   166,    27,   151,   154,    28,   136,
    94,    29,    30,     0,     0,    31,     0,    32,     0,     0,
    75,     0,     0,    76,    33,    34,    35,    36,    37,    77,
    78,     0,     0,     0,    79,    80,     0,     0,     0,   131,
     0,     0,     0,     0,     0,    81,    12,     0,    27,     0,
   111,    28,   134,     0,    29,    30,     0,     0,    31,     0,
    32,     0,     0,     0,     0,     0,     0,    33,    34,    35,
    36,    37,    12,     0,    27,     0,     0,    28,     0,     0,
    29,    30,     0,     0,    31,     0,    32,     0,     0,    75,
     0,     0,    76,    33,    34,    35,    36,    37,    77,    78,
     0,     0,     0,    79,    80,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    81
};

static const short yycheck[] = {     8,
     9,    10,    64,    22,    73,     8,     8,     0,    97,    18,
    19,    20,    21,   102,    24,     9,   103,     8,    12,     8,
    40,    37,    41,    36,    18,    19,    35,   114,    90,    23,
    24,    47,     9,    85,    37,    12,    38,    46,    39,    42,
    34,    18,    19,    36,    38,    55,    23,    24,    37,    10,
    36,    70,   121,    72,   143,    49,    65,    34,   110,    20,
    11,    22,    35,    82,    35,    70,   128,    72,    29,    42,
    21,    42,    49,    92,    38,    26,    36,     8,    87,    10,
    43,    34,    13,    36,    44,    16,    17,   106,    43,    20,
    25,    22,    27,    28,    43,   104,    37,    38,    29,    30,
    31,    32,    33,    41,    42,    15,    38,    35,    37,    49,
    36,    36,    49,    15,    45,    46,    38,    15,   127,   138,
    39,    42,    39,   142,     8,    39,    10,    35,   137,    13,
     5,   140,    16,    17,     5,    47,    20,    48,    22,     0,
     2,    21,    41,    95,    87,    29,    30,    31,    32,    33,
   145,    67,    36,     8,   160,    10,   138,   142,    13,   106,
    44,    16,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,
     9,    -1,    -1,    12,    29,    30,    31,    32,    33,    18,
    19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    44,
    -1,    -1,    -1,    -1,    -1,    34,     8,    -1,    10,    -1,
    39,    13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
    32,    33,     8,    -1,    10,    -1,    -1,    13,    -1,    -1,
    16,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,     9,
    -1,    -1,    12,    29,    30,    31,    32,    33,    18,    19,
    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    34
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 153 "../gramObjc.ycc"
{
	if (yyvsp[0].abstractType != NULL) compiler->linkExternalDecl(yyvsp[0].abstractType);
    ;
    break;}
case 2:
#line 157 "../gramObjc.ycc"
{
	if (yyvsp[0].abstractType != NULL) compiler->linkExternalDecl(yyvsp[0].abstractType);
    ;
    break;}
case 6:
#line 167 "../gramObjc.ycc"
{
	yyval.abstractType= NULL;
    ;
    break;}
case 7:
#line 177 "../gramObjc.ycc"
{
	yyval.abstractType= new OClass(yyvsp[-7].identifier, yyvsp[-5].identifier, yyvsp[-4].identifier, yyvsp[-3].varDecl, yyvsp[-2].interfaceDecl);
    ;
    break;}
case 8:
#line 187 "../gramObjc.ycc"
{
	yyval.abstractType= new OCategory(yyvsp[-7].identifier, yyvsp[-5].identifier, yyvsp[-3].identifier, yyvsp[-2].interfaceDecl);
    ;
    break;}
case 9:
#line 197 "../gramObjc.ycc"
{
	yyval.abstractType= new OProtocol(yyvsp[-4].identifier, yyvsp[-3].identifier, yyvsp[-2].interfaceDecl);
    ;
    break;}
case 10:
#line 204 "../gramObjc.ycc"
{
	yyval.identifier= NULL;
    ;
    break;}
case 11:
#line 208 "../gramObjc.ycc"
{
	yyval.identifier= compiler->flushIdentList();
    ;
    break;}
case 12:
#line 214 "../gramObjc.ycc"
{
	compiler->linkIdentifier(yyvsp[0].identifier);
    ;
    break;}
case 13:
#line 218 "../gramObjc.ycc"
{
	compiler->linkIdentifier(yyvsp[0].identifier);
    ;
    break;}
case 14:
#line 225 "../gramObjc.ycc"
{
	yyval.varDecl= NULL;
    ;
    break;}
case 16:
#line 235 "../gramObjc.ycc"
{
	yyval.varDecl= compiler->flushStructList();
    ;
    break;}
case 17:
#line 239 "../gramObjc.ycc"
{
	yyval.varDecl= NULL;
    ;
    break;}
case 19:
#line 246 "../gramObjc.ycc"
{
	compiler->startStructList(yyvsp[0].varDecl);
    ;
    break;}
case 20:
#line 250 "../gramObjc.ycc"
{
	compiler->linkStructDecl(yyvsp[0].varDecl);
    ;
    break;}
case 21:
#line 257 "../gramObjc.ycc"
{
	VariableDeclaration *varDecl= compiler->flushStructList();

	yyval.varDecl= varDecl;
	while (varDecl != NULL) {
	    varDecl->setProtection((VariableDeclaration::Protection)yyvsp[-1].integerNumber);
	    varDecl= (VariableDeclaration *)varDecl->getNext();
	}

    ;
    break;}
case 22:
#line 271 "../gramObjc.ycc"
{
	yyval.integerNumber= VariableDeclaration::pPrivate;
    ;
    break;}
case 23:
#line 275 "../gramObjc.ycc"
{
	yyval.integerNumber= VariableDeclaration::pProtected;
    ;
    break;}
case 24:
#line 279 "../gramObjc.ycc"
{
	yyval.integerNumber= VariableDeclaration::pPublic;
    ;
    break;}
case 25:
#line 286 "../gramObjc.ycc"
{
	yyval.interfaceDecl= NULL;
    ;
    break;}
case 26:
#line 290 "../gramObjc.ycc"
{
	yyval.interfaceDecl= compiler->flushDeclarationList();
    ;
    break;}
case 27:
#line 297 "../gramObjc.ycc"
{
	compiler->linkDeclaration(yyvsp[0].interfaceDecl);
    ;
    break;}
case 28:
#line 301 "../gramObjc.ycc"
{
	compiler->linkDeclaration(yyvsp[0].interfaceDecl);
    ;
    break;}
case 31:
#line 313 "../gramObjc.ycc"
{
	yyval.interfaceDecl= new MethodDeclaration((FunctionalDeclaration::Kind)yyvsp[-3].integerNumber, yyvsp[-2].otype, yyvsp[-1].slot);
    ;
    break;}
case 32:
#line 320 "../gramObjc.ycc"
{
	yyval.integerNumber= FunctionalDeclaration::kClassMethod;
    ;
    break;}
case 33:
#line 324 "../gramObjc.ycc"
{
	yyval.integerNumber= FunctionalDeclaration::kInstanceMethod;
    ;
    break;}
case 34:
#line 331 "../gramObjc.ycc"
{
	yyval.otype= PrimitiveType::getBuiltIn(PrimitiveType::tId);
    ;
    break;}
case 35:
#line 335 "../gramObjc.ycc"
{
	yyval.otype= yyvsp[0].otype;
    ;
    break;}
case 36:
#line 342 "../gramObjc.ycc"
{
	yyvsp[-2].otype->setRTQualifier((OType::RunTimeQualifier)yyvsp[-3].integerNumber);
	yyvsp[-2].otype->addPointers(yyvsp[-1].integerNumber);
	yyval.otype= yyvsp[-2].otype;
    ;
    break;}
case 37:
#line 351 "../gramObjc.ycc"
{
	yyval.slot= new Slot(yyvsp[0].identifier);
    ;
    break;}
case 38:
#line 355 "../gramObjc.ycc"
{
	if (yyvsp[0].slot != NULL) {
	    compiler->linkSlotDecl(yyvsp[0].slot);
	}
	yyval.slot= compiler->flushSlotList();
    ;
    break;}
case 39:
#line 365 "../gramObjc.ycc"
{
	compiler->linkSlotDecl(yyvsp[0].slot);
    ;
    break;}
case 40:
#line 369 "../gramObjc.ycc"
{
	compiler->linkSlotDecl(yyvsp[0].slot);
    ;
    break;}
case 41:
#line 376 "../gramObjc.ycc"
{
	yyval.slot= new Slot(yyvsp[-1].otype, yyvsp[0].identifier);
    ;
    break;}
case 42:
#line 380 "../gramObjc.ycc"
{
	yyval.slot= new Slot(yyvsp[-3].identifier, yyvsp[-1].otype, yyvsp[0].identifier);
    ;
    break;}
case 43:
#line 387 "../gramObjc.ycc"
{
	yyval.slot= NULL;
    ;
    break;}
case 44:
#line 391 "../gramObjc.ycc"
{
	yyval.slot= yyvsp[0].slot;
    ;
    break;}
case 45:
#line 398 "../gramObjc.ycc"
{
	yyval.slot= new EllipsisSlot();
    ;
    break;}
case 46:
#line 402 "../gramObjc.ycc"
{
	yyval.slot= new ParameterSlot(compiler->flushParamList());
    ;
    break;}
case 47:
#line 409 "../gramObjc.ycc"
{
	yyval.identifier= NULL;
    ;
    break;}
case 49:
#line 417 "../gramObjc.ycc"
{
	yyval.identifier= new Identifier(yyvsp[0].string);
     ;
    break;}
case 50:
#line 424 "../gramObjc.ycc"
{
	compiler->startStructList(yyvsp[0].varDecl);
    ;
    break;}
case 51:
#line 428 "../gramObjc.ycc"
{
	compiler->linkStructDecl(yyvsp[0].varDecl);
    ;
    break;}
case 52:
#line 435 "../gramObjc.ycc"
{
	VariableDeclaration *tmpVar= yyval.varDecl= compiler->flushStructList();
	do {
	    tmpVar->setReturnType(yyvsp[-2].otype);
	    tmpVar= (VariableDeclaration *)tmpVar->getNext();
	} while (tmpVar != NULL);
    ;
    break;}
case 53:
#line 445 "../gramObjc.ycc"
{
	compiler->startStructList(yyvsp[0].varDecl);
    ;
    break;}
case 54:
#line 449 "../gramObjc.ycc"
{
	compiler->linkStructDecl(yyvsp[0].varDecl);
  ;
    break;}
case 55:
#line 456 "../gramObjc.ycc"
{
	yyval.varDecl= new VariableDeclaration(yyvsp[-2].integerNumber, yyvsp[-1].identifier, yyvsp[0].varModif);
    ;
    break;}
case 56:
#line 463 "../gramObjc.ycc"
{
	yyval.varModif= NULL;
    ;
    break;}
case 59:
#line 472 "../gramObjc.ycc"
{
	yyval.varModif= new BitFieldDeclarator(yyvsp[0].integerNumber);
    ;
    break;}
case 60:
#line 479 "../gramObjc.ycc"
{
	compiler->addClassNotification(compiler->flushIdentList());
    ;
    break;}
case 61:
#line 486 "../gramObjc.ycc"
{
	yyval.otype= new UserType(yyvsp[0].identifier);
    ;
    break;}
case 65:
#line 496 "../gramObjc.ycc"
{
	yyval.otype= yyvsp[0].otype;
    ;
    break;}
case 66:
#line 502 "../gramObjc.ycc"
{
	yyval.otype= new StructureType(yyvsp[0].identifier);
    ;
    break;}
case 67:
#line 506 "../gramObjc.ycc"
{
	yyval.otype= new StructureType(yyvsp[-3].identifier, compiler->flushStructList());
    ;
    break;}
case 68:
#line 513 "../gramObjc.ycc"
{
	yyval.varModif= new ArrayDeclarator(yyvsp[0].integerNumber);
    ;
    break;}
case 69:
#line 517 "../gramObjc.ycc"
{
	((ArrayDeclarator *)yyvsp[-1].varModif)->addDimension(yyvsp[0].integerNumber);
	yyval.varModif= yyvsp[-1].varModif;
    ;
    break;}
case 70:
#line 525 "../gramObjc.ycc"
{
	yyval.integerNumber= yyvsp[-1].integerNumber;
    ;
    break;}
case 71:
#line 532 "../gramObjc.ycc"
{
	yyval.integerNumber= 0;
    ;
    break;}
case 72:
#line 536 "../gramObjc.ycc"
{
	yyval.integerNumber= yyvsp[0].integerNumber;
    ;
    break;}
case 73:
#line 543 "../gramObjc.ycc"
{
	yyval.integerNumber= 0;
    ;
    break;}
case 75:
#line 551 "../gramObjc.ycc"
{
	yyval.integerNumber= 1;
    ;
    break;}
case 76:
#line 555 "../gramObjc.ycc"
{
	yyval.integerNumber= yyvsp[-2].integerNumber + 1;
    ;
    break;}
case 77:
#line 562 "../gramObjc.ycc"
{
	yyval.integerNumber= 0;
    ;
    break;}
case 79:
#line 570 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtConstant;
    ;
    break;}
case 80:
#line 574 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtVolatile;
    ;
    break;}
case 82:
#line 582 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtIn;
    ;
    break;}
case 83:
#line 586 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtOut;
    ;
    break;}
case 84:
#line 590 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtInOut;
    ;
    break;}
case 85:
#line 594 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtByCopy;
    ;
    break;}
case 86:
#line 598 "../gramObjc.ycc"
{
	yyval.integerNumber= OType::rtOneWay;
    ;
    break;}
case 87:
#line 605 "../gramObjc.ycc"
{
	yyval.interfaceDecl= new FunctionDeclaration(yyvsp[-5].otype, yyvsp[-4].identifier, yyvsp[-2].parameter);
    ;
    break;}
case 88:
#line 612 "../gramObjc.ycc"
{
	yyval.otype= new FunctionalType(yyvsp[-6].otype, yyvsp[-4].integerNumber, yyvsp[-1].parameter);
    ;
    break;}
case 89:
#line 619 "../gramObjc.ycc"
{
	yyval.parameter= NULL;
    ;
    break;}
case 90:
#line 623 "../gramObjc.ycc"
{
	yyval.parameter= compiler->flushParamList();
    ;
    break;}
case 91:
#line 630 "../gramObjc.ycc"
{
	compiler->startParamList(yyvsp[0].parameter);
    ;
    break;}
case 92:
#line 634 "../gramObjc.ycc"
{
	compiler->linkParameter(yyvsp[0].parameter);
    ;
    break;}
case 93:
#line 641 "../gramObjc.ycc"
{
	yyvsp[-1].otype->addPointers(yyvsp[0].integerNumber);
	yyval.parameter= new Parameter(yyvsp[-1].otype);
    ;
    break;}
case 94:
#line 646 "../gramObjc.ycc"
{
	yyvsp[-2].otype->addPointers(yyvsp[-1].integerNumber);
	yyval.parameter= new Parameter(yyvsp[-2].otype, yyvsp[0].identifier);
    ;
    break;}
case 97:
#line 656 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tVoid);
    ;
    break;}
case 98:
#line 660 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tId);
    ;
    break;}
case 99:
#line 667 "../gramObjc.ycc"
{
	((PrimitiveType *)yyvsp[0].otype)->setUnsigned();
	yyval.otype= yyvsp[0].otype;
    ;
    break;}
case 100:
#line 672 "../gramObjc.ycc"
{
	yyval.otype= yyvsp[0].otype;
    ;
    break;}
case 102:
#line 677 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tInt);
	((PrimitiveType *)yyval.otype)->setUnsigned();
    ;
    break;}
case 103:
#line 684 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tChar);
    ;
    break;}
case 104:
#line 688 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tShort);
    ;
    break;}
case 105:
#line 692 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tInt);
    ;
    break;}
case 106:
#line 696 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tLong);
    ;
    break;}
case 107:
#line 702 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tFloat);
    ;
    break;}
case 108:
#line 706 "../gramObjc.ycc"
{
	yyval.otype= new PrimitiveType(PrimitiveType::tDouble);
    ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 711 "../gramObjc.ycc"


/* --------------- Fin de la grammaire --------------- */
