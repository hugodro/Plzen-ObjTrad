/********************************************************
* Fichier: objcTokens.l
* Desc: traducteur de mots pour compiler le langage Obj-C.
* Module: AkraLog : JavaKit.
* Revision: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
********************************************************/

%option yylineno

%{

/* On met ici les declaration et les fichiers inclus */

#include <stdio.h>
#include <akra/portableDefs.h>

#ifndef _cplusplus
#define class	typedef unsigned int 
class Identifier;
class OAbstractType;
class VariableDeclaration;
class FunctionalDeclaration;
class OType;
class Slot;
class VariableModificator;
class Parameter;
#endif

#include "y.tab.h"


extern void PasseCommentaire1(void);
extern void PasseCommentaire2(void);
extern void PreCompDirective(void);
extern int GetTokenID(char *);
extern void ShowCompilerMessage(int, char *, char *);


/*** Variables globales definies dans ce module. ***/
static char StrBuffer[1024];

%}


alpha   [a-zA-Z]
digit   [0-9]
hexa [0-9a-fA-F]
special [\_]
ident   (({alpha}|{special})({alpha}|{digit}|{special})*)
integer     ({digit}+[lL]?)
exp     ([Ee][-+]?{digit}+)
float   ((({digit}+\.?)|(\.{digit}+)){digit}*{exp}?[fFdD]?)
timenum ({digit}+[YMDhmstun])
timeval ({timenum}+)
hexaNumber (0x{hexa}+)
newlineCR (\r)
newlineLF (\n)
newlineMIX ({newlineCR}{newlineLF})
newline ({newlineMIX}|{newlineCR}|{newlineLF})


/* --------------- Debut des definitions de mots --------------- */

%%
[\ \t\f]+   {;}
{newline}[\ ]*#		{ PreCompDirective(); }
{newline}	        { ; }

"/*"            { PasseCommentaire1(); }
"//"            { PasseCommentaire2(); }

"@"		{ return '@'; }
"("             { return '('; }
","             { return ','; }
")"             { return ')'; }
";"             { return ';'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }
"*"             { return '*'; }
"/"             { return '/'; }
"+"             { return '+'; }
"-"             { return '-'; }
"%"             { return '%'; }
"^"             { return '^'; }
"&"             { return '&'; }
"|"		{ return '|'; }
"`"		{ return '`'; }
"?"             { return '?'; }
":"             { return ':'; }
"!"             { return '!'; }
"."             { return '.'; }
"~"             { return '~'; }
"<"             { return '<'; }
">"             { return '>'; }
"."             { return '.'; }
"="             { return '='; }
"\.\.\."             { return ELLIPSIS_KW; }


\' {
    unsigned int i;
    char *tmpStr= StrBuffer, c;
    
    i= 0;
    do {
    	if ((*tmpStr++= input()) == '\'') {
	    if ((c= input()) != '\'') {
	    	unput(c);
		*(tmpStr-1)= '\0';
		break;
	     }
	 }
	else {
	    if (*(tmpStr-1) == 0) {	/* Si on frappe une fin de fichier, on avertit ! */
		ShowCompilerMessage(1, "Got EOF while in char constant", NULL);
		break;
	     }
	    else if (i++ > 4) {
		ShowCompilerMessage(1, "Char constant is longer than 4 characters", NULL);
		break;
	     }
	 }
     } while(1);
    yylval.string= StrBuffer;
    return LITERAL_CHAR;
}


{ident} {
    struct PreCompiler *cppInfo;
    struct PreCompilerMacro *macro;
    int tokenID;

#ifdef A_FAIRE
    if ((macro= GetMacroNamed(cppInfo->macroDefinitions, yytext)) != NULL) {
	ExpandMacro(cppInfo, macro);
     } else
#endif

    if ((tokenID= GetTokenID(yytext)) != -1) {
	return tokenID;
     }
    else {
	yylval.string= yytext;
	return IDENTIFIER_KW;
     }

}


{integer} {
	unsigned int i, result;

	i= strlen(yytext);
	if ((yytext[i]== 'l') || (yytext[i] == 'L')) {
	    yylval.longNumber[0]= atoi(yytext);
	    result= LITERAL_LONG;
	 }
	else {
	    yylval.integerNumber= atoi(yytext);
	    result= LITERAL_INT;
	 }
	return result;
}


{float} {
/* ATTENTION: Doit traiter le type de float trouve (simple ou double). */
	sscanf(yytext, "%g", &yylval.floatNumber);
	return LITERAL_FLOAT;
 }


{hexaNumber} {
	unsigned int i, j;
	char c;

	yylval.integerNumber= 0;
	if ((i= strlen(yytext)) < 7) {
	    for (j= 2; j < i; j++) {
	    	c= yytext[i];
		yylval.integerNumber+= (unsigned int )((c > '9') ? (toupper(c) - 'A') : (c - '0')) * (1 << (8 * (i - j)));
	     }
	 }
	else {
	    /* Declare un overflow. */
	 }
	return LITERAL_INT;
 }


\" {
    unsigned int i;
    char *tmpStr= StrBuffer, c;
    
    i= 0;
    do {
    	if ((*tmpStr++= input()) == '"') {
	    if ((c= input()) != '"') {
	    	unput(c);
		*(tmpStr-1)= '\0';
		break;
	     }
	 }
	else {
	    if (*(tmpStr-1) == 0) {	/* Si on frappe une fin de fichier, on avertit ! */
		ShowCompilerMessage(1, "Reached EOF while reading string constant", NULL);
		break;
	     }
	    else if (i++ > 512) {
		ShowCompilerMessage(1, "string constant is longer than 512 characters", NULL);
		break;
	     }
	 }
     } while(1);
    yylval.string= StrBuffer;
    return LITERAL_STRING;
}


.                       { return 0; }

%%



/* --------------- Fin des definitions de mots --------------- */


int lexInput()
{
    return input();
}


void lexUnput(int c)
{
    unput(c);
}


