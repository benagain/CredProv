#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"
#include <string>
#ifndef MOBILE
#include "Win\B64ConversionDirect.h"
#endif

namespace myid
{

// base 64 conversions using direct code
// These are much faster than DataExchange,
// for arrays up 1000 bytes about 1000 times faster, around 1Mb about 15 times faster
void base64(_In_ const myid::VectorOfByte& bin, _Out_ std::wstring& b64);
void base64(_In_ const VectorOfBytePtr& bin, _Out_ std::wstring& b64);
void base64(_In_ const myid::VectorOfByte& bin, _Out_ std::string& b64);
void base64(_In_ const VectorOfBytePtr& bin, _Out_ std::string& b64);
OKBOOL base64(_In_ const std::wstring& b64, _Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin);
OKBOOL base64(_In_ const std::string& b64, _Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin);
OKBOOL base64WhiteSpace(_In_ const std::wstring& b64, _Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin);
OKBOOL base64WhiteSpace(_In_ const std::string& b64, _Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin);

void base64urlEncode(_In_ const std::wstring& b64, _Out_ std::wstring& b64url);
void base64urlEncode(_In_ const std::string& b64, _Out_ std::string& b64url);
void base64urlDecode(_In_ const std::wstring& b64url, _Out_ std::wstring& b64);
void base64urlDecode(_In_ const std::string& b64url, _Out_ std::string& b64);

}
