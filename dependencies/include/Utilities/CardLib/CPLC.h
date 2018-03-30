#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include <stdint.h>

namespace scard
{

class CPLC
{
public:
	class Date
	{
	public:
		Date();
		Date(_In_ uint16_t rhs);
		std::wstring str(void) const;
		uint16_t year(void) const;
		uint16_t days(void) const;
		OKBOOL get(_Out_ int& month, _Out_ int& day) const;

		uint16_t date;
	};

	CPLC();
	CPLC(_In_ const VectorOfByte& rhs);

	OKBOOL TLV(_In_ const VectorOfByte& reply);

	uint16_t Fabricator(void) const;
	uint16_t Type(void) const;
	uint16_t OperatingSystemID(void) const;
	Date OperatingReleaseDate(void) const;
	uint16_t OperatingReleaseLevel(void) const;
	Date FabricationDate(void) const;
	uint32_t SerialNumber(void) const;
	uint16_t BatchID(void) const;
	uint16_t ModuleFabricator(void) const;
	Date ModulePackDate(void) const;
	uint16_t ICCManufacturer(void) const;
	Date EmbeddingDate(void) const;
	uint16_t PrePerso(void) const;
	Date PrePersoDate(void) const;
	uint32_t PrePersoID(void) const;
	uint16_t Perso(void) const;
	Date PersoDate(void) const;
	uint32_t PersoID(void) const;

	void CUID(_Inout_ VectorOfByte& cuid) const;
	void LongSerialNumber(_Inout_ VectorOfByte& sn) const;

	static void AddTo(_Inout_ VectorOfByte& vec, _In_ uint16_t data);
	static void AddTo(_Inout_ VectorOfByte& vec, _In_ uint32_t data);

	byte cplc[42];
};
} // namespace scard
