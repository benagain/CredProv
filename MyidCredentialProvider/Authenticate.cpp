#include "stdafx.h"
#include "Authenticate.h"
#include "AuthPackage.h"
#include "CspInfo.h"
#include "..\VscCommon\Support.h"

#include <NTSecAPI.h>
#include <LM.h>

#pragma comment(lib, "Netapi32.lib")

#ifdef DEBUG_WRAP
namespace
{

std::basic_ostream<wchar_t, std::char_traits<wchar_t>>& operator<<(std::basic_ostream<wchar_t, std::char_traits<wchar_t>>& stream, const UNICODE_STRING& us)
{
	stream << us.Length << L" " << us.MaximumLength << L" " << myid::ToHex((ULONG)us.Buffer);
	return stream;
}

std::wstring str(const byte* rgbSerialization, const UNICODE_STRING& us)
{
	return std::wstring((LPCWSTR)&rgbSerialization[(ULONG)us.Buffer], us.Length / sizeof(WCHAR));
}

} // anon namespace
#endif

namespace Authenticate
{

/// Find out if the PC is joined to a domain
bool IsDomainJoined(void)
{
	static bool status(false);

	static myid::lock::CallOnce loaded;
	loaded.Call([]()
	{
		LPWSTR name(nullptr);
		NETSETUP_JOIN_STATUS joined(NetSetupUnknownStatus);
		if (NetGetJoinInformation(nullptr, &name, &joined) == NERR_Success)
		{
			NetApiBufferFree(name);

			status = joined == NetSetupDomainName;
		}
	});

	return status;
}

/// Output contents of CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION
void DebugSerialization(_Inout_ std::wstringstream& stream, _In_opt_ const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs)
{
#ifdef DEBUG_WRAP
	if (pcpcs)
	{
		stream << L"Authentication Package " << myid::ToHex(pcpcs->ulAuthenticationPackage) << L" " << GetAuthPackageName(pcpcs->ulAuthenticationPackage) << L"\n";
		stream << L"Credential Provider " << Support::ToWstr(pcpcs->clsidCredentialProvider) << L"\n";

		if ((pcpcs->cbSerialization > 0) &&
			(pcpcs->rgbSerialization != nullptr))
		{
			VectorOfByte data(pcpcs->rgbSerialization, pcpcs->cbSerialization);
			stream << myid::bin_2_hex(data) << L"\n";
		}
	}
#else
	UNREFERENCED_PARAMETER(stream);
	UNREFERENCED_PARAMETER(pcpcs);
#endif
}

void DebugSerializationKerb(_Inout_ std::wstringstream& stream, _In_opt_ const CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION* pcpcs)
{
#ifdef DEBUG_WRAP
	if (pcpcs)
	{
		if ((pcpcs->cbSerialization > 0) &&
			(pcpcs->rgbSerialization != nullptr))
		{
			KERB_LOGON_SUBMIT_TYPE submitType = *(PKERB_LOGON_SUBMIT_TYPE)pcpcs->rgbSerialization;
			stream << L"Submit type " << submitType << L"\n";
			switch (submitType)
			{
			case KerbCertificateLogon:
			case KerbCertificateUnlockLogon:
			{
				PKERB_CERTIFICATE_LOGON cl = (PKERB_CERTIFICATE_LOGON)pcpcs->rgbSerialization;
				stream << L"DomainName " << cl->DomainName << L" '" << str(pcpcs->rgbSerialization, cl->DomainName) << L"'\n"
					<< L"UserName " << cl->UserName << L" '" << str(pcpcs->rgbSerialization, cl->UserName) << L"'\n"
					<< L"Pin " << cl->Pin << L" '" << str(pcpcs->rgbSerialization, cl->Pin) << L"'\n"
					<< L"Flags " << myid::ToHex(cl->Flags) << L"\n"
					<< L"CSP length " << cl->CspDataLength << L"\n"
					<< L"CSP data " << myid::ToHex((ULONG)cl->CspData) << L"\n";
				byte* cspData = pcpcs->rgbSerialization + (ULONG)cl->CspData;
				PKERB_SMARTCARD_CSP_INFO cspInfo = (PKERB_SMARTCARD_CSP_INFO)cspData;
				stream << L"CSP length " << cspInfo->dwCspInfoLen << L"\n"
					<< L"MessageType " << cspInfo->MessageType << L"\n"
					<< L"Flags " << myid::ToHex(cspInfo->flags) << L"\n"
					<< L"KeySpec " << cspInfo->KeySpec << L"\n";
				LPCWSTR name = &cspInfo->bBuffer;
				stream << L"Card name " << cspInfo->nCardNameOffset << L" " << &name[cspInfo->nCardNameOffset] << L"\n"
					<< L"Reader name " << cspInfo->nReaderNameOffset << L" " << &name[cspInfo->nReaderNameOffset] << L"\n"
					<< L"Container name " << cspInfo->nContainerNameOffset << L" " << &name[cspInfo->nContainerNameOffset] << L"\n"
					<< L"CSPName name " << cspInfo->nCSPNameOffset << L" " << &name[cspInfo->nCSPNameOffset] << L"\n";
				break;
			}
			}
		}
	}
#else
	UNREFERENCED_PARAMETER(stream);
	UNREFERENCED_PARAMETER(pcpcs);
#endif
}

} // namespace Authenticate
