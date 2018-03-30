#pragma once

#include "../CommonKey.h"
#include "../AbstractKeys/KeyStore.h"
#include "../AbstractKeys/AbstractKeyParameters.h"
#include "Utilities/EdeficeCommon/Conversions/OpenSSLptr.h"
#include <boost/noncopyable.hpp>

namespace OpenSSLCrypt
{

class RsaKey : public MyCrypto::RsaKey, public MyCrypto::KeyPair, private boost::noncopyable
{
public:
	static OKBOOL Create(_Out_ KeyStore::RSAPrivate& key, _In_ unsigned long size = 2048);
	static OKBOOL Create(_Out_ KeyStore::RSAPrivate& key, _In_ unsigned long size, _In_ unsigned long exponent);
	static OKBOOL Create(_Out_ KeyStore::RSAPrivate& key, _In_ unsigned long size, _In_ const VectorOfByte& exponent);
	static OKBOOL Create(_Out_ KeyStore::RSAPrivate& key, _In_ const AbstractKeys::RSAKeyParameters& keyParameters);

	RsaKey();

	virtual KeyStore::RSAPrivate exportPrivateKey(void) const;
	virtual KeyStore::RSAPublic exportPublicKey(void) const;
	virtual OKBOOL importPrivateKey(_In_ const KeyStore::RSAPrivate& key);
	virtual OKBOOL importPublicKey(_In_ const KeyStore::RSAPublic& key);
	virtual bool hasKey(void) const { return pairHasKey(); }
	virtual unsigned long blockSize(void) const { return pairBlockSize(); }

	virtual OKBOOL create(_In_ unsigned long size = 2048);
	virtual OKBOOL create(_In_ unsigned long size, _In_ unsigned long exponent);
	virtual OKBOOL create(_In_ unsigned long size, _In_ const VectorOfByte& exponent);
	virtual OKBOOL create(_In_ const AbstractKeys::RSAKeyParameters& keyParameters);

	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte sign(_In_ const VectorOfByte& hash, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual bool verify(_In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_ const AbstractKeys::RSACryptParameters& crypt);

	virtual VectorOfByte public_encrypt(_In_ const VectorOfByte &data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte private_encrypt(_In_ const VectorOfByte &data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte public_decrypt(_In_ const VectorOfByte &data, _In_ const AbstractKeys::RSACryptParameters& crypt);
	virtual VectorOfByte private_decrypt(_In_ const VectorOfByte &data, _In_ const AbstractKeys::RSACryptParameters& crypt);

	static int hashAlgorithm(_In_ const AbstractKeys::CryptParameters::HashParameter& crypt);

protected:
	virtual unsigned long pairBlockSize(void) const;
	static int paddingMode(_In_ const AbstractKeys::RSACryptParameters& crypt);

	OpenSSL::RSA	m_rsa;				///< the key pair
};

} // namespace OpenSSLCrypt
