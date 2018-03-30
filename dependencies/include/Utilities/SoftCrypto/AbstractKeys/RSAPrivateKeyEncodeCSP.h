#pragma once

#include "KeyEncoder.h"


namespace AbstractKeys
{

namespace KeyEncoder
{

/** Microsoft PRIVATEKEYBLOB format containing RSA private key.*/
class RSAPrivateKeyEncodeCSP : public IRSAPrivateKeyData, public IKeyEncoder
{
public:
	RSAPrivateKeyEncodeCSP(void);
	virtual ~RSAPrivateKeyEncodeCSP();

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

	// Overloads of interface methods for convenience
	virtual VectorOfBytePtr GetPublicExponent(void) const;
	virtual VectorOfBytePtr GetModulus(void) const;
	virtual VectorOfBytePtr GetPrime1(void) const;
	virtual VectorOfBytePtr GetPrime2(void) const;
	virtual VectorOfBytePtr GetExponent1(void) const;
	virtual VectorOfBytePtr GetExponent2(void) const;
	virtual VectorOfBytePtr GetCoefficient(void) const;
	virtual VectorOfBytePtr GetPrivateExponent(void) const;

private:
	// CSPPRIVATEKEYBLOB format
	VectorOfByte m_vecPrivateKey; 

	long m_lKeypairBitSize;
	DWORD m_lPublicExponent;
	BYTE *m_pModulus;

	void ClearData();
};

} //namespace KeyEncoder

} //namespace AbstractKeys

