#pragma once

#ifndef DOXYGEN

#if _MSC_VER >= 1910
	#import "VC15\DirectAPISmartCard.tlb"
#elif _MSC_VER >= 1900
	#import "VC14\DirectAPISmartCard.tlb"
#elif _MSC_VER >= 1800
	#import "VC12\DirectAPISmartCard.tlb"
#elif _MSC_VER >= 1700
	#import "VC11\DirectAPISmartCard.tlb"
#elif _MSC_VER >= 1600
	#import "VC10\DirectAPISmartCard.tlb"
#endif

#endif
