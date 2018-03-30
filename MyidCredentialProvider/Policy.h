#pragma once

namespace Data
{

/// Group policy settings
class Policy
{
public:
	Policy() = default;
	Policy(const Policy&) = delete;
	Policy& operator=(const Policy&) = delete;

	bool AllowCertificatesWithNoEKU(void) const;
	bool EnumerateECCCerts(void) const;
	bool AllowSignatureOnlyKeys(void) const;
	bool AllowTimeInvalidCertificates(void) const;
	bool FilterDuplicateCerts(void) const;
	bool ForceReadingAllCertificates(void) const;
	bool ReverseSubject(void) const;
	bool X509HintsNeeded(void) const;

	static Policy& Get(void);

private:
	bool m_AllowCertificatesWithNoEKU{false};
	bool m_EnumerateECCCerts{false};
	bool m_AllowSignatureOnlyKeys{false};
	bool m_AllowTimeInvalidCertificates{false};
	bool m_FilterDuplicateCerts{true};
	bool m_ForceReadingAllCertificates{false};
	bool m_ReverseSubject{true};
	bool m_X509HintsNeeded{false};
};

} // namespace Authenticate
