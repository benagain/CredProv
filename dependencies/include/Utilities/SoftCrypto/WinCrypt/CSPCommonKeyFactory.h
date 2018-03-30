#include "StdAfx.h"
#include "../CommonKeyFactory.h"

namespace CspCrypt
{
class KeyFactory : public MyCrypto::KeyFactory
{
public:
	virtual MyCrypto::RandomPtr Random() const;
	virtual MyCrypto::HashPtr Hash() const;
	virtual MyCrypto::HMACPtr HMAC() const;
	virtual MyCrypto::RsaKeyPtr RsaKey() const;
	virtual MyCrypto::EccKeyPtr EccKey() const;
	virtual MyCrypto::SymKeyPtr AES() const;
	virtual MyCrypto::SymKeyPtr DES() const;
	virtual MyCrypto::PBKDF2Ptr PBKDF2() const;

	virtual MyCrypto::Library::library Library() const;

	static void Register();
};
}
