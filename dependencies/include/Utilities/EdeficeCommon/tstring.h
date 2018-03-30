#pragma once

#include <tchar.h>
#include <string>
#include <atlconv.h>
#include "VectorOfByte.h"
#include "BasicTString.h"

/************************************************************************************************

namespace is EdeficeCommon

************************************************************************************************/


namespace EdeficeCommon
{
	// Various flavours of hex/bin conversions for wide, narrow and T strings.

	VectorOfByte hex_to_bin(tstring const & strHex); // throws range_error
	VectorOfByte w_hex_to_bin(std::wstring const & wstrHex); // throws range_error
	VectorOfByte a_hex_to_bin(std::string const & strHex); // throws range_error

	tstring bin_to_hex(VectorOfByte const & vecBin);
	std::wstring w_bin_to_hex(VectorOfByte const & vecBin);
	std::string a_bin_to_hex(VectorOfByte const & vecBin);

	// wrappers for ATL conversion macros

	inline std::wstring const & widestring(std::wstring const &wstrIn)
	{
		return wstrIn;
	}

	inline std::wstring widestring(std::string const &strIn)
	{
		USES_CONVERSION;
		return A2CW(strIn.c_str());
	}

	inline std::string narrowstring(tstring const &tstrIn)
	{
		USES_CONVERSION;
		return T2CA(tstrIn.c_str());
	}

	inline tstring TString(std::wstring const &wstrIn)
	{
		USES_CONVERSION;
		return W2CT(wstrIn.c_str());
	}

	inline tstring TString(std::string const &strIn)
	{
		USES_CONVERSION;
		return A2CT(strIn.c_str());
	}
}
