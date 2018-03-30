#pragma once
#include "SalFix.h"

namespace myid
{
/// A set of utility methods for dealing with files
namespace FileUtils
{
// -----------------------------------------------------------------------------------------
// File loading
// -----------------------------------------------------------------------------------------

bool LoadBinaryFile(_In_ const std::wstring& filename, _Out_ VectorOfByte& fileDataOut);
bool LoadTextFile(_In_ const std::wstring& filename, _Out_ std::wstring& fileTextOut);
void GetFileText(_In_ const VectorOfByte& fileData, _Out_ std::wstring& fileTextOut);

// -----------------------------------------------------------------------------------------
// File saving
// -----------------------------------------------------------------------------------------

void CreateAnsiFile(_In_ const std::wstring& filename, _In_z_ const wchar_t* pwszFileText, _In_ DWORD dwFlags = CREATE_ALWAYS);
void CreateUnicodeFile(_In_ const std::wstring& filename, _In_z_ const wchar_t* pwszFileText, _In_ DWORD dwFlags = CREATE_ALWAYS);
void CreateBinaryFile(_In_ const std::wstring& filename, _In_ const VectorOfByte& data, _In_ DWORD dwFlags = CREATE_ALWAYS);

namespace win32
{
bool DoesFilenameContainIllegalCharacters(_In_ const std::wstring &filename);
} // namespace win32
} // namespace FileUtils
} // namespace myid
