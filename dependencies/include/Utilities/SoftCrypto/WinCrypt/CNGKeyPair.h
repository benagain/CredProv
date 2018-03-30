#pragma once

#include "CNGCrypt.h"
#include "CNGKey.h"
#include <boost/noncopyable.hpp>

#include <bcrypt.h>

namespace CngCrypt
{

/// Parent class for CNG key pairs
class KeyPair : public MyCrypto::KeyPair, private boost::noncopyable
{
protected:
	KeyPair();
	explicit KeyPair(_In_ const CngCrypt::AlgHandle* alg);

	virtual unsigned long pairBlockSize(void) const;

	bool cng_create(_In_ unsigned long size);

	const CngCrypt::AlgHandle*	m_alg;		///< algorithm
	CngCrypt::Key				m_handle;	///< key handle
};

/// Parent class for CNG key pairs in a store, usually hardware (HSM, TPM etc)
class StoreKeyPair : public MyCrypto::KeyPair, public MyCrypto::KeyName, private boost::noncopyable
{
public:
	void Provider(_In_ const std::wstring& provider);
	std::wstring Provider(void) const;
	virtual void Key(_In_ const std::wstring& name);

protected:
	StoreKeyPair();
	explicit StoreKeyPair(_In_ const std::wstring& provider);

	virtual unsigned long pairBlockSize(void) const;

	mutable CngKey::Store	m_store;		///< store provider
};

} // namespace CngCrypt
