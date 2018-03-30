#include "stdafx.h"
#include "AuthPackage.h"

#define SECURITY_WIN32
#include <NTSecAPI.h>
#include <security.h>

#pragma comment(lib, "Secur32.lib")

namespace Authenticate
{

/// Get the current authentication package
HRESULT GetAuthPackage(_Out_ ULONG& authPackage)	///< auth package
{
	authPackage = 0;

	HANDLE hLsa(nullptr);
	NTSTATUS status = LsaConnectUntrusted(&hLsa);
	HRESULT hr = HRESULT_FROM_NT(status);
	if (SUCCEEDED(hr))
	{
		LSA_STRING name{};
		name.Buffer = NEGOSSP_NAME_A;
		name.Length = (USHORT)strlen(name.Buffer);
		name.MaximumLength = name.Length + 1;

		ULONG auth(0);
		status = LsaLookupAuthenticationPackage(hLsa, &name, &auth);
		hr = HRESULT_FROM_NT(status);
		if (SUCCEEDED(hr))
		{
			authPackage = auth;
			hr = S_OK;
		}

		LsaDeregisterLogonProcess(hLsa);
	}

	return hr;
}

/// Get authentication package name
std::wstring GetAuthPackageName(_In_ ULONG authPackage)			///< auth package
{
	std::wstring name;

	HANDLE hLsa(nullptr);
	NTSTATUS status = LsaConnectUntrusted(&hLsa);
	HRESULT hr = HRESULT_FROM_NT(status);
	if (SUCCEEDED(hr))
	{
		LSA_STRING names[3]{};
		names[0].Buffer = NEGOSSP_NAME_A;
		names[1].Buffer = MICROSOFT_KERBEROS_NAME_A;
		names[2].Buffer = NTLMSP_NAME_A;
		for (auto& n : names)
		{
			n.Length = (USHORT)strlen(n.Buffer);
			n.MaximumLength = n.Length + 1;
		}

		for (auto& n : names)
		{
			ULONG auth(0);
			status = LsaLookupAuthenticationPackage(hLsa, &n, &auth);
			hr = HRESULT_FROM_NT(status);
			if (SUCCEEDED(hr))
			{
				if (auth == authPackage)
				{
					name = myid::ToWstr(n.Buffer);
					break;
				}
			}
		}

		LsaDeregisterLogonProcess(hLsa);
	}

	return name;
}

} // namespace Authenticate
