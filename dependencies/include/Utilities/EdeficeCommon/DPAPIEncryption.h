#pragma once

#include "VectorOfByte.h"

namespace myid
{
namespace DPAPIEncryption
{
VectorOfByte EncryptData(_In_ std::wstring const & input);
VectorOfByte EncryptData(_In_ std::string const & input);
void DecryptData(_In_ VectorOfByte const & input, _Out_ std::wstring & output);
void DecryptData(_In_ VectorOfByte const & input, _Out_ std::string & output);
}
}

