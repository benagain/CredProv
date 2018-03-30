#pragma once

#include "../VectorOfBytePtr.h"
#include "HexBinVectorConversion.h"
#include "B64Conversion.h"
#include "UTF8Conversion.h"
#ifndef MOBILE
#include"Win\VectorOfByteConversion.h"
#endif

namespace myid
{
	std::string toBinaryRepresentation(_In_ VectorOfByte const & bin);

	// truncated unicode to vector (high order bytes dumped)
	void stdStringToVector(_In_ std::wstring const & strInput, _Out_ VectorOfByte& vecOutput);
	VectorOfByte stdStringToVector(_In_ std::wstring const & strInput);
	VectorOfByte wstringToVector(_In_z_ const wchar_t* wstrInput);
	void wstringToVector(_In_z_ const wchar_t* wstrInput, _Out_ VectorOfByte& vecOutput);

	// char copy to/from vector
	VectorOfBytePtr makeBinary(_In_ std::string const& bytes);
	std::string makeString(_In_ VectorOfByte const& bin);
	std::string makeString(_In_ VectorOfByteConstPtr const& bin);
	void stdStringToVector(_In_ std::string const & strInput, _Out_ VectorOfByte& vecOutput);
	VectorOfByte stdStringToVector(_In_ std::string const & strInput);

	// vector single byte to unicode string
	void VectorToString(_In_ VectorOfByte const & vecInput, _Out_ std::wstring& wstrOutput);
	std::wstring VectorToString(_In_ VectorOfByte const & vecInput);

	// vector pair of bytes to/from unicode string, high order byte first
	void VectorToUnicodeString(_In_ VectorOfByte const & vecInput, _Out_ std::wstring& wstrOutput);
	std::wstring VectorToUnicodeString(_In_ VectorOfByte const & vecInput);
	void stdUnicodeStringToVector(_In_ std::wstring const & strInput, _Out_ VectorOfByte& vecOutput);
	VectorOfBytePtr stdUnicodeStringToVector(_In_ std::wstring const & strInput);

	OKBOOL SecureClear(_Inout_ VectorOfByte& data);
	OKBOOL SecureClear(_Inout_bytecount_(length) void* first, _In_ size_t length);
	OKBOOL SecureClear(_Inout_ std::string& data);
	OKBOOL SecureClear(_Inout_ std::wstring& data);
}

