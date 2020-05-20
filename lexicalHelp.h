#ifndef _LEXICALHELP_H_
#define _LEXICALHELP_H_
/**************************************************
* File: lexicalHelp.h.
* Desc: Support pour l'analyse lexicale
* Module: AkraLog : TradObjc.
* Rev: 12 juin 1997 : REV 0 : Hugo DesRosiers : Creation.
**************************************************/

#ifndef EOF_CHAR
#define EOF_CHAR	-1
#endif

#ifndef FALSE
#define FALSE	(0L)
#endif

#ifndef TRUE
#define TRUE	(1L)
#endif



#define MKW_DEFINE		1
#define MKW_ELSE		2
#define MKW_ELIF		3
#define MKW_ENDIF		4
#define MKW_IF			5
#define MKW_IFDEF		6
#define MKW_IFNDEF		7
#define MKW_INCLUDE	8
#define MKW_UNDEF		9
#define MKW_IMPORT		10


#define MAX_FILEPATH_LEN	1024

#endif		/* _LEXICALHELP_H_ */
