#pragma once
#include "paddinghelper.h"
#define NCOMPAT
#include "OpenSSL\des.h"

/** DES/3DES functionality (previously in) softcrypto isolated into its own class
currently will not seed SSL RNG (override class currently responsible - 
e.g. SoftCrypo, which seeds RNG in constructor, or SoftwareDESKey, with uses SeedRNGOpenSSL to seed on demand */
class SoftCryptoDES : public CPaddingHelper
{
public:
	SoftCryptoDES(void);
	virtual ~SoftCryptoDES(void);

	virtual VectorOfByte RData(int const nSize);

	VectorOfByte TripleDesEcbEncrypt(_In_ VectorOfByte const & plainData);
	VectorOfByte TripleDesCbcEncrypt(_In_ VectorOfByte const & plainData, _In_opt_ VectorOfByte *vecChainingVector = nullptr);
	VectorOfByte TripleDesEcbDecrypt(_In_ VectorOfByte const & plainData);
	VectorOfByte TripleDesCbcDecrypt(_In_ VectorOfByte const & plainData, _In_opt_ VectorOfByte *vecChainingVector = nullptr);

	VectorOfByte SingleDesEcbEncrypt(_In_ VectorOfByte const & plainData);
	VectorOfByte SingleDesEcbDecrypt(_In_ VectorOfByte const & plainData);
	VectorOfByte SingleDesCbcEncrypt(_In_ VectorOfByte const & plainData, _In_opt_ VectorOfByte *vecChainingVector);
	VectorOfByte SingleDesCbcDecrypt(_In_ VectorOfByte const & plainData, _In_opt_ VectorOfByte *vecChainingVector);

	VectorOfByte Encrypt_2DES_16(_In_ VectorOfByte const & divData);

	VectorOfByte HMAC_SHA1(_In_ const VectorOfByte &vecData);

	bool isSingleDesAllowed() const;
	bool isDesKeySet();
	void SetDesStatus(_In_ bool bStatus);
	OKBOOL SetDesKey(_In_ VectorOfByte const & vecDesKey);
	OKBOOL GenTripleDesKey();
	OKBOOL GetTripleDes(_Out_ _Always_(_Post_valid_) VectorOfByte & key);

	static void SetDESParity( VectorOfByte &vecDESKey ); // functions for DES/2DES/3DES

	class TripleDes
	{
	public:
		DES_cblock Key1;
		DES_cblock Key2;
		DES_cblock Key3;

		size_t	nKeyLength;
		bool    m_IsDesKeySet;		///< is DES key set?

		TripleDes();
		~TripleDes();
		void Clear(void);
		void SetDesStatus(bool bStatus);
	};
protected:
	class TripleDesKeySchedule
	{
	public:
		DES_key_schedule key1;
		DES_key_schedule key2;
		DES_key_schedule key3;

		TripleDesKeySchedule( TripleDes const & key );
	};

	bool DesLoopBackTest();

	TripleDes  m_3DesKey;
};
