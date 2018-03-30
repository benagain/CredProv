#pragma once

#include "ECCPublicKey.h"

namespace AbstractKeys
{

namespace KeyEncoder
{

/**
	The BCRYPT_ECCKEY_BLOB structure is used as a header for an elliptic curve public key or private key BLOB in memory.

	Consists of two (4 byte) ULONGs describing the type (dwMagicNumber) and length in bytes of the key (cbKey)

	and if followed by either a BCRYPT_ECCPUBLIC_BLOB or BCRYPT_ECCKEY_BLOB

	For BCRYPT_ECCKEY_BLOB the following cbKey are the X co-ordinates, and then the Y co-ordinates as
	unsigned integers in big-endian, the BCRYPT_ECCPRIVATE_BLOB has a third 'd' co-ordinate


*/

class ECCPublicKeyCNG : public ECCPublicKey
{
public:
	//IKeyEncoder
	virtual void GetEncodedData(_Out_ VectorOfByte &vecEncodedKey);
	virtual void SetEncodedData(_In_ const VectorOfByte &vecEncodedKey);

};

} //namespace KeyEncoder

} //namespace AbstractKeys
