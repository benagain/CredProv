// XMLUtils.h: interface for the CXMLUtils class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#ifndef NO_MSXML

#include "VS2005Fix.h"
#include "PragmaMessages.h"
#include "ComPtrUtils.h"
#include "Conversions\StringUtils.h"
#include "Conversions\Numbers.h"
#include "XMLIterator.h"

// note - only used in Debug but include so debug/release builds which use this need the same includes
#include "Debug.h"

#include <sstream>

#include <AtlComTime.h>

// this namespace deals with helper functions for dealing with Raw XML DOM functionality
// that has been #imported into the project.
namespace eXML
{

static const std::wstring NO_NODE = L"_no_match_";

/// test if a node is empty or was not found, ie not NO_NODE (ie _no_match_)
inline bool nodeIsEmpty(_In_ const std::wstring&  nodeContents) { return nodeContents.empty() || nodeContents == NO_NODE; }

/// test if a node is not empty and not NO_NODE (ie _no_match_)
inline bool nodeContainsData(_In_ const std::wstring&  nodeContents) { return !nodeIsEmpty(nodeContents); }

/// test if a node was found
inline bool nodeExists(_In_ const std::wstring&  nodeContents) { return nodeContents != NO_NODE; }

/// Convert NO_NODE (ie _no_match_) to an empty string
inline void NoNodeToEmpty(_Inout_ std::wstring& nodeContents) { if (nodeContents == NO_NODE) nodeContents.clear(); }

/// Convert an empty string to NO_NODE (ie _no_match_)
inline void EmptyToNoNode(_Inout_ std::wstring& nodeContents) { if (nodeContents.empty()) nodeContents = NO_NODE; }


// Forward declarations (used by WriteXMLText)
MSXML::IXMLDOMNodePtr createNodeByXPath(_In_ MSXML::IXMLDOMNodePtr, _In_ std::wstring const&);
std::wstring ToWstr(_In_ const MSXML::IXMLDOMNodePtr&);


/// returns the newly created node
inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, _In_ const _bstr_t& bstrNodeData)
{
	MSXML::IXMLDOMNodePtr pNewNode = ptrNodeToAppendTo->ownerDocument->createNode(_variant_t((long)MSXML::NODE_ELEMENT), bstrNodeNameToAdd, L"");
	if (bstrNodeData.length() > 0)
		pNewNode->Puttext(bstrNodeData);

	ptrNodeToAppendTo->appendChild(pNewNode);

	return pNewNode;
}

inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, const std::wstring& bstrNodeData)
{
	return AppendXMLNode(ptrNodeToAppendTo, bstrNodeNameToAdd, _bstr_t(bstrNodeData.c_str()));
}

inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, _In_z_ const wchar_t* bstrNodeData)
{
	return AppendXMLNode(ptrNodeToAppendTo, bstrNodeNameToAdd, _bstr_t(bstrNodeData));
}

inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, _In_ const long lNodeData)
{
	_variant_t vLong(lNodeData, VT_I4);
	return eXML::AppendXMLNode(ptrNodeToAppendTo, bstrNodeNameToAdd, (_bstr_t)vLong);
}

inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMElementPtr& ptrDocumentElement, _In_ _bstr_t const & bstrNodeNameToAdd, _In_ _bstr_t const & bstrNodeData)
{
	MSXML::IXMLDOMNodePtr ptrNodeToAppendTo = ptrDocumentElement;
	return AppendXMLNode(ptrNodeToAppendTo, bstrNodeNameToAdd, bstrNodeData);
}

inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMElementPtr& ptrDocumentElement, _In_ _bstr_t const & bstrNodeNameToAdd, _In_z_ const wchar_t* bstrNodeData)
{
	MSXML::IXMLDOMNodePtr ptrNodeToAppendTo = ptrDocumentElement;
	return AppendXMLNode(ptrNodeToAppendTo, bstrNodeNameToAdd, bstrNodeData);
}

/// returns the newly created node
inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, _In_ const _bstr_t& bstrNodeData, _In_ const std::wstring& wstrNamespaceURI)
{
	MSXML::IXMLDOMNodePtr pNewNode = ptrNodeToAppendTo->ownerDocument->createNode(_variant_t((long)MSXML::NODE_ELEMENT), bstrNodeNameToAdd, wstrNamespaceURI.c_str());
	if (bstrNodeData.length() > 0)
		pNewNode->Puttext(bstrNodeData);

	ptrNodeToAppendTo->appendChild(pNewNode);

	return pNewNode;
}

// in case ADO is not hash-imported this functionality is available only if specifically requested
#ifdef XMLUTILS_ADO
/// append a node based into the XML - recordset version uses the value of the field named bstrNodeNameToAdd as the value
/// returns the newly created node
inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, ADODB::_RecordsetPtr &spRS)
{
	_bstr_t bstrValue(L"");

	_variant_t varValue = spRS->Fields->GetItem(bstrNodeNameToAdd)->Value;
	if(varValue.vt != VT_NULL)
	{
		varValue.ChangeType(VT_BSTR);
		bstrValue = varValue.bstrVal;
	}

	MSXML::IXMLDOMNodePtr pNewNode = ptrNodeToAppendTo->ownerDocument->createNode(_variant_t((long)MSXML::NODE_ELEMENT), bstrNodeNameToAdd, L"");

	if(bstrValue.length() > 0)
		pNewNode->Puttext(bstrValue);

	ptrNodeToAppendTo->appendChild(pNewNode);

	return pNewNode;
}

/// append a new node to the XML, but the name of the node can be different to the field name in the recordset
inline MSXML::IXMLDOMNodePtr AppendXMLNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrNodeNameToAdd, _In_ const _bstr_t& bstrFieldNameInRecordset, _In_ ADODB::_RecordsetPtr &spRS)
{
	_bstr_t bstrValue(L"");

	_variant_t varValue = spRS->Fields->GetItem(bstrFieldNameInRecordset)->Value;
	if(varValue.vt != VT_NULL)
	{
		varValue.ChangeType(VT_BSTR);
		bstrValue = varValue.bstrVal;
	}

	MSXML::IXMLDOMNodePtr pNewNode = ptrNodeToAppendTo->ownerDocument->createNode(_variant_t((long)MSXML::NODE_ELEMENT), bstrNodeNameToAdd, L"");

	if(bstrValue.length() > 0)
		pNewNode->Puttext(bstrValue);

	ptrNodeToAppendTo->appendChild(pNewNode);

	return pNewNode;
}


#endif

// -------------------------------------------------------------------------------------------------
// Methods to read XML nodes
// -------------------------------------------------------------------------------------------------

/// Get the text content of the XML node at a specified XPath location
// \returns The string representation of the XML node text, or the specified default value if not found
inline std::wstring ReadXMLText(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,			///< The root node for the XPath expression
	_In_ const std::wstring& wstrXPath,				///< An XPath expression defining the path to the node be read
	_In_ const std::wstring& defaultValue = L"")	///< Optional. Specify an alternative value to return if the attribute was not found, default is an an empty string
{
	if (auto node = pXmlNode->selectSingleNode(wstrXPath.c_str()))
	{
		return eXML::ToWstr(node);
	}

	return defaultValue;
}

// -------------------------------------------------------------------------------------------------

/// Get the text content of the XML node at a specified XPath location
/// \returns The integer representation of the XML node text, or the specified default value if not found
inline long ReadXMLTextLong(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,	///< The root node for the XPath expression
	_In_ const std::wstring& wstrXPath,		///< An XPath expression defining the path to the node be read
	_In_ const long& defaultValue = 0)		///< Optional. Specify an alternative value to return if the attribute was not found, default is zero
{
	if (auto node = pXmlNode->selectSingleNode(wstrXPath.c_str()))
	{
		std::wstring nodeText = eXML::ToWstr(node);
		return myid::WSTRtoLONG(nodeText);
	}

	return defaultValue;
}

// Given an Xpath, get the text of all matching nodes
inline std::vector<std::wstring> GetNodeValues(_In_ const MSXML::IXMLDOMDocumentPtr &doc, _In_ const std::wstring &xpath)
{
	auto valueNodes = doc->selectNodes(xpath.c_str());
	std::vector<std::wstring> valuesFound;
	std::transform(eXML::NodeList::begin(valueNodes), eXML::NodeList::end(valueNodes),
		std::back_inserter(valuesFound),
		[](const MSXML::IXMLDOMNodePtr &node) { return myid::ToWstr(node->text); });
	return valuesFound;
}

/* Calling ->text will, if there are child nodes, get the text of the child nodes as well,
this may be undesirable. */
inline std::wstring GetNodeTextIgnoringChildNodes(_In_ const MSXML::IXMLDOMNodePtr &node)
{
	switch (node->nodeType)
	{
	case NODE_TEXT:
	case NODE_ATTRIBUTE:
	case NODE_CDATA_SECTION:
	case NODE_COMMENT:
	case NODE_PROCESSING_INSTRUCTION:
		return myid::ToWstr(node->nodeValue);
	case NODE_ELEMENT:
	{
		auto childNodes = node->childNodes;
		for (long i = 0; i < childNodes->length; ++i)
		{
			if (childNodes->item[i]->nodeType == NODE_TEXT)
				return eXML::ToWstr(childNodes->item[i]);
		}
	}
	}
	return ToWstr(node);
}

// -------------------------------------------------------------------------------------------------
// End of methods to read XML nodes
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
// Methods to write XML nodes
// -------------------------------------------------------------------------------------------------

/// Set the text content of the XML node at a specified XPath location
inline void WriteXMLText(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,	///< The root node for the XPath expression
	_In_ const std::wstring& wstrXPath,		///< An XPath expression defining the path to the node be written
	_In_ const std::wstring& value)			///< The value to be written to the XML node
{
	MSXML::IXMLDOMNodePtr pTargetXMLNode = createNodeByXPath(pXmlNode, wstrXPath);
	pTargetXMLNode->Puttext(value.c_str());
}

// -------------------------------------------------------------------------------------------------

/// Set the text content of the XML node at a specified XPath location
inline void WriteXMLTextLong(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,	///< The root node for the XPath expression
	_In_ const std::wstring& wstrXPath,		///< An XPath expression defining the path to the node be writte
	_In_ long value)						///< The value to be written to the XML node
{
	WriteXMLText(pXmlNode, wstrXPath, myid::LONGtoWSTR(value));
}

// -------------------------------------------------------------------------------------------------
// End of methods to write XML nodes
// -------------------------------------------------------------------------------------------------

/// add an attribute to a specific node
/// returns the newly created attribute
inline MSXML::IXMLDOMAttributePtr AddXMLAttribute(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrAttributeNameToAdd, _In_ const _bstr_t& bstrAttributeData)
{
	MSXML::IXMLDOMAttributePtr ptrAttribute = ptrNodeToAppendTo->ownerDocument->createAttribute(bstrAttributeNameToAdd);
	ptrNodeToAppendTo->Getattributes()->setNamedItem(ptrAttribute);

	ptrAttribute->Puttext(bstrAttributeData);

	return ptrAttribute;
}

/// add an attribute to a specific node
/// returns the newly created attribute
inline MSXML::IXMLDOMAttributePtr AddXMLAttribute(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToAppendTo, _In_ const _bstr_t& bstrAttributeNameToAdd, _In_ long lAttributeData)
{
	MSXML::IXMLDOMAttributePtr ptrAttribute = ptrNodeToAppendTo->ownerDocument->createAttribute(bstrAttributeNameToAdd);
	ptrNodeToAppendTo->Getattributes()->setNamedItem(ptrAttribute);

	_variant_t varLong(lAttributeData);
	varLong.ChangeType(VT_BSTR);

	ptrAttribute->Puttext(varLong.bstrVal);

	return ptrAttribute;
}

// -------------------------------------------------------------------------------------------------
// Methods to read XML attributes
// -------------------------------------------------------------------------------------------------

/*!
* Get a named XML attribute from the provided XML node
*
* \param[in] pXmlNode
*   Node containing the attribute to get
* \param[in] attributeName
*   Name of the attribute to be get
*
* \returns
*   A pointer to the XML attribute DOM object, or NULL if no such attribute is found
*/
inline MSXML::IXMLDOMNodePtr GetXMLAttribute(_In_ MSXML::IXMLDOMNodePtr pXmlNode, _In_ const std::wstring& attributeName)
{
	return MSXML::IXMLDOMNodePtr(pXmlNode->attributes->getNamedItem(attributeName.c_str()));
}

/*!
* Check if a named XML attribute exists in the provided XML node
*
* \param[in] pXmlNode
*   Node to be checked
* \param[in] attributeName
*   Name of the attribute to be find
*
* \returns
*   True if the node contains an attribute with the specified name, false otherwise
*/
inline bool DoesXMLAttributeExist(_In_ MSXML::IXMLDOMNodePtr pXmlNode, _In_ const std::wstring& attributeName)
{
	return NULL != GetXMLAttribute(pXmlNode, attributeName);
}

/*!
* Read the value of the named XML attribute from the provided XML node
*
* \param[in] pXmlNode
*   Node from which to read an attribute
* \param[in] attributeName
*   Name of the attribute to be read
* \param[in] defaultValue
*   Optional. Specify an alternative value to return if the attribute was not found, default is an
*   an empty string
*
* \returns
*   The string representation of the attribute, or the specified default value if not found
*/
inline std::wstring ReadXMLAttribute(_In_ MSXML::IXMLDOMNodePtr pXmlNode, _In_ const std::wstring& attributeName, _In_ const std::wstring& defaultValue = L"")
{
	MSXML::IXMLDOMNodePtr pAttrib = GetXMLAttribute(pXmlNode, attributeName);
	return (NULL != pAttrib) ? std::wstring(pAttrib->text) : defaultValue;
}

/*!
* Read the value of the named XML attribute as a long from the provided XML node
*
* \param[in] pXmlNode
*   Node from which to read an attribute
* \param[in] attributeName
*   Name of the attribute to be read
* \param[in] defaultValue
*   Optional. Specify an alternative value to return if the attribute was not found, default is zero
*
* \returns
*   The integer representation of the attribute value, or the specified default value if not found
*/
inline long ReadXMLAttributeLong(_In_ MSXML::IXMLDOMNodePtr pXmlNode, _In_ const std::wstring& attributeName, _In_ const long& defaultValue = 0)
{
	MSXML::IXMLDOMNodePtr pAttrib = GetXMLAttribute(pXmlNode, attributeName);
	return (NULL != pAttrib) ? myid::WSTRtoLONG(std::wstring(pAttrib->text)) : defaultValue;
}

// -------------------------------------------------------------------------------------------------
// End of methods to read XML attributes
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
// Methods to write XML attributes
// -------------------------------------------------------------------------------------------------

/// Set the value of the named attribute value of the provided XML node
inline void WriteXMLAttribute(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,		///< The node to set the attribute upon
	_In_ const std::wstring& wstrAttribute,		///< Name of the attribute to be set
	_In_ const std::wstring& wstrValue)			///< The value to set the attribute to
{
	AddXMLAttribute(pXmlNode, wstrAttribute.c_str(), wstrValue.c_str());
}

// -------------------------------------------------------------------------------------------------

/// Set the value of the named attribute value of the provided XML node
inline void WriteXMLAttributeLong(
	_In_ MSXML::IXMLDOMNodePtr pXmlNode,		///< The node to set the attribute upon
	_In_ const std::wstring& wstrAttribute,		///< Name of the attribute to be set
	_In_ long value)							///< The value to set the attribute to
{
	WriteXMLAttribute(pXmlNode, wstrAttribute, myid::LONGtoWSTR(value));
}

// -------------------------------------------------------------------------------------------------
// End of methods to write XML attributes
// -------------------------------------------------------------------------------------------------

/// check that the node exists, and that it contains some text
inline bool NodeIsText(_In_ const MSXML::IXMLDOMNodePtr &ptrNode)
{
	if (ptrNode == NULL)
		return false;

	if (ptrNode->Gettext().length() == 0)
		return false;

	return true;
}

/// check that node exists, and that it contains some kind of numeric value
inline bool NodeIsNumber(_In_ const MSXML::IXMLDOMNodePtr &ptrNode)
{
	if (ptrNode == NULL)
		return false;

	ATL::CComVariant varNodeValue = ptrNode->GetnodeTypedValue();
	if (FAILED(varNodeValue.ChangeType(VT_I4)))
		return false;

	return true;
}

/// if this node doesn't contain a number really, then 0 is returned. it is advisable to first validate
inline long Getlong(_In_ const MSXML::IXMLDOMNodePtr &ptrNode)
{
	if (ptrNode == NULL)
		return 0;

	ATL::CComVariant varNodeValue = ptrNode->GetnodeTypedValue();
	if (FAILED(varNodeValue.ChangeType(VT_I4)))
		return 0;

	return varNodeValue.lVal;
}


/// for safety in case of bstrIn containing NULL, the output will be set to L""
inline std::wstring ToWstr(_In_ _bstr_t const& bstrIn)
{
	return myid::ToWstr(bstrIn);
}

inline std::wstring ToWstr(_In_ ATL::CComBSTR const& bstrIn)
{
	return myid::ToWstr(bstrIn);
}

inline std::wstring ToWstr(_In_z_ wchar_t const* pwszIn)
{
	return myid::ToWstr(pwszIn);
}

inline std::wstring ToWstr(_In_ const ATL::CComVariant &vInput)
{
	return myid::ToWstr(vInput);
}

inline std::wstring ToWstr(_In_ _variant_t const& vInput)
{
	return myid::ToWstr(vInput);
}

inline std::string ToStr(_In_ const MSXML::IXMLDOMNodePtr& pNode)
{
	if (pNode == NULL)
		return "";
	return myid::ToStr(pNode->text);
}

inline std::wstring ToWstr(_In_ const MSXML::IXMLDOMNodePtr& pNode)
{
	if (pNode == NULL)
		return L"";
	return ToWstr(pNode->text);
}

#ifdef XMLUTILS_ADO
inline std::wstring ToWstr(_In_ ADODB::_RecordsetPtr const& rs, _In_z_ const wchar_t* fieldName)
{
	return ToWstr( rs->Fields->GetItem( fieldName )->Value );
}
inline std::wstring ToWstr(_In_ ADODB::_RecordsetPtr const& rs, _In_ std::wstring const& fieldName)
{
	return ToWstr( rs->Fields->GetItem( fieldName.c_str() )->Value );
}
#endif


/// Return a pointer to the specified node, if the node does not exist it will be created along
/// with any subnodes required.
inline MSXML::IXMLDOMNodePtr findOrCreate(
	_In_ MSXML::IXMLDOMDocumentPtr toFindIn, ///< the document pointer
	_In_ std::wstring const& nodeName)	  ///< the entire XPATH node, including the document element node
{
	MSXML::IXMLDOMNodePtr foundNode = toFindIn->selectSingleNode(nodeName.c_str());

	if (!static_cast<bool>(foundNode))
	{
		std::wstring newNodeName = nodeName;
		std::wstring::size_type ixSlash = newNodeName.rfind(L"/");

		if (ixSlash == std::wstring::npos)
		{
			foundNode = toFindIn->documentElement;
		}
		else
		{
			newNodeName = nodeName.substr(ixSlash + 1);
			foundNode = findOrCreate(toFindIn, nodeName.substr(0, ixSlash));
		}

		foundNode = AppendXMLNode(foundNode, newNodeName.c_str(), L"");
	}

	return foundNode;
}



/// Return a pointer to the specified node, if the node does not exist it will be created along
/// with any subnodes required as a subnode of the input
inline MSXML::IXMLDOMNodePtr findOrCreate(
	_In_ MSXML::IXMLDOMNodePtr toFindIn,	///< the node pointer
	_In_ std::wstring const& nodeName)		///< the entire XPATH node, including the document element node
{
	MSXML::IXMLDOMNodePtr foundNode = toFindIn->selectSingleNode(nodeName.c_str());

	if (!static_cast<bool>(foundNode))
	{
		std::wstring newNodeName = nodeName;
		std::wstring::size_type ixSlash = newNodeName.rfind(L"/");

		if (ixSlash == std::wstring::npos)
		{
			foundNode = toFindIn;
		}
		else
		{
			newNodeName = nodeName.substr(ixSlash + 1);
			foundNode = findOrCreate(toFindIn, nodeName.substr(0, ixSlash));
		}

		foundNode = AppendXMLNode(foundNode, newNodeName.c_str(), L"");
	}

	return foundNode;
}


/// Create the specified node by an XPath, the node is created empty, and all necessary subnodes are created too.  The
/// final node is created _even if it already exists_, if you don't want duplicate nodes, use findOrCreate(...).
inline MSXML::IXMLDOMNodePtr createNodeByXPath(
	_In_ MSXML::IXMLDOMNodePtr toCreateIn,	///< the node pointer
	_In_ std::wstring const& nodeName)		///< the entire XPATH node, including the document element node
{
	if (toCreateIn == NULL)
		return NULL;

	MSXML::IXMLDOMNodePtr createdNode;

	std::wstring newNodeName = nodeName;
	std::wstring::size_type ixSlash = newNodeName.find(L"/");

	if (ixSlash == std::wstring::npos)
	{
		createdNode = AppendXMLNode(toCreateIn, newNodeName.c_str(), L"");
	}
	else
	{
		std::wstring singleNodeName = nodeName.substr(0, ixSlash);
		if (singleNodeName.length() == 0)
			return NULL;

		MSXML::IXMLDOMNodePtr subNode = toCreateIn->selectSingleNode(singleNodeName.c_str());
		if (subNode == NULL)
			subNode = AppendXMLNode(toCreateIn, singleNodeName.c_str(), L"");

		newNodeName = nodeName.substr(ixSlash + 1);
		createdNode = createNodeByXPath(subNode, newNodeName);
	}

	return createdNode;
}


inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_ _bstr_t const & xml, _In_ std::string const & errorText)
{
	MSXML::IXMLDOMDocumentPtr document = eCom::CreateComPtr<MSXML::IXMLDOMDocumentPtr>(myPROGID_DOMDocument);
	if (document->loadXML(xml) == FALSE)
	{
		MSXML::IXMLDOMParseErrorPtr errPtr = document->parseError;
		_bstr_t bstrErr(errPtr->Getreason());

		std::stringstream s;
		s << errorText << std::endl << "Line " << errPtr->line <<
			"; Char " << errPtr->linepos << "; " << (char*)bstrErr;

#ifdef MYID_DEBUG
		CDebug debug;
		if (debug)
		{
			debug.GetStream() << "Bad XML " << errorText << "\n" << xml;
			debug.Write();
		}
#endif

		throw std::runtime_error(s.str());
	}

	return document;
}

inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_ _bstr_t const & xml)
{
	return ToXmlDocument(xml, "Invalid XML");
}

inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_z_ wchar_t const * xml, _In_ std::string const & errorText)
{
	_bstr_t coercedXml(xml);
	return ToXmlDocument(coercedXml, errorText);
}

inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_z_ wchar_t const * xml)
{
	_bstr_t coercedXml(xml);
	return ToXmlDocument(coercedXml);
}

inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_ std::wstring const& xml, _In_ std::string const & errorText)
{
	return ToXmlDocument(xml.c_str(), errorText);
}

inline MSXML::IXMLDOMDocumentPtr ToXmlDocument(_In_ std::wstring const& xml)
{
	return ToXmlDocument(xml.c_str());
}

inline MSXML::IXMLDOMNodePtr ToXmlNode(_In_ const VARIANT& vXMLIn)
{
	if (vXMLIn.vt == VT_BSTR)
		return ToXmlDocument(_bstr_t(vXMLIn.bstrVal))->documentElement;
	else if (vXMLIn.vt == VT_DISPATCH)
		return vXMLIn.pdispVal;
	else if (vXMLIn.vt == VT_UNKNOWN)
		return vXMLIn.punkVal;
	else
		return NULL;
}

inline MSXML::IXMLDOMNodePtr PrependNode(_In_ MSXML::IXMLDOMDocumentPtr doc, _In_ std::wstring const& firstChildOf, _In_ MSXML::IXMLDOMNodePtr ins)
{
	MSXML::IXMLDOMNodePtr location = doc->selectSingleNode(firstChildOf.c_str());
	MSXML::IXMLDOMNodeListPtr f = doc->selectNodes((firstChildOf + std::wstring(L"/") + std::wstring(ins->nodeName)).c_str());

	if (f->length > 0)
	{
		return location->insertBefore(ins, f->item[0].GetInterfacePtr());
	}

	return location->appendChild(ins);
}

inline MSXML::IXMLDOMNodePtr PrependNode(_In_ MSXML::IXMLDOMDocumentPtr doc, _In_ std::wstring const& firstChildOf, _In_ std::wstring const& nodeName, _In_ std::wstring const& text)
{
	MSXML::IXMLDOMNodePtr ins = doc->createNode(MSXML::NODE_ELEMENT, nodeName.c_str(), L"");

	ins->text = text.c_str();

	return PrependNode(doc, firstChildOf, ins);
}

inline MSXML::IXMLDOMNodePtr CloneNode(_In_ const MSXML::IXMLDOMNodePtr & cloneMe, _In_ MSXML::IXMLDOMNodePtr & newParent)
{
	if (cloneMe == NULL)
	{
		return NULL;
	}

	MSXML::IXMLDOMNodePtr copy = cloneMe->cloneNode(VARIANT_TRUE);
	return newParent->appendChild(copy);
}

inline MSXML::IXMLDOMNodePtr CloneNode(_In_ const MSXML::IXMLDOMNodePtr & cloneBase, _In_ std::wstring const & xpathToClone, _In_ MSXML::IXMLDOMNodePtr & newParent)
{
	MSXML::IXMLDOMNodePtr cloneMe = cloneBase->selectSingleNode(xpathToClone.c_str());
	return CloneNode(cloneMe, newParent);
}

inline MSXML::IXMLDOMNodePtr CloneNode(_In_ const MSXML::IXMLDOMDocumentPtr & cloneBase, _In_ std::wstring const & xpathToClone, _In_ MSXML::IXMLDOMNodePtr & newParent)
{
	MSXML::IXMLDOMNodePtr cloneMe = cloneBase->selectSingleNode(xpathToClone.c_str());
	return CloneNode(cloneMe, newParent);
}

/// Deletes a node if it exists
inline void DeleteNode(_In_ const MSXML::IXMLDOMNodePtr &ptrNodeToDeleteFrom, _In_z_ const wchar_t* name)
{
	if (name == NULL || *name == 0)
		return;

	MSXML::IXMLDOMNodePtr nodeDel = ptrNodeToDeleteFrom->selectSingleNode(name);
	if (nodeDel != NULL)
	{
		ptrNodeToDeleteFrom->removeChild(nodeDel);
	}
}

}
#endif
