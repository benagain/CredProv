#pragma once

#include <memory>
#include <vector>
#include "BasicTString.h"
#include "VectorOfBytePtr.h"

struct HKEY__;
typedef HKEY__* HKEY;

namespace eUtil {

	typedef std::auto_ptr< unsigned char > BytePtr;

	namespace win32 {

		/// Return a Handle wrapper around HKEY_LOCAL_MACHINE
		extern HKEY LocalMachineHkeyHandle();

		/**
		 * Provides easy access to the Windows registry for reading and writing
		 */
		class Registry {
		public:
			explicit Registry(HKEY startingKey);
			Registry( HKEY startingKey, tstring const& baseSubKey );
			~Registry();

			static long deleteValue( HKEY baseKey, tstring const& subKey, tstring const& value );

			long openSubKey( tstring const& keyName );

			tstring readString(
				tstring const& identity,
				bool&          exists,
				tstring const& defaultValue = tstring()) const;

			tstring readString(
				tstring const& identity,
				tstring const& defaultValue = tstring()) const;

			long readLong(
				tstring const& identity,
				bool* exists,
				long defaultValue = 0) const;

			static tstring readString(
				HKEY base,
				//tstring const& subKey,
				tstring const& identity,
				bool&          exists,
				tstring const& defaultValue = tstring());

			static tstring readString(
				HKEY base,
				//tstring const& subKey,
				tstring const& identity,
				tstring const& defaultValue = tstring());

			static void writeString(
				HKEY base,
				tstring const& subKey,
				tstring const& identity,
				tstring const& value);

		protected:
			VectorOfBytePtr readRegValue(HKEY baseKey, const tstring& identity, unsigned long type, bool* exists) const;

			std::pair< tstring, tstring > splitRegistryPath( tstring const& fullPath );

		private:
			HKEY baseKey_;
		};

	}

}
