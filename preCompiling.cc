/**************************************************
* File: preCompiling.cc.
* Desc: Implantations des classes qui supportent les directives de pre-compilation.
* Module: AkraLog : TradObjc.
* Rev: 16 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/portableDefs.h>
#include "identifier.h"
#include "preCompiling.h"


/**************************************************
* Implementation: CompiloMacro.
**************************************************/

CompiloMacro::CompiloMacro(char *aName)
{
    next= NULL;
    name= new Identifier(aName);
    nbrArguments= 0;
    arguments= NULL;
    value= NULL;
    isPrioritary= false;
}


CompiloMacro::~CompiloMacro(void)
{
    MacroArgument *tmpArg;
    delete name;
    while (arguments != NULL) {
	tmpArg= arguments->next;
	delete arguments;
	arguments= tmpArg;
    }
    delete value;
}


void CompiloMacro::setPriority(boolean aValue)
{
    isPrioritary= aValue;
}


unsigned int CompiloMacro::argCount()
{
    return nbrArguments;
}


MacroArgument *CompiloMacro::getArgument(char *aName)
{
    MacroArgument *tmpArg= arguments;

    while (tmpArg != NULL) {
	if (tmpArg->getName()->isEqual(aName)) break;
	tmpArg= tmpArg->next;
    }

    return tmpArg;
}


void CompiloMacro::setValue(MacroValue *aValue)
{
    value= aValue;
}


Identifier *CompiloMacro::getName(void)
{
    return name;
}


/**************************************************
* Implementation: MacroValue.
**************************************************/

MacroValue::MacroValue(void)
{
    segments= tailSegment= NULL;
    kind= kConstant;
}


void MacroValue::addSegment(MacroSegment *aSegment)
{
    if (segments == NULL) {
	segments= aSegment;
    }
    else {
	tailSegment->next= aSegment;
    }

    tailSegment= aSegment;
}


/**************************************************
* Implementation: MacroArgument.
**************************************************/

MacroArgument::MacroArgument(char *aName)
{
    name= new Identifier(aName);
}


Identifier *MacroArgument::getName(void)
{
    return name;
}


/**************************************************
* Implementation: MacroSegment.
**************************************************/

MacroSegment::MacroSegment(void)
{
    next= NULL;
}


/**************************************************
* Implementation: SegmentVariable.
**************************************************/

SegmentVariable::SegmentVariable(MacroArgument *aValue)
    : MacroSegment()
{
    value= aValue;
}


/**************************************************
* Implementation: SegmentMacro.
**************************************************/

SegmentMacro::SegmentMacro(CompiloMacro *aValue)
    : MacroSegment()
{
    value= aValue;
}


/**************************************************
* Implementation: SegmentString.
**************************************************/

SegmentString::SegmentString(char *aValue, unsigned int aLength)
{
    length= aLength;
    if (length > 0) {
	value= new char[aLength];
	memcpy(value, aValue, length);
    }
    else value= NULL;
}


/**************************************************
* Implementation: ConditionalSegment.
**************************************************/

ConditionalSegment::ConditionalSegment(ConditionalSegment::Kind aKind)
{
    kind= aKind;
    symbolExists= false;
}


boolean ConditionalSegment::testResult(void)
{
    if (kind == tIfdef) return symbolExists;
    else if (kind == tIfndef) return !symbolExists;
    else return symbolExists;		// ATTN: To correct.
}


ConditionalSegment::Kind ConditionalSegment::getKind(void)
{
    return kind;
}


void ConditionalSegment::setKind(ConditionalSegment::Kind aKind)
{
    if (aKind == tElse) {
	symbolExists= !symbolExists;
    }
    kind= aKind;
}


