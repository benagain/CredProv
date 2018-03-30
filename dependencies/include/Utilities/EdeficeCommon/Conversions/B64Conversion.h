#pragma once

#include "../VectorOfBytePtr.h"
#ifdef MOBILE
#include "Mobile/B64Conversion.h"
#else
#include "Win/B64Conversion.h"
#endif

namespace myid
{

// test for base 64
bool isBase64(_In_ VectorOfByte const& b64);
bool isBase64(_In_ const std::wstring& b64);
bool isBase64(_In_ const std::string& b64);
bool isBase64(_In_ char b64);
bool isBase64(_In_ wchar_t b64);

bool stripBase64WhiteSpace(_Inout_ VectorOfByte& b64);
bool stripBase64WhiteSpace(_Inout_ std::wstring& b64);
bool stripBase64WhiteSpace(_Inout_ std::string& b64);

}
