#pragma once

#include <sstream>
#include <iomanip>

#include "ExceptionHandler.h"
#include "ComException.h"
#include "ExceptionBase.h"
#include "Utilities/EdeficeCommon/Conversions/StringUtils.h"

namespace myid
{
	inline std::wstring ExceptionReporterCatchAllCommon()
	{
		myid::ExceptionReporterCatchAll reporter;
		reporter
			.then< myid::Exception >()
			.then< std::exception >()
			.then< myid::ComException >()
			.then< _com_error >();
		return reporter.report();
	}

	inline std::wstring ExceptionReporterCatchAllCommon(HRESULT& hr)
	{
		myid::ExceptionReporterCatchAll reporter;
		reporter
			.then< myid::Exception >()
			.then< std::exception >()
			.then< myid::ComException >()
			.then< _com_error >();
		return reporter.report(hr);
	}

	template<>
	inline std::wstring reportException<std::exception>(const std::exception& ex)
	{
		return myid::ToWstr(ex.what());
	}

	template<>
	inline std::wstring reportException<std::exception>(const std::exception& ex, HRESULT& hr)
	{
		hr = E_FAIL;
		return reportException(ex);
	}

	template<>
	inline std::wstring reportException<myid::Exception>(const myid::Exception& ex)
	{
		return ex.message();
	}

	template<>
	inline std::wstring reportException<myid::Exception>(const myid::Exception& ex, HRESULT& hr)
	{
		hr = ex.getHRESULT();
		return reportException(ex);
	}

	template<>
	inline std::wstring reportException<_com_error>(const _com_error& ex)
	{
		std::wstringstream message;
		message << L"Error: 0x" << std::hex << std::setw(8) << std::setfill(L'0') << ex.Error() << L" ";

		const _bstr_t& erMsg = ex.ErrorMessage();
		if (erMsg.length() != 0)
			message << erMsg << std::endl;

		const _bstr_t& desc = ex.Description();
		if (desc.length() != 0)
		{
			message << desc;
			if (((const wchar_t*)desc)[desc.length()-1] != '\n')
				message << std::endl;
		}

		const _bstr_t& source = ex.Source();
		if (source.length() != 0)
		{
			message << L"In object " << source << std::endl;
		}

		return message.str();
	}

	template<>
	inline std::wstring reportException<_com_error>(const _com_error& ex, HRESULT& hr)
	{
		hr = ex.Error();
		return reportException(ex);
	}

	template<>
	inline std::wstring reportException<myid::ComException>(const myid::ComException& ex)
	{
		std::wstring err = reportException<_com_error>(ex);

#ifdef MYID_DEBUG
		const wchar_t* st = ex.GetStackTrace();
		if (st && *st)
		{
			err += st;
		}
#endif

		return err;
	}

	template<>
	inline std::wstring reportException<myid::ComException>(const myid::ComException& ex, HRESULT& hr)
	{
		hr = ex.Error();
		return reportException(ex);
	}
}
