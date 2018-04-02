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

#include "Utilities\SoftCrypto\CryptNTstatus.h"

#include "resource.h"
#include "Resources\Strings.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <comdef.h>

#define INITGUID
#include <guiddef.h>
#include <credentialprovider.h>
#include <ShlGuid.h>
#include <wincred.h>

#include <atomic>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <thread>
#include <string>

#include "Utilities\EdeficeCommon\VectorOfByte.h"
#include "Utilities\EdeficeCommon\Conversions\Numbers.h"
#include "Utilities\EdeficeCommon\Conversions\StringUtils.h"
#include "Utilities\EdeficeCommon\Conversions\HexBinVectorConversion.h"
#include "Utilities\EdeficeCommon\Exceptions\ErrorException.h"
#include "Utilities\EdeficeCommon\Instance.h"

#include "..\VscCommon\Debug.h"

_COM_SMARTPTR_TYPEDEF(ICredentialProvider, __uuidof(ICredentialProvider));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderCredential, __uuidof(ICredentialProviderCredential));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderCredential2, __uuidof(ICredentialProviderCredential2));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderCredentialEvents, __uuidof(ICredentialProviderCredentialEvents));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderCredentialEvents2, __uuidof(ICredentialProviderCredentialEvents2));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderEvents, __uuidof(ICredentialProviderEvents));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderSetUserArray, __uuidof(ICredentialProviderSetUserArray));
_COM_SMARTPTR_TYPEDEF(ICredentialProviderUser, __uuidof(ICredentialProviderUser));

extern HINSTANCE DLL_hInstance;

#ifdef MYID_DEBUG
#define DEBUG_COM
#define DEBUG_VSC
#define DEBUG_WRAP
#define DEBUG_WRAP_EVENTS
#define DEBUG_WRAP_FIELDS
#define DEBUG_SID
#endif

