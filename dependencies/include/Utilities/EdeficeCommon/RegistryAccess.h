#pragma once

#include <boost/shared_ptr.hpp>
#include "SalFix.h"

namespace eUtil
{

	namespace win32
	{

typedef boost::shared_ptr<class RegistryImpl> RegistryImplPtr;

class RegistryAccess
{
public:
	DWORD read(_In_ const std::wstring& identity, _Out_ bool& exists, _In_ DWORD defaultValue = 0, _In_ HKEY key = HKEY_LOCAL_MACHINE) const;

	std::wstring read(_In_ const std::wstring& identity, _Out_ bool& exists, _In_ const std::wstring& defaultValue = std::wstring(), _In_ HKEY key = HKEY_LOCAL_MACHINE) const;

	bool write(_In_ const std::wstring& subKey, _In_ const std::wstring& identity, _In_ const std::wstring& value, _In_ HKEY key = HKEY_LOCAL_MACHINE);

	static void ChangeAccessorObject(_In_ RegistryImplPtr newAccessor);
	static RegistryImplPtr GetAccessorObject()
	{
		return m_Registry;
	}
private:
	static RegistryImplPtr m_Registry;
};

template<typename T>
class RegistryAccessOverride
{
	boost::shared_ptr<T> m_Ptr;
	RegistryImplPtr m_PrevPtr;
public:
	RegistryAccessOverride()
	{
		m_Ptr.reset(new T);
		m_PrevPtr = RegistryAccess::GetAccessorObject();
		RegistryAccess::ChangeAccessorObject(m_Ptr);
	}
	~RegistryAccessOverride()
	{
		RegistryAccess::ChangeAccessorObject(m_PrevPtr);
	}
	T &operator*()
	{
		return *m_Ptr;
	}
	T* operator->()
	{
		return m_Ptr.get();
	}
};

class RegistryImpl
{
public:
	virtual DWORD read(_In_ const std::wstring& identity, _Out_ bool& exists, _In_ DWORD defaultValue = 0, _In_ HKEY key = HKEY_LOCAL_MACHINE) const = 0;

	virtual std::wstring read(_In_ const std::wstring& identity, _Out_ bool& exists, _In_ const std::wstring& defaultValue = std::wstring(), _In_ HKEY key = HKEY_LOCAL_MACHINE) const = 0;

	virtual bool write(_In_ const std::wstring& subKey, _In_ const std::wstring& identity, _In_ const std::wstring& value, _In_ HKEY key = HKEY_LOCAL_MACHINE) = 0;
};

	}
}