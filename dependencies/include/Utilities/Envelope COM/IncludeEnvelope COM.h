#pragma once

#if _MSC_VER >= 1910
	#include "VC15\Envelope COM.h"
#elif _MSC_VER >= 1900
	#include "VC14\Envelope COM.h"
#elif _MSC_VER >= 1800
	#include "VC12\Envelope COM.h"
#elif _MSC_VER >= 1700
	#include "VC11\Envelope COM.h"
#elif _MSC_VER >= 1600
	#include "VC10\Envelope COM.h"
#endif
