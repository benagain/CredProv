#pragma once

#include "Mac.h"
#include "MacFactory.h"

namespace myid
{
	/*
	 Forward declaration of MacSHA256 object
	*/
	class MacSHA256;

	/*
	 Type declaration of an MacSHA256 smart pointer
	*/
	typedef boost::shared_ptr<MacSHA256> MacSHA256Ptr;

	/*
	 Real declaration of MacSHA256 object
	*/
	class MacSHA256 : public Mac
	{
	protected:
		MacSHA256(void);
		friend MacFactory;

	private:
		// Disallow copy / assignment
		MacSHA256(const MacSHA256&);
		MacSHA256& operator = (const MacSHA256&);

	public:
		virtual ~MacSHA256(void);
		virtual long GetMacLength(void) const;

	protected:
		virtual const EVP_MD* GetEVP_MD(void) const;

	};
} // namespace myid
