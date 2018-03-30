#pragma once

namespace TestAbstractKeys
{
	enum EHSMType
	{
		eUnknown,
		eLuna,
		eNCipher,
		eSoftware		// Software only test using SoftwareKeyFactory
	};

	/// Convert the HSM enum into a string
	std::wstring GetHSMType(const EHSMType& hsm)
	{
		switch (hsm)
		{
		case eLuna:
			return L"LunaSA";
		case eNCipher:
			return L"nCipher";
		case eSoftware:
			return L"SoftCrypto";
		case eUnknown:
		default:
			return L"Unknown";
		}
	}
}