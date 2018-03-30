#pragma once

#include "KeyEncoder.h"


namespace AbstractKeys
{

namespace KeyEncoder
{
/** class that can be initialised with mod and pubexp, to allow subsequent retrieval using another format (such as RSAPublicKeyEncodeCSP) */
class RSAPublicKeyHolder : public IRSAPublicKeyData
{
private:
	VectorOfByte m_vecPubExp;
	VectorOfByte m_vecModulus;
public:
	RSAPublicKeyHolder(const VectorOfByte &vecModulus, const VectorOfByte &vecPubExp) : m_vecModulus(vecModulus), m_vecPubExp(vecPubExp) {}

	virtual void GetPublicExponent(VectorOfByte &vecData) const { vecData = m_vecPubExp; }
	virtual void GetModulus(VectorOfByte &vecData) const {vecData = m_vecModulus;}

	virtual long GetKeySizeBits() const {return static_cast<long>(m_vecModulus.size()) * 8;}
};

/** Microsoft PUBLICKEYBLOB format containing RSA private key.*/
class RSAPublicKeyEncodeCSP : public IRSAPublicKeyData, public IKeyEncoder
{
public:
	RSAPublicKeyEncodeCSP(void);
	virtual ~RSAPublicKeyEncodeCSP();

	// IRSAPublicKeyData
	virtual void GetPublicExponent(VectorOfByte &vecData) const;
	virtual void GetModulus(VectorOfByte &vecData) const;

	virtual long GetKeySizeBits() const;

	//IKeyEncoder
	virtual void GetEncodedData(VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(const VectorOfByte &vecEncodedKey);
	virtual void SetKey(const IKeyData &key);

	//helpers
	static VectorOfByte PubExpToVectorOfByte(const DWORD dwPubExp);
	static DWORD PubExpToDWORD(const VectorOfByte &vecPubExp);

	static void CopyKeyComponent(byte *pDestination, VectorOfByte &vecSource, const long lNewKeySize, const bool bHalfSize);
	static void NormaliseSize(VectorOfByte &vecSourceLittleEndian, const size_t nComponentSize);

private:
	// CSPPUBLICKEYBLOB format
	VectorOfByte m_vecPublicKey; 

	long m_lKeypairBitSize;
	DWORD m_lPublicExponent;
	BYTE *m_pModulus;

	void ClearData();
};

} //namespace KeyEncoder

} //namespace AbstractKeys

