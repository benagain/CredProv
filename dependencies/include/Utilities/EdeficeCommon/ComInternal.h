#pragma once

#include <atlcomcli.h>

namespace myid
{

/// Provide basic reference counting
/** \note Example implementaion
/verbatim
	class CliVersionInternal
	: public myid::IDispatchInternal<CliVersionImpl>
/endverbatim 
Example usage
/verbatim
	CliVersionInternal* object = new CliVersionInternal();
	ClientVersionLib::ICliVersionPtr ptr;
	object->QueryInterface(IID_PPV_ARGS(&ptr));
/endverbatim */
template<class T>
class IUnknownInternal
	: public T
{
public:
	IUnknownInternal()
		: m_ref(1)
	{}

	IFACEMETHOD(QueryInterface)(REFIID riid, void** ppv) = 0;
	// Example implementation of QueryInterface(
	//IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv)
	//{
	//	static const QITAB qit[] =
	//	{
	//		QITABENT(CliVersionInternal, ICliVersion),
	//		QITABENT(CliVersionInternal, ISupportErrorInfo),
	//		{0},
	//	};
	//	return QISearch(this, qit, riid, ppv);
	//}

	IFACEMETHOD_(ULONG, AddRef)()
	{
		return InterlockedIncrement(&m_ref);
	}

	IFACEMETHOD_(ULONG, Release)()
	{
		long ref = InterlockedDecrement(&m_ref);
		if (!ref)
			delete this;
		return ref;
	}

protected:
	virtual ~IUnknownInternal() {}

private:
	long m_ref;			///< COM reference counter
};

/// This does not provide a valid implementation, only methods to allow linking
template<class T>
class IDispatchInternal
	: public IUnknownInternal<T>
{
public:
	IFACEMETHOD(GetTypeInfoCount)(unsigned int* pctinfo)
	{ 
		if (pctinfo == NULL) 
			return E_POINTER; 
		*pctinfo = 1; 
		return S_OK;
	}

	IFACEMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**)
	{
		return E_NOTIMPL;
	}

	IFACEMETHOD(GetIDsOfNames)(REFIID, _In_count_(cNames) LPOLESTR*, unsigned int cNames, LCID, DISPID*)
	{
		UNREFERENCED_PARAMETER(cNames);

		return E_NOTIMPL;
	}

	IFACEMETHOD(Invoke)(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*)
	{
		return E_NOTIMPL;
	}

protected:
	virtual ~IDispatchInternal() {}
};

/// A smart COM pointer to an Internal object
/// The object is created by the default constructor
template <class T>
class InternalPtr
	: public ATL::CComPtr<T>
{
public:
	InternalPtr() throw()
	{
		Attach(new T());
	}

	InternalPtr(_Inout_opt_ T* lp) throw()
		: ATL::CComPtr<T>(lp)
	{}

	InternalPtr(_Inout_ const InternalPtr<T>& lp) throw()
		: ATL::CComPtr<T>(lp.p)
	{}

	T* operator=(_Inout_opt_ T* lp) throw()
	{
		return ATL::CComPtr<T>::operator=(lp);
	}

	T* operator=(_Inout_ const InternalPtr<T>& lp) throw()
	{
		return ATL::CComPtr<T>::operator=(lp);
	}

	InternalPtr(_Inout_ InternalPtr<T>&& lp) throw()
		: ATL::CComPtr<T>(lp)
	{}

	T* operator=(_Inout_ InternalPtr<T>&& lp) throw()
	{
		return ATL::CComPtr<T>::operator=(lp);
	}
};

} // namespace myid
