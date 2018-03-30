#pragma once
#include "resource.h"
#include "Fields.h"
#include "IncludeMyidCredentialProvider.h"
#include "Data.h"

/// VscCredential object
class ATL_NO_VTABLE MyidCredential
	: public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>
	, public ICredentialProviderCredential2
	, public ICredentialProviderCredentialWithFieldOptions
{
public:
	MyidCredential();
	virtual ~MyidCredential();

	DECLARE_NOT_AGGREGATABLE(MyidCredential)

	BEGIN_COM_MAP(MyidCredential)
		COM_INTERFACE_ENTRY(ICredentialProviderCredential)
		COM_INTERFACE_ENTRY(ICredentialProviderCredential2)
		COM_INTERFACE_ENTRY(ICredentialProviderCredentialWithFieldOptions)
	END_COM_MAP()

	// ICredentialProviderCredential Methods
	IFACEMETHOD(Advise)(__RPC__in_opt ICredentialProviderCredentialEvents* pcpce);
	IFACEMETHOD(UnAdvise)();
	IFACEMETHOD(SetSelected)(__RPC__out BOOL* pbAutoLogon);
	IFACEMETHOD(SetDeselected)();
	IFACEMETHOD(GetFieldState)(__RPC__in DWORD fieldID, __RPC__out CREDENTIAL_PROVIDER_FIELD_STATE* pcpfs, __RPC__out CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE* pcpfis);
	IFACEMETHOD(GetStringValue)(__RPC__in DWORD fieldID, __RPC__deref_out_opt_string LPWSTR* ppsz);
	IFACEMETHOD(GetBitmapValue)(__RPC__in DWORD fieldID, __RPC__deref_out_opt HBITMAP* phbmp);
	IFACEMETHOD(GetCheckboxValue)(__RPC__in DWORD fieldID, __RPC__out BOOL* pbChecked, __RPC__deref_out_opt_string LPWSTR* ppszLabel);
	IFACEMETHOD(GetSubmitButtonValue)(__RPC__in DWORD fieldID, __RPC__out DWORD* pdwAdjacentTo);
	IFACEMETHOD(GetComboBoxValueCount)(__RPC__in DWORD fieldID, __RPC__out DWORD* pcItems, _Deref_out_range_(<, *pcItems) __RPC__out DWORD* pdwSelectedItem);
	IFACEMETHOD(GetComboBoxValueAt)(__RPC__in DWORD fieldID, __RPC__in DWORD dwItem, __RPC__deref_out_opt_string LPWSTR* ppszItem);
	IFACEMETHOD(SetStringValue)(__RPC__in DWORD fieldID, __RPC__in_string LPCWSTR psz);
	IFACEMETHOD(SetCheckboxValue)(__RPC__in DWORD fieldID, __RPC__in BOOL bChecked);
	IFACEMETHOD(SetComboBoxSelectedValue)(__RPC__in DWORD fieldID, __RPC__in DWORD dwSelectedItem);
	IFACEMETHOD(CommandLinkClicked)(__RPC__in DWORD fieldID);
	IFACEMETHOD(GetSerialization)(__RPC__out CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE* pcpgsr, __RPC__out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs, __RPC__deref_out_opt_string LPWSTR* ppszOptionalStatusText, __RPC__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon);
	IFACEMETHOD(ReportResult)(__RPC__in NTSTATUS ntsStatus, __RPC__in NTSTATUS ntsSubstatus, __RPC__deref_out_opt_string LPWSTR* ppszOptionalStatusText, __RPC__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon);

	// ICredentialProviderCredential2 Methods
	IFACEMETHOD(GetUserSid)(__RPC__deref_out_opt_string LPWSTR* sid);

	// ICredentialProviderCredentialWithFieldOptions Methods
	IFACEMETHOD(GetFieldOptions)(__RPC__in DWORD fieldID, __RPC__out CREDENTIAL_PROVIDER_CREDENTIAL_FIELD_OPTIONS* options);

	void Init(_In_ DWORD index, _In_ const Data::Credential& data, _In_ CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus);

protected:
	HRESULT SerializationData(__RPC__out byte*& data, __RPC__out ULONG& dataSize);

	mutable Support::Debug m_debug;							///< debug data
	Data::Credential m_data;								///< credential data
	Fields::String m_strings[Fields::FID_NUM_FIELDS];		///< field strings
	CREDENTIAL_PROVIDER_USAGE_SCENARIO m_cpus;				///< from SetUsageScenario()
	ICredentialProviderCredentialEventsPtr m_events;		///< from Advise
	ICredentialProviderCredentialEvents2Ptr m_events2;		///< from m_events
};
