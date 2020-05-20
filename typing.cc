/**************************************************
* File: typing.cc.
* Desc: Definition of the OType hierarchy of classes.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include "identifier.h"
#include "typing.h"


/**************************************************
* Implementation: VariableModificator.
**************************************************/

VariableModificator::VariableModificator(unsigned int aLength)
{
    length= aLength;
}


unsigned int VariableModificator::getLength(void)
{
    return length;
}


/**************************************************
* Implementation: ArrayDeclarator.
**************************************************/

ArrayDeclarator::ArrayDeclarator(unsigned int aSize)
    : VariableModificator(1)
{
    sizes[0]= aSize;
}


void ArrayDeclarator::addDimension(unsigned int aSize)
{
    sizes[length]= aSize;
    length++;
}


VariableModificator::SubType ArrayDeclarator::getSubType(void)
{
    return vmArray;
}


/**************************************************
* Implementation: BitFieldDeclarator.
**************************************************/

BitFieldDeclarator:: BitFieldDeclarator(unsigned int aSize)
    : VariableModificator(aSize)
{
// ATTN: Anything to do ?
}


VariableModificator::SubType BitFieldDeclarator::getSubType(void)
{
    return vmBitField;
}


/**************************************************
* Implementation: OType.
**************************************************/

OType::OType(void)
{
    pointerDepth= 0;
    vectorialInfo= NULL;
    rtMode= rtNone;
}


void OType::setRTQualifier(RunTimeQualifier aQualifier)
{
    rtMode= aQualifier;
}


void OType::addPointers(unsigned int aDepth)
{
    pointerDepth+= aDepth;
}


void OType::setVectorInfo(VariableModificator *aVectorInfo)
{
    vectorialInfo= aVectorInfo;
}


boolean OType::isEqual(OType *aType)
{
    return false;
}


/**************************************************
* Implementation: PrimitiveType.
**************************************************/

PrimitiveType *PrimitiveType::references[PrimitiveType::nbrReferences]=
    {
	new PrimitiveType(PrimitiveType::tVoid),
	new PrimitiveType(PrimitiveType::tId),
	new PrimitiveType(PrimitiveType::tChar),
	new PrimitiveType(PrimitiveType::tShort),
	new PrimitiveType(PrimitiveType::tInt),
	new PrimitiveType(PrimitiveType::tLong),
	new PrimitiveType(PrimitiveType::tFloat),
	new PrimitiveType(PrimitiveType::tDouble)
    };


PrimitiveType *PrimitiveType::getBuiltIn(BuiltIn aKnownType)
{
    if (aKnownType < nbrReferences) {
	return references[aKnownType];
    }
    return NULL;
}


PrimitiveType::PrimitiveType(BuiltIn aKnownType)
    : OType()
{
    kind= aKnownType;
    unsignedValue= false;
}


void PrimitiveType::setUnsigned(void)
{
    unsignedValue= true;
}


unsigned int PrimitiveType::writeAsJava(char *aBuffer)
{
    switch(kind) {
	case tVoid:
	    strcpy(aBuffer, "void");
	    return 4;
	case tId:
	    strcpy(aBuffer, "Object");
	    return 6;
	case tChar:
	    strcpy(aBuffer, "char");
	    return 4;
	case tShort:
	    strcpy(aBuffer, "short");
	    return 5;
	case tInt:
	    strcpy(aBuffer, "int");
	    return 3;
	case tLong:
	    strcpy(aBuffer, "long");
	    return 4;
	case tFloat:
	    strcpy(aBuffer, "float");
	    return 5;
	case tDouble:
	    strcpy(aBuffer, "double");
	    return 6;
	default:
	    // TODO: Raise an exception.
	    break;
    }
    return 0;
}

boolean PrimitiveType::isEqual(OType *aType)
{
    if (aType->getMetaKind() == OType::kPrimitive) {
	return (((PrimitiveType *)aType)->kind == kind);
    }
    return false;
}


OType::Kind PrimitiveType::getMetaKind()
{
    return OType::kPrimitive;	
}

/**************************************************
* Implementation: UserType.
**************************************************/

boolean UserType::translateToJava(char *tmpBuffer)
{
    boolean didModif= false;

    if (strcmp(tmpBuffer, "NSObject") == 0) {
	strcpy(tmpBuffer, "OSObject");
	didModif= true;
    }
    else if (strcmp(tmpBuffer, "NSString") == 0) {
	strcpy(tmpBuffer, "String");
	didModif= true;
    }
    else {
	if ((tmpBuffer[0] == 'N') && (tmpBuffer[1] == 'S')) {
	    tmpBuffer[0]= 'O';
	    didModif= true;
	}
    }

    return didModif;
}


UserType::UserType(Identifier *aName)
    : OType()
{
    name= aName;
}


unsigned int UserType::writeAsJava(char *aBuffer)
{
    if (name->isEqual("NSObject")) {
	strcpy(aBuffer, "OSObject");
	return 6;
    }
    else if (name->isEqual("BOOL")) {
	strcpy(aBuffer, "boolean");
	return 7;
    }
    else if (name->isEqual("NSString")) {
	strcpy(aBuffer, "String");
	return 6;
    }
    else if (name->isEqual("SEL")) {
	strcpy(aBuffer, "MethodSelector");
	return 6;
    }
    else {
	unsigned int nameLength;
	nameLength= name->writeAsciiValue(aBuffer);
	if ((aBuffer[0] == 'N') && (aBuffer[1] == 'S')) {
	    aBuffer[0]= 'O';
	}
	return nameLength;
    }
}


OType::Kind UserType::getMetaKind()
{
    return OType::kUser;	
}


/**************************************************
* Implementation: FunctionalType.
**************************************************/

FunctionalType::FunctionalType(OType *aType, unsigned int aSize, Parameter *someParams)
    : UserType(NULL)
{
    fctPtrDepth= aSize;
    returnType= aType;
    parameterTypes= someParams;
}


unsigned int FunctionalType::writeAsJava(char *aBuffer)
{
// TODO.
// TMP:
    strcpy(aBuffer, "<fct-type>");
    return 10;
}


OType::Kind FunctionalType::getMetaKind()
{
    return OType::kFunctional;	
}


/**************************************************
* Implementation: StructureType.
**************************************************/

StructureType::StructureType(Identifier *aName)
    : UserType(aName)
{
    // ATTN: Anything to do ?
}


StructureType::StructureType(Identifier *aName, VariableDeclaration *someVarDecls)
    : UserType(aName)
{
    components= someVarDecls;
}


unsigned int StructureType::writeAsJava(char *aBuffer)
{
    if (name != NULL) return name->writeAsciiValue(aBuffer);
    else {
	strcpy(aBuffer, "NONAME");
	return 6;
    }
}


OType::Kind StructureType::getMetaKind()
{
    return OType::kStructure;	
}


