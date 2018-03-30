#pragma once

#include "ExceptionBase.h"
#include "ComException.h"
#include "ExceptionHandlerStd.h"
#include "Utilities\EdeficeCommon\Conversions\StringUtils.h"
#include <comdef.h>

namespace myid
{

template<typename T, const CLSID* pclsid>
HRESULT reportError(ATL::CComCoClass<T, pclsid> & reporter)
{
	return myid::CoBoundaryExceptionHandler<T, pclsid>().reportError(reporter);
}

template<typename T, const CLSID* pclsid>
HRESULT reportError(ATL::CComCoClass<T, pclsid> & reporter, std::wstring const& functionName, bool bSuppressErrorOutput = false, HRESULT fnResult = E_FAIL)
{
	return myid::CoBoundaryExceptionHandler<T, pclsid>().reportError(reporter, functionName, bSuppressErrorOutput, fnResult);
}

template<typename T, const CLSID* pclsid>
HRESULT reportError(ATL::CComCoClass<T, pclsid> & reporter, std::string const& functionName, bool bSuppressErrorOutput = false, HRESULT fnResult = E_FAIL)
{
	std::wstring functionNameW = myid::ToWstr( functionName );
	return myid::CoBoundaryExceptionHandler<T, pclsid>().reportError(reporter, functionNameW, bSuppressErrorOutput, fnResult );
}


template<typename T, const CLSID* pclsid>
class CoBoundaryExceptionHandler
{
public:
	typedef ATL::CComCoClass<T, pclsid> CoClass;
	HRESULT reportError(CoClass& reporter)
	{
		return reportError(reporter, L"");
	}

	virtual HRESULT reportError(CoClass& reporter, std::wstring const& functionName, bool bSuppressErrorOutput = false, HRESULT fnResult = E_FAIL)
	{
		HRESULT hr = S_OK;
		std::wstring error;

		try
		{
			throw;
		}
		catch(myid::Exception& e)
		{
			error = reportException<myid::Exception>(e, hr);
		}
		catch( std::exception const& e )
		{
			error = reportException<std::exception>(e, hr);
		}
		catch (myid::ComException& e)
		{
			error = reportException<myid::ComException>(e, hr);
		}
		catch( _com_error& e )
		{
			error = reportException<_com_error>(e, hr);
		}
		catch( ... )
		{
			hr = E_FAIL;
			error = L"An unknown error occurred";
		}

		reportError(reporter, functionName, error, hr, bSuppressErrorOutput);

		// if output is being suppressed return the hresult that was passed in to reportError
		return bSuppressErrorOutput ? fnResult : hr;
	}

protected:
	typedef CoBoundaryExceptionHandler<T, pclsid> BaseType;

	virtual void reportError(CoClass& reporter, std::wstring const& functionName, std::wstring & message, HRESULT &hr, bool bSuppressErrorOutput)
	{
		std::wstring fullMessage = L"An error occurred inside ";
		if( functionName.empty() )
		{
			fullMessage += determineClassName();
			fullMessage += L"::";
		}
		else
		{
			fullMessage += functionName;
		}

		fullMessage += L"\n";
		fullMessage += message;

		message = fullMessage;

		// allow override to modify behaviour
		onReportError(reporter, functionName, message, hr);

		if (!bSuppressErrorOutput)
		{
			// The override may have changed the message, if it has then it wants that message to be passed onto IErrorInfo
			reporter.Error(message.c_str());
		}
	}

	virtual void onReportError(CoClass& /*reporter*/, std::wstring const& /*functionName*/, std::wstring & /*message*/, HRESULT &/*hr*/)
	{
		// override could modify message, log to logevents, etc... if required
	}

	std::wstring determineClassName() const
	{
		try
		{
			// As we are using ATL for the COM objects, the actual class name is buried in a load of templates
			// The name is the last class found in the complete string, e.g.
			// "class ATL::CComCoClass<class BioApiConnector,&struct _GUID const CLSID_BioApiConnector>"
			//                               ^ class name ^

			std::string atlClassName = typeid(CoClass).name();
			size_t classNameStart = atlClassName.rfind("class ") + 6;
			size_t classNameEnd = atlClassName.find(",", classNameStart);

			if((classNameStart == std::wstring::npos) || (classNameEnd == std::wstring::npos))
				return L"<unknown class>";

			std::string className = atlClassName.substr(classNameStart, classNameEnd - classNameStart);
			return myid::ToWstr(className);
		}
		catch(...)
		{
			// If anything goes wrong, we want to report the original error as it is in the context
			// of the application rather than the context of error reporting.
			return L"<unknown class>";
		}
	}
};

}

