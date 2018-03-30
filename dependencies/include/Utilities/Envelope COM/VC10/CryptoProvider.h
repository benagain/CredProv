

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:01:00 2018
 */
/* Compiler settings for ..\..\Envelope COM\CryptoProvider.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CryptoProvider_h__
#define __CryptoProvider_h__

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
    {	PT_Unknown	= 0,
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
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


