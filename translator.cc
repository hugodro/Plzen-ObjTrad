/**************************************************
* File: translator.cc.
* Desc: Implementation of the ObjcTranslator class.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

extern "C" {
#include <string.h>
#include <time.h>
}

#include <iostream.h>
#include <Compiler/sourceFile.h>
#include "identifier.h"
#include "memberSupport.h"
#include "metaTypes.h"
#include "members.h"
#include "preCompiling.h"
#include "translator.h"


extern "C" {

/* Variables used in this module defined in external modules. */

extern int yylineno;
extern FILE *yyin;

}


extern int yyparse(void);


/**************************************************
* Implementation: ObjcTranslator.
**************************************************/

ObjcTranslator *ObjcTranslator::publicCompiler= NULL;


ObjcTranslator *ObjcTranslator::getCurrentCompiler(void)
{
    return publicCompiler;
}


ObjcTranslator::ObjcTranslator(void)
{
    publicCompiler= this;
}


boolean ObjcTranslator::boot(int argc, char **argv)
{
    abstractTypeList= tailAbstractType= NULL;
    classNotifications= NULL;
    identifierList= tailIdent= NULL;
    nbrDeclList= 0;
    varDeclList[0]= tailVarDecl[0]= NULL;
    fctDeclList= tailFctDecl= NULL;
    slotList= tailSlot= NULL;
    nbrParamList= 0;
    parameterList[0]= tailParam[0]= NULL;
    macros= NULL;
    conditionalSection= NULL;

    inputFileName= new char[strlen(argv[argc-1]) + 1];
    strcpy(inputFileName, argv[argc-1]);
    return true;
};


int ObjcTranslator::parseFile(char *aFile)
{
    SourceFile *mainSource;
    int result;

    mainSource= new SourceFile(aFile);
    if (mainSource->getFIO() != NULL) {
	yyin= mainSource->getFIO();
	result= yyparse();
	if (result == 0) {
	    writeAsJava();
	}
     }
    else {
	result= -1;
     }
    return result;
}


void ObjcTranslator::startStructList(VariableDeclaration *aVarDecl)
{
    varDeclList[nbrDeclList]= tailVarDecl[nbrDeclList]= aVarDecl;
    nbrDeclList++;
}


void ObjcTranslator::startParamList(Parameter *aParam)
{
    parameterList[nbrParamList]= tailParam[nbrParamList]= aParam;
    nbrParamList++;
}


void ObjcTranslator::linkExternalDecl(OAbstractType *aMetaType)
{
    if (abstractTypeList == NULL) {
	abstractTypeList= aMetaType;
    }
    else {
	tailAbstractType->setNext(aMetaType);
    }
    tailAbstractType= aMetaType;
}


void ObjcTranslator::linkIdentifier(Identifier *anIdent)
{
    if (identifierList == NULL) {
	identifierList= anIdent;
    }
    else {
	tailIdent->setNext(anIdent);
    }
    tailIdent= anIdent;
}


void ObjcTranslator::linkStructDecl(VariableDeclaration *aVarDecl)
{
    if (varDeclList[nbrDeclList-1] == NULL) {
	varDeclList[nbrDeclList-1]= aVarDecl;
    }
    else {
	tailVarDecl[nbrDeclList-1]->setNext(aVarDecl);
    }
    tailVarDecl[nbrDeclList-1]= aVarDecl;
}


void ObjcTranslator::linkDeclaration(FunctionalDeclaration *aFctDecl)
{
    if (fctDeclList == NULL) {
	fctDeclList= aFctDecl;
    }
    else {
	tailFctDecl->setNext(aFctDecl);
    }
    tailFctDecl= aFctDecl;
}


void ObjcTranslator::linkSlotDecl(Slot *aSlot)
{
    if (slotList == NULL) {
	slotList= aSlot;
    }
    else {
	tailSlot->setNext(aSlot);
    }
    tailSlot= aSlot;
}


void ObjcTranslator::linkParameter(Parameter *aParam)
{
    if (parameterList[nbrParamList-1] == NULL) {
	parameterList[nbrParamList-1]= aParam;
    }
    else {
	tailParam[nbrParamList-1]->setNext(aParam);
    }
    tailParam[nbrParamList-1]= aParam;
}


void ObjcTranslator::addClassNotification(Identifier *someClasses)
{
    someClasses->setNext(classNotifications);
    classNotifications= someClasses;
}



Identifier *ObjcTranslator::flushIdentList(void)
{
    Identifier *result= identifierList;
    identifierList= tailIdent= NULL;
    return result;
}


VariableDeclaration *ObjcTranslator::flushStructList(void)
{
    VariableDeclaration *result;

    if (nbrDeclList > 0) {
	nbrDeclList--;
	result= varDeclList[nbrDeclList];
	varDeclList[nbrDeclList]= tailVarDecl[nbrDeclList]= NULL;
    }
    else {
	cout << "ERRMSG: ObjcTranslator::flushStructList doit faire un flush alors qu'il n'y a pas de liste en cours ";
	cout << " (ligne= " << yylineno << ").\n";
	result= NULL;
    }
    return result;
}


FunctionalDeclaration *ObjcTranslator::flushDeclarationList(void)
{
    FunctionalDeclaration *result= fctDeclList;
    fctDeclList= tailFctDecl= NULL;
    return result;
}


Parameter *ObjcTranslator::flushParamList(void)
{
   Parameter *result;

    if (nbrParamList > 0) {
	nbrParamList--;
	result= parameterList[nbrParamList];
	parameterList[nbrParamList]= tailParam[nbrParamList]= NULL;
    }
    else {
	cout << "ERRMSG: ObjcTranslator::flushStructList doit faire un flush alors qu'il n'y a pas de liste en cours.\n";
	result= NULL;
    }
    return result;
}


Slot *ObjcTranslator::flushSlotList(void)
{
    Slot *result= slotList;
    slotList= tailSlot= NULL;
    return result;
}


void ObjcTranslator::writeAsJava(void)
{
    OAbstractType *tmpType;
    char outName[256], *lastSlash;

    tmpType= abstractTypeList;

    while (tmpType != NULL) {
	tmpType->getJavaName(outName);
	if ((lastSlash= rindex(outName, '/')) == NULL) {
	    lastSlash= outName;
	}
	else lastSlash++;
	if ((lastSlash[0] == 'N') && (lastSlash[1]= 'S')) lastSlash[0]= 'O';
	strcat(outName, ".java");
	if ((currentOutFile= new ofstream(outName)) != NULL) {
	    writeHeader(tmpType);
	    tmpType->spitJavaCode(this);
	    writeFooter(tmpType);
	    currentOutFile->close();
	    delete currentOutFile;
	}
	else {
	    cout << "ERRMSG: Can't open output file " << outName << ".java.\n";
	}
	tmpType= tmpType->getNext();
    }

}


void ObjcTranslator::writeHeader(OAbstractType *aType)
{
    char tmpBuffer[1024];
    time_t now;

    time(&now);
    *currentOutFile << "/* Obj-C to Java:\n";
    aType->getKindName(tmpBuffer); 
    *currentOutFile << "* " << tmpBuffer << ": ";
    aType->getObjCName(tmpBuffer); 
    *currentOutFile << tmpBuffer << ".\n";
    *currentOutFile << "* Source File: " << inputFileName << ".\n";
    *currentOutFile << "* Module: OpenStep : AppKit.\n";
    *currentOutFile << "* Time stamp: ";
    strcpy(tmpBuffer, ctime(&now));
    tmpBuffer[strlen(tmpBuffer)-1]= '.';
    *currentOutFile << tmpBuffer << "\n";
    *currentOutFile << "*/\n\n";
    *currentOutFile << "package openstep.foundation;\n\n";
    *currentOutFile << "import openstep.foundation.*;\n";
    *currentOutFile << "import openstep.appkit.*;\n\n";
}


void ObjcTranslator::writeFooter(OAbstractType *aType)
{
    *currentOutFile << "\n\n";
}


ofstream *ObjcTranslator::getCurrentOutput(void)
{
    return currentOutFile;
}


boolean ObjcTranslator::addMacro(CompiloMacro *aMacro)
{
    aMacro->next= macros;
    macros= aMacro;
}


void ObjcTranslator::setParseMode(ParseMode aMode)
{
    parseMode= aMode;
}


CompiloMacro *ObjcTranslator::getMacro(char *aName)
{
    CompiloMacro *tmpMacro= macros;

    while (tmpMacro != NULL) {
	if (tmpMacro->getName()->isEqual(aName)) break;
	tmpMacro= tmpMacro->next;
    }

    return tmpMacro;
}


void ObjcTranslator::pushConditionalSegment(ConditionalSegment *aSegment, char *symbolName)
{
    aSegment->next= conditionalSection;
    conditionalSection= aSegment;
    aSegment->symbolExists= (getMacro(symbolName) != NULL);
}


void ObjcTranslator::pushConditionalSegment(ConditionalSegment *aSegment)
{
    aSegment->next= conditionalSection;
    conditionalSection= aSegment;
}


ConditionalSegment *ObjcTranslator::popCondSegment(void)
{
    ConditionalSegment *result= conditionalSection;
    if (result != NULL) {
	conditionalSection= result->next;
    }
    return result;
}


void ObjcTranslator::deleteMacro(CompiloMacro *aMacro)
{
    CompiloMacro *tmpMacro= macros, *lastMacro;

    lastMacro= tmpMacro;
    while (tmpMacro != NULL) {
	if (tmpMacro == aMacro) break;
	lastMacro= tmpMacro;
	tmpMacro= tmpMacro->next;
    }
    if (tmpMacro != NULL) {
	if (tmpMacro == macros) {
	    macros= tmpMacro->next;
	}
	else {
	    lastMacro->next= tmpMacro->next;
	}
	delete tmpMacro;
    }
}


