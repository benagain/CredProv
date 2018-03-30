#pragma once

#include <comdef.h>
#include <atlcomcli.h>

namespace myid
{
	// -----------------------------------------------------
	// ToBstr & ToBSTR

	/// Create a _bstr_t from an std string
	template< typename T >
	inline _bstr_t ToBstr(_In_ const std::basic_string<T>& in)
	{
		return in.c_str();
	}

	BSTR ToBSTR(_In_ const std::string& in);
	BSTR ToBSTR(_In_ const std::wstring& in);

	// -----------------------------------------------------
	// ToStr

	std::string ToStr(_In_ const _bstr_t& in);
	std::string ToStr(_In_ ATL::CComBSTR const& in);
	std::string ToStr(_In_ const _variant_t& in);
	std::string ToStr(_In_ ATL::CComVariant const& in);

	// -----------------------------------------------------
	// ToWstr

	std::wstring ToWstr(_In_ const _bstr_t& in);
	std::wstring ToWstr(_In_ ATL::CComBSTR const& in);
	std::wstring ToWstr(_In_ const _variant_t& in);
	std::wstring ToWstr(_In_ ATL::CComVariant const& in);
}
