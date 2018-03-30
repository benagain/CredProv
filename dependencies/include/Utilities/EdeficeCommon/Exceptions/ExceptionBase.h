#pragma once

#include <string>
#include <exception>
#include "../SalFix.h"

namespace myid
{

/// Base exception class for MyID projects.  Intended as a easier-to-use
/// replacement for iComm0001::Exception
///
/// Simple usage: Derive and override constructMessage()
class Exception : public std::exception
{
public:
	Exception();
	// cppcheck-suppress noExplicitCopyMoveConstructor
	Exception(_In_ Exception const& rhs);

	virtual ~Exception() throw();

	const char* what() const throw();
	wchar_t const* message() const;

	virtual unsigned long getErrorNumber(void) const;
	virtual long getHRESULT(void) const;

protected:
	/**
	* Derived classes should override this to
	* provide their own formatting of exception
	* messages.
	*
	* This will only be called once per exception
	* thrown.
	*/
	virtual std::wstring buildMessage() const = 0;


private:
	mutable std::wstring mesg_;
	mutable std::string mesgn_;

	std::wstring const& exposeMessage() const;
};

}
