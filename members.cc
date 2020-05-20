/**************************************************
* File: members.cc.
* Desc: Definition of the Member hierarchy of classes.
* Module: AkraLog : TradObjc.
* Rev: 16 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <stdio.h>
#include <akra/portableDefs.h>
#include "typing.h"
#include "identifier.h"
#include "memberSupport.h"
#include "members.h"


/**************************************************
* Implementation: MemberDeclaration.
**************************************************/

MemberDeclaration::MemberDeclaration(OType *aType)
{
    next= NULL;
    returnType= aType;
}

MemberDeclaration *MemberDeclaration::getNext(void)
{
    return next;
}


void MemberDeclaration::setNext(MemberDeclaration *theNext)
{
    next= theNext;
}


void MemberDeclaration::setReturnType(OType *aType)
{
    returnType= aType;
}


/**************************************************
* Implementation: VariableDeclaration.
**************************************************/

VariableDeclaration::VariableDeclaration(unsigned int aDepth, Identifier *aName, VariableModificator *aVectorInfo)
    : MemberDeclaration(NULL)
{
    pointerDepth= aDepth;
    name= aName;
    vectorialInfo= aVectorInfo;
    protection= pProtected;
}


void VariableDeclaration::setProtection(Protection aProtection)
{
    protection= aProtection;
}


void VariableDeclaration::writeAsJava(char *aBuffer)
{
    unsigned int tmpLength;

    if (returnType->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tVoid))) {
	    // ATTN: Should check to make sure that there are pointers.
	strcpy(aBuffer, "Object");
	tmpLength= 6;
	aBuffer[tmpLength++]=' ';
	tmpLength+= name->writeAsciiValue(&aBuffer[tmpLength]);
    }
    else {
	tmpLength= returnType->writeAsJava(aBuffer);
    
	aBuffer[tmpLength++]=' ';
	tmpLength+= name->writeAsciiValue(&aBuffer[tmpLength]);
    
	if (vectorialInfo != NULL) {
	    if (vectorialInfo->getSubType() == VariableModificator::vmArray) {
		unsigned int i;
    
		tmpLength= strlen(aBuffer);
		for (i= 0; i < vectorialInfo->getLength(); i++) {
		    // TODO: Ajoute les dims.
		}
		for (i= 0; i < vectorialInfo->getLength(); i++) {
		    // TODO: Ajoute le new d'un array equivalent.
		}
	    }
	}
    
	if (pointerDepth > 1) {
	    // TODO: Ajoute des commentaires.
	}
    }
}


/**************************************************
* Implementation: FunctionalDeclaration.
**************************************************/

FunctionalDeclaration::FunctionalDeclaration(Kind aKind, OType *aType)
    : MemberDeclaration(aType)
{
    kind= aKind;
}


/**************************************************
* Implementation: MethodDeclaration.
**************************************************/

MethodDeclaration::MethodDeclaration(Kind aKind, OType *aType, Slot *someSlots)
    : FunctionalDeclaration(aKind, aType)
{
    slots= someSlots;
}


void MethodDeclaration::writeAsJava(char *aBuffer)
{
    unsigned int length;

    if (kind == kClassMethod) {
	strcpy(aBuffer, "static ");
	length= 7;
    }
    else {
	length= 0;
    }

    length+= returnType->writeAsJava(&aBuffer[length]);
    aBuffer[length++]= ' ';

    if (slots->getKind() == Slot::voidSlot) {
	length+= slots->writeSlotName(&aBuffer[length]);
	aBuffer[length++]= '(';
    }
    else {
	Slot *tmpSlot= slots;
	OType *slotType;
	unsigned int argCount;

	    // Fabrique le nom de la fonction.
	argCount= 0;
	do {
	    argCount++;
	    if (tmpSlot->getKind() == Slot::fullSlot) {
		if (argCount > 1) aBuffer[length++]= '_';
		length+= tmpSlot->writeSlotName(&aBuffer[length]);
	    }
	    tmpSlot= (Slot *)tmpSlot->getNext();
	} while (tmpSlot != NULL);

	aBuffer[length++]= '(';

	argCount= 0;
	tmpSlot= slots;
	    // Fabrique les parametres de la fonction.
	do {
	    argCount++;
	    if (argCount > 1) {
		aBuffer[length++]= ',';
		aBuffer[length++]= ' ';
	    }

	    if (tmpSlot->getKind() != Slot::ellipsis) {
		slotType= tmpSlot->getParamType();
		length+= slotType->writeAsJava(&aBuffer[length]);
		aBuffer[length++]= ' ';
		if (tmpSlot->getKind() == Slot::anonymSlot) {
		    strcpy(&aBuffer[length], "arg");
		    sprintf(&aBuffer[length+3], "%d", argCount);
		    length+= 3+ ((argCount < 10) ? 1 :
					    (argCount < 100) ? 2 : 3);
		}
		else {
		    length+= tmpSlot->writeName(&aBuffer[length]);
		}
	    }
	    else {
		strcpy(&aBuffer[length], "Object[] ellipsis");
		length+= 17;
	    }
	    tmpSlot= (Slot *)tmpSlot->getNext();
	} while (tmpSlot != NULL);
    }

    strcpy(&aBuffer[length], ")\n    {\n");
    length+= 8;
    switch(returnType->getMetaKind()) {
	case OType::kPrimitive:
	    if (((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tId))) {
		strcpy(&aBuffer[length], "\treturn null;\n");
		length+= 14;
	    }
	    else if (((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tChar))) {
		strcpy(&aBuffer[length], "\treturn '\0';\n");
		length+= 13;
	    }
	    else if ((((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tShort)))
	    		|| (((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tInt)))
			|| (((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tLong)))) {
		strcpy(&aBuffer[length], "\treturn 0;\n");
		length+= 11;
	    }
	    else if ((((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tFloat)))
	    		|| (((PrimitiveType *)returnType)->isEqual(PrimitiveType::getBuiltIn(PrimitiveType::tDouble)))) {
		strcpy(&aBuffer[length], "\treturn 0.0;\n");
		length+= 13;
	    }
	    break;
	case OType::kUser:
	    char typeName[80];
	    ((UserType *)returnType)->writeAsJava(typeName);
	    if (strcmp(typeName, "boolean") == 0) {
		strcpy(&aBuffer[length], "\treturn false;\n");
		length+= 15;
	    }
	    else {
		strcpy(&aBuffer[length], "\treturn null;\n");
		length+= 14;
	    }
	    break;
	default:
	    strcpy(&aBuffer[length], "\treturn null;\n");
	    length+= 14;
	    break;
    }
    strcpy(&aBuffer[length], "    }");
}


/**************************************************
* Implementation: FunctionDeclaration.
**************************************************/

FunctionDeclaration::FunctionDeclaration(OType *aType, Identifier *aName, Parameter *someParams)
    : FunctionalDeclaration(FunctionalDeclaration::kDynFunction, aType)
{
    name= aName;
    parameters= someParams;
}


void FunctionDeclaration::writeAsJava(char *aBuffer)
{
// TODO.
// TMP:
    strcpy(aBuffer, "<fct-decl>");
}
