#ifdef _MANAGED
// This provides a standard implementation for the IObjectSafety interface defined in SiteSafety.h

#ifdef SITESAFETY_OBJECT_SAFETY
/// Implement IObjectSafety::GetInterfaceSafetyOptions()
public: virtual HRESULT GetInterfaceSafetyOptions(REFIID /*riid*/, DWORD *pdwSupportedOptions, DWORD *pdwEnabledOptions)
{
	*pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA;
	*pdwEnabledOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA;

	return S_OK;
}

/// Implement IObjectSafety::SetInterfaceSafetyOptions()
public: virtual HRESULT SetInterfaceSafetyOptions(REFIID /*riid*/, DWORD /*dwOptionSetMask*/, DWORD /*dwEnabledOptions*/)
{
	return S_OK;
}
#endif

#ifdef SITESAFETY_OBJECT_WITHSITE
/// Implement IObjectWithSite::GetSite()
public: virtual HRESULT GetSite(REFIID riid, void** ppvSite)
{
	HRESULT hr = E_POINTER;
	if (ppvSite != NULL)
	{
		if (m_pUnkSite)
			hr = m_pUnkSite->QueryInterface(riid, ppvSite);
		else
		{
			*ppvSite = NULL;
			hr = E_FAIL;
		}
	}
	return hr;
}

/// Implement IObjectWithSite::SetSite()
public: virtual HRESULT SetSite(IUnknown *pUnkSite)
{
	m_pUnkSite = pUnkSite;
	return S_OK;
}

private: msclr::com::ptr<IUnknown> m_pUnkSite;

#endif

#endif
