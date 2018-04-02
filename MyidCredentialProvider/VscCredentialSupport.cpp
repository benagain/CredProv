#include "stdafx.h"
#include "Resource.h"
#include "MyidCredential.h"
#include "dllmain.h"

//#include "Msg\EventLog.h"

namespace
{

/// Response messages to error codes
struct ReportData
{
	NTSTATUS ntsStatus;						///< status to match
	NTSTATUS ntsSubstatus;					///< sub-status to match
	UINT id;								///< resource ID
	CREDENTIAL_PROVIDER_STATUS_ICON cpsi;	///< icon
};

/// Responses to errors
ReportData ReportMsg[] =
{
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_CERT_REVOKED, IDS_CERT_REVOKED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_ISSUING_CA_UNTRUSTED, IDS_CA_UNTRUSTED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_ISSUING_CA_UNTRUSTED_KDC, IDS_CA_UNTRUSTED_KDC, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_REVOCATION_OFFLINE_C, IDS_REVOCATION_OFFLINE_C, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_PKINIT_CLIENT_FAILURE, IDS_PKINIT_CLIENT_FAILURE, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_CERT_EXPIRED, IDS_CERT_EXPIRED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_SUBSYSTEM_FAILURE, IDS_LOGON_FAILURE, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_NO_KEY_CONTAINER, IDS_NO_KEY_CONTAINER, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_WRONG_PIN, IDS_WRONG_PIN, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_SMARTCARD_CARD_BLOCKED, IDS_CARD_BLOCKED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_KDC_CERT_EXPIRED, IDS_CREDENTIAL_NOT_VERIFIED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_KDC_CERT_REVOKED, IDS_CREDENTIAL_NOT_VERIFIED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_REVOCATION_OFFLINE_KDC, IDS_REVOCATION_OFFLINE_KDC, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, STATUS_PKINIT_NAME_MISMATCH, IDS_CREDENTIAL_NOT_VERIFIED, CPSI_ERROR},
	{STATUS_LOGON_FAILURE, 0, IDS_CREDENTIAL_NOT_VERIFIED, CPSI_ERROR},
	{STATUS_ACCOUNT_EXPIRED, STATUS_ACCOUNT_EXPIRED, IDS_ACCOUNT_EXPIRED, CPSI_WARNING},
	{STATUS_ACCOUNT_LOCKED_OUT, 0, IDS_ACCOUNT_LOCKED_OUT, CPSI_WARNING},
	{STATUS_ACCOUNT_RESTRICTION, STATUS_ACCOUNT_DISABLED, IDS_ACCOUNT_DISABLED, CPSI_WARNING},
	{STATUS_ACCOUNT_RESTRICTION, STATUS_INVALID_LOGON_HOURS, IDS_ACCOUNT_RESTRICTION, CPSI_WARNING},
	{STATUS_ACCOUNT_RESTRICTION, STATUS_PASSWORD_EXPIRED, IDS_PASSWORD_EXPIRED, CPSI_WARNING},
	{STATUS_ACCOUNT_RESTRICTION, STATUS_INVALID_WORKSTATION, IDS_INVALID_WORKSTATION, CPSI_WARNING},
	{STATUS_ACCOUNT_RESTRICTION, 0, IDS_CREDENTIAL_NOT_VERIFIED, CPSI_WARNING},
	{STATUS_NO_LOGON_SERVERS, 0, IDS_NO_LOGON_SERVERS, CPSI_WARNING},
	{STATUS_LOGON_TYPE_NOT_GRANTED, 0, IDS_LOGON_TYPE_NOT_GRANTED, CPSI_WARNING},
	{STATUS_NOT_SUPPORTED, 0, IDS_NOT_SUPPORTED, CPSI_WARNING},
};

} // anon namespace

//==========================================================================================================================

MyidCredential::MyidCredential()
	: m_cpus(CPUS_INVALID)
	, m_debug(L"Vsc")
{
	_AtlModule.Lock();
#ifdef DEBUG_COM
	m_debug.Log(L"Start", myid::ToHex((ULONG_PTR)this));
#endif
}


MyidCredential::~MyidCredential()
{
#ifdef DEBUG_COM
	m_debug.Log(L"End", myid::ToHex((ULONG_PTR)this));
#endif
	_AtlModule.Unlock();
}

/// Initialise object
void MyidCredential::Init(
	_In_ DWORD index,									///< index
	_In_ const Data::Credential& data,					///< credential data
	_In_ CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus)		///< copy from provider
{
	if (m_debug)
	{
		m_debug.Instance(L"Vsc " + myid::ULONGtoWSTR(index));
#ifdef MYID_DEBUG
		m_debug.WsIns() << L"Init '" << data.reader << L"' '" << data.name << L"' '" << data.user << L"' " << data.sid << L" " << L"\n";
		m_debug.Write();
#endif
	}

	m_cpus = cpus;
	for (auto& s : m_strings)
		s.Clear();

	m_data = data;
	m_strings[Fields::FID_NAME] = m_data.name;
	m_strings[Fields::FID_SUBMIT].Resource(IDS_SUBMIT);

	if (m_data.ipt)
	{
		m_strings[Fields::FID_HINT].Resource(IDS_UNSEL_HINT_IPT);
		m_strings[Fields::FID_LABEL].Resource(IDS_LABEL_IPT);
		if (m_cpus != CPUS_CREDUI)
			m_strings[Fields::FID_PROMPT].Resource(IDS_LOGIN);
	}
	else
	{
		m_strings[Fields::FID_HINT].Resource(IDS_UNSEL_HINT);
		m_strings[Fields::FID_LABEL].Resource(IDS_LABEL);
	}

	m_strings[Fields::FID_PIN].Secure(true);
}

/// Report from a lookup table
IFACEMETHODIMP MyidCredential::ReportResult(__RPC__in NTSTATUS ntsStatus, __RPC__in NTSTATUS ntsSubstatus, __RPC__deref_out_opt_string LPWSTR* ppszOptionalStatusText, __RPC__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon)
{
	if ((ppszOptionalStatusText == nullptr) || (pcpsiOptionalStatusIcon == nullptr))
		return E_INVALIDARG;

	if (ntsStatus != STATUS_SUCCESS)
	{
		if (!m_data.ipt)
		{
			// clear password
			m_strings[Fields::FID_PIN].Clear();
			if (m_events)
				m_events->SetFieldString(this, Fields::FID_PIN, m_strings[Fields::FID_PIN]);
		}

		// look for ntsStatus and ntsSubstatus
		for (const auto& msg : ReportMsg)
		{
			if ((msg.ntsStatus == ntsStatus) && (msg.ntsSubstatus == ntsSubstatus))
			{
				Fields::String str;
				str.Resource(msg.id);
				str.Release(ppszOptionalStatusText);
				*pcpsiOptionalStatusIcon = msg.cpsi;
				return S_OK;
			}
		}

		bool found(false);
		// not found ntsSubstatus, look for ntsStatus default
		for (const auto& msg : ReportMsg)
		{
			if ((msg.ntsStatus == ntsStatus) && (msg.ntsSubstatus == 0))
			{
				Fields::String str;
				str.Resource(msg.id);
				str.Release(ppszOptionalStatusText);
				*pcpsiOptionalStatusIcon = msg.cpsi;
				found = true;
				break;
			}
		}

		if (!found)
		{
			// not found ntsStatus or ntsSubstatus, get error text for ntsStatus
			Fields::String str(myid::ErrorException::GetErrorText(ntsStatus));
			str.Release(ppszOptionalStatusText);
			*pcpsiOptionalStatusIcon = CPSI_ERROR;
		}

		myid::StringList strs{myid::ToHex(ntsStatus), myid::ToHex(ntsSubstatus)};
		//Support::LogEvent(IPT_LOGON_UNKNOWN_ERROR, strs, L"IPTCredentialProvider");

		m_debug.LogError(L"ReportResult", ntsStatus);
		m_debug.LogError(L"ReportResult", ntsSubstatus);
	}
	else
	{
		*ppszOptionalStatusText = nullptr;
		*pcpsiOptionalStatusIcon = CPSI_NONE;
	}

	return S_OK;
}
