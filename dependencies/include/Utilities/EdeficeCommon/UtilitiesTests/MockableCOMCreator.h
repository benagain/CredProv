#pragma once

#include "../ComCreator.h"
#include "MockCommon.h"

namespace myid
{
	namespace testing
	{
		/* FakeComCreator in Server/TestHelper is probably more useful to you,
		this is for cases where you want to do something really weird. */
		class MockableCOMCreator : public myid::ComCreator
		{
		public:
			/* Compiler doesn't like us making CreateImpl the mock function, we get
			a "warning treated as error" about the const-ness of the parameters changing
			when they haven't. */
			MOCK_METHOD2(mockCreateImpl, ATL::CComPtr<IUnknown>(const wchar_t * const progId, HRESULT & result));
			virtual ATL::CComPtr<IUnknown> CreateImpl(const wchar_t * const progId, HRESULT & result)
			{
				return mockCreateImpl(progId, result);
			}
		};
	}
}
