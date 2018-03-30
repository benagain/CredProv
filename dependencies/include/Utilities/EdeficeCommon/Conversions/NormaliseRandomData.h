#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"

/** Sometimes when random data is generated (as VectorOfByte form), we want to get random data
in some normalised form (e.g. ascii 0-9). This class when fed with random data will normalise
it to a specified byte range*/
class CNormaliseRandomData
{
public:
	CNormaliseRandomData(void);
	virtual ~CNormaliseRandomData(void);

	void SetRandomData(_In_ const VectorOfByte &vecRandomData);
	VectorOfBytePtr GetNormalisedOutput(_In_ const byte byMinimumValue = 0x00, _In_ const byte byMaximumValue = 0xFF);
private:
	byte NormaliseByte(_In_ byte byToNormalise);
	VectorOfByte m_vecRandomData;
	byte m_byMinimumValue;
	byte m_byMaximumValue;
};
