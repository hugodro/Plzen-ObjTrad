#ifndef _PRECOMPILING_H_
#define _PRECOMPILING_H_
/**************************************************
* File: preCompiling.h.
* Desc: Definitions des classes qui supportent les directives de pre-compilation.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>

class Identifier;
class MacroArgument;
class MacroValue;
class MacroSegment;

class CompiloMacro : public AkObject {
  public:
    enum Constants {
	maxNameLength= 128,
	maxBufferLength=  512
    };

  public:
    CompiloMacro *next;
    Identifier *name;
    unsigned int nbrArguments;
    MacroArgument *arguments;
    MacroValue *value;
    boolean isPrioritary;		// Indicates if this macro is more important than other with the same name following.


  public:
    CompiloMacro(char *aName);	// Define a new macro, with its name.
    virtual ~CompiloMacro(void);
    virtual void setPriority(boolean aValue);
    virtual unsigned int argCount();		// Gives the number of arguments for the macro.
    virtual MacroArgument *getArgument(char *aName);
    virtual void setValue(MacroValue *aValue);
    virtual Identifier *getName(void);
    
};


class MacroValue : public AkObject {
  public:
    enum ReadingMode {
	readValue, concatenate,
	readString
    };
    enum Kind {
	kConstant, kFunction
    };

  protected:
    MacroSegment *segments, *tailSegment;
    Kind kind;

  public:
    MacroValue(void);
    void addSegment(MacroSegment *aSegment);
};


class MacroArgument : public AkObject {
  public:
    MacroArgument *next, *prev;
    Identifier *name;

  public:
    MacroArgument(char *aName);
    virtual Identifier *getName(void);
};


class MacroSegment : public AkObject {
  public:
    MacroSegment *next;

  public:
    MacroSegment(void);
};


class SegmentVariable : public MacroSegment {
  protected:
    MacroArgument *value;

  public:
    SegmentVariable(MacroArgument *aValue);
};


class SegmentMacro : public MacroSegment {
  protected:
    CompiloMacro *value;

  public:
    SegmentMacro(CompiloMacro *aValue);
};


class SegmentString : public MacroSegment {
  protected:
    unsigned int length;
    char *value;

  public:
    SegmentString(char *aValue, unsigned int aLength);
};


class ConditionalSegment : public AkObject {
  public:
    enum Kind {
	tIfdef, tIfndef, tElse, tIf, tElif
    };

  public:
    ConditionalSegment *next;
    Kind kind;
    boolean symbolExists;

  public:
    ConditionalSegment(Kind aKind);
    virtual boolean testResult(void);
    virtual Kind getKind(void);
    virtual void setKind(Kind aKind);
};



#endif		/* _PRECOMPILING_H_ */
