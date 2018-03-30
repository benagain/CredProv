#pragma once

#if !defined(MOBILE)
	#include <sal.h>
#ifndef NTSTATUS
#if (_MSC_VER >= 1800)
	typedef _Return_type_success_(return >= 0) long NTSTATUS;
#else
	typedef long NTSTATUS;
#endif
#endif
	#include <ntstatus.h>
	#define WIN32_NO_STATUS
#endif
