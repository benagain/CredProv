#pragma once

#include ".\AbstractKey.h"
#include ".\Softwarekeyfactory.h"

namespace AbstractKeys
{

	/** Software implementation of Random number generation. Really this is a container
	class that allows generation of random data which can then be exported*/
	class SoftwareRNG : public RNG
	{
	protected:
		friend class SoftwareKeyFactory;
		SoftwareRNG(SoftwareKeyFactory &factory); // only SoftwareKeyFactory can create this
	public:
		virtual ~SoftwareRNG(void);

		virtual std::wstring Export(const KeyFormat &format,
						CryptParameters &wrapParameters,
						AbstractKeyPtr &WrappingKey);

		virtual void Generate(KeyParametersPtr pKeyParameters);

		/// Export this key (wrapped by WrappingKey)
		virtual VectorOfBytePtr ExportEx(const KeyFormat &format,
			CryptParameters &wrapParameters,
			AbstractKeyPtr &WrappingKey);

	virtual VectorOfBytePtr Sign(const VectorOfByte &vecUnsigned,
							CryptParameters &signParameters);

	virtual bool Verify(const VectorOfByte &vecData,
						const VectorOfByte &vecSignature,
						CryptParameters &verifyParams);

	protected:
		const SoftwareKeyFactory &m_Factory;
		VectorOfByte m_vecRandomData;
	};

}