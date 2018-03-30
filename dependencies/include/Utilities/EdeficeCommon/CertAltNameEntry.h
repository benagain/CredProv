#pragma once

namespace myid
{

class CertAltNameEntry
{
public:
	explicit CertAltNameEntry(PCERT_ALT_NAME_ENTRY const pEntry);

	std::wstring Type() const { return m_type; }
	std::wstring Data() const { return m_data; }

private:

	// type - a string denoting the CERT_ALT_NAME type - for CERT_ALT_NAME_OTHER_NAME type this is the objectID
	std::wstring m_type;
	std::wstring m_data;

};

typedef std::vector<CertAltNameEntry> VectorOfCertAltNameEntry;

} // namespace myid