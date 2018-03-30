#pragma once

#include "Asn1Encoder.h"
#include <boost/noncopyable.hpp>

struct _CERT_EXTENSION;


/// Container class for an extension to an X509 structure
/// SEQUENCE {
///   OBJECT IDENTIFIER
///     id-piv-interim (2 16 840 1 101 3 6 9 1)
///   OCTET STRING, encapsulates {
///     VectorOfBytePtr m_value
///     }
///   }
/// }
class ASN1Extension : private boost::noncopyable
{
public:
	ASN1Extension(_In_ std::string const & oid, _In_ VectorOfBytePtr const & value);

	operator _CERT_EXTENSION() const;

private:
	std::string const m_oid;
	VectorOfBytePtr const m_value;
};
typedef boost::shared_ptr<class ASN1Extension> ASN1ExtensionPtr;
typedef ASN1Extension CASN1Extension;
typedef ASN1ExtensionPtr CASN1ExtensionPtr;


/** Container class for a list of extensions to an X509 structure
\verbatim
SEQUENCE {
	<ASN1Extension m_extensions>
}
\endverbatim */
class ASN1Extensions : public ASN1::Encoder::ASN1Encoder
{
public:
	void AddItem(_In_ ASN1ExtensionPtr const & p);
	size_t size() const;
	void EncodeExtensions();

protected:
	typedef std::vector<ASN1ExtensionPtr> ASN1ExtensionList;
	ASN1ExtensionList m_extensions;

	std::vector<_CERT_EXTENSION> BuildRawExtensionList() const;
};
typedef boost::shared_ptr<class ASN1Extensions> ASN1ExtensionsPtr;
typedef ASN1Extensions CASN1Extensions;
typedef ASN1ExtensionsPtr CASN1ExtensionsPtr;


/** encapsulate a extension in a cert request. Because of the way encoding works in CAPI
(raw pointers etc) it is important the underlying data that the CRYPT_ATTRIBUTE points to
is in existance at the time the P10 is encoded (hence this container class)
\verbatim
SEQUENCE {
	OBJECT IDENTIFIER <oid>
	SET {
		<vecEncodedData>
	}
}
\endverbatim */
class CryptAttribute
{
public:
	CryptAttribute(_In_ const std::string &strOID, _In_ const VectorOfByte &vecEncodedData);
	void PopulateAttribute(std::vector<struct _CRYPT_ATTRIBUTE> &vecAttributes);

	struct _CRYPT_ATTRIBUTE * GetAttribute() const;

private:
	boost::shared_ptr<struct _CRYPTOAPI_BLOB> m_attributeBlob;// the single attribute blob. (multiples not supported)
	boost::shared_ptr<struct _CRYPT_ATTRIBUTE> m_attribute;
	VectorOfByte m_encodedData;
	std::string m_oid;
};
typedef boost::shared_ptr<class CryptAttribute> CryptAttributePtr;

class CryptAttributeList
{
public:
	void add(_In_ CryptAttributePtr const & p);
	size_t size() const;

	struct _CRYPT_ATTRIBUTE * GetAttributes();

private:
	std::vector<CryptAttributePtr> m_attributes;
	std::vector<_CRYPT_ATTRIBUTE> m_attributeRawList;
};
