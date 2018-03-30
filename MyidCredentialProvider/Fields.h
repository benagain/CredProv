#pragma once

namespace Fields
{

enum FIELD_ID
{
	FID_IMAGE = 0,
	FID_LABEL = 1,
	FID_NAME = 2,
	FID_READER = 3,
	FID_USERNAME = 4,
	FID_HINT = 5,
	FID_PROMPT = 6,
	FID_PIN = 7,
	FID_X509 = 8,
	FID_SUBMIT = 9,
	FID_NUM_FIELDS = 10
};

static const CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR FieldDescriptors[FID_NUM_FIELDS] =
{
	{ FID_IMAGE, CPFT_TILE_IMAGE, L"Image", CPFG_CREDENTIAL_PROVIDER_LOGO },
	{ FID_LABEL, CPFT_SMALL_TEXT, L"IPT", CPFG_CREDENTIAL_PROVIDER_LABEL },
	{ FID_NAME, CPFT_LARGE_TEXT, L"Name", CPFG_LOGON_USERNAME },
	{ FID_READER, CPFT_SMALL_TEXT, L"Reader" },
	{ FID_USERNAME, CPFT_SMALL_TEXT, L"Username", CPFG_SMARTCARD_USERNAME },
	{ FID_HINT, CPFT_SMALL_TEXT, L"Hint" },
	{ FID_PROMPT, CPFT_SMALL_TEXT, L"Empty" },
	{ FID_PIN, CPFT_PASSWORD_TEXT, L"PIN", CPFG_SMARTCARD_PIN },
	{ FID_X509, CPFT_EDIT_TEXT, L"Username hint" },
	{ FID_SUBMIT, CPFT_SUBMIT_BUTTON, L"Submit" },
};

static const CREDENTIAL_PROVIDER_FIELD_STATE FieldStates[FID_NUM_FIELDS] =
{
	CPFS_DISPLAY_IN_BOTH,
	CPFS_HIDDEN,
	CPFS_DISPLAY_IN_BOTH,
	CPFS_HIDDEN,
	CPFS_DISPLAY_IN_BOTH,
	CPFS_DISPLAY_IN_BOTH,
	CPFS_DISPLAY_IN_SELECTED_TILE,
	CPFS_HIDDEN,
	CPFS_HIDDEN,
	CPFS_DISPLAY_IN_SELECTED_TILE
};

class String
{
public:
	String();
	explicit String(_In_ bool secure);
	explicit String(_In_z_ LPCWSTR rhs);
	explicit String(_In_z_ LPCWSTR rhs, _In_ bool secure);
	explicit String(_In_ const std::wstring& rhs);
	explicit String(_In_ const std::wstring& rhs, _In_ bool secure);
	~String();

	String& operator=(_In_z_ LPCWSTR rhs);
	String& operator=(_In_ const std::wstring& rhs);
	explicit operator bool() const;
	operator LPCWSTR() const;
	HRESULT Dup(_Outptr_result_nullonfailure_ LPWSTR* ppsz) const;
	void Attach(_In_opt_z_ PWSTR ppsz);
	void Release(_Outptr_result_maybenull_ LPWSTR* ppsz);
	void Resource(_In_ UINT id);
	void Clear(void);
	void Secure(_In_ bool secure);
	bool Empty(void) const;

private:
	bool	m_secure{};
	PWSTR	m_string{};
};

} // namespace Fields
