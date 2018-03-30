#pragma once

#include <vector>
#include <string>
#include <list>

#include "MockCommon.h"
#include "../XMLnode.h"
#include "../XMLIterator.h"
#include "../Conversions/Numbers.h"

namespace myid
{
	namespace testing
	{
		inline bool LoadXML(eXML::IXMLDOMDocumentPtr& doc, const wchar_t* xml)
		{
			return doc.loadXML(xml);
		}

		inline bool LoadXML(eXML::IXMLDOMDocumentPtr& doc, const std::wstring& xml)
		{
			return doc.loadXML(xml);
		}

		inline bool LoadXML(eXML::IXMLDOMDocumentPtr& doc, const variant_t& xml)
		{
			if(VT_BSTR != xml.vt)
				return false;

			return doc.loadXML(xml.bstrVal);
		}

		namespace gmock
		{
			/* This gets used a lot, hence has its own functor rather than a lambda.
			It also needs overloads for template purposes. */
			class XmlNodeMatches
			{
				const std::wstring Value_;
				/* This can't be non-copyable but we need to override the copy assignment
				or we get "cannot generator assignment operator" error. */
				XmlNodeMatches &operator=(const XmlNodeMatches &rhs) /* = delete*/;
			public:
				XmlNodeMatches(const std::wstring &value)
					: Value_(value)
				{
				}
				XmlNodeMatches(long value)
					: Value_(myid::LONGtoWSTR(value))
				{
				}	
				bool operator()(const eXML::IXMLDOMNodePtr &node) const
				{
					const std::wstring val = eXML::GetNodeTextIgnoringChildNodes(node);
					return val == Value_;
				}
			};

			/* This requires that nodes with the same name are contiguous in the
			input list.  If they are not, the results are undefined. */
			template<typename NodeNameIter, typename ValueIter>
			class XmlChildNodesMatch
			{
				NodeNameIter m_FirstNodeName, m_LastNodeName;
				ValueIter m_FirstValue, m_LastValue;
				::testing::MatchResultListener *m_result_listener;

				bool FindAndExtractValue(const ValueIter &valueIter, std::list<std::wstring> &values, const NodeNameIter &nodeIter) const
				{
					auto pos = std::find(values.begin(), values.end(), *valueIter);
					if (pos == values.end())
					{
						if (m_result_listener)
						{
							*m_result_listener << "Could not find value \"" << ::testing::PrintToString(*valueIter)
								<< "\" in node \"" << ::testing::PrintToString(*nodeIter) << "\"";
						}
						return false;
					}
					values.erase(pos);
					return true;
				}
			public:
				XmlChildNodesMatch(const NodeNameIter &firstNode, const NodeNameIter &lastNode,
					const ValueIter &firstValue, const ValueIter &lastValue,
					::testing::MatchResultListener *result_listener)
					: m_FirstNodeName(firstNode)
					, m_LastNodeName(lastNode)
					, m_FirstValue(firstValue)
					, m_LastValue(lastValue)
					, m_result_listener(result_listener)
				{
				}
				bool operator()(const eXML::IXMLDOMNodePtr &node) const
				{
					ValueIter valueIter = m_FirstValue;
					/* We may increment the iterators during the loop,
					hence this is not an algorithm call. */
					for (NodeNameIter nodeIter = m_FirstNodeName;
						nodeIter != m_LastNodeName;
						++nodeIter, ++valueIter)
					{
						const StringList &orgValues = node.ChildNodes(*nodeIter);
						if (orgValues.empty())
						{
							if (m_result_listener)
							{
								*m_result_listener << "Could not find child node \"" << ::testing::PrintToString(*nodeIter)
									<< "\"";
							}
							return false;
						}
						std::list<std::wstring> values(orgValues.begin(), orgValues.end()); // List allows easy removal of elements in the middle
						if (!FindAndExtractValue(valueIter, values, nodeIter))
						{
							return false;
						}

						/* Here is where we assume that nodes with the same name
						are contiguous in the input range. */
						auto nextNode = nodeIter;
						++nextNode;
						auto nextValue = valueIter;
						++nextValue;
						std::iterator_traits<NodeNameIter>::difference_type foundAdjacentNodes = 0;
						while (nextNode != m_LastNodeName
							&& *nextNode == *nodeIter)
						{
							if (!FindAndExtractValue(nextValue, values, nextNode))
							{
								return false;
							}

							++foundAdjacentNodes;
							++nextNode;
							++nextValue;
						}
						/* If there are any additional nodes in the XML with this name that are not expected,
						they will still be in the "values" container. */
						std::list<std::wstring> emptyList;
						if (!::testing::ExplainMatchResult(::testing::ContainerEq(emptyList), values, m_result_listener))
						{
							return false;
						}
						// If we processed any nodes with the same name there's no need to do them again.
						std::advance(nodeIter, foundAdjacentNodes);
						std::advance(valueIter, foundAdjacentNodes);
					}
					return true;
				}
			};

			MATCHER_P(HasNode, xpath, "Verifies that the specified node exists")
			{
				eXML::IXMLDOMDocumentPtr doc;
				if (!LoadXML(doc, arg))
				{
					if (result_listener)
					{
						*result_listener << "Argument is not valid XML";
					}

					return false;
				}
		
				const auto &node = doc.selectSingleNode(xpath);
				if (!node)
				{
					if (result_listener)
					{
						// This stream is narrow but arg is probably wide, so it has to be converted
						*result_listener << "XPath \"" << ::testing::PrintToString(xpath) << "\" does not match";
					}
					return false;
				}
				return true;
			}
			
			MATCHER_P(HasNoNode, xpath, "Verifies that the specified node does not exist")
			{
				eXML::IXMLDOMDocumentPtr doc;
				if (!LoadXML(doc, arg))
				{
					if (result_listener)
					{
						*result_listener << "Argument is not valid XML";
					}

					return false;
				}
		
				const auto &node = doc.selectSingleNode(xpath);
				if (node)
				{
					if (result_listener)
					{
						// This stream is narrow but arg is probably wide, so it has to be converted
						*result_listener << "XPath \"" << ::testing::PrintToString(xpath) << "\" matches";
					}
					return false;
				}
				return true;
			}
			
			MATCHER_P2(HasNodeEqual, xpath, value, "Verifies that the specified node exists and has the correct value")
			{
				eXML::IXMLDOMDocumentPtr doc;
				if (!LoadXML(doc, arg))
				{
					if (result_listener)
					{
						*result_listener << "Argument is not valid XML";
					}

					return false;
				}
		
				auto nodelist = doc.selectNodes(xpath);
				// We can get back a list object containing zero nodes
				if (!static_cast<bool>(nodelist) || !nodelist.length)
				{
					if (result_listener)
					{
						*result_listener << "XPath \"" << ::testing::PrintToString(xpath) << "\" does not match";
					}

					return false;
				}

				XmlNodeMatches m(value);
				auto iter = std::find_if(eXML::NodeList::begin(nodelist), eXML::NodeList::end(nodelist), m);
				if (iter == eXML::NodeList::end(nodelist))
				{
					if (result_listener)
					{
						*result_listener << "None of the matching nodes contain the value \"" << ::testing::PrintToString(value) << "\"";
					}
					return false;
				}
				return true;
			}

			MATCHER_P3(HasChildNodesWithValues, xpath, child_node_names, values,
				"Verifies that the specified Xpath is valid and that it has the specified child node and values")
			{
				auto first_child = std::begin(child_node_names),
					last_child = std::end(child_node_names);
				auto first_value = std::begin(values),
					last_value = std::end(values);
				if (std::distance(first_child, last_child)
					!= std::distance(first_value, last_value))
					throw std::invalid_argument("child_node_names and values are not the same size");

				eXML::IXMLDOMDocumentPtr doc;
				if (!LoadXML(doc, arg))
				{
					if (result_listener)
					{
						*result_listener << "Argument is not valid XML";
					}

					return false;
				}
				
				auto nodelist = doc.selectNodes(xpath);
				// We can get back a list object containing zero nodes
				if (!static_cast<bool>(nodelist) || !nodelist.length)
				{
					if (result_listener)
					{
						*result_listener << "XPath \"" << ::testing::PrintToString(xpath) << "\" does not match";
					}

					return false;
				}

				XmlChildNodesMatch<decltype(first_child), decltype(first_value)> matcher(first_child, last_child, first_value, last_value, result_listener);
				auto iter = std::find_if(eXML::NodeList::begin(nodelist), eXML::NodeList::end(nodelist), matcher);
				if (iter == eXML::NodeList::end(nodelist))
				{
					return false;
				}
				return true;
			}
			
			namespace DAL
			{
				MATCHER_P(HasAddNode, field_name, "Verifies that the DAL XML has an add node for the specified field")
				{
					auto m = HasNodeEqual(L"/Parameters/Add/FieldName", field_name);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}
				MATCHER_P2(HasAddNodeValue, field_name, value, "Verifies that the DAL XML has an add node for the specified field")
				{
					myid::StringOrNumberToString converter;

					std::array<std::wstring, 2> field_list;
					field_list[0] = L"FieldName";
					field_list[1] = L"FieldValue";
					std::array<std::wstring, 2> value_list;
					value_list[0] = field_name;
					value_list[1] = converter(value);
					auto m = HasChildNodesWithValues(L"/Parameters/Add", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasFieldNode, field_name, "Verifies that the DAL XML has a field node for the specified field")
				{
					auto m = HasNodeEqual(L"/Parameters/Field/FieldName", field_name);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}
				MATCHER_P2(HasFieldAsNode, field_name, as_name, "Verifies that the DAL XML has a field node for the specified field")
				{
					myid::StringOrNumberToString converter;

					std::array<std::wstring, 2> field_list;
					field_list[0] = L"FieldName";
					field_list[1] = L"As";
					std::array<std::wstring, 2> value_list;
					value_list[0] = converter(field_name);
					value_list[1] = as_name;
					auto m = HasChildNodesWithValues(L"/Parameters/Field", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasMaxRecordsNode, max_records, "Verifies that the DAL XML has a max records node with the specified number")
				{
					auto m = HasNodeEqual(L"/Parameters/MaxRecords", max_records);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasWithHintNode, hint, "Verifies that the DAL XML has a with node with the specified hint")
				{
					auto m = HasNodeEqual(L"/Parameters/WITH", hint);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P2(HasOrderByNode, field_name, bDesc, "Verifies that the DAL XML has an order by node for the specified field and direction")
				{
					myid::StringOrNumberToString converter;

					std::array<std::wstring, 2> field_list;
					field_list[0] = L"OrderFieldName";
					field_list[1] = L"Desc";
					std::array<std::wstring, 2> value_list;
					value_list[0] = converter(field_name);
					value_list[1] = (static_cast<bool>(bDesc) ? L"Yes" : L"No");
					auto m = HasChildNodesWithValues(L"/Parameters/OrderBy", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasGroupByNode, field_name, "Verifies that the DAL XML has a group-by node with the specified field name")
				{
					auto m = HasNodeEqual(L"/Parameters/GroupBy/GroupFieldName", field_name);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P3(HasHavingNode, field_name, value, operation, "Verifies that the DAL XML has a having node with the specified field name, value and operation")
				{
					myid::StringOrNumberToString converter;

					std::array<std::wstring, 3> field_list;
					field_list[0] = L"FieldName";
					field_list[1] = L"FieldValue";
					field_list[2] = L"Operation";
					std::array<std::wstring, 3> value_list;
					value_list[0] = converter(field_name);
					value_list[1] = converter(value);
					value_list[2] = operation;
					auto m = HasChildNodesWithValues(L"/Parameters/Having", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}
				
				MATCHER_P3(HasUpdateNode, field_name, value, field_type, "Verifies that the DAL XML has an update node with the specified field name, value and operation")
				{
					myid::StringOrNumberToString converter;

					/* We are not testing the HexString parameter here as it can't be easily mocked at present.
					For similar reasons we're not looking at the enc or hash overloads. */
					std::array<std::wstring, 3> field_list;
					field_list[0] = L"FieldName";
					field_list[1] = L"FieldValue";
					field_list[2] = L"FieldType";
					std::array<std::wstring, 3> value_list;
					value_list[0] = field_name;
					value_list[1] = converter(value);
					value_list[2] = field_type;
					auto m = HasChildNodesWithValues(L"/Parameters/Update", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasTableNode, table, "Verifies that the DAL XML has a table node with the specified table name")
				{
					auto m = HasNodeEqual(L"/Parameters/Table", table);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasTopNode, record_count, "Verifies that the DAL XML has a top node with the specified number")
				{
					auto m = HasNodeEqual(L"/Parameters/Top", record_count);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P4(HasSubQueryNode, field_name, operation, subquery, bOR,\
					"Verifies that the DAL XML has a Where/SubQuery node with the specified field, operation, subquery and conjunction")
				{
					std::vector<std::wstring> field_list, value_list;
					field_list.push_back(L"FieldName");
					value_list.push_back(field_name);
					field_list.push_back(L"Operation");
					value_list.push_back(operation);
					field_list.push_back(L"SubQuery");
					value_list.push_back(subquery);
					if (bOR)
					{
						field_list.push_back(L"Conjunction");
						value_list.push_back(L"or");
					}
					auto m = HasChildNodesWithValues(L"/Parameters/Where", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P5(HasSubQueryTableNode, field_name, operation, table, subquery, bOR,\
					"Verifies that the DAL XML has a Where/SubQuery node with the specified field, operation, subquery and conjunction")
				{
					auto fn = HasNodeEqual(L"/Parameters/Where/FieldName", field_name);
					auto op = HasNodeEqual(L"/Parameters/Where/Operation", operation);
					auto tn = HasNodeEqual(L"/Parameters/Where/SubQuery/Table", table);
					auto sq = HasNodeEqual(L"/Parameters/Where/SubQuery", subquery);
					// Can't use ternary op here as the two objects have different types
					if (bOR)
					{
						auto co = HasNodeEqual(L"/Parameters/Where/Conjunction", L"or");
						auto all = ::testing::AllOf(fn, op, sq, tn, co);
						return ::testing::ExplainMatchResult(all, arg, result_listener);
					}
					else
					{
						auto co = HasNoNode(L"/Parameters/Where/Conjunction");
						auto all = ::testing::AllOf(fn, op, sq, tn, co);
						return ::testing::ExplainMatchResult(all, arg, result_listener);
					}
				}

				MATCHER_P5(HasTypedWhereNode, field_name, value, operation, field_type, bOR,\
					"Verifies that the DAL XML has a Where node with the specified field, value, operation, type and conjunction")
				{
					myid::StringOrNumberToString converter;

					std::vector<std::wstring> field_list, value_list;
					field_list.push_back(L"FieldName");
					value_list.push_back(field_name);
					field_list.push_back(L"FieldValue");
					value_list.push_back(converter(value));
					field_list.push_back(L"FieldType");
					value_list.push_back(field_type);
					field_list.push_back(L"Operation");
					value_list.push_back(operation);
					if (bOR)
					{
						field_list.push_back(L"Conjunction");
						value_list.push_back(L"or");
					}
					auto m = HasChildNodesWithValues(L"/Parameters/Where", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P4(HasWhereNode, field_name, value, operation, bOR,\
					"Verifies that the DAL XML has a Where node with the specified field, value, operation and conjunction")
				{
					myid::StringOrNumberToString converter;

					std::vector<std::wstring> field_list, value_list;
					field_list.push_back(L"FieldName");
					value_list.push_back(field_name);
					field_list.push_back(L"FieldValue");
					value_list.push_back(converter(value));
					field_list.push_back(L"Operation");
					value_list.push_back(operation);
					if (bOR)
					{
						field_list.push_back(L"Conjunction");
						value_list.push_back(L"or");
					}
					auto m = HasChildNodesWithValues(L"/Parameters/Where", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P5(HasInWhereNode, field_name, values, operation, field_type, bOR,\
					"Verifies that the DAL XML has an In Where node with the specified field name, values, operation and conjunction")
				{
					std::vector<std::wstring> field_list, value_list;
					field_list.push_back(L"FieldName");
					value_list.push_back(field_name);
					field_list.push_back(L"Operation");
					value_list.push_back(operation);
					if (bOR)
					{
						field_list.push_back(L"Conjunction");
						value_list.push_back(L"or");
					}
					/* This next bit is a little ugly as we could have either number or string inputs.
					It isn't possible to have a template lambda in C++11, hence the use of the functor. */
					std::generate_n(std::back_inserter(field_list),
						std::distance(std::begin(values), std::end(values)),
						[](){ return L"FieldValue"; });
					myid::StringOrNumberToString w;
					std::transform(std::begin(values), std::end(values),
						std::back_inserter(value_list),
						w);
					auto m = HasChildNodesWithValues(L"/Parameters/Where", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P(HasBracketNode, bracket, "Verifies that the DAL XML has a where node with the specified bracket")
				{
					auto m = HasNodeEqual(L"/Parameters/Where/Operation", bracket);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER(HasDistinctNode, "Verifies that the DAL XML has a distinct node")
				{
					auto m = HasNode(L"/Parameters/Distinct");
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER(HasExactSearchNode, "Verifies that the DAL XML has an exact search node")
				{
					auto m = HasNode(L"/Parameters/ExactSearch");
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER(HasNoAbortNode, "Verifies that the DAL XML has a NoAbort node")
				{
					auto m = HasNode(L"/Parameters/NoAbort");
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER(HasReadOnlyNode, "Verifies that the DAL XML has a ReadOnly node")
				{
					auto m = HasNode(L"/Parameters/RecordsetReadOnly");
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}

				MATCHER_P2(HasParameterNode, value, type, "Verifies that the DAL XML has a parameter node with the specified value and type")
				{
					myid::StringOrNumberToString converter;

					std::array<std::wstring, 2> field_list;
					field_list[0] = L"ParameterValue";
					field_list[1] = L"ParameterType";
					std::array<std::wstring, 2> value_list;
					value_list[0] = converter(value);
					value_list[1] = type;
					auto m = HasChildNodesWithValues(L"/Parameters/Param", field_list, value_list);
					return ::testing::ExplainMatchResult(m, arg, result_listener);
				}
			} // namespace DAL
		} // namespace gmock
	} // namespace testing
} // namespace myid
