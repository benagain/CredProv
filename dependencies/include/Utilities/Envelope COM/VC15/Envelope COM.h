

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\Envelope COM\Envelope COM.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Envelope_COM_h__
#define __Envelope_COM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICryptoProvider_FWD_DEFINED__
#define __ICryptoProvider_FWD_DEFINED__
typedef interface ICryptoProvider ICryptoProvider;

#endif 	/* __ICryptoProvider_FWD_DEFINED__ */


#ifndef __ICryptoProvider2_FWD_DEFINED__
#define __ICryptoProvider2_FWD_DEFINED__
typedef interface ICryptoProvider2 ICryptoProvider2;

#endif 	/* __ICryptoProvider2_FWD_DEFINED__ */


#ifndef __ICryptoManager_FWD_DEFINED__
#define __ICryptoManager_FWD_DEFINED__
typedef interface ICryptoManager ICryptoManager;

#endif 	/* __ICryptoManager_FWD_DEFINED__ */


#ifndef __ICryptoManager2_FWD_DEFINED__
#define __ICryptoManager2_FWD_DEFINED__
typedef interface ICryptoManager2 ICryptoManager2;

#endif 	/* __ICryptoManager2_FWD_DEFINED__ */


#ifndef __IEnvelope_FWD_DEFINED__
#define __IEnvelope_FWD_DEFINED__
typedef interface IEnvelope IEnvelope;

#endif 	/* __IEnvelope_FWD_DEFINED__ */


#ifndef __IEnvelope2_FWD_DEFINED__
#define __IEnvelope2_FWD_DEFINED__
typedef interface IEnvelope2 IEnvelope2;

#endif 	/* __IEnvelope2_FWD_DEFINED__ */


#ifndef __IEnvelope3_FWD_DEFINED__
#define __IEnvelope3_FWD_DEFINED__
typedef interface IEnvelope3 IEnvelope3;

#endif 	/* __IEnvelope3_FWD_DEFINED__ */


#ifndef __IEnvelope4_FWD_DEFINED__
#define __IEnvelope4_FWD_DEFINED__
typedef interface IEnvelope4 IEnvelope4;

#endif 	/* __IEnvelope4_FWD_DEFINED__ */


#ifndef __ICryptoHelper_FWD_DEFINED__
#define __ICryptoHelper_FWD_DEFINED__
typedef interface ICryptoHelper ICryptoHelper;

#endif 	/* __ICryptoHelper_FWD_DEFINED__ */


#ifndef __ICryptoHelper2_FWD_DEFINED__
#define __ICryptoHelper2_FWD_DEFINED__
typedef interface ICryptoHelper2 ICryptoHelper2;

#endif 	/* __ICryptoHelper2_FWD_DEFINED__ */


#ifndef __Envelope_FWD_DEFINED__
#define __Envelope_FWD_DEFINED__

#ifdef __cplusplus
typedef class Envelope Envelope;
#else
typedef struct Envelope Envelope;
#endif /* __cplusplus */

#endif 	/* __Envelope_FWD_DEFINED__ */


#ifndef __Envelope2_FWD_DEFINED__
#define __Envelope2_FWD_DEFINED__

#ifdef __cplusplus
typedef class Envelope2 Envelope2;
#else
typedef struct Envelope2 Envelope2;
#endif /* __cplusplus */

#endif 	/* __Envelope2_FWD_DEFINED__ */


#ifndef __CryptoHelper_FWD_DEFINED__
#define __CryptoHelper_FWD_DEFINED__

#ifdef __cplusplus
typedef class CryptoHelper CryptoHelper;
#else
typedef struct CryptoHelper CryptoHelper;
#endif /* __cplusplus */

#endif 	/* __CryptoHelper_FWD_DEFINED__ */


#ifndef __SoftwareCrypto_FWD_DEFINED__
#define __SoftwareCrypto_FWD_DEFINED__

#ifdef __cplusplus
typedef class SoftwareCrypto SoftwareCrypto;
#else
typedef struct SoftwareCrypto SoftwareCrypto;
#endif /* __cplusplus */

#endif 	/* __SoftwareCrypto_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICryptoProvider_INTERFACE_DEFINED__
#define __ICryptoProvider_INTERFACE_DEFINED__

/* interface ICryptoProvider */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [helpstring] */ 
enum tagESignatureType
    {
        PT_Unknown	= 0,
        PT_Device	= 1,
        PT_Software	= 2,
        PT_Server	= 3
    } 	ESignatureType;


EXTERN_C const IID IID_ICryptoProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACFE951D-E2B6-48F4-84AD-67F16E42029D")
    ICryptoProvider : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ BSTR bstrClearText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrCipherText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ BSTR bstrCipherText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrClearText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrSigBlock) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSigBlock) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptEx( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrClearText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEx( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrSigBlock) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignatureType( 
            /* [retval][out] */ ESignatureType *eType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoProvider * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            ICryptoProvider * This,
            /* [in] */ BSTR bstrClearText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrCipherText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            ICryptoProvider * This,
            /* [in] */ BSTR bstrCipherText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrClearText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            ICryptoProvider * This,
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            ICryptoProvider * This,
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptEx )( 
            ICryptoProvider * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrClearText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEx )( 
            ICryptoProvider * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignatureType )( 
            ICryptoProvider * This,
            /* [retval][out] */ ESignatureType *eType);
        
        END_INTERFACE
    } ICryptoProviderVtbl;

    interface ICryptoProvider
    {
        CONST_VTBL struct ICryptoProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoProvider_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoProvider_Encrypt(This,bstrClearText,bstrSN,bstrKeyName,bstrCipherText)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrClearText,bstrSN,bstrKeyName,bstrCipherText) ) 

#define ICryptoProvider_Decrypt(This,bstrCipherText,bstrSN,bstrKeyName,bstrClearText)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrCipherText,bstrSN,bstrKeyName,bstrClearText) ) 

#define ICryptoProvider_Sign(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock)	\
    ( (This)->lpVtbl -> Sign(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock) ) 

#define ICryptoProvider_Verify(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock)	\
    ( (This)->lpVtbl -> Verify(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock) ) 

#define ICryptoProvider_DecryptEx(This,xmlInput,bstrClearText)	\
    ( (This)->lpVtbl -> DecryptEx(This,xmlInput,bstrClearText) ) 

#define ICryptoProvider_SignEx(This,xmlInput,bstrSigBlock)	\
    ( (This)->lpVtbl -> SignEx(This,xmlInput,bstrSigBlock) ) 

#define ICryptoProvider_SignatureType(This,eType)	\
    ( (This)->lpVtbl -> SignatureType(This,eType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoProvider_INTERFACE_DEFINED__ */


#ifndef __ICryptoProvider2_INTERFACE_DEFINED__
#define __ICryptoProvider2_INTERFACE_DEFINED__

/* interface ICryptoProvider2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICryptoProvider2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1728FC0B-C2AD-4511-B7BA-65445EDBBBDD")
    ICryptoProvider2 : public ICryptoProvider
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEnvelopeVersions( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastEnvelopeVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastEnvelopeVersion( 
            /* [in] */ BSTR Val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastSignatureHashAlgorithm( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastSignatureHashAlgorithm( 
            /* [in] */ BSTR Val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastSignatureAlgorithm( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastSignatureAlgorithm( 
            /* [in] */ BSTR Val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastEncryptionAlgorithm( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastEncryptionAlgorithm( 
            /* [in] */ BSTR Val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoProvider2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoProvider2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoProvider2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoProvider2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoProvider2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoProvider2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoProvider2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoProvider2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR bstrClearText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrCipherText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR bstrCipherText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrClearText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [retval][out] */ BSTR *bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR bstrText,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptEx )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrClearText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEx )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrSigBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignatureType )( 
            ICryptoProvider2 * This,
            /* [retval][out] */ ESignatureType *eType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetEnvelopeVersions )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastEnvelopeVersion )( 
            ICryptoProvider2 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastEnvelopeVersion )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR Val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastSignatureHashAlgorithm )( 
            ICryptoProvider2 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastSignatureHashAlgorithm )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR Val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastSignatureAlgorithm )( 
            ICryptoProvider2 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastSignatureAlgorithm )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR Val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastEncryptionAlgorithm )( 
            ICryptoProvider2 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastEncryptionAlgorithm )( 
            ICryptoProvider2 * This,
            /* [in] */ BSTR Val);
        
        END_INTERFACE
    } ICryptoProvider2Vtbl;

    interface ICryptoProvider2
    {
        CONST_VTBL struct ICryptoProvider2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoProvider2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoProvider2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoProvider2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoProvider2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoProvider2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoProvider2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoProvider2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoProvider2_Encrypt(This,bstrClearText,bstrSN,bstrKeyName,bstrCipherText)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrClearText,bstrSN,bstrKeyName,bstrCipherText) ) 

#define ICryptoProvider2_Decrypt(This,bstrCipherText,bstrSN,bstrKeyName,bstrClearText)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrCipherText,bstrSN,bstrKeyName,bstrClearText) ) 

#define ICryptoProvider2_Sign(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock)	\
    ( (This)->lpVtbl -> Sign(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock) ) 

#define ICryptoProvider2_Verify(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock)	\
    ( (This)->lpVtbl -> Verify(This,bstrText,bstrSN,bstrKeyName,bstrSigBlock) ) 

#define ICryptoProvider2_DecryptEx(This,xmlInput,bstrClearText)	\
    ( (This)->lpVtbl -> DecryptEx(This,xmlInput,bstrClearText) ) 

#define ICryptoProvider2_SignEx(This,xmlInput,bstrSigBlock)	\
    ( (This)->lpVtbl -> SignEx(This,xmlInput,bstrSigBlock) ) 

#define ICryptoProvider2_SignatureType(This,eType)	\
    ( (This)->lpVtbl -> SignatureType(This,eType) ) 


#define ICryptoProvider2_SetEnvelopeVersions(This,xmlInput,xmlOut)	\
    ( (This)->lpVtbl -> SetEnvelopeVersions(This,xmlInput,xmlOut) ) 

#define ICryptoProvider2_get_LastEnvelopeVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_LastEnvelopeVersion(This,pVal) ) 

#define ICryptoProvider2_put_LastEnvelopeVersion(This,Val)	\
    ( (This)->lpVtbl -> put_LastEnvelopeVersion(This,Val) ) 

#define ICryptoProvider2_get_LastSignatureHashAlgorithm(This,pVal)	\
    ( (This)->lpVtbl -> get_LastSignatureHashAlgorithm(This,pVal) ) 

#define ICryptoProvider2_put_LastSignatureHashAlgorithm(This,Val)	\
    ( (This)->lpVtbl -> put_LastSignatureHashAlgorithm(This,Val) ) 

#define ICryptoProvider2_get_LastSignatureAlgorithm(This,pVal)	\
    ( (This)->lpVtbl -> get_LastSignatureAlgorithm(This,pVal) ) 

#define ICryptoProvider2_put_LastSignatureAlgorithm(This,Val)	\
    ( (This)->lpVtbl -> put_LastSignatureAlgorithm(This,Val) ) 

#define ICryptoProvider2_get_LastEncryptionAlgorithm(This,pVal)	\
    ( (This)->lpVtbl -> get_LastEncryptionAlgorithm(This,pVal) ) 

#define ICryptoProvider2_put_LastEncryptionAlgorithm(This,Val)	\
    ( (This)->lpVtbl -> put_LastEncryptionAlgorithm(This,Val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoProvider2_INTERFACE_DEFINED__ */


#ifndef __ICryptoManager_INTERFACE_DEFINED__
#define __ICryptoManager_INTERFACE_DEFINED__

/* interface ICryptoManager */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICryptoManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0E4AD63-C588-44c1-BA02-8CD47D022B6E")
    ICryptoManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateKey( 
            /* [in] */ const BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrPublicKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKey( 
            /* [in] */ const BSTR bstrPublicKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ICryptoManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateKey )( 
            ICryptoManager * This,
            /* [in] */ const BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrPublicKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKey )( 
            ICryptoManager * This,
            /* [in] */ const BSTR bstrPublicKey);
        
        END_INTERFACE
    } ICryptoManagerVtbl;

    interface ICryptoManager
    {
        CONST_VTBL struct ICryptoManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoManager_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ICryptoManager_GenerateKey(This,xmlInput,bstrPublicKey)	\
    ( (This)->lpVtbl -> GenerateKey(This,xmlInput,bstrPublicKey) ) 

#define ICryptoManager_SetKey(This,bstrPublicKey)	\
    ( (This)->lpVtbl -> SetKey(This,bstrPublicKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoManager_INTERFACE_DEFINED__ */


#ifndef __ICryptoManager2_INTERFACE_DEFINED__
#define __ICryptoManager2_INTERFACE_DEFINED__

/* interface ICryptoManager2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICryptoManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1BA6A0A9-425E-4A5C-BD7F-DA64FFBC2ABE")
    ICryptoManager2 : public ICryptoManager
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportKey( 
            /* [in] */ const BSTR bstrPrivateKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoManager2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoManager2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoManager2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoManager2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoManager2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            ICryptoManager2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateKey )( 
            ICryptoManager2 * This,
            /* [in] */ const BSTR xmlInput,
            /* [retval][out] */ BSTR *bstrPublicKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKey )( 
            ICryptoManager2 * This,
            /* [in] */ const BSTR bstrPublicKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportKey )( 
            ICryptoManager2 * This,
            /* [in] */ const BSTR bstrPrivateKey);
        
        END_INTERFACE
    } ICryptoManager2Vtbl;

    interface ICryptoManager2
    {
        CONST_VTBL struct ICryptoManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoManager2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoManager2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoManager2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoManager2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoManager2_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ICryptoManager2_GenerateKey(This,xmlInput,bstrPublicKey)	\
    ( (This)->lpVtbl -> GenerateKey(This,xmlInput,bstrPublicKey) ) 

#define ICryptoManager2_SetKey(This,bstrPublicKey)	\
    ( (This)->lpVtbl -> SetKey(This,bstrPublicKey) ) 


#define ICryptoManager2_ImportKey(This,bstrPrivateKey)	\
    ( (This)->lpVtbl -> ImportKey(This,bstrPrivateKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoManager2_INTERFACE_DEFINED__ */


#ifndef __IEnvelope_INTERFACE_DEFINED__
#define __IEnvelope_INTERFACE_DEFINED__

/* interface IEnvelope */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnvelope;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9952091F-1CF0-4BBF-BFAF-3BD07F6067FE")
    IEnvelope : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEncrypt( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptVerify( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( 
            /* [in] */ BSTR bstrDataIn,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnEnvelope( 
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnvelopeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnvelope * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnvelope * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnvelope * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnvelope * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnvelope * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnvelope * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnvelope * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncrypt )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerify )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrDataIn,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnEnvelope )( 
            IEnvelope * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        END_INTERFACE
    } IEnvelopeVtbl;

    interface IEnvelope
    {
        CONST_VTBL struct IEnvelopeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnvelope_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnvelope_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnvelope_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnvelope_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnvelope_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnvelope_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnvelope_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnvelope_Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrEnvelope)	\
    ( (This)->lpVtbl -> Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrEnvelope) ) 

#define IEnvelope_Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrEnvelope)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrEnvelope) ) 

#define IEnvelope_SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrEnvelope) ) 

#define IEnvelope_Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope_Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope_DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope_Clear(This,bstrDataIn,bstrEnvelope)	\
    ( (This)->lpVtbl -> Clear(This,bstrDataIn,bstrEnvelope) ) 

#define IEnvelope_UnEnvelope(This,bstrEnvelope,bstrDataOut)	\
    ( (This)->lpVtbl -> UnEnvelope(This,bstrEnvelope,bstrDataOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnvelope_INTERFACE_DEFINED__ */


#ifndef __IEnvelope2_INTERFACE_DEFINED__
#define __IEnvelope2_INTERFACE_DEFINED__

/* interface IEnvelope2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnvelope2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2FE85BB7-8FA6-4FCA-AFAC-2932D7FBA411")
    IEnvelope2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEncrypt( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptVerify( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnEnvelope( 
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEx( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnk,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptEx( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptVerifyEx( 
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEncryptEx( 
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignID( 
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncryptID( 
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignEncryptID( 
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ const BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ const BSTR bstrEncryptKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearID( 
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnvelope2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnvelope2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnvelope2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnvelope2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnvelope2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnvelope2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnvelope2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnvelope2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncrypt )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerify )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnEnvelope )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEx )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnk,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptEx )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerifyEx )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptEx )( 
            IEnvelope2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignID )( 
            IEnvelope2 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptID )( 
            IEnvelope2 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptID )( 
            IEnvelope2 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ const BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ const BSTR bstrEncryptKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearID )( 
            IEnvelope2 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        END_INTERFACE
    } IEnvelope2Vtbl;

    interface IEnvelope2
    {
        CONST_VTBL struct IEnvelope2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnvelope2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnvelope2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnvelope2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnvelope2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnvelope2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnvelope2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnvelope2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnvelope2_Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope2_Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope2_SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope2_Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope2_Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope2_DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope2_Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope2_UnEnvelope(This,bstrEnvelope,bstrDataOut)	\
    ( (This)->lpVtbl -> UnEnvelope(This,bstrEnvelope,bstrDataOut) ) 

#define IEnvelope2_SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope) ) 

#define IEnvelope2_DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut) ) 

#define IEnvelope2_DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut) ) 

#define IEnvelope2_SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope) ) 

#define IEnvelope2_SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope2_EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope2_SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope2_ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnvelope2_INTERFACE_DEFINED__ */


#ifndef __IEnvelope3_INTERFACE_DEFINED__
#define __IEnvelope3_INTERFACE_DEFINED__

/* interface IEnvelope3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnvelope3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2A73594-0238-456D-9F35-5442C1D9D3DA")
    IEnvelope3 : public IEnvelope2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NegotiateEnvelopeVersions( 
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnvelope3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnvelope3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnvelope3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnvelope3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnvelope3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnvelope3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnvelope3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnvelope3 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncrypt )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerify )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnEnvelope )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEx )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnk,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptEx )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerifyEx )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptEx )( 
            IEnvelope3 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignID )( 
            IEnvelope3 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptID )( 
            IEnvelope3 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptID )( 
            IEnvelope3 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ const BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ const BSTR bstrEncryptKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearID )( 
            IEnvelope3 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NegotiateEnvelopeVersions )( 
            IEnvelope3 * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        END_INTERFACE
    } IEnvelope3Vtbl;

    interface IEnvelope3
    {
        CONST_VTBL struct IEnvelope3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnvelope3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnvelope3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnvelope3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnvelope3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnvelope3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnvelope3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnvelope3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnvelope3_Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope3_Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope3_SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope3_Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope3_Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope3_DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope3_Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope3_UnEnvelope(This,bstrEnvelope,bstrDataOut)	\
    ( (This)->lpVtbl -> UnEnvelope(This,bstrEnvelope,bstrDataOut) ) 

#define IEnvelope3_SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope) ) 

#define IEnvelope3_DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut) ) 

#define IEnvelope3_DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut) ) 

#define IEnvelope3_SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope) ) 

#define IEnvelope3_SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope3_EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope3_SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope3_ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 


#define IEnvelope3_NegotiateEnvelopeVersions(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> NegotiateEnvelopeVersions(This,xmlIn,xmlOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnvelope3_INTERFACE_DEFINED__ */


#ifndef __IEnvelope4_INTERFACE_DEFINED__
#define __IEnvelope4_INTERFACE_DEFINED__

/* interface IEnvelope4 */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [public][public][v1_enum] */ 
enum __MIDL_IEnvelope4_0001
    {
        EnvelopeFormat_Unknown	= 0,
        EnvelopeFormat_Clear	= ( EnvelopeFormat_Unknown + 1 ) ,
        EnvelopeFormat_Sign	= ( EnvelopeFormat_Clear + 1 ) ,
        EnvelopeFormat_Encrypt	= ( EnvelopeFormat_Sign + 1 ) ,
        EnvelopeFormat_SignEncrypt	= ( EnvelopeFormat_Encrypt + 1 ) 
    } 	EnvelopeFormat;


EXTERN_C const IID IID_IEnvelope4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC13E055-E8F5-4915-89E4-26C3FB75D4BB")
    IEnvelope4 : public IEnvelope3
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEnvelopeFormat( 
            /* [in] */ BSTR inputData,
            /* [retval][out] */ EnvelopeFormat *envelopeFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEnvelopeVersion( 
            /* [in] */ BSTR inputData,
            /* [retval][out] */ BSTR *envelopeVersion) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnvelope4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnvelope4 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnvelope4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnvelope4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnvelope4 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnvelope4 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnvelope4 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnvelope4 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncrypt )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerify )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [in] */ BSTR bstrEncryptKeyName,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeviceType,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnEnvelope )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEx )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnk,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptEx )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptVerifyEx )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrEnvelope,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkVerifier,
            /* [in] */ IUnknown *pUnkDecryptor,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptEx )( 
            IEnvelope4 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [in] */ BSTR xmlIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignID )( 
            IEnvelope4 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptID )( 
            IEnvelope4 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnk,
            /* [in] */ const BSTR bstrKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignEncryptID )( 
            IEnvelope4 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ IUnknown *pUnkSigner,
            /* [in] */ const BSTR bstrSignKeyName,
            /* [in] */ IUnknown *pUnkEncryptor,
            /* [in] */ const BSTR bstrEncryptKeyName,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearID )( 
            IEnvelope4 * This,
            /* [in] */ const BSTR bstrDataIn,
            /* [in] */ const BSTR bstrSN,
            /* [in] */ const BSTR bstrDeviceType,
            /* [in] */ const BSTR bstrSessionID,
            /* [retval][out] */ BSTR *bstrEnvelope);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NegotiateEnvelopeVersions )( 
            IEnvelope4 * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEnvelopeFormat )( 
            IEnvelope4 * This,
            /* [in] */ BSTR inputData,
            /* [retval][out] */ EnvelopeFormat *envelopeFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEnvelopeVersion )( 
            IEnvelope4 * This,
            /* [in] */ BSTR inputData,
            /* [retval][out] */ BSTR *envelopeVersion);
        
        END_INTERFACE
    } IEnvelope4Vtbl;

    interface IEnvelope4
    {
        CONST_VTBL struct IEnvelope4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnvelope4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnvelope4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnvelope4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnvelope4_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnvelope4_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnvelope4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnvelope4_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnvelope4_Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Sign(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope4_Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Encrypt(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope4_SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncrypt(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope4_Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Verify(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope4_Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> Decrypt(This,bstrEnvelope,pUnk,bstrKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope4_DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerify(This,bstrEnvelope,pUnkVerifier,bstrSignKeyName,pUnkDecryptor,bstrEncryptKeyName,bstrSN,bstrDataOut) ) 

#define IEnvelope4_Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope)	\
    ( (This)->lpVtbl -> Clear(This,bstrDataIn,bstrSN,bstrDeviceType,bstrEnvelope) ) 

#define IEnvelope4_UnEnvelope(This,bstrEnvelope,bstrDataOut)	\
    ( (This)->lpVtbl -> UnEnvelope(This,bstrEnvelope,bstrDataOut) ) 

#define IEnvelope4_SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEx(This,bstrDataIn,xmlIn,pUnk,bstrEnvelope) ) 

#define IEnvelope4_DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptEx(This,bstrEnvelope,pUnk,xmlIn,bstrDataOut) ) 

#define IEnvelope4_DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut)	\
    ( (This)->lpVtbl -> DecryptVerifyEx(This,bstrEnvelope,xmlIn,pUnkVerifier,pUnkDecryptor,bstrDataOut) ) 

#define IEnvelope4_SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptEx(This,bstrDataIn,xmlIn,pUnkSigner,pUnkEncryptor,bstrEnvelope) ) 

#define IEnvelope4_SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope4_EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> EncryptID(This,bstrDataIn,pUnk,bstrKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope4_SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> SignEncryptID(This,bstrDataIn,pUnkSigner,bstrSignKeyName,pUnkEncryptor,bstrEncryptKeyName,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 

#define IEnvelope4_ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope)	\
    ( (This)->lpVtbl -> ClearID(This,bstrDataIn,bstrSN,bstrDeviceType,bstrSessionID,bstrEnvelope) ) 


#define IEnvelope4_NegotiateEnvelopeVersions(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> NegotiateEnvelopeVersions(This,xmlIn,xmlOut) ) 


#define IEnvelope4_GetEnvelopeFormat(This,inputData,envelopeFormat)	\
    ( (This)->lpVtbl -> GetEnvelopeFormat(This,inputData,envelopeFormat) ) 

#define IEnvelope4_GetEnvelopeVersion(This,inputData,envelopeVersion)	\
    ( (This)->lpVtbl -> GetEnvelopeVersion(This,inputData,envelopeVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnvelope4_INTERFACE_DEFINED__ */


#ifndef __ICryptoHelper_INTERFACE_DEFINED__
#define __ICryptoHelper_INTERFACE_DEFINED__

/* interface ICryptoHelper */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICryptoHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D1D21DF8-C0EC-4FD3-A4ED-D3391D323EF6")
    ICryptoHelper : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifyKeyCheckValue( 
            /* [in] */ BSTR bstrParametersXML,
            /* [in] */ BSTR bstrKeyToCheck,
            /* [in] */ BSTR bstrKeyCheckValue,
            /* [retval][out] */ VARIANT_BOOL *bVerify) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoHelper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoHelper * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifyKeyCheckValue )( 
            ICryptoHelper * This,
            /* [in] */ BSTR bstrParametersXML,
            /* [in] */ BSTR bstrKeyToCheck,
            /* [in] */ BSTR bstrKeyCheckValue,
            /* [retval][out] */ VARIANT_BOOL *bVerify);
        
        END_INTERFACE
    } ICryptoHelperVtbl;

    interface ICryptoHelper
    {
        CONST_VTBL struct ICryptoHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoHelper_VerifyKeyCheckValue(This,bstrParametersXML,bstrKeyToCheck,bstrKeyCheckValue,bVerify)	\
    ( (This)->lpVtbl -> VerifyKeyCheckValue(This,bstrParametersXML,bstrKeyToCheck,bstrKeyCheckValue,bVerify) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoHelper_INTERFACE_DEFINED__ */


#ifndef __ICryptoHelper2_INTERFACE_DEFINED__
#define __ICryptoHelper2_INTERFACE_DEFINED__

/* interface ICryptoHelper2 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICryptoHelper2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2572BF87-5997-4be6-B327-C159B24A89BF")
    ICryptoHelper2 : public ICryptoHelper
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCapabilities( 
            /* [retval][out] */ BSTR *bstrOutData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hash( 
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrHashAlgorithm,
            /* [in] */ BSTR bstrInputFormat,
            /* [retval][out] */ BSTR *bstrOutData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MultiHash( 
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrHashAlgorithm,
            /* [in] */ BSTR bstrInputFormat,
            /* [in] */ LONG lHashIterations,
            /* [retval][out] */ BSTR *bstrOutData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MakePwd( 
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrSalt,
            /* [in] */ BSTR bstrPwdAlgorithm,
            /* [retval][out] */ BSTR *bstrOutData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MakeAuthString( 
            /* [in] */ BSTR bstrInputDataXMLut,
            /* [in] */ BSTR bstrPersonSalt,
            /* [in] */ BSTR bstrSessionSalt,
            /* [in] */ BSTR bstrAuthAlgorithm,
            /* [retval][out] */ BSTR *bstrOutData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoHelper2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICryptoHelper2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICryptoHelper2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICryptoHelper2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICryptoHelper2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICryptoHelper2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICryptoHelper2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICryptoHelper2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifyKeyCheckValue )( 
            ICryptoHelper2 * This,
            /* [in] */ BSTR bstrParametersXML,
            /* [in] */ BSTR bstrKeyToCheck,
            /* [in] */ BSTR bstrKeyCheckValue,
            /* [retval][out] */ VARIANT_BOOL *bVerify);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCapabilities )( 
            ICryptoHelper2 * This,
            /* [retval][out] */ BSTR *bstrOutData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hash )( 
            ICryptoHelper2 * This,
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrHashAlgorithm,
            /* [in] */ BSTR bstrInputFormat,
            /* [retval][out] */ BSTR *bstrOutData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MultiHash )( 
            ICryptoHelper2 * This,
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrHashAlgorithm,
            /* [in] */ BSTR bstrInputFormat,
            /* [in] */ LONG lHashIterations,
            /* [retval][out] */ BSTR *bstrOutData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MakePwd )( 
            ICryptoHelper2 * This,
            /* [in] */ BSTR bstrInputData,
            /* [in] */ BSTR bstrSalt,
            /* [in] */ BSTR bstrPwdAlgorithm,
            /* [retval][out] */ BSTR *bstrOutData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MakeAuthString )( 
            ICryptoHelper2 * This,
            /* [in] */ BSTR bstrInputDataXMLut,
            /* [in] */ BSTR bstrPersonSalt,
            /* [in] */ BSTR bstrSessionSalt,
            /* [in] */ BSTR bstrAuthAlgorithm,
            /* [retval][out] */ BSTR *bstrOutData);
        
        END_INTERFACE
    } ICryptoHelper2Vtbl;

    interface ICryptoHelper2
    {
        CONST_VTBL struct ICryptoHelper2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICryptoHelper2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICryptoHelper2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICryptoHelper2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICryptoHelper2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICryptoHelper2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICryptoHelper2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICryptoHelper2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICryptoHelper2_VerifyKeyCheckValue(This,bstrParametersXML,bstrKeyToCheck,bstrKeyCheckValue,bVerify)	\
    ( (This)->lpVtbl -> VerifyKeyCheckValue(This,bstrParametersXML,bstrKeyToCheck,bstrKeyCheckValue,bVerify) ) 


#define ICryptoHelper2_GetCapabilities(This,bstrOutData)	\
    ( (This)->lpVtbl -> GetCapabilities(This,bstrOutData) ) 

#define ICryptoHelper2_Hash(This,bstrInputData,bstrHashAlgorithm,bstrInputFormat,bstrOutData)	\
    ( (This)->lpVtbl -> Hash(This,bstrInputData,bstrHashAlgorithm,bstrInputFormat,bstrOutData) ) 

#define ICryptoHelper2_MultiHash(This,bstrInputData,bstrHashAlgorithm,bstrInputFormat,lHashIterations,bstrOutData)	\
    ( (This)->lpVtbl -> MultiHash(This,bstrInputData,bstrHashAlgorithm,bstrInputFormat,lHashIterations,bstrOutData) ) 

#define ICryptoHelper2_MakePwd(This,bstrInputData,bstrSalt,bstrPwdAlgorithm,bstrOutData)	\
    ( (This)->lpVtbl -> MakePwd(This,bstrInputData,bstrSalt,bstrPwdAlgorithm,bstrOutData) ) 

#define ICryptoHelper2_MakeAuthString(This,bstrInputDataXMLut,bstrPersonSalt,bstrSessionSalt,bstrAuthAlgorithm,bstrOutData)	\
    ( (This)->lpVtbl -> MakeAuthString(This,bstrInputDataXMLut,bstrPersonSalt,bstrSessionSalt,bstrAuthAlgorithm,bstrOutData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICryptoHelper2_INTERFACE_DEFINED__ */



#ifndef __ENVELOPECOMLib_LIBRARY_DEFINED__
#define __ENVELOPECOMLib_LIBRARY_DEFINED__

/* library ENVELOPECOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ENVELOPECOMLib;

EXTERN_C const CLSID CLSID_Envelope;

#ifdef __cplusplus

class DECLSPEC_UUID("994B0A5E-26AA-446F-9FA5-F4CEE3B9EEEF")
Envelope;
#endif

EXTERN_C const CLSID CLSID_Envelope2;

#ifdef __cplusplus

class DECLSPEC_UUID("55D5006F-17DA-47E5-B0A9-E035067A0593")
Envelope2;
#endif

EXTERN_C const CLSID CLSID_CryptoHelper;

#ifdef __cplusplus

class DECLSPEC_UUID("AC5DDB1F-3834-4624-8DB3-9F9202E6E638")
CryptoHelper;
#endif

EXTERN_C const CLSID CLSID_SoftwareCrypto;

#ifdef __cplusplus

class DECLSPEC_UUID("0FBFC5DE-CE2E-4951-B66B-7B7A38087DD9")
SoftwareCrypto;
#endif
#endif /* __ENVELOPECOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


