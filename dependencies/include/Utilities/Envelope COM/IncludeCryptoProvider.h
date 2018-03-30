#pragma once

#if _MSC_VER >= 1910
	#include "VC15\CryptoProvider.h"
#elif _MSC_VER >= 1900
	#include "VC14\CryptoProvider.h"
#elif _MSC_VER >= 1800
	#include "VC12\CryptoProvider.h"
#elif _MSC_VER >= 1700
	#include "VC11\CryptoProvider.h"
#elif _MSC_VER >= 1600
	#include "VC10\CryptoProvider.h"
#endif
