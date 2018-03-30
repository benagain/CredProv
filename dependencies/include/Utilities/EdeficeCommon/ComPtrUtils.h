#pragma once

#include <string>
#include <sstream>
#include <exception>
#include <atlbase.h>

#include "./Conversions/StringUtils.h"
#include "./Exceptions/ErrorException.h"

namespace eCom
{

/// Interface for error handling when using CreateComPtrEx
class CreateComPtrErrorHandler
{
public:
	virtual ~CreateComPtrErrorHandler() {}
	virtual void creationError(_In_ long error) = 0;
};

/// Standard error handler for CreateComPtrEx
class CreateComPtrStandardErrorHandler : public CreateComPtrErrorHandler
{
public:
	explicit CreateComPtrStandardErrorHandler(_In_z_ wchar_t const * className)
		: m_className(className)
	{}

	virtual void creationError(_In_ long error)
	{
		std::stringstream err;
		err << "Failed to instantiate " << myid::ToStr(m_className) << ".  Error " << std::hex << error;
		throw std::runtime_error(err.str());
	}

protected:
	wchar_t const * m_className;
};

class CreateComPtrErrorExceptionErrorHandler : public CreateComPtrErrorHandler
{
public:
	explicit CreateComPtrErrorExceptionErrorHandler(_In_z_ wchar_t const * className)
		: m_className(className)
	{}

	virtual void creationError(_In_ long error)
	{
		std::wstringstream err;
		err << "Failed to instantiate " << m_className << ".  Error " << std::hex << error;

		throw myid::ErrorException(error, err.str());
	}

protected:
	wchar_t const * m_className;
};

/**
 * Instantiate a COM object of the type specified using the class
 * name string specified.  Will throw the exception object given
 * if the instantiation fails.
 */
template< class ComType >
ComType CreateComPtr(_In_z_ wchar_t const * className, _In_ CreateComPtrErrorHandler& errorHandler)
{
	ComType ptr;
	HRESULT hr = ptr.CreateInstance(const_cast<wchar_t*>(className));
	if (FAILED(hr))
		errorHandler.creationError(hr);

	return ptr;
}


/**
 * Instantiate a COM object of the type specified using the class
 * name string specified.  Will throw a general runtime_error if
 * the instantiation fails
 */
template< class ComType >
ComType CreateComPtr(wchar_t const * className)
{
	CreateComPtrStandardErrorHandler errorHandler(className);
	return CreateComPtr<ComType>(const_cast<wchar_t*>(className), errorHandler);
}

template<class ComType>
ComType CreateComPtr(const struct _GUID& clsid, CreateComPtrErrorHandler& errorHandler)
{
	ComType ptr;
	HRESULT hr = ptr.CreateInstance(clsid);
	if (FAILED(hr))
		errorHandler.creationError(hr);

	return ptr;
}

template<class ComType>
ComType CreateComPtr(const struct _GUID& clsid, wchar_t const * className)
{
	CreateComPtrStandardErrorHandler errorHandler(className);
	return CreateComPtr<ComType>(clsid, errorHandler);
}

class AutoComInit
{
public:
	explicit AutoComInit(COINIT init = COINIT_MULTITHREADED)
	{
#pragma warning(suppress: 6031)
		CoInitializeEx(NULL, init);
	}
	~AutoComInit()
	{
		CoUninitialize();
	}
};

}
