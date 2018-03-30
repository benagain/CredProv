#pragma once

#include "HashAlgorithm.h"

namespace myid
{
	class SHA256HashAlgorithm : public HashAlgorithm
	{
	public:
		SHA256HashAlgorithm();

	protected:
		virtual void Hash(const VectorOfBytePtr input, VectorOfBytePtr hash);
	};
}