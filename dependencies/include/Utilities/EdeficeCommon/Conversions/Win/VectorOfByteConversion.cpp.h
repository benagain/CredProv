namespace myid
{

/// this function (as opposed to bstrStringToVector) works on BSTR's directly,
/// allowing conversion of strings that have embedded NULL's, by using the stored
/// length of the BSTR to determine the length, rather than casting to a wchar*, and determining
/// the length from that - which will generally stop at the first embedded NULL.
/// because BSTR is a unicode string, you can expect the output bytes to
/// be like 01 00 02 00 03 00 if the input string is "123".
/// \note The low order byte is put into the vector first, then the high order byte.
void BSTRToVector(
	_In_ const BSTR bstrInput,			///< a BSTR that may contain nulls
	_Out_ VectorOfByte &vecOutput)		///< output vector
{
	size_t length = bstrInput == NULL ? 0 : ::SysStringByteLen(bstrInput);
	if (0 == length)
	{
		vecOutput.resize(0);
	}
	else
	{
		vecOutput.resize(length);
		memcpy(&vecOutput[0], (byte*)bstrInput, length);

	}
}

VectorOfBytePtr BSTRToVector(_In_ const BSTR bstrInput)	///< a BSTR that may contain nulls
{
	VectorOfBytePtr bin(new VectorOfByte);
	BSTRToVector(bstrInput, *bin);
	return bin;
}

/// this function - the opposite of BSTRToVector allocates and outputs a raw BSTR
/// it is up to the calling function to free this BSTR. 
BSTR VectorToBSTR(_In_ const VectorOfByte &vecInput)
{
	size_t length = vecInput.size();
	BSTR bstrOut = ::SysAllocStringByteLen(NULL, static_cast<UINT>(length));
	if (length > 0)
		memcpy(bstrOut, &vecInput[0], length);

	return bstrOut;
}

/// Get a vector from the low order byte of a BSTR, high order bytes are dumped
void AnsiBSTRToVector(
	_In_ const BSTR bstrInput,			///< a BSTR that may contain nulls
	_Out_ VectorOfByte &vecOutput)		///< output vector
{
	size_t length = ::SysStringLen(bstrInput);
	if (length == 0)
	{
		vecOutput.resize(0);
	}
	else
	{
		vecOutput.resize(length);
		for (size_t nIndex = 0; nIndex < length; ++nIndex)
		{
			vecOutput[nIndex] = (byte)bstrInput[nIndex];
		}
	}
}

/// Generate a BSTR from a vector, high order byte is always 0
BSTR VectorToAnsiBSTR(_In_ const VectorOfByte &vecInput)
{
	const size_t length = vecInput.size();

	BSTR bstrOut = ::SysAllocStringLen(NULL, static_cast<UINT>(length));
	for (size_t nIndex = 0; nIndex < length; ++nIndex)
	{
		bstrOut[nIndex] = vecInput[nIndex];
	}
#pragma warning(suppress: 6011)
	bstrOut[length] = 0;

	return bstrOut;
}

/// Convert string to vector, unicode chars are probably approximated or converted to ?
void bstrStringToVector(
	_In_ BSTR const & bstrInput,
	_Out_ VectorOfByte& vecOutput)
{
	_bstr_t in(bstrInput);
	std::string strInput;
	if (in.length() > 0)
		strInput = (const char*)in;

	stdStringToVector(strInput, vecOutput);
}

/// Convert string to vector, unicode chars are truncated
/// to maintain backwards compatibility will truncate string, should embedded NULL be found
VectorOfByte bstrStringToVector(_In_ BSTR const & bstrInput)
{
	const wchar_t *pwszInput = (wchar_t*)bstrInput;
	if (!pwszInput)
		return VectorOfByte(0); //protect against potentially NULL BSTR's

	std::wstring wstrInput(pwszInput);
	size_t length = wstrInput.length();
	VectorOfByte vecOutput(length);
	for (size_t nIndex = 0; nIndex < length; ++nIndex)
	{
		vecOutput[nIndex] = (byte)wstrInput[nIndex];
	}
	return vecOutput;
}

/// Decode a vector stored as a UNICODE string.
/// This creates a detached BSTR that must be freed by the calling code.
/// Pairs of bytes make one unicode char, the first makes the high byte, the second the low byte
void VectorToUnicodeString(
	_In_ VectorOfByte const & vecInput,
	_Out_ BSTR& bstrOutput)
{
	size_t length = vecInput.size();
	if ((length & 1) != 0)
		throw myid::LocalisedException(LOCALISE_FN_STATIC, L"Vector has odd number of bytes");

	bstrOutput = ::SysAllocStringLen(NULL, static_cast<UINT>(length) / 2);

	if (length > 0)
	{
		const byte* in = &vecInput[0];
		wchar_t* out = &bstrOutput[0];
		for (size_t nIndex = 0; nIndex < length; nIndex += 2, in += 2, out++)
		{
#pragma warning(suppress: 6011)
			*out = (in[0] << 8) | in[1];
		}
		*out = '\0';
	}
}

/// Encode a UNICODE string to a vector, encoding 2 bytes per character.
/// The first makes the high byte, the second the low byte.
void stdUnicodeStringToVector(
	_In_ const BSTR bstrInput,
	_Out_ VectorOfByte& vecOutput)
{
	size_t length = bstrInput == NULL ? 0 : ::SysStringLen(bstrInput);
	if (0 == length)
	{
		vecOutput.resize(0);
	}
	else
	{
		vecOutput.resize(length * 2);

		const wchar_t* in = &bstrInput[0];
		byte* out = &vecOutput[0];
		for (size_t nIndex = 0; nIndex < length; nIndex++, out += 2, in++)
		{
			out[1] = static_cast<byte>(*in & 0xFF);
			out[0] = static_cast<byte>(*in >> 8);
		}
	}
}

/// Encode a UNICODE string to a vector, encoding 2 bytes per character.
/// The first makes the high byte, the second the low byte.
VectorOfBytePtr stdUnicodeStringToVector(_In_ const BSTR bstrInput)
{
	VectorOfBytePtr vecOutput(new VectorOfByte);
	stdUnicodeStringToVector(bstrInput, *vecOutput);
	return vecOutput;
}

/// in future improve further by defining version of VectorOfByte with custom allocator class which auto clears memory during every deallocation
OKBOOL SecureClear(_Inout_ VectorOfByte& data)
{
	if (data.empty())
		return false;

	SecureZeroMemory(&data[0], data.size());

	return true;
}

OKBOOL SecureClear(_Inout_bytecount_(length) void* first, _In_ size_t length)
{
	if ((first == nullptr) || (length == 0))
		return false;

	SecureZeroMemory(first, length);

	return true;
}

OKBOOL SecureClear(_Inout_ std::string& data)
{
	if (data.empty())
		return false;

	SecureZeroMemory(&data[0], data.size());

	return true;
}

OKBOOL SecureClear(_Inout_ std::wstring& data)
{
	if (data.empty())
		return false;

	SecureZeroMemory(&data[0], data.size() * sizeof(wchar_t));

	return true;
}

/// Extract from appropriate types of SAFEARRY
myid::VectorOfByte ToVector(_In_opt_ SAFEARRAY* sarray)
{
	myid::VectorOfByte rtn;
	ToVector(sarray, rtn);
	return rtn;
}

/// Extract from appropriate types of SAFEARRY
/// \return true if converted
OKBOOL ToVector(
	_In_opt_ SAFEARRAY* sarray,
	_Out_ _Always_(_Post_valid_) VectorOfByte& vecOutput)
{
	vecOutput.clear();

	if (sarray)
	{
		if (SafeArrayGetDim(sarray) == 1)
		{
			VARTYPE type(VT_EMPTY);
			if (SafeArrayGetVartype(sarray, &type) == S_OK)
			{
				if ((type == VT_UI1) || (type == VT_I1))
				{
					void* data(nullptr);
					if (SafeArrayAccessData(sarray, &data) == S_OK)
					{
						DWORD length = sarray->rgsabound[0].cElements;
						vecOutput.set((byte*)data, length);
						SafeArrayUnaccessData(sarray);
						return true;
					}
				}
			}
		}
	}

	return false;
}

/// Extract from appropriate types of VARIANT
myid::VectorOfByte ToVector(_In_ const VARIANT& variant)
{
	myid::VectorOfByte rtn;
	ToVector(variant, rtn);
	return rtn;
}

/// Extract from appropriate types of VARIANT
/// \return true if converted
OKBOOL ToVector(
	_In_ const VARIANT& variant,
	_Out_ _Always_(_Post_valid_) VectorOfByte& vecOutput)
{
	vecOutput.clear();
	if (variant.vt == VT_EMPTY)
		return true;

	if ((variant.vt != (VT_ARRAY | VT_UI1)) &&
		(variant.vt != (VT_ARRAY | VT_I1)))
		return false;

	return ToVector(variant.parray, vecOutput);
}

SAFEARRAY* ToSafeArray(_In_ const VectorOfByte& vecInput)
{
	SAFEARRAY* rtn;
	ToSafeArray(vecInput, &rtn);
	return rtn;
}

OKBOOL ToSafeArray(
	_In_ const VectorOfByte& vecInput,
	_Out_ _Always_(_Post_valid_) SAFEARRAY** sarray)
{
	if (sarray == nullptr)
		return false;

	unsigned long len = vecInput.lsize();
	*sarray = SafeArrayCreateVector(VT_UI1, 0, len);
	if (*sarray == nullptr)
		return false;

	if (len)
	{
		void* data(nullptr);
		if (SafeArrayAccessData(*sarray, &data) != S_OK)
			return false;

		memcpy(data, vecInput.ptr(), len);

		SafeArrayUnaccessData(*sarray);
	}

	return true;
}

VARIANT ToVariant(_In_ const VectorOfByte& vecInput)
{
	VARIANT rtn;
	ToVariant(vecInput, &rtn);
	return rtn;
}

OKBOOL ToVariant(
	_In_ const VectorOfByte& vecInput,
	_Out_ _Always_(_Post_valid_) VARIANT* variant)
{
	if (vecInput.empty())
	{
		VariantInit(variant);
		return true;
	}

	variant->vt = VT_ARRAY | VT_UI1;
	return ToSafeArray(vecInput, &variant->parray);
}

}	// end namespace myid
