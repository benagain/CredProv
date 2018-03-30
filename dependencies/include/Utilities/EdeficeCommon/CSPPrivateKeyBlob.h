#pragma once

#include "VectorOfBytePtr.h"

class CCSPPrivateKeyBlob
{
public:
	CCSPPrivateKeyBlob();
	virtual ~CCSPPrivateKeyBlob();

	enum EncodingType {EncodeCSP, EncodeP11};
	bool Load(const VectorOfByte &vecUnencryptedPrivateKey);

	void SetEncodingType(EncodingType encode);

	// accessors to get at the components
	DWORD GetPublicExponent() const;
	void GetPublicExponent(VectorOfByte &vecData) const;
	void GetModulus(VectorOfByte &vecData) const;
	void GetPrime1(VectorOfByte &vecData) const;
	void GetPrime2(VectorOfByte &vecData) const;
	void GetExponent1(VectorOfByte &vecData) const;
	void GetExponent2(VectorOfByte &vecData) const;
	void GetCoefficient(VectorOfByte &vecData) const;
	void GetPrivateExponent(VectorOfByte &vecData) const;

	long GetKeypairBitSize() const;

	void GetPrivateKeyBlob(VectorOfByte &vecData) const;

protected:
	VectorOfByte m_vecPrivateKey;
	long m_lKeypairBitSize;
	DWORD m_lPublicExponent;
	BYTE *m_pModulus;

	bool m_bInitialised;

	EncodingType m_EncodingType;
};

