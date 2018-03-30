#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"

class CPaddingHelper
{
public:
	explicit CPaddingHelper(_In_ const int nBlockSize = 8);
	virtual ~CPaddingHelper(void);

	// DES Padding as used in MyID keyserver database key encryption (rh byte indicates how many bytes of padding are required)
	VectorOfByte Pad_DES_MYID(_In_ const VectorOfByte &vecData);
	VectorOfByte UnPad_DES_MYID(_In_ const VectorOfByte &vecData);

	// DES Padding as defined in OP Card Spec 2.1, section B.4
	VectorOfByte Pad_DES_OP(_In_ const VectorOfByte &vecData);
	VectorOfByte UnPad_DES_OP(_In_ const VectorOfByte &vecData);

	// to make this class usable - must provide an override to RData - to return a vector of random bytes
	//(since this may require expensive initialisation ie RAND_Screen, this is out of scope of this class)
	virtual VectorOfByte RData(_In_ int const nSize) = 0;

	int BlockSize() const { return m_nBlockSize; }

protected:
	int m_nBlockSize;
};

/// concrete version of CPaddingHelper that uses OpenSSL to generate random data
class CPaddingHelperRand : public CPaddingHelper
{
public:
	explicit CPaddingHelperRand(_In_ const int nBlockSize = 8);
	virtual VectorOfByte RData(_In_ int const nSize);
};
