#pragma once

#include <map>
#include <vector>
#include "XmlNode.h"

namespace eXML
{
class CXMLParser
{
public:
	static const std::wstring NO_NODE;

	static bool nodeIsEmpty(_In_ const std::wstring&  nodeContents) { return eXML::nodeIsEmpty(nodeContents); }
	static bool nodeContainsData(_In_ const std::wstring&  nodeContents) { return eXML::nodeContainsData(nodeContents); }
	static bool nodeExists(_In_ const std::wstring&  nodeContents) { return eXML::nodeExists(nodeContents); }
	static void NoNodeToEmpty(_Inout_ std::wstring& nodeContents) { eXML::NoNodeToEmpty(nodeContents); }
	static void EmptyToNoNode(_Inout_ std::wstring& nodeContents) { eXML::EmptyToNoNode(nodeContents); }

	CXMLParser();
	virtual ~CXMLParser();

	MSXML::IXMLDOMNodePtr ParseXMLType(_In_ const std::wstring& wstrNodeName);
	bool ParseXMLType(_In_ const std::wstring&  wstrNodeName, _Out_ long& lNodeValue) const;
	bool ParseXMLType(_In_ const std::wstring&  wstrNodeName, _Out_ std::wstring &wstrNodeValue) const;
	bool ParseXMLType(_In_ const std::wstring&  wstrNodeName, _Out_ std::vector<std::wstring> &vecNodeValues) const;
	void ParseXMLType(_In_ const long lItemID, _Out_ std::wstring &wstrNodeName, _Out_ std::wstring &wstrNodeValue, _Out_ BOOL &bEmpty) const;
	std::wstring ParseNodeString(_In_ const std::wstring&  wstrNodeName) const;

	std::wstring CopyXmlTree(void) const;
	std::wstring CopyXmlTree(_In_ const std::wstring&  wstrNodeName) const;
	std::vector<std::wstring> CopyXmlTrees(_In_ const std::wstring&  strNodeName) const;

	std::vector<std::map<std::wstring, std::wstring> > ParseXMLTypeAttributes(_In_ const std::wstring& wstrNodeName, _In_ const std::vector < std::wstring > & vecAttributes) const;
	void ParseXMLTypeAttribute(_In_ const std::wstring& wstrAttributeName, _In_ const long lItemID, _Out_ std::wstring &wstrNodeValue, _Out_ BOOL &bEmpty) const;
	std::map<std::wstring, std::wstring> ParseXMLOrderedAttributes(_In_ const std::wstring& wstrNodeName, _In_ const std::wstring& wstrOrderAttribute, _In_ const int nCount) const;
	std::map<std::wstring, std::wstring> ParseXMLAttributesFromQuery(_In_ const std::wstring& wstrQuery) const;

	bool SetNodesLevel(_In_ const std::wstring& wstrLevel);
	void SetNodesLevel(_In_ const std::wstring& wstrLevel, _Out_ BOOL & bEmpty);
	bool SetNodesLevel(_In_ const std::wstring& wstrLevel, _In_ long const lIndex);
	void SetNodesLevel(_In_ const std::wstring& wstrLevel, _In_ long const lIndex, _Out_ BOOL &bEmpty);
	bool SetNodesLevel2(_In_ const std::wstring& wstrLevel, _In_ long const lIndex = 0);
	void SetNodesLevel2(_In_ const std::wstring& wstrLevel, _In_ long const lIndex, _Out_ BOOL &bEmpty);
	void SetNodesLevelWrtChild(_In_ const std::wstring& wstrLevel, _In_ long const lIndex, _Out_ BOOL &bEmpty);
	bool SetNodesLevelFromQuery(_In_ const std::wstring& wstrQuery);
	void SetNodesLevelFromQuery(_In_ const std::wstring& wstrQuery, _Out_ BOOL &bEmpty);

	bool LoadXML(_In_ const BSTR bstrXML);
	bool LoadXML(_In_ const std::wstring& wstrXML) { return LoadXML(_bstr_t(wstrXML.c_str())); }
	void LoadXMLNode(_In_ MSXML::IXMLDOMNodePtr pNodeXML);
	bool LoadXMLStringOrNode(_In_ const VARIANT& vXML);
	bool Loaded(void) const;

	std::wstring GetXML(_In_ int const item) const;

	MSXML::IXMLDOMDocumentPtr GetXMLDOC(void) const { return m_spDOMDoc; }

	/// return NodePtr to doc-element
	eXML::IXMLDOMNodePtr& XML(void) { return m_spNodeElement; }
	_variant_t XMLNodeVariant() { return _variant_t(XML().GetInterfacePtr()); }

	MSXML::IXMLDOMNodePtr GetNode(_In_ const std::wstring& wstrLevel, _In_ long const lIndex) const;

protected:
	virtual void SetParseConditions(_In_ MSXML::IXMLDOMDocumentPtr& spDOMDoc);
	virtual void HandleLoadXMLError(_In_ const _bstr_t& bstrParseReason);
	virtual void HandleNoElementError(void);

	MSXML::IXMLDOMNodeListPtr m_pChildNodes;	///< current set of child nodes

	MSXML::IXMLDOMDocumentPtr m_spDOMDoc;
	eXML::IXMLDOMNodePtr m_spNodeElement;		///< document node
	MSXML::IXMLDOMElementPtr m_pElement;		///< same node as m_spNodeElement
};
};

typedef eXML::CXMLParser CXMLParser;

