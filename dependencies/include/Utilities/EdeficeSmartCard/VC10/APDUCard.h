

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:00:59 2018
 */
/* Compiler settings for ..\..\EdeficeSmartCard\APDUCard.idl:
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

#ifndef __APDUCard_h__
#define __APDUCard_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAPDUCard_FWD_DEFINED__
#define __IAPDUCard_FWD_DEFINED__
typedef interface IAPDUCard IAPDUCard;
#endif 	/* __IAPDUCard_FWD_DEFINED__ */


#ifndef __IAPDUProcessor_FWD_DEFINED__
#define __IAPDUProcessor_FWD_DEFINED__
typedef interface IAPDUProcessor IAPDUProcessor;
#endif 	/* __IAPDUProcessor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "eSCardCOM.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAPDUCard_INTERFACE_DEFINED__
#define __IAPDUCard_INTERFACE_DEFINED__

/* interface IAPDUCard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAPDUCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("432B48FF-9384-45a7-B227-C05525696A5E")
    IAPDUCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValid( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [out][in] */ ISCardCmd **pSCardCmd,
            /* [retval][out] */ unsigned short *pStatusWord) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _SetHandle( 
            /* [in] */ unsigned long Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _Invalidate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _SetHandle64( 
            /* [in] */ ULONG_PTR Val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAPDUCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAPDUCard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAPDUCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAPDUCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAPDUCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAPDUCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAPDUCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAPDUCard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValid )( 
            IAPDUCard * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IAPDUCard * This,
            /* [out][in] */ ISCardCmd **pSCardCmd,
            /* [retval][out] */ unsigned short *pStatusWord);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_SetHandle )( 
            IAPDUCard * This,
            /* [in] */ unsigned long Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_Invalidate )( 
            IAPDUCard * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *_SetHandle64 )( 
            IAPDUCard * This,
            /* [in] */ ULONG_PTR Val);
        
        END_INTERFACE
    } IAPDUCardVtbl;

    interface IAPDUCard
    {
        CONST_VTBL struct IAPDUCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAPDUCard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAPDUCard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAPDUCard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAPDUCard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAPDUCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAPDUCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAPDUCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAPDUCard_IsValid(This,pVal)	\
    ( (This)->lpVtbl -> IsValid(This,pVal) ) 

#define IAPDUCard_SendCommand(This,pSCardCmd,pStatusWord)	\
    ( (This)->lpVtbl -> SendCommand(This,pSCardCmd,pStatusWord) ) 

#define IAPDUCard__SetHandle(This,Val)	\
    ( (This)->lpVtbl -> _SetHandle(This,Val) ) 

#define IAPDUCard__Invalidate(This)	\
    ( (This)->lpVtbl -> _Invalidate(This) ) 

#define IAPDUCard__SetHandle64(This,Val)	\
    ( (This)->lpVtbl -> _SetHandle64(This,Val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAPDUCard_INTERFACE_DEFINED__ */


#ifndef __IAPDUProcessor_INTERFACE_DEFINED__
#define __IAPDUProcessor_INTERFACE_DEFINED__

/* interface IAPDUProcessor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAPDUProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("991B0EAF-4258-4dff-A05E-0FB695EEB38D")
    IAPDUProcessor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialise( 
            /* [in] */ IAPDUCard *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsInitialised( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessString( 
            /* [in] */ BSTR bstrDataToProcess,
            /* [retval][out] */ BSTR *bstrDataProcessed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Process( 
            /* [out][in] */ IUnknown **pObjectToProcess) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAPDUProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAPDUProcessor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAPDUProcessor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAPDUProcessor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAPDUProcessor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAPDUProcessor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAPDUProcessor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAPDUProcessor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialise )( 
            IAPDUProcessor * This,
            /* [in] */ IAPDUCard *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsInitialised )( 
            IAPDUProcessor * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessString )( 
            IAPDUProcessor * This,
            /* [in] */ BSTR bstrDataToProcess,
            /* [retval][out] */ BSTR *bstrDataProcessed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Process )( 
            IAPDUProcessor * This,
            /* [out][in] */ IUnknown **pObjectToProcess);
        
        END_INTERFACE
    } IAPDUProcessorVtbl;

    interface IAPDUProcessor
    {
        CONST_VTBL struct IAPDUProcessorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAPDUProcessor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAPDUProcessor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAPDUProcessor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAPDUProcessor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAPDUProcessor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAPDUProcessor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAPDUProcessor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAPDUProcessor_Initialise(This,pVal)	\
    ( (This)->lpVtbl -> Initialise(This,pVal) ) 

#define IAPDUProcessor_IsInitialised(This,pVal)	\
    ( (This)->lpVtbl -> IsInitialised(This,pVal) ) 

#define IAPDUProcessor_ProcessString(This,bstrDataToProcess,bstrDataProcessed)	\
    ( (This)->lpVtbl -> ProcessString(This,bstrDataToProcess,bstrDataProcessed) ) 

#define IAPDUProcessor_Process(This,pObjectToProcess)	\
    ( (This)->lpVtbl -> Process(This,pObjectToProcess) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAPDUProcessor_INTERFACE_DEFINED__ */


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


