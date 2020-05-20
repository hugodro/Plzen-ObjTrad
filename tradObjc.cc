/**************************************************
* File: tradObjc.cc.
* Desc: Module principal du traducteur de Objc a Java.
* Module: AkraLog : JavaKit.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#include <iostream.h>
#include "translator.h"

extern "C" {
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
}

/* Prototypes of external functions used in this module. */


extern int yydebug;
extern "C" {
/* MOD-MSC: Extrait les definitions precedentes. */
extern FILE *yyin;
}


void describe(int, char **);


static int majorVersion= 0;
static int minorVersion= 0;


/* The Code. */


ObjcTranslator *compiler= NULL;


main(int argc, char **argv)
{
    char sourceFileName[255];

    yydebug= 0;
    yyin= stdin;

    if (argc >1 ) {
	strcpy(sourceFileName, argv[argc-1]);
	if (argc > 2) {
	    yydebug= atoi(argv[argc-2]);
	    if ((yydebug != 0) && (yydebug != 1)) yydebug= 0;
	 }
     }
    else {
	describe(argc, argv);
	exit(0);
     }

    compiler= new ObjcTranslator();
    if (compiler->boot(argc, argv)) {
	compiler->parseFile(sourceFileName);
    }
}


void describe(int argc, char **argv)
{
    cout  << "AkraLog's ObjC translator, version " << majorVersion << "." << minorVersion << ".\n";

    cout  << "Usage: <options> <class-file>.\n";
    cout << "Options: none.\n";

}

