#pragma once

#include <comutil.h>
#include <atlbase.h>

namespace myid
{
VectorOfBytePtr hex_2_bin(_In_ const BSTR bstrHex);
VectorOfBytePtr hex_2_bin(_In_ const ATL::CComBSTR& bstrHex);
VectorOfBytePtr hex_2_bin(_In_ const _bstr_t& bstrHex);
_bstr_t hex_4_bin(_In_ const _bstr_t& bstrHex);
void hex_2_bin(_In_ const BSTR bstrHex, _Out_ VectorOfByte& vecOut);
void hex_2_bin(_In_ const _bstr_t& bstrHex, _Out_ VectorOfByte& vecOut);
void hex_2_bin(_In_ const ATL::CComBSTR& bstrHex, _Out_ VectorOfByte& vecOut);
std::wstring bin_4_hex(_In_ const BSTR bstrIn);
void bin_2_hex(_In_ VectorOfByte const & vecBin, _Out_ _bstr_t& bstrOutput);
void bin_4_hex(_In_ const BSTR bstrIn, _Out_ std::wstring& wstrOutput);
void bin_4_hex(_In_ const BSTR bstrIn, _Out_ _bstr_t& bstrOutput);
}
