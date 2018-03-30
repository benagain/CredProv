// Requires _AtlModule to be defined
// To be included in the file where _AtlModule is defined
// Please add to the .def file:
//      DllInstall	PRIVATE
#ifdef SET_COM_EXCEPTION
#include "Utilities\EdeficeCommon\Exceptions\ComException.h"
#endif

#ifdef OPENSSL_CALLBACKS
#include "Utilities\EdeficeCommon\Locking.h"
#endif

#ifndef REGISTER_TYPELIB
#define REGISTER_TYPELIB TRUE
#endif

#ifdef _MERGE_PROXYSTUB

extern "C"
{
BOOL WINAPI PrxDllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved);
STDAPI PrxDllCanUnloadNow(void);
STDAPI PrxDllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
STDAPI PrxDllRegisterServer(void);
STDAPI PrxDllUnregisterServer(void);
}

#endif

// if required, add
// extern HINSTANCE DLL_hInstance;
// to StdAfx.h
HINSTANCE DLL_hInstance = NULL;			///< DLL instance

#ifndef OMIT_DLLMAIN_ENTRYPOINT
/// DLL Entry Point
extern "C" BOOL WINAPI DllMain(_In_ HINSTANCE hInstance, _In_ DWORD dwReason, _In_ LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(hInstance, dwReason, lpReserved))
		return FALSE;
#endif
	DLL_hInstance = hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
#ifdef SET_COM_EXCEPTION
		myid::ComException::SetComException();
#endif

#ifdef OPENSSL_CALLBACKS
		OpenSSL_setup();
#endif
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
#ifdef OPENSSL_CALLBACKS
		OpenSSL_cleanup();
#endif
	}

	return _AtlModule.DllMain(dwReason, lpReserved);
}
#endif


/// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
	HRESULT hr = PrxDllCanUnloadNow();
	if (hr != S_OK)
		return hr;
#endif

#ifdef __AFXWIN_H__
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
#else
	return _AtlModule.DllCanUnloadNow();
#endif
}


/// Returns a class factory to create an object of the requested type
_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
	if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
		return S_OK;
#endif

	return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


/// Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	HRESULT hr = _AtlModule.DllRegisterServer(REGISTER_TYPELIB);
#ifdef _MERGE_PROXYSTUB
	if (FAILED(hr))
		return hr;
	hr = PrxDllRegisterServer();
#endif
	return hr;
}


/// Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer(REGISTER_TYPELIB);
#ifdef _MERGE_PROXYSTUB
	if (FAILED(hr))
		return hr;
	hr = PrxDllRegisterServer();
	if (FAILED(hr))
		return hr;
	hr = PrxDllUnregisterServer();
#endif
	return hr;
}


/// Adds/Removes entries to the system registry per user per machine.
STDAPI DllInstall(_In_ BOOL bInstall, _In_opt_ LPCWSTR pszCmdLine)
{
	HRESULT hr = E_FAIL;
#if _MSC_VER >= 1500
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != NULL)
	{
		if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
		{
			ATL::AtlSetPerUserRegistration(true);
		}
	}
#else
	pszCmdLine;
#endif

	if (bInstall)
	{
		hr = DllRegisterServer();
		if (FAILED(hr))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}
