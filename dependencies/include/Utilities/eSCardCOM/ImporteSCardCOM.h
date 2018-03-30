#pragma once

#ifndef DOXYGEN

#if _MSC_VER >= 1910
	#import "VC15\eSCardCOM.tlb"
#elif _MSC_VER >= 1900
	#import "VC14\eSCardCOM.tlb"
#elif _MSC_VER >= 1800
	#import "VC12\eSCardCOM.tlb"
#elif _MSC_VER >= 1700
	#import "VC11\eSCardCOM.tlb"
#elif _MSC_VER >= 1600
	#import "VC10\eSCardCOM.tlb"
#endif

#endif

