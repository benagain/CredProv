#pragma once

#include <wincrypt.h>

// class to facilitate using the cryptoAPI to logon to the CSP.
// this will prevent the CSP from presenting the user with a 'please enter PIN' dialog.
// Only works, or is required with certain cards, since some do not support this functionality,
// or some will count a pkcs11 login as enough to grant access to the card.

// because different cards work differently - might be that some developer will need to override this class.
class CCSPLogin
{
public:
	CCSPLogin();
	virtual ~CCSPLogin();

	virtual void Login(_In_ const std::wstring &PIN, _In_ const std::wstring &CSPName, _In_ const std::wstring &ReaderName);

	static DWORD ProviderType(_In_ const std::wstring &CSPName);

protected:
	HCRYPTPROV m_hCrypt;

	std::wstring m_sContainerName;
	std::wstring m_sCSPName;
	DWORD		m_providerType;
	bool		m_dummyContainerCreated;
};

