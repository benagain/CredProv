// Requires a CComModule _Module; to be defined
// To be included

#ifndef OMIT_DLLMAIN_ENTRYPOINT

#ifndef MODULE_LIBID
#pragma message("MODULE_LIBID not defined")
#endif

#ifdef SET_COM_EXCEPTION
#include "Utilities\EdeficeCommon\Exceptions\ComException.h"
#endif

#ifdef OPENSSL_CALLBACKS
#include "Utilities\EdeficeCommon\Locking.h"
#endif

#ifdef _MERGE_PROXYSTUB
extern "C" HINSTANCE hProxyDll;
#endif

/// DLL Entry Point
extern "C" BOOL WINAPI DllMain(_In_ HINSTANCE hInstance, _In_ DWORD dwReason, _In_ LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(hInstance, dwReason, lpReserved))
	{
		return FALSE;
	}
#else
	UNREFERENCED_PARAMETER(lpReserved);
#endif

	if (dwReason == DLL_PROCESS_ATTACH)
	{
#ifdef SET_COM_EXCEPTION
		myid::ComException::SetComException();
#endif
		_Module.Init(ObjectMap, hInstance, &MODULE_LIBID);

#ifdef OPENSSL_CALLBACKS
		OpenSSL_setup();
#endif
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
#ifdef OPENSSL_CALLBACKS
		OpenSSL_cleanup();
#endif
		_Module.Term();
	}

	return TRUE;    // ok
}
#endif


/// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
	if (PrxDllCanUnloadNow() != S_OK)
		return S_FALSE;
#endif
	return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/// Returns a class factory to create an object of the requested type
_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
	if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
		return S_OK;
#endif
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/// Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
	HRESULT hRes = PrxDllRegisterServer();
	if (FAILED(hRes))
		return hRes;
#endif
	// registers object, typelib and all interfaces in typelib
	return _Module.RegisterServer(TRUE);
}

/// Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
	PrxDllUnregisterServer();
#endif
	return _Module.UnregisterServer(TRUE);
}
