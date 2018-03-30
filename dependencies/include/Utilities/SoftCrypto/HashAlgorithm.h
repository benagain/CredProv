#pragma once

#include "Utilities/EdeficeCommon/VectorOfBytePtr.h"
#include "Utilities/EdeficeCommon/Conversions/VectorOfByteConversion.h"

namespace myid
{
	// A null deleter to allow us to wrap a VectorOfBytePtr in a VectorOfBytePtr without the
	// shared pointer trying to delete it and causing really bad things to happen
	struct null_deleter { void operator()(void const *) const {} };

	// ---------------------------------------------------------------------------------------------

	/*!
	* A base class for a hash algorithm, this provides the logic for registration and other common code
	* such as multiple hash iterations leaving the derived classes to implement the hashing logic.
	*/
	class HashAlgorithm
	{
	public:
		VectorOfBytePtr HashString(const std::wstring& string, unsigned int iterations = 1)
		{
			return HashBytes(myid::wstringToVector(string.c_str()), iterations);
		}

		VectorOfBytePtr HashBytes(const VectorOfByte& input, unsigned int iterations = 1)
		{
			// Note: Using const_cast to coorce the vector into the pointer, which gets passed as a
			// const VectorOfBytePtr and is safe from modification. Not ideal but it avoids having
			// to copy vecData into a new VectorOfByte just for this function call
			return HashBytes(VectorOfBytePtr(const_cast<VectorOfByte*>(&input), null_deleter()), iterations);
		}

		VectorOfBytePtr HashBytes(const VectorOfBytePtr input, unsigned int iterations = 1)
		{
			VectorOfBytePtr nextInput(input);
			VectorOfBytePtr buffer1(new VectorOfByte(m_hashLength));
			VectorOfBytePtr buffer2((iterations > 1) ? new VectorOfByte(m_hashLength) : NULL);

			for (unsigned int i = 0; i < iterations; ++i)
			{
				Hash(nextInput, (i%2 == 0) ? buffer1 : buffer2);
				nextInput = (i%2 == 0) ? buffer1 : buffer2;
			}

			return nextInput;
		}

	protected:
		explicit HashAlgorithm(unsigned int hashLength)
		{
			m_hashLength = hashLength;
		}

		/*!
		* Performs a single hash iteration upon the input data provided
		*
		* \note
		*   The output hash vector is pre-initialised to the required size and, where possible, should be
		*   populated with the hash result without any reinitialisation. This will improve efficiency when
		*   multiple hash iterations are used because the HashBytes() function which calls this will swap
		*   between two buffers rather than allocating new ones for each iteration.
		*/
		virtual void Hash(const VectorOfBytePtr input, VectorOfBytePtr hash) = 0;

	private:
		unsigned int m_hashLength;
	};

	typedef std::shared_ptr<HashAlgorithm> HashAlgorithmPtr;
}