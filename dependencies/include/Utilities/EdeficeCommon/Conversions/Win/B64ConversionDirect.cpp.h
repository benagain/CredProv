namespace myid
{

/// Convert from binary to a base 64 string
void base64(
	_In_ const myid::VectorOfByte& bin,	///< binary
	_Out_ _bstr_t& b64)					///< base 64 string
{
	size_t length = bin.size();
	if (length == 0)
	{
		b64 = L"";
		return;
	}

	BSTR sb64 = ::SysAllocStringByteLen(NULL, (UINT)((length + 2) / 3) * 8);

	::base64<wchar_t>(&bin[0], sb64, length);
	b64.Attach(sb64);
}

/// Convert from a base 64 string to binary
/// \return is valid base 64 string
OKBOOL base64(
	_In_ const _bstr_t& b64,				///< base 64 string
	_Out_ _Always_(_Post_valid_) myid::VectorOfByte& bin)		///< binary
{
	return ::base64<wchar_t>((wchar_t*)b64, b64.length(), false, bin);
}

}	// end namespace myid
