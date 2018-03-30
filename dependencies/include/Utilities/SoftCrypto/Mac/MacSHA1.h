#pragma once

#include "Mac.h"
#include "MacFactory.h"

namespace myid
{
	/*
	 Forward declaration of MacSHA1 object
	*/
	class MacSHA1;

	/*
	 Type declaration of an MacSHA1 smart pointer
	*/
	typedef boost::shared_ptr<MacSHA1> MacSHA1Ptr;

	/*
	 Real declaration of MacSHA1 object
	*/
	class MacSHA1 : public Mac
	{
	protected:
		MacSHA1(void);
		friend MacFactory;

	private:
		// Disallow copy / assignment
		MacSHA1(const MacSHA1&);
		MacSHA1& operator = (const MacSHA1&);

	public:
		virtual ~MacSHA1(void);
		virtual long GetMacLength(void) const;

	protected:
		virtual const EVP_MD* GetEVP_MD(void) const;

	};
} // namespace myid
