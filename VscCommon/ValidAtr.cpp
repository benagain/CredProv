#include "stdafx.h"
#include "VscApi.h"
#include "ValidAtr.h"

namespace
{
/// Intercede VSC fixed ATRs
/// \note 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65 is Intercede
/// Historical is custom Compact TLV
/// \li 0 Intercede
/// \li 1 byte 0 0, byte 1 type from Process::VscType

/// Map ATRs to Vsc types
const DWORD ATR_SIZE = 17;
struct atrs
{
	Process::ATR atr;			///< ATR
	DWORD len;					///< length of ATR
	Process::VscType type;		///< Vsc type
} ATR[(unsigned int)Process::VscType::MaxNum] =
{
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x00, 0xD4 }, ATR_SIZE, Process::VscType::CNG },
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x01, 0xD5 }, ATR_SIZE, Process::VscType::TPM },
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x02, 0xD6 }, ATR_SIZE, Process::VscType::CSP },
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x03, 0xD7 }, ATR_SIZE, Process::VscType::IPT },
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x04, 0xD0 }, ATR_SIZE, Process::VscType::ITL },
	{ { 0x3B, 0x8D, 0x01, 0x09, 0x49, 0x6E, 0x74, 0x65, 0x72, 0x63, 0x65, 0x64, 0x65, 0x12, 0x00, 0x05, 0xD1 }, ATR_SIZE, Process::VscType::ECC },
};
}

namespace ValidAtr
{

/// Check the ATR is recognised
/// \return true if recognised
bool Valid(
	_In_reads_(atrLen) const PBYTE atr,				///< ATR to test
	_In_ DWORD atrLen)								///< length of ATR
{
	if (atr != nullptr)
	{
		for (int a = 0; a < static_cast<int>(Process::VscType::MaxNum); ++a)
		{
			if (atrLen != ATR[a].len)
				continue;

			if (memcmp(atr, ATR[a].atr, atrLen) == 0)
				return true;
		}
	}

	return false;
}

/// Get the ATR for a Vsc type
/// \return status
DWORD Get(
	_In_ Process::VscType type,		///< Vsc type
	_Out_ Process::ATR* atr,		///< ATR for type
	_Out_ DWORD* atrLen)			///< length of ATR
{
	if ((atr == nullptr) || (atrLen == nullptr))
		return Errors::SC_E_INVALID_PARAMETER;

	memset(*atr, 0, sizeof(*atr));
	*atrLen = 0;

	for (int a = 0; a < static_cast<int>(Process::VscType::MaxNum); ++a)
	{
		if (ATR[a].type == type)
		{
			memcpy_s(*atr, sizeof(Process::ATR), ATR[a].atr, ATR[a].len);
			*atrLen = ATR[a].len;

			return SCARD_S_SUCCESS;
		}
	}

	return Errors::SC_E_INVALID_PARAMETER;
}

/// Get the ATR type
Process::VscType Type(_In_ const VectorOfByte& atr)
{
	size_t len = atr.size();
	if (len > 0)
	{
		for (int a = 0; a < static_cast<int>(Process::VscType::MaxNum); ++a)
		{
			if (ATR[a].len == len)
			{
				if (memcmp(atr.data(), ATR[a].atr, len) == 0)
					return ATR[a].type;
			}
		}
	}

	return Process::VscType::Undefined;
}

} // namespace ValidAtr
