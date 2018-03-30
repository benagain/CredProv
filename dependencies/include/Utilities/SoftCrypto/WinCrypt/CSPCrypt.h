#pragma once

#include "Utilities\EdeficeCommon\VectorOfByte.h"
#include "Utilities\EdeficeCommon\SmartHandle.h"
#include "CSPCommon.h"
#include "../CommonKey.h"

/// CSP crypt interface
namespace CspCrypt
{

DWORD ProviderType(_In_ const std::wstring &CSPName);

struct HCRYPTPROV_Deleter
{
	void operator()(_In_ HCRYPTPROV handle) const
	{
		CryptReleaseContext(handle, 0);
	}
};

/// A provider handle
/// \note Provider smart handle closing
typedef public myid::SmartHandle<HCRYPTPROV, HCRYPTPROV_Deleter, NULL> ProvHandle;

struct HCRYPTKEY_Deleter
{
	void operator()(_In_ HCRYPTKEY handle) const
	{
		CryptDestroyKey(handle);
	}
};

/// A key handle
/// \note Key smart handle closing
typedef myid::SmartHandle<HCRYPTKEY, HCRYPTKEY_Deleter, NULL> KeyHandle;

struct HCRYPTHASH_Deleter
{
	void operator()(_In_ HCRYPTHASH handle) const
	{
		CryptDestroyHash(handle);
	}
};

/// A hash handle
/// \note Hash smart handle closing
typedef public myid::SmartHandle<HCRYPTHASH, HCRYPTHASH_Deleter, NULL> HashHandle;

/// Random number generation
class Random : public MyCrypto::Random, public CspCommon
{
public:
	static VectorOfByte Generate(_In_ int bytes);
	static VectorOfByte Generate(_In_ const VectorOfByte& entropy, _In_ int bytes);

	virtual void Seed() const;
	virtual VectorOfByte Bytes(_In_ int bytes) const;
	virtual VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes) const;
};

} // namespace CspCrypt
