#pragma once

#include <string>
#include <list>
#include <openssl/x509.h>
#include "Utilities/EdeficeCommon/StringList.h"
#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include "../AbstractKeys/KeyStore.h"

namespace Certificate
{
	class Certificate;
}

namespace PKCS_Utilities
{

::EVP_PKEY* createKeys(_In_ const std::wstring &keyAlgorithmName, _In_ unsigned long keySize);
OKBOOL createPKCS10Request(_In_ const std::wstring& hashAlgorithmName, _In_ const std::wstring& subjectDN, _In_::EVP_PKEY *keys, _Out_ std::wstring& pkcs10, _Inout_ std::wstring& error);
OKBOOL createPKCS10RequestForSigningWithPlatformKeys(_In_ const std::wstring& subjectDN, _In_::EVP_PKEY *keys, _Out_ std::vector<unsigned char>& digest, _Out_ X509_REQ** request, _Inout_ std::wstring& error);
OKBOOL createPKCS12(_In_ const VectorOfByte& derCertificate, _In_::EVP_PKEY *privateKey, _In_ const std::string& password, _In_ const std::string& friendlyName, _Out_ VectorOfByte& pkcs12, _Inout_ std::wstring& error);
OKBOOL createPKCS12(_In_ const Certificate::Certificate& certificate, _In_ const VectorOfByte& privateKeyData, _Inout_ KeyStore::KeyContainer& privateKeyContainer, _In_ const std::string& pkcs12Password, _Out_ VectorOfByte& pkcs12Result, _Inout_ std::wstring& error);
OKBOOL checkSinglePKCS7tag(_In_ const VectorOfByte& data);
OKBOOL createTemporaryPassword(_Inout_ VectorOfByte& newPassword, _In_ unsigned char passwordLength = 32);
void splitDN(_In_ const std::wstring& subjectDN, _Inout_ myid::StringList& fields, _Inout_ myid::StringList& values);
void reverseDN(_Inout_ myid::StringList& fields, _Inout_ myid::StringList& values);


/// Pfx container, with a vector of byte for the certificate data and a private key container
class Pfx : public VectorOfByte, public KeyStore::KeyContainer
{
public:
	Pfx();
	Pfx(_In_ const VectorOfByte& pkcs12, _In_ const std::string& password, _In_ bool fips = true);
	Pfx(_In_ const VectorOfByte& certificate, _In_ const KeyStore::KeyContainer& key);

	OKBOOL Load(_In_ const VectorOfByte& pkcs12, _In_ const std::string& password, _In_ bool fips = true);
	void Load(_In_ const VectorOfByte& certificate, _In_ const KeyStore::KeyContainer& key);

	OKBOOL Create(_In_ const std::string& friendlyName, _In_ const std::string& password, _Out_ VectorOfByte& pkcs12, _Inout_ std::wstring& error) const;

	bool VerifyKey(_Inout_ std::wstring& error) const;
	OKBOOL PKCS8(_In_ const VectorOfByte& pkcs12, _In_ const std::string& password, _Out_ VectorOfByte& pkcs8, _In_ bool fips = true);

	std::list<VectorOfBytePtr> chain;		///< certificate chain
};

} // namespace PKCS_Utilities
