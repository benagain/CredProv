#pragma once

#include <boost/shared_ptr.hpp>
#include "Utilities/EdeficeCommon/VectorOfByte.h"
#include "Utilities/Softcrypto/IncludeCardmod.h"

namespace AbstractKeys
{

enum KeyFamily
{
	familySharedSecret,
	familyDES,			///< includes DES/2DES/3DES
	familyAES,
	familyRSA,
	familyRNG,			///< Random Number Generation facility
	family2DES16,
	familyHMAC,
	familyECC
};

class SymmetricKeyParameters;
class DESKeyParameters;
class AESKeyParameters;
class RNGKeyParameters;
class RSAKeyParameters;
class HMACKeyParameters;
class ECCKeyParameters;

/**Key usage Attributes (cannot directly reuse CProtKeyPublicData since this is BOLCommon,
yet limited (software) crypto support should be available for clientside components */
class KeyAttributes
{
public:
	KeyAttributes(void);

protected:
	bool m_bExportable;
	bool m_bIsDEK;
	bool m_bIsKEK;
	bool m_bIsMAC;
	bool m_bDerive;

public:
	void SetExportable(_In_ bool bVal) { m_bExportable = bVal; }
	void SetDEK(_In_ bool bVal) { m_bIsDEK = bVal; }
	void SetKEK(_In_ bool bVal) { m_bIsKEK = bVal; }
	void SetMAC(_In_ bool bVal) { m_bIsMAC = bVal; }
	void SetDerive(_In_ bool bVal) { m_bDerive = bVal; }

	bool GetExportable() const { return m_bExportable; }
	bool GetDEK() const { return m_bIsDEK; }
	bool GetKEK() const { return m_bIsKEK; }
	bool GetMAC() const { return m_bIsMAC; }
	bool GetDerive() const { return m_bDerive; }
};

class KeyParameters;

/** Generic parameters applying to all keys*/
class KeyParameters
{
public:
	KeyParameters(void);
	virtual ~KeyParameters(void) {}

	/// allocate and return a new copy of this object. Must be overridden for every concrete class
	virtual KeyParameters *Clone() const = 0;

	// operator = // If shallow copy is not enough to create new unique object, override "operator ="

	/// should be overridden in concrete class to return key family
	virtual KeyFamily Family() const = 0;

	virtual unsigned long GetKeyLengthBytes() const { return 0; }
	virtual unsigned long GetBlockSize() const { return 0; }

	/// override for cases where certain params in this structure must be initialised before the type of key is known.
	virtual bool KeyTypeKnown() const { return true; }

	bool m_bPersistStorage;			///< used for HSM keys where the key can be persisted permanently on the device
	std::wstring m_wstrKeyName;		///< User friendly name for a key (optional)
	std::wstring m_wstrUniqueID;	///< used for HSM keys to uniquely identify a key

	KeyAttributes m_attributes;

	virtual bool IsSymmetric() const { return false; }

	DESKeyParameters &GetDESKeyParameters();
	RNGKeyParameters &GetRNGKeyParameters();
	SymmetricKeyParameters &GetSymmetricKeyParameters();
	AESKeyParameters &GetAESKeyParameters();
	RSAKeyParameters &GetRSAKeyParameters();
	HMACKeyParameters &GetHMACKeyParameters();
	ECCKeyParameters &GetECCKeyParameters();
};
typedef boost::shared_ptr<KeyParameters> KeyParametersPtr;

class SymmetricKeyParameters : public KeyParameters
{
public:
	bool m_bGetKeyCheckValue;			 ///< if set to true, keygen or import shall retrieve KCV and place it in m_vecKeyCheckValue
	VectorOfByte m_vecKeyCheckValue;

	virtual bool IsSymmetric() const { return true; }

	SymmetricKeyParameters();
};
typedef boost::shared_ptr<SymmetricKeyParameters> SymmetricKeyParametersPtr;

/** Parameters for DES Key generation or import*/
class DESKeyParameters : public SymmetricKeyParameters
{
public:
	enum DESKeyType			/// DES key length
	{
		typeUnknown,
		typeDES,			///< 56 bits 1 DES, not FIPS 140
		type2DES,			///< 112 bits, 2 DES
		type3DES,			///< 168 bits, 3 DES
		type2DES16			///< special Gemalto using DES, not FIPS 140
	};

	DESKeyType m_DESKeyType;

	explicit DESKeyParameters(_In_ const DESKeyType typeToGenerate = typeUnknown);

	virtual unsigned long GetKeyLengthBytes() const;
	virtual unsigned long GetBlockSize() const { return 8; }

	virtual KeyParameters *Clone() const;

	virtual bool KeyTypeKnown() const { return (m_DESKeyType != DESKeyParameters::typeUnknown); }
	virtual KeyFamily Family() const
	{
		if (m_DESKeyType == type2DES16)
			return family2DES16;
		else
			return familyDES;
	}
};

class AESKeyParameters : public SymmetricKeyParameters
{
public:
	enum AESKeyType				/// AES key length
	{
		typeUnknown = 0,
		typeAES128 = 128,		///< 128 bits
		typeAES192 = 192,		///< 192 bits
		typeAES256 = 256		///< 256 bits
	};

	AESKeyType m_AESKeyType;

	explicit AESKeyParameters(_In_ const AESKeyType typeToGenerate = typeUnknown);

	virtual unsigned long GetKeyLengthBytes() const { return m_AESKeyType / 8; }
	virtual unsigned long GetBlockSize() const { return 16; }

	virtual KeyParameters *Clone() const;

	virtual bool KeyTypeKnown() const { return (m_AESKeyType != AESKeyParameters::typeUnknown); }
	virtual KeyFamily Family() const { return familyAES; }

	AESKeyType GetAESKeyTypeFromBitLen(_In_ const unsigned long nBitLength) const;
};

/** 'key' generation parameters for RNG class. Allows random data of a specified length
to be generated. Although it inherits from KeyParameters (in order to fit in with base class)
the KeyParameters aren't really used*/
class RNGKeyParameters : public KeyParameters
{
public:
	unsigned long m_nDataLength;

	explicit RNGKeyParameters(_In_ const unsigned long nDataLength);

	virtual KeyParameters *Clone() const;
	virtual KeyFamily Family() const { return familyRNG; }
};

class RSAKeyParameters : public KeyParameters
{
public:
	unsigned long			m_nKeyLengthBits;	///< 0 == unknown
	VectorOfByte			m_publicExponent;	///< public exponent to use

	explicit RSAKeyParameters(_In_ const unsigned long nKeyLengthBits = 0);
	RSAKeyParameters(_In_ const unsigned long nKeyLengthBits, _In_ unsigned long exponent);
	RSAKeyParameters(_In_ const unsigned long nKeyLengthBits, _In_ const VectorOfByte& exponent);

	virtual KeyParameters *Clone() const;
	virtual KeyFamily Family() const { return familyRSA; }

	virtual unsigned long GetKeyLengthBytes() const { return m_nKeyLengthBits / 8; }
	virtual unsigned long GetBlockSize() const { return m_nKeyLengthBits / 8; }
};

class HMACKeyParameters : public SymmetricKeyParameters
{
public:
	unsigned long m_nKeyLengthBits;

	explicit HMACKeyParameters(_In_ const unsigned long nKeyLengthBits = 0);
	virtual ~HMACKeyParameters(void) {}

	virtual KeyParameters* Clone() const;
	virtual KeyFamily Family() const { return familyHMAC; }
	virtual unsigned long GetKeyLengthBytes() const { return m_nKeyLengthBits / 8; }
	virtual bool KeyTypeKnown() const { return (0 != m_nKeyLengthBits); }
};

class ECCKeyParameters : public KeyParameters
{
public:
	enum ECCKeyType
	{
		typeUnknown = 0,
		typeECDSA_P256 = AT_ECDSA_P256,
		typeECDSA_P384 = AT_ECDSA_P384,
		typeECDSA_P521 = AT_ECDSA_P521,
		typeECDHE_P256 = AT_ECDHE_P256,
		typeECDHE_P384 = AT_ECDHE_P384,
		typeECDHE_P521 = AT_ECDHE_P521
	};

	ECCKeyType		m_ECCKeyType;
	unsigned long	m_nKeyLengthBits;		///< 0 == unknown
	bool			m_dsa;					///< true for DSA, false for DH

	ECCKeyParameters(_In_ const unsigned long nKeyLengthBits, _In_ bool dsa = true);
	explicit ECCKeyParameters(_In_ const ECCKeyType typeToGenerate = typeUnknown);
	virtual KeyParameters* Clone() const;
	virtual KeyFamily Family() const { return familyECC; }

	static unsigned long BitLength(_In_ const AbstractKeys::ECCKeyParameters& keyParameters);
	static bool isDSA(_In_ const AbstractKeys::ECCKeyParameters& keyParameters);
};

class SymmetricCryptParameters;
class DESCryptParameters;
class AESCryptParameters;
class RSACryptParameters;
class HMACCryptParameters;
class ECCCryptParameters;

class CryptParameters
{
public:
	enum HashType		/// hash algorithm
	{
		hashNone,		///< no hashing
		hashNoneOID,	///< no hashing with OID
		hashSHA1,		///< SHA1
		hashSHA256,		///< SHA256
		hashSHA1OID,	///< ASN1 encoded SHA1 hash with OID (for P10/P7)
		hashSHA256OID,	///< ASN1 encoded SHA256 hash with OID (for P10/P7)
		hashAnyOID,		///< ASN1 encoded hash with OID (for P10/P7)
		hashSHA384,		///< ASN1 encoded SHA384 hash
		hashSHA384OID,	///< ASN1 encoded SHA384 hash with OID (for P10/P7)
		hashSHA512,		///< ASN1 encoded SHA512 hash
		hashSHA512OID,	///< ASN1 encoded SHA512 hash with OID (for P10/P7)
		hashAny,		///< for verify only, try various hash types
	};

	class HashParameter
	{
	public:
		explicit HashParameter(_In_ const HashType hashType = hashNone);

		bool PadOID(void) const;
		bool VerifyHashSize(_In_ const VectorOfByte& hash) const;

		HashType m_hashType;
	};

	CryptParameters(void);
	virtual ~CryptParameters() {}
	SymmetricCryptParameters &GetSymmetricCryptParameters();
	DESCryptParameters &GetDESCryptParameters();
	AESCryptParameters &GetAESCryptParameters();
	RSACryptParameters &GetRSACryptParameters();
	HMACCryptParameters &GetHMACCryptParameters();
	ECCCryptParameters &GetECCCryptParameters();

	static unsigned long HashSize(_In_ HashType hashType);
	static bool verifyHashSize(_In_ const VectorOfByte& hash, _In_ HashType hashType);

	/// Obviously for HSM etc. it is not possible to override attributes. The purpose of this flag is for software based crypto where operations (e.g. Encrypt) are used to facilitate interaction with HSM based key, or get the KCV for a key that wouldnt normally allow DEK.
	bool m_bOverrideAttributes;
};
typedef boost::shared_ptr<CryptParameters> CryptParametersPtr;

enum KeyFormat
{
	HexSymmetricBlob,	///< Hexed key data (optionally encrypted with a wrapping key)
	LoadPersistedKey,	///< (HSM) find an existing Persisted Key of a specific name
	HexRSA_CSPPrivate,
	HexRSA_CSPPublic,
	HexRSA_PKCS8Private,
	HexRSA_PKCS1Public,
	HexECC_Private,
	HexECC_Public,
	HexECC_PKCS8Private,
	HexECC_PKCS1Public,
	/**ZMKComponentXML**/
};


class SymmetricCryptParameters : public CryptParameters
{
public:
	enum SymmetricMode
	{
		modeUnknown,
		modeECB,						///< can only encrypt multiples of key-block length
		modeCBC,						///< can encrypt any length of data (but padding must be specified
		mode2DES_16,					///< from 8 bytes (D) diversify a 16 byte (key) using a 2DES master key using ECB mode. See Gemplus MPCOS Reference manual pg 38. E(Kl)D(Kr)E(Kl) + E(Kr)D(Kl)E(Kr)
		modeSP800_38B_CMAC,				///< CMAC (ciphered MAC) as defined in sp800-38B
		modeSP800_108_KDFCounterCMAC	///< As required by GP SCP03, referencing NIST sp800-108, and sp800-38B
	};
	enum SymmetricPadding
	{
		padNone,
		padOP,				///< ISO9797 Method 2- Padding as defined in OP Card Spec 2.1, section B.4
		padMyID,			///< ISO10126 - Padding as used in MyID key server database key encryption (rh byte indicates how many bytes of padding are required), compatible with xml-enc (http://www.w3.org/TR/xmlenc-core/)
		padOPToBlock		///< Padding as defined in OP Card Spec 2.1, but don't add extra block of padding if exact match already
	};

	SymmetricMode m_SymmetricMode;
	SymmetricPadding m_SymmetricPadding;
	VectorOfByte m_vecICV;
	unsigned long m_nMACOutputLengthBytes; ///< used for modeSP800_38B_CMAC

	SymmetricCryptParameters(_In_ const SymmetricMode mode = modeUnknown, _In_ const SymmetricPadding padding = padNone);

	virtual bool InputDataMustAlignBlockLength();
};

class DESCryptParameters : public SymmetricCryptParameters
{
public:
	typedef SymmetricMode DESMode;			///< for backwards compatibility, (since previously SymmetricCryptParameters did not exist)
	typedef SymmetricPadding DESPadding;	///< for backwards compatibility, (since previously SymmetricCryptParameters did not exist)

	DESCryptParameters(_In_ const SymmetricMode mode = modeUnknown, _In_ const SymmetricPadding padding = padNone);
};

class AESCryptParameters : public SymmetricCryptParameters
{
public:
	AESCryptParameters(_In_ const SymmetricMode mode = modeUnknown, _In_ const SymmetricPadding padding = padNone);
};

class HMACCryptParameters : public SymmetricCryptParameters, public CryptParameters::HashParameter
{
public:
	HMACCryptParameters(_In_ const HashType hashType=hashNone) ;

	unsigned long GetMacLengthBytes(void) const;
};

class RSACryptParameters : public CryptParameters, public CryptParameters::HashParameter
{
public:
	enum RSAPadding		/// padding type
	{
		padPKCS1,		///< standard PKCS1 padding
		padPKCS1OAEP,	///< OAEP padding
		padSSLV23,		///< SSLV23 padding
		padRaw			///< no padding
	};

	RSAPadding m_rsaPadding;		///< padding scheme

	RSACryptParameters(_In_ const RSAPadding padding = padPKCS1, _In_ HashType hashtype = hashSHA1);
};

class ECCCryptParameters : public CryptParameters, public CryptParameters::HashParameter
{
public:
	/** Signature format
	\li true if signature are in DSA-Sig-Value format
	\verbatim
	DSA - Sig - Value :: = SEQUENCE{
	r INTEGER,
	s INTEGER
	}
	\endverbatim
	\li false signature is R|S */
	bool m_asnSignature;

	ECCCryptParameters(_In_ HashType hashtype = hashSHA256, _In_ bool asnSignature = true);
};

}
