#pragma once

#include "KeyStoreEncoder.h" 

namespace AbstractKeys
{

namespace KeyEncoder
{
/** class that can be initialised with X and Y, to allow subsequent retrieval using another format (such as ECCPublicKey) */
class ECCPublicKeyHolder : public KeyStore::ECCPublicKeyData
{
public:
	ECCPublicKeyHolder(_In_ const VectorOfByte &vecX, _In_ const VectorOfByte &vecY)
	{
		x = vecX;
		y = vecY;
		m_initialised = true;
	}

};

class ECCPublicKey : public IECCPublicKeyData, public IKeyEncoder 
{
public:
	// IECCPublicKeyData
	virtual void GetPublicKey(_Out_ VectorOfByte &vecData) const; // big endian pubkey - no RFC5480 compression byte just the X+Y?
	virtual void GetOID(_Out_ std::string &oid) const;
	virtual long GetKeySizeBits() const;

	//IKeyEncoder
	virtual void GetEncodedData(_Out_ VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(_In_ const VectorOfByte &vecEncodedKey);
	virtual void SetKey(_In_ const IKeyData &key);

protected:
	KeyStore::ECCPublic m_key;
};

} //namespace KeyEncoder

} //namespace AbstractKeys
