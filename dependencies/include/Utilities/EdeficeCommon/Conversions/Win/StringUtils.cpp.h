#pragma once

#include <comdef.h>
#include <atlconv.h>
#include <atlcomcli.h>
#include "Utilities\EdeficeCommon\GlobalOperator.h"

namespace myid
{
// -----------------------------------------------------
// ToBstr & ToBSTR

/// Gets a detached BSTR for COM return values
BSTR ToBSTR(_In_ const std::string& in)
{
	return ::SysAllocString(ATL::CA2W(in.c_str()));
}

/// Gets a detached BSTR for COM return values
BSTR ToBSTR(_In_ const std::wstring& in)
{
	return ::SysAllocString(in.c_str());
}

// -----------------------------------------------------
// ToStr

/// Convert to std::string, copes with NULLs
std::string ToStr(_In_opt_z_ const wchar_t* in)
{
	if ((in == NULL) || (*in == 0))
		return std::string();

	return std::string(ATL::CW2A(in));
}

/// Convert to std::string
std::string ToStr(_In_ const std::wstring& in)
{
	return ToStr(in.c_str());
}

/// Convert to std::string, copes with empty input
std::string ToStr(_In_ const _bstr_t& in)
{
	if (in.length() == 0)
		return std::string();
	return (char*)in;
}

/// Convert to std::string, copes with empty input
std::string ToStr(_In_ ATL::CComBSTR const& in)
{
	if (in.Length() == 0)
		return std::string();
	return ToStr((LPCWSTR)in);
}

/// Convert to std::string, copes with empty input
std::string ToStr(_In_ const _variant_t& in)
{
	std::string rtn;
	rtn << in;
	return rtn;
}

/// Convert to std::string
std::string ToStr(_In_ ATL::CComVariant const& in)
{
	std::string rtn;
	rtn << in;
	return rtn;
}

// -----------------------------------------------------
// ToWstr

/// Convert to std::wstring, copes with NULLs
std::wstring ToWstr(_In_opt_z_ const char* in)
{
	if ((in == NULL) || (*in == 0))
		return std::wstring();

	return std::wstring(ATL::CA2W(in));
}

/// Convert to std::wstring
std::wstring ToWstr(_In_ const std::string& in)
{
	return ToWstr(in.c_str());
}

/// Convert to std::wstring, copes with empty input
std::wstring ToWstr(_In_ const _bstr_t& in)
{
	if (in.length() == 0)
		return std::wstring();
	return (wchar_t*)in;
}

/// Convert to std::wstring, copes with empty input
std::wstring ToWstr(_In_ ATL::CComBSTR const& in)
{
	if (in.Length() == 0)
		return std::wstring();
	return std::wstring(in);
}

/// Convert to std::string, copes with empty input
std::wstring ToWstr(_In_ const _variant_t& in)
{
	std::wstring rtn;
	rtn << in;
	return rtn;
}

/// Convert to std::wstring
std::wstring ToWstr(_In_ ATL::CComVariant const& in)
{
	std::wstring rtn;
	rtn << in;
	return rtn;
}
}
