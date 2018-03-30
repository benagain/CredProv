#pragma once

#include "VectorOfByte.h"
#include <boost/noncopyable.hpp>

namespace myid
{

class HashAlgorithm : private boost::noncopyable
{
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE m_CryptProvider; // We don't own this
	DWORD m_KeyProvider; // Type of above
	const std::wstring m_Algorithm; // Standard identifier, e.g "SHA256"
public:
	HashAlgorithm(DWORD keyProvider, HCRYPTPROV_OR_NCRYPT_KEY_HANDLE handle, const std::wstring &algorithm)
		: m_CryptProvider(handle)
		, m_Algorithm(algorithm)
		, m_KeyProvider(keyProvider)
	{}
	virtual ~HashAlgorithm()
	{}

	virtual VectorOfByte HashData(const VectorOfByte &data) = 0;
	virtual VectorOfByte HashAndSignData(const VectorOfByte &data) = 0;
	const char *const GetOID() const;

	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE Provider() const
	{
		return m_CryptProvider;
	}
	DWORD KeyProvider() const
	{
		return m_KeyProvider;
	}
	const std::wstring &Algorithm() const
	{
		return m_Algorithm;
	}
};
typedef std::shared_ptr<myid::HashAlgorithm> HashAlgorithmPtr;

class HashAlgorithmFactory
{
public:
	static HashAlgorithmPtr Create(DWORD keyProvider, HCRYPTPROV_OR_NCRYPT_KEY_HANDLE handle, const std::wstring &algorithmIdentifier);
};

class CSPHasher : public HashAlgorithm
{
	ALG_ID m_AlgorithmID;
public:
	CSPHasher(DWORD keyProvider, HCRYPTPROV_OR_NCRYPT_KEY_HANDLE handle, const std::wstring &algorithmIdentifier);
	virtual ~CSPHasher();
	virtual VectorOfByte HashData(const VectorOfByte &data);
	virtual VectorOfByte HashAndSignData(const VectorOfByte &data);
};

class CNGHasher : public HashAlgorithm
{
	BCRYPT_ALG_HANDLE m_AlgorithmHandle;
public:
	CNGHasher(DWORD keyProvider, HCRYPTPROV_OR_NCRYPT_KEY_HANDLE handle, const std::wstring &algorithmIdentifier);
	virtual ~CNGHasher();
	virtual VectorOfByte HashData(const VectorOfByte &data);
	virtual VectorOfByte HashAndSignData(const VectorOfByte &data);
};

}