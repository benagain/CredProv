#pragma once

#ifdef _MANAGED

// See SiteSafety.cpp for a standard implememtation
#include <ObjSafe.h>
#include <msclr\com\ptr.h>

namespace MyId
{
namespace SiteSafety
{

#ifdef SITESAFETY_OBJECT_SAFETY

[ComImport]
[Guid("CB5BDC81-93C1-11CF-8F20-00805F2CD064")]
[InterfaceType(ComInterfaceType::InterfaceIsIUnknown)]
[ComVisible(true)]
public interface class IObjectSafety
{
public:
	[PreserveSig]
	virtual HRESULT GetInterfaceSafetyOptions(REFIID riid, DWORD* pdwSupportedOptions, DWORD* pdwEnabledOptions) = 0;

	[PreserveSig]
	virtual HRESULT SetInterfaceSafetyOptions(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions) = 0;
};
#endif

#ifdef SITESAFETY_OBJECT_WITHSITE
[ComImport]
[InterfaceType(ComInterfaceType::InterfaceIsIUnknown)]
[Guid(L"FC4801A3-2BA9-11CF-A229-00AA003D7352")]
[ComVisible(true)]
public interface class IObjectWithSite
{
public:
	[PreserveSig]
	virtual HRESULT GetSite(REFIID riid, void** ppvSite) = 0;

	[PreserveSig]
	virtual HRESULT SetSite(IUnknown *pUnkSite) = 0;
};
#endif

} // namespace SiteSafety
} // namespace MyId

#endif
