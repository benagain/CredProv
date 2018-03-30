#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"
#include "Utilities/EdeficeCommon/TimeCommon.h"
#include "Utilities/EdeficeCommon/Status.h"
#include "Utilities/EdeficeCommon/OIDDefs.h"
#include "Utilities/EdeficeCommon/StringList.h"
#include "Utilities/EdeficeCommon/ASN1Decode.h"
#include "Utilities/EdeficeCommon/GlobalOperator.h"
#include "AbstractKeys/KeyStore.h"
#include <string>
#include <list>
#include <bitset>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>
#include <boost/variant.hpp>

namespace Certificate
{

template <class L>
class List : public std::list<L>
{
	typedef std::list<L> inherited;

public:
	std::wstring str(void) const
	{
		std::wstring str;

		for (typename inherited::const_iterator it = inherited::begin(); it != inherited::end(); ++it)
		{
			if (!str.empty())
				str << L"\n";
			str << it->str();
		}

		return str;
	}
};

class Array : public myid::VectorOfByte
{
	typedef myid::VectorOfByte inherited;

public:
	Array();
	Array(_In_ const Array& rhs);
	Array(_In_ const VectorOfByte& rhs);
	Array& operator=(_In_ const Array& rhs);
	Array& operator=(_In_ const VectorOfByte& rhs);
	std::wstring str(void) const;
};

enum Versions			/// certificate versions
{
	V1 = 0,
	V2 = 1,
	V3 = 2
};
class Version : public myid::Status<Versions, V1>
{
	typedef myid::Status<Versions, V1> inherited;

public:
	Version() {}
	explicit Version(_In_ S status) : inherited(status) {}
	Version& operator=(_In_ S status) { inherited::operator=(status); return *this; }
	std::wstring text(void) const;
	std::wstring str(void) const { return text(); }
};

// ---------------------------------------------------------------------------------------------------------
// common attribute classes

/// OID as a string
class Oid
{
public:
	Oid();
	explicit Oid(_In_ const std::string& oid);
	virtual ~Oid();

	Oid& operator=(_In_ const ASN1::OID& rhs) { oid = rhs; return *this; }

	void clear(void);
	std::wstring str(_In_ bool brief = false) const;

	ASN1::OID	oid;
};

/// time
class Time : public myid::Time
{
	typedef myid::Time inherited;

public:
	Time();
	explicit Time(_In_ const Time& rhs);
	explicit Time(_In_ const myid::Time& rhs);
	Time& operator=(_In_ const myid::Time& rhs);

	std::wstring str(void) const;
};

/// validity period
class ValidPeriod
{
public:
	bool valid(_In_ const myid::Time& when = myid::Time::now()) const;
	bool expired(_In_ const myid::Time& when = myid::Time::now()) const;
	std::wstring str(void) const;

	Time		notBefore;
	Time		notAfter;
};

/// Algorithm
class Algorithm : public Oid
{
public:
};

/// Any type of ASN1 data
class Any : public ASN1::Decoder::ASNDecodeVector
{
	typedef ASN1::Decoder::ASNDecodeVector inherited;

public:
	Any();
	Any(_In_ const Any& rhs);
	Any(_In_ const myid::VectorOfByte& rhs);
	Any& operator=(_In_ const Any& rhs);
	Any& operator=(_In_ const myid::VectorOfByte& rhs);
	void clear(void);
	std::wstring str(void) const;
	bool GetVector(_Out_ myid::VectorOfByte& data) const;
};

/// General ASN1 Attribute class
/// /note Also deals with AttributeTypeAndValue
class Attribute
{
public:
	void clear(void);
	std::wstring str(void) const;

	Oid				type;
	std::list<Any>	values;
};

/// Attribute set
class Attributes : public List<Attribute>
{
};


class IPAddr : public Array
{
	typedef Array inherited;

public:
	IPAddr();
	IPAddr(_In_ const IPAddr& rhs);
	IPAddr(_In_ const VectorOfByte& rhs);
	IPAddr& operator=(_In_ const IPAddr& rhs);
	IPAddr& operator=(_In_ const VectorOfByte& rhs);
	std::wstring str(void) const;
};

// ---------------------------------------------------------------------------------------------------------
// name classes

/// Single RDN, OID with string
class NameStr : public Oid
{
public:
	std::wstring	str;
};

/// RDN type
/// \li OpenSSL - X509_NAME
/// \li COM - IX500DistinguishedName
/// \note Used by issuer and subject
class Name : public std::list<NameStr>
{
	typedef std::list<NameStr> inherited;

public:
	enum format			/// name format
	{
		CN,				///< get just the CN part
		SN,				///< slash separated with DN
		LDAP,			///< comma separated with DN
		COMMA,			///< comma separated
	};
	std::wstring	find(_In_ const OIDS::OID& oid, _In_ bool forwards = true) const;
	std::wstring	str(_In_ format f = COMMA, _In_ bool forwards = true) const;
	StringList		detail(void) const;
};

/// Component of GeneralName
class AnotherName
{
public:
	void clear(void);
	std::wstring str(void) const;

	Oid		type_id;
	Any		value;
};

/// General name
class GeneralName
{
	typedef std::wstring inherited;

public:
	enum nameTypes				/// name choice
	{
		UNDEFINED = -1,			///< std::wstring, empty
		OTHER = 0,				///< AnotherName
		RFC822 = 1,				///< std::wstring
		DNS = 2,				///< std::wstring
		X400_ADDRESS = 3,		///< std::wstring (temp)
		DIRECTORY = 4,			///< Name
		EDI_PARTY = 5,			///< std::wstring (temp)
		URI = 6,				///< std::wstring
		IP_ADDRESS = 7,			///< Array
		REGISTERED_ID = 8		///< Oid
	};

	class nameType : public myid::Status<nameTypes, OTHER>
	{
		typedef myid::Status<nameTypes, OTHER> inherited;

	public:
		nameType() {}
		explicit nameType(_In_ S status) : inherited(status) {}
		nameType& operator=(_In_ S status) { inherited::operator=(status); return *this; }
		std::wstring text(void) const;
	};

	void clear(void);
	std::wstring str(void) const;

	nameType	type;
	boost::variant<AnotherName, Name, std::wstring, Any, IPAddr, Oid>	name;
};

/// List of general names
class GeneralNames : public List<GeneralName>
{
public:
	boost::optional<std::wstring> email(void) const;
};

// ---------------------------------------------------------------------------------------------------------
// key classes

/// RSA public key
class PublicKeyRSA : public KeyStore::RSAPublic
{
public:
	std::wstring str(void) const;
};

/// ECC public key
class PublicKeyECC : public KeyStore::ECCPublic
{
public:
	std::wstring str(void) const;
};

/// Public key with type OID
class PublicKey : public Oid, public KeyStore::KeyContainer
{
public:
	std::wstring str(void) const;
};

// ---------------------------------------------------------------------------------------------------------
// extension data classes

/// Key usage data
class KeyUsage : public std::bitset<9>
{
	typedef std::bitset<9> inherited;

public:
	enum usages
	{
		DIGITAL_SIGNATURE = 0,
		NON_REPUDIATION = 1,
		KEY_ENCIPHERMENT = 2,
		DATA_ENCIPHERMENT = 3,
		KEY_AGREEMENT = 4,
		KEY_CERTSIGN = 5,
		CRL_SIGN = 6,
		ENCIPHER_ONLY = 7,
		DECIPHER_ONLY = 8
	};
	class usage : public myid::Status<usages, DIGITAL_SIGNATURE>
	{
		typedef myid::Status<usages, DIGITAL_SIGNATURE> inherited;

	public:
		usage() {}
		explicit usage(_In_ S status) : inherited(status) {}
		std::wstring text(void) const;
	};

	KeyUsage();
	KeyUsage& operator=(_In_ const inherited& rhs);
	std::wstring str(void) const;
};

/// Extended key usage data
class OidList : public std::list<ASN1::OID>
{
	typedef std::list<ASN1::OID> inherited;

public:
	bool contains(_In_ const ASN1::OID& oid) const;
	std::wstring str(void) const;
};

/// Authority key info
class AuthKey
{
public:
	void clear(void);
	std::wstring str(void) const;

	boost::optional<Array>			key;
	boost::optional<GeneralNames>	name;
	boost::optional<Array>			serial;
};

/// CRL distribution point
class CrlDistPoint
{
public:
	enum reasonFlags
	{
		UNUSED = 0,
		KEY_COMPROMISE = 1,
		CA_COMPROMISE = 2,
		AFFILIATION_CHANGED = 3,
		SUPERSEDED = 4,
		CESSATION_OF_OPERATION = 5,
		CERTIFICATE_HOLD = 6,
		PRIVILEGE_WITHDRAWN = 7,
		AA_COMPROMISE = 8
	};
	class reasonFlag : public myid::Status<reasonFlags, UNUSED>
	{
		typedef myid::Status<reasonFlags, UNUSED> inherited;

	public:
		reasonFlag() {}
		explicit reasonFlag(_In_ S status) : inherited(status) {}
		std::wstring text(void) const;
	};

	class ReasonsFlags : public std::vector<bool>
	{
		typedef std::vector<bool> inherited;

	public:
		ReasonsFlags();
		ReasonsFlags& operator=(_In_ const inherited& rhs);
		std::wstring str(void) const;
	};

	class CrlDistPointName
	{
	public:
		std::wstring str(void) const;
		void clear(void);

		boost::variant<GeneralNames, Name>	name;
	};

	void clear(void);
	std::wstring str(void) const;

	boost::optional<CrlDistPointName>	distPoint;
	boost::optional<ReasonsFlags>		reasons;
	boost::optional<GeneralNames>		issuer;
};

/// CRL distribution point
class CrlDistPoints : public List<CrlDistPoint>
{
};

class Policy : public Oid
{
public:
	class NoticeRef
	{
	public:
		void clear(void);
		std::wstring str(void) const;

		std::wstring	organization;
		std::list<long>	numbers;
	};

	class UserNotice
	{
	public:
		void clear(void);
		std::wstring str(void) const;

		boost::optional<NoticeRef>		notice;
		boost::optional<std::wstring>	text;
	};

	class PolicyQualifier : public Oid
	{
	public:
		std::wstring str(void) const;

		boost::variant<std::wstring, UserNotice, Any>	qualifier;
	};

	void clear(void);
	std::wstring str(void) const;

	List<PolicyQualifier>	qualifiers;
};

class Policies : public List<Policy>
{
	typedef List<Policy> inherited;

public:
	bool HasPolicy(_In_ const ASN1::OID& oid) const;
};

class AccessDescription : public Oid
{
public:
	void clear(void);
	std::wstring str(void) const;

	GeneralName		location;
};

class AccessDescriptions : public List<AccessDescription>
{
};

class PolicyConstraints
{
public:
	void clear(void);
	std::wstring str(void) const;

	boost::optional<long>		requireExplicitPolicy;
	boost::optional<long>		inhibitPolicyMapping;
};

class BasicConstraints
{
public:
	BasicConstraints();
	void clear(void);
	std::wstring str(void) const;

	bool						ca;
	boost::optional<long>		pathLenConstraint;
};

class PolicyMapping
{
public:
	void clear(void);
	std::wstring str(void) const;

	Oid						issuerDomainPolicy;
	Oid						subjectDomainPolicy;
};

class PolicyMappings : public List<PolicyMapping>
{
};

class InhibitAnyPolicy
{
public:
	std::wstring str(void) const;

	int32_t				inhibitAnyPolicy;
};

class NameConstraints
{
public:
	class GeneralSubtree
	{
	public:
		void clear(void);
		std::wstring str(void) const;

		GeneralName				base;
		boost::optional<long>	minimum;
		boost::optional<long>	maximum;
	};

	class GeneralSubtrees : public List<GeneralSubtree>
	{
	};

	void clear(void);
	std::wstring str(void) const;

	boost::optional<GeneralSubtrees>		permittedSubtrees;
	boost::optional<GeneralSubtrees>		excludedSubtrees;
};

class CrlNumber
{
public:
	void clear(void);
	std::wstring str(void) const;

	boost::variant<long, Array>			crlNumber;
};

class IssuingDistPoint
{
public:
	IssuingDistPoint();
	void clear(void);
	std::wstring str(void) const;

	boost::optional<CrlDistPoint::CrlDistPointName>	distributionPoint;
	bool								onlyContainsUserCerts;
	bool								onlyContainsCACerts;
	boost::optional<CrlDistPoint::ReasonsFlags>		onlySomeReasons;
	bool								indirectCRL;
	bool								onlyContainsAttributeCerts;
};

enum CrlReasons					/// revocation reasons
{
	UNSPECIFIED = 0,
	KEY_COMPROMISE = 1,
	CA_COMPROMISE = 2,
	AFFILIATION_CHANGED = 3,
	SUPERSEDED = 4,
	CESSATION_OF_OPERATION = 5,
	CERTIFICATE_HOLD = 6,
	REMOVE_FROM_CRL = 8,
	PRIVILEGE_WITHDRAWN = 9,
	AA_COMPROMISE = 10
};
class CrlReason : public myid::Status<CrlReasons, UNSPECIFIED>
{
	typedef myid::Status<CrlReasons, UNSPECIFIED> inherited;

public:
	CrlReason() {}
	explicit CrlReason(S status) : inherited(status) {}
	std::wstring text(void) const;
	std::wstring str(void) const { return text(); }
};

class MSCertTemplate : public Oid
{
public:
	void clear(void);
	std::wstring str(void) const;

	boost::optional<unsigned long>		majorVersion;
	boost::optional<unsigned long>		minorVersion;
};

class PivNaci
{
public:
	std::wstring str(void) const;

	bool			naci;
};

// ---------------------------------------------------------------------------------------------------------
// extension classes

/// Generic extension root
class Ext : public Oid
{
protected:
	explicit Ext(_In_ const std::string& oid);
	Ext(_In_ const std::string& oid, _In_ int crit);

	template <class L>
	std::wstring str(_In_ const L* obj, _In_ bool oid = false) const
	{
		std::wstring str;

		if (oid)
			str << Oid::str() << L"\n";
		str << obj->str();

		return str;
	}

public:
	virtual std::wstring str(_In_ bool oid = false) const = 0;

	bool			critical;			///< extension critical flag
	bool			known;				///< is a known extension
};
typedef boost::shared_ptr<Ext> ExtPtr;
typedef std::list<ExtPtr> ExtPtrList;

/// Generic, ie unknown
class ExtGeneric : public Ext, public Any
{
public:
	ExtGeneric(_In_ const std::string& oid, _In_ int crit) : Ext(oid, crit) { known = false; }
	ExtGeneric& operator=(_In_ const VectorOfByte& rhs) { Any::operator=(rhs); return *this; }
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<Any>(this, oidIn); }

	static bool IsKnown(_In_ const std::string& oid);
};

/// Key usage
class ExtKeyUsage : public Ext, public KeyUsage
{
public:
	ExtKeyUsage() : Ext(OIDS::KeyUsage) {}
	ExtKeyUsage& operator=(_In_ const std::vector<bool>& rhs);
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<KeyUsage>(this, oidIn); }
};

/// Extended key usage
class ExtExtendedKeyUsage : public Ext, public OidList
{
public:
	ExtExtendedKeyUsage() : Ext(OIDS::ExtendedKeyUsage) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<OidList>(this, oidIn); }
};

/// Subject key identifier
class ExtSubjectKeyIdentifier : public Ext, public Array
{
public:
	ExtSubjectKeyIdentifier() : Ext(OIDS::SubjectKeyIdentifier) {}
	ExtSubjectKeyIdentifier& operator=(_In_ const VectorOfByte& rhs) { VectorOfByte::operator=(rhs); return *this; }
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<Array>(this, oidIn); }
};

/// Authority key identifier
class ExtAuthKey : public Ext, public AuthKey
{
public:
	ExtAuthKey() : Ext(OIDS::AuthorityKeyIdentifier) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<AuthKey>(this, oidIn); }
};

/// Subject alt names
class ExtSubjectAltName : public Ext, public GeneralNames
{
public:
	ExtSubjectAltName() : Ext(OIDS::SubjectAltName) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<GeneralNames>(this, oidIn); }
};

/// Issuer alt names
class ExtIssuerAltName : public Ext, public GeneralNames
{
public:
	explicit ExtIssuerAltName(_In_ int crit) : Ext(OIDS::IssuerAltName, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<GeneralNames>(this, oidIn); }
};

/// CRL distribution points
class ExtCrlDistPoints : public Ext, public CrlDistPoints
{
public:
	ExtCrlDistPoints() : Ext(OIDS::CRLDistributionPoint) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<CrlDistPoints>(this, oidIn); }
};

/// Certificate policies
class ExtPolicies : public Ext, public Policies
{
public:
	explicit ExtPolicies(_In_ int crit) : Ext(OIDS::CertificatePolicies, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<Policies>(this, oidIn); }
};

/// Authority Information Access
class ExtAuthorityInformationAccess : public Ext, public AccessDescriptions
{
public:
	explicit ExtAuthorityInformationAccess(_In_ int crit) : Ext(OIDS::AuthorityInformationAccess, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<AccessDescriptions>(this, oidIn); }
};

/// Subject Information Access
class ExtSubjectInformationAccess : public Ext, public AccessDescriptions
{
public:
	explicit ExtSubjectInformationAccess(_In_ int crit) : Ext(OIDS::SubjectInformationAccess, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<AccessDescriptions>(this, oidIn); }
};

/// Policy Constraints
class ExtPolicyConstraints : public Ext, public PolicyConstraints
{
public:
	explicit ExtPolicyConstraints(_In_ int crit) : Ext(OIDS::PolicyConstraints, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<PolicyConstraints>(this, oidIn); }
};

/// Basic Constraints
class ExtBasicConstraints : public Ext, public BasicConstraints
{
public:
	explicit ExtBasicConstraints(_In_ int crit) : Ext(OIDS::BasicConstraints, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<BasicConstraints>(this, oidIn); }
};

/// Name Constraints
class ExtNameConstraints : public Ext, public NameConstraints
{
public:
	ExtNameConstraints() : Ext(OIDS::NameConstraints) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<NameConstraints>(this, oidIn); }
};

/// Policy Mappings
class ExtPolicyMappings : public Ext, public PolicyMappings
{
public:
	explicit ExtPolicyMappings(_In_ int crit) : Ext(OIDS::PolicyMappings, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<PolicyMappings>(this, oidIn); }
};

/// Subject Directory Attributes
class ExtSubjectDirAttrs : public Ext, public Attributes
{
public:
	ExtSubjectDirAttrs() : Ext(OIDS::SubjectDirAttrs) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<Attributes>(this, oidIn); }
};

/// Inhibit Any Policy
class ExtInhibitAnyPolicy : public Ext, public InhibitAnyPolicy
{
public:
	explicit ExtInhibitAnyPolicy(_In_ int crit) : Ext(OIDS::InhibitAnyPolicy, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<InhibitAnyPolicy>(this, oidIn); }
};

/// CRL Number
class ExtCrlNumber : public Ext, public CrlNumber
{
public:
	explicit ExtCrlNumber(_In_ int crit) : Ext(OIDS::CrlNumber, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<CrlNumber>(this, oidIn); }
};

/// Issuing Distribution Point
class ExtIssuingDistPoint : public Ext, public IssuingDistPoint
{
public:
	explicit ExtIssuingDistPoint(_In_ int crit) : Ext(OIDS::IssuingDistributionPoint, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<IssuingDistPoint>(this, oidIn); }
};

/// Delta CRL Indicator
class ExtDeltaCrlIndicator : public Ext, public CrlNumber
{
public:
	explicit ExtDeltaCrlIndicator(_In_ int crit) : Ext(OIDS::DeltaCrlIndicator, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<CrlNumber>(this, oidIn); }
};

/// FreshestCRL
class ExtFreshestCrl : public Ext, public CrlDistPoints
{
public:
	ExtFreshestCrl() : Ext(OIDS::FreshestCRL) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<CrlDistPoints>(this, oidIn); }
};

/// Reason code
class ExtReasonCode : public Ext, public CrlReason
{
public:
	explicit ExtReasonCode(_In_ int crit) : Ext(OIDS::CrlReasonCode, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<CrlReason>(this, oidIn); }
};

/// Invalidity Date
class ExtInvalidityDate : public Ext, public Time
{
public:
	explicit ExtInvalidityDate(_In_ int crit) : Ext(OIDS::InvalidityDate, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<Time>(this, oidIn); }
};

/// Certificate Issuer
class ExtCertificateIssuer : public Ext, public GeneralNames
{
public:
	explicit ExtCertificateIssuer(_In_ int crit) : Ext(OIDS::CertificateIssuer, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<GeneralNames>(this, oidIn); }
};

/// MS Certificate Template
class ExtMSCertTemplate : public Ext, public MSCertTemplate
{
public:
	explicit ExtMSCertTemplate(_In_ int crit) : Ext(OIDS::MSCertificateTemplate, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<MSCertTemplate>(this, oidIn); }
};

/// PIV NACI
class ExtPivNaci : public Ext, public PivNaci
{
public:
	explicit ExtPivNaci(_In_ int crit) : Ext(OIDS::PIVNaci, crit) {}
	std::wstring str(_In_ bool oidIn = false) const { return Ext::str<PivNaci>(this, oidIn); }
};

/// List of extensions
class Exts : public ExtPtrList
{
public:
	void			add(_In_ Ext* Ext);
	const Ext*		find(_In_ const OIDS::OID& oid) const;
	template <class T> const T* find(_In_ const OIDS::OID& oid) const
	{
		const Ext* e = find(oid);
		return e == nullptr ? nullptr : dynamic_cast<const T*>(e);
	}
	template <class T, class E> boost::optional<T> get(_In_ const OIDS::OID& oid) const
	{
		const E* ex = find<E>(oid);
		boost::optional<T> r;
		if (ex != nullptr)
			r = *ex;
		return r;
	}
	bool			critical(_In_ const OIDS::OID& oid) const;
	ExtPtrList		getGeneric(void) const;
	std::wstring	str(_In_ bool oid = false) const;

	// fetch extension data
	boost::optional<KeyUsage>			getKeyUsage(void) const { return get<KeyUsage, ExtKeyUsage>(OIDS::KeyUsage); }
	boost::optional<OidList>			getExtendedKeyUsage(void) const { return get<OidList, ExtExtendedKeyUsage>(OIDS::ExtendedKeyUsage); }
	boost::optional<Array>				getSubjectKeyIdentifier(void) const { return get<Array, ExtSubjectKeyIdentifier>(OIDS::SubjectKeyIdentifier); }
	boost::optional<AuthKey>			getAuthKey(void) const { return get<AuthKey, ExtAuthKey>(OIDS::AuthorityKeyIdentifier); }
	boost::optional<GeneralNames>		getSubjectAltName(void) const { return get<GeneralNames, ExtSubjectAltName>(OIDS::SubjectAltName); }
	boost::optional<GeneralNames>		getIssuerAltName(void) const { return get<GeneralNames, ExtIssuerAltName>(OIDS::IssuerAltName); }
	boost::optional<CrlDistPoints>		getCrlDistPoints(void) const { return get<CrlDistPoints, ExtCrlDistPoints>(OIDS::CRLDistributionPoint); }
	boost::optional<Policies>			getPolicies(void) const { return get<Policies, ExtPolicies>(OIDS::CertificatePolicies); }
	boost::optional<AccessDescriptions>	getAuthorityInformationAccess(void) const { return get<AccessDescriptions, ExtAuthorityInformationAccess>(OIDS::AuthorityInformationAccess); }
	boost::optional<AccessDescriptions>	getSubjectInformationAccess(void) const { return get<AccessDescriptions, ExtSubjectInformationAccess>(OIDS::SubjectInformationAccess); }
	boost::optional<PolicyConstraints>	getPolicyConstraints(void) const { return get<PolicyConstraints, ExtPolicyConstraints>(OIDS::PolicyConstraints); }
	boost::optional<BasicConstraints>	getBasicConstraints(void) const { return get<BasicConstraints, ExtBasicConstraints>(OIDS::BasicConstraints); }
	boost::optional<NameConstraints>	getNameConstraints(void) const { return get<NameConstraints, ExtNameConstraints>(OIDS::NameConstraints); }
	boost::optional<PolicyMappings>		getPolicyMappings(void) const { return get<PolicyMappings, ExtPolicyMappings>(OIDS::PolicyMappings); }
	boost::optional<Attributes>			getSubjectDirAttrs(void) const { return get<Attributes, ExtSubjectDirAttrs>(OIDS::SubjectDirAttrs); }
	boost::optional<InhibitAnyPolicy>	getInhibitAnyPolicy(void) const { return get<InhibitAnyPolicy, ExtInhibitAnyPolicy>(OIDS::InhibitAnyPolicy); }
	boost::optional<CrlNumber>			getCrlNumber(void) const { return get<CrlNumber, ExtCrlNumber>(OIDS::CrlNumber); }
	boost::optional<IssuingDistPoint>	getIssuingDistPoint(void) const { return get<IssuingDistPoint, ExtIssuingDistPoint>(OIDS::IssuingDistributionPoint); }
	boost::optional<CrlNumber>			getDeltaCrlIndicator(void) const { return get<CrlNumber, ExtDeltaCrlIndicator>(OIDS::DeltaCrlIndicator); }
	boost::optional<CrlDistPoints>		getFreshestCrl(void) const { return get<CrlDistPoints, ExtFreshestCrl>(OIDS::FreshestCRL); }
	boost::optional<CrlReason>			getReasonCode(void) const { return get<CrlReason, ExtReasonCode>(OIDS::CrlReasonCode); }
	boost::optional<Time>				getInvalidityDate(void) const { return get<Time, ExtInvalidityDate>(OIDS::InvalidityDate); }
	boost::optional<GeneralNames>		getCertificateIssuer(void) const { return get<GeneralNames, ExtCertificateIssuer>(OIDS::CertificateIssuer); }
	boost::optional<Policies>			getMSApplicationPolicies(void) const { return get<Policies, ExtPolicies>(OIDS::MSApplicationPolicies); }
	boost::optional<MSCertTemplate>		getMSCertTemplate(void) const { return get<MSCertTemplate, ExtMSCertTemplate>(OIDS::MSCertificateTemplate); }
	boost::optional<PivNaci>			getPivNaci(void) const { return get<PivNaci, ExtPivNaci>(OIDS::PIVNaci); }
};

// ---------------------------------------------------------------------------------------------------------

/// Common certificate or Crl data storage
class RawData
{
public:
	RawData();
	explicit RawData(_In_ const VectorOfBytePtr& data);
	explicit RawData(_In_ const VectorOfByte& data);
	virtual ~RawData();

	void Load(_In_ const VectorOfBytePtr& data);
	void Load(_In_ const VectorOfByte& data);

	VectorOfBytePtr		data;					///< certificate, Crl data
	bool				loaded;					///< has a load attempt been made
	bool				valid;					///< is certificate data valid
};

/// Certificate data container
class Data : protected RawData
{
	typedef RawData inherited;

public:
	Data();
	Data(_In_ const std::wstring& reference, _In_ const VectorOfBytePtr& data);
	Data(_In_ const std::wstring& reference, _In_ const VectorOfByte& data);

	void Load(_In_ const std::wstring& reference, _In_ const VectorOfBytePtr& data);
	void Load(_In_ const std::wstring& reference, _In_ const VectorOfByte& data);

	std::wstring serialNumber(void) const;
	std::wstring usage(void) const;
	bool isValid(void) const;
	VectorOfByte const & certificate(void) const;
	std::wstring str(void) const;

	// supplied data
	std::wstring		reference;				///< user defined label
	std::wstring		description;			///< human friendly display label

	// content data
	Version				version;				///< version 1 to 3
	Array				serial;					///< serial number
	Algorithm			signature;				///< signature Algorithm
	Name				issuer;					///< issuer name
	ValidPeriod			validPeriod;			///< validity period
	Name				subject;				///< subject name
	PublicKey			publicKey;				///< public key
	Exts				extension;				///< list of extensions

	// signature
	Algorithm			signatureAlgorithm;		///< signature Algorithm
	Array				signatureData;			///< signature

	// derived data
	boost::optional<std::wstring> email(void) const;

	int					bit_size;				///< key size in bits
	bool				canSign;				///< can digitally sign
	bool				canEncrypt;				///< can encrypt
	bool				canSignEmail;			///< can digitally sign emails
	bool				canEncryptEmail;		///< can encrypt emails
	bool				clientAuth;				///< can be used for SSL client authentication
};

//=======================================================================================================================================
//=======================================================================================================================================
// CRL

class Revoked
{
public:
	void clear(void);
	std::wstring str(void) const;

	boost::optional<CrlReason>	reason;					///< reason code
	Array						serial;					///< serial number
	Time						revocationDate;			///< revocation date
	GeneralNames				issuer;					///< issuers
	Exts						extension;				///< list of entry extensions
};

class RevokedList : public List<Revoked>
{
};

class Crl : protected RawData
{
	typedef RawData inherited;

public:
	Crl();
	explicit Crl(_In_ const VectorOfBytePtr& data);
	explicit Crl(_In_ const VectorOfByte& data);
	std::wstring str(void) const;

	boost::optional<Version>	version;			///< version 1 to 2
	Algorithm					signature;			///< signature Algorithm
	Name						issuer;				///< issuer name
	Time						thisUpdate;			///< when issued
	boost::optional<Time>		nextUpdate;			///< next update
	RevokedList					revoked;			///< list of revoked certificates
	Exts						extension;			///< list of crl extensions

	// signature
	Algorithm					signatureAlgorithm;	///< signature Algorithm
	Array						signatureData;		///< signature
};

} // namespace Certificate
