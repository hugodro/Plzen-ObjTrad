/**************************************************
* File: identifier.cc.
* Desc: Definition of the Identifier class.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <string.h>
#include "identifier.h"


/**************************************************
* Implementation: Identifier.
**************************************************/

Identifier::Identifier(char *aString)
{
    unsigned int tmpLength;

    next= NULL;
    valueLength= strlen(aString);
    value= new char[valueLength+1];
    memcpy(value, aString, sizeof(char) * (valueLength + 1));
}


void Identifier::setNext(Identifier *theNext)
{
    next= theNext;
}


unsigned int Identifier::writeAsciiValue(char *aBuffer)
{
    strcpy(aBuffer, value);
    return valueLength;
}


char *Identifier::getAsciiValue(void)
{
    return value;
}


boolean Identifier::isEqual(char *aValue)
{
    return (strcmp(aValue, value) == 0);
}


Identifier *Identifier::getNext(void)
{
    return next;
}

