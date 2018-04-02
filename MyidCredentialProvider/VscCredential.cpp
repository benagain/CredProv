#include "stdafx.h"
#include "VscCredential.h"
#include "VscProvider.h"
#include "AuthPackage.h"
#include "Policy.h"
//#include "Msg\EventLog.h"


IFACEMETHODIMP VscCredential::Advise(__RPC__in_opt ICredentialProviderCredentialEvents* pcpce)
{
	m_events.Attach(pcpce, true);
	pcpce->QueryInterface(IID_PPV_ARGS(&m_events2));

	return S_OK;
}

IFACEMETHODIMP VscCredential::UnAdvise()
{
	if (m_events)
		m_events.Release();
	if (m_events2)
		m_events2.Release();

	return S_OK;
}

IFACEMETHODIMP VscCredential::SetSelected(__RPC__out BOOL* pbAutoLogon)
{
	try
	{
		*pbAutoLogon = FALSE;

		if (m_data.showUser)
		{
			m_strings[Fields::FID_NAME] = m_data.name;
			m_strings[Fields::FID_USERNAME] = m_data.user;
		}
		else
		{
			m_strings[Fields::FID_NAME].Clear();
			m_strings[Fields::FID_USERNAME].Clear();
		}
		if (m_data.ipt)
			m_strings[Fields::FID_HINT].Resource(m_data.sid.empty() ? IDS_SEL_HINT_IPT : IDS_UNSEL_HINT_IPT);
		else
			m_strings[Fields::FID_HINT].Resource(m_data.sid.empty() ? IDS_SEL_HINT : IDS_UNSEL_HINT);

		if (m_events2)
			m_events2->BeginFieldUpdates();

		if (m_events)
		{
			m_events->SetFieldString(this, Fields::FID_NAME, m_strings[Fields::FID_NAME]);
			m_events->SetFieldString(this, Fields::FID_USERNAME, m_strings[Fields::FID_USERNAME]);
			m_events->SetFieldString(this, Fields::FID_HINT, m_strings[Fields::FID_HINT]);

			m_events->SetFieldState(this, Fields::FID_NAME, m_strings[Fields::FID_NAME].Empty() ? CPFS_HIDDEN : Fields::FieldStates[Fields::FID_NAME]);
			m_events->SetFieldState(this, Fields::FID_USERNAME, m_strings[Fields::FID_USERNAME].Empty() ? CPFS_HIDDEN : Fields::FieldStates[Fields::FID_USERNAME]);
		}

		if (m_events2)
			m_events2->EndFieldUpdates();

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"SetSelected", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"SetSelected", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::SetDeselected()
{
	try
	{
		m_strings[Fields::FID_NAME] = m_data.name;
		m_strings[Fields::FID_USERNAME].Clear();
		if (m_data.ipt)
		{
			m_strings[Fields::FID_HINT].Resource(IDS_UNSEL_HINT_IPT);
		}
		else
		{
			m_strings[Fields::FID_HINT].Resource(IDS_UNSEL_HINT);
			m_strings[Fields::FID_PIN].Clear();
		}

		if (m_events2)
			m_events2->BeginFieldUpdates();

		if (m_events)
		{
			m_events->SetFieldString(this, Fields::FID_NAME, m_strings[Fields::FID_NAME]);
			m_events->SetFieldString(this, Fields::FID_USERNAME, m_strings[Fields::FID_USERNAME]);
			m_events->SetFieldString(this, Fields::FID_HINT, m_strings[Fields::FID_HINT]);
			if (!m_data.ipt)
				m_events->SetFieldString(this, Fields::FID_PIN, m_strings[Fields::FID_PIN]);

			m_events->SetFieldState(this, Fields::FID_NAME, m_strings[Fields::FID_NAME].Empty() ? CPFS_HIDDEN : Fields::FieldStates[Fields::FID_NAME]);
			m_events->SetFieldState(this, Fields::FID_USERNAME, m_strings[Fields::FID_USERNAME].Empty() ? CPFS_HIDDEN : Fields::FieldStates[Fields::FID_USERNAME]);
		}

		if (m_events2)
			m_events2->EndFieldUpdates();

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"SetDeselected", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"SetDeselected", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::GetFieldState(__RPC__in DWORD fieldID, __RPC__out CREDENTIAL_PROVIDER_FIELD_STATE* pcpfs, __RPC__out CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE* pcpfis)
{
	try
	{
		if ((pcpfs == nullptr) || (pcpfis == nullptr))
			return E_INVALIDARG;

		if (fieldID >= Fields::FID_NUM_FIELDS)
			return E_INVALIDARG;

		switch (fieldID)
		{
		case Fields::FID_PROMPT:
			*pcpfs = (m_data.ipt && !Data::Policy::Get().X509HintsNeeded()) ? CPFS_DISPLAY_IN_SELECTED_TILE : CPFS_HIDDEN;
			break;
		case Fields::FID_PIN:
			*pcpfs = m_data.ipt ? CPFS_HIDDEN : CPFS_DISPLAY_IN_SELECTED_TILE;
			break;
		case Fields::FID_X509:
			*pcpfs = Data::Policy::Get().X509HintsNeeded() ? CPFS_DISPLAY_IN_SELECTED_TILE : CPFS_HIDDEN;
			break;
		default:
			*pcpfs = Fields::FieldStates[fieldID];
			break;
		}

		switch (fieldID)
		{
		case Fields::FID_PIN:
			*pcpfis = m_data.ipt ? CPFIS_NONE : CPFIS_FOCUSED;
			break;
		default:
			*pcpfis = CPFIS_NONE;
			break;
		}

		return S_OK;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetFieldState", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetFieldState", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::GetStringValue(__RPC__in DWORD fieldID, __RPC__deref_out_opt_string LPWSTR* ppsz)
{
	*ppsz = nullptr;

	try
	{
		if (fieldID >= Fields::FID_NUM_FIELDS)
			return E_INVALIDARG;

		HRESULT hr;
		if (m_strings[fieldID])
			hr = m_strings[fieldID].Dup(ppsz);
		else
			hr = SHStrDupW(L"", ppsz);
		__analysis_assume(hr == S_OK);
		return hr;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetStringValue", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetStringValue", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::GetBitmapValue(__RPC__in DWORD fieldID, __RPC__deref_out_opt HBITMAP* phbmp)
{
	*phbmp = nullptr;

	if (fieldID != Fields::FID_IMAGE)
		return E_INVALIDARG;

	// the bitmap object is not deleted by us
#ifdef MYID_DEBUG
	HBITMAP hbmp = LoadBitmap(DLL_hInstance, MAKEINTRESOURCE(IDB_MYID_READER_DEBUG));
#else
	HBITMAP hbmp = LoadBitmap(DLL_hInstance, MAKEINTRESOURCE(IDB_MYID_READER));
#endif
	if (hbmp == NULL)
		return HRESULT_FROM_WIN32(GetLastError());

	*phbmp = hbmp;

	return S_OK;
}

IFACEMETHODIMP VscCredential::GetCheckboxValue(__RPC__in DWORD fieldID, __RPC__out BOOL* pbChecked, __RPC__deref_out_opt_string LPWSTR* ppszLabel)
{
	UNREFERENCED_PARAMETER(fieldID);
	UNREFERENCED_PARAMETER(pbChecked);

	*ppszLabel = nullptr;

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::GetSubmitButtonValue(__RPC__in DWORD fieldID, __RPC__out DWORD* pdwAdjacentTo)
{
	if (pdwAdjacentTo == nullptr)
		return E_INVALIDARG;

	if (fieldID != Fields::FID_SUBMIT)
		return E_INVALIDARG;

	if (Data::Policy::Get().X509HintsNeeded())
		*pdwAdjacentTo = Fields::FID_X509;
	else if (m_data.ipt)
		*pdwAdjacentTo = Fields::FID_PROMPT;
	else
		*pdwAdjacentTo = Fields::FID_PIN;

	return S_OK;
}

IFACEMETHODIMP VscCredential::GetComboBoxValueCount(__RPC__in DWORD fieldID, __RPC__out DWORD* pcItems, _Deref_out_range_(<, *pcItems) __RPC__out DWORD* pdwSelectedItem)
{
	UNREFERENCED_PARAMETER(fieldID);
	UNREFERENCED_PARAMETER(pcItems);
	UNREFERENCED_PARAMETER(pdwSelectedItem);

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::GetComboBoxValueAt(__RPC__in DWORD fieldID, __RPC__in DWORD dwItem, __RPC__deref_out_opt_string LPWSTR* ppszItem)
{
	UNREFERENCED_PARAMETER(fieldID);
	UNREFERENCED_PARAMETER(dwItem);

	*ppszItem = nullptr;

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::SetStringValue(__RPC__in DWORD fieldID, __RPC__in_string LPCWSTR psz)
{
	try
	{
		switch (fieldID)
		{
		case Fields::FID_PIN:
		case Fields::FID_X509:
			m_strings[fieldID] = psz;
			return S_OK;
		}
		return E_INVALIDARG;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"SetStringValue", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"SetStringValue", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::SetCheckboxValue(__RPC__in DWORD fieldID, __RPC__in BOOL bChecked)
{
	UNREFERENCED_PARAMETER(fieldID);
	UNREFERENCED_PARAMETER(bChecked);

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::SetComboBoxSelectedValue(__RPC__in DWORD fieldID, __RPC__in DWORD dwSelectedItem)
{
	UNREFERENCED_PARAMETER(fieldID);
	UNREFERENCED_PARAMETER(dwSelectedItem);

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::CommandLinkClicked(__RPC__in DWORD fieldID)
{
	UNREFERENCED_PARAMETER(fieldID);

	return E_NOTIMPL;
}

IFACEMETHODIMP VscCredential::GetSerialization(__RPC__out CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE* pcpgsr, __RPC__out CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs, __RPC__deref_out_opt_string LPWSTR* ppszOptionalStatusText, __RPC__out CREDENTIAL_PROVIDER_STATUS_ICON* pcpsiOptionalStatusIcon)
{
	*pcpgsr = CPGSR_NO_CREDENTIAL_NOT_FINISHED;
	*ppszOptionalStatusText = nullptr;
	*pcpsiOptionalStatusIcon = CPSI_NONE;

	try
	{
		if ((pcpgsr == nullptr) || (pcpcs == nullptr))
			return E_INVALIDARG;

		if (m_data.ipt)
		{
			if (m_events2)
				m_events2->BeginFieldUpdates();

			if (m_events)
			{
				m_events->SetFieldState(this, Fields::FID_X509, CPFS_HIDDEN);
				m_events->SetFieldState(this, Fields::FID_PROMPT, CPFS_DISPLAY_IN_SELECTED_TILE);
				Fields::String str;
				str.Resource(IDS_DISPLAYING_IPT);
				m_events->SetFieldString(this, Fields::FID_PROMPT, str);
			}

			if (m_events2)
				m_events2->EndFieldUpdates();

			// cause PIN popup to appear
			DWORD rc = m_data.sign();

			if (m_events2)
				m_events2->BeginFieldUpdates();

			if (m_events)
			{
				CREDENTIAL_PROVIDER_FIELD_STATE cpfs{};
				CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE cpfis{};
				if (SUCCEEDED(GetFieldState(Fields::FID_X509, &cpfs, &cpfis)))
					m_events->SetFieldState(this, Fields::FID_X509, cpfs);
				if (SUCCEEDED(GetFieldState(Fields::FID_PROMPT, &cpfs, &cpfis)))
					m_events->SetFieldState(this, Fields::FID_PROMPT, cpfs);
				m_events->SetFieldString(this, Fields::FID_PROMPT, m_strings[Fields::FID_PROMPT]);
			}

			if (m_events2)
				m_events2->EndFieldUpdates();

			if (rc != SCARD_S_SUCCESS)
			{
				pcpcs->cbSerialization = 0;
				*pcpsiOptionalStatusIcon = CPSI_ERROR;

				Fields::String str;
				switch (rc)
				{
				case SCARD_W_CANCELLED_BY_USER:
					str.Resource(IDS_IPT_CANCELLED);
					break;
				case SCARD_W_CHV_BLOCKED:
					str.Resource(IDS_IPT_BLOCKED);
					break;
				case ERROR_ACCESS_DENIED:
				case SCARD_E_NO_ACCESS:
					str.Resource(IDS_ACCESS_DENIED_IPT);
					break;
				default:
				{
					str.Resource(IDS_IPT_PIN_ERROR);
					m_debug.LogError(L"GetSerialization IPT sign", rc);
					myid::StringList strs{myid::ToHex(rc)};
					//Support::LogEvent(IPT_SIGN_UNKNOWN_ERROR, strs, L"IPTCredentialProvider");
				}
				}
				str.Release(ppszOptionalStatusText);

				return S_OK;
			}
		}

		pcpcs->clsidCredentialProvider = CLSID_VscProvider;

		HRESULT hr = m_data.serialisation(m_cpus, m_strings[Fields::FID_X509], m_strings[Fields::FID_PIN], pcpcs->rgbSerialization, pcpcs->cbSerialization);
		if (SUCCEEDED(hr))
		{
			ULONG authPackage;
			hr = Authenticate::GetAuthPackage(authPackage);
			if (SUCCEEDED(hr))
			{
				pcpcs->ulAuthenticationPackage = authPackage;

				*pcpgsr = CPGSR_RETURN_CREDENTIAL_FINISHED;

#ifdef MYID_DEBUG
				if (m_debug)
				{
					VectorOfByte ser(pcpcs->rgbSerialization, pcpcs->cbSerialization);
					m_debug.LogOK(L"GetSerialization", myid::bin_2_hex(ser));
				}
#endif
			}
		}
		if (FAILED(hr))
		{
			m_debug.LogError(L"GetSerialization", hr);

			pcpcs->cbSerialization = 0;
			*pcpsiOptionalStatusIcon = CPSI_ERROR;
		}

		return hr;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetSerialization", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetSerialization", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::GetUserSid(__RPC__deref_out_opt_string LPWSTR* sid)
{
	*sid = nullptr;

	try
	{
		if (m_data.sid.empty())
		{
#ifdef DEBUG_SID
			m_debug.Log(L"GetUserSid", L"false");
#endif

			__analysis_assume(false);
			return S_FALSE;
		}

		HRESULT hr = SHStrDupW(m_data.sid.c_str(), sid);
		__analysis_assume(hr == S_OK);
#ifdef DEBUG_SID
		m_debug.Log(L"GetUserSid", m_data.sid);
#endif
		return hr;
	}
	catch (myid::Exception& e)
	{
		m_debug.Log(L"GetUserSid", e.message());
	}
	catch (...)
	{
		m_debug.Log(L"GetUserSid", L"unknown exception");
	}

	return E_UNEXPECTED;
}

IFACEMETHODIMP VscCredential::GetFieldOptions(__RPC__in DWORD fieldID, __RPC__out CREDENTIAL_PROVIDER_CREDENTIAL_FIELD_OPTIONS* options)
{
	if (fieldID >= Fields::FID_NUM_FIELDS)
		return E_INVALIDARG;

	if (options == nullptr)
		return E_INVALIDARG;

	*options = CPCFO_NONE;

	switch (fieldID)
	{
	case Fields::FID_PIN:
		*options = CPCFO_ENABLE_PASSWORD_REVEAL;
		break;
	case Fields::FID_IMAGE:
		*options = CPCFO_ENABLE_TOUCH_KEYBOARD_AUTO_INVOKE;
		break;
	}

	return S_OK;
}
