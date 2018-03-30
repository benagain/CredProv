#pragma once

#include "AbstractKey.h"
#include "../CommonKeyFactory.h"
#include <boost/noncopyable.hpp>

namespace AbstractKeys
{

/** Use SoftwareKeyFactory to create SoftwareKey objects.
SoftwareKeyFactory requires no special initialisation
Because SoftwareKeys created hold a back reference, this object should not be allowed to go
out of scope until all the key objects are gone*/
class SoftwareKeyFactory : public AbstractKeyFactory
{
public:
	virtual ~SoftwareKeyFactory(void);

	virtual AbstractKeyPtr Create(_In_ const KeyFamily &family);
	virtual AbstractKeyPtr Create(_In_ const KeyFamily &family, _In_ const MyCrypto::KeyFactoryPtr& keyFactory);
	virtual bool AreExportableKeysAvailable();
};

class SoftwareAbstractKey : private boost::noncopyable
{
protected:
	explicit SoftwareAbstractKey(_In_ SoftwareKeyFactory &factory);

	SoftwareKeyFactory& m_Factory;
};


}
