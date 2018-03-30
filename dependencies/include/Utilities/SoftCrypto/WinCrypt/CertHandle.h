#pragma once

#include <wincrypt.h>

namespace CertStore
{

	//------------------------------------------------------------------------------------------------------------------
	// Handles

	/// Certificate store handle, auto closes
	class StoreHandle
	{
	public:
		StoreHandle();
		explicit StoreHandle(_In_ HCERTSTORE rhs);
		explicit StoreHandle(_In_ const StoreHandle& rhs);
		~StoreHandle();

		bool Open(_In_z_ LPCSTR provider, _In_ DWORD encodingType, _In_ DWORD dwFlags, _In_ const void* pvPara);
		bool Open(_In_z_ const wchar_t* store);
		void Close();
		StoreHandle& operator=(_In_ HCERTSTORE rhs);
		StoreHandle& operator=(_In_ const StoreHandle& rhs);
		void Attach(_In_ HCERTSTORE rhs);
		void Dettach(void);
		bool operator!() const;
#ifndef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
		explicit operator bool(void) const;
#else
		operator bool(void) const;
#endif
		operator HCERTSTORE();
		HCERTSTORE* operator&();

	protected:
		HCERTSTORE		hStore;				///< certificate store handle
	};

	/// cert contexts, auto close and copy
	template <class C, BOOL WINAPI F(_In_opt_ const C* c), const C* WINAPI D(_In_opt_ const C* c)>
	class context
	{
	public:
		context() : ctx(nullptr) {}
		explicit context(_In_opt_ const C* rhs) { ctx = D(rhs); }
		explicit context(_In_ const context& rhs) { ctx = D(rhs.ctx); }
		~context() { Close(); }

		void Close()
		{
			if (ctx)
			{
				F(ctx);
				ctx = nullptr;
			}
		}
		context& operator=(_In_opt_ const C* rhs) { ctx = D(rhs); return *this; }
		context& operator=(_In_ const context& rhs) { ctx = D(rhs.ctx); return *this; }
		bool operator!() const { return ctx == nullptr; }
		const C& operator*() const { return ctx; }
		const C* operator->() const { return ctx; }
		const C** operator&() { return &ctx; }
		operator const C*() const { return ctx; }
#ifndef BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
		explicit operator bool() const { return ctx != nullptr; }
#else
		operator bool() const { return ctx != nullptr; }
#endif

	protected:
		_Maybenull_ const C*	ctx;			///< context
	};

	typedef context<CERT_CONTEXT, CertFreeCertificateContext, CertDuplicateCertificateContext> CertContext;
	typedef context<CRL_CONTEXT, CertFreeCRLContext, CertDuplicateCRLContext> CrlContext;
	typedef context<CTL_CONTEXT, CertFreeCTLContext, CertDuplicateCTLContext> CtlContext;

} // namespace CertStore
