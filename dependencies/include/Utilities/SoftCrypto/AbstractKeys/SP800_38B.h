#pragma once

#include "AbstractKey.h"

namespace AbstractKeys
{

/** implement CMAC functionality as defined in sp800-38B
http://csrc.nist.gov/publications/nistpubs/800-38B/SP_800-38B.pdf
*/
class SP800_38B
{
public:
	SP800_38B(void);
	virtual ~SP800_38B(void);

	void Initialise(_In_ AbstractKeyPtr symKey, _In_ const size_t nBlockSizeBytes);
	VectorOfBytePtr CMAC(_In_ const VectorOfByte &vecMessage, _In_ const size_t nByteLengthOutput);
	bool CMACVerify(_In_ const VectorOfByte &vecMessage, _In_ const VectorOfByte &vecCMAC);

private:
	void SubkeyGeneration();
	VectorOfByte Xor(_In_ const VectorOfByte &vecData1, _In_ const VectorOfByte &vecData2) const;
	void LShift(_Inout_ VectorOfByte &vecData, _In_ const int nNumBitsToShift) const;
	bool MSBit(_In_ const VectorOfByte &vecData) const;
	void InitialiseRb(_Inout_ VectorOfByte &vecRb) const;
	void MaskFinalBlock(_Inout_ VectorOfByte &vecMessageToMask, _In_ const VectorOfByte &vecMaskingBlock) const;
	void PadToBlockSize(_Inout_ VectorOfByte &vecMessagePad) const;
	void TruncateEncMessageToMAC(_Inout_ VectorOfByte &vecEncMessage, _In_ const size_t nByteLengthOutput) const;

	// as defined in sp800-38b these arent cryptokeys, but really bytestrings
	VectorOfByte m_vecSubkey1; // K1
	VectorOfByte m_vecSubkey2; // K2

	AbstractKeyPtr m_symKey;
	size_t m_nBlockSizeBytes;
};

}
