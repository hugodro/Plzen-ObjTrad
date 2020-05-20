#ifndef _TRANSLATOR_H_
#define _TRANSLATOR_H_
/**************************************************
* File: translator.h.
* Desc: Definition of the ObjcTranslator class.
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <akra/AkObject.h>
#include <akra/portableDefs.h>


class OAbstractType;
class Identifier;
class VariableDeclaration;
class FunctionalDeclaration;
class Slot;
class Parameter;
class ofstream;
class CompiloMacro;
class ConditionalSegment;


class ObjcTranslator : public AkObject {
  public:
    enum ParseMode {
	pmMacro, pmSource, pmCondIfDef, pmCondIfNDef,
	pmCondIf, pmCondElse, pmCondElif
    };

  private:		// Class variables.
    static ObjcTranslator *publicCompiler;

  public:		// Class methods.
    static ObjcTranslator *getCurrentCompiler(void);

  protected:
    OAbstractType *abstractTypeList, *tailAbstractType;
    Identifier *classNotifications;
    CompiloMacro *macros;
    char *inputFileName;
    ofstream *currentOutFile;
    ParseMode parseMode;
    ConditionalSegment *conditionalSection;

	// Running lists;
    Identifier *identifierList, *tailIdent;
    unsigned int nbrDeclList;
    VariableDeclaration *varDeclList[256], *tailVarDecl[256];
    FunctionalDeclaration *fctDeclList, *tailFctDecl;
    Slot *slotList, *tailSlot;
    unsigned int nbrParamList;
    Parameter *parameterList[256], *tailParam[256];

  public:
    ObjcTranslator(void);
    virtual boolean boot(int argc, char **argv);
    virtual int parseFile(char *aFile);

    virtual void startStructList(VariableDeclaration *aVarDecl);
    virtual void startParamList(Parameter *aParam);

    virtual void linkExternalDecl(OAbstractType *aMetaType);
    virtual void linkIdentifier(Identifier *anIdent);
    virtual void linkStructDecl(VariableDeclaration *aVarDecl);
    virtual void linkDeclaration(FunctionalDeclaration *aFctDecl);
    virtual void linkSlotDecl(Slot *aSlot);
    virtual void linkParameter(Parameter *aParam);
    virtual void addClassNotification(Identifier *someClasses);

    virtual Identifier *flushIdentList(void);
    virtual VariableDeclaration *flushStructList(void);
    virtual FunctionalDeclaration *flushDeclarationList(void);
    virtual Parameter *flushParamList(void);
    virtual Slot *flushSlotList(void);

    virtual void writeAsJava(void);
    virtual void writeHeader(OAbstractType *aType);
    virtual void writeFooter(OAbstractType *aType);
    virtual ofstream *getCurrentOutput(void);
    virtual boolean addMacro(CompiloMacro *aMacro);
    virtual void setParseMode(ParseMode aMode);
    virtual CompiloMacro *getMacro(char *aName);
    virtual void pushConditionalSegment(ConditionalSegment *aSegment, char *symbolName);
    virtual void pushConditionalSegment(ConditionalSegment *aSegment);
    virtual ConditionalSegment *popCondSegment(void);
    virtual void deleteMacro(CompiloMacro *aMacro);
};

#endif		/* _TRANSLATOR_H_ */
