#pragma once

#include <comdef.h>
#include "../SalFix.h"
#include "StackDump.h"

namespace myid
{

/// This exception derives from_com_error, and adds a stack trace
class ComException : public _com_error, virtual public myid::StackDump
{
	typedef _com_error inherited;

public:
	ComException(_In_ HRESULT hr, _In_ IErrorInfo* perrinfo = NULL, _In_ bool fAddRef = false) throw();
	ComException(_In_ const ComException& rhs) throw();

	ComException& operator=(_In_ const ComException& rhs) throw();

	static void SetComException(void);
	static void __stdcall ErrorHandler(_In_ HRESULT hr, _In_ IErrorInfo* perrinfo);
};

}
