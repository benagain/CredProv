#pragma once

#include "AbstractKey.h"
#include "AbstractKeyParameters.h"
#include "SoftwareKeyFactory.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{
	class SoftwareHMACKey :	public AbstractKey
						  , public HMACKey
						  , public boost::enable_shared_from_this<SoftwareHMACKey>
	{
	public:
		virtual ~SoftwareHMACKey(void);

		virtual void Generate(
			KeyParametersPtr pKeyParameters
			);
		
		VectorOfBytePtr Encrypt(
			const VectorOfByte& data
		  , CryptParameters& cryptParameters
		  );
		
		VectorOfBytePtr Decrypt(
			const VectorOfByte& data
		  , CryptParameters& cryptParameters
		  );

		virtual bool DestroyKey(void);

		virtual AbstractKeyPtr DeriveKey(
			const VectorOfByte& vecDerivationData
		  , CryptParameters& deriveParams
		  , KeyParametersPtr& newKeyParameters
		  );

		virtual KeyParametersPtr GetKeyParameters(void) const;

		virtual void Import(
			const std::wstring& wstrKeyData
		  , const KeyFormat& keyFormat
		  , CryptParameters& unwrapParameters
		  , KeyParametersPtr importedKeyParameters
		  , AbstractKeyPtr& unwrappingKey
		  );

		virtual void ImportEx(
			const VectorOfByte& vecKeyData
		  , const KeyFormat& keyFormat
		  , CryptParameters& unwrapParameters
		  , KeyParametersPtr importedKeyParameters
		  , AbstractKeyPtr &UnwrappingKey
		  );

		virtual std::wstring Export(
			const KeyFormat& keyFormat
		  , CryptParameters& wrapParameters
		  , AbstractKeyPtr& wrappingKey
		  );
		
		virtual VectorOfBytePtr ExportEx(
			const KeyFormat& keyFormat
		  , CryptParameters& wrapParameters
		  , AbstractKeyPtr& wrappingKey
		  );

		virtual VectorOfBytePtr Sign(
			const VectorOfByte& vecUnsigned
		  , CryptParameters& signParameters
		  );

		virtual bool Verify(
			const VectorOfByte& vecData
		  , const VectorOfByte& vecSignature
		  , CryptParameters& verifyParams
		  );

	protected:
		SoftwareHMACKey(SoftwareKeyFactory& factory);
		
		virtual void ImportHexSymmetricBlob(
			const VectorOfByte& vecKeyData
		  , CryptParameters& unwrapParameters
		  , KeyParametersPtr importedKeyParameters
		  , AbstractKeyPtr& unwrappingKey
		  );

		SoftwareKeyFactory& m_Factory;
		KeyParametersPtr m_pKeyParameters;

		friend class SoftwareKeyFactory;

	private:
		VectorOfByte m_vecKeyData;

	};
}
