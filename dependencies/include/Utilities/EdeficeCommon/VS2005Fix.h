#pragma once

#ifdef _MSC_VER

	#pragma warning(disable:4482 4351)
	#pragma warning(default:4355)
	#define _CRT_SECURE_NO_WARNINGS
	#define _CRT_NON_CONFORMING_SWPRINTFS

	#if !defined(MOBILE)
		#if defined(_MANAGED) && (_MSC_VER >= 1600)
			#pragma warning(disable:4564)
		#endif

		#if !defined(_WIN32_WINNT)
			#define _WIN32_WINNT _WIN32_WINNT_VISTA
		#elif (_WIN32_WINNT < _WIN32_WINNT_VISTA)
			#undef _WIN32_WINNT
			#define _WIN32_WINNT _WIN32_WINNT_VISTA
		#endif
	#endif

#endif

#ifdef _DEBUG
	#ifndef DEBUG
		#define DEBUG
	#endif
#endif

#include "SalFix.h"
