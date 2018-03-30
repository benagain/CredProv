#pragma once
#include "Utilities/EdeficeCommon/SalFix.h"

namespace myid
{
	// BSTR with embedded null to/from vector, low order byte first
void BSTRToVector(_In_ const BSTR bstrInput, _Out_ VectorOfByte &vecOutput);
	VectorOfBytePtr BSTRToVector(_In_ const BSTR bstrInput);
	BSTR VectorToBSTR(_In_ const VectorOfByte &vecInput);

	// BSTR with embedded null to/from vector (high order bytes dumped)
	void AnsiBSTRToVector(_In_ const BSTR bstrInput, _Out_ VectorOfByte &vecOutput);
	BSTR VectorToAnsiBSTR(_In_ const VectorOfByte &vecInput);

	// truncated unicode to vector (high order bytes dumped)
	void bstrStringToVector(_In_ BSTR const & bstrInput, _Out_ VectorOfByte& vecOutput);
	VectorOfByte bstrStringToVector(_In_ BSTR const & bstrInput);

	// vector pair of bytes to/from BSTR with embedded null, high order byte first
	void VectorToUnicodeString(_In_ VectorOfByte const & vecInput, _Out_ BSTR& bstrOutput);
	void stdUnicodeStringToVector(_In_ const BSTR bstrInput, _Out_ VectorOfByte& vecOutput);
	VectorOfBytePtr stdUnicodeStringToVector(_In_ const BSTR bstrInput);

	myid::VectorOfByte ToVector(_In_opt_ SAFEARRAY* sarray);
	OKBOOL ToVector(_In_opt_ SAFEARRAY* sarray, _Out_ _Always_(_Post_valid_) VectorOfByte& vecOutput);
	myid::VectorOfByte ToVector(_In_ const VARIANT& variant);
	OKBOOL ToVector(_In_ const VARIANT& variant, _Out_ _Always_(_Post_valid_) VectorOfByte& vecOutput);

	SAFEARRAY* ToSafeArray(_In_ const VectorOfByte& vecInput);
	OKBOOL ToSafeArray(_In_ const VectorOfByte& vecInput, _Out_ _Always_(_Post_valid_) SAFEARRAY** sarray);
	VARIANT ToVariant(_In_ const VectorOfByte& vecInput);
	OKBOOL ToVariant(_In_ const VectorOfByte& vecInput, _Out_ _Always_(_Post_valid_) VARIANT* variant);
}

