#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <boost/config.hpp>
#include "SalFix.h"

namespace myid
{

class MultiString;

/// A vector of strings
class StringList : public std::vector<std::wstring>
{
	typedef std::vector<std::wstring> inherited;

public:
	StringList();
	// cppcheck-suppress noExplicitConstructor
	StringList(_In_ const StringList& rhs);
	explicit StringList(_In_ const inherited& rhs);
	explicit StringList(_In_ const MultiString& rhs);
	StringList(_In_reads_opt_z_(len) const wchar_t* in, _In_ size_t len);
	StringList(_In_ const std::wstring& in, _In_ wchar_t split);
	StringList(_In_ const std::wstring& in, _In_ const std::wstring& split);
	StringList(_In_opt_z_ const wchar_t* in, _In_ wchar_t split);
	StringList(_In_opt_z_ const wchar_t* in, _In_opt_z_ const wchar_t* split);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	// cppcheck-suppress noExplicitConstructor
	StringList(_In_ std::initializer_list<const wchar_t*> rhs);
	// cppcheck-suppress noExplicitConstructor
	StringList(_In_ std::initializer_list<std::wstring> rhs);
#endif

	StringList& operator=(_In_ const StringList& rhs);
	StringList& operator=(_In_ const inherited& rhs);
	StringList& operator=(_In_ const MultiString& rhs);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	StringList& operator=(_In_ std::initializer_list<const wchar_t*> rhs);
	StringList& operator=(_In_ std::initializer_list<std::wstring> rhs);
#endif

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
	explicit StringList(_Inout_ StringList&& rhs);
	StringList(_Inout_ inherited&& rhs);
	StringList& operator=(_Inout_ StringList&& rhs);
	StringList& operator=(_Inout_ inherited&& rhs);
#endif

	StringList& Make(_In_reads_opt_z_(len) const wchar_t* in, _In_ size_t len);
	StringList& Make(_In_ const MultiString& in);
	MultiString Make(void) const;
	StringList& Split(_In_ const std::wstring& in, _In_ wchar_t split);
	StringList& Split(_In_ const std::wstring& in, _In_ const std::wstring& split);
	StringList& Split(_In_opt_z_ const wchar_t* in, _In_ wchar_t split);
	StringList& Split(_In_opt_z_ const wchar_t* in, _In_opt_z_ const wchar_t* split);

	std::wstring Combine(_In_ const std::wstring& sep = L"") const;
};

StringList ToStringList(_In_reads_opt_z_(len) const wchar_t* in, _In_ size_t len);
StringList SplitString(_In_ const std::wstring& in, _In_ wchar_t split);
StringList SplitString(_In_opt_z_ const wchar_t* in, _In_ wchar_t split);

/// A Windows multi-string. This contains strings separated by one 0 and terminated by two 0
class MultiString : public std::vector<wchar_t>
{
	typedef std::vector<wchar_t> inherited;

public:
	MultiString();
	// cppcheck-suppress noExplicitConstructor
	MultiString(_In_ const MultiString& rhs);
	explicit MultiString(_In_ const StringList& rhs);
	explicit MultiString(_In_ const inherited& rhs);
	explicit MultiString(_In_opt_z_ const wchar_t* rhs);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	// cppcheck-suppress noExplicitConstructor
	MultiString(_In_ std::initializer_list<const wchar_t*> rhs);
	// cppcheck-suppress noExplicitConstructor
	MultiString(_In_ std::initializer_list<std::wstring> rhs);
#endif

	MultiString& operator=(_In_ const MultiString& rhs);
	MultiString& operator=(_In_ const StringList& rhs);
	MultiString& operator=(_In_ const inherited& rhs);
	MultiString& operator=(_In_opt_z_ const wchar_t* rhs);
#ifndef BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
	MultiString& operator=(_In_ std::initializer_list<const wchar_t*> rhs);
	MultiString& operator=(_In_ std::initializer_list<std::wstring> rhs);
#endif

	reference operator[](_In_ int _Pos);
	const_reference operator[](_In_ int _Pos) const;

	MultiString& set(_In_opt_z_ const wchar_t* in);
	MultiString& set(_In_opt_z_ const wchar_t* in, _In_ size_t len);

	operator wchar_t*();
	operator const wchar_t*() const;
};

} // namespace myid

typedef myid::StringList StringList;
typedef std::vector<long> LongList;

