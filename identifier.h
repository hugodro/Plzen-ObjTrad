#ifndef _IDENTIFIER_H_
#define _IDENTIFIER_H_
/**************************************************
* File: identifier.h.
* Desc: Definition of the Identifier class.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>


class Identifier : public AkObject {
  protected:
    Identifier *next;
    unsigned int valueLength;
    char *value;

  public:
    Identifier(char *aString);
    virtual void setNext(Identifier *theNext);
    virtual unsigned int writeAsciiValue(char *aBuffer);
    virtual char *getAsciiValue(void);
    virtual boolean isEqual(char *aValue);
    virtual Identifier *getNext(void);
};


#endif		/* _IDENTIFIER_H_ */
