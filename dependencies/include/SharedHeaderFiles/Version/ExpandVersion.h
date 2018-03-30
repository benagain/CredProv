// Core Product Build Version numbers
// consumed by subordinate projects
// This file is genrally not updated by developers, it is instead updated as part of the pre-build process

#include "..\Copyright.h"

#define FILEVERSION_MAJOR			FILEVERSION_MAJOR_HI,FILEVERSION_MAJOR_LO
#define FILEVERSION_MAJOR_DOT		FILEVERSION_MAJOR_HI.FILEVERSION_MAJOR_LO
#define FILE_VERSION				FILEVERSION_MAJOR,FILE_REVISION,BUILD_NUMBER
#define FILE_VERSION_DOT			FILEVERSION_MAJOR_DOT.FILE_REVISION.BUILD_NUMBER

#define PRODUCTVERSION_MAJOR		PRODUCTVERSION_MAJOR_HI,PRODUCTVERSION_MAJOR_LO
#define PRODUCTVERSION_MAJOR_DOT	PRODUCTVERSION_MAJOR_HI.PRODUCTVERSION_MAJOR_LO
#define PRODUCT_VERSION				PRODUCTVERSION_MAJOR,VENDOR_VERSION,VENDOR_ISSUE
#define PRODUCT_VERSION_DOT			PRODUCTVERSION_MAJOR_DOT.VENDOR_VERSION.VENDOR_ISSUE

// The number-sign or "stringizing" operator (#) converts macro parameters (after expansion) to string constants. 
// It is used only with macros that take arguments. If it precedes a formal parameter in the macro definition, the actual 
// argument passed by the macro invocation is enclosed in quotation marks and treated as a string literal. The string 
// literal then replaces each occurrence of a combination of the stringizing operator and formal parameter within the macro
// definition. White space preceding the first token of the actual argument and following the last token of the actual 
// argument is ignored. Any white space between the tokens in the actual argument is reduced to a single white space in 
// the resulting string literal. Thus, if a comment occurs between two tokens in the actual argument, it is reduced to a 
// single white space. The resulting string literal is automatically concatenated with any adjacent string literals from 
// which it is separated only by white space. 
// Further, if a character contained in the argument usually requires an escape sequence when used in a string literal 
// (for example, the quotation mark (") or backslash (\) character), the necessary escape backslash is automatically 
// inserted before the character. The following example shows a macro definition that includes the stringizing operator 
// and a main function that invokes the macro:


// Causes the corresponding actual argument to be enclosed in double quotation marks with trailing NUL
// so 1.0.1.0 becomes "1.0.1.0\0"

#define VERSION_STRING_RAW(x)			# x "\0"	
#define VERSION_STRING(x)				VERSION_STRING_RAW(x)	// forces the expansion

#define FILEVERSION_STRING				VERSION_STRING(FILE_VERSION)
#define FILEVERSION_STRING_DOT			VERSION_STRING(FILE_VERSION_DOT)
#define PRODUCTVERSION_STRING			VERSION_STRING(PRODUCT_VERSION)
#define PRODUCTVERSION_STRING_DOT		VERSION_STRING(PRODUCT_VERSION_DOT)


