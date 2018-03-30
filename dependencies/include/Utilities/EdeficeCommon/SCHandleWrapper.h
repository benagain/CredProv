#pragma once

#include <WinSvc.h>

// DEPRECATED use SmartHandle.h, class ServiceHandle

// Generic SC_HANDLE wrapper that uses CloseServiceHandle for closing.
class SCHandleWrapper
{
public:
	SCHandleWrapper() : m_hHandle(NULL)
	{
	}

	explicit SCHandleWrapper(SC_HANDLE hIn) : m_hHandle(hIn)
	{
	}

	~SCHandleWrapper(void)
	{
		if (m_hHandle != NULL)
		{
			CloseServiceHandle(m_hHandle);
			m_hHandle = NULL;
		}
	}

	operator SC_HANDLE() { return m_hHandle;}

#ifdef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	operator bool(void) const { return m_hHandle != NULL; }
#else
	explicit operator bool(void) const { return m_hHandle != NULL; }
#endif

protected:
	SC_HANDLE m_hHandle;
};
