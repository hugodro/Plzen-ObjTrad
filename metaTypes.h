#ifndef _METATYPES_H_
#define _METATYPES_H_
/**************************************************
* File: metaTypes.h.
* Desc: Definition of the OAbstractType hiearchy class.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>


class Identifier;
class FunctionalDeclaration;
class VariableDeclaration;
class ObjcTranslator;


class OAbstractType : public AkObject {
  protected:
    OAbstractType *next;
    Identifier *name;
    Identifier *protocolRefs;
    FunctionalDeclaration *interface;

  public:
    OAbstractType(Identifier *aName, Identifier *someIdents, FunctionalDeclaration *someDecls);
    virtual void setNext(OAbstractType *theNext);
    virtual OAbstractType *getNext(void);

    virtual void getJavaName(char *aBuffer);
    virtual void getObjCName(char *aBuffer);
    virtual void getKindName(char *aBuffer)= 0;

    virtual void spitJavaCode(ObjcTranslator *context)= 0;
};


class OClass : public OAbstractType {
  protected:
    Identifier *superName;
    VariableDeclaration *instanceVariables;

  public:
    OClass(Identifier *aName, Identifier *supName, Identifier *someIdents, VariableDeclaration *someVars, FunctionalDeclaration *someDecls);
    virtual void getKindName(char *aBuffer);
    virtual void spitJavaCode(ObjcTranslator *context);
};


class OCategory : public OAbstractType {
  protected:
    Identifier *categoryName;

  public:
    OCategory(Identifier *aName, Identifier *catName, Identifier *someIdents, FunctionalDeclaration *someDecls);
    virtual void getJavaName(char *aBuffer);
    virtual void getObjCName(char *aBuffer);
    virtual void getKindName(char *aBuffer);
    virtual void spitJavaCode(ObjcTranslator *context);
};


class OProtocol : public OAbstractType {
  protected:

  public:
    OProtocol(Identifier *aName, Identifier *someIdents, FunctionalDeclaration *someDecls);
    virtual void getKindName(char *aBuffer);
    virtual void getJavaName(char *aBuffer);
    virtual void spitJavaCode(ObjcTranslator *context);
};

#endif		/* _METATYPES_H_ */
