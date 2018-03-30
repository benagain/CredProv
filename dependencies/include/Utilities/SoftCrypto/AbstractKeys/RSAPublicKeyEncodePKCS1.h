#pragma once

#include "KeyEncoder.h"

namespace AbstractKeys
{

namespace KeyEncoder
{
/** PKCS1 RSA public key is ASN1 - following format
SEQUENCE {
	INT 0
	SEQUENCE {
		OID 1.2.840.113549.1.1.1 = RSA PKCS 1 Encryption
		NULL
	}
	OCTET wraps	{
		RSAPublicKey ::= SEQUENCE 
		{
		modulus INTEGER, -- n
		publicExponent INTEGER, -- e
		}
	}
}
*/
class RSAPublicKeyEncodePKCS1 : public IRSAPublicKeyData, public IKeyEncoder
{
public:
	RSAPublicKeyEncodePKCS1(void);
	virtual ~RSAPublicKeyEncodePKCS1();

	// IRSAPublicKeyData
	virtual void GetPublicExponent(VectorOfByte &vecData) const;
	virtual void GetModulus(VectorOfByte &vecData) const;

	virtual long GetKeySizeBits() const;

	//IKeyEncoder
	virtual void GetEncodedData(VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(const VectorOfByte &vecEncodedKey);
	virtual void SetKey(const IKeyData &key);

private:
	VectorOfByte m_vecPublicExponent, m_vecModulus;
	bool m_bInitialised;
	long m_lKeypairBitSize;

	size_t NormaliseComponent(VectorOfByte &vecComponent, bool bAllowOverrunOneByte) const;
	void DeleteKey();
};

} //namespace KeyEncoder

} //namespace AbstractKeys

