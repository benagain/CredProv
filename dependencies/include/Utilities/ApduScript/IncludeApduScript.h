#pragma once

#if _MSC_VER >= 1910
	#include "VC15\ApduScript.h"
#elif _MSC_VER >= 1900
	#include "VC14\ApduScript.h"
#elif _MSC_VER >= 1800
	#include "VC12\ApduScript.h"
#elif _MSC_VER >= 1700
	#include "VC11\ApduScript.h"
#elif _MSC_VER >= 1600
	#include "VC10\ApduScript.h"
#endif
