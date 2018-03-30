/** \file
 * Global operator functions
 */

#pragma once

#include "VS2005Fix.h"

#ifndef MOBILE
#include "Win\GlobalOperator.h"
#endif

//----------------------------------------------------------------
// operator +=

std::wstring operator+=(_In_opt_z_ const wchar_t* lhs, _In_ const std::wstring& rhs);
std::string operator+=(_In_opt_z_ const char* lhs, _In_ const std::string& rhs);

//----------------------------------------------------------------
// operator <<
// These allow strings to behave like a stream, but with none of the fancy stream stuff
// Using them avoids the temporary object creation that operator+ performs
// They also allow for all common source types found in myid

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const std::wstring& rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const std::string& rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_opt_z_ const wchar_t* rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_opt_z_ const char* rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ bool rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ char rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ wchar_t rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ int rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ long rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ unsigned long rhs);

std::string& operator<<(_Inout_ std::string& lhs, _In_ const std::wstring& rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ const std::string& rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_opt_z_ const wchar_t* rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_opt_z_ const char* rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ bool rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ char rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ wchar_t rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ int rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ long rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ unsigned long rhs);


