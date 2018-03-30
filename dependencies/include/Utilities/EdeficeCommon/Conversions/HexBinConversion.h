#pragma once
#include <stdlib.h>
#include "../VectorOfByte.h"
#include "../Exceptions/LocalisedException.h"

namespace myid
{

template <typename _in, typename _out> _out fromHex(_In_ _in in, _Out_ _out& out)
{
	out = static_cast<_out>(in);
	if (in >= '0' && in <= '9')      out -= '0';
	else if (in >= 'a' && in <= 'f') out -= 'a' - 10;
	else if (in >= 'A' && in <= 'F') out -= 'A' - 10;
	else
		throw myid::LocalisedException(LOCALISE_FN_STATIC, L"Invalid char in hex string");
	return out;
}

inline void hex_bin(_Inout_ byte& ch)
{
	fromHex(ch, ch);
}

template <typename _in, typename _out> _out toHex(_In_ _in in, _Out_ _out& out)
{
	_in c = in & 0x0f;
	out = static_cast<_out>(c + (c < 10 ? '0' : 'A' - 10));
	return out;
}

inline byte bin_hex(_In_ byte ch)
{
	byte b;
	return toHex(ch, b);
}

/// Test if the character is hex
template <typename _ch> bool isHex(_In_ _ch hex)
{
	return (hex >= '0' && hex <= '9') ||
		   (hex >= 'A' && hex <= 'F') ||
		   (hex >= 'a' && hex <= 'f');
}

// base conversion - all these require the output buffer to be allocated
void bin_2_hex(_In_ size_t length, _In_count_(length) const byte* in, _Out_cap_(length * 2 + 1) wchar_t* out);
void bin_to_hex(_In_ size_t length, _In_count_(length) const byte* in, _Out_cap_(length * 2 + 1) char* out);
void bin_to_hex(_In_ size_t length, _In_count_(length) const char* in, _Out_cap_(length * 2 + 1) char* out);
void bin_4_hex(_In_ size_t length, _In_count_(length) const wchar_t* in, _Out_cap_(length * 4 + 1) wchar_t* out);

/// conversion from integral types to string
template <typename _chout, typename _chin> void ToHex(_In_ _chin in, _Out_ _chout* out)
{
	for (int s = sizeof(_chin)*8 - 4; s >= 0; s -= 4)
	{
		toHex((byte)(in >> s), *(out++));
	}
	*out = '\0';
}

/// conversion from integral types to STL string
template <typename _chout, typename _chin> void ToHex(_In_ _chin in, _Out_ std::basic_string<_chout>& out)
{
	_chout _out[17];			// enough for __int64
	ToHex(in, _out);
	out = _out;
}

/// conversion from integral types
template <typename _ch> std::wstring ToHex(_In_ _ch in)
{
	wchar_t out[17];			// enough for __int64
	ToHex(in, out);
	return out;
}

/// conversion from integral types
template <typename _ch> std::string ToSHex(_In_ _ch in)
{
	char out[17];			// enough for __int64
	ToHex(in, out);
	return out;
}

void hex_2_bin(_In_ size_t length, _In_count_(length * 2) const wchar_t* in, _Out_cap_(length) byte* out);
void hex_2_bin(_In_ size_t length, _In_count_(length * 2) const wchar_t* in, _Out_cap_(length) wchar_t* out);
void hex_4_bin(_In_ size_t length, _In_count_(length * 4) const wchar_t* in, _Out_cap_(length) wchar_t* out);
void hex_to_bin(_In_ size_t length, _In_count_(length * 2) const char* in, _Out_cap_(length) byte* out);
void hex_to_bin(_In_ size_t length, _In_count_(length * 2) const char* in, _Out_cap_(length) char* out);
size_t hex_2_bin_ignorewhitespace(_In_ size_t length, _In_count_(length * 2) const wchar_t* in, _Out_cap_(length) byte* out);

/// conversion to integral types
template <typename _chout, typename _chin> _chout FromHex(_In_ const _chin* in, _Out_ _chout& out)
{
	out = 0;
	for (size_t n = 0; (n < sizeof(out)*2) && isHex(*in); in++, n++)
	{
		byte b = fromHex(*in, b);
		out <<= 4;
		out |= b;
	}
	return out;
}

/// conversion to integral types
template <typename _chout, typename _chin> _chout FromHex(_In_ const std::basic_string<_chin>& in, _Out_ _chout& out)
{
	FromHex(in.c_str(), out);
	return out;
}

std::wstring makeHexFromAscii(_In_ const std::wstring& ascii);
std::wstring makeAsciiFromHex(_In_ const std::wstring& hex);

} // namespace myid
