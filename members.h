#ifndef _MEMBERS_H_
#define _MEMBERS_H_
/**************************************************
* File: members.h.
* Desc: Definition of the Member hierarchy of classes.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>


class OType;
class Identifier;
class ArrayDeclarator;
class Slot;
class Parameter;
class VariableModificator;

class MemberDeclaration : public AkObject {
  protected:
    MemberDeclaration *next;
    OType *returnType;
    unsigned int pointerDepth;
    VariableModificator *vectorialInfo;

  public:
    MemberDeclaration(OType *aType);
    MemberDeclaration *getNext(void);
    virtual void setNext(MemberDeclaration *theNext); 
    virtual void setReturnType(OType *aType);
    virtual void writeAsJava(char *aBufffer)= 0;
};


class VariableDeclaration : public MemberDeclaration {
  public:
    enum Protection {
	pPublic, pProtected, pPrivate
    };

  protected:
    Identifier *name;
    Protection protection;

  public:
    VariableDeclaration(unsigned int aDepth, Identifier *aName, VariableModificator *aVectorInfo);
    virtual void setProtection(Protection aProtection);
    virtual void writeAsJava(char *aBufffer);
};


class FunctionalDeclaration : public MemberDeclaration {
  public:
    enum Kind {
	kClassMethod, kInstanceMethod, kDynFunction, kStaticFunction
    };

  protected:
    Kind kind;

  public:
    FunctionalDeclaration(Kind aKind, OType *aType);
};


class MethodDeclaration : public FunctionalDeclaration {
  protected:
    Slot *slots;

  public:
    MethodDeclaration(Kind aKind, OType *aType, Slot *someSlots);
    virtual void writeAsJava(char *aBufffer);
};


class FunctionDeclaration : public FunctionalDeclaration {
  protected:
    Identifier *name;
    Parameter *parameters;

  public:
    FunctionDeclaration(OType *aType, Identifier *aName, Parameter *someParams);
    virtual void writeAsJava(char *aBufffer);
};


#endif		/* _MEMBERS_H_ */
