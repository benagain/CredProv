#pragma once

#include "wincrypt.h"
#include "../OpenSSL/OpenSSLEccKey.h"

namespace AbstractKeys
{

class ECCKeyHelper
{
public:
	ECCKeyHelper(void);
	virtual ~ECCKeyHelper(void);

	void Generate(_In_ const long lKeySizeBits, _In_ bool bExportable);
	void Import(_In_ const VectorOfByte &vecPrivateKeyBlob, _In_ bool bExportable);

	void GetPrivateKeyBlob(_Out_ VectorOfByte &vecData);
	void GetPublicKeyBlob(_Out_ VectorOfByte &vecData);

	void DeleteKey();

	std::wstring GetContainerName() const;
protected:
	std::wstring m_wstrContainerName;

	MyCrypto::EccKeyPtr		m_key;
};

}
