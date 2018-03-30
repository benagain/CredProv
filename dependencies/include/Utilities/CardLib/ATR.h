/// \file ATR.h
/// ATR handling

#pragma once

#include "Utilities/CardLib/APDUVector.h"

namespace scard
{
/// Conversion from FI to F and Fs
/// \note from table 6 of ISO7816-3
struct ATR_CLOCK_RATE
{
	const char* F;		///< Clock rate conversion factor
	const char* Fs;		///< fs (max) MHz
};

/// Conversion from DI to D
/// \note from table 7 of ISO7816-3
struct ATR_BIT_RATE
{
	const char* D;		///< Bit rate adjustment factor
};

extern ATR_CLOCK_RATE ATR_CLOCK_RATE_Table[16];
extern ATR_BIT_RATE ATR_BIT_RATE_Table[16];

const int ATR_MAX_SIZE = 32;			///< maximum size of an ATR

/// ATR
class ATR
{
public:
	ATR();
	explicit ATR(_In_ const ATR& rhs);
	explicit ATR(_In_ const VectorOfByte& rhs);
	ATR& clear(void);

	ATR& operator=(_In_ const ATR& rhs);
	ATR& operator=(_In_ const VectorOfByte& rhs);

	operator VectorOfByte() const;
	operator byte*();
	operator const byte*() const;
	operator unsigned long*();
	operator unsigned long() const;
#ifdef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	operator bool(void) const;
#else
	explicit operator bool(void) const;
#endif
	bool operator!() const;
	byte& operator[](_In_ int pos);
	const byte& operator[](_In_ int pos) const;

	VectorOfByte HistoricATR(void) const;
	bool ExtendedAPDU(void) const;
	bool Simplex(void) const;
	OKBOOL Verify(_Out_ std::wstring& reason) const;
	apdu::ApduCommand InitialAccess(void) const;
	OKBOOL Match(_In_z_ const wchar_t* atr, _In_opt_z_ const wchar_t* mask = nullptr) const;

	static VectorOfByte HistoricATR(_In_ const VectorOfByte& atr);
	static bool ExtendedAPDU(_In_ const VectorOfByte& atr);
	static bool Simplex(_In_ const VectorOfByte& atr);
	static OKBOOL Verify(_In_ const VectorOfByte& atr, _Out_ std::wstring& reason);
	static apdu::ApduCommand InitialAccess(_In_ const VectorOfByte& atr);
	static OKBOOL Match(_In_ const VectorOfByte& match, _In_z_ const wchar_t* atr, _In_opt_z_ const wchar_t* mask = nullptr);

protected:
	byte			m_atr[ATR_MAX_SIZE];	///< ATR data
	unsigned long	m_atr_len;				///< valid length of ATR
};
} // namespace scard
