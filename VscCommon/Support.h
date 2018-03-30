#pragma once

#include "Products\Common\Microsoft\CNG\MD\CardMod.h"
#include "Utilities\EdeficeCommon\VectorOfByte.h"

typedef     DWORD                       PIN_ID, *PPIN_ID;

/// APDU transfer support functions
namespace Support
{

bool ValidPinId(PIN_ID PinId);

bool ValidDirName(_In_opt_z_ LPSTR pszName, _Out_ std::string& name);
bool ValidFileName(_In_z_ LPSTR pszName, _Out_ std::string& name);

void SetData(_In_ const std::string& name, _Inout_ VectorOfByte& data, _In_ size_t position = 0);
void SetData(_In_ DWORD value, _Inout_ VectorOfByte& data, _In_ size_t position = 0);
VectorOfByte SetData(_In_ const std::string& name);
VectorOfByte SetData(_In_ DWORD value);

std::wstring GetName(_In_ const VectorOfByte& data, _In_ size_t position = 0);
DWORD GetDWORD(_In_ const VectorOfByte& data, _In_ size_t position = 0);
byte GetByte(_In_ const VectorOfByte& data, _In_ size_t position = 0);

std::wstring ToWstr(const GUID& guid);

} // namespace Support
