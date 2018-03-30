#pragma once

#include "Utilities/SoftCrypto/AbstractKeys/AbstractKey.h"
#include "Utilities/SoftCrypto/AbstractKeys/AbstractKeyParameters.h"
#include "Utilities/SoftCrypto/Mac/Mac.h"
#include "Utilities/SoftCrypto/Mac/MacFactory.h"

namespace AbstractKeys
{
	/*
	 Forward declaration of HKDF object
	*/
	class HKDF;

	/*
	 Type declaration of an HKDF smart pointer
	*/
	typedef boost::shared_ptr<HKDF> HKDFPtr;

	/*
	 Real declaration of HKDF object
	*/
	class HKDF
	{
	private:
		/*
		 HMACProxy :: PAB
		*/
		class HMACProxy
		{
		public:
			virtual VectorOfBytePtr Sign(const VectorOfBytePtr& pVecUnsigned) const = 0;
		};

		/*
		 HMACProxyT :: Templated class for storage of variable type data
		*/
		template <typename T> class HMACProxyT : public HMACProxy
		{
		public:
			HMACProxyT(const T& proxy) : HMACProxy(), m_Proxy(proxy) {}
		protected:
			T m_Proxy;
		};

		/*
		 AbstractKeyProxy :: Concrete implementation for AbstractKey HMAC
		*/
		class AbstractKeyProxy : public HMACProxyT<AbstractKeyPtr>
		{
		public:
			AbstractKeyProxy(const AbstractKeyPtr& pKey, const CryptParameters::HashType hashType);
			virtual VectorOfBytePtr Sign(const VectorOfBytePtr& pVecUnsigned) const;

		private:
			CryptParameters::HashType m_HashType;
		};

		/*
		 MacProxy :: Concrete implementation for MacPtr HMAC
		*/
		class MacProxy : public HMACProxyT<myid::MacPtr>
		{
		public:
			MacProxy(const myid::MacPtr& pMac);
			virtual VectorOfBytePtr Sign(const VectorOfBytePtr& pVecUnsigned) const;
		};

		/*
		 Type declaration of an HMACProxy smart pointer
		*/
		typedef boost::shared_ptr<HMACProxy> HMACProxyPtr;

	private:
		HKDF(void);

		// Disallow copy / assignment
		HKDF(const HKDF&);
		HKDF& operator = (const HKDF&);

	public:
		virtual ~HKDF(void);

		/**
		* Create a new HKDF object which will use the specified hashing algorithm
		* 
		* @param eHashAlgorithm
		*		- hashing algorithm to use
		* 
		* @return HKDFPtr (HKDF object wrapped up in a smart pointer)
		*/
		static HKDFPtr Create(const CryptParameters::HashType eHashType);
		static HKDFPtr Create(const myid::MacFactory::EHashAlgorithm eHashAlgorithm);

		/**
		* Step 1 of RFC 5869
		* 
		* @param pVecIKM
		*		- input keying material
		* @param pVecSalt
		*		- salt to use
		* 
		* @return PRK (pseudo random key)
		*/
		VectorOfBytePtr Extract(const VectorOfBytePtr& pVecIKM, const VectorOfBytePtr& pVecSalt = VectorOfBytePtr()) const;

		/**
		* Step 2 of RFC 5869.
		* 
		* @param pPRK / pVecPRK
		*		- pseudo random key from step 1
		* @param pVecInfo
		*		- application specific additional data
		* @param len
		*		- size of the output keying material
		* 
		* @return OKM (output keying material)
		*/
		VectorOfBytePtr Expand(const AbstractKeyPtr& pPRK, const VectorOfBytePtr& pVecInfo, const long len) const;
		VectorOfBytePtr Expand(const VectorOfBytePtr& pVecPRK, const VectorOfBytePtr& pVecInfo, const long len) const;

	private:
		/**
		* Creates a Mac instance and initializes it with required parameters
		* 
		* @param pVecKey
		*		- key data to use
		*
		* @return new MacPtr instance
		*/
		myid::MacPtr CreateHMac(const VectorOfBytePtr& pVecKey) const;

		/**
		* Make sure that the VectorOfBytePtr specified is not NULL and if
		* it is then initialise a new VectorOfByte of the specified length
		* 
		* @param pVecKey
		*		- the VectorOfBytePtr to check
		* @param lMacLength
		*		- the length to use when creating a new VectorOfByte
		*
		* @return new VectorOfBytePtr instance
		*/
		VectorOfBytePtr ValidateVectorOfBytePtr(const VectorOfBytePtr& pVec, const long len) const;

		/**
		* Step 2 of RFC 5869.
		* 
		* @param pProxy
		*		- proxy used to sign data
		* @param pVecInfo
		*		- application specific additional data
		* @param len
		*		- size of the output keying material
		* 
		* @return OKM (output keying material)
		*/
		VectorOfBytePtr Expand(const HMACProxyPtr& pProxy, const VectorOfBytePtr& pVecInfo, const long len) const;

	private:
		myid::MacFactory::EHashAlgorithm m_HashAlgorithm;

	};
}
