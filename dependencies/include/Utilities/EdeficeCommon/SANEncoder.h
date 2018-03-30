#pragma once

#include "ImportMSXML.h"
#include "VectorOfBytePtr.h"
#include <wincrypt.h>
#include <boost/noncopyable.hpp>

class CSANEncoder
{
public:
	CSANEncoder();
	~CSANEncoder();

	VectorOfBytePtr EncodeSAN(MSXML::IXMLDOMNodeListPtr pSANNodes);
};

/// wrapper class for subject alt names array
class AltNamesContainer : private boost::noncopyable
{
public:
	/// constructor creates array of specified size
	/// @param[in] nElements size of array to create
	explicit AltNamesContainer(int nElements);
	/// destructor clears up all memory in structure
	~AltNamesContainer();
	/// overloaded array accessor
	/// @param[in] nElement array element to access
	/// @return reference to array element
	CERT_ALT_NAME_ENTRY &operator[](int nElement);

	CERT_ALT_NAME_ENTRY *pAltNames;

private:
	int m_nElements;
};
