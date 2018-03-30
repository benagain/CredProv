#pragma once

#include "../UTF8Conversion.h"

namespace myid
{
	std::string ToStr(const wchar_t* in)
	{
		if ((in == NULL) || (*in == 0))
			return std::string();

		return StringToUTF8String(in);
	}

	/// Convert to std::string
	std::string ToStr(const std::wstring& in)
	{
		return StringToUTF8String(in);
	}

	std::wstring ToWstr(const char* in)
	{
		if ((in == NULL) || (*in == 0))
			return std::wstring();

		return UTF8StringToString(in);
	}

	/// Convert to std::wstring
	std::wstring ToWstr(const std::string& in)
	{
		return UTF8StringToString(in);
	}
}
