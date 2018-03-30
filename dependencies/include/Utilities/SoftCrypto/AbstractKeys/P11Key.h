#pragma once

#include ".\AbstractKey.h"

#include "Utilities/EdeficeCommon/IncludePkcs11.h"

namespace AbstractKeys
{
	/** All keys which are Pkcs11 should derive from this*/
	class P11Key : public HardKey
	{
	public:
		/// Retrieve P11 object handle (to enable P11 keys to interact with each other)
		virtual CK_OBJECT_HANDLE GetKey()=0;
	};
}
