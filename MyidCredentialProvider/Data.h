#pragma once

namespace Data
{

/// Reader detail
class Reader
{
public:
	void clear();

	std::wstring reader;			///< smart card reader
	std::wstring card;				///< card name
	bool ipt{};						///< is IPT type reader
	bool vsc{};						///< is Vsc type reader
};

/// Reader details
class Readers : public std::list<Reader>
{
public:
	Readers() = default;
	Readers(const Readers&) = delete;
	Readers& operator=(const Readers&) = delete;

	bool IsVscReader(_In_z_ LPCWSTR reader) const;
	bool IsIptReader(_In_z_ LPCWSTR reader) const;

	static Readers& Get(_In_ bool force = false);

private:
	void Load(_In_ bool force);

	bool m_gotten{};					///< gotten credentials
	std::recursive_mutex m_mutex;		///< mutex for Reader list
};

/// Data item from SetUserArray()
class User
{
public:
	std::wstring user;					///< user name
	std::wstring upn;					///< qualified user name converted to UPN
	std::wstring sid;					///< SID
};

/// All data from SetUserArray()
class Users : public std::vector<User>
{
public:
	Users() = default;
	Users(const Users&) = delete;
	Users& operator=(const Users&) = delete;

	static Users& Get(void);
};

/// Data from one certificate
class Credential : public Reader
{
public:
	void clear();
	DWORD sign() const;
	bool certificate(const VectorOfByte& certData);
	HRESULT serialisation(_In_ CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus, _In_opt_z_ LPCWSTR hint, _In_opt_z_ LPCWSTR pin, __RPC__out byte*& data, __RPC__out ULONG& dataSize);

	std::wstring name;						///< display name
	std::wstring user;						///< user name (UPN or DNS)
	std::wstring container;					///< container name
	std::wstring sid;						///< SID, if empty it is an original one obtained from the cards
	bool showUser{true};					///< show the user
	bool signedIn{false};					///< is signed in
	std::string certTemplate;				///< CA template OID
	DWORD certVersion{};					///< CA template major version
	UCHAR certHash[CERT_HASH_LENGTH] {};	///< SHA1 hash of cert
	FILETIME certExpiry{};					///< certificate expiry date
	DWORD keySpec{};						///< key spec that was used
};

/// All certificate data
class Credentials : public std::list<Credential>
{
public:
	Credentials() = default;
	Credentials(const Credentials&) = delete;
	Credentials& operator=(const Credentials&) = delete;

	bool IsVscUser(_In_opt_z_ LPCWSTR user) const;
	void SetSID(_In_ const std::wstring& upn, _In_ const std::wstring& sid);

	static Credentials& Get(_In_ bool force = false);
	void AddUsers(void);

private:
	void Load(_In_ bool force);

	bool m_gotten{};					///< gotten credentials
	std::recursive_mutex m_mutex;		///< mutex for Credential list
	std::recursive_mutex m_dataLock;	///< thread lock for Credential list
};

} // namespace Authenticate

