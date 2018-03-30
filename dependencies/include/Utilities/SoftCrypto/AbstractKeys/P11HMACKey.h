#pragma once

#include "AbstractKey.h"
#include "AbstractKeyParameters.h"
#include "P11SymmetricKey.h"
#include "P11SessionKeyFactory.h"

#include <boost/enable_shared_from_this.hpp>

namespace AbstractKeys
{
	class P11HMACKey : public P11SymmetricKey
		             , public HMACKey
					 , public boost::enable_shared_from_this<P11HMACKey> 
	{
	public:
		virtual ~P11HMACKey(void);

		virtual void Generate(
			KeyParametersPtr pKeyParameters
			);
		
		virtual VectorOfBytePtr Encrypt(
			const VectorOfByte& data
		  , CryptParameters& cryptParameters
		  );
		
		virtual VectorOfBytePtr Decrypt(
			const VectorOfByte& data
		  , CryptParameters& cryptParameters
		  );

		virtual void SetSymmetricMechanism(
			SymmetricCryptParameters& symKeyParams
		  , CK_MECHANISM& mechanism
		  , bool bCombinePadding = false
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
		P11HMACKey(P11SessionKeyFactory &factory); // must be instantiated via a KeyFactory object

		virtual CK_MECHANISM_TYPE GetKeyGenMechanism(
			const SymmetricKeyParameters& symKeyParams
		  , int& nCKA_VALUE_LEN
		  ) const;

		virtual CK_KEY_TYPE CryptoAlgorithmToP11KeyType(
			const SymmetricKeyParameters& symKeyParams
			) const;

		virtual AbstractKeyPtr GenerateTemporaryKey(
			AbstractKeyFactory& keyFactory
		  , KeyParametersPtr& params
		  );

		virtual void GetKeyTypeCurrentlyLoaded(SymmetricKeyParameters& symKeyParams);

		virtual void SetKeyParametersByEncryptedDataLength(
			const unsigned long nKeyDataLength
		  , const SymmetricCryptParameters& unwrapParams
		  , SymmetricKeyParameters& symKeyParams
		  , const AbstractKeyPtr pEncryptionKey
		  ) const;

		friend class P11SessionKeyFactory;
	};
}
