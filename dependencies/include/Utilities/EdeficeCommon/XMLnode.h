/// \file XMLnode.h
///
/// Smarter MSXML derived classes
//
//////////////////////////////////////////////////////////////////////

#pragma once
#ifndef NO_MSXML

#pragma warning (push)
#pragma warning (disable:4127)
#include <atlcomtime.h>
#pragma warning (pop)

#include <iomanip>

#include "XmlUtils.h"
#include "GlobalOperator.h"
#include "StringList.h"

namespace eXML
{
class DECLSPEC_NOVTABLE IXMLDOMNodeListPtr;

/// Node pointer. Provides a std::wstring interface to MSXML::IXMLDOMNodePtr.
class DECLSPEC_NOVTABLE IXMLDOMNodePtr : public MSXML::IXMLDOMNodePtr
{
	typedef MSXML::IXMLDOMNodePtr inherited;

public:
	/// default constructor
	IXMLDOMNodePtr() {}
	/// copy constructor
	IXMLDOMNodePtr(const IXMLDOMNodePtr& rhs) : inherited(rhs) {}
	/// construct from parent
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMNodePtr(const inherited& rhs) : inherited(rhs) {}
	/// construct from NULL
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMNodePtr(int rhs) : inherited(rhs) {}
	/// construct from DocumentElement
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMNodePtr(const MSXML::IXMLDOMElementPtr& rhs) : inherited((MSXML::IXMLDOMNodePtr)rhs) {}

	//-------------------------------------------------------------------------
	eXML::IXMLDOMNodePtr selectSingleNode(const std::wstring& node)	const
	{
		if (!operator bool())
			return NULL;
		return operator->()->selectSingleNode(node.c_str());
	}

	eXML::IXMLDOMNodePtr selectSingleNode(const wchar_t* node) const
	{
		if (!operator bool())
			return NULL;
		if ((node == NULL) || (*node == 0))
			return NULL;
		return operator->()->selectSingleNode(node);
	}

	eXML::IXMLDOMNodeListPtr selectNodes(const std::wstring& node) const;
	eXML::IXMLDOMNodeListPtr selectNodes(const wchar_t* node) const;

	//-------------------------------------------------------------------------
	eXML::IXMLDOMNodePtr AppendNode(const std::wstring& node, const std::wstring& text) const
	{
		return eXML::AppendXMLNode(*this, node.c_str(), text.c_str());
	}

	eXML::IXMLDOMNodePtr AppendNode(const std::wstring& node, const wchar_t* text = L"") const
	{
		return eXML::AppendXMLNode(*this, node.c_str(), text);
	}

	eXML::IXMLDOMNodePtr AppendNode(const wchar_t* node, const std::wstring& text) const
	{
		return eXML::AppendXMLNode(*this, node, text.c_str());
	}

	eXML::IXMLDOMNodePtr AppendNode(const wchar_t* node, const wchar_t* text = L"") const
	{
		return eXML::AppendXMLNode(*this, node, text);
	}

	eXML::IXMLDOMNodePtr AppendNode(const std::wstring& node, long number) const
	{
		return eXML::AppendXMLNode(*this, node.c_str(), number);
	}

	eXML::IXMLDOMNodePtr AppendNode(const wchar_t* node, long number) const
	{
		return eXML::AppendXMLNode(*this, node, number);
	}

	eXML::IXMLDOMNodePtr AppendNode(const std::wstring& node, const ATL::COleDateTime& datetime) const
	{
		return AppendNode(node.c_str(), datetime);
	}

	eXML::IXMLDOMNodePtr AppendNode(const wchar_t* node, const ATL::COleDateTime& datetime) const
	{
		if (datetime.GetStatus() == ATL::COleDateTime::null)
			return eXML::AppendXMLNode(*this, node, L"");
		if (datetime.GetStatus() != ATL::COleDateTime::valid)
			return NULL;

		std::wstringstream wstreamDate;
		wstreamDate.str().reserve(20);

		wstreamDate << std::setfill(L'0') << std::setw(4) << datetime.GetYear() << L"-";
		wstreamDate << std::setfill(L'0') << std::setw(2) << datetime.GetMonth() << L"-";
		wstreamDate << std::setfill(L'0') << std::setw(2) << datetime.GetDay() << L"T";
		wstreamDate << std::setfill(L'0') << std::setw(2) << datetime.GetHour() << L":";
		wstreamDate << std::setfill(L'0') << std::setw(2) << datetime.GetMinute() << L":";
		wstreamDate << std::setfill(L'0') << std::setw(2) << datetime.GetSecond();	 // << L".0Z";
		return eXML::AppendXMLNode(*this, node, wstreamDate.str().c_str());
	}

	eXML::IXMLDOMNodePtr AppendNode(const MSXML::IXMLDOMNodePtr& node) const
	{
		return operator->()->appendChild(node);
	}

	void AppendNode(const MSXML::IXMLDOMNodeListPtr& nodes) const
	{
		operator->();			// cause a com_error if pointer is NULL

		nodes->reset();
		MSXML::IXMLDOMNodePtr pnode = nodes->nextNode();
		while (pnode != NULL)
		{
			operator->()->appendChild(pnode);
			pnode = nodes->nextNode();
		}
	}

	eXML::IXMLDOMNodePtr findOrCreate(const std::wstring& path) const
	{
		return eXML::findOrCreate(*this, path);
	}

	eXML::IXMLDOMNodePtr createNodeByXPath(const std::wstring& path) const
	{
		return eXML::createNodeByXPath(*this, path);
	}

	void AppendChildrenOf(const MSXML::IXMLDOMNodePtr& node) const;

	bool AppendXML(const std::wstring& xml, bool root = true, bool children = false) const
	{
		return AppendXML(xml.c_str(), root, children);
	}

	bool AppendXML(const wchar_t* xml, bool root = true, bool children = false) const;

	/// Delete a node
	bool DeleteNode(const wchar_t* node)				///< child node name to delete, can be XPath
		const
	{
		eXML::IXMLDOMNodePtr nodeDel = selectSingleNode(node);
		if (nodeDel == NULL)
			return false;

		operator->()->removeChild(nodeDel);
		return true;
	}

	//-------------------------------------------------------------------------
	MSXML::IXMLDOMAttributePtr AddAttribute(const std::wstring& attr, const std::wstring& text) const
	{
		return AddAttribute(attr.c_str(), text.c_str());
	}

	MSXML::IXMLDOMAttributePtr AddAttribute(const std::wstring& attr, const wchar_t* text = L"") const
	{
		return AddAttribute(attr.c_str(), text);
	}

	MSXML::IXMLDOMAttributePtr AddAttribute(const wchar_t* attr, const std::wstring& text) const
	{
		return AddAttribute(attr, text.c_str());
	}

	// Add/replace attribute
	MSXML::IXMLDOMAttributePtr AddAttribute(const wchar_t* attr, const wchar_t* text = L"") const
	{
		if ((attr == NULL) || (*attr == 0) || (text == NULL))
			return NULL;

		MSXML::IXMLDOMNamedNodeMapPtr attrs = operator->()->Getattributes();
		attrs->removeNamedItem(attr);
		MSXML::IXMLDOMAttributePtr ptrAttribute = operator->()->ownerDocument->createAttribute(attr);
		attrs->setNamedItem(ptrAttribute);

		ptrAttribute->Puttext(text);
		return ptrAttribute;
	}

	MSXML::IXMLDOMAttributePtr AddAttribute(const std::wstring& attr, long number) const
	{
		return AddAttribute(attr.c_str(), number);
	}

	MSXML::IXMLDOMAttributePtr AddAttribute(const wchar_t* attr, long number) const
	{
		std::wstring textTemp;
		textTemp << number;
		return AddAttribute(attr, textTemp.c_str());
	}

	/// Delete an attribute
	bool DeleteAttribute(const wchar_t* attr)							///< attribute name to delete
		const
	{
		if (!operator bool())
			return false;
		if ((attr == NULL) || (*attr == 0))
			return false;
		return operator->()->Getattributes()->removeNamedItem(attr) != NULL;
	}

	//-------------------------------------------------------------------------

	/// tell if a node contains text
	bool NodeIsText(void) const
	{
		return eXML::NodeIsText(*this);
	}

	/// Tell if a node is number
	bool NodeIsNumber(void) const
	{
		return eXML::NodeIsNumber(*this);
	}

	__declspec(property(get=Getname))
	std::wstring name;									///< node name

	/// wrapper for name property
	std::wstring Getname(void) const
	{
		if (!operator bool())
			return L"";
		return myid::ToWstr(operator->()->GetnodeName());
	}

	__declspec(property(get=Gettext,put=Puttext))
	std::wstring text;									///< node text

	/// wrapper for text property
	std::wstring Gettext(void) const
	{
		if (!operator bool())
			return L"";
		return myid::ToWstr(operator->()->Gettext());
	}

	/// wrapper for text property
	void Puttext(const std::wstring& text)
	{
		operator->()->Puttext(text.c_str());
	}

	__declspec(property(get=Getxml))
	std::wstring xml;									///< node xml

	/// wrapper for xml property
	std::wstring Getxml(void) const
	{
		if (!operator bool())
			return L"";
		return myid::ToWstr(operator->()->Getxml());
	}

	__declspec(property(get=Getinnerxml))
	std::wstring innerxml;								///< node's inner xml (xml of all child nodes)

	/// wrapper for innerxml property
	std::wstring Getinnerxml(void) const
	{
		std::wstring xmlTemp;
		if (operator bool())
		{
			xmlTemp.reserve(1000);
			MSXML::IXMLDOMNodeListPtr children = operator->()->childNodes;
			children->reset();
			MSXML::IXMLDOMNodePtr pnode = children->nextNode();
			while (pnode != NULL)
			{
				const _bstr_t& p = pnode->Getxml();
				if (p.length() > 0)
					xmlTemp += p;
				pnode = children->nextNode();
			}
		}
		return xmlTemp;
	}

	__declspec(property(get=Getnumber,put=Putnumber))
	long number;										///< node text as a number

	/// wrapper for number property
	long Getnumber(void) const
	{
		if (!operator bool())
			return 0;
		return eXML::Getlong(*this);
	}

	/// wrapper for number property
	void Putnumber(long number)
	{
		_variant_t varLong(number);
		varLong.ChangeType(VT_BSTR);
		operator->()->Puttext(varLong.bstrVal);
	}

	/// Find out if an attribute exists
	bool AttrExists(const std::wstring& attribute)		///< attribute name
		const
	{
		return AttrExists(attribute.c_str());
	}

	/// Find out if an attribute exists
	bool AttrExists(const wchar_t* attribute)			///< attribute name
		const
	{
		if (!operator bool())
			return false;
		if ((attribute == NULL) || (*attribute == 0))
			return false;
		return operator->()->Getattributes()->getNamedItem(attribute) != NULL;
	}

	/// Get an attribute
	std::wstring Attr(const std::wstring& attribute)	///< attribute name
		const
	{
		return Attr(attribute.c_str());
	}

	/// Get an attribute
	/// \retval blank if the attribute does not exist
	std::wstring Attr(const wchar_t* attribute)			///< attribute name
		const
	{
		if (!operator bool())
			return L"";
		if ((attribute == NULL) || (*attribute == 0))
			return L"";
		eXML::IXMLDOMNodePtr attr = operator->()->Getattributes()->getNamedItem(attribute);
		return attr.text;
	}

	/// See if an attribute has a number
	bool AttrIsNumber(const std::wstring& attribute)	///< attribute name
		const
	{
		return AttrIsNumber(attribute.c_str());
	}

	/// See if an attribute has a number value
	bool AttrIsNumber(const wchar_t* attribute)			///< attribute name
		const
	{
		if (!operator bool())
			return false;
		if ((attribute == NULL) || (*attribute == 0))
			return false;
		eXML::IXMLDOMNodePtr attr = operator->()->Getattributes()->getNamedItem(attribute);
		return attr.NodeIsNumber();
	}

	/// Get a number from an attribute
	long AttrNumber(const std::wstring& attribute)		///< attribute name
		const
	{
		return AttrNumber(attribute.c_str());
	}

	/// Get a number from an attribute
	/// \retval 0 value if the attribute does not exist or does not contain a number or is blank
	long AttrNumber(const wchar_t* attribute)			///< attribute name
		const
	{
		if (!operator bool())
			return 0;
		if ((attribute == NULL) || (*attribute == 0))
			return 0;
		eXML::IXMLDOMNodePtr attr = operator->()->Getattributes()->getNamedItem(attribute);
		return attr.number;
	}

	//-------------------------------------------------------------------------

	// these are XMLParser type functions

	__declspec(property(get=GetchildNodes))
	eXML::IXMLDOMNodeListPtr childNodes;				///< child nodes

	eXML::IXMLDOMNodeListPtr GetchildNodes(void) const;

	/// See if a child node exists
	bool ChildNodeExists(const std::wstring& node)		///< child node name
		const
	{
		return ChildNodeExists(node.c_str());
	}

	/// See if a child node exists
	bool ChildNodeExists(const wchar_t* node)			///< child node name
		const
	{
		if (!operator bool())
			return false;
		if ((node == NULL) || (*node == 0))
			return false;

		_bstr_t bstrNode(node);
		MSXML::IXMLDOMNodeListPtr children = operator->()->childNodes;
		children->reset();
		MSXML::IXMLDOMNodePtr pnode = children->nextNode();
		while (pnode != NULL)
		{
			if (pnode->nodeName == bstrNode)
				return true;
			pnode = children->nextNode();
		}
		return false;
	}

	/// Get the text of a child node
	std::wstring ChildNode(const std::wstring& node,	///< child node name
						   bool blank = true)			///< \li true return blank if node does not exist
														///< \li false return _no_match  if node does not exist
		const
	{
		return ChildNode(node.c_str(), blank);
	}

	/// Get the text of a child node
	std::wstring ChildNode(const wchar_t* node,			///< child node name
						   bool blank = true)			///< \li true return blank if node does not exist
														///< \li false return _no_match  if node does not exist
		const
	{
		std::wstring textTemp;
		if (ChildNode(node, textTemp) || blank)
			return textTemp;
		return eXML::NO_NODE;
	}

	/// Get the text of the first matching child node, if the node does not exist blank is returned
	/// \return true if the node exists
	bool ChildNode(const std::wstring& node,			///< child node name
				   std::wstring& text)					///< text of child node
		const
	{
		return ChildNode(node.c_str(), text);
	}

	/// Get the text of the first matching child node, if the node does not exist blank is returned
	/// \return true if the node exists
	bool ChildNode(const wchar_t* node,					///< child node name
				   std::wstring& text)					///< text of child node
		const
	{
		text.clear();
		if (!operator bool())
			return false;
		if ((node == NULL) || (*node == 0))
			return false;

		_bstr_t bstrNode(node);
		MSXML::IXMLDOMNodeListPtr children = operator->()->childNodes;
		children->reset();
		MSXML::IXMLDOMNodePtr pnode = children->nextNode();
		while (pnode != NULL)
		{
			if (pnode->nodeName == bstrNode)
			{
				text = myid::ToWstr(pnode->Gettext());
				return true;
			}
			pnode = children->nextNode();
		}
		return false;
	}

	/// Get the number in the first matching child node, if the node does not exist 0 is returned
	/// \return true if the node exists
	bool ChildNode(const std::wstring& node,			///< child node name
				   long& number)						///< child node text as a number
		const
	{
		return ChildNode(node.c_str(), number);
	}

	/// Get the number in the first matching child node, if the node does not exist 0 is returned
	/// \return true if the node exists
	bool ChildNode(const wchar_t* node,					///< child node name
				   long& number)						///< child node text as a number
		const
	{
		std::wstring textTemp;
		bool rtn = ChildNode(node, textTemp);
		if (rtn)
			number = _wtol(textTemp.c_str());
		else
			number = 0;

		return rtn;
	}

	/// Get the number in the first matching child node, if the node does not exist 0 is returned
	long ChildNodeLong(const std::wstring& node)		///< child node name
		const
	{
		long rtn;
		ChildNode(node.c_str(), rtn);
		return rtn;
	}

	/// Get the number in the first matching child node, if the node does not exist 0 is returned
	long ChildNodeLong(const wchar_t* node)				///< child node name
		const
	{
		long rtn;
		ChildNode(node, rtn);
		return rtn;
	}

	/// Get the text of all matching child nodes
	void ChildNodes(const std::wstring& node,			///< child node name to match
					StringList& text)					///< text of matching child nodes
		const
	{
		ChildNodes(node.c_str(), text);
	}

	/// Get the text of all matching child nodes
	void ChildNodes(const wchar_t* node,				///< child node name to match
					StringList& text)					///< text of matching child nodes
		const
	{
		text.clear();
		if (operator bool() && (node != NULL) && *node)
		{
			text.reserve(25);
			_bstr_t bstrNode(node);
			MSXML::IXMLDOMNodeListPtr children = operator->()->childNodes;
			children->reset();
			MSXML::IXMLDOMNodePtr pnode = children->nextNode();

			while (pnode != NULL)
			{
				if (pnode->nodeName == bstrNode)
				{
					text.push_back(myid::ToWstr(pnode->Gettext()));
				}
				pnode = children->nextNode();
			}
		}
	}

	/// Get the text of all matching child nodes
	StringList ChildNodes(const std::wstring& node)		///< child node name to match
		const
	{
		StringList textTemp;
		ChildNodes(node.c_str(), textTemp);
		return textTemp;
	}

	/// Get the text of all matching child nodes
	StringList ChildNodes(const wchar_t* node)			///< child node name to match
		const
	{
		StringList textTemp;
		ChildNodes(node, textTemp);
		return textTemp;
	}

	/// Get the number from all matching child nodes
	void ChildNodesLong(const std::wstring& node,		///< child node name to match
						LongList& num)					///< number from matching child nodes
		const
	{
		ChildNodesLong(node.c_str(), num);
	}

	/// Get the number from all matching child nodes
	void ChildNodesLong(const wchar_t* node,			///< child node name to match
						LongList& num)					///< number from matching child nodes
		const
	{
		num.clear();
		if (operator bool() && (node != NULL) && *node)
		{
			num.reserve(25);
			_bstr_t bstrNode(node);
			MSXML::IXMLDOMNodeListPtr children = operator->()->childNodes;
			children->reset();
			MSXML::IXMLDOMNodePtr pnode = children->nextNode();

			while (pnode != NULL)
			{
				if (pnode->nodeName == bstrNode)
				{
					num.push_back(_wtol(pnode->Gettext()));
				}
				pnode = children->nextNode();
			}
		}
	}

	/// Get the number from all matching child nodes
	LongList ChildNodesLong(const std::wstring& node)	///< child node name to match
		const
	{
		LongList num;
		ChildNodesLong(node.c_str(), num);
		return num;
	}

	/// Get the number from all matching child nodes
	LongList ChildNodesLong(const wchar_t* node)		///< child node name to match
		const
	{
		LongList num;
		ChildNodesLong(node, num);
		return num;
	}
};

/// Node list, extracts eXML::IXMLDOMNodePtr objects
class DECLSPEC_NOVTABLE IXMLDOMNodeListPtr : public MSXML::IXMLDOMNodeListPtr
{
	typedef MSXML::IXMLDOMNodeListPtr inherited;

public:
	/// default constructor
	IXMLDOMNodeListPtr() {}
	/// copy constructor
	IXMLDOMNodeListPtr(const IXMLDOMNodeListPtr& rhs) : inherited(rhs) {}
	/// construct from parent
	IXMLDOMNodeListPtr(const inherited& rhs) : inherited(rhs) {}
	/// construct from NULL
	IXMLDOMNodeListPtr(int rhs) : inherited(rhs) {}

	__declspec(property(get=Getitem))
	eXML::IXMLDOMNodePtr item[];						///< random access to node list

	/// wrapper for item property array
	eXML::IXMLDOMNodePtr Getitem (long index)
	{
		if (!operator bool())
			return NULL;
		return operator->()->Getitem(index);
	}

	__declspec(property(get=Getlength))
	long length;										///< length of node list

	/// wrapper for length property
	long Getlength(void) const
	{
		if (!operator bool())
			return 0;
		return operator->()->Getlength();
	}

	__declspec(property(get=firstNode))
	eXML::IXMLDOMNodePtr first;							///< first node

	eXML::IXMLDOMNodePtr firstNode(void) const
	{
		if (!operator bool())
			return NULL;
		operator->()->reset();
		return operator->()->nextNode();
	}

	__declspec(property(get=nextNode))
	eXML::IXMLDOMNodePtr next;							///< next node

	eXML::IXMLDOMNodePtr nextNode(void) const
	{
		if (!operator bool())
			return NULL;
		return operator->()->nextNode();
	}

	__declspec(property(get=Getxml))
	std::wstring xml;									///< node list xml

	/// wrapper for xml property
	std::wstring Getxml(void) const
	{
		std::wstring xmlTemp;
		if (operator bool())
		{
			xmlTemp.reserve(1000);
			operator->()->reset();
			MSXML::IXMLDOMNodePtr pnode = operator->()->nextNode();
			while (pnode != NULL)
			{
				const _bstr_t& p = pnode->Getxml();
				if (p.length() > 0)
					xmlTemp += p;
				pnode = operator->()->nextNode();
			}
		}
		return xmlTemp;
	}

};

/// Document pointer. It extracts eXML::IXMLDOMNodePtr objects and provides
/// a std::wstring interface.
class DECLSPEC_NOVTABLE IXMLDOMDocumentPtr : public MSXML::IXMLDOMDocumentPtr
{
	typedef MSXML::IXMLDOMDocumentPtr inherited;

public:
	/// default constructor
	IXMLDOMDocumentPtr() {}
	/// copy constructor
	IXMLDOMDocumentPtr(const IXMLDOMDocumentPtr& rhs) : inherited(rhs) {}
	/// construct from parent
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMDocumentPtr(const inherited& rhs) : inherited(rhs) {}
	/// construct from NULL
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMDocumentPtr(int rhs) : inherited(rhs) {}
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMDocumentPtr(wchar_t const * const xml) : inherited(eXML::ToXmlDocument(xml)) {}
	// cppcheck-suppress noExplicitConstructor
	IXMLDOMDocumentPtr(std::wstring const & xml) : inherited(eXML::ToXmlDocument(xml)) {}

	/// Load from URL
	bool load(const std::wstring& xmlSource)
	{
		return load(xmlSource.c_str());
	}

	/// Load from URL
	bool load(const wchar_t* xmlSource)
	{
		createInstance();

		return operator->()->load(xmlSource) != FALSE;
	}

	/// load XML, the object will be created if required
	bool loadXML(const std::wstring& xml)
	{
		return loadXML(xml.c_str());
	}

	/// load XML, the object will be created if required
	bool loadXML(const wchar_t* xml)
	{
		createInstance();

		return operator->()->loadXML(xml) != FALSE;
	}

	/// load XML, the object will be created if required
	/// \return root node or NULL
	eXML::IXMLDOMNodePtr LoadXML(const std::wstring& xml)
	{
		return LoadXML(xml.c_str());
	}

	/// load XML, the object will be created if required
	/// \return root node or NULL
	eXML::IXMLDOMNodePtr LoadXML(const wchar_t* xml)
	{
		createInstance();

		if (operator->()->loadXML(xml) == FALSE)
			return NULL;

		return GetdocumentElement();
	}

	/// Loads an XML document without a root node
	bool loadXMLNoRoot(const std::wstring& xml, const wchar_t* rootnode = L"Parameters")
	{
		createInstance();

		std::wstring wstrXml;
		wstrXml.reserve(xml.size() + 100);
		wstrXml << L"<" << rootnode << L">";
		wstrXml << xml;
		wstrXml << L"</" << rootnode << L">";

		return loadXML(wstrXml.c_str());
	}

	/// create a new XML doc with optional header
	/// \return root node or NULL
	eXML::IXMLDOMNodePtr newDoc(const std::wstring& rootnode, bool header = false)
	{
		return newDoc(rootnode.c_str(), header);
	}

	/// create a new XML doc with optional header
	/// \return root node or NULL
	eXML::IXMLDOMNodePtr newDoc(const wchar_t* rootnode = L"Parameters", bool header = false)
	{
		createInstance();

		std::wstring wstrXml;
		wstrXml.reserve(100);
		if (header)
			wstrXml += L"<?xml version=\"1.0\" encoding=\"utf-8\"?>";
		wstrXml << L"<" << rootnode << L">";
		wstrXml << L"</" << rootnode << L">";
		if (!loadXML(wstrXml.c_str()))
			return NULL;

		return GetdocumentElement();
	}

	/// Create the object
	void createInstance(void)
	{
		if (GetInterfacePtr() == NULL)
			CreateInstance(myPROGID_DOMDocument);
	}

	/// force instantiation of a Free-Threaded DOM object, in order to allow multithreaded access to the underlying DOM
	/// any previously loaded instance data will be cleared, and a new empty FreeThreadedDOMDocument instance created
	/// This method must be called prior to loading a new DOM, when the object may be used from multiple threads
	/// however it is not possible to exchange nodes between a FreeThreadedDOMDocument and a regular DOMDocument
	void createInstanceForceFreeThreaded(void)
	{
		CreateInstance(myPROGID_FreeThreadedDOMDocument);
	}

	eXML::IXMLDOMNodePtr selectSingleNode(const std::wstring& node) const
	{
		if (!operator bool())
			return NULL;
		return operator->()->selectSingleNode(node.c_str());
	}

	eXML::IXMLDOMNodePtr selectSingleNode(const wchar_t* node) const
	{
		if (!operator bool())
			return NULL;
		if ((node == NULL) || (*node == 0))
			return NULL;
		return operator->()->selectSingleNode(node);
	}

	eXML::IXMLDOMNodeListPtr selectNodes(const std::wstring& node) const
	{
		if (!operator bool())
			return NULL;
		return operator->()->selectNodes(node.c_str());
	}

	eXML::IXMLDOMNodeListPtr selectNodes(const wchar_t* node) const
	{
		if (!operator bool())
			return NULL;
		if ((node == NULL) || (*node == 0))
			return NULL;
		return operator->()->selectNodes(node);
	}

	// these are XMLParser type functions

	eXML::IXMLDOMNodePtr findOrCreate(const std::wstring& path) const
	{
		return eXML::findOrCreate(*this, path);
	}

	__declspec(property(get=GetdocumentElement))
	eXML::IXMLDOMNodePtr documentElement;		///< document node

	eXML::IXMLDOMNodePtr GetdocumentElement()
	{
		return (MSXML::IXMLDOMNodePtr)operator->()->GetdocumentElement();
	}

	const eXML::IXMLDOMNodePtr GetdocumentElement() const
	{
		return (const MSXML::IXMLDOMNodePtr)operator->()->GetdocumentElement();
	}

	__declspec(property(get=Getxml))
	std::wstring xml;							///< node xml

	/// wrapper for xml property
	std::wstring Getxml(void) const
	{
		if (!operator bool())
			return L"";
		return myid::ToWstr(operator->()->Getxml());
	}

	std::wstring transformNode(MSXML::IXMLDOMDocumentPtr transform)
	{
		if (!operator bool())
			return L"";
		return myid::ToWstr(operator->()->transformNode(transform));
	}

	// Similar to ChildNodeExists but for XPath instead
	bool ContainsNode(const std::wstring &xpath) const
	{
		return ContainsNode(xpath.c_str());
	}
	bool ContainsNode(const wchar_t *xpath) const
	{
		IXMLDOMNodePtr node = selectSingleNode(xpath);
		return node;
	}
};

/// Appends children supplied as XML.
/// \return true if succeded
inline bool eXML::IXMLDOMNodePtr::AppendXML(const wchar_t* xml,	///< XML source
											bool root,			///< \li true XML has a single root node
																///< \li false XML is a list of nodes
											bool children)		///< only applies if root is true
																///< \li true append children of root
																///< \li false append root node as only child
	const
{
	eXML::IXMLDOMDocumentPtr doc;
	if (root)
	{
		if (!doc.loadXML(xml))
			return false;
	}
	else
	{
		if (!doc.loadXMLNoRoot(xml))
			return false;
		children = true;
	}

	eXML::IXMLDOMNodePtr rootNode = doc.documentElement;
	if (rootNode != NULL)
	{
		if (children)
			AppendChildrenOf(rootNode);
		else
			operator->()->appendChild(rootNode);
		return true;
	}
	return false;
}


inline eXML::IXMLDOMNodeListPtr eXML::IXMLDOMNodePtr::selectNodes(const std::wstring& node) const
{
	if (!operator bool())
		return NULL;
	return operator->()->selectNodes(node.c_str());
}

inline eXML::IXMLDOMNodeListPtr eXML::IXMLDOMNodePtr::selectNodes(const wchar_t* node) const
{
	if (!operator bool())
		return NULL;
	if ((node == NULL) || (*node == 0))
		return NULL;
	return operator->()->selectNodes(node);
}

/// transfer children of node to self
inline void eXML::IXMLDOMNodePtr::AppendChildrenOf(const MSXML::IXMLDOMNodePtr& node) const
{
	if (node != NULL)
	{
		eXML::IXMLDOMNodeListPtr nodes(node->childNodes);
		while (nodes.length > 0)
			operator->()->appendChild(nodes.item[0]);
	}
}

/// wrapper for childNodes property
inline eXML::IXMLDOMNodeListPtr eXML::IXMLDOMNodePtr::GetchildNodes(void) const
{
	if (!operator bool())
		return NULL;
	return operator->()->childNodes;
}


} // namespace eXML
#endif
