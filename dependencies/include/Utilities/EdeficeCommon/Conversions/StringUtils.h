#pragma once

#include "../VS2005Fix.h"
#include <string>
#include <vector>
#include <wchar.h>
#ifndef MOBILE
#include "Win\StringUtils.h"
#endif

namespace myid
{
std::string ToStr(_In_opt_z_ const char* in);
std::string ToStr(_In_opt_z_ const wchar_t* in);
std::string ToStr(_In_ const std::string& in);
std::string ToStr(_In_ const std::wstring& in);
std::wstring ToWstr(_In_opt_z_ const wchar_t* in);
std::wstring ToWstr(_In_opt_z_ const char* in);
std::wstring ToWstr(_In_ const std::string& in);
std::wstring ToWstr(_In_ const std::wstring& in);

bool isWstr(_In_opt_z_ const wchar_t* in);
bool isWstr(_In_ const std::wstring& in);

std::string FindAndReplace(_In_ std::string const & input, _In_ std::string const & match, _In_ std::string const & replace);
std::wstring FindAndReplace(_In_ std::wstring const & input, _In_ std::wstring const & match, _In_ std::wstring const & replace);

void RemoveLineBreaksInPlace(_Inout_ std::wstring& input);
std::wstring RemoveLineBreaks(_In_ const std::wstring& input);

std::string ChangeCase(_In_ const std::string& input, _In_ bool ToLower = true);
std::wstring ChangeCase(_In_ const std::wstring& input, _In_ bool ToLower = true);

std::vector<std::string> split(_In_ const std::string& input, _In_ char s, _In_ bool empty = true);
std::vector<std::wstring> split(_In_ const std::wstring& input, _In_ wchar_t s, _In_ bool empty = true);
std::vector<std::string> split(_In_ const std::string& input, _In_ const std::string& s, _In_ bool empty = true);
std::vector<std::wstring> split(_In_ const std::wstring& input, _In_ const std::wstring& s, _In_ bool empty = true);
std::vector<std::string> splitAny(_In_ const std::string& input, _In_ const std::string& s, _In_ bool empty = true);
std::vector<std::wstring> splitAny(_In_ const std::wstring& input, _In_ const std::wstring& s, _In_ bool empty = true);
}
