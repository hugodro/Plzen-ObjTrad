#ifndef _TYPING_H_
#define _TYPING_H_
/**************************************************
* File: typing.h.
* Desc: Definition of the Member hierarchy of classes.
* Module: AkraLog : TradObjc.
* Rev: 13 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>


class Identifier;
class Parameter;
class VariableDeclaration;


class VariableModificator : public AkObject {
  public:
    enum SubType {
	vmArray, vmBitField
    };

  protected:
    unsigned int length;

  public:
    VariableModificator(unsigned int aLength);
    virtual SubType getSubType(void)= 0; 
    virtual unsigned int getLength(void);
};

class ArrayDeclarator : public VariableModificator {
  protected:
    unsigned int sizes[64];

  public:
    ArrayDeclarator(unsigned int aSize);
    virtual void addDimension(unsigned int aSize);
    virtual SubType getSubType(void); 
};


class BitFieldDeclarator : public VariableModificator {
  protected:

  public:
    BitFieldDeclarator(unsigned int aSize);
    virtual SubType getSubType(void); 
};


class OType : public AkObject {
  public:
    enum RunTimeQualifier {
	rtNone, rtConstant, rtVolatile,
	rtIn, rtOut, rtInOut,
	rtByCopy, rtOneWay
    };
    enum Kind {
	kPrimitive, kUser, kFunctional, kStructure
    };

  protected:
    unsigned int pointerDepth;		// Depth of pointing to base type.
    VariableModificator *vectorialInfo;	// Vectorial or bitfield info.
    RunTimeQualifier rtMode;

  public:
    OType(void);
    virtual void setRTQualifier(RunTimeQualifier aQualifier);
    virtual void addPointers(unsigned int aDepth);
    virtual void setVectorInfo(VariableModificator *aVectorInfo);
    virtual unsigned int writeAsJava(char *aBuffer)= 0;
    virtual boolean isEqual(OType *aType);
    virtual Kind getMetaKind()= 0;
};


class PrimitiveType : public OType {
  public:
    enum BuiltIn {
	tVoid, tId, tChar, tShort, tInt, tLong, tFloat, tDouble
	, nbrReferences
    };

  private:
    static PrimitiveType *references[nbrReferences];

  public:
    static PrimitiveType *getBuiltIn(BuiltIn aKnownType);

  protected:
    BuiltIn kind;
    boolean unsignedValue;

  public:
    PrimitiveType(BuiltIn aKnownType);
    virtual void setUnsigned(void);
    virtual unsigned int writeAsJava(char *aBuffer);
    virtual boolean isEqual(OType *aType);
    virtual Kind getMetaKind();
};


class UserType : public OType {
  protected:
    Identifier *name;

  public:
    static boolean translateToJava(char *tmpBuffer);

  public:
    UserType(Identifier *aName);
    virtual unsigned int writeAsJava(char *aBuffer);
    virtual Kind getMetaKind();
};


class FunctionalType : public UserType {
  protected:
    unsigned int fctPtrDepth;
    OType *returnType;
    Parameter *parameterTypes;

  public:
    FunctionalType(OType *aType, unsigned int aSize, Parameter *someParams);
    virtual unsigned int writeAsJava(char *aBuffer);
    virtual Kind getMetaKind();
};


class StructureType : public UserType {
  protected:
    VariableDeclaration *components;

  public:
    StructureType(Identifier *aName);
    StructureType(Identifier *aName, VariableDeclaration *someVarDecls);
    virtual unsigned int writeAsJava(char *aBuffer);
    virtual Kind getMetaKind();
};


#endif	/* _TYPING_H_ */
