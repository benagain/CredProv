/// Vector hex conversion

#pragma once

#include "../VectorOfBytePtr.h"
#include "HexBinConversion.h"
#ifndef MOBILE
#include "Win\HexBinVectorConversion.h"
#endif

namespace myid
{
	VectorOfBytePtr hex_to_bin(_In_ std::string const& strHex);
	void hex_to_bin(_In_ std::string const& strHex, _Out_ std::string& strOutput);
	void hex_to_bin(_In_ std::string const& strHex, _Out_ VectorOfByte& vecOut);
	std::string bin_to_hex(_In_ VectorOfByte const& bin);
	std::string bin_to_hex(_In_ VectorOfByteConstPtr const& bin);
	std::string bin_to_hex(_In_ std::string const& strIn);

	// convert to a new object
	VectorOfBytePtr hex_2_bin(_In_opt_z_ const wchar_t *pwszHex);
	VectorOfBytePtr hex_2_bin(_In_ const std::wstring& wstrHex);
	std::wstring hex_4_bin(_In_ const std::wstring& wstrHex);
	// convert to existing object
	void hex_2_bin(_In_opt_z_ const wchar_t *pwszHex, _Out_ VectorOfByte& vecOut);
	void hex_2_bin(_In_ const std::wstring& wstrHex, _Out_ VectorOfByte& vecOut);

	void hex_2_bin_ignorewhitespace(_In_ const std::wstring& wstrHex, _Out_ VectorOfByte& vecOut);

	// convert to a new object
	std::wstring bin_2_hex(_In_ VectorOfByte const & vecBin);
	std::wstring bin_4_hex(_In_ const std::wstring& wstrIn);

	// convert to existing object
	void bin_2_hex(_In_ VectorOfByte const & vecBin, _Out_ std::wstring& wstrOutput);
	void bin_4_hex(_In_ const std::wstring& wstrIn, _Out_ std::wstring& wstrOutput);

	// test for hex
	bool isHex(_In_ VectorOfByte const& vecPossibleHex);
	bool isHex(_In_ const std::wstring& wstrPossibleHex);
	bool isHex(_In_ const std::string& wstrPossibleHex);
}
