#pragma once

#ifndef DOXYGEN

#if _MSC_VER >= 1910
	#import "VC15\GPScriptingObjects.tlb"
#elif _MSC_VER >= 1900
	#import "VC14\GPScriptingObjects.tlb"
#elif _MSC_VER >= 1800
	#import "VC12\GPScriptingObjects.tlb"
#elif _MSC_VER >= 1700
	#import "VC11\GPScriptingObjects.tlb"
#elif _MSC_VER >= 1600
	#import "VC10\GPScriptingObjects.tlb"
#endif

#endif
