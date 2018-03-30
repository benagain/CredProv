#include "stdafx.h"
#include "VscPinPolicy.h"

namespace MyID_Vsc
{

PinPolicy::PinPolicy()
{
	Reset();
}

/// Reset policy data to defaults
void PinPolicy::Reset(void)
{
	SecureZeroMemory(this, sizeof(PinPolicy_Data));

	m_version = VSC_PIN_POLICY_CURRENT_VERSION;
	m_minLength = 8;
	m_maxLength = 32;

	m_policy[UpperCase] = PinPolicyOption::Allow;
	m_policy[LowerCase] = PinPolicyOption::Allow;
	m_policy[Digits] = PinPolicyOption::Allow;
	m_policy[Special] = PinPolicyOption::Allow;
	m_policy[NonPrintable] = PinPolicyOption::Disallow;

	m_modified = true;
}

/// Get Pin policy
void PinPolicy::Get(_Out_ VectorOfByte& policy) const
{
	policy.set(this, sizeof(PinPolicy_Data));
}

/// Set the Pin policy
bool PinPolicy::Set(_In_ const VectorOfByte& policy)
{
	// check smallest data
	if (policy.size() < sizeof(PinPolicy_Data_1))
		return false;

	// determine version
	const PinPolicy_Data_1* data1 = reinterpret_cast<const PinPolicy_Data_1*>(policy.ptr());
	if ((data1->m_version != 0) &&
		(data1->m_version != VSC_PIN_POLICY_CURRENT_VERSION) )
		return false;

	// check current version
	if (policy.size() != sizeof(PinPolicy_Data))
		return false;

	policy.get(this, sizeof(PinPolicy_Data));
	m_version = VSC_PIN_POLICY_CURRENT_VERSION;
	m_modified = true;
	return true;
}

/// Set the policy from elements
bool PinPolicy::Set(
	_In_ LONG minLength,				///< minimum PIN length
	_In_ LONG maxLength,				///< maximum PIN length
	_In_ const std::wstring& allowed)	///< allowed definition, length 5, contains ARD (Allow, Required, Disallow) for (upper case, lower case, digits, special, non printable)
{
	if (allowed.size() != NumPinPolicy)
		return false;
	if (allowed.find_first_not_of(L"ARD") != std::wstring::npos)
		return false;

	PinPolicy_Data policy;
	policy.m_version = VSC_PIN_POLICY_CURRENT_VERSION;
	policy.m_minLength = minLength;
	policy.m_maxLength = maxLength;

	for (int p = 0; p < NumPinPolicy; ++p)
	{
		switch (allowed[p])
		{
		case 'A':
			policy.m_policy[p] = PinPolicyOption::Allow;
			break;
		case 'R':
			policy.m_policy[p] = PinPolicyOption::Required;
			break;
		case 'D':
			policy.m_policy[p] = PinPolicyOption::Disallow;
			break;
		}
	}

	if (!Check(policy))
		return false;

	PinPolicy_Data::operator=(policy);
	m_modified = true;

	return true;
}

/// Check a pin matches policy data
bool PinPolicy::ValidatePin(_In_ const VectorOfByte& pin) const
{
	if ((pin.lsize() < m_minLength) ||
		(pin.lsize() > m_maxLength) )
		return false;

	static PinPolicySelection policy[256] = 
	{
		NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable,
		NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Digits, Digits, Digits, Digits, Digits, Digits, Digits, Digits, Digits, Digits, Special, Special, Special, Special, Special, Special,
		Special, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase,
		UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, UpperCase, Special, Special, Special, Special, Special,
		Special, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase,
		LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, LowerCase, Special, Special, Special, Special, NonPrintable,
		NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable,
		NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable, NonPrintable,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
		Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special, Special,
	};

	bool foundPolicy[NumPinPolicy] {};
	for (const auto p : pin)
	{
		foundPolicy[policy[p]] = true;
	}

	for (int p = 0; p < NumPinPolicy; ++p)
	{
		switch (m_policy[p])
		{
		case PinPolicyOption::Required:
			if (!foundPolicy[p])
				return false;
			break;
		case PinPolicyOption::Disallow:
			if (foundPolicy[p])
				return false;
			break;
		}
	}

	return true;
}

/// Validate supplied policy version
bool PinPolicy::CheckVersion(_In_reads_bytes_(cbDataLen) PBYTE pbData, _In_ DWORD cbDataLen)
{
	if ((cbDataLen < sizeof(PinPolicy_Data_1)) ||
		(cbDataLen > sizeof(PinPolicy_Data)) )
		return false;

	PinPolicy_Data_1* policy = reinterpret_cast<PinPolicy_Data_1*>(pbData);
	return CheckVersion(*policy);
}

/// Validate supplied policy
bool PinPolicy::Check(_In_reads_bytes_(cbDataLen) PBYTE pbData, _In_ DWORD cbDataLen)
{
	if (cbDataLen != sizeof(PinPolicy_Data_1))
		return false;

	PinPolicy_Data_1* policy = reinterpret_cast<PinPolicy_Data_1*>(pbData);
	return Check(*policy);
}


/// Validate supplied policy version
bool PinPolicy::CheckVersion(_In_ const PinPolicy_Data_1& policy)
{
	return (policy.m_version == 0) ||
		(policy.m_version <= VSC_PIN_POLICY_CURRENT_VERSION);
}


/// Check the policy data is valid
bool PinPolicy::Check(_In_ const PinPolicy_Data_1& policy)
{
	if ((policy.m_minLength < VSC_MIN_PIN_LENGTH) || (policy.m_minLength > VSC_MAX_PIN_LENGTH))
		return false;
	if ((policy.m_maxLength < VSC_MIN_PIN_LENGTH) || (policy.m_maxLength > VSC_MAX_PIN_LENGTH))
		return false;
	if (policy.m_minLength > policy.m_maxLength)
		return false;

	for (const auto& p : policy.m_policy)
	{
		switch (p)
		{
		case PinPolicyOption::Allow:
		case PinPolicyOption::Disallow:
		case PinPolicyOption::Required:
			break;
		default:
			return false;
		}
	}

	if ((policy.m_policy[UpperCase] == PinPolicyOption::Disallow) &&
		(policy.m_policy[LowerCase] == PinPolicyOption::Disallow) &&
		(policy.m_policy[Digits] == PinPolicyOption::Disallow) &&
		(policy.m_policy[Special] == PinPolicyOption::Disallow))
		return false;

	return true;
}

bool PinPolicy::Modified(void) const
{
	return m_modified;
}

void PinPolicy::Modified(bool modified)
{
	m_modified = modified;
}

} // namespace MyID_Vsc
