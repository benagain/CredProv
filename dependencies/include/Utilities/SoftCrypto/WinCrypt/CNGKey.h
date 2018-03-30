#pragma once

#include <string>
#include <list>
#include "Utilities\EdeficeCommon\SmartHandle.h"
#include "Utilities\EdeficeCommon\StringList.h"
#include "Utilities\EdeficeCommon\Exceptions\LocalisedException.h"

#ifndef MS_PLATFORM_KEY_STORAGE_PROVIDER
#define MS_PLATFORM_KEY_STORAGE_PROVIDER   L"Microsoft Platform Crypto Provider"
#endif
#ifndef MS_NGC_KEY_STORAGE_PROVIDER
#define MS_NGC_KEY_STORAGE_PROVIDER        L"Microsoft Passport Key Storage Provider"
#endif

/// CNG key storage interface
namespace CngKey
{

/// One key provider
class KeyProvider
{
public:
	void operator=(_In_ const NCryptProviderName& rhs);

	std::wstring	name;			///< provider name
	std::wstring	comment;		///< provider comment
};

/// List of providers
class KeyProviderList : public std::list<KeyProvider>
{
public:
	void Load(_In_ bool force = false);
};

extern KeyProviderList KeyProviders;

struct NCRYPT_HANDLE_Deleter
{
	void operator()(_In_ NCRYPT_HANDLE handle) const
	{
		NCryptFreeObject(handle);
	}
};

/// A provider or key handle
/// \note Provides smart handle closing
typedef myid::SmartHandle<NCRYPT_HANDLE, NCRYPT_HANDLE_Deleter, NULL> Handle;

/// Persisted key definition
class Key
{
public:
	std::wstring fullName(void) const;

	std::wstring	reader;			///< reader name
	std::wstring	name;			///< from NCryptKeyName.pszName
	std::wstring	alg;			///< from NCryptKeyName.pszAlgid
	DWORD			legacy;			///< from NCryptKeyName.dwLegacyKeySpec
	DWORD			flags;			///< from NCryptKeyName.dwFlags
	DWORD			openFlags;		///< flags from NCryptEnumKeys input
};
typedef std::list<Key> KeyList;

/// CNG Key Store processing
class Store
{
public:
	Store();
	~Store();

	OKBOOL OpenHandle(void);
	void CloseHandle(void);
	void Algorithms(void);
	KeyList& Keys(_In_ bool force = false);

	OKBOOL Create(_In_ const std::wstring& name, _In_ const std::wstring& alg, _In_ DWORD dwLegacyKeySpec, _In_ DWORD length, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Import(_In_ const std::wstring& name, _In_ const std::wstring& alg, _In_ DWORD dwLegacyKeySpec, _In_z_ const wchar_t* type, _In_ const VectorOfByte& input, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Import(_In_ const std::wstring& name, _In_z_ const wchar_t* type, _In_opt_ NCryptBufferDesc* parameterList, _In_ const VectorOfByte& input, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Export(_In_ const std::wstring& name, _In_z_ const wchar_t* type, _In_opt_ NCryptBufferDesc* parameterList, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Delete(_In_ const std::wstring& name, _In_ DWORD dwFlags);
	OKBOOL Decrypt(_In_ const std::wstring& name, _In_ const VectorOfByte& input, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Encrypt(_In_ const std::wstring& name, _In_ const VectorOfByte& input, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL SignHash(_In_ const std::wstring& name, _In_ const VectorOfByte& hash, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Verify(_In_ const std::wstring& name, _In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_opt_ void* padInfo, _In_ DWORD dwFlags);

	OKBOOL Create(_In_ const std::wstring& name, _In_ const std::wstring& alg, _In_ DWORD dwLegacyKeySpec, _In_ DWORD length, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _Out_ Handle& hKey, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Import(_In_ const std::wstring& name, _In_ const std::wstring& alg, _In_ DWORD dwLegacyKeySpec, _In_z_ const wchar_t* type, _In_ const VectorOfByte& input, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _Out_ Handle& hKey, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Import(_In_ const std::wstring& name, _In_z_ const wchar_t* type, _In_opt_ NCryptBufferDesc* parameterList, _In_ const VectorOfByte& input, _In_ DWORD _export, _In_ DWORD usage, _In_ DWORD dwFlags, _Out_ Handle& hKey, _In_opt_ const NCRYPT_UI_POLICY* ui_policy = nullptr);
	OKBOOL Export(_In_ const Handle& hKey, _In_z_ const wchar_t* type, _In_opt_ NCryptBufferDesc* parameterList, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Delete(_In_ const Handle& hKey, _In_ DWORD dwFlags);
	OKBOOL Decrypt(_In_ const Handle& hKey, _In_ const VectorOfByte& input, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Encrypt(_In_ const Handle& hKey, _In_ const VectorOfByte& input, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL SignHash(_In_ const Handle& hKey, _In_ const VectorOfByte& hash, _In_opt_ void* padInfo, _Out_ _Always_(_Post_valid_) VectorOfByte& output, _In_ DWORD dwFlags);
	OKBOOL Verify(_In_ const Handle& hKey, _In_ const VectorOfByte& hash, _In_ const VectorOfByte& signature, _In_opt_ void* padInfo, _In_ DWORD dwFlags);

	const Key* LocateKey(_In_ const std::wstring& name);
	OKBOOL OpenKey(_In_ const std::wstring& name, _Out_ _Always_(_Post_valid_) Handle& hKey);
	OKBOOL OpenKey(_In_ const Key& key, _Out_ _Always_(_Post_valid_) Handle& hKey);

	OKBOOL GetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _Out_ _Always_(_Post_valid_) std::wstring& str, _In_ DWORD dwFlags);
	OKBOOL GetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _Out_ _Always_(_Post_valid_) DWORD& value, _In_ DWORD dwFlags);
	OKBOOL GetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _Out_ _Always_(_Post_valid_) void*& value, _In_ DWORD dwFlags);
	OKBOOL GetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _Out_ _Always_(_Post_valid_) VectorOfByte& data, _In_ DWORD dwFlags);
	OKBOOL SetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _In_ const std::wstring& str, _In_ DWORD dwFlags);
	OKBOOL SetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _In_ DWORD value, _In_ DWORD dwFlags);
	OKBOOL SetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _In_ const void*& value, _In_ DWORD dwFlags);
	OKBOOL SetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _In_ const VectorOfByte& data, _In_ DWORD dwFlags);
	OKBOOL SetProperty(_In_ const Handle& hObject, _In_z_ const wchar_t* prop, _In_ const PBYTE data, _In_ DWORD size, _In_ DWORD dwFlags);

	std::wstring Provider(void) const;
	void Provider(_In_ const std::wstring& provider);
	void Readers(_In_ const StringList& readers);
	const Handle& ProviderHandle(void);
	bool SmartCard(void) const;
	bool Platform(void) const;
	bool WHfB(void) const;
	SECURITY_STATUS Error(void) const;
	void Throw(_In_ const std::wstring& info) const;
	void Throw(_In_ const myid::Localisation& location, _In_ const std::wstring& info) const;

	DWORD					m_algCount;			///< count of algorithms
	NCryptAlgorithmName*	m_algs;				///< algorithms
	KeyList					m_keys;				///< list of keys

protected:
	std::wstring			m_provider;			///< provider name
	bool					m_smartcard;		///< is smart card provider
	bool					m_platform;			///< is platform provider
	bool					m_whfb;				///< is passport provider
	StringList				m_readers;			///< smart card readers
	Handle					m_handle;			///< provider handle
	SECURITY_STATUS			m_error;			///< error code
};

} // namespace CngKey
