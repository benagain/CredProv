#pragma once

#include <comutil.h>

namespace myid
{

void base64(_In_ const myid::VectorOfByte& bin, _Out_ _bstr_t& b64);
OKBOOL base64(_In_ const _bstr_t& b64, _Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin);

}
