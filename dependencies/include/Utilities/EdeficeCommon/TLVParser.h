#pragma once

#include "VectorOfByte.h"

// helper class for parsing TLV format data
//originally came from CTLVFormat in edeficeSmartcard before moving into eCommon
class CTLVParser
{
public:
	CTLVParser();
	explicit CTLVParser(_In_ VectorOfByte const& dataBlock);
	virtual ~CTLVParser();

	VectorOfByte m_vecTLVDataBlock; // can be accessed directly to populate with binary TLV data

	OKBOOL FindDataObject(_In_ const byte byTagToFind, _Out_ VectorOfByte &vecDataContained) const;
	OKBOOL FindDataObject(_In_ const VectorOfByte &vecTagToFind, _Out_ VectorOfByte &vecDataContained) const;

private:
	// cppcheck-suppress unusedPrivateFunction
	DWORD ReadLength(_Inout_ long& lOffset) const;
};
