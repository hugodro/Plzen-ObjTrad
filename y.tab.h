typedef union
{
	// Builtin types.
    boolean boolValue;
    char *string;
    unsigned int integerNumber;
    unsigned int longNumber[2];
    float floatNumber;
    double doubleNumber;

	// Complex types.
    Identifier *identifier;
    OAbstractType *abstractType;
    VariableDeclaration *varDecl;
    FunctionalDeclaration *interfaceDecl;
    OType *otype;
    Slot *slot;
    VariableModificator *varModif;
    Parameter *parameter;
} YYSTYPE;
#define	LITERAL_CHAR	258
#define	LITERAL_LONG	259
#define	LITERAL_INT	260
#define	LITERAL_FLOAT	261
#define	LITERAL_STRING	262
#define	IDENTIFIER_KW	263
#define	BYCOPY_KW	264
#define	CHAR_KW	265
#define	CLASS_KW	266
#define	CONST_KW	267
#define	DOUBLE_KW	268
#define	ELLIPSIS_KW	269
#define	END_KW	270
#define	FLOAT_KW	271
#define	ID_KW	272
#define	IN_KW	273
#define	INOUT_KW	274
#define	INT_KW	275
#define	INTERFACE_KW	276
#define	LONG_KW	277
#define	ONEWAY_KW	278
#define	OUT_KW	279
#define	PRIVATE_KW	280
#define	PROTOCOL_KW	281
#define	PROTECTED_KW	282
#define	PUBLIC_KW	283
#define	SHORT_KW	284
#define	SIGNED_KW	285
#define	STRUCT_KW	286
#define	UNSIGNED_KW	287
#define	VOID_KW	288
#define	VOLATILE_KW	289


extern YYSTYPE yylval;
