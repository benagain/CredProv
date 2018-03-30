/** \file
 * Global operator functions
 */

#pragma once

#include <comdef.h>
#include <atlcomcli.h>
#include "..\ImportMSXML.h"

std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const _bstr_t& rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const ATL::CComBSTR& rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const _variant_t& rhs);
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const ATL::CComVariant& rhs);
#ifdef _INCLUDE_MSXML
std::wstring& operator<<(_Inout_ std::wstring& lhs, _In_ const MSXML::IXMLDOMNodePtr& rhs);
#endif

std::string& operator<<(_Inout_ std::string& lhs, _In_ const _bstr_t& rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ const ATL::CComBSTR& rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ const _variant_t& rhs);
std::string& operator<<(_Inout_ std::string& lhs, _In_ const ATL::CComVariant& rhs);
#ifdef _INCLUDE_MSXML
std::string& operator<<(_Inout_ std::string& lhs, _In_ const MSXML::IXMLDOMNodePtr& rhs);
#endif
