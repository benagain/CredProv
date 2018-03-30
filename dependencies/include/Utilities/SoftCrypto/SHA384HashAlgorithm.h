#pragma once

#include "HashAlgorithm.h"

namespace myid
{
	class SHA384HashAlgorithm : public HashAlgorithm
	{
	public:
		SHA384HashAlgorithm();

	protected:
		virtual void Hash(const VectorOfBytePtr input, VectorOfBytePtr hash);
	};
}