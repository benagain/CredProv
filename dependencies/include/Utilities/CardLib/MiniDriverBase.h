/// \file MiniDriverBase.h
/// Smart card minidriver interface
#pragma once

#include "Utilities/Softcrypto/IncludeCardmod.h"
#include "Utilities\EdeficeCommon\Exceptions\LocalisedException.h"

#undef CreateFile
#undef DeleteFile
#undef CreateDirectory

#define MD_BEGIN_COMMAND try { md::MiniDriverInCommand inCommand(this);
#define MD_BEGIN_COMMAND2(base) try { md::MiniDriverInCommand inCommand(base);
#define MD_END_COMMAND } catch (std::exception& e) { throw std::exception(e.what()); }

namespace md
{

/// Mini driver interface
class MiniDriverBase
{
	friend class MiniDriverInCommand;

public:
	struct ContainerInfo						/// Container data
	{
		ContainerInfo()
			: m_bContainerIndex(0), m_dwVersion(0)
		{}

		BYTE			m_bContainerIndex;		///< container number
		DWORD			m_dwVersion;			///< container version
		VectorOfByte	m_ExchangeKey;			///< exchange key
		VectorOfByte	m_SignatureKey;			///< signature key
	};

	/// cache
	typedef std::map<std::wstring, VectorOfByte> cache_data;
	/// cache data item
	typedef std::pair<std::wstring, VectorOfByte> cache_pair;
	/// list
	typedef std::vector<std::string> list;

	MiniDriverBase();
	virtual ~MiniDriverBase();

	virtual std::wstring MiniDriverName(void) const;
	virtual void MiniDriverName(const std::wstring& name);
	virtual std::wstring CardName(void) const;
	virtual void CardName(const std::wstring& name);
	virtual VectorOfByte ATR(void) const;
	virtual void ATR(const VectorOfByte& atr);

	virtual const CARD_DATA& CardData(void) const;
	virtual bool Load(SCARDCONTEXT context, SCARDHANDLE handle);
	virtual bool ThrowOnError(bool bThrow = true) const;
	virtual bool ThrowOnError(void) const;
	virtual DWORD Error(void) const;
	virtual void ClearError(void) const;
	virtual bool Success(void) const;
	virtual void FreeMemory(LPVOID mem) const;
	virtual void EraseCache(void) const;

	virtual CARD_FREE_SPACE_INFO QueryFreeSpace(void) const;
	virtual CARD_CAPABILITIES QueryCapabilities(void) const;
	virtual CARD_KEY_SIZES QueryKeySizes(DWORD keySpec) const;
	virtual bool GetProperty(LPWSTR _property, void* data, DWORD dataSize, DWORD& dataLen, DWORD flags) const;
	virtual bool GetProperty(CARD_FREE_SPACE_INFO& info) const;
	virtual bool GetProperty(CARD_CAPABILITIES& info) const;
	virtual bool GetProperty(CARD_KEY_SIZES& info, DWORD keySpec) const;
	virtual bool GetProperty(PIN_INFO& info, PIN_ID flags) const;
	virtual bool GetProperty(LPWSTR _property, PIN_SET& info) const;
	virtual bool SetProperty(LPWSTR _property, void* data, DWORD dataSize, DWORD flags) const;

	virtual ContainerInfo GetContainerInfo(BYTE containerIndex) const;
	virtual bool CreateContainer(BYTE containerIndex, DWORD flags, DWORD keySpec, DWORD keySize, PBYTE keyData) const;
	virtual bool CreateContainer(BYTE containerIndex, DWORD flags, DWORD keySpec, DWORD keySize, PBYTE keyData, PIN_ID id) const;
	virtual bool DeleteContainer(BYTE containerIndex) const;
	virtual bool GetContainerProperty(BYTE containerIndex, LPWSTR _property, void* data, DWORD dataSize, DWORD& dataLen, DWORD flags) const;
	virtual bool GetContainerProperty(BYTE containerIndex, ContainerInfo& info) const;
	virtual bool GetContainerProperty(BYTE containerIndex, PIN_ID& info) const;
	virtual bool SetContainerProperty(BYTE containerIndex, LPWSTR _property, void* data, DWORD dataSize, DWORD flags) const;

	virtual bool CreateDirectory(const std::string& directoryName, CARD_DIRECTORY_ACCESS_CONDITION access) const;
	virtual bool DeleteDirectory(const std::string& directoryName) const;
	virtual list EnumFiles(const std::string& directoryName) const;
	virtual CARD_FILE_INFO FileInfo(const std::string& directoryName, const std::string& fileName) const;
	virtual bool CreateFile(const std::string& directoryName, const std::string& fileName, DWORD size, CARD_FILE_ACCESS_CONDITION access) const;
	virtual VectorOfByte ReadFile(const std::string& directoryName, const std::string& fileName) const;
	virtual bool WriteFile(const std::string& directoryName, const std::string& fileName, const VectorOfByte& data) const;
	virtual bool WriteFile(const std::string& directoryName, const std::string& fileName, const void* pbData, DWORD cbData) const;
	virtual bool DeleteFile(const std::string& directoryName, const std::string& fileName) const;

	virtual bool Authenticate(const VectorOfByte& pin, bool admin, DWORD* attemptsRemaining = nullptr) const;
	virtual bool Authenticate(PIN_ID id, const VectorOfByte& pin, VectorOfByte* sessionPin, DWORD flags, DWORD* attemptsRemaining = nullptr) const;
	virtual bool DeAuthenticate(bool admin) const;
	virtual bool DeAuthenticate(PIN_SET pins) const;
	virtual bool GetChallenge(VectorOfByte& challenge) const;
	virtual bool GetChallenge(PIN_ID id, VectorOfByte& challenge) const;
	virtual VectorOfByte GetChallenge(void) const;
	virtual VectorOfByte GetChallenge(PIN_ID id) const;
	virtual bool AuthenticateChallenge(const VectorOfByte& response, DWORD* attemptsRemaining = nullptr) const;
	virtual bool UnblockPIN(const VectorOfByte& response, const VectorOfByte& pin, DWORD retryCount = 0) const;
	virtual bool ChangePIN(const VectorOfByte& oldPin, const VectorOfByte& newPin, bool admin, DWORD retryCount = 0, DWORD* attemptsRemaining = nullptr) const;
	virtual bool ChangeSOPIN(const VectorOfByte& response, const VectorOfByte& newPin, DWORD retryCount = 0, DWORD* attemptsRemaining = nullptr) const;
	virtual bool ChangeAuthenticator(PIN_ID id, const VectorOfByte& pin, PIN_ID targetId, const VectorOfByte& targetPin, DWORD flags, DWORD retryCount = 0, DWORD* attemptsRemaining = nullptr) const;

	virtual bool SignData(CARD_SIGNING_INFO& info) const;
	virtual bool RSADecrypt(CARD_RSA_DECRYPT_INFO& info) const;
	virtual bool DeriveKey(CARD_DERIVE_KEY& key) const;

	virtual bool ConstructDHAgreement(CARD_DH_AGREEMENT_INFO& agreementInfo) const;
	virtual bool DestroyDHAgreement(BYTE secretAgreementIndex, DWORD flags) const;

	virtual bool MDImportSessionKey(LPCWSTR blobType, LPCWSTR algId, CARD_KEY_HANDLE& hKey, const VectorOfByte& input) const;
	virtual bool MDEncryptData(CARD_KEY_HANDLE hKey, LPCWSTR secureFunction, const VectorOfByte& input, DWORD flags, std::list<VectorOfByte>& output) const;
	virtual bool ImportSessionKey(BYTE containerIndex, LPVOID paddingInfo, LPCWSTR blobType, LPCWSTR algId, CARD_KEY_HANDLE& hKey, const VectorOfByte& input, DWORD flags) const;
	virtual bool GetSharedKeyHandle(const VectorOfByte& input, VectorOfByte& output, CARD_KEY_HANDLE& hKey) const;
	virtual bool GetAlgorithmProperty(LPCWSTR algId, LPCWSTR _property, void* data, DWORD dataSize, DWORD& dataLen, DWORD flags) const;
	virtual bool GetKeyProperty(CARD_KEY_HANDLE hKey, LPCWSTR _property, void* data, DWORD dataSize, DWORD& dataLen, DWORD flags) const;
	virtual bool SetKeyProperty(CARD_KEY_HANDLE hKey, LPCWSTR _property, void* data, DWORD dataSize, DWORD flags) const;
	virtual bool DestroyKey(CARD_KEY_HANDLE hKey) const;
	virtual bool ProcessEncryptedData(CARD_KEY_HANDLE hKey, LPCWSTR secureFunction, const std::list<VectorOfByte>& input, VectorOfByte& output, DWORD flags) const;

	virtual HMODULE GetModule() const;

protected:
	virtual void Unload(void);
	virtual bool HandleError(const myid::Localisation& location, const wchar_t* message, const wchar_t* extra1 = nullptr, const wchar_t* extra2 = nullptr) const;
	virtual bool HandleError(const myid::Localisation& location, const wchar_t* message, BYTE containerIndex) const;
	virtual bool HandleError(const myid::Localisation& location, const wchar_t* message, DWORD extra) const;
	virtual bool HandleError(const myid::Localisation& location, const wchar_t* message, const std::string& directoryName) const;
	virtual bool HandleError(const myid::Localisation& location, const wchar_t* message, const std::string& directoryName, const std::string& fileName) const;
	virtual bool HandlePropertyError(const myid::Localisation& location, const wchar_t* message, const wchar_t* _property) const;
	virtual bool ThrowError(void) const;
	virtual bool TestNULL(const void* func) const;
	virtual void InCommand(bool begin) const;
	static LPSTR NamePtr(const std::string& name);

	std::wstring	m_MiniDriver;			///< driver name
	CARD_DATA		m_CardData;				///< card data
	VectorOfByte	m_ATR;					///< ATR for card data
	std::wstring	m_CardName;				///< card name for card data
	mutable bool	m_Throw;				///< throw on error
	HMODULE			m_Module;				///< driver DLL module handle
	mutable DWORD	m_rc;					///< error code
	mutable cache_data	m_Cache;			///< cache
};

//==========================================================================================

/// Auto manage the in command state
class MiniDriverInCommand
{
public:
	explicit MiniDriverInCommand(const MiniDriverBase* miniDriver)
		: m_miniDriver(miniDriver)
	{
		m_miniDriver->InCommand(true);
	}
	~MiniDriverInCommand()
	{
		m_miniDriver->InCommand(false);
	}

private:
	const MiniDriverBase* m_miniDriver;		///< minidriver to manage
};

} // namespace md
