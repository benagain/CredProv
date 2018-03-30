#pragma once

#include "CatchCommon.h"
#include "CatchException.h"

#include "Utilities/EdeficeCommon/Conversions/StringUtils.h"
#include "Utilities/EdeficeCommon/Conversions/VectorOfByteConversion.h"
#include "Utilities/EdeficeCommon/StringList.h"
#include "Utilities/EdeficeCommon/XMLnode.h"

namespace Catch {
namespace Matchers {
	
	namespace Impl { namespace Xml { struct HasNode; struct HasNoNode; } }

	/**
		CHECK_THAT( xml, HasNode("p/node/leaf") );
		CHECK_THAT( xml, HasNode("p/node/leaf").Equal("value") );
		CHECK_THAT( xml, HasNoNode("p/node/leaf") );

		CHECK_THAT( xml, HasNode("p/node/leaf").WithAttribute("name") );
		CHECK_THAT( xml, HasNode("p/node/leaf").WithAttribute("name").Equal("value") );
		CHECK_THAT( xml, HasNode("p/node/leaf").WithoutAttribute("name") );

		CHECK_THAT matcher that looks for the node defined by the xpath and ensures
		a variety of states of the node and its attributes.
	
		If the CHECK fails it returns readable output that pinpoints the line
		of the CHECK, the XML input, the xpath and expected state.
		
		e.g.
		1>  TestImport.cpp(590): FAILED:
		1>    CHECK_THAT( query HasNode(L"Parameters/Add[FieldName='DeviceSerialNo']/FieldValue").Equal(L"552") )
		1>  with expansion:
		1>    <Parameters><Add><FieldName>DeviceSerialNo</FieldName><FieldValue>55<
		1>    /FieldValue><FieldType>string</FieldType></Add></Parameters>
		1>
		1>     expected to have node
		1>      "Parameters/Add[FieldName='DeviceSerialNo']/FieldValue"
		1>    with value "552"
		1>    but value was ""

	**/
	template<typename T>
	inline Impl::Xml::HasNode    HasNode(const std::basic_string<T> & xpath);

	template<typename T>
	inline Impl::Xml::HasNode    HasNode(const T* xpath);

	template<typename T>
	inline Impl::Xml::HasNoNode  HasNoNode(const std::basic_string<T> & xpath);

	template<typename T>
	inline Impl::Xml::HasNoNode  HasNoNode(const T* xpath);

}}


namespace Catch {
namespace XML {

	// ---------------------------------------------------------------------------------------------
	// Helper functions for XML testing
	// ---------------------------------------------------------------------------------------------

	/*!
	* Loads an XML document from a wide string into an IXMLDOMNodePtr or fails the test if the
	* provided wide string does not contain a valid XML document
	*
	* \param[in] wstrXML
	*   A wide string containing a valid XML document
	* \param[in] bPrintXML
	*   A flag to indicate whether the value of wstrXML should be printed to the test info stream
	*
	* \returns
	*   An IXMLDOMNodePtr to the root element of the loaded XML document
	*/
	inline eXML::IXMLDOMNodePtr LoadXML(const wchar_t* wstrXML, bool bPrintXML)
	{
		if (bPrintXML)
		{
			INFO("wstrXML = " << myid::ToStr(wstrXML));
		}

		auto pXMLDoc = eCom::CreateComPtr<MSXML::IXMLDOMDocumentPtr>(myPROGID_DOMDocument);

		REQUIRE(pXMLDoc->loadXML(wstrXML));
		return pXMLDoc->GetdocumentElement();
	}

	// ---------------------------------------------------------------------------------------------

	/*!
	* Given an XML node, validates that the text content of the node matches a specified value
	*
	* \param[in] pNode
	*   The XML node to check the text content of
	* \param[in] wstrExpectedValue
	*   The text that the node is expected to contain
	* \param[in] bCaseSensitive
	*   A flag to indicate whether the comparison should be case sensitive or not
	*/
	inline void RequireNodeValue(eXML::IXMLDOMNodePtr pNode, const wchar_t* wstrExpectedValue, bool bCaseSensitive = false)
	{
		INFO("node value = '" << pNode->text << "', expecting '" << myid::ToStr(wstrExpectedValue) << "'");

		if (bCaseSensitive)
		{
			CHECK(0 == wcscmp(wstrExpectedValue, pNode->text));
		}
		else
		{
			CHECK(0 == _wcsicmp(wstrExpectedValue, pNode->text));
		}
	}

	// ---------------------------------------------------------------------------------------------

	/*!
	* Given an XML base node and an XPath expression, checks that a node exists that matches the
	* XPath expression and that the text content of that node matches a specified value
	*
	* \param[in] pBaseNode
	*   The XML node from which the XPath expression is rooted
	* \param[in] wstrXPath
	*   The XPath expression to be used
	* \param[in] wstrExpectedValue
	*   The text that the node found by the XPath expression is expected to contain
	* \param[in] bCaseSensitive
	*   A flag to indicate whether the comparison should be case sensitive or not
	*/
	inline void RequireNodeValue(eXML::IXMLDOMNodePtr pBaseNode, const wchar_t* wstrXPath, const wchar_t* wstrExpectedValue, bool bCaseSensitive = false)
	{
		INFO("expecting node '" << myid::ToStr(wstrXPath) << "' to contain '" << myid::ToStr(wstrExpectedValue) << "'");
		INFO(pBaseNode->xml);

		eXML::IXMLDOMNodePtr pNode = pBaseNode->selectSingleNode(wstrXPath);
		REQUIRE(pNode);
		RequireNodeValue(pNode, wstrExpectedValue, bCaseSensitive);
	}

	// ---------------------------------------------------------------------------------------------

	/*!
	* Given an XML node, validates that the named attribute exists and its value matches a
	* specified value
	*
	* \param[in] pNode
	*   The XML node to check an attribute of
	* \param[in] wstrAttribute
	*   The name of the attribute to be checked
	* \param[in] wstrExpectedValue
	*   The value that the attribute is expected to contain
	* \param[in] bCaseSensitive
	*   A flag to indicate whether the comparison should be case sensitive or not
	*/
	inline void RequireAttributeValue(eXML::IXMLDOMNodePtr pNode, const wchar_t* wstrAttribute, const wchar_t* wstrExpectedValue, bool bCaseSensitive = false)
	{
		INFO("wstrAttribute = " << myid::ToStr(wstrAttribute));
		INFO( pNode->xml );

		MSXML::IXMLDOMAttributePtr ptrAttrib = pNode->attributes->getNamedItem(wstrAttribute);
		REQUIRE(ptrAttrib);

		INFO("attribute value = '" << ptrAttrib->text << "', expecting '" << myid::ToStr(wstrExpectedValue) << "'");

		if (bCaseSensitive)
		{
			CHECK(0 == wcscmp(wstrExpectedValue, ptrAttrib->text));
		}
		else
		{
			CHECK(0 == _wcsicmp(wstrExpectedValue, ptrAttrib->text));
		}
	}

} // namespace XML
} // namespace Catch



namespace Catch {
	inline std::string toString(MSXML::IXMLDOMNodePtr value)
	{
		return myid::ToStr(eXML::IXMLDOMNodePtr(value).xml);
	}
	inline std::string toString(MSXML::IXMLDOMDocumentPtr value)
	{
		return myid::ToStr(value->xml);
	}
}

namespace Catch {
namespace Matchers {
namespace Impl {
namespace Xml
{
	struct NodeMatcher
	{
		NodeMatcher() : xpath(L"") { }
		NodeMatcher(const std::wstring & xpath) : xpath(xpath) { }

		template<typename T>
		bool match(const T & xml) const
		{
			return findNode(xml);
		}

		template<typename T>
		eXML::IXMLDOMNodePtr findNode(const T & xml) const
		{
			eXML::IXMLDOMDocumentPtr document = eCom::CreateComPtr<MSXML::IXMLDOMDocumentPtr>(myPROGID_DOMDocument);
			if (!document.loadXML(xml)) return false;

			return findNode((MSXML::IXMLDOMNodePtr)document);
		}

		eXML::IXMLDOMNodePtr findNode(MSXML::IXMLDOMNodePtr document) const
		{
			return ((eXML::IXMLDOMNodePtr)document).selectSingleNode(xpath);
		}

		eXML::IXMLDOMNodePtr findNode(MSXML::IXMLDOMDocumentPtr document) const
		{
			return document->selectSingleNode(myid::ToBstr(xpath));
		}
		virtual std::string toString() const { return ""; }

		std::wstring xpath;
	};


	struct HasNode : MatcherImpl<HasNode, std::wstring>, NodeMatcher
	{
		HasNode(const std::wstring & xpath) : NodeMatcher(xpath) { }
		HasNode(const HasNode & other) : NodeMatcher(other.xpath) { }
		
		virtual bool match(const BSTR xml) const
		{
			return match(myid::ToWstr(xml));
		}
		virtual bool match(const bstr_t & xml) const
		{
			return match(myid::ToWstr(xml));
		}
		virtual bool match(const std::wstring & xml) const
		{
			return NodeMatcher::match<std::wstring>(xml);
		}
		template <typename T>
		bool match(T xml) const
		{
			return NodeMatcher::match<T>(xml);
		}

		virtual std::string toString() const
		{
			return "\nexpected to have node\n  \"" + myid::ToStr(xpath) + "\"";
		}

		struct BaseMatcher;

		struct EqualMatcher;
		struct EqualMatcher Equal(const std::wstring & value);

		struct ContainsMatcher;
		struct ContainsMatcher Contains(const std::wstring & value);

		struct WithAttributeMatcher;
		struct WithAttributeMatcher WithAttribute(const std::wstring & name);

		struct WithoutAttributeMatcher;
		struct WithoutAttributeMatcher WithoutAttribute(const std::wstring & name);
	};

	struct HasNode::BaseMatcher : MatcherImpl<BaseMatcher, std::wstring>
	{
		BaseMatcher(const NodeMatcher & hasNode, const std::wstring & value) : hasNode(hasNode), value(value) { }
		BaseMatcher(const BaseMatcher & is) : hasNode(is.hasNode), value(is.value) { }

		virtual bool match(const std::wstring & xml) const
		{
			return match<std::wstring>(xml);
		}

		// Need to define this so the above method has something to link against
		// Assume failure as we expect the subclass to correctly implement this
		template<typename T>
		bool match(const T &) const
		{
			return false;
		};

		virtual std::string toString() const
		{
			std::string r = hasNode.toString() + "\nwith value \"" + myid::ToStr(value) + "\"";
			r += "\nbut value was \"" + myid::ToStr(actualValue) + "\"";
			return r;
		}

	protected:
		std::wstring value;
		NodeMatcher hasNode;
		mutable std::wstring actualValue;
	};

	struct HasNode::EqualMatcher : BaseMatcher
	{
		EqualMatcher(const NodeMatcher & hasNode, const std::wstring & value) : BaseMatcher(hasNode, value) { }
		EqualMatcher(const EqualMatcher & is) : BaseMatcher(is.hasNode, is.value) { }

		template<typename T>
		bool match(const T & xml) const
		{
			return ((NodeMatcher)hasNode).match(xml) 
				&& (actualValue = hasNode.findNode(xml).text) == value;
		}
	};

	inline HasNode::EqualMatcher HasNode::Equal(const std::wstring & value) { return EqualMatcher(xpath, value); }

	struct HasNode::ContainsMatcher : BaseMatcher
	{
		ContainsMatcher(const NodeMatcher & hasNode, const std::wstring & value) : BaseMatcher(hasNode, value) { }
		ContainsMatcher(const ContainsMatcher & is) : BaseMatcher(is.hasNode, is.value) { }

		template<typename T>
		bool match(const T & xml) const
		{
			if(false == ((NodeMatcher)hasNode).match(xml))
				return false;

			actualValue = hasNode.findNode(xml).text;
			return (T::npos != actualValue.find(value));
		}
	};

	inline HasNode::ContainsMatcher HasNode::Contains(const std::wstring & value) { return ContainsMatcher(xpath, value); }

	struct HasNode::WithAttributeMatcher : MatcherImpl<HasNode::WithAttributeMatcher, std::wstring>
	{
		WithAttributeMatcher(const HasNode & hasNode, const std::wstring & name) : hasNode(hasNode), name(name) { }
		WithAttributeMatcher(const WithAttributeMatcher & is) : hasNode(is.hasNode), name(is.name) { }
		virtual ~WithAttributeMatcher() { }

		virtual bool match(const std::wstring & xml) const
		{
			return match<std::wstring>(xml);
		}

		template<typename T>
		bool match(const T & xml) const
		{
			return ((NodeMatcher)hasNode).match(xml)
				&& hasNode.findNode(xml).AttrExists(name);
		}

		virtual std::string toString() const
		{
			return hasNode.toString() + "\"\nwith attribute \"" + myid::ToStr(name) + "\"";
		}

		struct AttributeEqualMatcher;
		AttributeEqualMatcher Equal(const std::wstring & value);

		std::wstring name;
		HasNode hasNode;
	};

	inline HasNode::WithAttributeMatcher HasNode::WithAttribute(const std::wstring & value) { return HasNode::WithAttributeMatcher(xpath, value); }

	struct HasNode::WithAttributeMatcher::AttributeEqualMatcher : MatcherImpl<HasNode::WithAttributeMatcher::AttributeEqualMatcher, std::wstring>
	{
		AttributeEqualMatcher(const WithAttributeMatcher & hasNode, const std::wstring & value) : withAttr(hasNode), value(value) { }
		AttributeEqualMatcher(const AttributeEqualMatcher & is) : withAttr(is.withAttr), value(is.value) { }

		virtual bool match(const std::wstring & xml) const
		{
			return match<std::wstring>(xml);
		}

		template<typename T>
		bool match(const T & xml) const
		{
			return withAttr.match(xml) &&
				(actualValue = withAttr.hasNode.findNode(xml).Attr(withAttr.name)) == value;
		}

		virtual std::string toString() const
		{
			std::string r = withAttr.toString() + "\"\nwith value \"" + myid::ToStr(value) + "\"";
			r += "\nbut value was \"" + myid::ToStr(actualValue) + "\"";
			return r;
		}


		std::wstring value;
		WithAttributeMatcher withAttr;
		mutable std::wstring actualValue;
	};

	inline HasNode::WithAttributeMatcher::AttributeEqualMatcher HasNode::WithAttributeMatcher::Equal(const std::wstring & value) { return AttributeEqualMatcher(*this, value); }


	struct HasNode::WithoutAttributeMatcher : MatcherImpl<HasNode::WithoutAttributeMatcher, std::wstring>
	{
		WithoutAttributeMatcher(const WithAttributeMatcher & hasNode) : with(hasNode) { }
		WithoutAttributeMatcher(const WithoutAttributeMatcher & is) : with(is.with) { }

		virtual bool match(const std::wstring & xml) const
		{
			return !with.match(xml);
		}

		virtual std::string toString() const
		{
			return with.hasNode.toString() + "\"\nwithout attribute \"" + myid::ToStr(with.name) + "\"";
		}

		WithAttributeMatcher with;
	};

	inline HasNode::WithoutAttributeMatcher HasNode::WithoutAttribute(const std::wstring & value) 
	{ 
		return HasNode::WithoutAttributeMatcher(HasNode::WithAttributeMatcher(*this, value));
	}

	struct HasNoNode : MatcherImpl<HasNoNode, std::wstring>, NodeMatcher
	{
		HasNoNode(const std::wstring & xpath) : NodeMatcher(xpath) { }
		HasNoNode(const HasNoNode & other) : NodeMatcher(other.xpath) { }

		virtual bool match(const std::wstring & xml) const
		{
			return ! NodeMatcher::match<std::wstring>(xml);
		}

		template <typename T>
		bool match(T xml) const
		{
			return ! NodeMatcher::match<T>(xml);
		}
		virtual std::string toString() const
		{
			return "\nexpected not to have node\n  \"" + myid::ToStr(xpath) + "\"";
		}
	};
}}

	template<typename T>
	inline Impl::Xml::HasNode    HasNode(const std::basic_string<T> & xpath) {
		return Impl::Xml::HasNode(xpath);
	}

	template<typename T>
	inline Impl::Xml::HasNode    HasNode(const T* xpath) {
		return Impl::Xml::HasNode(std::basic_string<T>(xpath));
	}

	template<typename T>
	inline Impl::Xml::HasNoNode  HasNoNode(const std::basic_string<T> & xpath) {
		return Impl::Xml::HasNoNode(xpath);
	}

	template<typename T>
	inline Impl::Xml::HasNoNode  HasNoNode(const T* xpath) {
		return Impl::Xml::HasNoNode(std::basic_string<T>(xpath));
	}
}}
