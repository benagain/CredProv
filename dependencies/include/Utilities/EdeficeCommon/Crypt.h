#pragma once
#if !defined(MOBILE)
#include "Utilities/EdeficeCommon/LeanWindows.h"
#include <wincrypt.h>
#elif !defined(__WINCRYPT_H__)
// define stuff from Windows
#define __WINCRYPT_H__
#include <stdint.h>

#ifndef CRYPTO_BLOBS_DEFINED
// check nothing else has included wincrypt.h
// data blob from wincrypt.h
struct DATA_BLOB
{
	uint32_t		cbData;
	unsigned char*	pbData;
};
#endif

#define AT_KEYEXCHANGE          1
#define AT_SIGNATURE            2

#ifndef ALG_CLASS_KEY_EXCHANGE
#define ALG_CLASS_KEY_EXCHANGE          (5 << 13)
#define ALG_CLASS_SIGNATURE             (1 << 13)
#define ALG_TYPE_RSA                    (2 << 9)
#define ALG_TYPE_DH                     (5 << 9)
#define ALG_SID_RSA_ANY                 0
#define ALG_SID_ECDH                    5
#define CALG_RSA_SIGN           (ALG_CLASS_SIGNATURE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_RSA_KEYX           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_ECDH               (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_ECDH)

#define PUBLICKEYBLOB           0x6
#define PRIVATEKEYBLOB          0x7
#define CUR_BLOB_VERSION        2
#endif

#ifndef ALGIDDEF
#define ALGIDDEF

typedef uint32_t ALG_ID;
struct PUBLICKEYSTRUC
{
	uint8_t			bType;
	uint8_t			bVersion;
	uint16_t		reserved;
	ALG_ID			aiKeyAlg;
};

struct RSAPUBKEY
{
	uint32_t		magic;		///< Has to be RSA1
	uint32_t		bitlen;		/// # of bits in modulus
	uint32_t		pubexp;		///< public exponent
								// Modulus data follows
};
#endif

#ifndef BCRYPT_RSAPUBLIC_MAGIC
#define BCRYPT_RSAPUBLIC_MAGIC      0x31415352  // RSA1
#define BCRYPT_RSAPRIVATE_MAGIC     0x32415352  // RSA2
#endif

#endif
