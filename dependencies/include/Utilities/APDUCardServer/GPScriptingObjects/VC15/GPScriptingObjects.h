

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\APDUCardServer\GPScriptingObjects\GPScriptingObjects.idl:
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

#ifndef __GPScriptingObjects_h__
#define __GPScriptingObjects_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScriptConstructor_FWD_DEFINED__
#define __IScriptConstructor_FWD_DEFINED__
typedef interface IScriptConstructor IScriptConstructor;

#endif 	/* __IScriptConstructor_FWD_DEFINED__ */


#ifndef __IScriptArray_FWD_DEFINED__
#define __IScriptArray_FWD_DEFINED__
typedef interface IScriptArray IScriptArray;

#endif 	/* __IScriptArray_FWD_DEFINED__ */


#ifndef __ISerialiseXML_FWD_DEFINED__
#define __ISerialiseXML_FWD_DEFINED__
typedef interface ISerialiseXML ISerialiseXML;

#endif 	/* __ISerialiseXML_FWD_DEFINED__ */


#ifndef __IByteString_FWD_DEFINED__
#define __IByteString_FWD_DEFINED__
typedef interface IByteString IByteString;

#endif 	/* __IByteString_FWD_DEFINED__ */


#ifndef __IByteBuffer_FWD_DEFINED__
#define __IByteBuffer_FWD_DEFINED__
typedef interface IByteBuffer IByteBuffer;

#endif 	/* __IByteBuffer_FWD_DEFINED__ */


#ifndef __ITLV_FWD_DEFINED__
#define __ITLV_FWD_DEFINED__
typedef interface ITLV ITLV;

#endif 	/* __ITLV_FWD_DEFINED__ */


#ifndef __ITLVList_FWD_DEFINED__
#define __ITLVList_FWD_DEFINED__
typedef interface ITLVList ITLVList;

#endif 	/* __ITLVList_FWD_DEFINED__ */


#ifndef __IKey_FWD_DEFINED__
#define __IKey_FWD_DEFINED__
typedef interface IKey IKey;

#endif 	/* __IKey_FWD_DEFINED__ */


#ifndef __ICrypto_FWD_DEFINED__
#define __ICrypto_FWD_DEFINED__
typedef interface ICrypto ICrypto;

#endif 	/* __ICrypto_FWD_DEFINED__ */


#ifndef __ByteString_FWD_DEFINED__
#define __ByteString_FWD_DEFINED__

#ifdef __cplusplus
typedef class ByteString ByteString;
#else
typedef struct ByteString ByteString;
#endif /* __cplusplus */

#endif 	/* __ByteString_FWD_DEFINED__ */


#ifndef __ByteBuffer_FWD_DEFINED__
#define __ByteBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ByteBuffer ByteBuffer;
#else
typedef struct ByteBuffer ByteBuffer;
#endif /* __cplusplus */

#endif 	/* __ByteBuffer_FWD_DEFINED__ */


#ifndef __TLV_FWD_DEFINED__
#define __TLV_FWD_DEFINED__

#ifdef __cplusplus
typedef class TLV TLV;
#else
typedef struct TLV TLV;
#endif /* __cplusplus */

#endif 	/* __TLV_FWD_DEFINED__ */


#ifndef __Key_FWD_DEFINED__
#define __Key_FWD_DEFINED__

#ifdef __cplusplus
typedef class Key Key;
#else
typedef struct Key Key;
#endif /* __cplusplus */

#endif 	/* __Key_FWD_DEFINED__ */


#ifndef __Crypto_FWD_DEFINED__
#define __Crypto_FWD_DEFINED__

#ifdef __cplusplus
typedef class Crypto Crypto;
#else
typedef struct Crypto Crypto;
#endif /* __cplusplus */

#endif 	/* __Crypto_FWD_DEFINED__ */


#ifndef __TLVList_FWD_DEFINED__
#define __TLVList_FWD_DEFINED__

#ifdef __cplusplus
typedef class TLVList TLVList;
#else
typedef struct TLVList TLVList;
#endif /* __cplusplus */

#endif 	/* __TLVList_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "dispex.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IScriptConstructor_INTERFACE_DEFINED__
#define __IScriptConstructor_INTERFACE_DEFINED__

/* interface IScriptConstructor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IScriptConstructor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF1693FC-559C-46e6-B273-2988F3992DF8")
    IScriptConstructor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Constructor( 
            /* [in] */ DISPPARAMS *pdp) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScriptConstructorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScriptConstructor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScriptConstructor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScriptConstructor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScriptConstructor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScriptConstructor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScriptConstructor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScriptConstructor * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Constructor )( 
            IScriptConstructor * This,
            /* [in] */ DISPPARAMS *pdp);
        
        END_INTERFACE
    } IScriptConstructorVtbl;

    interface IScriptConstructor
    {
        CONST_VTBL struct IScriptConstructorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScriptConstructor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScriptConstructor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScriptConstructor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScriptConstructor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScriptConstructor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScriptConstructor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScriptConstructor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScriptConstructor_Constructor(This,pdp)	\
    ( (This)->lpVtbl -> Constructor(This,pdp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScriptConstructor_INTERFACE_DEFINED__ */


#ifndef __IScriptArray_INTERFACE_DEFINED__
#define __IScriptArray_INTERFACE_DEFINED__

/* interface IScriptArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IScriptArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3885D852-93FE-4715-863D-3FB6C6C348F1")
    IScriptArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEntry( 
            /* [in] */ BSTR bstrPropertyName,
            /* [in] */ VARIANT vEntry) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IScriptArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScriptArray * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScriptArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScriptArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScriptArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScriptArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScriptArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScriptArray * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetEntry )( 
            IScriptArray * This,
            /* [in] */ BSTR bstrPropertyName,
            /* [in] */ VARIANT vEntry);
        
        END_INTERFACE
    } IScriptArrayVtbl;

    interface IScriptArray
    {
        CONST_VTBL struct IScriptArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScriptArray_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScriptArray_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScriptArray_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScriptArray_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScriptArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScriptArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScriptArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IScriptArray_SetEntry(This,bstrPropertyName,vEntry)	\
    ( (This)->lpVtbl -> SetEntry(This,bstrPropertyName,vEntry) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScriptArray_INTERFACE_DEFINED__ */


#ifndef __ISerialiseXML_INTERFACE_DEFINED__
#define __ISerialiseXML_INTERFACE_DEFINED__

/* interface ISerialiseXML */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISerialiseXML;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61FE2942-7997-4ebc-8440-39A2DDF2C3B1")
    ISerialiseXML : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveToXML( 
            /* [in] */ IDispatch *pNodeToSerialiseUnder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromXML( 
            /* [in] */ IDispatch *pNodeContainingSerialisedData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISerialiseXMLVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISerialiseXML * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISerialiseXML * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISerialiseXML * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISerialiseXML * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISerialiseXML * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISerialiseXML * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISerialiseXML * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveToXML )( 
            ISerialiseXML * This,
            /* [in] */ IDispatch *pNodeToSerialiseUnder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromXML )( 
            ISerialiseXML * This,
            /* [in] */ IDispatch *pNodeContainingSerialisedData);
        
        END_INTERFACE
    } ISerialiseXMLVtbl;

    interface ISerialiseXML
    {
        CONST_VTBL struct ISerialiseXMLVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISerialiseXML_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISerialiseXML_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISerialiseXML_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISerialiseXML_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISerialiseXML_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISerialiseXML_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISerialiseXML_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISerialiseXML_SaveToXML(This,pNodeToSerialiseUnder)	\
    ( (This)->lpVtbl -> SaveToXML(This,pNodeToSerialiseUnder) ) 

#define ISerialiseXML_LoadFromXML(This,pNodeContainingSerialisedData)	\
    ( (This)->lpVtbl -> LoadFromXML(This,pNodeContainingSerialisedData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISerialiseXML_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_GPScriptingObjects_0000_0003 */
/* [local] */ 

typedef 
enum EncodingTypes
    {
        HEX	= 0,
        ASCII	= 1,
        UTF8	= 2,
        BASE64	= 3,
        CN	= 4
    } 	EncodingTypes;




extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0003_v0_0_s_ifspec;

#ifndef __IByteString_INTERFACE_DEFINED__
#define __IByteString_INTERFACE_DEFINED__

/* interface IByteString */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IByteString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE8E375C-3D0F-477F-A406-A280F645AC33")
    IByteString : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toString( 
            /* [optional][in] */ VARIANT lEncoding,
            /* [retval][out] */ BSTR *pStringVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fromString( 
            /* [in] */ BSTR bstrNewValue,
            /* [in] */ LONG lEncoding) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE byteAt( 
            /* [in] */ LONG offset,
            /* [retval][out] */ LONG *pByteVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE bytes( 
            /* [in] */ LONG offsetByte,
            /* [optional][in] */ VARIANT nCountBytes,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE left( 
            /* [in] */ LONG numBytes,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE right( 
            /* [in] */ LONG numBytes,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE equals( 
            /* [in] */ IByteString *pValToCompare,
            /* [retval][out] */ VARIANT_BOOL *bEquals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE concat( 
            /* [in] */ IByteString *pValToConcat,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE find( 
            /* [in] */ IByteString *pDataToFind,
            /* [optional][in] */ VARIANT lPosition,
            /* [retval][out] */ long *lPositionOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE and( 
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE or( 
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE xor( 
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE not( 
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE pad( 
            /* [in] */ LONG lPadMethod,
            /* [optional][in] */ VARIANT vDontPad8,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE unpad( 
            /* [in] */ LONG lPadMethod,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE padToBlock( 
            /* [in] */ LONG lPadMethod,
            /* [in] */ LONG lBlockSize,
            /* [optional][in] */ VARIANT vDontPadBoundary,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE unpadToBlock( 
            /* [in] */ LONG lPadMethod,
            /* [in] */ LONG lBlockSize,
            /* [retval][out] */ IByteString **ppOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IByteStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IByteString * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IByteString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IByteString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IByteString * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IByteString * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IByteString * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IByteString * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            IByteString * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toString )( 
            IByteString * This,
            /* [optional][in] */ VARIANT lEncoding,
            /* [retval][out] */ BSTR *pStringVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *fromString )( 
            IByteString * This,
            /* [in] */ BSTR bstrNewValue,
            /* [in] */ LONG lEncoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *byteAt )( 
            IByteString * This,
            /* [in] */ LONG offset,
            /* [retval][out] */ LONG *pByteVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *bytes )( 
            IByteString * This,
            /* [in] */ LONG offsetByte,
            /* [optional][in] */ VARIANT nCountBytes,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *left )( 
            IByteString * This,
            /* [in] */ LONG numBytes,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *right )( 
            IByteString * This,
            /* [in] */ LONG numBytes,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *equals )( 
            IByteString * This,
            /* [in] */ IByteString *pValToCompare,
            /* [retval][out] */ VARIANT_BOOL *bEquals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *concat )( 
            IByteString * This,
            /* [in] */ IByteString *pValToConcat,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *find )( 
            IByteString * This,
            /* [in] */ IByteString *pDataToFind,
            /* [optional][in] */ VARIANT lPosition,
            /* [retval][out] */ long *lPositionOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *and )( 
            IByteString * This,
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *or )( 
            IByteString * This,
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *xor )( 
            IByteString * This,
            /* [in] */ IByteString *pValIn,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *not )( 
            IByteString * This,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *pad )( 
            IByteString * This,
            /* [in] */ LONG lPadMethod,
            /* [optional][in] */ VARIANT vDontPad8,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *unpad )( 
            IByteString * This,
            /* [in] */ LONG lPadMethod,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *padToBlock )( 
            IByteString * This,
            /* [in] */ LONG lPadMethod,
            /* [in] */ LONG lBlockSize,
            /* [optional][in] */ VARIANT vDontPadBoundary,
            /* [retval][out] */ IByteString **ppOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *unpadToBlock )( 
            IByteString * This,
            /* [in] */ LONG lPadMethod,
            /* [in] */ LONG lBlockSize,
            /* [retval][out] */ IByteString **ppOut);
        
        END_INTERFACE
    } IByteStringVtbl;

    interface IByteString
    {
        CONST_VTBL struct IByteStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IByteString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IByteString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IByteString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IByteString_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IByteString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IByteString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IByteString_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IByteString_get_length(This,pVal)	\
    ( (This)->lpVtbl -> get_length(This,pVal) ) 

#define IByteString_toString(This,lEncoding,pStringVal)	\
    ( (This)->lpVtbl -> toString(This,lEncoding,pStringVal) ) 

#define IByteString_fromString(This,bstrNewValue,lEncoding)	\
    ( (This)->lpVtbl -> fromString(This,bstrNewValue,lEncoding) ) 

#define IByteString_byteAt(This,offset,pByteVal)	\
    ( (This)->lpVtbl -> byteAt(This,offset,pByteVal) ) 

#define IByteString_bytes(This,offsetByte,nCountBytes,ppOut)	\
    ( (This)->lpVtbl -> bytes(This,offsetByte,nCountBytes,ppOut) ) 

#define IByteString_left(This,numBytes,ppOut)	\
    ( (This)->lpVtbl -> left(This,numBytes,ppOut) ) 

#define IByteString_right(This,numBytes,ppOut)	\
    ( (This)->lpVtbl -> right(This,numBytes,ppOut) ) 

#define IByteString_equals(This,pValToCompare,bEquals)	\
    ( (This)->lpVtbl -> equals(This,pValToCompare,bEquals) ) 

#define IByteString_concat(This,pValToConcat,ppOut)	\
    ( (This)->lpVtbl -> concat(This,pValToConcat,ppOut) ) 

#define IByteString_find(This,pDataToFind,lPosition,lPositionOut)	\
    ( (This)->lpVtbl -> find(This,pDataToFind,lPosition,lPositionOut) ) 

#define IByteString_and(This,pValIn,ppOut)	\
    ( (This)->lpVtbl -> and(This,pValIn,ppOut) ) 

#define IByteString_or(This,pValIn,ppOut)	\
    ( (This)->lpVtbl -> or(This,pValIn,ppOut) ) 

#define IByteString_xor(This,pValIn,ppOut)	\
    ( (This)->lpVtbl -> xor(This,pValIn,ppOut) ) 

#define IByteString_not(This,ppOut)	\
    ( (This)->lpVtbl -> not(This,ppOut) ) 

#define IByteString_pad(This,lPadMethod,vDontPad8,ppOut)	\
    ( (This)->lpVtbl -> pad(This,lPadMethod,vDontPad8,ppOut) ) 

#define IByteString_unpad(This,lPadMethod,ppOut)	\
    ( (This)->lpVtbl -> unpad(This,lPadMethod,ppOut) ) 

#define IByteString_padToBlock(This,lPadMethod,lBlockSize,vDontPadBoundary,ppOut)	\
    ( (This)->lpVtbl -> padToBlock(This,lPadMethod,lBlockSize,vDontPadBoundary,ppOut) ) 

#define IByteString_unpadToBlock(This,lPadMethod,lBlockSize,ppOut)	\
    ( (This)->lpVtbl -> unpadToBlock(This,lPadMethod,lBlockSize,ppOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IByteString_INTERFACE_DEFINED__ */


#ifndef __IByteBuffer_INTERFACE_DEFINED__
#define __IByteBuffer_INTERFACE_DEFINED__

/* interface IByteBuffer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IByteBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0DD9659-D30F-4F98-A692-482ECADF73FB")
    IByteBuffer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toString( 
            /* [retval][out] */ BSTR *pStringVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fromString( 
            /* [in] */ BSTR bstrNewValue,
            /* [in] */ LONG lEncoding) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE byteAt( 
            /* [in] */ LONG offset,
            /* [retval][out] */ LONG *pByteVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE append( 
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toByteString( 
            /* [optional][in] */ VARIANT nOffset,
            /* [optional][in] */ VARIANT nCount,
            /* [retval][out] */ IByteString **pByteStringOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE find( 
            /* [in] */ IByteString *pDataToFind,
            /* [optional][in] */ VARIANT lPosition,
            /* [retval][out] */ long *lPositionOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear( 
            /* [optional][in] */ VARIANT vOffset,
            /* [optional][in] */ VARIANT vCount,
            /* [retval][out] */ IByteBuffer **pByteBufferOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE copy( 
            /* [in] */ LONG at,
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE insert( 
            /* [in] */ LONG at,
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setAt( 
            /* [in] */ LONG at,
            /* [in] */ LONG byVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IByteBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IByteBuffer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IByteBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IByteBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IByteBuffer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IByteBuffer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IByteBuffer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IByteBuffer * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            IByteBuffer * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toString )( 
            IByteBuffer * This,
            /* [retval][out] */ BSTR *pStringVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *fromString )( 
            IByteBuffer * This,
            /* [in] */ BSTR bstrNewValue,
            /* [in] */ LONG lEncoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *byteAt )( 
            IByteBuffer * This,
            /* [in] */ LONG offset,
            /* [retval][out] */ LONG *pByteVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *append )( 
            IByteBuffer * This,
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toByteString )( 
            IByteBuffer * This,
            /* [optional][in] */ VARIANT nOffset,
            /* [optional][in] */ VARIANT nCount,
            /* [retval][out] */ IByteString **pByteStringOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *find )( 
            IByteBuffer * This,
            /* [in] */ IByteString *pDataToFind,
            /* [optional][in] */ VARIANT lPosition,
            /* [retval][out] */ long *lPositionOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *clear )( 
            IByteBuffer * This,
            /* [optional][in] */ VARIANT vOffset,
            /* [optional][in] */ VARIANT vCount,
            /* [retval][out] */ IByteBuffer **pByteBufferOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *copy )( 
            IByteBuffer * This,
            /* [in] */ LONG at,
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *insert )( 
            IByteBuffer * This,
            /* [in] */ LONG at,
            /* [in] */ VARIANT vSource,
            /* [retval][out] */ IByteBuffer **pByteBufferOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setAt )( 
            IByteBuffer * This,
            /* [in] */ LONG at,
            /* [in] */ LONG byVal);
        
        END_INTERFACE
    } IByteBufferVtbl;

    interface IByteBuffer
    {
        CONST_VTBL struct IByteBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IByteBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IByteBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IByteBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IByteBuffer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IByteBuffer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IByteBuffer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IByteBuffer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IByteBuffer_get_length(This,pVal)	\
    ( (This)->lpVtbl -> get_length(This,pVal) ) 

#define IByteBuffer_toString(This,pStringVal)	\
    ( (This)->lpVtbl -> toString(This,pStringVal) ) 

#define IByteBuffer_fromString(This,bstrNewValue,lEncoding)	\
    ( (This)->lpVtbl -> fromString(This,bstrNewValue,lEncoding) ) 

#define IByteBuffer_byteAt(This,offset,pByteVal)	\
    ( (This)->lpVtbl -> byteAt(This,offset,pByteVal) ) 

#define IByteBuffer_append(This,vSource,pByteBufferOut)	\
    ( (This)->lpVtbl -> append(This,vSource,pByteBufferOut) ) 

#define IByteBuffer_toByteString(This,nOffset,nCount,pByteStringOut)	\
    ( (This)->lpVtbl -> toByteString(This,nOffset,nCount,pByteStringOut) ) 

#define IByteBuffer_find(This,pDataToFind,lPosition,lPositionOut)	\
    ( (This)->lpVtbl -> find(This,pDataToFind,lPosition,lPositionOut) ) 

#define IByteBuffer_clear(This,vOffset,vCount,pByteBufferOut)	\
    ( (This)->lpVtbl -> clear(This,vOffset,vCount,pByteBufferOut) ) 

#define IByteBuffer_copy(This,at,vSource,pByteBufferOut)	\
    ( (This)->lpVtbl -> copy(This,at,vSource,pByteBufferOut) ) 

#define IByteBuffer_insert(This,at,vSource,pByteBufferOut)	\
    ( (This)->lpVtbl -> insert(This,at,vSource,pByteBufferOut) ) 

#define IByteBuffer_setAt(This,at,byVal)	\
    ( (This)->lpVtbl -> setAt(This,at,byVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IByteBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_GPScriptingObjects_0000_0005 */
/* [local] */ 

typedef /* [public] */ 
enum __MIDL___MIDL_itf_GPScriptingObjects_0000_0005_0001
    {
        DGI	= 0,
        EMV	= 1,
        L16	= 2
    } 	TLVEncodingModes;



extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0005_v0_0_s_ifspec;

#ifndef __ITLV_INTERFACE_DEFINED__
#define __ITLV_INTERFACE_DEFINED__

/* interface ITLV */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITLV;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A27AEAC3-DB87-48F7-9874-0BCC182E77F0")
    ITLV : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DGI( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EMV( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_L16( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_encodingMode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE make( 
            /* [in] */ ULONG lTag,
            /* [in] */ IByteString *pValue,
            /* [in] */ LONG lEncoding) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTag( 
            /* [retval][out] */ ULONG *pulTag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getL( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getLV( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTLV( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTV( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITLVVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITLV * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITLV * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITLV * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITLV * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITLV * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITLV * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITLV * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DGI )( 
            ITLV * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EMV )( 
            ITLV * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_L16 )( 
            ITLV * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_size )( 
            ITLV * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_encodingMode )( 
            ITLV * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *make )( 
            ITLV * This,
            /* [in] */ ULONG lTag,
            /* [in] */ IByteString *pValue,
            /* [in] */ LONG lEncoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTag )( 
            ITLV * This,
            /* [retval][out] */ ULONG *pulTag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getValue )( 
            ITLV * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getL )( 
            ITLV * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getLV )( 
            ITLV * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTLV )( 
            ITLV * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getTV )( 
            ITLV * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toString )( 
            ITLV * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ITLVVtbl;

    interface ITLV
    {
        CONST_VTBL struct ITLVVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITLV_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITLV_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITLV_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITLV_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITLV_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITLV_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITLV_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITLV_get_DGI(This,pVal)	\
    ( (This)->lpVtbl -> get_DGI(This,pVal) ) 

#define ITLV_get_EMV(This,pVal)	\
    ( (This)->lpVtbl -> get_EMV(This,pVal) ) 

#define ITLV_get_L16(This,pVal)	\
    ( (This)->lpVtbl -> get_L16(This,pVal) ) 

#define ITLV_get_size(This,pVal)	\
    ( (This)->lpVtbl -> get_size(This,pVal) ) 

#define ITLV_get_encodingMode(This,pVal)	\
    ( (This)->lpVtbl -> get_encodingMode(This,pVal) ) 

#define ITLV_make(This,lTag,pValue,lEncoding)	\
    ( (This)->lpVtbl -> make(This,lTag,pValue,lEncoding) ) 

#define ITLV_getTag(This,pulTag)	\
    ( (This)->lpVtbl -> getTag(This,pulTag) ) 

#define ITLV_getValue(This,ppValue)	\
    ( (This)->lpVtbl -> getValue(This,ppValue) ) 

#define ITLV_getL(This,ppValue)	\
    ( (This)->lpVtbl -> getL(This,ppValue) ) 

#define ITLV_getLV(This,ppValue)	\
    ( (This)->lpVtbl -> getLV(This,ppValue) ) 

#define ITLV_getTLV(This,ppValue)	\
    ( (This)->lpVtbl -> getTLV(This,ppValue) ) 

#define ITLV_getTV(This,ppValue)	\
    ( (This)->lpVtbl -> getTV(This,ppValue) ) 

#define ITLV_toString(This,pVal)	\
    ( (This)->lpVtbl -> toString(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITLV_INTERFACE_DEFINED__ */


#ifndef __ITLVList_INTERFACE_DEFINED__
#define __ITLVList_INTERFACE_DEFINED__

/* interface ITLVList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITLVList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FA426AD-FE72-4ED2-AC7C-E2FEDA7BAD11")
    ITLVList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_encodingMode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE make( 
            /* [in] */ IByteString *pValue,
            /* [in] */ LONG lEncoding) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE append( 
            /* [in] */ VARIANT vSource,
            /* [optional][in] */ VARIANT vBytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE appendValue( 
            /* [in] */ ULONG tag,
            /* [in] */ IByteString *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE appendValueIndex( 
            /* [in] */ LONG index,
            /* [in] */ IByteString *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteByIndex( 
            /* [in] */ LONG index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deleteByTag( 
            /* [in] */ ULONG tag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE find( 
            /* [in] */ ULONG tag,
            /* [retval][out] */ ITLV **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE findIndex( 
            /* [in] */ ULONG tag,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE index( 
            /* [in] */ LONG index,
            /* [retval][out] */ ITLV **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toByteString( 
            /* [retval][out] */ IByteString **ppValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE updateValue( 
            /* [in] */ ULONG tag,
            /* [in] */ IByteString *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE updateValueIndex( 
            /* [in] */ LONG index,
            /* [in] */ IByteString *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE toString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITLVListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITLVList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITLVList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITLVList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITLVList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITLVList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITLVList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITLVList * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_encodingMode )( 
            ITLVList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            ITLVList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *make )( 
            ITLVList * This,
            /* [in] */ IByteString *pValue,
            /* [in] */ LONG lEncoding);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *append )( 
            ITLVList * This,
            /* [in] */ VARIANT vSource,
            /* [optional][in] */ VARIANT vBytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *appendValue )( 
            ITLVList * This,
            /* [in] */ ULONG tag,
            /* [in] */ IByteString *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *appendValueIndex )( 
            ITLVList * This,
            /* [in] */ LONG index,
            /* [in] */ IByteString *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deleteByIndex )( 
            ITLVList * This,
            /* [in] */ LONG index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deleteByTag )( 
            ITLVList * This,
            /* [in] */ ULONG tag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *find )( 
            ITLVList * This,
            /* [in] */ ULONG tag,
            /* [retval][out] */ ITLV **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *findIndex )( 
            ITLVList * This,
            /* [in] */ ULONG tag,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *index )( 
            ITLVList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ ITLV **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toByteString )( 
            ITLVList * This,
            /* [retval][out] */ IByteString **ppValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *updateValue )( 
            ITLVList * This,
            /* [in] */ ULONG tag,
            /* [in] */ IByteString *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *updateValueIndex )( 
            ITLVList * This,
            /* [in] */ LONG index,
            /* [in] */ IByteString *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *toString )( 
            ITLVList * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } ITLVListVtbl;

    interface ITLVList
    {
        CONST_VTBL struct ITLVListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITLVList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITLVList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITLVList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITLVList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITLVList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITLVList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITLVList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITLVList_get_encodingMode(This,pVal)	\
    ( (This)->lpVtbl -> get_encodingMode(This,pVal) ) 

#define ITLVList_get_length(This,pVal)	\
    ( (This)->lpVtbl -> get_length(This,pVal) ) 

#define ITLVList_make(This,pValue,lEncoding)	\
    ( (This)->lpVtbl -> make(This,pValue,lEncoding) ) 

#define ITLVList_append(This,vSource,vBytes)	\
    ( (This)->lpVtbl -> append(This,vSource,vBytes) ) 

#define ITLVList_appendValue(This,tag,pValue)	\
    ( (This)->lpVtbl -> appendValue(This,tag,pValue) ) 

#define ITLVList_appendValueIndex(This,index,pValue)	\
    ( (This)->lpVtbl -> appendValueIndex(This,index,pValue) ) 

#define ITLVList_deleteByIndex(This,index)	\
    ( (This)->lpVtbl -> deleteByIndex(This,index) ) 

#define ITLVList_deleteByTag(This,tag)	\
    ( (This)->lpVtbl -> deleteByTag(This,tag) ) 

#define ITLVList_find(This,tag,ppValue)	\
    ( (This)->lpVtbl -> find(This,tag,ppValue) ) 

#define ITLVList_findIndex(This,tag,pVal)	\
    ( (This)->lpVtbl -> findIndex(This,tag,pVal) ) 

#define ITLVList_index(This,index,ppValue)	\
    ( (This)->lpVtbl -> index(This,index,ppValue) ) 

#define ITLVList_toByteString(This,ppValue)	\
    ( (This)->lpVtbl -> toByteString(This,ppValue) ) 

#define ITLVList_updateValue(This,tag,pValue)	\
    ( (This)->lpVtbl -> updateValue(This,tag,pValue) ) 

#define ITLVList_updateValueIndex(This,index,pValue)	\
    ( (This)->lpVtbl -> updateValueIndex(This,index,pValue) ) 

#define ITLVList_toString(This,pVal)	\
    ( (This)->lpVtbl -> toString(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITLVList_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_GPScriptingObjects_0000_0007 */
/* [local] */ 

/* [v1_enum] */ 
enum TKeyComponent
    {
        DES	= 0,
        CRT_P	= 1,
        CRT_Q	= 2,
        CRT_DP1	= 3,
        CRT_DQ1	= 4,
        CRT_PQ	= 5,
        EXPONENT	= 6,
        MODULUS	= 7,
        SUBJECTPUBLICKEYINFO	= 8,
        PRIVATEEXPONENT	= 9,
        AES	= 10,
        _COMPONENT_PRIVATEKEY_BLOB	= 101,
        _COMPONENT_PUBLICKEY_BLOB	= 102
    } ;


extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0007_v0_0_s_ifspec;

#ifndef __IKey_INTERFACE_DEFINED__
#define __IKey_INTERFACE_DEFINED__

/* interface IKey */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E142D83-47F1-4203-93FD-D24F95E9A092")
    IKey : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRT_P( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRT_Q( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRT_DP1( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRT_DQ1( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CRT_PQ( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EXPONENT( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MODULUS( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SUBJECTPUBLICKEYINFO( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getComponent( 
            /* [in] */ LONG lKeyComponent,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setComponent( 
            /* [in] */ LONG lKeyComponent,
            /* [in] */ IByteString *pDataIn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE encrypt( 
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE decrypt( 
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE deriveKey( 
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDivData,
            /* [retval][out] */ IKey **ppDerivedKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateKey( 
            /* [in] */ LONG lKeyType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getSize( 
            /* [retval][out] */ LONG *plKeySizeBits) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setSize( 
            /* [in] */ LONG lKeySizeBits) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateKeyPair( 
            /* [in] */ LONG lKeyMechanism,
            /* [in] */ LONG lKeySizeBits) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_protKeyID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_protKeyID( 
            /* [in] */ LONG val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ BSTR bstrPropertyName,
            /* [retval][out] */ BSTR *bstrPropertyValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AES( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKey * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKey * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKey * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IKey * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IKey * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IKey * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IKey * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRT_P )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRT_Q )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRT_DP1 )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRT_DQ1 )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CRT_PQ )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EXPONENT )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MODULUS )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SUBJECTPUBLICKEYINFO )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getComponent )( 
            IKey * This,
            /* [in] */ LONG lKeyComponent,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setComponent )( 
            IKey * This,
            /* [in] */ LONG lKeyComponent,
            /* [in] */ IByteString *pDataIn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *encrypt )( 
            IKey * This,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *decrypt )( 
            IKey * This,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *deriveKey )( 
            IKey * This,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDivData,
            /* [retval][out] */ IKey **ppDerivedKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateKey )( 
            IKey * This,
            /* [in] */ LONG lKeyType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getSize )( 
            IKey * This,
            /* [retval][out] */ LONG *plKeySizeBits);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setSize )( 
            IKey * This,
            /* [in] */ LONG lKeySizeBits);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateKeyPair )( 
            IKey * This,
            /* [in] */ LONG lKeyMechanism,
            /* [in] */ LONG lKeySizeBits);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_protKeyID )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_protKeyID )( 
            IKey * This,
            /* [in] */ LONG val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IKey * This,
            /* [in] */ BSTR bstrPropertyName,
            /* [retval][out] */ BSTR *bstrPropertyValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AES )( 
            IKey * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IKeyVtbl;

    interface IKey
    {
        CONST_VTBL struct IKeyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKey_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKey_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKey_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKey_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IKey_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IKey_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IKey_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IKey_get_DES(This,pVal)	\
    ( (This)->lpVtbl -> get_DES(This,pVal) ) 

#define IKey_get_CRT_P(This,pVal)	\
    ( (This)->lpVtbl -> get_CRT_P(This,pVal) ) 

#define IKey_get_CRT_Q(This,pVal)	\
    ( (This)->lpVtbl -> get_CRT_Q(This,pVal) ) 

#define IKey_get_CRT_DP1(This,pVal)	\
    ( (This)->lpVtbl -> get_CRT_DP1(This,pVal) ) 

#define IKey_get_CRT_DQ1(This,pVal)	\
    ( (This)->lpVtbl -> get_CRT_DQ1(This,pVal) ) 

#define IKey_get_CRT_PQ(This,pVal)	\
    ( (This)->lpVtbl -> get_CRT_PQ(This,pVal) ) 

#define IKey_get_EXPONENT(This,pVal)	\
    ( (This)->lpVtbl -> get_EXPONENT(This,pVal) ) 

#define IKey_get_MODULUS(This,pVal)	\
    ( (This)->lpVtbl -> get_MODULUS(This,pVal) ) 

#define IKey_get_SUBJECTPUBLICKEYINFO(This,pVal)	\
    ( (This)->lpVtbl -> get_SUBJECTPUBLICKEYINFO(This,pVal) ) 

#define IKey_getComponent(This,lKeyComponent,ppDataOut)	\
    ( (This)->lpVtbl -> getComponent(This,lKeyComponent,ppDataOut) ) 

#define IKey_setComponent(This,lKeyComponent,pDataIn)	\
    ( (This)->lpVtbl -> setComponent(This,lKeyComponent,pDataIn) ) 

#define IKey_encrypt(This,lMechanism,pDataIn,vInitialVector,ppDataOut)	\
    ( (This)->lpVtbl -> encrypt(This,lMechanism,pDataIn,vInitialVector,ppDataOut) ) 

#define IKey_decrypt(This,lMechanism,pDataIn,vInitialVector,ppDataOut)	\
    ( (This)->lpVtbl -> decrypt(This,lMechanism,pDataIn,vInitialVector,ppDataOut) ) 

#define IKey_deriveKey(This,lMechanism,pDivData,ppDerivedKey)	\
    ( (This)->lpVtbl -> deriveKey(This,lMechanism,pDivData,ppDerivedKey) ) 

#define IKey_generateKey(This,lKeyType)	\
    ( (This)->lpVtbl -> generateKey(This,lKeyType) ) 

#define IKey_getSize(This,plKeySizeBits)	\
    ( (This)->lpVtbl -> getSize(This,plKeySizeBits) ) 

#define IKey_setSize(This,lKeySizeBits)	\
    ( (This)->lpVtbl -> setSize(This,lKeySizeBits) ) 

#define IKey_generateKeyPair(This,lKeyMechanism,lKeySizeBits)	\
    ( (This)->lpVtbl -> generateKeyPair(This,lKeyMechanism,lKeySizeBits) ) 

#define IKey_get_protKeyID(This,pVal)	\
    ( (This)->lpVtbl -> get_protKeyID(This,pVal) ) 

#define IKey_put_protKeyID(This,val)	\
    ( (This)->lpVtbl -> put_protKeyID(This,val) ) 

#define IKey_GetProperty(This,bstrPropertyName,bstrPropertyValue)	\
    ( (This)->lpVtbl -> GetProperty(This,bstrPropertyName,bstrPropertyValue) ) 

#define IKey_get_AES(This,pVal)	\
    ( (This)->lpVtbl -> get_AES(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKey_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_GPScriptingObjects_0000_0008 */
/* [local] */ 

/* [v1_enum] */ 
enum TCryptoMechanisms
    {
        DES_CBC	= 1,
        DES_CBC_LP	= 2,
        DES_CBC_P	= 3,
        DES_ECB	= 4,
        DES_ECB_LP	= 5,
        DES_ECB_P	= 6,
        DES_MAC	= 7,
        DES_MAC_EMV	= 8,
        Crypto_RSA	= 9,
        DES_2DES_16	= 10
    } ;
/* [v1_enum] */ 
enum TCryptoKeyTypes
    {
        KeyTypeDES	= 1,
        KeyTypeDES2	= 2,
        KeyTypeDES3	= 3,
        KeyTypeAES128	= 4,
        KeyTypeAES192	= 5,
        KeyTypeAES256	= 6
    } ;
/* [v1_enum] */ 
enum TCryptoHashTypes
    {
        MD5	= 0,
        SHA_1	= 1,
        SHA_256	= 2
    } ;
/* [v1_enum] */ 
enum TCryptoPadTypes
    {
        ISO9797_METHOD_1	= 1,
        ISO9797_METHOD_2	= 2
    } ;


extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GPScriptingObjects_0000_0008_v0_0_s_ifspec;

#ifndef __ICrypto_INTERFACE_DEFINED__
#define __ICrypto_INTERFACE_DEFINED__

/* interface ICrypto */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICrypto;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4FA68AB6-9B13-42E8-8E34-FABBD7553A84")
    ICrypto : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MD5( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SHA_1( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_CBC( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_CBC_LP( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_CBC_P( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_ECB( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_ECB_LP( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_ECB_P( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_MAC( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_MAC_EMV( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RSA( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES2( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES3( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISO9797_METHOD_1( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISO9797_METHOD_2( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateRandom( 
            /* [in] */ LONG lLengthToGenerate,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE digest( 
            /* [in] */ LONG lCryptoHashType,
            /* [in] */ IByteString *pDataToHash,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE encrypt( 
            /* [in] */ IKey *pKey,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE decrypt( 
            /* [in] */ IKey *pKey,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateKey( 
            /* [in] */ LONG lKeyType,
            /* [in] */ IKey *pKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE generateKeyPair( 
            /* [in] */ LONG lKeyMechanism,
            /* [in] */ IKey *pPublicKey,
            /* [in] */ IKey *pPrivateKey) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DES_2DES_16( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AES128( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AES192( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AES256( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SHA_256( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICryptoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICrypto * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICrypto * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICrypto * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICrypto * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICrypto * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICrypto * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICrypto * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MD5 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SHA_1 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_CBC )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_CBC_LP )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_CBC_P )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_ECB )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_ECB_LP )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_ECB_P )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_MAC )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_MAC_EMV )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RSA )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES2 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES3 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISO9797_METHOD_1 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISO9797_METHOD_2 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateRandom )( 
            ICrypto * This,
            /* [in] */ LONG lLengthToGenerate,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *digest )( 
            ICrypto * This,
            /* [in] */ LONG lCryptoHashType,
            /* [in] */ IByteString *pDataToHash,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *encrypt )( 
            ICrypto * This,
            /* [in] */ IKey *pKey,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *decrypt )( 
            ICrypto * This,
            /* [in] */ IKey *pKey,
            /* [in] */ LONG lMechanism,
            /* [in] */ IByteString *pDataIn,
            /* [optional][in] */ VARIANT vInitialVector,
            /* [retval][out] */ IByteString **ppDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateKey )( 
            ICrypto * This,
            /* [in] */ LONG lKeyType,
            /* [in] */ IKey *pKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *generateKeyPair )( 
            ICrypto * This,
            /* [in] */ LONG lKeyMechanism,
            /* [in] */ IKey *pPublicKey,
            /* [in] */ IKey *pPrivateKey);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DES_2DES_16 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AES128 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AES192 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AES256 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SHA_256 )( 
            ICrypto * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ICryptoVtbl;

    interface ICrypto
    {
        CONST_VTBL struct ICryptoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICrypto_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICrypto_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICrypto_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICrypto_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICrypto_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICrypto_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICrypto_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICrypto_get_MD5(This,pVal)	\
    ( (This)->lpVtbl -> get_MD5(This,pVal) ) 

#define ICrypto_get_SHA_1(This,pVal)	\
    ( (This)->lpVtbl -> get_SHA_1(This,pVal) ) 

#define ICrypto_get_DES_CBC(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_CBC(This,pVal) ) 

#define ICrypto_get_DES_CBC_LP(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_CBC_LP(This,pVal) ) 

#define ICrypto_get_DES_CBC_P(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_CBC_P(This,pVal) ) 

#define ICrypto_get_DES_ECB(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_ECB(This,pVal) ) 

#define ICrypto_get_DES_ECB_LP(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_ECB_LP(This,pVal) ) 

#define ICrypto_get_DES_ECB_P(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_ECB_P(This,pVal) ) 

#define ICrypto_get_DES_MAC(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_MAC(This,pVal) ) 

#define ICrypto_get_DES_MAC_EMV(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_MAC_EMV(This,pVal) ) 

#define ICrypto_get_RSA(This,pVal)	\
    ( (This)->lpVtbl -> get_RSA(This,pVal) ) 

#define ICrypto_get_DES(This,pVal)	\
    ( (This)->lpVtbl -> get_DES(This,pVal) ) 

#define ICrypto_get_DES2(This,pVal)	\
    ( (This)->lpVtbl -> get_DES2(This,pVal) ) 

#define ICrypto_get_DES3(This,pVal)	\
    ( (This)->lpVtbl -> get_DES3(This,pVal) ) 

#define ICrypto_get_ISO9797_METHOD_1(This,pVal)	\
    ( (This)->lpVtbl -> get_ISO9797_METHOD_1(This,pVal) ) 

#define ICrypto_get_ISO9797_METHOD_2(This,pVal)	\
    ( (This)->lpVtbl -> get_ISO9797_METHOD_2(This,pVal) ) 

#define ICrypto_generateRandom(This,lLengthToGenerate,ppDataOut)	\
    ( (This)->lpVtbl -> generateRandom(This,lLengthToGenerate,ppDataOut) ) 

#define ICrypto_digest(This,lCryptoHashType,pDataToHash,ppDataOut)	\
    ( (This)->lpVtbl -> digest(This,lCryptoHashType,pDataToHash,ppDataOut) ) 

#define ICrypto_encrypt(This,pKey,lMechanism,pDataIn,vInitialVector,ppDataOut)	\
    ( (This)->lpVtbl -> encrypt(This,pKey,lMechanism,pDataIn,vInitialVector,ppDataOut) ) 

#define ICrypto_decrypt(This,pKey,lMechanism,pDataIn,vInitialVector,ppDataOut)	\
    ( (This)->lpVtbl -> decrypt(This,pKey,lMechanism,pDataIn,vInitialVector,ppDataOut) ) 

#define ICrypto_generateKey(This,lKeyType,pKey)	\
    ( (This)->lpVtbl -> generateKey(This,lKeyType,pKey) ) 

#define ICrypto_generateKeyPair(This,lKeyMechanism,pPublicKey,pPrivateKey)	\
    ( (This)->lpVtbl -> generateKeyPair(This,lKeyMechanism,pPublicKey,pPrivateKey) ) 

#define ICrypto_get_DES_2DES_16(This,pVal)	\
    ( (This)->lpVtbl -> get_DES_2DES_16(This,pVal) ) 

#define ICrypto_get_AES128(This,pVal)	\
    ( (This)->lpVtbl -> get_AES128(This,pVal) ) 

#define ICrypto_get_AES192(This,pVal)	\
    ( (This)->lpVtbl -> get_AES192(This,pVal) ) 

#define ICrypto_get_AES256(This,pVal)	\
    ( (This)->lpVtbl -> get_AES256(This,pVal) ) 

#define ICrypto_get_SHA_256(This,pVal)	\
    ( (This)->lpVtbl -> get_SHA_256(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICrypto_INTERFACE_DEFINED__ */



#ifndef __GPScriptingObjectsLib_LIBRARY_DEFINED__
#define __GPScriptingObjectsLib_LIBRARY_DEFINED__

/* library GPScriptingObjectsLib */
/* [helpstring][version][uuid] */ 





EXTERN_C const IID LIBID_GPScriptingObjectsLib;

EXTERN_C const CLSID CLSID_ByteString;

#ifdef __cplusplus

class DECLSPEC_UUID("38F8B239-A75F-449F-83AA-D36815F91543")
ByteString;
#endif

EXTERN_C const CLSID CLSID_ByteBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("F490E1C9-AA23-4826-B96A-CE70099EE8F0")
ByteBuffer;
#endif

EXTERN_C const CLSID CLSID_TLV;

#ifdef __cplusplus

class DECLSPEC_UUID("A05EF81B-5C2F-461A-BA66-27E2FC1ACBE9")
TLV;
#endif

EXTERN_C const CLSID CLSID_Key;

#ifdef __cplusplus

class DECLSPEC_UUID("73D7C9B2-7389-4246-8D75-971C4C58FED8")
Key;
#endif

EXTERN_C const CLSID CLSID_Crypto;

#ifdef __cplusplus

class DECLSPEC_UUID("087DC27A-8FDE-4767-9EB2-3B4A2F454CA0")
Crypto;
#endif

EXTERN_C const CLSID CLSID_TLVList;

#ifdef __cplusplus

class DECLSPEC_UUID("47E9CB01-5F35-4A25-ACAA-8B5112CCFF0A")
TLVList;
#endif
#endif /* __GPScriptingObjectsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


