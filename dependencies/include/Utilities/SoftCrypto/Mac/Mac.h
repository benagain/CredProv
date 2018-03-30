#pragma once

#include "OpenSSL/hmac.h"

namespace myid
{
	/*
	 Forward declaration of Mac object
	*/
	class Mac;

	/*
	 Type declaration of an Mac smart pointer
	*/
	typedef boost::shared_ptr<Mac> MacPtr;

	/*
	 Real declaration of Mac object
	*/
	class Mac
	{
	protected:
		Mac(void);

	private:
		// Disallow copy / assignment
		Mac(const Mac&);
		Mac& operator = (const Mac&);

	public:
		virtual ~Mac(void);
		
		/*
		 Name: GetMacLength
		 Description:
		   Get the length of the message authentication code
		*/
		virtual long GetMacLength(void) const = 0;

		/*
		 Name: HMAC
		 Description:
		   Perform a single stage HMAC
		*/
		virtual VectorOfBytePtr HMAC(
			const VectorOfBytePtr& pVecKeyData
		  , const VectorOfBytePtr& pVecData
		  );

		/*
		 Name: Init
		 Description:
		   Initialise the underlying HMAC context with the key specified
		*/
		virtual void Init(
			const VectorOfBytePtr& pVecKey
			);

		/*
		 Name: Update
		 Description:
		   Update the message authentication code with the data specified
		*/
		virtual void Update(
			const VectorOfBytePtr& pVecData
			);

		/*
		 Name: Final
		 Description:
		   Return the message authentication code
		*/
		virtual VectorOfBytePtr Final(void);

		/*
		 Name: Reset
		 Description:
		   Re-initialise the underlying HMAC context
		*/
		virtual void Reset(void);

	protected:
		virtual const EVP_MD* GetEVP_MD(void) const = 0;

	private:
		HMAC_CTX m_CTX;

	};
} // namespace myid
