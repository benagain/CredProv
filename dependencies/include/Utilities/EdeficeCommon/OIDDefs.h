#pragma once

#include "OIDs.h"

namespace OIDS					/// list of OIDs that are used by MyID
{
	using namespace ASN1;

	extern OID EccPublicKey;
	extern OID EccCurve256;
	extern OID RsaEncryption;
	extern OID Sha1Rsa;
	extern OID Sha256Rsa;
	extern OID Pkcs9EmailAddress;
	extern OID TDesCbc;
	extern OID MSAnyPurpose;
	extern OID MSSmartCardLogon;
	extern OID MSPrincipalName;
	extern OID MSCertificateTemplate;
	extern OID MSApplicationPolicies;
	extern OID PKIX;
	extern OID AuthorityInformationAccess;
	extern OID SubjectInformationAccess;
	extern OID ClientAuthentication;
	extern OID NistSha1;
	extern OID SecurityObject;
	extern OID EccCurve384;
	extern OID EccCurve521;
	extern OID ECDH;
	extern OID CN;
	extern OID OU;
	extern OID SubjectDirAttrs;
	extern OID SubjectKeyIdentifier;
	extern OID KeyUsage;
	extern OID SubjectAltName;
	extern OID IssuerAltName;
	extern OID BasicConstraints;
	extern OID CrlNumber;
	extern OID CrlReasonCode;
	extern OID InvalidityDate;
	extern OID DeltaCrlIndicator;
	extern OID IssuingDistributionPoint;
	extern OID CertificateIssuer;
	extern OID NameConstraints;
	extern OID CRLDistributionPoint;
	extern OID CertificatePolicies;
	extern OID PolicyMappings;
	extern OID AuthorityKeyIdentifier;
	extern OID PolicyConstraints;
	extern OID ExtendedKeyUsage;
	extern OID AnyExtendedKeyUsage;
	extern OID FreshestCRL;
	extern OID InhibitAnyPolicy;
	extern OID Aes128Cbc;
	extern OID Aes192Cbc;
	extern OID Aes256Cbc;
	extern OID NistSha256;
	extern OID NistSha384;
	extern OID NistSha512;
	extern OID PIVFascN;
	extern OID PIVNaci;
} // namespace OIDS
