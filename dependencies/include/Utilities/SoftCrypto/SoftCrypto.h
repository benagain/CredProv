#pragma once
/// Soft Cryptographic routines library

#include <algorithm>
#include <malloc.h>
#include "time.h"


#include "OpenSSL\rsa.h"
#include "OpenSSL\sha.h"
#include "OpenSSL\rand.h"
#include "OpenSSL\err.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Errors.h"
#include "Utilities\EdeficeCommon\Exceptions\ErrorException.h"
#include "AbstractKeys/AbstractKey.h"

#include "PaddingHelper.h"
#include "SoftCryptoDES.h"

namespace SoftCryptoLib
{

class SoftCryptoException : public myid::ErrorException
{
		typedef myid::ErrorException inherited;

public:
	
	SoftCryptoException(_In_ myid::Localisation const& location, _In_ long reason);
	virtual ~SoftCryptoException() throw();

protected:
	virtual std::wstring getErrorText(void) const;
};

} // namespace SoftCryptoLib


class SoftCrypto : public SoftCryptoDES
{
// OPEN SSL
public:
	enum KeyType { SignKey, EncryptKey };
	enum DesMethod { DesEcb, DesCbc };

	enum PBEKeyType { TripleDES112, TripleDES168 };

public:
	SoftCrypto();

	void SetRsaStatus(KeyType key, bool bStatus);
	bool isRsaKeySet(KeyType key);

	bool GenRsaKeyPair(KeyType const & key, int const & nKeySizeBits, std::string const & strExponent);

	VectorOfByte RsaPublicEncrypt(KeyType const & key, VectorOfByte const & vecBinDataIn);
	VectorOfByte RsaPublicDecrypt(KeyType const & key, VectorOfByte const & vecBinDataIn);
	VectorOfByte RsaPrivateDecrypt(KeyType const & key, VectorOfByte const & vecBinDataIn);
	VectorOfByte RsaPrivateEncrypt(KeyType const & key, VectorOfByte const & vecBinDataIn);

	VectorOfByte TripleDesEncrypt(VectorOfByte const & vecDataIn);
	VectorOfByte TripleDesDecrypt(VectorOfByte const & vecDataIn);

	static VectorOfByte HashSHA1(VectorOfByte const& vecDataIn);
	static VectorOfByte HashSHA256(VectorOfByte const& vecDataIn);
	static VectorOfByte HashSHA384(VectorOfByte const& vecDataIn);
	static VectorOfByte HashSHA512(VectorOfByte const& vecDataIn);
	static VectorOfByte HashNamed(VectorOfByte const& vecDataIn, std::wstring const & hashSystem);

	bool SetRsaKeyPair(KeyType const & key, VectorOfByte const & vecPublic, VectorOfByte const & vecPriv, std::string const & Exponent);
	bool SetRsaPublicKey(KeyType const & key, VectorOfByte const & vecPublic, std::string const & Exponent);
	bool SetRsaPrivateKey(KeyType const & key, VectorOfByte const & vecPriv, std::string const & Exponent);
	
	void SetDesMethod( DesMethod method );

	bool GetRsaKeyPair(KeyType const & key, VectorOfByte & vecPublic, VectorOfByte & vecPriv, std::string & Exponent);

	bool GenPBEKey(std::wstring const & password, VectorOfByte const & salt, unsigned long iterCount, PBEKeyType keyType);

	/// Stores an RSA key pair, or just the public or private part if required
	class KeyPair
	{
	public:
		VectorOfByte m_PrivateKey;		///< the private key
		VectorOfByte m_PublicKey;		///< the public key
		std::string m_Exponent;			///< common exponent (65537)
		bool m_PrivateSet;				///< is the private key set?
		bool m_PublicSet;				///< is the public key set?

		KeyPair();
		~KeyPair();
		void Clear(void);
		void SetRsaStatus(bool bStatus, bool bPublic);
		bool isRsaKeySet(bool bPublic);
	};

	bool isRsaKeySet(KeyType key, bool bPublic);

	bool RsaLoopBackTest(KeyType const & key);

	VectorOfByte des_pad(VectorOfByte const & vecBuffer);
	VectorOfByte des_unpad(VectorOfByte const & vecBuffer);

	virtual VectorOfByte RData(int const nSize);

	VectorOfByte PBE_F(VectorOfByte const & password, VectorOfByte const & salt, unsigned long iterCount, unsigned long block);

	KeyPair    m_SignKey;			///< an RSA key pair
	KeyPair    m_EncryptKey;		///< an RSA key pair

	DesMethod  m_DesMethod;
	bool       m_padDesData;


// CRYPTO API
public:
	VectorOfByte GenerateSecretKey(std::wstring const & wstrKeyType);
};

/// main high level Hash
class Hash
{
public:
	static VectorOfByte SHA1(_In_ VectorOfByte const& vecDataIn);
	static VectorOfByte SHA256(_In_ VectorOfByte const& vecDataIn);
	static VectorOfByte SHA384(_In_ VectorOfByte const& vecDataIn);
	static VectorOfByte SHA512(_In_ VectorOfByte const& vecDataIn);
	static VectorOfByte SHA(_In_ VectorOfByte const& vecDataIn, _In_ const AbstractKeys::CryptParameters::HashType hashType);
	static VectorOfByte SHA(_In_ VectorOfByte const& vecDataIn, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ int iterations);
	static VectorOfByte Named(_In_ VectorOfByte const& vecDataIn, _In_ std::wstring const & hashSystem);
	static VectorOfByte Named(_In_ VectorOfByte const& vecDataIn, _In_ std::wstring const & hashSystem, _In_ int iterations);
};

/// Main high level random interface
class Random
{
public:
	static void Seed();
	static VectorOfByte Bytes(_In_ int bytes);
	static VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes);

	template< typename T >
	static void Value(_Out_ T& value)
	{
		VectorOfByte vec(Bytes((int)sizeof(T)));
		value = *reinterpret_cast<const T*>(vec.ptr());
	}
};

/// Password based key derivation as defined by RFC2898 (PKCS5) and NIST SP800-132
class PBKDF2
{
public:
	static VectorOfByte Derive(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ unsigned long length, _In_ int iterations);
	static VectorOfByte DerivePKCS5(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ unsigned long length, _In_ int iterations = 2048);
};
