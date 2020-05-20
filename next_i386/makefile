#/************************************************
#* File: makefile.
#* Desc: Building definitions for the Obj-C translator.
#************************************************/

TARGET_SYSTEM= next_i386

VPATH= ..
AKRAHOME= /Users/hugo/AkraLog/Projets
JAVAHOME= $(AKRAHOME)/Plzen
COMP_OBJ= $(JAVAHOME)/Compiler/$(TARGET_SYSTEM)


EXTERNOBJS= $(COMP_OBJ)/sourceFile.o


SRCS=  gramObjc.cc gramObjc.ycc  objcTokens.c objcTokens.l \
	lexicalHelp.cc \
	metaTypes.cc memberSupport.cc identifier.cc \
	typing.cc members.cc preCompiling.cc \
	translator.cc tradObjc.cc

OBJS= gramObjc.o objcTokens.o \
	lexicalHelp.o \
	metaTypes.o memberSupport.o identifier.o \
	typing.o members.o preCompiling.o \
	translator.o tradObjc.o \
	$(EXTERNOBJS)

INC= -I$(AKRAHOME) -I$(AKRAHOME)/Plzen


CC= cc
CFLAGS= -g
YACC= bison
YACCFLAGS= -dyv
LEX= flex
LEXFLAGS=
LIBS= -lg++

.SUFFIXES: .cc
all: tobjc

tobjc: $(OBJS)
	$(CC)  $(CFLAGS) -o $@ $(OBJS) $(LIBS)


.c.o:
	$(CC) $(INC) $(CFLAGS) -c  $<

.cc.o:
	$(CC) $(INC) $(CFLAGS) -c  $<


gramObjc.cc: gramObjc.ycc
	$(YACC) $(YACCFLAGS) gramObjc.ycc
	mv y.tab.c $(VPATH)/gramObjc.cc
	mv y.tab.h $(VPATH)

objcTokens.c: objcTokens.l
	$(LEX) $(LEXFLAGS) objcTokens.l
	mv lex.yy.c $(VPATH)/objcTokens.c
