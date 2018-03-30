#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include "Utilities/EdeficeCommon/Status.h"
#include "Utilities/EdeficeCommon/Crypt.h"
typedef struct rsa_st RSA;
typedef struct ec_key_st EC_KEY;
typedef struct evp_pkey_st EVP_PKEY;
#include <boost/shared_ptr.hpp>

#ifndef MOBILE
#include "Win/KeyStore.h"
#endif

/// Key storage interface
namespace KeyStore
{

class RSAPublic;
class RSAPrivate;
class ECCPublic;
class ECCPrivate;

class Key
{
public:
	/// key types
	enum keyTypes
	{
		NONE,					///< undefined
		RSA,					///< RSA
		ECDH,					///< ECC DH
		ECDSA					///< ECC DSA
	};
	/// key pair access types
	enum keyAccess
	{
		NA,						///< not applicable
		PUBLIC,					///< public
		PRIVATE,				///< private
		SECRET					///< secret
	};
	/// key sizes
	enum keySizes
	{
		ZERO = 0,				///< undefined
		RSA1024 = 1024,			///< RSA 1024
		RSA2048 = 2048,			///< RSA 2048
		RSA3072 = 3072,			///< RSA 3072
		RSA4096 = 4096,			///< RSA 4096
		ECC256 = 256,			///< ECC 256
		ECC384 = 384,			///< ECC 384
		ECC521 = 521			///< ECC 521
	};
	/// ASN1 format
	enum asn1
	{
		KEY,					///< RSAPublicKey or RSAPrivateKey from RFC3447
		PKCS1,					///< DisgestInfo from RFC3447
		PKCS8,					///< PrivateKeyInfo from RFC5958
		X509					///< subjectPublicKeyInfo from RFC5280
	};
	class keyType
	{
	public:
		keyType();
		keyType(_In_ keyTypes type, _In_ keyAccess access);
		bool operator==(_In_ keyTypes rhs) const;
		bool operator==(_In_ keyAccess rhs) const;
		bool operator==(_In_ const keyType& rhs) const;
		bool operator!=(_In_ keyTypes rhs) const;
		bool operator!=(_In_ keyAccess rhs) const;
		bool operator!=(_In_ const keyType& rhs) const;
		operator keyTypes() const;
		operator keyAccess() const;
		std::wstring text() const;

	protected:
		myid::Status<keyTypes, NONE> m_types;
		myid::Status<keyAccess, NA> m_access;
	};
	class keySize
	{
	public:
		keySize();
		explicit keySize(_In_ unsigned long size);
		keySize(_In_ keyTypes type, _In_ keySizes size);
		keySize& operator=(_In_ keyTypes type);
		keySize& operator=(_In_ keySizes size);
		bool operator==(_In_ keyTypes rhs) const;
		bool operator==(_In_ keySizes rhs) const;
		bool operator==(_In_ const keySize& rhs) const;
		bool operator!=(_In_ keyTypes rhs) const;
		bool operator!=(_In_ keySizes rhs) const;
		bool operator!=(_In_ const keySize& rhs) const;
		operator keyTypes() const;
		operator keySizes() const;
		std::wstring text() const;
		void bits(_In_ unsigned long size);
		unsigned long bits() const;
		unsigned long bytes() const;

	protected:
		myid::Status<keyTypes, NONE> m_types;
		myid::Status<keySizes, ZERO> m_sizes;
	};

	Key();
	virtual ~Key();

	virtual void Clear(void);
	virtual keyType type(void) const = 0;
	virtual keySize size(void) const = 0;
	virtual bool Initialised(void) const;
	virtual void Initialised(_In_ bool rhs);
	virtual void SetInitialised(void) = 0;

	virtual bool operator==(_In_ const Key& rhs) const;

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs) = 0;
	virtual VectorOfByte CNG(void) const = 0;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs) = 0;
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_RSA_KEYX) const = 0;

	virtual bool OpenSslKey(_In_ const EVP_PKEY* rhs) = 0;
	virtual EVP_PKEY* OpenSslKey(void) const = 0;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = X509) = 0;
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = X509) const = 0;

protected:
	bool		m_initialised;

private:
	void LocalClear(void);
};
typedef boost::shared_ptr<Key> KeyPtr;

/// Generic key container
class KeyContainer : public Key
{
	typedef Key inherited;

public:
	~KeyContainer();

	virtual void Clear(void);
	virtual bool operator==(_In_ const KeyContainer& rhs) const;
	virtual bool Create(_In_ keyType const& type);

	virtual keyType type(void) const;
	virtual keySize size(void) const;
	virtual bool Initialised(void) const;
	virtual void Initialised(_In_ bool rhs);
	virtual void SetInitialised(void);

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CNG(void) const;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_RSA_KEYX) const;

	virtual bool OpenSslKey(_In_ const EVP_PKEY* rhs);
	virtual EVP_PKEY* OpenSslKey(void) const;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = X509);
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = X509) const;

	const RSAPublic* rsaPublic(void) const;
	const RSAPrivate* rsaPrivate(void) const;
	RSAPublic* rsaPublic(void);
	RSAPrivate* rsaPrivate(void);
	const ECCPublic* eccPublic(void) const;
	const ECCPrivate* eccPrivate(void) const;
	ECCPublic* eccPublic(void);
	ECCPrivate* eccPrivate(void);

	KeyPtr		key;

private:
	void LocalClear(void);
};

/// RSA public key
class RSAPublic : public Key
{
	typedef Key inherited;

public:
	RSAPublic();
	~RSAPublic();

	virtual void Clear(void);
	virtual keyType type(void) const;
	virtual keySize size(void) const;

	virtual bool operator==(_In_ const Key& rhs) const;
	virtual bool operator==(_In_ const RSAPublic& rhs) const;

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CNG(void) const;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_RSA_KEYX) const;

	virtual bool OpenSslKey(_In_ const EVP_PKEY* rhs);
	virtual EVP_PKEY* OpenSslKey(void) const;

	virtual bool OpenSslRsa(_In_ const ::RSA* rhs);
	virtual ::RSA* OpenSslRsa(void) const;
	virtual void OpenSslRsaPublic(_Out_ ::RSA* rhs) const;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = X509);
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = X509) const;

	virtual unsigned long BitLength(void) const;
	virtual void BitLength(_In_ unsigned long rhs);
	virtual VectorOfByte Modulus(void) const;
	virtual void Modulus(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte PublicExponent(void) const;
	virtual void PublicExponent(_In_ const VectorOfByte& rhs);

	virtual unsigned long PublicExponentLong(void) const;
	virtual void PublicExponentLong(_In_ unsigned long rhs);
	static unsigned long ConvertPublicExponent(_In_ const VectorOfByte& vecData);
	static VectorOfByte ConvertPublicExponent(_In_ unsigned long data);

	virtual void SetInitialised(void);

	unsigned long	bitLength;
	VectorOfByte	publicExponent;		///< E
	VectorOfByte	modulus;			///< N

protected:
	void Normalise(_Inout_ VectorOfByte& data, _In_ int mult = 1) const;

private:
	void LocalClear(void);
};

/// RSA private key
class RSAPrivate : public RSAPublic
{
	typedef RSAPublic inherited;

public:
	RSAPrivate();
	~RSAPrivate();

	virtual void Clear(void);
	virtual keyType type(void) const;

	virtual bool operator==(_In_ const Key& rhs) const;
	virtual bool operator==(_In_ const RSAPrivate& rhs) const;

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CNG(void) const;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_RSA_KEYX) const;

	virtual bool OpenSslRsa(_In_ const ::RSA* rhs);
	virtual ::RSA* OpenSslRsa(void) const;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = PKCS8);
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = PKCS8) const;

	virtual VectorOfByte Prime1(void) const;
	virtual void Prime1(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Prime2(void) const;
	virtual void Prime2(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Exponent1(void) const;
	virtual void Exponent1(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Exponent2(void) const;
	virtual void Exponent2(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Coefficient(void) const;
	virtual void Coefficient(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte PrivateExponent(void) const;
	virtual void PrivateExponent(_In_ const VectorOfByte& rhs);

	virtual void SetInitialised(void);

	VectorOfByte	prime1;					///< P
	VectorOfByte	prime2;					///< Q
	VectorOfByte	exponent1;				///< DmP-1
	VectorOfByte	exponent2;				///< DmQ-1
	VectorOfByte	coefficient;			///< QmP
	VectorOfByte	privateExponent;		///< D

protected:
	bool			m_public;				///< if true only public part is available

private:
	void LocalClear(void);
};

/// ECC public key
class ECCPublic : public Key
{
	typedef Key inherited;

public:
	ECCPublic();
	~ECCPublic();

	virtual void Clear(void);
	virtual keyType type(void) const;
	virtual keySize size(void) const;
	virtual void size(keySize sz);
	virtual void dsa(bool dsa);

	virtual bool operator==(_In_ const Key& rhs) const;
	virtual bool operator==(_In_ const ECCPublic& rhs) const;

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CNG(void) const;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_ECDH) const;

	virtual bool OpenSslKey(_In_ const EVP_PKEY* rhs);
	virtual EVP_PKEY* OpenSslKey(void) const;

	virtual bool OpenSslEcc(_In_ const ::EC_KEY* rhs);
	virtual ::EC_KEY* OpenSslEcc(void) const;
	virtual void OpenSslEccPublic(_Out_ ::EC_KEY* rhs) const;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = X509);
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = X509) const;

	virtual VectorOfByte X(void) const;
	virtual void X(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Y(void) const;
	virtual void Y(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte Point(void) const;
	virtual void Point(_In_ const VectorOfByte& rhs);

	virtual void SetInitialised(void);

	static bool ASN1Signature(_In_ const VectorOfByte& asn, _In_ unsigned long size, _Out_ VectorOfByte& r, _Out_ VectorOfByte& s);
	static VectorOfByte ASN1Signature(_In_ const VectorOfByte& r, _In_ const VectorOfByte& s);

	keySize			ksize;		///< key type & size
	VectorOfByte	x;			///< X
	VectorOfByte	y;			///< Y

private:
	void LocalClear(void);
};

/// ECC private key
class ECCPrivate : public ECCPublic
{
	typedef ECCPublic inherited;

public:
	ECCPrivate();
	~ECCPrivate();

	virtual void Clear(void);
	virtual keyType type(void) const;

	virtual bool operator==(_In_ const Key& rhs) const;
	virtual bool operator==(_In_ const ECCPrivate& rhs) const;

#ifndef MOBILE
	virtual bool CNG(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CNG(void) const;
#endif

	virtual bool CAPI(_In_ const VectorOfByte& rhs);
	virtual VectorOfByte CAPI(_In_ ALG_ID algId = CALG_ECDH) const;

	virtual bool OpenSslEcc(_In_ const ::EC_KEY* rhs);
	virtual ::EC_KEY* OpenSslEcc(void) const;

	virtual bool ASN1(_In_ const VectorOfByte& rhs, _In_ asn1 algorithm = X509);
	virtual VectorOfByte ASN1(_In_ asn1 algorithm = X509) const;

	virtual VectorOfByte PrivateKey(void) const;
	virtual void PrivateKey(_In_ const VectorOfByte& rhs);

	virtual void SetInitialised(void);

	VectorOfByte	prv;			///< private key

protected:
	bool			m_public;				///< if true only public part is available

private:
	void LocalClear(void);
};

/// Support for CAPI RSA keys
struct RsaPublicKey
{
	PUBLICKEYSTRUC publicKey;
	RSAPUBKEY RSAPubKey;
	const byte* data() const { return (const byte*)(this + 1); }
};

} // namespace KeyStore
