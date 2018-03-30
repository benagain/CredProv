#pragma once

#include "Utilities/EdeficeCommon/XMLnode.h"

namespace myid
{

// unknown extension parsed from the XML produced by CSP COM
class UnknownExtension
{
public:
	explicit UnknownExtension(eXML::IXMLDOMNodePtr const & xmlNode);

	std::wstring OID() const { return m_OID; }
	VectorOfByte Bytes() const { return m_pBytes; }
private:

	std::wstring m_OID;
	bool m_critical;
	std::wstring m_hexBytes;

	VectorOfByte m_pBytes;
};

typedef std::vector<UnknownExtension> VectorOfUnknownExtension;

} // namespace myid