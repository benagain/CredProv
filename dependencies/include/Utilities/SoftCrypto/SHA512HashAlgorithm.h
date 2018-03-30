#pragma once

#include "HashAlgorithm.h"

namespace myid
{
	class SHA512HashAlgorithm : public HashAlgorithm
	{
	public:
		SHA512HashAlgorithm();

	protected:
		virtual void Hash(const VectorOfBytePtr input, VectorOfBytePtr hash);
	};
}