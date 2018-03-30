#pragma once

#include "wincrypt.h"

namespace AbstractKeys
{

class CRSAKeyHelperCSP
{
public:
	CRSAKeyHelperCSP(void);
	virtual ~CRSAKeyHelperCSP(void);

	void Generate(_In_ const long lKeySizeBits, _In_ bool bExportable);
	void Import(_In_ const VectorOfByte &vecPrivateKeyBlob, _In_ bool bExportable);

	void GetPrivateKeyBlob(_Out_ VectorOfByte &vecData);
	void GetPublicKeyBlob(_Out_ VectorOfByte &vecData);

	void DeleteKey();

	HCRYPTPROV AcquireContext();
	HCRYPTKEY GetCryptKey() { return m_hKey; };

	std::wstring GetCSPName() const;
	std::wstring GetContainerName() const;
protected:
	std::wstring m_wstrCSPName;
	std::wstring m_wstrContainerName;
	HCRYPTPROV m_hCrypt;
	HCRYPTKEY m_hKey;

	void ExtractPrivateKey();
	void ExtractPublicKeyBlob(_Out_ VectorOfByte &vecPubKeyBlob);
	BOOL ExtractPublicOrPrivateKey(_Out_ VectorOfByte &vecData, _In_ const DWORD dwCryptKeyType);

	VectorOfByte m_vecPubKeyBlob;
};

}
