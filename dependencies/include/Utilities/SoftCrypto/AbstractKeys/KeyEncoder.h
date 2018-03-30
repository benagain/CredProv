#pragma once

#include "Utilities/EdeficeCommon/VectorOfByte.h"

namespace AbstractKeys
{

namespace KeyEncoder
{

class IKeyData
{
public:
	virtual ~IKeyData() {}
};

/// Pure abstract base class for manipulating RSA public key formats
/// \note All key components to be returned in big-endian format
class IRSAPublicKeyData : public virtual IKeyData
{
public:
	virtual void GetPublicExponent(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetModulus(_Out_ VectorOfByte& vecData) const = 0;

	virtual long GetKeySizeBits() const = 0;
};

/// Pure abstract base class for manipulating RSA private key formats
/// \note All key components to be returned in big-endian format
class IRSAPrivateKeyData : public IRSAPublicKeyData
{
public:
	virtual void GetPrime1(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetPrime2(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetExponent1(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetExponent2(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetCoefficient(_Out_ VectorOfByte& vecData) const = 0;
	virtual void GetPrivateExponent(_Out_ VectorOfByte& vecData) const = 0;
};

/** pure abstract base class for manipulating ECC public key formats*/
class IECCPublicKeyData : public virtual IKeyData 
{
public:
	/// all key components to be returned in big-endian format
	virtual void GetPublicKey(_Out_ VectorOfByte &vecData) const=0; // big endian pubkey - no RFC5480 compression byte just the X+Y
	virtual void GetOID(_Out_ std::string &oid) const=0;

	virtual long GetKeySizeBits() const=0;
};

/** pure abstract base class for manipulating ECC private key formats*/
class IECCPrivateKeyData : public IECCPublicKeyData
{
public:
	/// all key components to be returned in big-endian format
	virtual long GetVersion() const=0;
	virtual void GetPrivateKey(_Out_ VectorOfByte &vecData) const=0; // big endian 
};

/** pure abstract base class for manipulating ECC signature*/

class IECCSignature : public virtual IKeyData
{
public:
	/// all key components to be returned in big-endian format
	virtual void r(_Out_ VectorOfByte &vecData) const=0;
	virtual void s(_Out_ VectorOfByte &vecData) const=0;
//	virtual void OID(_Out_ std::string &oid) const=0;
};


/** pure abstract base class for manipulating key formats. Concrete implementations should inherit
an IKeyEncoder, and a IKeyData override (e.g. IRSAPrivateKeyData).
This uses the CAPI PUBLICKEYSTRUC as the encoded data
This will allow interchange between (for example) CSP private key blobs, and Pkcs8 private key blobs*/
class IKeyEncoder
{
public:
	virtual ~IKeyEncoder() {}

	/// get an encoded version of the key contained in this object
	virtual void GetEncodedData(_Out_ VectorOfByte &vecEncodedKey) = 0;

	/// initialise this object based on the supplied binary data
	virtual void SetEncodedData(_In_ const VectorOfByte &vecEncodedKey) = 0;

	/// initialise this object based on another key object (which may be in a different format).
	virtual void SetKey(_In_ const IKeyData &key) = 0;
};

} //namespace KeyEncoder

} //namespace AbstractKeys

