#pragma once

#include "Mac.h"
#include "Utilities/SoftCrypto/AbstractKeys/AbstractKeyParameters.h"

namespace myid
{
	class MacFactory
	{
	public:
		enum EHashAlgorithm
		{
			eNone
		  , eSHA1
		  , eSHA256
		};

	public:
		MacFactory(void);
		virtual ~MacFactory(void);

	private:
		// Disallow copy / assignment
		MacFactory(const MacFactory&);
		MacFactory& operator = (const MacFactory&);

	public:
		// Create a Mac object which supports the hash algorithm specified
		MacPtr Create(const EHashAlgorithm eHashAlgorithm) const;

		// Convert from MacFactory::EHashAlgorithm to AbstractKeys::CryptParameters::HashType
		static AbstractKeys::CryptParameters::HashType EHashAlgorithmToHashType(const MacFactory::EHashAlgorithm eHashAlgorithm);
		
		// Convert from AbstractKeys::CryptParameters::HashType to MacFactory::EHashAlgorithm
		static MacFactory::EHashAlgorithm HashTypeToEHashAlgorithm(const AbstractKeys::CryptParameters::HashType hashType);

	};
} // namespace myid
