#pragma once

#include <stdlib.h>
#include <string>
#include "../VectorOfByte.h"

namespace myid
{
// To UTF8
bool StringToUTF8Vector(_In_ const std::wstring& strInput, _Out_ VectorOfByte& vecOutput, _In_ bool terminate = false);
VectorOfByte StringToUTF8Vector(_In_ const std::wstring& strInput, _In_ bool terminate = false);
bool StringToUTF8String(_In_ const std::wstring& strInput, _Out_ std::string& strOutput);
std::string StringToUTF8String(_In_ const std::wstring& strInput);
bool StringToUTF8String(_In_ const std::wstring& strInput, byte* strOutput);
size_t UTF8Length(_In_ const std::wstring& strInput);

// From UTF8
bool UTF8VectorToString(_In_ const VectorOfByte& vecInput, _Out_ std::wstring& strOutput);
std::wstring UTF8VectorToString(_In_ const VectorOfByte& vecInput);
bool UTF8StringToString(_In_ const std::string& strInput, _Out_ std::wstring& strOutput);
std::wstring UTF8StringToString(_In_ const std::string& strInput);
bool UTF8StringToString(_In_z_count_(sz) const byte* strInput, _In_ size_t sz, _Out_ std::wstring& strOutput);
size_t UTF8Length(_In_z_count_(sz) const byte* strInput, _In_ size_t sz);
}
