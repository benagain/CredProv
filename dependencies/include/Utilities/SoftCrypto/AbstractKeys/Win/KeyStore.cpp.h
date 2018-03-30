#include "..\StdAfx.h"

namespace KeyStore
{

unsigned long CNGMagic(_In_ const VectorOfByte& rhs)
{
	if (rhs.size() < sizeof(BCRYPT_KEY_BLOB))
		throw myid::LocalisedException(LOCALISE_FN_STATIC, L"Data too small");

	const BCRYPT_KEY_BLOB* blob = (const BCRYPT_KEY_BLOB*)rhs.ptr();
	return blob->Magic;
}

//=====================================================================================================================================================
//=====================================================================================================================================================

bool KeyContainer::CNG(_In_ const VectorOfByte& rhs)
{
	bool rtn = false;
	unsigned long magic = CNGMagic(rhs);

	switch (magic)
	{
	case BCRYPT_RSAPUBLIC_MAGIC:
	{
		RSAPublic* rsa = new RSAPublic;
		rtn = rsa->CNG(rhs);
		key = KeyPtr(rsa);
		m_initialised = true;
		break;
	}
	case BCRYPT_RSAPRIVATE_MAGIC:
	case BCRYPT_RSAFULLPRIVATE_MAGIC:
	{
		RSAPrivate* rsa = new RSAPrivate;
		rtn = rsa->CNG(rhs);
		key = KeyPtr(rsa);
		m_initialised = true;
		break;
	}
	case BCRYPT_ECDH_PUBLIC_P256_MAGIC:
	case BCRYPT_ECDH_PUBLIC_P384_MAGIC:
	case BCRYPT_ECDH_PUBLIC_P521_MAGIC:
	case BCRYPT_ECDSA_PUBLIC_P256_MAGIC:
	case BCRYPT_ECDSA_PUBLIC_P384_MAGIC:
	case BCRYPT_ECDSA_PUBLIC_P521_MAGIC:
	{
		ECCPublic* ecc = new ECCPublic;
		rtn = ecc->CNG(rhs);
		key = KeyPtr(ecc);
		m_initialised = true;
		break;
	}
	case BCRYPT_ECDH_PRIVATE_P256_MAGIC:
	case BCRYPT_ECDH_PRIVATE_P384_MAGIC:
	case BCRYPT_ECDH_PRIVATE_P521_MAGIC:
	case BCRYPT_ECDSA_PRIVATE_P256_MAGIC:
	case BCRYPT_ECDSA_PRIVATE_P384_MAGIC:
	case BCRYPT_ECDSA_PRIVATE_P521_MAGIC:
	{
		ECCPrivate* ecc = new ECCPrivate;
		rtn = ecc->CNG(rhs);
		key = KeyPtr(ecc);
		m_initialised = true;
		break;
	}
	default:
		key.reset();
		m_initialised = false;
	}
	return rtn;
}

VectorOfByte KeyContainer::CNG(void) const
{
	if (key)
		return key->CNG();

	return VectorOfByte();
}

//=====================================================================================================================================================
//=====================================================================================================================================================

bool RSAPublic::CNG(_In_ const VectorOfByte& rhs)		///< Source is BCRYPT_RSAKEY_BLOB
{
	LocalClear();

	if (rhs.size() < sizeof(BCRYPT_RSAKEY_BLOB))
		throw myid::LocalisedException(LOCALISE_FN, L"Data too small");

	const BCRYPT_RSAKEY_BLOB* blob = (const BCRYPT_RSAKEY_BLOB*)rhs.ptr();
	if ((blob->Magic != BCRYPT_RSAPUBLIC_MAGIC) &&
		(blob->Magic != BCRYPT_RSAPRIVATE_MAGIC) &&
		(blob->Magic != BCRYPT_RSAFULLPRIVATE_MAGIC))
		throw myid::LocalisedException(LOCALISE_FN, L"Wrong source");

	if (rhs.size() < sizeof(BCRYPT_RSAKEY_BLOB) + blob->cbPublicExp + blob->cbModulus)
		throw myid::LocalisedException(LOCALISE_FN, L"Data too small");

	bitLength = blob->BitLength;

	const byte* data = (const byte*)(blob + 1);
	publicExponent.set(data, blob->cbPublicExp);
	data += blob->cbPublicExp;
	modulus.set(data, blob->cbModulus);

	SetInitialised();
	return m_initialised;
}

VectorOfByte RSAPublic::CNG(void) const
{
	VectorOfByte rtn;

	if (m_initialised)
	{
		rtn.reserve(sizeof(BCRYPT_RSAKEY_BLOB) + publicExponent.size() + modulus.size());
		rtn.resize(sizeof(BCRYPT_RSAKEY_BLOB));

		BCRYPT_RSAKEY_BLOB* blob = (BCRYPT_RSAKEY_BLOB*)rtn.ptr();
		blob->Magic = BCRYPT_RSAPUBLIC_MAGIC;
		blob->BitLength = bitLength;
		blob->cbPublicExp = publicExponent.lsize();
		blob->cbModulus = modulus.lsize();
		blob->cbPrime1 = 0;
		blob->cbPrime2 = 0;

		rtn += publicExponent;
		rtn += modulus;
	}

	return rtn;
}

//=====================================================================================================================================================
//=====================================================================================================================================================

bool RSAPrivate::CNG(_In_ const VectorOfByte& rhs)			///< Source is BCRYPT_RSAKEY_BLOB
{
	LocalClear();

	const BCRYPT_RSAKEY_BLOB* blob = (const BCRYPT_RSAKEY_BLOB*)rhs.ptr();
	if (blob->Magic == BCRYPT_RSAPRIVATE_MAGIC)
	{
		if (rhs.size() < sizeof(BCRYPT_RSAKEY_BLOB) + blob->cbPublicExp + blob->cbModulus + blob->cbPrime1 + blob->cbPrime2)
		{
			Clear();
			throw myid::LocalisedException(LOCALISE_FN, L"Data too small");
		}

		if (!inherited::CNG(rhs))
			return false;
	}
	else if (blob->Magic == BCRYPT_RSAFULLPRIVATE_MAGIC)
	{
		if (rhs.size() < sizeof(BCRYPT_RSAKEY_BLOB) + blob->cbPublicExp + blob->cbModulus * 2 + blob->cbPrime1 * 3 + blob->cbPrime2 * 2)
		{
			Clear();
			throw myid::LocalisedException(LOCALISE_FN, L"Data too small");
		}

		if (!inherited::CNG(rhs))
			return false;
	}
	else if (blob->Magic == BCRYPT_RSAPUBLIC_MAGIC)
	{
		m_public = true;
		return inherited::CNG(rhs);
	}
	else
	{
		Clear();
		throw myid::LocalisedException(LOCALISE_FN, L"Wrong source");
	}

	const byte* data = (const byte*)(blob + 1);
	data += blob->cbPublicExp + blob->cbModulus;
	prime1.set(data, blob->cbPrime1);
	data += blob->cbPrime1;
	prime2.set(data, blob->cbPrime2);

	if (blob->Magic == BCRYPT_RSAFULLPRIVATE_MAGIC)
	{
		data += blob->cbPrime2;
		exponent1.set(data, blob->cbPrime1);
		data += blob->cbPrime1;
		exponent2.set(data, blob->cbPrime2);
		data += blob->cbPrime2;
		coefficient.set(data, blob->cbPrime1);
		data += blob->cbPrime1;
		privateExponent.set(data, blob->cbModulus);
	}

	SetInitialised();
	return m_initialised;
}

VectorOfByte RSAPrivate::CNG(void) const
{
	VectorOfByte rtn = inherited::CNG();

	if (m_initialised && !m_public)
	{
		rtn.reserve(rtn.size() + prime1.size() + prime2.size() + exponent1.size() + exponent2.size() + coefficient.lsize() + privateExponent.lsize());

		BCRYPT_RSAKEY_BLOB* blob = (BCRYPT_RSAKEY_BLOB*)rtn.ptr();
		blob->Magic = BCRYPT_RSAFULLPRIVATE_MAGIC;
		blob->cbPrime1 = prime1.lsize();
		blob->cbPrime2 = prime2.lsize();

		rtn += prime1;
		rtn += prime2;
		rtn += exponent1;
		rtn += exponent2;
		rtn += coefficient;
		rtn += privateExponent;
	}

	return rtn;
}

//=====================================================================================================================================================
//=====================================================================================================================================================

namespace
{
const int MAP_SIZE = 12;
struct EccMap
{
	unsigned long magic;
	Key::keyTypes type;
	Key::keySizes size;
	bool _public;
} map[MAP_SIZE] =
{
	{ BCRYPT_ECDH_PUBLIC_P256_MAGIC, Key::ECDH, Key::ECC256, true },
	{ BCRYPT_ECDH_PUBLIC_P384_MAGIC, Key::ECDH, Key::ECC384, true },
	{ BCRYPT_ECDH_PUBLIC_P521_MAGIC, Key::ECDH, Key::ECC521, true },
	{ BCRYPT_ECDSA_PUBLIC_P256_MAGIC, Key::ECDSA, Key::ECC256, true },
	{ BCRYPT_ECDSA_PUBLIC_P384_MAGIC, Key::ECDSA, Key::ECC384, true },
	{ BCRYPT_ECDSA_PUBLIC_P521_MAGIC, Key::ECDSA, Key::ECC521, true },
	{ BCRYPT_ECDH_PRIVATE_P256_MAGIC, Key::ECDH, Key::ECC256, false },
	{ BCRYPT_ECDH_PRIVATE_P384_MAGIC, Key::ECDH, Key::ECC384, false },
	{ BCRYPT_ECDH_PRIVATE_P521_MAGIC, Key::ECDH, Key::ECC521, false },
	{ BCRYPT_ECDSA_PRIVATE_P256_MAGIC, Key::ECDSA, Key::ECC256, false },
	{ BCRYPT_ECDSA_PRIVATE_P384_MAGIC, Key::ECDSA, Key::ECC384, false },
	{ BCRYPT_ECDSA_PRIVATE_P521_MAGIC, Key::ECDSA, Key::ECC521, false }
};
}

bool ECCPublic::CNG(_In_ const VectorOfByte& rhs)				///< Source is BCRYPT_ECCKEY_BLOB
{
	LocalClear();

	if (rhs.size() < sizeof(BCRYPT_ECCKEY_BLOB))
		throw myid::LocalisedException(LOCALISE_FN, L"Data too small");

	const BCRYPT_ECCKEY_BLOB* blob = (const BCRYPT_ECCKEY_BLOB*)rhs.ptr();
	int m;
	for (m = 0; m < MAP_SIZE; ++m)
	{
		if (blob->dwMagic == map[m].magic)
		{
			ksize = map[m].type;
			ksize = map[m].size;
			break;
		}
	}
	// were we passed a non-prefixed r|s?
	if (m == MAP_SIZE)
		throw myid::LocalisedException(LOCALISE_FN, L"Wrong source");

	if ((rhs.size() != sizeof(BCRYPT_ECCKEY_BLOB) + blob->cbKey * 2) &&
		(rhs.size() != sizeof(BCRYPT_ECCKEY_BLOB) + blob->cbKey * 3) )
			throw myid::LocalisedException(LOCALISE_FN, L"Data wrong size");

	const byte* data = (const byte*)(blob + 1);
	x.set(data, blob->cbKey);
	data += blob->cbKey;
	y.set(data, blob->cbKey);

	SetInitialised();
	return m_initialised;
}

VectorOfByte ECCPublic::CNG(void) const
{
	VectorOfByte rtn;

	if (m_initialised)
	{
		rtn.reserve(sizeof(BCRYPT_ECCKEY_BLOB) + ksize.bytes() * 2);
		rtn.resize(sizeof(BCRYPT_ECCKEY_BLOB));

		BCRYPT_ECCKEY_BLOB* blob = (BCRYPT_ECCKEY_BLOB*)rtn.ptr();
		for (int m = 0; m < MAP_SIZE; ++m)
		{
			if (map[m]._public &&
				(ksize == map[m].type) &&
				(ksize == map[m].size))
			{
				blob->dwMagic = map[m].magic;
				break;
			}
		}
		blob->cbKey = ksize.bytes();

		rtn += x;
		rtn += y;
	}

	return rtn;
}


//=====================================================================================================================================================
//=====================================================================================================================================================

bool ECCPrivate::CNG(_In_ const VectorOfByte& rhs)			///< Source is BCRYPT_ECCKEY_BLOB
{
	LocalClear();

	const BCRYPT_ECCKEY_BLOB* blob = (const BCRYPT_ECCKEY_BLOB*)rhs.ptr();
	int m;
	for (m = 0; m < MAP_SIZE; ++m)
	{
		if (blob->dwMagic == map[m].magic)
		{
			if (map[m]._public)
			{
				m_public = true;
				return inherited::CNG(rhs);
			}
			break;
		}
	}
	if (m == MAP_SIZE)
		throw myid::LocalisedException(LOCALISE_FN, L"Wrong source");

	if (rhs.size() != sizeof(BCRYPT_ECCKEY_BLOB) + blob->cbKey * 3)
		throw myid::LocalisedException(LOCALISE_FN, L"Data wrong size");

	if (!inherited::CNG(rhs))
		return false;

	const byte* data = (const byte*)(blob + 1);
	data += blob->cbKey * 2;
	prv.set(data, blob->cbKey);

	SetInitialised();
	return m_initialised;
}

VectorOfByte ECCPrivate::CNG(void) const
{
	VectorOfByte rtn = inherited::CNG();

	if (m_initialised && !m_public)
	{
		BCRYPT_ECCKEY_BLOB* blob = (BCRYPT_ECCKEY_BLOB*)rtn.ptr();
		for (int m = 0; m < MAP_SIZE; ++m)
		{
			if (!map[m]._public &&
				(ksize == map[m].type) &&
				(ksize == map[m].size))
			{
				blob->dwMagic = map[m].magic;
				break;
			}
		}

		rtn += prv;
	}

	return rtn;
}

} // namespace KeyStore
