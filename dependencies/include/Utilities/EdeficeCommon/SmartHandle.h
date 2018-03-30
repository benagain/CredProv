#pragma once
#include <boost/noncopyable.hpp>
#include "LeanWindows.h"

namespace myid
{

// Note: the unset value is NULL and not INVALID_HANDLE_VALUE - study MSDN carefully for why
// some handles are ULONG_PTR, which require NULL and not nullptr

template <typename H, class D, H V=NULL>
class SmartHandle : private boost::noncopyable
{
public:
	SmartHandle()
		: m_handle(V)
	{}

	explicit SmartHandle(_In_ const H& rhs)
		: m_handle(rhs)
	{}

	explicit SmartHandle(_Inout_ SmartHandle&& rhs)
		: m_handle(rhs.m_handle)
	{
		rhs.m_handle = V;
	}

	virtual ~SmartHandle()
	{
		close();
	}

	virtual void close()
	{
		if (valid())
		{
			DWORD error = GetLastError();
			m_delete(m_handle);
			SetLastError(error);
			m_handle = V;
		}
	}

	SmartHandle& operator=(_In_ const H& rhs)
	{
		if (m_handle != rhs)
		{
			close();
			m_handle = rhs;
		}

		return *this;
	}

	SmartHandle& operator=(_Inout_ SmartHandle&& rhs)
	{
		if (this != &rhs)
		{
			if (m_handle != rhs.m_handle)
			{
				close();
				m_handle = rhs.m_handle;
			}
			rhs.m_handle = V;
		}

		return *this;
	}

	bool operator!() const
	{
		return !valid();
	}

	operator H()
	{
		return m_handle;
	}

	operator const H() const
	{
		return m_handle;
	}

	operator H*()
	{
		return &m_handle;
	}

	H* operator&()
	{
		return &m_handle;
	}

#ifndef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	explicit
#endif
		operator bool() const
	{
		return valid();
	}

	bool valid(void) const
	{
		return (m_handle != V);
	}

	const H& get(void) const
	{
		return m_handle;
	}

	H& get(void)
	{
		return m_handle;
	}

protected:
	H m_handle;		///< handle of some kind
	D m_delete;		///< deleter
};

namespace deleter
{

struct HANDLE_Deleter
{
	void operator()(_In_ ::HANDLE handle) const
	{
		::CloseHandle(handle);
	}
};

struct FILEHANDLE_Deleter
{
	void operator()(_In_ ::HANDLE handle) const
	{
		::FindClose(handle);
	}
};

struct HKEY_Deleter
{
	void operator()(_In_ ::HKEY handle) const
	{
		::RegCloseKey(handle);
	}
};

struct SC_HANDLE_Deleter
{
	void operator()(_In_ ::SC_HANDLE handle) const
	{
		if (handle != nullptr)
		{
			CloseServiceHandle(handle);
		}
	}
};

}

// smart handles
typedef SmartHandle<::HANDLE, deleter::HANDLE_Deleter, nullptr> Handle;
typedef SmartHandle<::HANDLE, deleter::FILEHANDLE_Deleter, nullptr> FileHandle;
typedef SmartHandle<::HKEY, deleter::HKEY_Deleter, nullptr> RegHandle;
typedef SmartHandle<::SC_HANDLE, deleter::SC_HANDLE_Deleter, nullptr> ServiceHandle;

} // namespace myid
