#pragma once

#include "../CommonKey.h"

struct aes_key_st;
struct evp_cipher_st;
struct DES_ks;

namespace OpenSSLCrypt
{

/// Common OpenSSL symmetric key handling
class SymKey : public MyCrypto::SymKey
{
public:
	SymKey();

protected:
	VectorOfByte fips_encrypt(_In_ const VectorOfByte& data, _In_ const byte* key, _Inout_opt_ byte* ivc, _In_opt_ const evp_cipher_st* cipher, _In_z_ const wchar_t* desc) const;
	VectorOfByte fips_decrypt(_In_ const VectorOfByte& data, _In_ const byte* key, _Inout_opt_ byte* ivc, _In_opt_ const evp_cipher_st* cipher, _In_z_ const wchar_t* desc) const;
};

/// Low level AES processing
class AES : public OpenSSLCrypt::SymKey
{
public:
	AES();
	virtual ~AES();

	virtual bool FIPS(void) const;
	virtual VectorOfByte exportKey(void) const;
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual bool hasKey(void) const;
	virtual OKBOOL generateKey(_In_ unsigned long keySize);
	virtual unsigned long blockSize(void) const;
	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_encrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_decrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;

protected:
	_Ret_maybenull_ const evp_cipher_st* cipher(_In_ bool ecb) const;

	byte			m_key[256 / 8];				///< key data, max is AES256
	unsigned long	m_keySize;					///< key size in bits (128, 192, 256)
	bool			m_valid;					///< key is valid
	aes_key_st*		m_encryptKey;				///< non FIPS encryption key
	aes_key_st*		m_decryptKey;				///< non FIPS decryption key
};

/// Low level DES processing
class DES : public OpenSSLCrypt::SymKey
{
public:
	DES();
	virtual ~DES();

	virtual bool FIPS(void) const;
	virtual VectorOfByte exportKey(void) const;
	virtual OKBOOL importKey(_In_ const VectorOfByte& key);
	virtual bool hasKey(void) const;
	virtual OKBOOL generateKey(_In_ unsigned long keySize);
	virtual unsigned long blockSize(void) const;
	virtual VectorOfByte encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_encrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_encrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;
	virtual VectorOfByte decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte ecb_decrypt(_In_ const VectorOfByte& data) const;
	virtual VectorOfByte cbc_decrypt(_In_ const VectorOfByte& data, _Inout_ VectorOfByte& ivc) const;

	static void setParity(_Inout_ VectorOfByte& key);
	static void setParity(_Inout_updates_(keySize) byte* key, _In_ unsigned long keySize);
	static bool isWeakKey(_In_ const VectorOfByte& key);
	static bool isWeakKey(_In_reads_(keySize) const byte* key, _In_ unsigned long keySize);

protected:
	const evp_cipher_st* cipher(_In_ bool ecb) const;

	byte			m_key[3][8];				///< key data, max is 3DES
	unsigned long	m_keySize;					///< key size in bits (64, 96, 128)
	bool			m_valid;					///< key is valid
	DES_ks*			m_ks;						///< non FIPS key schedule
};

/// Password based key derivation
class PBKDF2 : public MyCrypto::PBKDF2
{
public:
	virtual VectorOfByte Derive(_In_ const std::string& password, _In_ const VectorOfByte& salt, _In_ const AbstractKeys::CryptParameters::HashType hashType, _In_ unsigned long length, _In_ int iterations = 2048) const;
};

} // namespace OpenSSLCrypt
