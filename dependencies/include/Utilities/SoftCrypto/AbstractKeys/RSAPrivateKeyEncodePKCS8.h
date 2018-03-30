#pragma once

#include "KeyEncoder.h"

namespace AbstractKeys
{

namespace KeyEncoder
{
/** PKCS8 RSA private key is ASN1 - following format
SEQUENCE {
	INT 0
	SEQUENCE {
		OID 1.2.840.113549.1.1.1 = RSA PKCS 1 Encryption
		NULL
	}
	OCTET wraps	{
		RSAPrivateKey ::= SEQUENCE 
		{
		version Version (0),
		modulus INTEGER, -- n
		publicExponent INTEGER, -- e
		privateExponent INTEGER, -- d
		prime1 INTEGER, -- p
		prime2 INTEGER, -- q
		exponent1 INTEGER, -- d mod (p-1)
		exponent2 INTEGER, -- d mod (q-1)
		coefficient INTEGER -- (inverse of q) mod p
		}
	}
}
*/
class RSAPrivateKeyEncodePKCS8 : public IRSAPrivateKeyData, public IKeyEncoder
{
public:
	RSAPrivateKeyEncodePKCS8(void);
	virtual ~RSAPrivateKeyEncodePKCS8();

	// IRSAPrivateKeyData
	virtual void GetPublicExponent(VectorOfByte &vecData) const;
	virtual void GetModulus(VectorOfByte &vecData) const;
	virtual void GetPrime1(VectorOfByte &vecData) const;
	virtual void GetPrime2(VectorOfByte &vecData) const;
	virtual void GetExponent1(VectorOfByte &vecData) const;
	virtual void GetExponent2(VectorOfByte &vecData) const;
	virtual void GetCoefficient(VectorOfByte &vecData) const;
	virtual void GetPrivateExponent(VectorOfByte &vecData) const;

	virtual long GetKeySizeBits() const;

	//IKeyEncoder
	virtual void GetEncodedData(VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(const VectorOfByte &vecEncodedKey);
	virtual void SetKey(const IKeyData &key);

private:
	VectorOfByte m_vecPublicExponent, m_vecModulus, m_vecPrime1, m_vecPrime2, m_vecExp1, m_vecExp2, m_vecCoeff, m_vecPrivateExp;
	bool m_bInitialised;
	long m_lKeypairBitSize;

	size_t NormaliseComponent(VectorOfByte &vecComponent, bool bAllowOverrunOneByte) const;
	void DeleteKey();
};

} //namespace KeyEncoder

} //namespace AbstractKeys

