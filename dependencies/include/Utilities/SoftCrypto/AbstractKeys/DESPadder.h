#pragma once

#include "..\PaddingHelper.h"
#include ".\AbstractKeyParameters.h"
#include ".\abstractkey.h"

namespace AbstractKeys
{

/** internal helper class designed to perform DES padding and unpadding operations for AbstractKeys classes*/
class SymmetricPadder 
{
public:
	SymmetricPadder(CPaddingHelper &padHelper);
	virtual ~SymmetricPadder(void);

	const VectorOfByte &PadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
											VectorOfByte &vecPaddedData,
											const VectorOfByte &dataToPad);
	VectorOfBytePtr UnpadIfRequired(const SymmetricCryptParameters::SymmetricPadding &nPadding, 
											VectorOfBytePtr vecData);

protected:
	CPaddingHelper &m_padHelper;
};

/// SymmetricPadder used to be DESPadder. Keep DESPadder alive for legacy code
class DESPadder : public SymmetricPadder
{
public:
	DESPadder(CPaddingHelper &padHelper) : SymmetricPadder(padHelper) {}
};

}