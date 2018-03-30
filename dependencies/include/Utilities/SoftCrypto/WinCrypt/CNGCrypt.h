#pragma once
#ifndef MOBILE
#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include "Utilities/EdeficeCommon/SmartHandle.h"
#include "../CommonKey.h"

#include <bcrypt.h>

/// CNG bcrypt interface
namespace CngCrypt
{

bool FipsMode();

struct BCRYPT_KEY_HANDLE_Deleter
{
	void operator()(_In_ BCRYPT_KEY_HANDLE handle) const
	{
		BCryptDestroyKey(handle);
	}
};

/// An ephemeral key handle
/// \note Provides smart handle closing
typedef myid::SmartHandle<BCRYPT_KEY_HANDLE, BCRYPT_KEY_HANDLE_Deleter, nullptr> Key;

/// Wraps an algorithm handle
class AlgHandle
{
public:
	explicit AlgHandle(_In_z_ LPCWSTR algId);
	AlgHandle(_In_z_ LPCWSTR algId, _In_ DWORD flags);
	AlgHandle(_In_z_ LPCWSTR algId, _In_ DWORD flags, _In_z_ LPCWSTR provider);
	~AlgHandle();

	operator BCRYPT_ALG_HANDLE() const;
	DWORD OBJECT_LENGTH() const;
	DWORD HASH_LENGTH() const;

	static const AlgHandle& Handle(_In_z_ LPCWSTR algId, _In_opt_z_ LPCWSTR version = nullptr);
	static const AlgHandle& Handle(_In_z_ LPCWSTR algId, _In_ DWORD flags, _In_opt_z_ LPCWSTR version = nullptr);
	static const AlgHandle& Handle(_In_z_ LPCWSTR algId, _In_ DWORD flags, _In_z_ LPCWSTR provider, _In_opt_z_ LPCWSTR version = nullptr);

protected:
	BCRYPT_ALG_HANDLE handle;		///< the algorithm handle
};

/// Random number generation
class Random : public MyCrypto::Random
{
public:
	static VectorOfByte Generate(_In_ int bytes);
	static VectorOfByte Generate(_In_ const VectorOfByte& entropy, _In_ int bytes);

	virtual void Seed() const;
	virtual VectorOfByte Bytes(_In_ int bytes) const;
	virtual VectorOfByte Bytes(_In_ const VectorOfByte& entropy, _In_ int bytes) const;
};

/// Data protection using DPAPI
class Protect
{
public:
	static OKBOOL ProtectData(_In_ const std::string& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL ProtectData(_In_ const std::wstring& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL ProtectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL ProtectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _In_ const std::wstring& description, _In_opt_ CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct, _In_ DWORD dwFlags, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL UnprotectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) std::string& outData);
	static OKBOOL UnprotectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) std::wstring& outData);
	static OKBOOL UnprotectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL UnprotectData(_In_ const VectorOfByte& inData, _In_ const VectorOfByte& entropy, _Out_ _Always_(_Post_valid_) std::wstring& description, _In_opt_ CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct, _In_ DWORD dwFlags, _Out_ _Always_(_Post_valid_) VectorOfByte& outData);
	static OKBOOL ProtectMemory(_Inout_ VectorOfByte& data);
	static OKBOOL UnprotectMemory(_Inout_ VectorOfByte& data);
};

} // namespace CngCrypt
#endif
