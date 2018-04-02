#include "stdafx.h"
#include "VscProvider.h"
#include "Fields.h"
#include "Authenticate.h"
#include "AuthPackage.h"
#include <propkey.h>
#include <NTSecAPI.h>
#define SECURITY_WIN32
#define _SEC_WINNT_AUTH_TYPES
#include <Sspi.h>
#include <security.h>

#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "CredUI.lib")

IFACEMETHODIMP VscProvider::SetUsageScenario(__RPC__in CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus, __RPC__in DWORD dwFlags)
{
#ifdef MYID_DEBUG
	if (m_debug)
	{
		m_debug.WsIns() << L"SetUsageScenario " << cpus << L" " << myid::ToHex(dwFlags);
		m_debug.Write();
	}
#endif

	m_cpus = cpus;
	m_usageFlags = dwFlags;

	//if (Authenticate::IsCurrentSessionRemote())
	//	return E_NOTIMPL;

	switch (cpus)
	{
	case CPUS_LOGON:
	case CPUS_UNLOCK_WORKSTATION:
		if (!Authenticate::IsDomainJoined())
			return E_NOTIMPL;
		return S_OK;
	case CPUS_CREDUI:
		return S_OK;
	case CPUS_CHANGE_PASSWORD:
		// cannot change PIN
		// will use wrapped to change PIN on not IPT readers
		return E_NOTIMPL;
	}
	return E_NOTIMPL;
}

IFACEMETHODIMP VscProvider::SetSerialization(__RPC__in const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs)
{
	if (pcpcs == nullptr)
		return E_INVALIDARG;

#ifdef MYID_DEBUG
	if (m_debug)
	{
		std::wstringstream& stream = m_debug.WsIns();
		stream << L"SetSerialization\n";
		Authenticate::DebugSerialization(stream, pcpcs);
		m_debug.Write();
	}
#endif

	HRESULT hr = E_UNEXPECTED;
	//if (IsEqualGUID(CLSID_VscProvider, pcpcs->clsidCredentialProvider) || (m_cpus == CPUS_CREDUI))
	//{
	//	ULONG authPackage;
	//	hr = Authenticate::GetAuthPackage(authPackage);
	//	if (SUCCEEDED(hr))
	//	{
	//		if (m_cpus == CPUS_CREDUI)
	//		{
	//			if (m_usageFlags & CREDUIWIN_IN_CRED_ONLY)
	//			{
	//				hr = E_INVALIDARG;
	//			}
	//			else if (m_usageFlags & CREDUIWIN_AUTHPACKAGE_ONLY)
	//			{
	//				if (authPackage == pcpcs->ulAuthenticationPackage)
	//				{
	//					hr = S_FALSE;
	//				}
	//				else
	//				{
	//					hr = E_INVALIDARG;
	//				}
	//			}
	//		}
	//		if ((authPackage == pcpcs->ulAuthenticationPackage) &&
	//			(pcpcs->cbSerialization > 0) &&
	//			(pcpcs->rgbSerialization != nullptr) )
	//		{
	//			KERB_LOGON_SUBMIT_TYPE submitType = *(PKERB_LOGON_SUBMIT_TYPE)pcpcs->rgbSerialization;

	//			PSEC_WINNT_CREDUI_CONTEXT credUIContext(nullptr);
	//			SECURITY_STATUS st = SspiUnmarshalCredUIContext(pcpcs->rgbSerialization, pcpcs->cbSerialization, &credUIContext);
	//			if (st != SEC_E_OK)
	//			{
	//				m_debug.LogError(L"SspiUnmarshalCredUIContext", st);
	//			}
	//			else
	//			{
	//				LUID* logonID(nullptr);
	//				if (submitType == KerbCertificateUnlockLogon)
	//				{
	//					KERB_INTERACTIVE_UNLOCK_LOGON* pkil = (KERB_INTERACTIVE_UNLOCK_LOGON*)pcpcs->rgbSerialization;
	//					logonID = &pkil->LogonId;
	//				}
	//				PSEC_WINNT_CREDUI_CONTEXT_VECTOR credUIContexts(nullptr);
	//				HANDLE tokenHandle(nullptr);

	//				st = SspiGetCredUIContext(credUIContext->CredUIContextHandle, (GUID*)&SEC_WINNT_AUTH_DATA_TYPE_CERT, logonID, &credUIContexts, &tokenHandle);
	//				if (st != SEC_E_OK)
	//				{
	//					m_debug.LogError(L"SspiGetCredUIContext", st);
	//				}

	//				// ????

	//				if (credUIContexts)
	//					SspiLocalFree(credUIContexts);
	//			}
	//			if (credUIContext)
	//				SspiLocalFree(credUIContext);
	//		}
	//	}
	//}

	return hr;
}

IFACEMETHODIMP VscProvider::Advise(__RPC__in_opt ICredentialProviderEvents* pcpe, __RPC__in UINT_PTR upAdviseContext)
{
	try
	{
		m_providerEvents.Attach(pcpe, true);
		m_adviseContext = upAdviseContext;

#ifdef DEBUG_VSC
		if (m_debug)
		{
			m_debug.WsIns() << L"Advise " << myid::ToHex(upAdviseContext);
			m_debug.Write();
		}
#endif

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"Advise", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"Advise", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscProvider::UnAdvise()
{
	if (m_providerEvents)
		m_providerEvents.Release();
	m_adviseContext = 0;

#ifdef DEBUG_VSC
	if (m_debug)
	{
		m_debug.Log(L"UnAdvise");
	}
#endif

	return S_OK;
}

IFACEMETHODIMP VscProvider::GetFieldDescriptorCount(__RPC__out DWORD* pdwCount)
{
	if (pdwCount == nullptr)
		return E_INVALIDARG;

	*pdwCount = Fields::FID_NUM_FIELDS;

	return S_OK;
}

IFACEMETHODIMP VscProvider::GetFieldDescriptorAt(__RPC__in DWORD dwIndex, __RPC__deref_out_opt CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR** ppcpfd)
{
	*ppcpfd = nullptr;

	try
	{
		if (dwIndex >= Fields::FID_NUM_FIELDS)
			return E_INVALIDARG;

		const CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR* in = &Fields::FieldDescriptors[dwIndex];
		CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR* out = (CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR*)CoTaskMemAlloc(sizeof(CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR));
		if (out == nullptr)
			return E_OUTOFMEMORY;

		*ppcpfd = out;

		out->dwFieldID = in->dwFieldID;
		out->cpft = in->cpft;
		out->guidFieldType = in->guidFieldType;

		Fields::String str;
		switch (in->dwFieldID)
		{
		case Fields::FID_PIN:
			str.Resource(IDS_PIN);
			break;
		case Fields::FID_X509:
			str.Resource(IDS_X509_HINT);
			break;
		case Fields::FID_SUBMIT:
			str.Resource(IDS_SUBMIT);
			break;
		default:
			str = in->pszLabel;
		}
		str.Release(&out->pszLabel);

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetFieldDescriptorAt", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetFieldDescriptorAt", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscProvider::GetCredentialCount(__RPC__out DWORD* pdwCount, __RPC__range(0, *pdwCount) __RPC__out DWORD* pdwDefault, __RPC__out BOOL* pbAutoLogonWithDefault)
{
	try
	{
		if ((pdwCount == nullptr) || (pdwDefault == nullptr) || (pbAutoLogonWithDefault == nullptr))
			return E_INVALIDARG;

		GetCredentials();

		*pdwCount = static_cast<DWORD>(m_credential.size());
		*pdwDefault = CREDENTIAL_PROVIDER_NO_DEFAULT;
		*pbAutoLogonWithDefault = FALSE;

#ifdef DEBUG_VSC
		if (m_debug)
		{
			m_debug.WsIns() << L"Readers " << Data::Readers::Get().size()
				<< L" credentials " << *pdwCount;
			m_debug.Write();
		}
#endif

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetCredentialCount", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetCredentialCount", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscProvider::GetCredentialAt(__RPC__in DWORD dwIndex, __RPC__deref_out_opt ICredentialProviderCredential** ppcpc)
{
	*ppcpc = nullptr;

	try
	{
		if (dwIndex >= m_credential.size())
			return E_INVALIDARG;

		if (m_credential[dwIndex] == nullptr)
			return E_INVALIDARG;

		return m_credential[dwIndex]->QueryInterface(IID_PPV_ARGS(ppcpc));
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetCredentialAt", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetCredentialAt", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscProvider::SetUserArray(__RPC__in_opt ICredentialProviderUserArray* users)
{
	try
	{
		if (users == nullptr)
			return E_INVALIDARG;

		DWORD count(0);
		HRESULT hr = users->GetCount(&count);
		if (SUCCEEDED(hr) && (count > 0))
		{
#ifdef MYID_DEBUG
			m_debug.Log(L"SetUserArray count", count);
#endif
			Data::Users& usrs = Data::Users::Get();
			usrs.clear();
			usrs.reserve(count);

			for (DWORD c = 0; c < count; ++c)
			{
				ICredentialProviderUserPtr user;
				hr = users->GetAt(c, &user);
				if (SUCCEEDED(hr))
				{
					Data::User usr;
					std::wstring qual;

					PWSTR value(nullptr);
					hr = user->GetStringValue(PKEY_Identity_UserName, &value);
					if (SUCCEEDED(hr))
					{
						usr.user = value;
					}
					CoTaskMemFree(value);

					value = nullptr;
					hr = user->GetStringValue(PKEY_Identity_QualifiedUserName, &value);
					if (SUCCEEDED(hr))
					{
						qual = value;

						ULONG nSize(0);
						if (TranslateName(qual.c_str(), NameSamCompatible, NameUserPrincipal, nullptr, &nSize) != 0)
						{
							std::wstring upn(nSize - 1, ' ');
							if (TranslateName(qual.c_str(), NameSamCompatible, NameUserPrincipal, (LPWSTR)upn.c_str(), &nSize) != 0)
								usr.upn = upn;
						}
					}
					CoTaskMemFree(value);

					value = nullptr;
					hr = user->GetSid(&value);
					if (SUCCEEDED(hr))
					{
						usr.sid = value;
					}
					CoTaskMemFree(value);

					usrs.push_back(usr);
#ifdef MYID_DEBUG
					if (m_debug)
					{
						std::wstring display, status;

						value = nullptr;
						hr = user->GetStringValue(PKEY_Identity_DisplayName, &value);
						if (SUCCEEDED(hr))
						{
							display = value;
						}
						CoTaskMemFree(value);

						value = nullptr;
						hr = user->GetStringValue(PKEY_Identity_LogonStatusString, &value);
						if (SUCCEEDED(hr))
						{
							status = value;
						}
						CoTaskMemFree(value);

						m_debug.WsIns() << L"User " << c << L" '" << display << L"' '" << usr.user << L"' '" << qual << L"' '" << usr.upn << L"' '" << status << L"' " << usr.sid;
						m_debug.Write();
					}
#endif
				}
			}
		}

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"SetUserArray", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"SetUserArray", L"unknown exception");
	}

	return E_UNEXPECTED;
}

