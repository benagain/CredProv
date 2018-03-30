#include "stdafx.h"
#include "Fields.h"

namespace Fields
{

String::String()
{
	operator=(L"");
}

String::String(_In_ bool secure)
	: m_secure(secure)
{
	operator=(L"");
}

String::String(_In_z_ LPCWSTR rhs)
{
	operator=(rhs);
}

String::String(_In_z_ LPCWSTR rhs, _In_ bool secure)
	: m_secure(secure)
{
	operator=(rhs);
}

String::String(_In_ const std::wstring& rhs)
{
	operator=(rhs);
}

String::String(_In_ const std::wstring& rhs, _In_ bool secure)
	: m_secure(secure)
{
	operator=(rhs);
}

String::~String()
{
	CoTaskMemFree(m_string);
	m_string = nullptr;
}

String& String::operator=(_In_z_ LPCWSTR rhs)
{
	Clear();

	if (rhs == nullptr)
		SHStrDupW(L"", &m_string);
	else
		SHStrDupW(rhs, &m_string);

	return *this;
}

String& String::operator=(_In_ const std::wstring& rhs)
{
	return operator=(rhs.c_str());
}

String::operator bool() const
{
	return m_string != nullptr;
}

String::operator LPCWSTR() const
{
	return m_string;
}

HRESULT String::Dup(_Outptr_result_nullonfailure_ LPWSTR* ppsz) const
{
	return SHStrDupW(m_string, ppsz);
}

void String::Attach(_In_opt_z_ PWSTR ppsz)
{
	Clear();

	m_string = ppsz;
}

void String::Release(_Outptr_result_maybenull_ LPWSTR* ppsz)
{
	if (ppsz != nullptr)
	{
		if (m_string != nullptr)
		{
			*ppsz = m_string;
			m_string = nullptr;
		}
		else
		{
			SHStrDupW(L"", ppsz);
		}
	}
}

void String::Resource(_In_ UINT id)
{
	WCHAR value[256]{};
	if (LoadString(ATL::_AtlBaseModule.GetModuleInstance(), id, value, 256) == 0)
		operator=(nullptr);
	else
		operator=(value);
}

void String::Clear(void)
{
	if (m_string != nullptr)
	{
		if (m_secure)
			SecureZeroMemory(m_string, wcslen(m_string) * sizeof(WCHAR));
		CoTaskMemFree(m_string);
		m_string = nullptr;
	}

	SHStrDupW(L"", &m_string);
}

void String::Secure(_In_ bool secure)
{
	m_secure = secure;
}

bool String::Empty(void) const
{
	if (m_string == nullptr)
		return true;

	return m_string[0] == 0;
}

} // namespace Fields

