#pragma once

#include <comutil.h>

namespace myid
{

// base 64 conversions using DataExchange
VectorOfBytePtr fromBase64(const _bstr_t& b64);
VectorOfBytePtr fromBase64(const std::string& b64);
VectorOfBytePtr fromBase64(const std::wstring& b64);
void fromBase64(const _bstr_t& b64, VectorOfByte& bin);
void fromBase64(const std::string& b64, VectorOfByte& bin);
void fromBase64(const std::wstring& b64, VectorOfByte& bin);
void fromBase64(const std::wstring& b64, std::wstring& hex);
void fromBase64Hex(const std::wstring& hexb64, VectorOfByte& bin);
void fromBase64Hex(const std::wstring& hexb64, std::wstring& hex);
std::string toBase64String(VectorOfByte const & bin);
std::wstring toBase64Wstr(VectorOfByte const & bin);
void toBase64(const VectorOfByte& bin, _bstr_t& b64);
void toBase64(const VectorOfByte& bin, std::string& b64);
void toBase64(const VectorOfByte& bin, std::wstring& b64);
void toBase64(const std::wstring& hex, std::wstring& b64);
void toBase64Hex(const VectorOfByte& bin, std::wstring& hexb64);

// tests
bool isBase64(_In_ const _bstr_t& b64);
bool stripBase64WhiteSpace(_Inout_ _bstr_t& b64);
}
