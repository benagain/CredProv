#include "stdafx.h"
#include "Policy.h"

namespace Data
{
bool Policy::AllowCertificatesWithNoEKU(void) const
{
	return m_AllowCertificatesWithNoEKU;
}

bool Policy::EnumerateECCCerts(void) const
{
	return m_EnumerateECCCerts;
}

bool Policy::AllowSignatureOnlyKeys(void) const
{
	return m_AllowSignatureOnlyKeys;
}

bool Policy::AllowTimeInvalidCertificates(void) const
{
	return m_AllowTimeInvalidCertificates;
}

bool Policy::FilterDuplicateCerts(void) const
{
	return m_FilterDuplicateCerts;
}

bool Policy::ForceReadingAllCertificates(void) const
{
	return m_ForceReadingAllCertificates;
}

bool Policy::ReverseSubject(void) const
{
	return m_ReverseSubject;
}

bool Policy::X509HintsNeeded(void) const
{
	return m_X509HintsNeeded;
}

/// Get the group policy settings
Policy& Policy::Get(void)
{
	Policy& policy = *myid::Instance<Policy>();

	static myid::lock::CallOnce loaded;
	loaded.Call([&policy]()
	{
		ATL::CRegKey reg;
		if (ERROR_SUCCESS == reg.Open(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\SmartCardCredentialProvider", KEY_READ))
		{
			DWORD value;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"AllowCertificatesWithNoEKU", value))
				policy.m_AllowCertificatesWithNoEKU = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"EnumerateECCCerts", value))
				policy.m_EnumerateECCCerts = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"AllowSignatureOnlyKeys", value))
				policy.m_AllowSignatureOnlyKeys = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"AllowTimeInvalidCertificates", value))
				policy.m_AllowTimeInvalidCertificates = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"FilterDuplicateCerts", value))
				policy.m_FilterDuplicateCerts = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"ForceReadingAllCertificates", value))
				policy.m_ForceReadingAllCertificates = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"ReverseSubject", value))
				policy.m_ReverseSubject = value != 0;
			if (ERROR_SUCCESS == reg.QueryDWORDValue(L"X509HintsNeeded", value))
				policy.m_X509HintsNeeded = value != 0;
		}
	});

	return policy;
}

} // namespace Data

