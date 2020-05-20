/**************************************************
* File: lexicalHelp.cc.
* Desc: Fonctions pour aider a l'analyse du lexique.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <stdio.h>
#include <ctype.h>
#include <akra/portableDefs.h>
#include "preCompiling.h"
#include "translator.h"
#include "lexicalHelp.h"

class Identifier;
class OAbstractType;
class VariableDeclaration;
class FunctionalDeclaration;
class OType;
class Slot;
class VariableModificator;
class Parameter;
#include "y.tab.h"


/* Declarations des fonctions utilises par ce module. */

extern "C" {
    extern int lexInput();
    extern void lexUnput(int);


/* Declarations des fonctions dans ce module. */

    void PasseCommentaire1(void);
    void PasseCommentaire2(void);
    void PreCompDirective(void);
    int GetTokenID(char *);
    void yyerror(char *);
    void ShowCompilerMessage(int, char *, char *);
    int yywrap();
}


int IncludeDirective(void);
int DefineDirective(void);
int IfdefDirective(boolean);
int IfNdefDirective(void);
int elseDirective(void);
int EndifDirective(void);
int IfDirective(void);
int ElifDirective(void);
int UndefDirective(void);

int GetPreCompIdent(char *);
int GetArgList(MacroArgument **arguments);
int ReadMacroValue(CompiloMacro *);
int PasseCodeCond(void);
int PasseString(void);
int FinishDirectLine(void);



/* Variables globales definies dans ce module. */

int yylineno;
static char StrBuffer[1024];
extern ObjcTranslator *compiler;


/********************************************************
* Fonction: PasseCommentaire1.
* Desc: Prend une suite de commentaire (commencee par '/''*')
*       et ignore tout ce qui suit, jusqu'a '*''/'.
* Args: Aucun.
* Renvoie: Rien.
********************************************************/

void PasseCommentaire1(void)
{
    char lastChar, c;

    while (1) {
	while ((c = lexInput()) != '/') lastChar= c;
	if (lastChar == '*') {
	    return;
	 }
        else if (c == EOF_CHAR) {
	    return;
	 }
	else lastChar= c;
    }
}


/********************************************************
* Fonction: PasseComentaire2.
* Desc: Prend une suite de commentaire (commencee par '/''/')
*       et ignore tout ce qui suit, jusqu'a la fin de la ligne.
* Args: Aucun.
* Renvoie: Rien.
********************************************************/

void PasseCommentaire2(void)
{
    char c;

    while ((c = lexInput()) != '\n') {
	if (c == EOF_CHAR) {
	    break;
	 }
     }

    if (c == '\n') lexUnput(c);

    return;
}


/********************************************************
* Fonction: PreCompDirective.
* Desc: Traite une directive de compilation.
* Args: Aucun.
* Renvoie: Rien.
********************************************************/

void PreCompDirective(void)
{
    int resultat;
    unsigned int i, offset, nbrDirectives= 9;	/* nbrDirectives = nbr de directives - 1. */
    static char *nomDirective[10]= { "define", "else", "elif", "endif", "if", "ifdef", "ifndef", "import", "include", "undef" };
    static unsigned int directives[11]= { MKW_DEFINE, MKW_ELSE, MKW_ELIF, MKW_ENDIF,
    		MKW_IF, MKW_IFDEF, MKW_IFNDEF, MKW_IMPORT,  MKW_INCLUDE, MKW_UNDEF, 0 };
    char c, *directiveName;
    boolean encore, trouve;

    trouve= false;
    encore= true;
    i= 0;
    offset= 0;
    directiveName= nomDirective[0];
    c= lexInput();
    do {
	if (c != *directiveName++) {
	    if (i++ == nbrDirectives) encore= false;
	    else directiveName=  nomDirective[i] + offset;
	    if (offset > 0) {
		if (nomDirective[i-1][offset-1] != *(directiveName-1)) {
		    encore= false;
		 }
	     }
	 }
	else if (*directiveName == '\0') {
	    c= lexInput();
	    if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r')) {
		trouve= true;
		encore= false;
		lexUnput(c);
	     }
	    else offset++;
	 }
	else {
	    c= lexInput();
	    offset++;
	 }
     } while (encore);
    if (trouve) {

	switch (directives[i]) {
	    case MKW_IMPORT:    /* include "filename" .*/
	    case MKW_INCLUDE:    /* include "filename" .*/
		resultat= IncludeDirective();
		break;
	    case MKW_DEFINE:    /* define <nom> <valeur>. */
		resultat= DefineDirective();
		break;
	    case MKW_IFDEF:    /* ifdef <nom>. */
		resultat= IfdefDirective(true);
		break;
	    case MKW_IFNDEF:    /* ifndef <nom>. */
		resultat= IfdefDirective(false);
		break;
	    case MKW_ELSE:    /* else. */
		resultat= elseDirective();
		break;
	    case MKW_ENDIF:    /* endif. */
		resultat= EndifDirective();
		break;
	    case MKW_IF:    /* if <expression_precom>. */
		resultat= IfDirective();
		break;
	    case MKW_ELIF:    /* elif <expression_precomp>. */
		resultat= ElifDirective();
		break;
	    case MKW_UNDEF:    /* undef <nom>. */
		resultat= UndefDirective();
		break;
	    default: /* Erreur interne. */
		break;
	 }

     }
    else {
	yyerror("syntax error: invalid compiler directive");
     }
}


int GetTokenID(char *aName)
{
#define NBR_KEYWORDS	25
    int resultat= -1;
    unsigned int i;

    char *tokens[NBR_KEYWORDS]= {
	"bycopy", "char", "class", "const", "double",
	"end","float", "id", "in", "inout",
	"int", "interface", "long", "oneway", "out",
	"private", "protocol", "protected", "public", "short",
	"signed", "struct", "unsigned", "void", "volatile"
    };

    int tokensID[NBR_KEYWORDS]= {
	BYCOPY_KW, CHAR_KW, CLASS_KW, CONST_KW, DOUBLE_KW,
	END_KW, FLOAT_KW, ID_KW, IN_KW, INOUT_KW,
	INT_KW, INTERFACE_KW, LONG_KW, ONEWAY_KW, OUT_KW,
	PRIVATE_KW, PROTOCOL_KW, PROTECTED_KW, PUBLIC_KW, SHORT_KW,
	SIGNED_KW, STRUCT_KW, UNSIGNED_KW, VOID_KW, VOLATILE_KW
     };


    for (i= 0; i < NBR_KEYWORDS; i++) {
	if (strcmp(aName, tokens[i]) == 0) {
	    break;
	}
    }

    if (i < NBR_KEYWORDS) {
	return tokensID[i];
    }

    return -1;
}


void yyerror(char *msg)
{
    fprintf(stderr, "%s on line %d.\n", msg, yylineno);
}


int yywrap()
{
    return 1;
}


void ShowCompilerMessage(int lineNum, char *msg1, char *msg2)
{
    char msgBuffer[200];

    sprintf(msgBuffer, msg1, msg2);
    fprintf(stderr, "line %d: %s", yylineno, msgBuffer);
}


int IncludeDirective(void)
{
    int resultat= 0;
    unsigned int i;
    char  c;
    static char includeFileName[MAX_FILEPATH_LEN];
    boolean trouve, encore;

    trouve= encore= false;
    i= 0;
    while ((c = lexInput()) != '\n') {
	if ((c == '"') || (c == '<') || (c == '>')) {
		// ATTN: Should make sure that '<' and '>' are well paired.
	    if (encore) {
		StrBuffer[i]= '\0';
		trouve= true;
		break;
	     }
	    else encore= true;
	 }
	else {
	    if (c == EOF_CHAR) {
		ShowCompilerMessage(1, "#include: unexpected EOF.\n", NULL);
		encore= false;
		resultat= -4;
	     }
	    if (encore) StrBuffer[i++]= c;
	 }
     }

    if (c == '\n') lexUnput(c);

    if ((resultat == 0) && trouve) {
	ShowCompilerMessage(1, "include request for file %s.\n", StrBuffer);
     }
    else {
	/* Pas trouve le nom de fichier. */
	ShowCompilerMessage(1, "#include: could not find a file to include.\n", NULL);
	resultat= -3;
     }

    return resultat;
}


int DefineDirective(void)
{
    CompiloMacro *macro;
    int resultat= 0, scanResult;
    static char identBuffer[CompiloMacro::maxNameLength];

    compiler->setParseMode(ObjcTranslator::pmMacro);

    if ((scanResult= GetPreCompIdent(identBuffer)) >= 0) {
	macro= new CompiloMacro(identBuffer);
	macro->setPriority(false);
	if (scanResult == 1) scanResult= GetArgList(&macro->arguments);
	else if (scanResult == 2) {
	    if (!compiler->addMacro(macro)) {
		delete macro;
		resultat= -3;
	     }
	    else {
		/* On indique a la prochaine passe qu'il n'y a rien a faire. */
		scanResult= 2;
	     }
	 }
	if (scanResult == 0) {
	    scanResult= ReadMacroValue(macro);
	    if (scanResult == 0) {
		if (!compiler->addMacro(macro)) {
		    delete macro;
		    resultat= -3;
		 }
	     }
	 }
	else if (scanResult != 2) resultat= -2;
     }
    else {
	resultat= -1;
     }

    compiler->setParseMode(ObjcTranslator::pmSource);

    return resultat;
}


int GetPreCompIdent(char *buffer)
{
    int resultat= -1;
    char c, *bufferPtr;
    boolean encore= true, isReadingIdent= false;

    bufferPtr= buffer;
    do {
	c= lexInput();
	if (c == '\n') {
	    if (isReadingIdent) {
		resultat= 2;
	     }
	    encore= false;
	 }
	else if (c == 0) {
	    ShowCompilerMessage(1, "pre-compiler: unexpected EOF.\n", NULL);
	    resultat= -4;
	 }
	else if (c == '(') {
	    if (isReadingIdent) resultat= 1;
	    else resultat= -2;
	 }
	else if ((c == ' ')  || (c == '\t')) {
	    if (isReadingIdent) {
		resultat= 0;
		encore= false;
	     }
	 }
	else if (isalpha((int)c) || (c == '_')) {
	    isReadingIdent= true;
	    if ((bufferPtr - buffer) < CompiloMacro::maxNameLength) {
		*bufferPtr++= c;
	     }
	    else {
		encore= false;
		resultat= -6;
	     }
	 }
	else if (isdigit((int)c)) {
	    if (isReadingIdent) {
		if ((bufferPtr - buffer) < CompiloMacro::maxNameLength) {
		    *bufferPtr++= c;
		 }
		else {
		    encore= false;
		    resultat= -6;
		 }
	     }
	    else {
		encore= false;
		resultat= -3;
	     }
	 }
	else {
	    encore= false;
	    resultat= -5;
	 }
     } while (encore);

    if (c == '\n') lexUnput(c);

    else {
	if ((c == ' ') || (c == '\t')) {
	    encore= true;
	    do {
		c= lexInput();
		if ((c != ' ') && (c != '\t')) {
		    lexUnput(c);
		    encore= false;
		 }
	     } while (encore);
	 }
     }

    if (resultat > -1) *bufferPtr= '\0';
    return resultat;
}


int GetArgList(MacroArgument **arguments)
{
    MacroArgument *lastArgPtr;
    int resultat= -1;
    unsigned int nbrArguments;
    char tmpIdent[CompiloMacro::maxNameLength], *bufferPtr, c;
    boolean encore= true, isReadingIdent= false, needSeparator;

    bufferPtr= tmpIdent;
    needSeparator= false;
    do {
	c= lexInput();
	if (c == '\n') {
	    encore= false;
	 }
	else if (c == 0) {
	    ShowCompilerMessage(1, "#define: unexpected EOF.\n", NULL);
	    resultat= -4;
	 }
	else if (c == ')') {
	    if (isReadingIdent) {
		*bufferPtr= '\0';
		if (lastArgPtr) {
		    lastArgPtr->next= new MacroArgument(tmpIdent);
		    lastArgPtr= lastArgPtr->next;
		 }
		else {
		    lastArgPtr= new MacroArgument(tmpIdent);
		    *arguments= lastArgPtr;
		 }
		resultat= 0;
	     }
	    else if (!needSeparator) {
		resultat= -7;
	     }
	    else resultat= 0;
	    encore= false;
	 }
	else if ((c == ' ')  || (c == '\t')) {
	    if (isReadingIdent) {
		*bufferPtr= '\0';
		if (lastArgPtr) {
		    lastArgPtr->next= new MacroArgument(tmpIdent);
		    lastArgPtr= lastArgPtr->next;
		 }
		else {
		    lastArgPtr= new MacroArgument(tmpIdent);
		    *arguments= lastArgPtr;
		 }
		needSeparator= true;
	     }
	 }
	else if (c == ',') {
	    if (isReadingIdent) {
		*bufferPtr= '\0';
		if (lastArgPtr) {
		    lastArgPtr->next= new MacroArgument(tmpIdent);
		    lastArgPtr->next->prev= lastArgPtr;
		    lastArgPtr= lastArgPtr->next;
		    lastArgPtr->next= NULL;
		 }
		else {
		    lastArgPtr= new MacroArgument(tmpIdent);
		    lastArgPtr->prev= lastArgPtr->next= NULL;
		    *arguments= lastArgPtr;
		 }
		needSeparator= false;
	     }
	    else if (!needSeparator) {
		encore= false;
		resultat= -7;
	     }
	 }
	else if (isalpha((int)c) || (c == '_')) {
	    isReadingIdent= true;
	    if ((bufferPtr - tmpIdent) < CompiloMacro::maxNameLength) {
		*bufferPtr++= c;
	     }
	    else {
		encore= false;
		resultat= -6;
	     }
	 }
	else if (isdigit((int)c)) {
	    if (isReadingIdent) {
		if ((bufferPtr - tmpIdent) < CompiloMacro::maxNameLength) {
		    *bufferPtr++= c;
		 }
		else {
		    encore= false;
		    resultat= -6;
		 }
	     }
	    else {
		encore= false;
		resultat= -3;
	     }
	 }
	else {
	    encore= false;
	    resultat= -5;
	 }
     } while (encore);
    return resultat;
}


int ReadMacroValue(CompiloMacro *macro)
{
    CompiloMacro *tmpMacro;
    struct MacroValue *tmpValue;
    struct MacroSegment *segmentPtr, *lastSegmentPtr;
    MacroArgument *tmpArgPtr;
    int resultat= -1;
    MacroValue::ReadingMode mode;
    static char valueBuf[CompiloMacro::maxBufferLength];
    char *bufferPtr, *identStart, tmpChar, c;
    boolean encore= true, isReadingIdent, gotAnIdent;

    tmpValue= new MacroValue();

    bufferPtr= valueBuf;
    mode= MacroValue::readValue;
    isReadingIdent= gotAnIdent= false;

    do {
	if (gotAnIdent) {
	    c= tmpChar;
	    gotAnIdent= false;
	 }
	else
	    c= lexInput();
	if (c == '\n') {
	    if (mode != MacroValue::concatenate) {
		encore= false;
		resultat= 0;
		lexUnput('\n');
		*bufferPtr= '\0';
	     }
	    else mode= MacroValue::readValue;
	 }
	else if (c == 0) {
	    ShowCompilerMessage(1, "#define: unexpected EOF.\n", NULL);
	    resultat= -2;
	 }
	else if ((c == ' ')  || (c == '\t')) {		/* Un espace. */
	    if (isReadingIdent) {
		tmpChar= c;
		*bufferPtr= '\0';
		isReadingIdent= false;
		gotAnIdent= true;
	     }
	    else {
		*bufferPtr++= c;
	     }
	 }
	else if (isalpha((int)c) || (c == '_')) {	/* Une lettre ou '_'. */
	    if (mode == MacroValue::concatenate) {
		encore= false;
		resultat= -4;
	     }
	    else {
		if (!isReadingIdent && (mode == MacroValue::readValue)) {
		    isReadingIdent= true;
		    identStart= bufferPtr;
		 }
		*bufferPtr++= c;
	     }
	 }
	else if (isdigit((int)c)) {	/* Un chiffre. */
	    if (mode == MacroValue::concatenate) {
		encore= false;
		resultat= -4;
	     }
	    else {
		*bufferPtr++= c;
	     }
	 }
	else if (c == '"') {
	    if (mode == MacroValue::concatenate) {
		encore= false;
		resultat= -5;
	     }
	    else {
		if (mode == MacroValue::readString) mode= MacroValue::readValue;
		else mode= MacroValue::readString;
		*bufferPtr++= c;
	     }
	 }
	else if (c == '\\') {	/* On veut concatener la prochaine ligne. */
	    if (mode == MacroValue::readValue) mode= MacroValue::concatenate;
	    else if (mode != MacroValue::readString) {
		encore= false;
		resultat= -3;
	     }
	 }
	else {		/* Tout autre caractere. */
	    if (mode == MacroValue::concatenate) {
		encore= false;
		resultat= -4;
	     }
	    else {
		if (isReadingIdent) {
		    tmpChar= c;
		    *bufferPtr= '\0';
		    gotAnIdent= true;
		    isReadingIdent= false;
		 }
		else {
		    *bufferPtr++= c;
		 }
	     }
	 }

	if (gotAnIdent) {
	    if ((tmpArgPtr= macro->getArgument(identStart)) != NULL) {
		    segmentPtr= new SegmentVariable(tmpArgPtr);
		    tmpValue->addSegment(segmentPtr);
		    bufferPtr= identStart;
	     }
	    else if ((tmpMacro= compiler->getMacro(identStart)) != NULL) {
		    segmentPtr= new SegmentMacro(tmpMacro);
		    tmpValue->addSegment(segmentPtr);
		    bufferPtr= identStart;
	     }
	 }
	if ((bufferPtr - valueBuf) == CompiloMacro::maxBufferLength) {
	    segmentPtr= new SegmentString(valueBuf, CompiloMacro::maxBufferLength);
	    tmpValue->addSegment(segmentPtr);
	    bufferPtr= valueBuf;
	 }
     } while (encore);
    if (resultat == 0) {
	if (bufferPtr != valueBuf) {
	    segmentPtr= new SegmentString(valueBuf, strlen(valueBuf));
	    tmpValue->addSegment(segmentPtr);
	 }
	macro->setValue(tmpValue);
     }
    else {
	delete tmpValue;
     }

    return resultat;
}


int IfdefDirective(boolean branchOnTrue)
{
    CompiloMacro *macro;
    ConditionalSegment *condBlock;
    int resultat= -1, scanResult;
    static char identBuffer[CompiloMacro::maxNameLength + 1];
    char c;
    boolean encore, commentStart;

    compiler->setParseMode((branchOnTrue) ? ObjcTranslator::pmCondIfDef : ObjcTranslator::pmCondIfNDef);
    if ((scanResult= GetPreCompIdent(identBuffer)) >= -1) {
/* ATTENTION: Comment gerer un macro avec argument ?  Faudrait-il lire ses arguments ensuite ? */
	if (scanResult == 1) {
		/* Pour le moment, on rejete l'arrive d'arguments. */
	    resultat= -2;
	 }
	else {
		/* Syntaxe: il ne doit rien y avoir apres, sauf commentaires et un newline. */
	    if (scanResult == 0) {
		scanResult= FinishDirectLine();
	     }
	    else scanResult= 0;	/* Sinon c'est -1, et donc on a bouffe le newline. */
	    if (scanResult == 0) {
		condBlock= new ConditionalSegment((branchOnTrue) ? ConditionalSegment::tIfdef : ConditionalSegment::tIfndef);
		compiler->pushConditionalSegment(condBlock, identBuffer);
		if (!condBlock->testResult()) {	/* Si on doit passer par dessus le code source: */
		    scanResult= PasseCodeCond();
		    if (scanResult > 0) {	/* On a trouve une commande de fin de scan. */
			resultat= 0;
		     }
		 }
		else resultat= 0;
	     }
	    else resultat= -3;
	 }
     }
    compiler->setParseMode(ObjcTranslator::pmSource);
    return resultat;
}


#if defined(OLD_CODE)
int IfNdefDirective(void)
{
/* ATTENTION: C'est la meme chose que ifdefDirective, sauf pour le test. */
    CompiloMacro *macro;
    ConditionalSegment *condBlock;
    int resultat= -1, scanResult;
    static char identBuffer[CompiloMacro::maxNameLength + 1];	/* La lng maximale d'un nom de macro est CompiloMacro::maxNameLength */
    char c;
    boolean encore, commentStart;

    globalCompiler->cppInfo->lexMode= LEX_IF;
    if ((scanResult= GetPreCompIdent(identBuffer)) >= -1) {
/* ATTENTION: Comment gerer un macro avec argument ?  Faudrait-il lire ses arguments ensuite ? */
	if (scanResult == 1) {
		/* Pour le moment, on rejete l'arrive d'arguments. */
	    resultat= -2;
	 }
	else {
		/* Syntaxe: il ne doit rien y avoir apres, sauf commentiares et un newline. */
	    if (scanResult == 0) {
		scanResult= FinishDirectLine();
	     }
	    else scanResult= 0;	/* Sinon c'est -1, et donc on a bouffe le newline. */
	    if (scanResult == 0) {
		condBlock= (struct ConditionalBlock *)malloc(sizeof(struct ConditionalBlock));
		condBlock->next= globalCompiler->cppInfo->ifBlocks;
		globalCompiler->cppInfo->ifBlocks= condBlock;
		condBlock->result= ((macro= GetMacroNamed(globalCompiler->cppInfo->macroDefs, identBuffer)) == NULL);
		condBlock->type= BLOCK_IFNDEF;
		condBlock->startLine= nbrLignes;
		if (condBlock->result == false) {	/* Si on doit passer par dessus le code source: */
		    scanResult= PasseCodeCond();
		    if (scanResult > 0) {	/* On a trouve une commande de fin de scan. */
			resultat= 0;
		     }
		 }
		else resultat= 0;
	     }
	    else resultat= -3;
	 }
     }
    globalCompiler->cppInfo->lexMode= LEX_NORMAL;
    return resultat;
}
#endif


int elseDirective(void)
{
    ConditionalSegment *block;
    int resultat= -1, scanResult;

    if ((block= compiler->popCondSegment()) != NULL) {
	if (block->getKind() == ConditionalSegment::tElse) {
	    ShowCompilerMessage(1, "pre-comp: #else after #else.\n", NULL);
	    resultat= -2;
	 }
	else {
	    block->setKind(ConditionalSegment::tElse);
	    compiler->pushConditionalSegment(block);

	    scanResult= FinishDirectLine();
	    if (scanResult == 0) {
		if (block->testResult()) {
		    if (scanResult == 0) {
			scanResult= PasseCodeCond();
			if (scanResult > 0) {
			    resultat= 0;
			 }
			else resultat= -3;
		     }
		 }
		else {
		    resultat= 0;
		 }
	     }
	    else resultat= -4;
	 }
     }
    else {
	ShowCompilerMessage(1, "pre-comp: #else without a #if to start with.\n", NULL);
     }
    return resultat;
}


int EndifDirective(void)
{
    ConditionalSegment *block;
    int resultat= -1, scanResult;

    if ((block= compiler->popCondSegment()) != NULL) {
	scanResult= FinishDirectLine();
	if (scanResult == 0) {
	    resultat= 0;
	 }
	else resultat= -4;
     }
    else {
	ShowCompilerMessage(1, "pre-comp: #endif without a #if to start with.\n", NULL);
     }
    return resultat;
}


int IfDirective(void)
{
    int resultat= -1;

    ShowCompilerMessage(1, "pre-comp: #if directive, not implemented.\n", NULL);
    return resultat;
}


int ElifDirective(void)
{
    int resultat= -1;
    ShowCompilerMessage(1, "pre-comp: #if directive, not implemented.\n", NULL);
    return resultat;
}


int UndefDirective(void)
{
    CompiloMacro *macro;
    int resultat= -1, scanResult;
    static char identBuffer[CompiloMacro::maxNameLength + 1];	/* La lng maximale d'un nom de macro est CompiloMacro::maxNameLength */


    if ((scanResult= GetPreCompIdent(identBuffer)) >= -1) {
	if (scanResult == 1) {
		/* Pour le moment, on rejete l'arrive d'arguments. */
	    resultat= -2;
	 }
	else {
		/* Syntaxe: il ne doit rien y avoir apres, sauf commentaires et un newline. */
	    if (scanResult == 0) {
		scanResult= FinishDirectLine();
	     }
	    else scanResult= 0;	/* Sinon c'est -1, et donc on a bouffe le newline. */
	    if (scanResult == 0) {
		macro= compiler->getMacro(identBuffer);
		if (macro != NULL) {
		    compiler->deleteMacro(macro);
		    resultat= 0;
		 }
		else {
		    ShowCompilerMessage(1, "pre-comp: #undef of unknown symbol.\n", NULL);
		    resultat= -3;
		 }
	     }
	    else {
		ShowCompilerMessage(1, "pre-comp: extra text after #undef symbol.\n", NULL);
		resultat= -4;
	     }
	 }
     }
    else {
	ShowCompilerMessage(1, "pre-comp: bad syntax after #undef.\n", NULL);
	resultat= -5;
     }
    return resultat;
}


int PasseCodeCond(void)
{
    int resultat= -1;
    unsigned int i, j;
    char c, cmdBuffer[10];
    boolean encore, isFirstOnLine, commentStart;

    isFirstOnLine= true;
    commentStart= false;
    encore= true;
    do {
	c= lexInput();
	if (c == '\n') {
	    isFirstOnLine= true;
	    commentStart= false;
	 }
	else if (c == EOF_CHAR) {
		ShowCompilerMessage(1, "conditional compilation: unexpected EOF.\n", NULL);
		encore= false;
		resultat= -3;
	 }
	else if (c == '#') {
	    if (isFirstOnLine) {
		/* si on detecte un else, elif, endif. */
		cmdBuffer[0]= lexInput();
		if (cmdBuffer[0] == 'e') {
		    for (i= 1; i < 6; i++) {
			cmdBuffer[i]= lexInput();
			if (!isalpha(cmdBuffer[i])) {
			    lexUnput(cmdBuffer[i]);
			    break;
			 }
		     }
			/* On remet tout de suite le car non alpha. */
		    cmdBuffer[i]= '\0';
		    if (strcmp(cmdBuffer, "else") == 0) {
			resultat= 1;
			encore= false;
		     }
		    else if (strcmp(cmdBuffer, "elif") == 0) {
			resultat= 2;
			encore= false;
		     }
		    else if (strcmp(cmdBuffer, "endif") == 0) {
			resultat= 3;
			encore= false;
		     }
		    if (!encore) {
			    /* On remet le data dans le buffer, pour que le 'lex' s'occupe de lancer la prochaine directive. */
			for (j= 0; j < i; j++) {
			    lexUnput(cmdBuffer[i-j-1]);
			 }
			lexUnput(c);
			lexUnput('\n');
		     }
		 }
		else lexUnput(cmdBuffer[0]);
		    /* sinon on continue a lire. */
		isFirstOnLine= false;
	     }
	    commentStart= false;
	 }
	else if (c == '/') {
	    if (!commentStart) {
		commentStart= true;
	     }
	    else {
		PasseCommentaire2();
	     }
	 }
	else if (c == '*') {
	    if (commentStart) {
		PasseCommentaire1();
	     }
	 }
	else if ((c == ' ') || (c == '\t')) {
	    commentStart= false;

	 }
	else if (c == '"') {
	    if (PasseString() != 0) {
		encore= false;
		resultat= -2;
	     }
	 }
	else {
	    commentStart= false;
	    isFirstOnLine= false;
	 }
     } while (encore);
    return resultat;
}


int PasseString(void)
{
    int resultat= -1;
    char c;
    boolean encore= true;

    do {
	c= lexInput();
	if (c == '"') {
	    c= lexInput();
	    if (c == '"') {
		
	     }
	    else {
		lexUnput(c);
		encore= false;
		resultat= 0;
	     }
	 }
	else if (c == 0) {
	    ShowCompilerMessage(1, "conditional compilation: unexpected EOF.\n", NULL);
	    resultat= -2;
	    encore= false;
	 }
     } while (encore);

    return resultat;
}


int FinishDirectLine(void)
{
    int resultat= -1;
    char c;
    boolean encore, commentStart;

    encore= true;
    commentStart= false;
    do {
	c= lexInput();
	if (c == '\n') {
	    encore= false;
	    resultat= 0;
	}
	else if (c == '/') {
	    if (!commentStart) {
		commentStart= true;
	    }
	    else {
		PasseCommentaire2();
		encore= false;
		resultat= 0;
	    }
	}
	else if (c == '*') {
	    if (commentStart) {
		PasseCommentaire1();
	    }
	    else {
		encore= false;
		resultat= -4;
	    }
	}
	else if ((c == ' ') || (c == '\t')) {
	    commentStart= false;
	}
	else {
	    encore= false;
	    resultat= -4;
	}
    } while (encore);


    return resultat;
}

