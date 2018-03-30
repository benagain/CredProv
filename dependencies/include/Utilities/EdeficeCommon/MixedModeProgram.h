#pragma once

/** \file
 * Mixed mode program link fix
 */

#ifdef _MANAGED

#ifdef _M_X64
	#pragma comment(linker, "/include:_DllMainCRTStartup")
#else
	#pragma comment(linker, "/include:__DllMainCRTStartup@12")
#endif

#endif
