#ifndef _MEMBERSUPPORT_H_
#define _MEMBERSUPPORT_H_
/**************************************************
* File: memberSupport.h.
* Desc: Definition of the Member support classes.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>

class Identifier;
class OType;
class Parameter;


class FunctionalParam : public AkObject {
  protected:
    FunctionalParam *next;
    OType *valueType;
    Identifier *name;

  public:
    FunctionalParam(OType *aType, Identifier *aName);
    virtual void setNext(FunctionalParam *theNext);
    virtual FunctionalParam *getNext(void);
    virtual unsigned int writeName(char *aBuffer);
    virtual OType *getParamType(void);
};


class Slot : public FunctionalParam {
  public:
    enum Kind {
	voidSlot, anonymSlot, fullSlot,
	ellipsis, parametered
    };

  protected:
    Identifier *slotName;
    Kind specificity;

  public:
    Slot(Identifier *aName);
    Slot(OType *aType, Identifier *paramName);
    Slot(Identifier *aName, OType *aType, Identifier *paramName);
    virtual Kind getKind(void);
    virtual unsigned int writeSlotName(char *aBuffer);
};


class EllipsisSlot : public Slot {
  protected:
  public:
    EllipsisSlot(void);
};


class ParameterSlot : public Slot {
  protected:
    Parameter *parameters;

  public:
    ParameterSlot(Parameter *someParameters);
};


class Parameter : public FunctionalParam {
  protected:
  public:
    Parameter(OType *aType);
    Parameter(OType *aType, Identifier *paramName);
};


#endif		/* _MEMBERSUPPORT_H_ */
