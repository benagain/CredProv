// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "IncludeMyidCredentialProvider.h"
#include "dllmain.h"

CMyidCredentialProviderModule _AtlModule;

HINSTANCE DLL_hInstance;


// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	DLL_hInstance = hInstance;

	return _AtlModule.DllMain(dwReason, lpReserved);
}
