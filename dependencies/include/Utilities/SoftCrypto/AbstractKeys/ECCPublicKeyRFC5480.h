#pragma once

#include "ECCPublicKey.h"

namespace AbstractKeys
{

namespace KeyEncoder
{

/** 
SubjectPublicKeyInfo  ::=  SEQUENCE  {
algorithm         AlgorithmIdentifier,
subjectPublicKey  BIT STRING
}

AlgorithmIdentifier  ::=  SEQUENCE  {
algorithm   OBJECT IDENTIFIER,
parameters  ANY DEFINED BY algorithm OPTIONAL
}

The subjectPublicKey from SubjectPublicKeyInfo is the ECC public key.
ECC public keys have the following syntax:

    ECPoint ::= OCTET STRING

--
-- Signature Algorithms
--

-- ECDSA with SHA-256
-- Parameters are ABSENT

id-ecPublicKey OBJECT IDENTIFIER ::= {
iso(1) member-body(2) us(840) ansi-X9-62(10045) keyType(2) 1 }

ecdsa-with-SHA256 OBJECT IDENTIFIER ::= {
    iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
    ecdsa-with-SHA2(3) 2 }

-- ECDSA with SHA-384
-- Parameters are ABSENT

ecdsa-with-SHA384 OBJECT IDENTIFIER ::= {
    iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
    ecdsa-with-SHA2(3) 3 }

-- ECDSA with SHA-512
-- Parameters are ABSENT

ecdsa-with-SHA512 OBJECT IDENTIFIER ::= {
    iso(1) member-body(2) us(840) ansi-X9-62(10045) signatures(4)
    ecdsa-with-SHA2(3) 4 }

--
-- Signature Values
--

-- DSA

DSA-Sig-Value ::= SEQUENCE {
    r  INTEGER,
    s  INTEGER
}

-- ECDSA

ECDSA-Sig-Value ::= SEQUENCE {
    r  INTEGER,
    s  INTEGER
}

Public key is ASN1 - following format
SEQUENCE {
	SEQUENCE {
		OID 1.2.840.10045.2.1 = ANSI X962 ECC Public Key
		OID x.y.z             = ANSI X962/Certicom ECC CURVE xyz
	}
	BITS {

	}
}

where x.y.z / xyz equates to EC CURVE P256/384/521

*/

class ECCPublicKeyRFC5480 : public ECCPublicKey
{
public:
	//IKeyEncoder
	virtual void GetEncodedData(VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(const VectorOfByte &vecEncodedKey);
	virtual void SetKey(const IKeyData &key);
};

} //namespace KeyEncoder

} //namespace AbstractKeys
