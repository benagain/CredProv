#pragma once

// WARNING do not use
// This has a serious design flaw, it uses INVALID_HANDLE_VALUE as a default value
// Use SmartHandle.h instead

#include <boost/noncopyable.hpp>

// Policy class for closing a handle
class CloseHandleFn
{
public:
	static void Close(HANDLE h)
	{
		CloseHandle(h);
	}
};

// Policy class for closing a file handle
class CloseFileHandleFn
{
public:
	static void Close(HANDLE h)
	{
		FindClose(h);
	}
};

// Policy class for closing a registry key
class CloseRegKeyHandleFn
{
public:
	static void Close(HKEY h)
	{
		RegCloseKey(h);
	}
};

// Policy class for initialisation of a handle
class HandleInit
{
public:
	static void Default(_Out_ HANDLE& h)
	{
		h = INVALID_HANDLE_VALUE;
	}

	static bool IsSet(_In_ HANDLE h)
	{
		return h != INVALID_HANDLE_VALUE;
	}
};

// Policy class for initialisation of a HKEY
class RegKeyInit
{
public:
	static void Default(_Out_ HKEY & h)
	{
		h = nullptr;
	}

	static bool IsSet(_In_ HKEY h)
	{
		return h != nullptr;
	}
};


// generic handle type wrapper
// initialised and checked for being set by the Initialisation policy class
// freed by the Closer policy class
// - HANDLE_TYPE is the type of handle
// - Initialisation is a policy class for setting the default value and testing to see if the HANDLE_TYPE is set
// - Closer is a policy class for releasing the HANDLE_TYPE
template< typename HANDLE_TYPE, typename Initialisation, typename Closer>
class CHandleTypeWrapperBase : private boost::noncopyable
{
public:
	CHandleTypeWrapperBase()
	{
		Initialisation::Default(m_hHandle);
	}

	explicit CHandleTypeWrapperBase(_In_ HANDLE_TYPE hIn)
		: m_hHandle(hIn)
	{}

	~CHandleTypeWrapperBase(void)
	{
		if (Initialisation::IsSet(m_hHandle))
		{
			Closer::Close(m_hHandle);
			Initialisation::Default(m_hHandle);
		}
	}

	operator HANDLE_TYPE() { return m_hHandle; }
	HANDLE_TYPE * operator& () { return &m_hHandle; }

#ifdef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
	operator bool() { return Initialisation::IsSet( m_hHandle); }
#else
	explicit operator bool() { return Initialisation::IsSet(m_hHandle); }
#endif

protected:

	HANDLE_TYPE m_hHandle;
};


// template specialisation of the CHandleTypeWrapperBase class for HANDLEs
template < typename Closer >
class CHandleWrapperBase : public CHandleTypeWrapperBase<HANDLE, HandleInit, Closer>
{
public:
	CHandleWrapperBase() : CHandleTypeWrapperBase()
	{}

	explicit CHandleWrapperBase(HANDLE hIn) : CHandleTypeWrapperBase(hIn)
	{}
};

// Generic handle wrapper
typedef CHandleWrapperBase< CloseHandleFn > CHandleWrapper;

// Handle wrapper for file handles, i.e. returns from FindFirstFile etc.
typedef CHandleWrapperBase< CloseFileHandleFn > CFileHandleWrapper;

// Handle wrapper for registry HKEYs
typedef CHandleTypeWrapperBase<HKEY, RegKeyInit, CloseRegKeyHandleFn> CRegKeyHandleWrapper;