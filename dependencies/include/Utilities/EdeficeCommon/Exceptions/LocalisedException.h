#pragma once

#include <typeinfo>
#include "ExceptionBase.h"
#include "StackDump.h"

#if defined ( _MSC_VER )
#define __FUNC__ __FUNCTION__
#elif defined (MYID_DEBUG)
#define __FUNC__ __PRETTY_FUNCTION__
#else
#define __FUNC__ __func__
#endif

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#define FUNCTION_NAME WIDEN(__FUNC__)
#define WSTRINGIZE(x) WIDEN(#x)
#define LOCALISE_CLASS myid::Localisation(*this, __FILE__, __LINE__)
#define LOCALISE_FN_(fn) myid::Localisation(*this, #fn, __FILE__, __LINE__)
#define LOCALISE_FN myid::Localisation(*this, __FUNC__, __FILE__, __LINE__)
#define LOCALISE_FN_STATIC_(fn) myid::Localisation(fn, __FILE__, __LINE__)
#define LOCALISE_FN_STATIC LOCALISE_FN_STATIC_(__FUNC__)
#define DECLARE_FUNCTION_NAME(name)

namespace myid
{
/// Provides the location of an exception
class Localisation
{
public:
	template<class T>
	Localisation(_In_ T const& throwingObject, _In_ std::string const& throwingFile, _In_ int throwingLine)
		: m_function(className(throwingObject))
		, m_file(fileName(throwingFile))
		, m_lineNumber(throwingLine)
	{}

	template<class T>
	Localisation(_In_ T const& throwingObject, _In_ std::wstring const& throwingFile, _In_ int throwingLine)
		: m_function(className(throwingObject))
		, m_file(myid::ToStr(fileName(throwingFile)))
		, m_lineNumber(throwingLine)
	{}

	template<class T>
	Localisation(_In_ T const& throwingObject, _In_ std::string const& throwingFunction, _In_ std::string const& throwingFile, _In_ int throwingLine)
		: m_function(functionName(throwingObject, throwingFunction))
		, m_file(fileName(throwingFile))
		, m_lineNumber(throwingLine)
	{}

	template<class T>
	Localisation(_In_ T const& throwingObject, _In_ std::wstring const& throwingFunction, _In_ std::wstring const& throwingFile, _In_ int throwingLine)
		: m_function(functionName(throwingObject, myid::ToStr(throwingFunction)))
		, m_file(myid::ToStr(fileName(throwingFile)))
		, m_lineNumber(throwingLine)
	{}

	Localisation();

	Localisation(_In_ std::string const& throwingFunction, _In_ std::string const& throwingFile, _In_ int throwingLine);
	Localisation(_In_ std::wstring const& throwingFunction, _In_ std::wstring const& throwingFile, _In_ int throwingLine);

	Localisation(_In_z_ char const* throwingFunction, _In_z_ char const* throwingFile, _In_ int throwingLine);
	Localisation(_In_z_ wchar_t const* throwingFunction, _In_z_ wchar_t const* throwingFile, _In_ int throwingLine);

	Localisation(_In_z_ char const* throwingFile, _In_ int throwingLine);
	Localisation(_In_z_ wchar_t const* throwingFile, _In_ int throwingLine);

	virtual ~Localisation();

	explicit Localisation(_In_ const Localisation& rhs);

	const std::string m_function;				///< name of the throwing function
	const std::string m_file;					///< filename of the throwing function
	int m_lineNumber;							///< line number in the throwing function

protected:
	template<class T>
	std::string className(_In_ T const&)
	{
		return std::string(&typeid(T).name()[6]);
	}

	template<class T>
	std::string functionName(_In_ T const& /*x*/, _In_ std::string const& function)
	{
		std::string classname(&typeid(T).name()[6]);
		classname.append("::");
		if (function.compare(0, classname.size(), classname) == 0)
			return function;				// function name already starts with class name
		return classname.append(function);
	}

	template<class T>
	std::wstring functionName(_In_ T const& /*x*/, _In_ std::wstring const& function)
	{
		std::wstring classname(&typeid(T).name()[6]);
		classname.append(L"::");
		if (function.compare(0, classname.size(), classname) == 0)
			return function;				// function name already starts with classname
		return classname.append(function);
	}

	std::string fileName(const std::string &path);
	std::wstring fileName(const std::wstring &path);

private:
	Localisation& operator=(_In_ const Localisation& rhs);
};

/// Basic exception with the location of the throw
class LocalisedException : public myid::Exception, virtual public myid::StackDump
{
public:
	LocalisedException();
	LocalisedException(_In_ std::wstring const& message);
	LocalisedException(_In_ std::string const& message);
	LocalisedException(_In_ Localisation const& location);
	LocalisedException(_In_ Localisation const& location, _In_ std::wstring const& message);
	LocalisedException(_In_ Localisation const& location, _In_ std::string const& message);
	virtual ~LocalisedException() throw();

protected:
	// derived classes may override this
	virtual std::wstring buildErrorMessage() const;

	// comment on not using this function
	virtual std::wstring buildMessage() const;
	std::wstring buildLocalisation() const;

	Localisation	m_location;						///< where the error occurred
	std::wstring	m_mesg;							///< error message
};
}
