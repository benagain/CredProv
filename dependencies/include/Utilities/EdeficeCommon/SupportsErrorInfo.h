#pragma once

namespace eCom
{

#define VERSION_ATL

	struct SupportsErrorInfo
	{
		SupportsErrorInfo (const IID& riid, const IID** supported, const size_t nNumberInterfaces=1)
			: riid_( riid ), supported_( supported ), m_nNumberInterfaces(nNumberInterfaces)
		{
		}

		/** Beware that the old system (where the number of interfaces supported would be
		dynamically calculated using sizeof did not work (because it just gets the sizeof the pointer)
		if a COM object supports multiple interfaces it MUST pass in the nNumberInterfaces to the constructor*/
		operator HRESULT()
		{
			//for (int i=0; i < sizeof(supported_) / sizeof(supported_[0]); i++)
			for (size_t i=0; i < m_nNumberInterfaces; i++)
			{
				if (VERSION_ATL::InlineIsEqualGUID(*supported_[i], riid_))
					return S_OK;
			}
			return S_FALSE;
		}

	private:
		const IID&  riid_;
		const IID** supported_;
		const size_t m_nNumberInterfaces;
	};
}
