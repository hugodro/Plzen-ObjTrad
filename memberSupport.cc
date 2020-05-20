/**************************************************
* File: memberSupport.cc.
* Desc: Definition of the Member support classes.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/portableDefs.h>
#include "typing.h"
#include "identifier.h"
#include "memberSupport.h"


/**************************************************
* Implementation: FunctionalParam.
**************************************************/

FunctionalParam::FunctionalParam(OType *aType, Identifier *aName)
{
    next= NULL;
    valueType= aType;
    name= aName;
}


void FunctionalParam::setNext(FunctionalParam *theNext)
{
    next= theNext;
}


FunctionalParam *FunctionalParam::getNext(void)
{
    return next;
}


unsigned int FunctionalParam::writeName(char *aBuffer)
{
    return name->writeAsciiValue(aBuffer);
}


OType *FunctionalParam::getParamType(void)
{
    return valueType;
}


/**************************************************
* Implementation: Slot.
**************************************************/

Slot::Slot(Identifier *aName)
    : FunctionalParam(PrimitiveType::getBuiltIn(PrimitiveType::tVoid), NULL)
{
    slotName= aName;
    specificity= voidSlot;
}


Slot::Slot(OType *aType, Identifier *paramName)
    : FunctionalParam(aType, paramName)
{
    slotName= NULL;
    specificity= anonymSlot;
}


Slot::Slot(Identifier *aName, OType *aType, Identifier *paramName)
    : FunctionalParam(aType, paramName)
{
    slotName= aName;
    specificity= fullSlot;
}


Slot::Kind Slot::getKind(void)
{
    return specificity;
}


unsigned int Slot::writeSlotName(char *aBuffer)
{
    return slotName->writeAsciiValue(aBuffer);
}


/**************************************************
* Implementation: EllipsisSlot.
**************************************************/

EllipsisSlot::EllipsisSlot(void)
    : Slot(NULL)
{
    slotName= NULL;
    specificity= ellipsis;
}


/**************************************************
* Implementation: ParameterSlot.
**************************************************/

ParameterSlot::ParameterSlot(Parameter *someParameters)
    : Slot(NULL)
{
    parameters= someParameters;
    specificity= parametered;
}


/**************************************************
* Implementation: Parameter.
**************************************************/

Parameter::Parameter(OType *aType)
    : FunctionalParam(aType, NULL)
{
// ATTN: Anything to do ?
}


Parameter::Parameter(OType *aType, Identifier *paramName)
    : FunctionalParam(aType, paramName)
{
// ATTN: Anything to do ?
}

