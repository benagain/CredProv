#pragma once

#ifndef DOXYGEN

#ifdef _MANAGED
#undef __IServiceProvider_INTERFACE_DEFINED__
#endif

#if _MSC_VER >= 1910
	#import "VC15\DataExchange.tlb"
#elif _MSC_VER >= 1900
	#import "VC14\DataExchange.tlb"
#elif _MSC_VER >= 1800
	#import "VC12\DataExchange.tlb"
#elif _MSC_VER >= 1700
	#import "VC11\DataExchange.tlb"
#elif _MSC_VER >= 1600
	#import "VC10\DataExchange.tlb"
#endif

#endif

