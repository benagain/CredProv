#include "stdafx.h"
#include "Data.h"
#include "Policy.h"
#include "..\VscCommon\VscMiniDriverSCard.h"
#include "CspInfo.h"
#include "Utilities\SoftCrypto\WinCrypt\CertHandle.h"
#include "Utilities\EdeficeCommon\OIDDefs.h"
#include <NTSecAPI.h>

#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "Crypt32.lib")

namespace Data
{

namespace
{

/// Protect a string using CredProtect()
HRESULT Protect(
	_In_ const std::wstring& in,		///< input string
	_Out_ std::wstring& out)			///< protected string
{
	CRED_PROTECTION_TYPE protectionType;
	if (CredIsProtected((LPWSTR)in.c_str(), &protectionType))
	{
		if (protectionType != CredUnprotected)
		{
			out = in;
			return S_OK;
		}
	}

	out.clear();
	DWORD rc(0);
	DWORD maxChars(0);
	if (!CredProtect(FALSE, (LPWSTR)in.c_str(), (DWORD)in.size() + 1, nullptr, &maxChars, nullptr))
	{
		rc = GetLastError();
		if (rc == ERROR_INSUFFICIENT_BUFFER)
			rc = 0;
		else
			return HRESULT_FROM_WIN32(rc);
	}

	out.resize(maxChars - 1);
	if (!CredProtect(FALSE, (LPWSTR)in.c_str(), (DWORD)in.size() + 1, (LPWSTR)out.c_str(), &maxChars, nullptr))
	{
		rc = GetLastError();
		return HRESULT_FROM_WIN32(rc);
	}

	return S_OK;
}

} // anon namespace

//====================================================================================================================================
//====================================================================================================================================

/// clear the data
void Credential::clear()
{
	Reader::clear();

	name.clear();
	user.clear();
	container.clear();
	showUser = true;
	signedIn = false;
	certTemplate.clear();
	certVersion = 0;
	memset(certHash, 0, sizeof(certHash));
	certExpiry.dwLowDateTime = 0;
	certExpiry.dwHighDateTime = 0;
	keySpec = 0;
}

/// This does a dummy sign which should cause the PIN dialog to appear.
/// The PIN is then cached by Intel so that it does not appear when inconvenient.
DWORD Credential::sign() const
{
	VscMD::MiniDriverSCard md;
	if (!md.Connect(reader) ||
		!md.Acquire())
		return false;

	md.LoadCertificate(keySpec == AT_SIGNATURE);

	return md.TestSign(keySpec, container);
}

/// Get the certificate details using MS code
bool Credential::certificate(const VectorOfByte& certData)		///< certificate data
{
	clear();

	if (certData.empty())
		return false;

	CertStore::CertContext context((PCCERT_CONTEXT)CertCreateContext(CERT_STORE_CERTIFICATE_CONTEXT, X509_ASN_ENCODING, certData.ptr(), certData.lsize(), CERT_CREATE_CONTEXT_NOCOPY_FLAG, nullptr));
	if (!context)
		return false;

	if (!Policy::Get().AllowTimeInvalidCertificates())
	{
		if (CertVerifyTimeValidity(nullptr, context->pCertInfo) != 0)
			return false;
	}

	if (!Policy::Get().EnumerateECCCerts())
	{
		if (OIDS::EccPublicKey == context->pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId)
			return false;
	}

	BYTE usage;
	CertGetIntendedKeyUsage(X509_ASN_ENCODING, context->pCertInfo, &usage, 1);
	if ((usage & CERT_DIGITAL_SIGNATURE_KEY_USAGE) == 0)
		return false;

	bool mslogon(false);
	bool eku(false);
	DWORD enhSize(0);
	if (CertGetEnhancedKeyUsage(context, 0, nullptr, &enhSize))
	{
		VectorOfByte enhData(enhSize);
		PCERT_ENHKEY_USAGE enh = (PCERT_ENHKEY_USAGE)enhData.ptr();
		if (CertGetEnhancedKeyUsage(context, 0, enh, &enhSize))
		{
			if (enh->cUsageIdentifier == 0)
			{
				if (GetLastError() == CRYPT_E_NOT_FOUND)
					eku = true;
			}
			else
			{
				for (DWORD u = 0; u < enh->cUsageIdentifier; ++u)
				{
					if (OIDS::MSSmartCardLogon == enh->rgpszUsageIdentifier[u])
					{
						mslogon = true;
						break;
					}
					if ((OIDS::AnyExtendedKeyUsage == enh->rgpszUsageIdentifier[u]) ||
						(OIDS::ClientAuthentication == enh->rgpszUsageIdentifier[u]))
						eku = true;
				}
			}
		}
	}
	if (!mslogon)
	{
		if (!eku || !Policy::Get().AllowCertificatesWithNoEKU())
			return false;
	}

	WCHAR value[500] = {L""};
	CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, nullptr, value, 500);
	name = value;

	value[0] = 0;
	CertGetNameString(context, CERT_NAME_UPN_TYPE, 0, nullptr, value, 500);
	if (value[0])
	{
		user = value;
	}
	else
	{
		DWORD flags = 0;
		flags = CERT_X500_NAME_STR;
		if (Policy::Get().ReverseSubject())
			flags |= CERT_NAME_STR_REVERSE_FLAG;
		CertNameToStr(X509_ASN_ENCODING, &context->pCertInfo->Subject, flags, value, 500);
		user = value;
	}

	PCERT_EXTENSION templateExt = CertFindExtension(szOID_CERTIFICATE_TEMPLATE, context->pCertInfo->cExtension, context->pCertInfo->rgExtension);
	if (templateExt)
	{
		PCERT_TEMPLATE_EXT templ(nullptr);
		DWORD templSize(0);
		if (CryptDecodeObjectEx(X509_ASN_ENCODING, X509_CERTIFICATE_TEMPLATE, templateExt->Value.pbData, templateExt->Value.cbData, CRYPT_DECODE_ALLOC_FLAG, nullptr, &templ, &templSize))
		{
			certTemplate = templ->pszObjId;
			certVersion = templ->dwMajorVersion;
			LocalFree(templ);
		}
	}

	DWORD cbData(CERT_HASH_LENGTH);
	CertGetCertificateContextProperty(context, CERT_HASH_PROP_ID, certHash, &cbData);

	certExpiry = context->pCertInfo->NotAfter;

	return true;
}

/// Produce logon serialisation block
/// \note The structure of this block is very particular
HRESULT Credential::serialisation(
	_In_ CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus,
	_In_opt_z_ LPCWSTR hint,		///< X509 hint
	_In_opt_z_ LPCWSTR pin,			///< PIN
	_Out_ byte*& data,				///< where to put the data
	_Out_ ULONG& dataSize)			///< data size
{
	data = nullptr;
	dataSize = 0;

	std::wstring cspName = MS_SCARD_PROV;
	VectorOfByte cspInfoData;
	cspInfoData.resize(sizeof(KERB_SMARTCARD_CSP_INFO) - sizeof(TCHAR) +
		(4 + reader.size() + card.size() + container.size() + cspName.size()) * sizeof(WCHAR), 0);

	PKERB_SMARTCARD_CSP_INFO cspInfo = (PKERB_SMARTCARD_CSP_INFO)cspInfoData.ptr();
	cspInfo->dwCspInfoLen = cspInfoData.lsize();
	cspInfo->MessageType = 1;
	cspInfo->flags = 0;
	cspInfo->KeySpec = keySpec;
	cspInfo->nCardNameOffset = 0;
	cspInfo->nReaderNameOffset = (ULONG)card.size() + cspInfo->nCardNameOffset + 1;
	cspInfo->nContainerNameOffset = (ULONG)reader.size() + cspInfo->nReaderNameOffset + 1;
	cspInfo->nCSPNameOffset = (ULONG)container.size() + cspInfo->nContainerNameOffset + 1;
	TCHAR* buffer = &cspInfo->bBuffer;

	memcpy(buffer + cspInfo->nCardNameOffset, card.c_str(), card.size() * sizeof(WCHAR));
	memcpy(buffer + cspInfo->nReaderNameOffset, reader.c_str(), reader.size() * sizeof(WCHAR));
	memcpy(buffer + cspInfo->nContainerNameOffset, container.c_str(), container.size() * sizeof(WCHAR));
	memcpy(buffer + cspInfo->nCSPNameOffset, cspName.c_str(), cspName.size() * sizeof(WCHAR));

	std::wstring domainName, userName;
	if (Data::Policy::Get().X509HintsNeeded())
	{
		userName = myid::ToWstr(hint);
		size_t pos = userName.find(L'\\');
		if ((pos != std::wstring::npos) && (pos > 0))
		{
			domainName = userName.substr(0, pos);
			userName = userName.substr(pos + 1);
		}
	}

	std::wstring unprotPin, protPin;
	if (!ipt)
		unprotPin = myid::ToWstr(pin);

	HRESULT hr = Protect(unprotPin, protPin);
	if (FAILED(hr))
		return hr;

	ULONG offset(0);
	switch (cpus)
	{
	case CPUS_LOGON:
	case CPUS_CREDUI:
		offset = sizeof(KERB_CERTIFICATE_LOGON);
		break;
	case CPUS_UNLOCK_WORKSTATION:
		offset = sizeof(KERB_CERTIFICATE_UNLOCK_LOGON);
		break;
	default:
		return S_FALSE;
	}

	// 7 for packing adjustment
	dataSize = (ULONG)(offset + (domainName.size() + userName.size() + protPin.size() + 3) * sizeof(WCHAR) + cspInfoData.lsize() + 7);
	data = (byte*)CoTaskMemAlloc(dataSize);
	if (data == nullptr)
		return E_OUTOFMEMORY;

	ZeroMemory(data, dataSize);

	PKERB_CERTIFICATE_LOGON logon = (PKERB_CERTIFICATE_LOGON)data;

	switch (cpus)
	{
	case CPUS_LOGON:
	case CPUS_CREDUI:
		logon->MessageType = KerbCertificateLogon;
		break;
	case CPUS_UNLOCK_WORKSTATION:
		logon->MessageType = KerbCertificateUnlockLogon;
		break;
	}

	if (!domainName.empty())
	{
		logon->DomainName.Length = (USHORT)domainName.size() * sizeof(WCHAR);
		logon->DomainName.MaximumLength = logon->DomainName.Length + sizeof(WCHAR);
		memcpy(data + offset, domainName.c_str(), domainName.size() * sizeof(WCHAR));
	}
	logon->DomainName.Buffer = (PWSTR)offset;
	offset += logon->DomainName.MaximumLength;

	if (!userName.empty())
	{
		logon->UserName.Length = (USHORT)userName.size() * sizeof(WCHAR);
		logon->UserName.MaximumLength = logon->UserName.Length + sizeof(WCHAR);
		memcpy(data + offset, userName.c_str(), userName.size() * sizeof(WCHAR));
	}
	logon->UserName.Buffer = (PWSTR)offset;
	offset += logon->UserName.MaximumLength;

	if (!protPin.empty())
	{
		logon->Pin.Length = (USHORT)protPin.size() * sizeof(WCHAR);
		logon->Pin.MaximumLength = logon->Pin.Length + sizeof(WCHAR);
		memcpy(data + offset, protPin.c_str(), protPin.size() * sizeof(WCHAR));
	}
	logon->Pin.Buffer = (PWSTR)offset;
	offset += logon->Pin.MaximumLength;

	offset = (offset + 7) & ~(size_t)7;		// adjust packing
	logon->CspDataLength = cspInfoData.lsize();
	logon->CspData = (PUCHAR)offset;
	memcpy(data + offset, cspInfoData.ptr(), cspInfoData.size());
	offset += cspInfoData.lsize();
	if (offset > dataSize)
		return HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW);
	dataSize = offset;

	return S_OK;
}

} // namespace Data
