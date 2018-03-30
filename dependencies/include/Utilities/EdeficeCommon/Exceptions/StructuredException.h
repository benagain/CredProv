#pragma once

#include "ExceptionBase.h"

typedef struct _EXCEPTION_POINTERS EXCEPTION_POINTERS;

namespace myid
{
namespace win32
{

/// Translates a Windows Structured Exception into a standard C++ exception
class StructuredException : public myid::Exception
{
	typedef myid::Exception inherited;

public:
	class Translator;

	unsigned int code() const;
	std::wstring address() const;

protected:
	const unsigned int m_code;
	const std::wstring m_message;
	const std::wstring m_address;

	StructuredException(_In_ unsigned int code, _In_ EXCEPTION_POINTERS *pPointers);

	virtual std::wstring buildMessage() const;

	friend class Translator;

	StructuredException& operator=(_In_ StructuredException const&); // not implemented
};

/// Helper to activate the Structured Exception
/// \note In order to report structured exception properly, this code needs to be added to StdAfx.cpp
/** \code{.cpp}
#include "Utilities\\EdeficeCommon\\Exceptions\\StructuredException.h"
myid::win32::StructuredException::Translator setr;
\endcode */
class StructuredException::Translator
{
public:
	Translator();
	~Translator();

private:
	static void exceptionTranslator(_In_ unsigned int code, _In_ EXCEPTION_POINTERS *pPointers);
	static StructuredException makeException(_In_ unsigned int code, _In_ EXCEPTION_POINTERS* pointers);

	_se_translator_function m_originalHandler;
};

} // namespace win32
} // namespace myid
