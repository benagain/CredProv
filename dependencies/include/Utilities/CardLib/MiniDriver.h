/// \file MiniDriver.h
/// Mini driver high level support

#pragma once

#include "MiniDriverBase.h"

namespace md
{

const BYTE INVALID_CONTAINER = 0xff;		///< invalid container
typedef char filename[9];					///< filename spec

/*!
* Mini driver with support functions
* Current published version of Smart Card Minidriver Specification is v7.07
* https://msdn.microsoft.com/en-us/library/windows/hardware/dn631754
*/

class MiniDriver : public MiniDriverBase
{
	typedef MiniDriverBase inherited;

public:
	/// container map handling
	class CardMap : public CONTAINER_MAP_RECORD
	{
	public:
		CardMap();

		void operator=(const std::wstring& rhs);
		bool operator==(const std::wstring& rhs) const;
		bool operator!=(const std::wstring& rhs) const;

		void clear(void);
		bool valid(void) const;
	};

	/// container map array
	typedef std::vector<CardMap> vecCardMap;

	MiniDriver();

	virtual void ConnectNoCard(const std::wstring& cardName);

	virtual bool ReadOnly(void) const;
	virtual void SetInternalData(void);

	virtual bool NeedGenerate(void) const;
	virtual void Generate(void) const;
	virtual list Apps(void) const;
	virtual WORD AddApp(const std::string& app, CARD_DIRECTORY_ACCESS_CONDITION access = UserCreateDeleteDirAc) const;
	virtual void DeleteApp(const std::string& app) const;
	virtual bool AppExists(const std::string& app) const;
	virtual void EraseCard(void) const;

	virtual std::wstring SerialNumber(bool shortForm = false) const;
	virtual std::wstring SerialNumberFromID(bool shortForm = false) const;

	virtual bool ResetCounters(void) const;
	virtual bool IncPINCounter(void) const;
	virtual bool IncContainerCounter(void) const;
	virtual bool IncFileCounter(void) const;
	virtual bool IncContainerFileCounter(void) const;
	virtual DWORD ReadAppDataCache(WORD app) const;
	virtual bool WriteAppDataCache(DWORD value, WORD app) const;

	virtual bool ReadCMap(bool force) const;
	virtual bool WriteCMap(void) const;

	virtual bool FileExists(const std::string& directoryName, const std::string& fileName) const;
	virtual bool FileReadable(const std::string& directoryName, const std::string& fileName) const;
	virtual void DeleteFiles(const std::string& app, const std::string& except = "") const;

	virtual BYTE LocateContainer(const std::wstring& name, bool free = false) const;
	virtual StringList LoadContainers(bool all = false) const;
	virtual bool SetDefaultContainer(const std::wstring& name) const;
	virtual BYTE GetDefaultContainer(void) const;
	virtual bool GetDefaultContainer(std::wstring& name) const;
	virtual BYTE RenameContainer(const std::wstring& nameOld, const std::wstring& nameNew) const;
	virtual BYTE EraseContainer(const std::wstring& name) const;
	virtual void EraseContainers(void) const;

	virtual void ReadCertificate(const std::wstring& name, DWORD keySpec, VectorOfByte& data) const;
	virtual bool WriteCertificate(const std::wstring& name, DWORD keySpec, const VectorOfByte& data, bool compress = true) const;
	virtual bool GetKeySpec(const std::wstring& name, DWORD& keySpec) const;

	virtual bool SignData(BYTE containerIndex, DWORD keySpec, ALG_ID hashAlg, LPVOID paddingInfo, DWORD paddingType, DWORD signingFlags, const VectorOfByte& toSign, VectorOfByte& sign) const;
	virtual bool VerifySign(BYTE containerIndex, DWORD keySpec, ALG_ID hashAlg, LPVOID paddingInfo, DWORD paddingType, DWORD signingFlags, const VectorOfByte& toSign, const VectorOfByte& sign, bool& verified) const;
	virtual bool RSADecrypt(BYTE containerIndex, DWORD keySpec, LPVOID paddingInfo, DWORD paddingType, VectorOfByte& data) const;
	virtual bool RSAEncrypt(BYTE containerIndex, DWORD keySpec, DWORD paddingType, VectorOfByte& data) const;
	virtual bool GenerateRSA(const std::wstring& name, DWORD keySpec, DWORD keySize, BYTE& containerIndex, PIN_ID id = ROLE_USER) const;
	virtual bool GenerateKey(const std::wstring& name, DWORD keySpec, DWORD keySize, BYTE& containerIndex, PIN_ID id = ROLE_USER) const;
	virtual bool ImportRSA(const std::wstring& name, DWORD keySpec, const VectorOfByte& privateKey, BYTE& containerIndex, PIN_ID id = ROLE_USER) const;
	virtual bool ImportKey(const std::wstring& name, DWORD keySpec, const VectorOfByte& privateKey, BYTE& containerIndex, PIN_ID id = ROLE_USER) const;

	virtual void GetResponse(const std::wstring& key, VectorOfByte& response);
	virtual void GetResponse(const VectorOfByte& key, VectorOfByte& response);
	virtual void GetResponse(PIN_ID id, const std::wstring& key, VectorOfByte& response);
	virtual void GetResponse(PIN_ID id, const VectorOfByte& key, VectorOfByte& response);
	static void DeriveResponse(const VectorOfByte& challenge, const VectorOfByte& key, VectorOfByte& response);

	virtual bool SupportsSessionPIN(PIN_ID id);

	mutable vecCardMap		m_Map;					///< container map file

protected:
	/// card cache counters
	class CardCF : public CARD_CACHE_FILE_FORMAT
	{
	public:
		CardCF();

		void operator=(const VectorOfByte& rhs);
		operator VectorOfByte() const;

		bool empty(void) const;
		void clear(void);

		DWORD AppData(WORD app) const;
		void AppData(WORD app, DWORD value);

	protected:
		bool				m_empty;		///< data has been assigned
		std::vector<DWORD>	m_AppData;		///< app data
	};

	bool CreateRSA(const std::wstring& name, DWORD dwFlags, DWORD keySpec, DWORD keySize, BYTE* keyData, BYTE& containerIndex, PIN_ID id) const;
	bool CreateKey(const std::wstring& name, DWORD dwFlags, DWORD keySpec, DWORD keySize, BYTE* keyData, BYTE& containerIndex, PIN_ID id) const;
	bool DefaultKeySpec(BYTE containerIndex, DWORD& keySpec) const;
	bool CheckFileCache(bool force) const;
	bool ReadFileCache(bool force) const;
	bool WriteFileCache(void) const;

	bool					m_readOnly;				///< if true card is read only
	CARD_CAPABILITIES		m_Capabilities;			///< card capabilities
	mutable CardCF			m_CardCF;				///< cache counters
};

} // namespace md
