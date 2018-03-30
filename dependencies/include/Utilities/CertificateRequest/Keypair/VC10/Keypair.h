

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:00:55 2018
 */
/* Compiler settings for ..\..\CertificateRequest\Keypair\Keypair.idl:
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

#ifndef __Keypair_h__
#define __Keypair_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IKeypair_FWD_DEFINED__
#define __IKeypair_FWD_DEFINED__
typedef interface IKeypair IKeypair;
#endif 	/* __IKeypair_FWD_DEFINED__ */


#ifndef __IDHProtectedKeyExchange_FWD_DEFINED__
#define __IDHProtectedKeyExchange_FWD_DEFINED__
typedef interface IDHProtectedKeyExchange IDHProtectedKeyExchange;
#endif 	/* __IDHProtectedKeyExchange_FWD_DEFINED__ */


#ifndef __IClientRSAProtectedKeyExchange_FWD_DEFINED__
#define __IClientRSAProtectedKeyExchange_FWD_DEFINED__
typedef interface IClientRSAProtectedKeyExchange IClientRSAProtectedKeyExchange;
#endif 	/* __IClientRSAProtectedKeyExchange_FWD_DEFINED__ */


#ifndef __ICertificateEnroll_FWD_DEFINED__
#define __ICertificateEnroll_FWD_DEFINED__
typedef interface ICertificateEnroll ICertificateEnroll;
#endif 	/* __ICertificateEnroll_FWD_DEFINED__ */


#ifndef __ICertificateEnroll_FWD_DEFINED__
#define __ICertificateEnroll_FWD_DEFINED__
typedef interface ICertificateEnroll ICertificateEnroll;
#endif 	/* __ICertificateEnroll_FWD_DEFINED__ */


#ifndef __IKeypair_FWD_DEFINED__
#define __IKeypair_FWD_DEFINED__
typedef interface IKeypair IKeypair;
#endif 	/* __IKeypair_FWD_DEFINED__ */


#ifndef __IDHProtectedKeyExchange_FWD_DEFINED__
#define __IDHProtectedKeyExchange_FWD_DEFINED__
typedef interface IDHProtectedKeyExchange IDHProtectedKeyExchange;
#endif 	/* __IDHProtectedKeyExchange_FWD_DEFINED__ */


#ifndef __IClientRSAProtectedKeyExchange_FWD_DEFINED__
#define __IClientRSAProtectedKeyExchange_FWD_DEFINED__
typedef interface IClientRSAProtectedKeyExchange IClientRSAProtectedKeyExchange;
#endif 	/* __IClientRSAProtectedKeyExchange_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IKeypair_INTERFACE_DEFINED__
#define __IKeypair_INTERFACE_DEFINED__

/* interface IKeypair */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IKeypair;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93D522A3-82A4-4514-832E-0BA04AE7616E")
    IKeypair : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Generate( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AcceptCertificate( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IKeypairVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKeypair * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKeypair * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKeypair * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IKeypair * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IKeypair * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IKeypair * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IKeypair * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Generate )( 
            IKeypair * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IKeypair * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptCertificate )( 
            IKeypair * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        END_INTERFACE
    } IKeypairVtbl;

    interface IKeypair
    {
        CONST_VTBL struct IKeypairVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKeypair_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKeypair_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKeypair_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKeypair_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IKeypair_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IKeypair_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IKeypair_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IKeypair_Generate(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> Generate(This,bstrXMLInput,bstrXMLOutput) ) 

#define IKeypair_Sign(This,bstrXMLInput,bstrOutput)	\
    ( (This)->lpVtbl -> Sign(This,bstrXMLInput,bstrOutput) ) 

#define IKeypair_AcceptCertificate(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> AcceptCertificate(This,bstrXMLInput,bstrXMLOutput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKeypair_INTERFACE_DEFINED__ */


#ifndef __IDHProtectedKeyExchange_INTERFACE_DEFINED__
#define __IDHProtectedKeyExchange_INTERFACE_DEFINED__

/* interface IDHProtectedKeyExchange */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDHProtectedKeyExchange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BEAB129-AC68-4d26-8D7C-EBFD756D15FE")
    IDHProtectedKeyExchange : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DHGenerateMasterKey( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DHExport( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DHImport( 
            /* [in] */ BSTR bstrXMLInput) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDHProtectedKeyExchangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDHProtectedKeyExchange * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDHProtectedKeyExchange * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDHProtectedKeyExchange * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DHGenerateMasterKey )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DHExport )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DHImport )( 
            IDHProtectedKeyExchange * This,
            /* [in] */ BSTR bstrXMLInput);
        
        END_INTERFACE
    } IDHProtectedKeyExchangeVtbl;

    interface IDHProtectedKeyExchange
    {
        CONST_VTBL struct IDHProtectedKeyExchangeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDHProtectedKeyExchange_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDHProtectedKeyExchange_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDHProtectedKeyExchange_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDHProtectedKeyExchange_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDHProtectedKeyExchange_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDHProtectedKeyExchange_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDHProtectedKeyExchange_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDHProtectedKeyExchange_DHGenerateMasterKey(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> DHGenerateMasterKey(This,bstrXMLInput,bstrXMLOutput) ) 

#define IDHProtectedKeyExchange_DHExport(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> DHExport(This,bstrXMLInput,bstrXMLOutput) ) 

#define IDHProtectedKeyExchange_DHImport(This,bstrXMLInput)	\
    ( (This)->lpVtbl -> DHImport(This,bstrXMLInput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDHProtectedKeyExchange_INTERFACE_DEFINED__ */


#ifndef __IClientRSAProtectedKeyExchange_INTERFACE_DEFINED__
#define __IClientRSAProtectedKeyExchange_INTERFACE_DEFINED__

/* interface IClientRSAProtectedKeyExchange */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IClientRSAProtectedKeyExchange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D16CE64-AF65-459a-A868-9156279E43CD")
    IClientRSAProtectedKeyExchange : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClientRSAExport( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClientRSAImport( 
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClientRSAProtectedKeyExchangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClientRSAProtectedKeyExchange * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClientRSAProtectedKeyExchange * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IClientRSAProtectedKeyExchange * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClientRSAExport )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClientRSAImport )( 
            IClientRSAProtectedKeyExchange * This,
            /* [in] */ BSTR bstrXMLInput,
            /* [retval][out] */ BSTR *bstrXMLOutput);
        
        END_INTERFACE
    } IClientRSAProtectedKeyExchangeVtbl;

    interface IClientRSAProtectedKeyExchange
    {
        CONST_VTBL struct IClientRSAProtectedKeyExchangeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClientRSAProtectedKeyExchange_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClientRSAProtectedKeyExchange_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClientRSAProtectedKeyExchange_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClientRSAProtectedKeyExchange_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IClientRSAProtectedKeyExchange_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IClientRSAProtectedKeyExchange_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IClientRSAProtectedKeyExchange_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IClientRSAProtectedKeyExchange_ClientRSAExport(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> ClientRSAExport(This,bstrXMLInput,bstrXMLOutput) ) 

#define IClientRSAProtectedKeyExchange_ClientRSAImport(This,bstrXMLInput,bstrXMLOutput)	\
    ( (This)->lpVtbl -> ClientRSAImport(This,bstrXMLInput,bstrXMLOutput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClientRSAProtectedKeyExchange_INTERFACE_DEFINED__ */


#ifndef __ICertificateEnroll_INTERFACE_DEFINED__
#define __ICertificateEnroll_INTERFACE_DEFINED__

/* interface ICertificateEnroll */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICertificateEnroll;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5ADA3784-8124-4D22-B89E-FB395DB263FC")
    ICertificateEnroll : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateRequest( 
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICertificateEnrollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICertificateEnroll * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICertificateEnroll * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICertificateEnroll * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICertificateEnroll * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICertificateEnroll * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICertificateEnroll * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICertificateEnroll * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateRequest )( 
            ICertificateEnroll * This,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        END_INTERFACE
    } ICertificateEnrollVtbl;

    interface ICertificateEnroll
    {
        CONST_VTBL struct ICertificateEnrollVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICertificateEnroll_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICertificateEnroll_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICertificateEnroll_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICertificateEnroll_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICertificateEnroll_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICertificateEnroll_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICertificateEnroll_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICertificateEnroll_CreateRequest(This,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> CreateRequest(This,bstrXMLIn,bstrXMLOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICertificateEnroll_INTERFACE_DEFINED__ */



#ifndef __KEYPAIRLib_LIBRARY_DEFINED__
#define __KEYPAIRLib_LIBRARY_DEFINED__

/* library KEYPAIRLib */
/* [helpstring][version][uuid] */ 






EXTERN_C const IID LIBID_KEYPAIRLib;
#endif /* __KEYPAIRLib_LIBRARY_DEFINED__ */

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


