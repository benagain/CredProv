#pragma once

#include "KeyEncoder.h"
#include "KeyStore.h"

namespace KeyStore
{

class RSAPublicKeyData : public RSAPublic, public AbstractKeys::KeyEncoder::IRSAPublicKeyData
{
	typedef RSAPublic inherited;

public:
	RSAPublicKeyData();
	RSAPublicKeyData(_In_ const RSAPublic& rhs);

	virtual void GetPublicExponent(_Out_ VectorOfByte& vecData) const;
	virtual void GetModulus(_Out_ VectorOfByte& vecData) const;
	virtual long GetKeySizeBits() const;
};

class RSAPrivateKeyData : public RSAPrivate, public AbstractKeys::KeyEncoder::IRSAPrivateKeyData
{
	typedef RSAPrivate inherited;

public:
	RSAPrivateKeyData();
	explicit RSAPrivateKeyData(_In_ const RSAPrivate& rhs);

	virtual void GetPublicExponent(_Out_ VectorOfByte& vecData) const;
	virtual void GetModulus(_Out_ VectorOfByte& vecData) const;
	virtual long GetKeySizeBits() const;
	virtual void GetPrime1(_Out_ VectorOfByte& vecData) const;
	virtual void GetPrime2(_Out_ VectorOfByte& vecData) const;
	virtual void GetExponent1(_Out_ VectorOfByte& vecData) const;
	virtual void GetExponent2(_Out_ VectorOfByte& vecData) const;
	virtual void GetCoefficient(_Out_ VectorOfByte& vecData) const;
	virtual void GetPrivateExponent(_Out_ VectorOfByte& vecData) const;
};


class ECCPublicKeyData : public ECCPublic, public AbstractKeys::KeyEncoder::IECCPublicKeyData
{
	typedef ECCPublic inherited;

public:
	ECCPublicKeyData(void);
	ECCPublicKeyData(_In_ const ECCPublic& rhs);

	// IECCPublicKeyData
	virtual void GetPublicKey(_Out_ VectorOfByte &vecData) const; // bignum without compression byte. (e.g. 64 bytes for P256)
	virtual void GetOID(_Out_ std::string &oid) const;
	virtual long GetKeySizeBits() const;
};

class ECCPrivateKeyData : public ECCPrivate, public AbstractKeys::KeyEncoder::IECCPrivateKeyData
{
	typedef ECCPrivate inherited;

public:
	ECCPrivateKeyData();
	ECCPrivateKeyData(_In_ const ECCPrivate& rhs);

	// IECCPublicKeyData
	virtual void GetPublicKey(_Out_ VectorOfByte &vecData) const; // bignum without compression byte. (e.g. 64 bytes for P256)
	virtual void GetOID(_Out_ std::string &oid) const;
	virtual long GetKeySizeBits() const;

	virtual long GetVersion() const=0;
	virtual void GetPrivateKey(_Out_ VectorOfByte &vecData) const=0; // big endian 
};


} // namespace KeyStore

