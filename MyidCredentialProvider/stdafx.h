#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define RPC_USE_NATIVE_WCHAR

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit
#define ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW
#define _ATL_NO_HOSTING
#define _ATL_ALL_WARNINGS

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

#define INITGUID
#include <guiddef.h>
#include <credentialprovider.h>
#include <ShlGuid.h>
#include <wincred.h>
