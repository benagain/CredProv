#include "stdafx.h"
#include "Support.h"
#define RPC_USE_NATIVE_WCHAR
#include <rpc.h>

#pragma comment(lib, "rpcrt4.lib")

namespace Support
{

namespace
{

/// Service function to get a name
/// A name is up to 8 lower case characters
bool ValidName(_In_z_ LPSTR pszName, _Out_ std::string& name)
{
	name.clear();

	if (*pszName == 0)
		return false;

	if (strlen(pszName) > 8)
		return false;

	name = pszName;
	for (char& n : name)
	{
		if ((n > 0) && (n < 0x20))
			return false;
		if (strchr("\"*/:<>?\\|", n) != nullptr)
			return false;
		n = (char)tolower(n);
	}

	return true;
}

} // namespace

/// Check if the PIN id is valid
bool ValidPinId(PIN_ID PinId)
{
	if (PinId == ROLE_EVERYONE)
		return false;
	if (PinId >= MAX_PINS)
		return false;

	return true;
}

/// Get a valid directory name
bool ValidDirName(_In_opt_z_ LPSTR pszName, _Out_ std::string& name)
{
	if (pszName == nullptr)
	{
		name.clear();
		return true;
	}

	return ValidName(pszName, name);
}

/// Get a valid file name
bool ValidFileName(_In_z_ LPSTR pszName, _Out_ std::string& name)
{
	if (pszName == nullptr)
		return false;

	return ValidName(pszName, name);
}

/// Set a directory or file name into the data
void SetData(_In_ const std::string& name, _Inout_ VectorOfByte& data, _In_ size_t position)
{
	if (data.size() < position + 8)
		data.resize(position + 8);

	size_t ns = name.size();
	for (size_t c = 0; c < 8; ++c)
	{
		if (c >= ns)
			data[position + c] = 0;
		else
			data[position + c] = name[c];
	}
}

/// Set a DWORD into the data
void SetData(_In_ DWORD value, _Inout_ VectorOfByte& data, _In_ size_t position)
{
	if (data.size() < position + sizeof(DWORD))
		data.resize(position + sizeof(DWORD));

	data[position + 0] = (value >> 24) & 0xFF;
	data[position + 1] = (value >> 16) & 0xFF;
	data[position + 2] = (value >> 8) & 0xFF;
	data[position + 3] = value & 0xFF;
}

/// Set a directory or file name into data
VectorOfByte SetData(_In_ const std::string& name)
{
	VectorOfByte rtn;
	SetData(name, rtn);
	return rtn;
}

/// Set a DWORD into data
VectorOfByte SetData(_In_ DWORD value)
{
	VectorOfByte rtn;
	SetData(value, rtn);
	return rtn;
}


/// Get a directory or file name from the data
std::wstring GetName(_In_ const VectorOfByte& data, _In_ size_t position)
{
	std::wstring name;
	name.reserve(8);

	size_t ds = data.size();
	for (size_t p = 0; p < 8; ++p)
	{
		if (p + position >= ds)
			break;
		if (data[p + position] == 0)
			break;
		name.push_back(data[p + position]);
	}

	return name;
}

/// Get a DWORD from the data
DWORD GetDWORD(_In_ const VectorOfByte& data, _In_ size_t position)
{
	DWORD value(0);
	if (position + sizeof(DWORD) <= data.size())
	{
		value = (data[position + 0] << 24) |
				(data[position + 1] << 16) |
				(data[position + 2] << 8) |
				data[position + 3];
	}

	return value;
}

/// Get a byte from the data
byte GetByte(_In_ const VectorOfByte& data, _In_ size_t position)
{
	byte value(0);

	if (position < data.size())
		value = data[position];

	return value;
}

std::wstring ToWstr(const GUID& guid)
{
	std::wstring rtn;
	RPC_WSTR string(nullptr);
	if (UuidToString(&guid, &string) == RPC_S_OK)
	{
		rtn = string;

		RpcStringFree(&string);
	}

	return rtn;
}

} // namespace Support
