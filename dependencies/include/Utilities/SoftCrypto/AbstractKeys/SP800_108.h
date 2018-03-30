#pragma once

#include "AbstractKey.h"

namespace AbstractKeys
{

/** implement "KDF in Counter Mode" functionality as defined in sp800-108
* http://csrc.nist.gov/publications/nistpubs/800-108/sp800-108.pdf
* The position and size of the "counter" byte(s) will be specified to
* add flexibility.  The counter is the only data that changes between calls
* to the PRF to generate a byte string of the required length.
* sp800-108 order	: [i]2 || Label || 0x00 || Context || [L]2 - 2 byte counter at the start of the data.
* SCP03 order		: Label || 0x00 || [L]2 || [i]1 || Context - 1 byte counter part way through the data.
*/
class SP800_108
{
public:
	SP800_108(void);
	virtual ~SP800_108(void);

	void Initialise(_In_ AbstractKeyPtr symKey);
	VectorOfBytePtr KDFInCounterMode(_In_ VectorOfByte vecMessage, _In_ const size_t counterPosition, _In_ const size_t counterSizeBytes, _In_ const size_t KoSizeBytes);

private:
	AbstractKeyPtr m_symKey;
};

}
