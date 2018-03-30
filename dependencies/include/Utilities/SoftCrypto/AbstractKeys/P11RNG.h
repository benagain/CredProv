#pragma once

#include ".\AbstractKey.h"
#include ".\P11SessionKeyFactory.h"

namespace AbstractKeys
{

	/** P11 implementation of Random number generation. Really this is a container
	class that allows generation of random data which can then be exported*/
	class P11RNG : public RNG,
					public HardKey // not inheriting of P11Key, because no key handle required
	{
	protected:
		friend class P11SessionKeyFactory;
		P11RNG(P11SessionKeyFactory &factory); // only P11KeyFactory can create this
	public:
		virtual ~P11RNG(void);

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
		const P11SessionKeyFactory &m_Factory;
		VectorOfByte m_vecRandomData;
	};

}
