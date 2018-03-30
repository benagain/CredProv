namespace myid
{

std::wstring bin_4_hex(_In_ const BSTR bstrIn)
{
	std::wstring wstrOutput;
	bin_4_hex(bstrIn, wstrOutput);
	return wstrOutput;
}

void bin_2_hex(_In_ VectorOfByte const & vecBin, _Out_ _bstr_t& bstrOutput)
{
	size_t length = vecBin.size();
	ATL::CComBSTR output(static_cast<int>(length * 2));
	if (length)
		bin_2_hex(length, &vecBin[0], (BSTR)output);

	bstrOutput.Attach(output.Detach());
}

/// Convert a BSTR to a hex string. Each input char will make 4 hex chars
void bin_4_hex(_In_ const BSTR bstrIn, _Out_ std::wstring& wstrOutput)
{
	ATL::CComBSTR input(L"");
#pragma warning(suppress: 6031)
	input.AppendBSTR(bstrIn);
	size_t length = input.Length();

	wstrOutput.assign(length * 4, '\0');
	if (length)
		bin_4_hex(length, (BSTR)input, &wstrOutput[0]);
}

/// Convert a BSTR to a hex string. Each input char will make 4 hex chars
void bin_4_hex(_In_ const BSTR bstrIn, _Out_ _bstr_t& bstrOutput)
{
	ATL::CComBSTR input(L"");
#pragma warning(suppress: 6031)
	input.AppendBSTR(bstrIn);
	size_t length = input.Length();
	if (length)
	{
		ATL::CComBSTR output(static_cast<int>(length * 4));
		bin_4_hex(length, (BSTR)input, (BSTR)output);
		bstrOutput.Attach(output.Detach());
	}
	else
	{
		bstrOutput = L"";
	}
}

/// Convert 2 hex bytes to vector
VectorOfBytePtr hex_2_bin(_In_ const BSTR bstrHex)
{
	VectorOfBytePtr vecResult(new VectorOfByte);
	hex_2_bin(bstrHex, *vecResult);
	return vecResult;
}

/// Convert 2 hex bytes to vector
VectorOfBytePtr hex_2_bin(_In_ const _bstr_t& bstrHex)
{
	VectorOfBytePtr vecResult(new VectorOfByte);
	hex_2_bin(bstrHex, *vecResult);
	return vecResult;
}

/// Convert 2 hex bytes to vector
VectorOfBytePtr hex_2_bin(_In_ const ATL::CComBSTR& bstrHex)
{
	VectorOfBytePtr vecResult(new VectorOfByte);
	hex_2_bin(bstrHex, *vecResult);
	return vecResult;
}

/// Convert 4 hex bytes to unicode string
_bstr_t hex_4_bin(_In_ const _bstr_t& bstrHex)
{
	size_t length = bstrHex.length();
	if (length)
	{
		ATL::CComBSTR output(static_cast<int>(length / 4));
		const wchar_t* in = bstrHex;
		wchar_t* out = &output[0];
		hex_4_bin(length, in, out);
		return _bstr_t(output.Detach(), false);
	}
	return L"";
}

/// Convert 2 hex bytes to vector
void hex_2_bin(_In_ const BSTR bstrHex, _Out_ VectorOfByte& vecOut)
{
	ATL::CComBSTR input(L"");
#pragma warning(suppress: 6031)
	input.AppendBSTR(bstrHex);
	hex_2_bin(input, vecOut);
}

/// Convert 2 hex bytes to vector
void hex_2_bin(_In_ const _bstr_t& bstrHex, _Out_ VectorOfByte& vecOut)
{
	size_t length = bstrHex.length();
	vecOut.resize(length / 2);
	if (length > 1)
		hex_2_bin(length, bstrHex, &vecOut[0]);
}

/// Convert 2 hex bytes to vector
void hex_2_bin(_In_ const ATL::CComBSTR& bstrHex, _Out_ VectorOfByte& vecOut)
{
	size_t length = bstrHex.Length();
	vecOut.resize(length / 2);
	if (length > 1)
		hex_2_bin(length, &bstrHex[0], &vecOut[0]);
}

}	// end namespace myid
