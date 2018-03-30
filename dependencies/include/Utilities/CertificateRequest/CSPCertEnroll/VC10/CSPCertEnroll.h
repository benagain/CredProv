

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:00:55 2018
 */
/* Compiler settings for ..\..\CertificateRequest\CSPCertEnroll\CSPCertEnroll.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CSPCertEnroll_h__
#define __CSPCertEnroll_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CSPCertEnrollArchivable_FWD_DEFINED__
#define __CSPCertEnrollArchivable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSPCertEnrollArchivable CSPCertEnrollArchivable;
#else
typedef struct CSPCertEnrollArchivable CSPCertEnrollArchivable;
#endif /* __cplusplus */

#endif 	/* __CSPCertEnrollArchivable_FWD_DEFINED__ */


#ifndef __CSPLowLevelCertEnroll_FWD_DEFINED__
#define __CSPLowLevelCertEnroll_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSPLowLevelCertEnroll CSPLowLevelCertEnroll;
#else
typedef struct CSPLowLevelCertEnroll CSPLowLevelCertEnroll;
#endif /* __cplusplus */

#endif 	/* __CSPLowLevelCertEnroll_FWD_DEFINED__ */


#ifndef __DualCSPCertEnroll_FWD_DEFINED__
#define __DualCSPCertEnroll_FWD_DEFINED__

#ifdef __cplusplus
typedef class DualCSPCertEnroll DualCSPCertEnroll;
#else
typedef struct DualCSPCertEnroll DualCSPCertEnroll;
#endif /* __cplusplus */

#endif 	/* __DualCSPCertEnroll_FWD_DEFINED__ */


#ifndef __DualCSPCertEnrollP10Archive_FWD_DEFINED__
#define __DualCSPCertEnrollP10Archive_FWD_DEFINED__

#ifdef __cplusplus
typedef class DualCSPCertEnrollP10Archive DualCSPCertEnrollP10Archive;
#else
typedef struct DualCSPCertEnrollP10Archive DualCSPCertEnrollP10Archive;
#endif /* __cplusplus */

#endif 	/* __DualCSPCertEnrollP10Archive_FWD_DEFINED__ */


#ifndef __CSPCertEnrollP10_FWD_DEFINED__
#define __CSPCertEnrollP10_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSPCertEnrollP10 CSPCertEnrollP10;
#else
typedef struct CSPCertEnrollP10 CSPCertEnrollP10;
#endif /* __cplusplus */

#endif 	/* __CSPCertEnrollP10_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Keypair.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __CSPCERTENROLLLib_LIBRARY_DEFINED__
#define __CSPCERTENROLLLib_LIBRARY_DEFINED__

/* library CSPCERTENROLLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CSPCERTENROLLLib;

EXTERN_C const CLSID CLSID_CSPCertEnrollArchivable;

#ifdef __cplusplus

class DECLSPEC_UUID("4BC1B08A-26C1-4610-BFD4-2F5468EF0009")
CSPCertEnrollArchivable;
#endif

EXTERN_C const CLSID CLSID_CSPLowLevelCertEnroll;

#ifdef __cplusplus

class DECLSPEC_UUID("61CB7A57-4AF8-4CF9-8008-0EFA946DCADB")
CSPLowLevelCertEnroll;
#endif

EXTERN_C const CLSID CLSID_DualCSPCertEnroll;

#ifdef __cplusplus

class DECLSPEC_UUID("D02222C1-BC11-4473-8F7A-137973A3326D")
DualCSPCertEnroll;
#endif

EXTERN_C const CLSID CLSID_DualCSPCertEnrollP10Archive;

#ifdef __cplusplus

class DECLSPEC_UUID("DB0262AF-2F7A-4E31-A46D-9F3E7E31CA4A")
DualCSPCertEnrollP10Archive;
#endif

EXTERN_C const CLSID CLSID_CSPCertEnrollP10;

#ifdef __cplusplus

class DECLSPEC_UUID("5A03367E-AD30-4E5E-A9C6-05AD19D1DB8C")
CSPCertEnrollP10;
#endif
#endif /* __CSPCERTENROLLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


