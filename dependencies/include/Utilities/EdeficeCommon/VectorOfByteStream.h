#pragma once

#include "VectorOfBytePtr.h"
#include <boost/noncopyable.hpp>

namespace myid
{
	/*
	 Forward declaration of VectorOfByteStream object
	*/
	class VectorOfByteStream;

	/*
	 Type declaration of an VectorOfByteStream smart pointer
	*/
	typedef boost::shared_ptr<VectorOfByteStream> VectorOfByteStreamPtr;

	/*
	 Real declaration of VectorOfByteStream object
	*/
	class VectorOfByteStream : private boost::noncopyable
	{
	public:
		typedef VectorOfByte::size_type size_type;

	private:
		explicit VectorOfByteStream(_In_ const VectorOfBytePtr& pVecBytes);

	public:
		virtual ~VectorOfByteStream(void);

	public:
		void Reset(void);
		void SkipBytes(_In_ const size_type& count);
		bool Eof(void) const;
		size_type GetPosition(void) const;

		void Read(_Out_ myid::VectorOfByte& vecBytes, _In_ const size_type& offset, _In_ const size_type& count, _In_ bool fReverseBytes = false);

		BYTE  ReadByte(void);
		int   ReadInt(_In_ bool fReverseBytes = false);
		short ReadShort(_In_ bool fReverseBytes = false);

	public:
		static VectorOfByteStreamPtr Create(_In_ const VectorOfBytePtr& pVecBytes);

	private:
		template<class T> T ReadType(_In_ bool fReverseBytes = false)
		{
			const size_t len = sizeof(T);

			VectorOfByte vecValue;
			Read(vecValue, 0, len, fReverseBytes);

			T value;
			memcpy_s(&value, len, &vecValue[0], len);

			return value;
		};

	private:
		VectorOfBytePtr m_pVecBytes;
		size_type m_Position;

	};
}
