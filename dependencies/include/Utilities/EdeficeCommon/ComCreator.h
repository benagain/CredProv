#pragma once

#include "Utilities\EdeficeCommon\Exceptions\ErrorException.h"
#include "Utilities\EdeficeCommon\ComPtrUtils.h"
#include <memory>

namespace myid
{
/// Create a COM object
///
/// The default implementation creates a real COM object.  Register your own creator if
/// you want different behaviour, for creating fakes for testing purposes for example.
class ComCreator
{
public:
	template<class T>
	static ATL::CComPtr<T> Create(_In_z_ const wchar_t * const progId,
		_In_opt_ eCom::CreateComPtrErrorHandler *handler = nullptr)
	{
		HRESULT result = E_NOINTERFACE;
		if (ATL::CComQIPtr<T> impl = creator->CreateImpl(progId, result))
			return impl;

		if (handler)
		{
			handler->creationError(result);
		}
		else
		{
			eCom::CreateComPtrErrorExceptionErrorHandler exception(progId);
			exception.creationError(result);
		}

		return nullptr;
	}


	static void Register(_In_ std::shared_ptr<ComCreator> creatorIn)
	{
		ComCreator::creator = creatorIn;
	}

	static std::shared_ptr<ComCreator> Creator()
	{
		return creator;
	}

protected:
	virtual ATL::CComPtr<IUnknown> CreateImpl(_In_z_ const wchar_t * const progId, _Out_ HRESULT & result) = 0;

private:
	static std::shared_ptr<ComCreator> creator;
};
	
class ComCreatorRegister
{
	std::shared_ptr<ComCreator> m_OldCreator;
public:
	explicit ComCreatorRegister(_In_ std::shared_ptr<ComCreator> creator)
		: m_OldCreator(ComCreator::Creator())
	{
		ComCreator::Register(creator);
	}
	~ComCreatorRegister()
	{
			ComCreator::Register(m_OldCreator);
	}
};
}