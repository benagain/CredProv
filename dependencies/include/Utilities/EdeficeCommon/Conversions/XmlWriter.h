#pragma once

#include "Utilities/EdeficeCommon/VS2005Fix.h"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#ifndef MOBILE
#include <comutil.h>
#include <atlcomcli.h>
#endif

namespace eXML
{

/// Lightweight XML writer.\n
/// This is much simpler than CXMLWriter which suffers from the usual MS code bloat.
class xmlwriter
{
public:
	enum format			/// formatting option
	{
		NONE,			///< no formatting
		CRLF,			///< add CRLF after node close
		INDENT			///< indent nodes using tabs
	};
	enum encoding		/// encoding option
	{
		NOHEADER,		///< no header, default, implies UTF16
		NOENC,			///< no encoding
		UTF8,			///< UTF8, all text is converted to UTF8
		UTF16			///< UTF16
	};

	xmlwriter();
	explicit xmlwriter(format _format);
	xmlwriter(const xmlwriter& rhs);
	xmlwriter& operator=(const xmlwriter& rhs);

	void Header(encoding _encoding = NOENC);
	void EscapeInvalid(bool escape = true);
	void Node(const wchar_t* node);
	void Node(const wchar_t* node, const wchar_t* text);
	void Node(const wchar_t* node, long value);
	void OptNode(const wchar_t* node, const wchar_t* text);
	void OpenNode(const wchar_t* node);
	void CloseNode(size_t nodes = 1);
	void CloseAllNode(void);
	void Attribute(const wchar_t* attr);
	void Attribute(const wchar_t* attr, const wchar_t* value);
	void Attribute(const wchar_t* attr, long value);
	void Text(const wchar_t* text);
	void Text(long value);
	void EscapedText(const wchar_t* text);
	void EscapedText(const wchar_t* node, const wchar_t* text);
	void CDATA(const wchar_t* text);
	void CDATA(const wchar_t* node, const wchar_t* text);
	void XML(const wchar_t* text);
	void XML(const wchar_t* node, const wchar_t* text);
	void Comment(const wchar_t* text, bool _crlf=true);
	void operator+=(const wchar_t* text);
	xmlwriter& operator<<(const wchar_t* text);

	void Indent(int indent);
	virtual void Reset(void);
	//operator std::string();
	operator std::wstring();
#ifndef MOBILE
	operator _bstr_t();
	operator ATL::CComBSTR();
	operator _variant_t();
	BSTR ToBSTR(void);
#endif

	// overloads
	void Node(const std::wstring& node)									{Node(node.c_str());}
	void Node(const wchar_t* node, const std::wstring& text)			{Node(node, text.c_str());}
	void Node(const std::wstring& node, const wchar_t* text)			{Node(node.c_str(), text);}
	void Node(const std::wstring& node, const std::wstring& text)		{Node(node.c_str(), text.c_str());}
	void Node(const std::wstring& node, long value)						{Node(node.c_str(), value);}
	void OptNode(const wchar_t* node, const std::wstring& text)			{OptNode(node, text.c_str());}
	void OptNode(const std::wstring& node, const wchar_t* text)			{OptNode(node.c_str(), text);}
	void OptNode(const std::wstring& node, const std::wstring& text)	{OptNode(node.c_str(), text.c_str());}
	void OpenNode(const std::wstring& node)								{OpenNode(node.c_str());}
	void Attribute(const std::wstring& attr)							{Attribute(attr.c_str());}
	void Attribute(const wchar_t* attr, const std::wstring& value)		{Attribute(attr, value.c_str());}
	void Attribute(const std::wstring& attr, const wchar_t* value)		{Attribute(attr.c_str(), value);}
	void Attribute(const std::wstring& attr, const std::wstring& value) {Attribute(attr.c_str(), value.c_str());}
	void Attribute(const std::wstring& attr, long value)				{Attribute(attr.c_str(), value);}
	void Text(const std::wstring& text)									{Text(text.c_str());}
	void EscapedText(const std::wstring& text)							{EscapedText(text.c_str());}
	void EscapedText(const wchar_t* node, const std::wstring& text)		{EscapedText(node, text.c_str());}
	void EscapedText(const std::wstring& node, const wchar_t* text)		{EscapedText(node.c_str(), text);}
	void EscapedText(const std::wstring& node, const std::wstring& text) {EscapedText(node.c_str(), text.c_str());}
	void CDATA(const std::wstring& text)								{CDATA(text.c_str());}
	void CDATA(const wchar_t* node, const std::wstring& text)			{CDATA(node, text.c_str());}
	void CDATA(const std::wstring& node, const wchar_t* text)			{CDATA(node.c_str(), text);}
	void CDATA(const std::wstring& node, const std::wstring& text)		{CDATA(node.c_str(), text.c_str());}
	void XML(const std::wstring& text)									{XML(text.c_str());}
	void XML(const wchar_t* node, const std::wstring& text)				{XML(node, text.c_str());}
	void XML(const std::wstring& node, const wchar_t* text)				{XML(node.c_str(), text);}
	void XML(const std::wstring& node, const std::wstring& text)		{XML(node.c_str(), text.c_str());}
	void Comment(const std::wstring& text, bool _crlf=true)				{Comment(text.c_str(), _crlf);}
	void operator+=(const std::wstring& text)							{operator+=(text.c_str());}
	xmlwriter& operator<<(const std::wstring& text)						{return operator<<(text.c_str());}

protected:
	explicit xmlwriter(const wchar_t* rhs);

	void WriteText(const wchar_t* text);
	void EscapeText(const wchar_t* text);
	void CDATAText(const wchar_t* text);
	void EncodeText(const wchar_t* text);
	static bool NeedEscape(const wchar_t* text, wchar_t apos = 0);
	void CloseAttribute(bool crlf);
	void TestAttribute(const wchar_t* attr) const;
	void crlf(void);
	void indent(void);
	static void TestNode(const wchar_t* node);
	static void TestText(const wchar_t* text);

	std::wostringstream	m_str;				///< internal data buffer
	bool				m_NodeOpen;			///< node is available for attribute writing
	format				m_format;			///< formatting options
	encoding			m_encoding;			///< encoding
	bool				m_escapeInvalid;	///< true to escape text containing XML, else CDATA it
	int					m_indent;			///< global extra indent
	std::stack<std::wstring>	m_node;		///< stack of open nodes
};

/// auto defines an outer "Parameters" node
class xmlWriterPar : public xmlwriter
{
	typedef xmlwriter inherited;

public:
	xmlWriterPar();
	virtual void Reset(void);
};

} // namespace
