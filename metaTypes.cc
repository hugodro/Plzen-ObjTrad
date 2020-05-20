/**************************************************
* File: metaTypes.cc.
* Desc: Implementation of the OAbstractType hiearchy class.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include "identifier.h"
#include "translator.h"
#include "members.h"
#include "typing.h"
#include "metaTypes.h"


/**************************************************
* Implementation: OAbstractType.
**************************************************/

OAbstractType::OAbstractType(Identifier *aName, Identifier *someIdents, FunctionalDeclaration *someDecls)
{
    next= NULL;
    name= aName;
    protocolRefs= someIdents;
    interface= someDecls;
}


void OAbstractType::setNext(OAbstractType *theNext)
{
    next= theNext;
}


OAbstractType *OAbstractType::getNext(void)
{
    return next;
}


void OAbstractType::getJavaName(char *aBuffer)
{
    name->writeAsciiValue(aBuffer);
}


void OAbstractType::getObjCName(char *aBuffer)
{
    name->writeAsciiValue(aBuffer);
}


/**************************************************
* Implementation: OClass.
**************************************************/

OClass:: OClass(Identifier *aName, Identifier *supName, Identifier *someIdents, VariableDeclaration *someVars, FunctionalDeclaration *someDecls)
    : OAbstractType(aName, someIdents, someDecls)
{
    superName= supName;
    instanceVariables= someVars;
}


void OClass::getKindName(char *aBuffer)
{
    strcpy(aBuffer, "Class");
}


void OClass::spitJavaCode(ObjcTranslator *context)
{
    ofstream *outFile;
    char tmpBuffer[1024];

    outFile= context->getCurrentOutput();

	// writeDeclarator:
    *outFile << "public class ";
    name->writeAsciiValue(tmpBuffer);
    UserType::translateToJava(tmpBuffer);
    *outFile << tmpBuffer << " extends ";
    superName->writeAsciiValue(tmpBuffer);
    UserType::translateToJava(tmpBuffer);
    *outFile << tmpBuffer;

    if (protocolRefs != NULL) {
	boolean moreThanOne= false;

	*outFile << " implements ";
	do {
	    Identifier *tmpIdent= protocolRefs;
	    if (moreThanOne) {
		*outFile << ", ";
	    }
	    else {
		moreThanOne= true;
	    }
	    tmpIdent->writeAsciiValue(tmpBuffer);
	    UserType::translateToJava(tmpBuffer);
	    *outFile << tmpBuffer;
	    protocolRefs= protocolRefs->getNext();
	} while (protocolRefs != NULL);
    }
    *outFile << " {\n";

	// writeBody:
    if (instanceVariables != NULL) {
	VariableDeclaration *tmpVar= instanceVariables;

	*outFile << "\t// Instance Variables.\n";
	do {
	    tmpVar->writeAsJava(tmpBuffer);
	    *outFile << "    " << tmpBuffer << ";\n";
	    tmpVar= (VariableDeclaration *)tmpVar->getNext();
	} while (tmpVar != NULL);
	*outFile << "\n";
    }

    if (interface != NULL) {
	FunctionalDeclaration *tmpFct= interface;

	*outFile << "\t// Methods.\n";
	do {
	    tmpFct->writeAsJava(tmpBuffer);
	    *outFile << "    " << tmpBuffer << "\n\n";
	    tmpFct= (FunctionalDeclaration *)tmpFct->getNext();
	} while (tmpFct != NULL);
    }

	// writeClosing:
    *outFile << "\n}\n";
}


/**************************************************
* Implementation: OCategory.
**************************************************/

OCategory::OCategory(Identifier *aName, Identifier *catName, Identifier *someIdents, FunctionalDeclaration *someDecls)
    : OAbstractType(aName, someIdents, someDecls)
{
    categoryName= catName;
}


void OCategory::getKindName(char *aBuffer)
{
    strcpy(aBuffer, "Category");
}


void OCategory::spitJavaCode(ObjcTranslator *context)
{
    ofstream *outFile;
    char tmpBuffer[1024];

    outFile= context->getCurrentOutput();

	// writeDeclarator:
    *outFile << "public class ";
    name->writeAsciiValue(tmpBuffer);
    UserType::translateToJava(tmpBuffer);
    *outFile << tmpBuffer << " categorizes ";
    categoryName->writeAsciiValue(tmpBuffer);
    UserType::translateToJava(tmpBuffer);
    *outFile << tmpBuffer;

    if (protocolRefs != NULL) {
	Identifier *tmpIdent= protocolRefs;
	boolean moreThanOne= false;

	*outFile << " implements ";
	do {
	    if (moreThanOne) {
		*outFile << ", ";
	    }
	    else {
		moreThanOne= true;
	    }
	    tmpIdent->writeAsciiValue(tmpBuffer);
	    UserType::translateToJava(tmpBuffer);
	    *outFile << tmpBuffer;
	    protocolRefs= protocolRefs->getNext();
	} while (protocolRefs != NULL);
    }
    *outFile << " {\n";


    if (interface != NULL) {
	FunctionalDeclaration *tmpFct= interface;

	*outFile << "\t// Methods.\n";
	do {
	    tmpFct->writeAsJava(tmpBuffer);
	    *outFile << "    " << tmpBuffer << "\n\n";
	    tmpFct= (FunctionalDeclaration *)tmpFct->getNext();
	} while (tmpFct != NULL);
    }

	// writeClosing:
    *outFile << "\n}\n";
}


void OCategory::getJavaName(char *aBuffer)
{
    unsigned int length;

    name->writeAsciiValue(aBuffer);
    length= strlen(aBuffer);
    aBuffer[length++]= '_';
    categoryName->writeAsciiValue(&aBuffer[length]);
}


void OCategory::getObjCName(char *aBuffer)
{
    unsigned int length;

    name->writeAsciiValue(aBuffer);
    length= strlen(aBuffer);
    aBuffer[length]= '(';
    categoryName->writeAsciiValue(&aBuffer[length+1]);
    strcat(&aBuffer[length+1], ")");
}


/**************************************************
* Implementation: OProtocol.
**************************************************/

OProtocol::OProtocol(Identifier *aName, Identifier *someIdents, FunctionalDeclaration *someDecls)
    : OAbstractType(aName, someIdents, someDecls)
{
	// Anything to do ?
}


void OProtocol::getKindName(char *aBuffer)
{
    strcpy(aBuffer, "Protocol");
}


void OProtocol::getJavaName(char *aBuffer)
{
    unsigned int length;

    name->writeAsciiValue(aBuffer);
    length= strlen(aBuffer);
    strcpy(&aBuffer[length], "_Prot");
}


void OProtocol::spitJavaCode(ObjcTranslator *context)
{
    ofstream *outFile;
    char tmpBuffer[1024];

    outFile= context->getCurrentOutput();

	// writeDeclarator:
    *outFile << "public interface ";
    name->writeAsciiValue(tmpBuffer);
    UserType::translateToJava(tmpBuffer);
    *outFile << tmpBuffer;

    if (protocolRefs != NULL) {
	Identifier *tmpIdent= protocolRefs;
	boolean moreThanOne= false;

	*outFile << " extends ";
	do {
	    if (moreThanOne) {
		*outFile << ", ";
	    }
	    else {
		moreThanOne= true;
	    }
	    tmpIdent->writeAsciiValue(tmpBuffer);
	    UserType::translateToJava(tmpBuffer);
	    *outFile << tmpBuffer;
	    protocolRefs= protocolRefs->getNext();
	} while (protocolRefs != NULL);
    }
    *outFile << " {\n";


    if (interface != NULL) {
	FunctionalDeclaration *tmpFct= interface;

	*outFile << "\t// Methods.\n";
	do {
	    tmpFct->writeAsJava(tmpBuffer);
	    *outFile << "    " << tmpBuffer << "\n\n";
	    tmpFct= (FunctionalDeclaration *)tmpFct->getNext();
	} while (tmpFct != NULL);
    }

	// writeClosing:
    *outFile << "\n}\n";
}


