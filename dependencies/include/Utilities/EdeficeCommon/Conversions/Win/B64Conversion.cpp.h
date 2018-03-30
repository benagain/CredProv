#include <atlbase.h>
#include <comdef.h>

#include "Utilities\EdeficeCommon\Exceptions\LocalisedException.h"
#include "Utilities\EdeficeCommon\Conversions\HexBinVectorConversion.h"
#include "Utilities\DataExchange\ImportDataExchange.h"

namespace myid
{

//============================================================================================================
//============================================================================================================
// DataExchange

namespace
{

typedef DATAEXCHANGELib::IDataXBufferPtr XBuf;

/// Support for B64
inline XBuf DataX()
{
	XBuf buffer;
	if(FAILED(buffer.CreateInstance(__uuidof(DATAEXCHANGELib::DataXBuffer))))
		throw myid::LocalisedException(LOCALISE_FN_STATIC, L"DataExchange.DLL");
	return buffer;
}

} // anon namespace

/// Convert from B64 string to vector
VectorOfBytePtr fromBase64(const _bstr_t& b64)
{
	VectorOfBytePtr bytes(new VectorOfByte);
	fromBase64(b64, *bytes);
	return bytes;
}

/// Convert from B64 string to vector
VectorOfBytePtr fromBase64(const std::string& b64)
{
	VectorOfBytePtr bytes(new VectorOfByte);
	fromBase64(b64, *bytes);
	return bytes;
}

/// Convert from B64 string to vector
VectorOfBytePtr fromBase64(const std::wstring& b64)
{
	VectorOfBytePtr bytes(new VectorOfByte);
	fromBase64(b64, *bytes);
	return bytes;
}

/// Convert from B64 string to vector
void fromBase64(const _bstr_t& b64, VectorOfByte& bin)
{
	if (b64.length() == 0)
	{
		bin.clear();
	}
	else
	{
		XBuf buffer(DataX());

		buffer->WriteBase64(b64);
		myid::hex_2_bin(buffer->ReadHex(), bin);
	}
}

/// Convert from B64 string to vector
void fromBase64(const std::string& b64, VectorOfByte& bin)
{
	if (b64.empty())
	{
		bin.clear();
	}
	else
	{
		fromBase64(_bstr_t(b64.c_str()), bin);
	}
}

/// Convert from B64 string to vector
void fromBase64(const std::wstring& b64, VectorOfByte& bin)
{
	if (b64.empty())
	{
		bin.clear();
	}
	else
	{
		fromBase64(_bstr_t(b64.c_str()), bin);
	}
}

/// Convert from B64 string to hex string
void fromBase64(const std::wstring& b64, std::wstring& hex)
{
	if (b64.empty())
	{
		hex.clear();
	}
	else
	{
		XBuf buffer(DataX());

		buffer->WriteBase64(b64.c_str());
		hex = (wchar_t*)buffer->ReadHex();
	}
}

/// Convert from B64 hex string to vector
void fromBase64Hex(const std::wstring& hexb64, VectorOfByte& bin)
{
	if (hexb64.empty())
	{
		bin.clear();
	}
	else
	{
		XBuf buffer(DataX());

		buffer->WriteBase64Hex(hexb64.c_str());
		myid::hex_2_bin(buffer->ReadHex(), bin);
	}
}

/// Convert from B64 hex string to hex string
void fromBase64Hex(const std::wstring& hexb64, std::wstring& hex)
{
	if (hexb64.empty())
	{
		hex.clear();
	}
	else
	{
		XBuf buffer(DataX());

		buffer->WriteBase64Hex(hexb64.c_str());
		hex = (wchar_t*)buffer->ReadHex();
	}
}

/// Convert from vector to B64 string
std::string toBase64String(VectorOfByte const & bin)
{
	std::string str;
	toBase64(bin, str);
	return str;
}

/// Convert from vector to B64 string
std::wstring toBase64Wstr(VectorOfByte const & bin)
{
	std::wstring str;
	toBase64(bin, str);
	return str;
}

/// Convert from vector to B64 string
void toBase64(const VectorOfByte& bin, _bstr_t& b64)
{
	if (bin.empty())
	{
		b64 = L"";
	}
	else
	{
		XBuf buffer(DataX());

		_bstr_t binHex;
		myid::bin_2_hex(bin, binHex);
		buffer->WriteHex(binHex);

		BSTR _result = 0;
		HRESULT _hr = buffer->raw_ReadBase64(&_result);
		if (FAILED(_hr)) _com_issue_error(_hr);

		b64.Attach(_result);
	}
}

/// Convert from vector to B64 string
void toBase64(const VectorOfByte& bin, std::string& b64)
{
	if (bin.empty())
	{
		b64.clear();
	}
	else
	{
		XBuf buffer(DataX());

		_bstr_t binHex;
		myid::bin_2_hex(bin, binHex);
		buffer->WriteHex(binHex);

		b64 = (char*)buffer->ReadBase64();
	}
}

/// Convert from vector to B64 string
void toBase64(const VectorOfByte& bin, std::wstring& b64)
{
	if (bin.empty())
	{
		b64.clear();
	}
	else
	{
		XBuf buffer(DataX());

		_bstr_t binHex;
		myid::bin_2_hex(bin, binHex);
		buffer->WriteHex(binHex);

		b64 = (wchar_t*)buffer->ReadBase64();
	}
}

/// Convert from hex string to B64 string
void toBase64(const std::wstring& hex, std::wstring& b64)
{
	if (hex.empty())
	{
		b64.clear();
	}
	else
	{
		XBuf buffer(DataX());

		buffer->WriteHex(hex.c_str());
		b64 = (wchar_t*)buffer->ReadBase64();
	}
}

/// Convert from vector to B64 hex string
void toBase64Hex(const VectorOfByte& bin, std::wstring& hexb64)
{
	if (bin.empty())
	{
		hexb64.clear();
	}
	else
	{
		XBuf buffer(DataX());

		_bstr_t binHex;
		myid::bin_2_hex(bin, binHex);
		buffer->WriteHex(binHex);

		hexb64 = (wchar_t*)buffer->ReadBase64Hex();
	}
}

/// Test for base 64
bool isBase64(_In_ const _bstr_t& b64)
{
	return isBase64(myid::ToWstr(b64));
}

/// Remove white space and test if remainder is base 64
bool stripBase64WhiteSpace(_Inout_ _bstr_t& b64)
{
	std::wstring b = myid::ToWstr(b64);
	bool rtn = stripBase64WhiteSpace(b);
	b64 = myid::ToBstr(b);

	return rtn;
}

}	// end namespace myid
