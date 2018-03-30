#pragma once

namespace SoftCryptoLib
{

// OPEN SSL
const unsigned long Soft_PublicEncrypt			= 0x80046000;	///< SoftCrypto: RsaPublicEncrypt, encrypt unsuccessful
const unsigned long Soft_PrivateEncrypt			= 0x80046001;	///< SoftCrypto: RsaPrivateEncrypt, encrypt unsuccessful
const unsigned long Soft_PublicDecrypt			= 0x80046002;	///< SoftCrypto: RsaPrivateDecrypt, decrypt unsuccessful
const unsigned long Soft_PrivateDecrypt			= 0x80046003;	///< SoftCrypto: RsaPublicDecrypt, decrypt unsuccessful
const unsigned long Soft_MemoryError			= 0x80046004;	///< SoftCrypto: Memory error
const unsigned long Soft_RsaKeyNotSet			= 0x80046005;	///< SoftCrypto: Rsa keypair not set
const unsigned long Soft_DesKeyNotSet			= 0x80046006;	///< SoftCrypto: Des key not set
const unsigned long Soft_HexInputError			= 0x80046007;	///< SoftCrypto: Hex input insufficient
const unsigned long Soft_DecryptError			= 0x80046008;	///< SoftCrypto: Decryption error
const unsigned long Soft_PaddingError			= 0x80046009;	///< SoftCrypto: Error unpadding data

// MS
const unsigned long Soft_MsAcquireContext		= 0x80046100;	///< SoftCrypto: Unable to acquire context to Microsoft Enhanced provider
const unsigned long Soft_MsKeyGenerate			= 0x80046101;	///< SoftCrypto: Key Generation failed
const unsigned long Soft_MsUserKey				= 0x80046102;	///< SoftCrypto: Failed to get handle on the user exchange key
const unsigned long Soft_MsExportKey			= 0x80046103;	///< SoftCrypto: Export key failed
const unsigned long Soft_MsDecryptKey			= 0x80046104;	///< SoftCrypto: Decrypt key failed

// PBE
const unsigned long Soft_PBEInvalidKeyType		= 0x80046150;	///< SoftCrypto: PBE invalid key type
const unsigned long Soft_PBEKeyGenError			= 0x80046151;	///< SoftCrypto: PBE key generate error

// Other
const unsigned long Soft_HashAlgorithmUnkown	= 0x80046200;	///< SoftCrypto: Unknown Hash Algorithm

} // namespace SoftCryptoLib
