#pragma once

#include "HashAlgorithm.h"

namespace myid
{
	class SHA1HashAlgorithm : public HashAlgorithm
	{
	public:
		SHA1HashAlgorithm();

	protected:
		virtual void Hash(const VectorOfBytePtr input, VectorOfBytePtr hash);
	};
}