/** \file
 * Global operator functions
 */

#pragma once
#include <AtlComTime.h>

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ int rhs)
{
	wchar_t str[33];
	if (0 == _itow_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ long rhs)
{
	wchar_t str[33];
	if (0 == _ltow_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ unsigned long rhs)
{
	wchar_t str[33];
	if (0 == _ultow_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const _bstr_t& rhs)
{
	unsigned int length = rhs.length();
	if (length > 0)
		lhs.append((const wchar_t*)rhs, length);

	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const ATL::CComBSTR& rhs)
{
	unsigned int length = rhs.Length();
	if (length > 0)
		lhs.append((const wchar_t*)rhs, length);

	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const _variant_t& rhs)
{
	switch (rhs.vt)
	{
	case VT_BSTR:
	case VT_LPWSTR:
		if (rhs.bstrVal != NULL)
			lhs += rhs.bstrVal;
		break;
	case VT_DATE:
		lhs += ATL::COleDateTime(rhs).Format(L"%Y-%m-%d %H:%M:%S");
		break;
	case VT_NULL:
	case VT_EMPTY:
		break;
	default:
		{
			_variant_t vChanged;
			vChanged.ChangeType(VT_BSTR, &rhs);
			if(vChanged.bstrVal != NULL)
				lhs += vChanged.bstrVal;
		}
	}

	return lhs;
}

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const ATL::CComVariant& rhs)
{
	switch (rhs.vt)
	{
	case VT_BSTR:
	case VT_LPWSTR:
		if (rhs.bstrVal != NULL)
			lhs += rhs.bstrVal;
		break;
	case VT_DATE:
		lhs += ATL::COleDateTime(rhs).Format(L"%Y-%m-%d %H:%M:%S");
		break;
	case VT_NULL:
	case VT_EMPTY:
		break;
	default:
		{
			ATL::CComVariant vChanged;
			if (SUCCEEDED(vChanged.ChangeType(VT_BSTR, &rhs)))
			{
				if(vChanged.bstrVal != NULL)
					lhs += vChanged.bstrVal;
			}
		}
	}

	return lhs;
}

#ifdef _INCLUDE_MSXML
/// append XML node text
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const MSXML::IXMLDOMNodePtr& rhs)
{
	if (rhs != NULL)
	{ 
		_bstr_t text(rhs->text);
		unsigned int length = text.length();
		if (length > 0)
			lhs.append((const wchar_t*)text, length);
	}

	return lhs;
}
#endif

//====================================================================================================
//====================================================================================================
//====================================================================================================

std::string& operator<<(_Inout_ std::string& lhs, _In_ int rhs)
{
	char str[33];
	if (0 == _itoa_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ long rhs)
{
	char str[33];
	if (0 == _ltoa_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ unsigned long rhs)
{
	char str[33];
	if (0 == _ultoa_s(rhs, str, 33, 10))
		lhs += str;
	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ const _bstr_t& rhs)
{
	unsigned int length = rhs.length();
	if (length > 0)
		lhs.append((const char*)rhs, length);

	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ const ATL::CComBSTR& rhs)
{
	unsigned int length = rhs.Length();
	if (length > 0)
		lhs.append(_bstr_t(rhs), length);

	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ const _variant_t& rhs)
{
	switch (rhs.vt)
	{
	case VT_BSTR:
	case VT_LPWSTR:
		if (rhs.bstrVal != NULL)
			lhs += _bstr_t(rhs.bstrVal);
		break;
	case VT_DATE:
		lhs += bstr_t(ATL::COleDateTime(rhs).Format(L"%Y-%m-%d %H:%M:%S"));
		break;
	case VT_NULL:
	case VT_EMPTY:
		break;
	default:
	{
		_variant_t vChanged;
		vChanged.ChangeType(VT_BSTR, &rhs);
		if (vChanged.bstrVal != NULL)
			lhs += _bstr_t(vChanged.bstrVal);
	}
	}

	return lhs;
}

std::string& operator<<(_Inout_ std::string& lhs, _In_ const ATL::CComVariant& rhs)
{
	switch (rhs.vt)
	{
	case VT_BSTR:
	case VT_LPWSTR:
		if (rhs.bstrVal != NULL)
			lhs += _bstr_t(rhs.bstrVal);
		break;
	case VT_DATE:
		lhs += bstr_t(ATL::COleDateTime(rhs).Format(L"%Y-%m-%d %H:%M:%S"));
		break;
	case VT_NULL:
	case VT_EMPTY:
		break;
	default:
	{
		ATL::CComVariant vChanged;
		if (SUCCEEDED(vChanged.ChangeType(VT_BSTR, &rhs)))
		{
			if (vChanged.bstrVal != NULL)
				lhs += _bstr_t(vChanged.bstrVal);
		}
	}
	}

	return lhs;
}

#ifdef _INCLUDE_MSXML
/// append XML node text
std::string& operator<<(_Inout_ std::string& lhs, _In_ const MSXML::IXMLDOMNodePtr& rhs)
{
	if (rhs != NULL)
	{
		_bstr_t text(rhs->text);
		unsigned int length = text.length();
		if (length > 0)
			lhs.append((const char*)text, length);
	}

	return lhs;
}
#endif
