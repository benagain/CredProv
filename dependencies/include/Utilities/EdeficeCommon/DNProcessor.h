#pragma once

namespace DNUtils
{

std::wstring ReverseDN(_In_ std::wstring const & dn, _Out_ std::wstring & cn);
void SplitCommonName(_In_ std::wstring const & cn, _In_ std::wstring & firstName, _Out_ std::wstring & lastName, _Out_ std::wstring & initial);
bool IsGenerationalSuffix(_In_ std::wstring const & str);

std::wstring ReEscapeX500(_In_ std::wstring const & DNElement);
std::wstring ReEscapeElement(_In_z_ const wchar_t *input);
std::wstring ConvertLDAPToX500(_In_ const std::wstring &input);

}// namespace DNUtils