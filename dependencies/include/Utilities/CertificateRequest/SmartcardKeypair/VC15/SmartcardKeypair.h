

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\CertificateRequest\SmartcardKeypair\SmartcardKeypair.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __SmartcardKeypair_h__
#define __SmartcardKeypair_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __SmartcardKeypair_FWD_DEFINED__
#define __SmartcardKeypair_FWD_DEFINED__

#ifdef __cplusplus
typedef class SmartcardKeypair SmartcardKeypair;
#else
typedef struct SmartcardKeypair SmartcardKeypair;
#endif /* __cplusplus */

#endif 	/* __SmartcardKeypair_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Keypair.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SMARTCARDKEYPAIRLib_LIBRARY_DEFINED__
#define __SMARTCARDKEYPAIRLib_LIBRARY_DEFINED__

/* library SMARTCARDKEYPAIRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SMARTCARDKEYPAIRLib;

EXTERN_C const CLSID CLSID_SmartcardKeypair;

#ifdef __cplusplus

class DECLSPEC_UUID("1AF901A7-F3FC-4441-B41F-C06F078C0031")
SmartcardKeypair;
#endif
#endif /* __SMARTCARDKEYPAIRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


