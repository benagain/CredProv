#pragma once

// All these methods are intended to be private to the SoftCrypto library and SoftCrypto.Tests
// Instead use abstract keys or SoftCrypto.h

#include "CommonKey.h"
#include "Utilities/EdeficeCommon/Status.h"
#include <list>

namespace MyCrypto
{
typedef boost::shared_ptr<class KeyFactory> KeyFactoryPtr;
typedef std::list<KeyFactoryPtr> KeyFactoryList;

class Library
{
public:
	/// Crypto library in use
	enum libraries
	{
		OPENSSL,		///< OpenSSL
		CNG,			///< Windows CNG
		NET,			///< Windows .NET
		CSP,			///< Windows CSP
		P11,			///< PKCS11
	};
	class library : public myid::Status<libraries, OPENSSL>
	{
		typedef myid::Status<libraries, OPENSSL> inherited;

	public:
		library() {}
		explicit library(S status) : inherited(status) {}
		std::wstring text() const;
	};

	static KeyFactoryPtr keyFactory;
	static KeyFactoryList keyFactories;
};

/// Generic factory using Library::keyFactory
class CommonKeyFactory
{
public:
	static RandomPtr Random();
	static HashPtr Hash();
	static HMACPtr HMAC();
	static RsaKeyPtr RsaKey();
	static EccKeyPtr EccKey();
	static SymKeyPtr AES();
	static SymKeyPtr DES();
	static PBKDF2Ptr PBKDF2();

	static RandomPtr Random(Library::library lib);
	static HashPtr Hash(Library::library lib);
	static HMACPtr HMAC(Library::library lib);
	static RsaKeyPtr RsaKey(Library::library lib);
	static EccKeyPtr EccKey(Library::library lib);
	static SymKeyPtr AES(Library::library lib);
	static SymKeyPtr DES(Library::library lib);
	static PBKDF2Ptr PBKDF2(Library::library lib);
};

/// Interface for specific factories
class KeyFactory
{
public:
	virtual RandomPtr Random() const = 0;
	virtual HashPtr Hash() const = 0;
	virtual HMACPtr HMAC() const = 0;
	virtual RsaKeyPtr RsaKey() const = 0;
	virtual EccKeyPtr EccKey() const = 0;
	virtual SymKeyPtr AES() const = 0;
	virtual SymKeyPtr DES() const = 0;
	virtual PBKDF2Ptr PBKDF2() const = 0;

	virtual MyCrypto::Library::library Library() const = 0;
};
}
