#pragma once
#include "resource.h"
#include "IncludeMyidCredentialProvider.h"
#include "MyidCredential.h"

/// VscProvider object
class ATL_NO_VTABLE VscProvider
	: public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>
	, public ATL::CComCoClass<VscProvider, &CLSID_VscProvider>
	, public ICredentialProvider
	, public ICredentialProviderSetUserArray
{
public:
	VscProvider();
	~VscProvider();

	DECLARE_NOT_AGGREGATABLE(VscProvider)
	DECLARE_REGISTRY_RESOURCEID(IDR_MYIDCREDENTIALPROVIDER)

	BEGIN_COM_MAP(VscProvider)
		COM_INTERFACE_ENTRY(ICredentialProvider)
		COM_INTERFACE_ENTRY(ICredentialProviderSetUserArray)
	END_COM_MAP()

	// ICredentialProvider Methods
	IFACEMETHOD(SetUsageScenario)(__RPC__in CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus, __RPC__in DWORD dwFlags);
	IFACEMETHOD(SetSerialization)(__RPC__in const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs);
	IFACEMETHOD(Advise)(__RPC__in_opt ICredentialProviderEvents* pcpe, __RPC__in UINT_PTR upAdviseContext);
	IFACEMETHOD(UnAdvise)();
	IFACEMETHOD(GetFieldDescriptorCount)(__RPC__out DWORD* pdwCount);
	IFACEMETHOD(GetFieldDescriptorAt)(__RPC__in DWORD dwIndex, __RPC__deref_out_opt CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR** ppcpfd);
	IFACEMETHOD(GetCredentialCount)(__RPC__out DWORD* pdwCount, __RPC__range(0, *pdwCount) __RPC__out DWORD* pdwDefault, __RPC__out BOOL* pbAutoLogonWithDefault);
	IFACEMETHOD(GetCredentialAt)(__RPC__in DWORD dwIndex, __RPC__deref_out_opt ICredentialProviderCredential** ppcpc);

	// ICredentialProviderSetUserArray Methods
	IFACEMETHOD(SetUserArray)(__RPC__in_opt ICredentialProviderUserArray* users);

	void OnCredentialsChanged(void);

protected:
	void GetCredentials(void);
	void ClearCredential(void);

	mutable Support::Debug m_debug;								///< debug data
	bool m_needCredentials{true};								///< need to get credentials
	std::recursive_mutex m_mutex;								///< mutex for m_credential
	std::vector<ICredentialProviderCredentialPtr> m_credential;	///< credential objects
	CREDENTIAL_PROVIDER_USAGE_SCENARIO m_cpus;					///< from SetUsageScenario()
	DWORD m_usageFlags{};										///< flags from SetUsageScenario()
	ICredentialProviderEventsPtr m_providerEvents;				///< provider events
	UINT_PTR m_adviseContext{};									///< opaque parameter for ICredentialProviderEvents
};

OBJECT_ENTRY_AUTO(__uuidof(VscProvider), VscProvider)
