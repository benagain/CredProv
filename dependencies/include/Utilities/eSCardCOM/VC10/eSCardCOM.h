

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:01:02 2018
 */
/* Compiler settings for ..\..\eSCardCOM\eSCardCOM.idl:
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

#ifndef __eSCardCOM_h__
#define __eSCardCOM_h__

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


#ifndef __IByteBuffer_FWD_DEFINED__
#define __IByteBuffer_FWD_DEFINED__
typedef interface IByteBuffer IByteBuffer;
#endif 	/* __IByteBuffer_FWD_DEFINED__ */


#ifndef __ISCardCmd_FWD_DEFINED__
#define __ISCardCmd_FWD_DEFINED__
typedef interface ISCardCmd ISCardCmd;
#endif 	/* __ISCardCmd_FWD_DEFINED__ */


#ifndef __ISCardCmd2_FWD_DEFINED__
#define __ISCardCmd2_FWD_DEFINED__
typedef interface ISCardCmd2 ISCardCmd2;
#endif 	/* __ISCardCmd2_FWD_DEFINED__ */


#ifndef __ISCard_FWD_DEFINED__
#define __ISCard_FWD_DEFINED__
typedef interface ISCard ISCard;
#endif 	/* __ISCard_FWD_DEFINED__ */


#ifndef __ByteBuffer_FWD_DEFINED__
#define __ByteBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ByteBuffer ByteBuffer;
#else
typedef struct ByteBuffer ByteBuffer;
#endif /* __cplusplus */

#endif 	/* __ByteBuffer_FWD_DEFINED__ */


#ifndef __SCardCmd_FWD_DEFINED__
#define __SCardCmd_FWD_DEFINED__

#ifdef __cplusplus
typedef class SCardCmd SCardCmd;
#else
typedef struct SCardCmd SCardCmd;
#endif /* __cplusplus */

#endif 	/* __SCardCmd_FWD_DEFINED__ */


#ifndef __SCard_FWD_DEFINED__
#define __SCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class SCard SCard;
#else
typedef struct SCard SCard;
#endif /* __cplusplus */

#endif 	/* __SCard_FWD_DEFINED__ */


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
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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


/* interface __MIDL_itf_eSCardCOM_0000_0003 */
/* [local] */ 

typedef /* [public] */ BYTE *LPBYTE;

typedef /* [version][v1_enum][helpstring] */ 
enum tagSCARD_SHARE_MODES
    {	EXCLUSIVE	= 1,
	SHARED	= 2
    } 	SCARD_SHARE_MODES;

typedef /* [version][v1_enum][helpstring] */ 
enum tagSCARD_DISPOSITIONS
    {	LEAVE	= 0,
	RESET	= 1,
	UNPOWER	= 2,
	EJECT	= 3
    } 	SCARD_DISPOSITIONS;

typedef /* [version][v1_enum][helpstring] */ 
enum tagSCARD_PROTOCOLS
    {	T0	= 0x1,
	T1	= 0x2,
	T0T1	= 0x3,
	RAW	= 0xff
    } 	SCARD_PROTOCOLS;



extern RPC_IF_HANDLE __MIDL_itf_eSCardCOM_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_eSCardCOM_0000_0003_v0_0_s_ifspec;

#ifndef __IByteBuffer_INTERFACE_DEFINED__
#define __IByteBuffer_INTERFACE_DEFINED__

/* interface IByteBuffer */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [unique] */ IByteBuffer *LPBYTEBUFFER;


EXTERN_C const IID IID_IByteBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0594531D-E44E-4ed0-BB31-9A928D52304D")
    IByteBuffer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LONG lSize,
            /* [in] */ BYTE *pData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [out] */ BYTE *pByte,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbRead) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ BYTE *pByte,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbWritten) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeHex( 
            /* [in] */ BSTR bstrDataHex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadHex( 
            /* [retval][out] */ BSTR *pbstrDataHex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadWithOffSet( 
            /* [out] */ BYTE *pByte,
            /* [in] */ LONG offset,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbRead) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IByteBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IByteBuffer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IByteBuffer * This,
            /* [in] */ LONG lSize,
            /* [in] */ BYTE *pData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IByteBuffer * This,
            /* [out] */ BYTE *pByte,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbRead);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IByteBuffer * This,
            /* [in] */ BYTE *pByte,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbWritten);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeHex )( 
            IByteBuffer * This,
            /* [in] */ BSTR bstrDataHex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadHex )( 
            IByteBuffer * This,
            /* [retval][out] */ BSTR *pbstrDataHex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadWithOffSet )( 
            IByteBuffer * This,
            /* [out] */ BYTE *pByte,
            /* [in] */ LONG offset,
            /* [in] */ LONG cb,
            /* [out] */ LONG *pcbRead);
        
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


#define IByteBuffer_Initialize(This,lSize,pData)	\
    ( (This)->lpVtbl -> Initialize(This,lSize,pData) ) 

#define IByteBuffer_Read(This,pByte,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pByte,cb,pcbRead) ) 

#define IByteBuffer_Write(This,pByte,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pByte,cb,pcbWritten) ) 

#define IByteBuffer_InitializeHex(This,bstrDataHex)	\
    ( (This)->lpVtbl -> InitializeHex(This,bstrDataHex) ) 

#define IByteBuffer_ReadHex(This,pbstrDataHex)	\
    ( (This)->lpVtbl -> ReadHex(This,pbstrDataHex) ) 

#define IByteBuffer_ReadWithOffSet(This,pByte,offset,cb,pcbRead)	\
    ( (This)->lpVtbl -> ReadWithOffSet(This,pByte,offset,cb,pcbRead) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IByteBuffer_INTERFACE_DEFINED__ */


#ifndef __ISCardCmd_INTERFACE_DEFINED__
#define __ISCardCmd_INTERFACE_DEFINED__

/* interface ISCardCmd */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [unique] */ ISCardCmd *LPSCARDCMD;


EXTERN_C const IID IID_ISCardCmd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E004BD57-8EB7-4416-AEA3-379755E04D2D")
    ISCardCmd : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BuildCmd( 
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ LPBYTEBUFFER pbyData,
            /* [in] */ LONG *pLe) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClassId( 
            /* [retval][out] */ BYTE *pbyClass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutClassId( 
            /* [in] */ BYTE byClass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutAlternateClassId( 
            /* [in] */ BYTE byClass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAlternateClassId( 
            /* [retval][out] */ BYTE *pbyClass) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInstructionId( 
            /* [retval][out] */ BYTE *pbyIns) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP1( 
            /* [retval][out] */ BYTE *pbyP1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2( 
            /* [retval][out] */ BYTE *pbyP2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP3( 
            /* [retval][out] */ BYTE *pbyP3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLe( 
            /* [retval][out] */ LONG *plSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutData( 
            /* [in] */ LPBYTEBUFFER pData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [out] */ LPBYTEBUFFER *ppData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutApduReply( 
            /* [in] */ LPBYTEBUFFER pReplyApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApduReplyLength( 
            /* [retval][out] */ LONG *plSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApduReply( 
            /* [out] */ LPBYTEBUFFER *ppReplyApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReplyStatus( 
            /* [retval][out] */ LPWORD pwStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReplyStatusSW1( 
            /* [retval][out] */ BYTE *pbySW1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReplyStatusSW2( 
            /* [retval][out] */ BYTE *pbySW2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApduLength( 
            /* [retval][out] */ LONG *plSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApdu( 
            /* [retval][out] */ LPBYTEBUFFER *ppApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutReplyStatus( 
            /* [in] */ WORD Status) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutApdu( 
            /* [in] */ LPBYTEBUFFER pApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutInstructionId( 
            /* [in] */ BYTE byIns) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutP1( 
            /* [in] */ BYTE byP1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutP2( 
            /* [in] */ BYTE byP2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnData( 
            /* [retval][out] */ LPBYTEBUFFER *ppData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnApduReply( 
            /* [retval][out] */ LPBYTEBUFFER *ppReplyApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BuildCmd2( 
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ IDispatch *pByteString,
            /* [in] */ LONG pLe) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutData2( 
            /* [in] */ IDispatch *pByteStringData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData2( 
            /* [retval][out] */ IDispatch **ppByteStringData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutApduReply2( 
            /* [in] */ IDispatch *pByteStringReplyApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApduReply2( 
            /* [retval][out] */ IDispatch **ppByteStringReplyApdu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDescriptionXML( 
            /* [retval][out] */ BSTR *pbstrDescriptionXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutDescriptionXML( 
            /* [in] */ BSTR bstrDescriptionXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApduReplyData2( 
            /* [retval][out] */ IDispatch **ppByteStringReplyData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetApdu2( 
            /* [retval][out] */ IDispatch **ppByteStringData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCardCmdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISCardCmd * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISCardCmd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISCardCmd * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISCardCmd * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISCardCmd * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISCardCmd * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISCardCmd * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BuildCmd )( 
            ISCardCmd * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ LPBYTEBUFFER pbyData,
            /* [in] */ LONG *pLe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClassId )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutClassId )( 
            ISCardCmd * This,
            /* [in] */ BYTE byClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutAlternateClassId )( 
            ISCardCmd * This,
            /* [in] */ BYTE byClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAlternateClassId )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInstructionId )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyIns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP1 )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyP1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2 )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyP2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP3 )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbyP3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLe )( 
            ISCardCmd * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutData )( 
            ISCardCmd * This,
            /* [in] */ LPBYTEBUFFER pData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISCardCmd * This,
            /* [out] */ LPBYTEBUFFER *ppData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApduReply )( 
            ISCardCmd * This,
            /* [in] */ LPBYTEBUFFER pReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReplyLength )( 
            ISCardCmd * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReply )( 
            ISCardCmd * This,
            /* [out] */ LPBYTEBUFFER *ppReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatus )( 
            ISCardCmd * This,
            /* [retval][out] */ LPWORD pwStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatusSW1 )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbySW1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatusSW2 )( 
            ISCardCmd * This,
            /* [retval][out] */ BYTE *pbySW2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduLength )( 
            ISCardCmd * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApdu )( 
            ISCardCmd * This,
            /* [retval][out] */ LPBYTEBUFFER *ppApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutReplyStatus )( 
            ISCardCmd * This,
            /* [in] */ WORD Status);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApdu )( 
            ISCardCmd * This,
            /* [in] */ LPBYTEBUFFER pApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutInstructionId )( 
            ISCardCmd * This,
            /* [in] */ BYTE byIns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutP1 )( 
            ISCardCmd * This,
            /* [in] */ BYTE byP1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutP2 )( 
            ISCardCmd * This,
            /* [in] */ BYTE byP2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnData )( 
            ISCardCmd * This,
            /* [retval][out] */ LPBYTEBUFFER *ppData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnApduReply )( 
            ISCardCmd * This,
            /* [retval][out] */ LPBYTEBUFFER *ppReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BuildCmd2 )( 
            ISCardCmd * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ IDispatch *pByteString,
            /* [in] */ LONG pLe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutData2 )( 
            ISCardCmd * This,
            /* [in] */ IDispatch *pByteStringData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData2 )( 
            ISCardCmd * This,
            /* [retval][out] */ IDispatch **ppByteStringData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApduReply2 )( 
            ISCardCmd * This,
            /* [in] */ IDispatch *pByteStringReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReply2 )( 
            ISCardCmd * This,
            /* [retval][out] */ IDispatch **ppByteStringReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDescriptionXML )( 
            ISCardCmd * This,
            /* [retval][out] */ BSTR *pbstrDescriptionXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutDescriptionXML )( 
            ISCardCmd * This,
            /* [in] */ BSTR bstrDescriptionXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReplyData2 )( 
            ISCardCmd * This,
            /* [retval][out] */ IDispatch **ppByteStringReplyData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApdu2 )( 
            ISCardCmd * This,
            /* [retval][out] */ IDispatch **ppByteStringData);
        
        END_INTERFACE
    } ISCardCmdVtbl;

    interface ISCardCmd
    {
        CONST_VTBL struct ISCardCmdVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCardCmd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISCardCmd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISCardCmd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISCardCmd_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISCardCmd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISCardCmd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISCardCmd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISCardCmd_BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,pLe)	\
    ( (This)->lpVtbl -> BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,pLe) ) 

#define ISCardCmd_GetClassId(This,pbyClass)	\
    ( (This)->lpVtbl -> GetClassId(This,pbyClass) ) 

#define ISCardCmd_PutClassId(This,byClass)	\
    ( (This)->lpVtbl -> PutClassId(This,byClass) ) 

#define ISCardCmd_PutAlternateClassId(This,byClass)	\
    ( (This)->lpVtbl -> PutAlternateClassId(This,byClass) ) 

#define ISCardCmd_GetAlternateClassId(This,pbyClass)	\
    ( (This)->lpVtbl -> GetAlternateClassId(This,pbyClass) ) 

#define ISCardCmd_GetInstructionId(This,pbyIns)	\
    ( (This)->lpVtbl -> GetInstructionId(This,pbyIns) ) 

#define ISCardCmd_GetP1(This,pbyP1)	\
    ( (This)->lpVtbl -> GetP1(This,pbyP1) ) 

#define ISCardCmd_GetP2(This,pbyP2)	\
    ( (This)->lpVtbl -> GetP2(This,pbyP2) ) 

#define ISCardCmd_GetP3(This,pbyP3)	\
    ( (This)->lpVtbl -> GetP3(This,pbyP3) ) 

#define ISCardCmd_GetLe(This,plSize)	\
    ( (This)->lpVtbl -> GetLe(This,plSize) ) 

#define ISCardCmd_PutData(This,pData)	\
    ( (This)->lpVtbl -> PutData(This,pData) ) 

#define ISCardCmd_GetData(This,ppData)	\
    ( (This)->lpVtbl -> GetData(This,ppData) ) 

#define ISCardCmd_PutApduReply(This,pReplyApdu)	\
    ( (This)->lpVtbl -> PutApduReply(This,pReplyApdu) ) 

#define ISCardCmd_GetApduReplyLength(This,plSize)	\
    ( (This)->lpVtbl -> GetApduReplyLength(This,plSize) ) 

#define ISCardCmd_GetApduReply(This,ppReplyApdu)	\
    ( (This)->lpVtbl -> GetApduReply(This,ppReplyApdu) ) 

#define ISCardCmd_GetReplyStatus(This,pwStatus)	\
    ( (This)->lpVtbl -> GetReplyStatus(This,pwStatus) ) 

#define ISCardCmd_GetReplyStatusSW1(This,pbySW1)	\
    ( (This)->lpVtbl -> GetReplyStatusSW1(This,pbySW1) ) 

#define ISCardCmd_GetReplyStatusSW2(This,pbySW2)	\
    ( (This)->lpVtbl -> GetReplyStatusSW2(This,pbySW2) ) 

#define ISCardCmd_GetApduLength(This,plSize)	\
    ( (This)->lpVtbl -> GetApduLength(This,plSize) ) 

#define ISCardCmd_GetApdu(This,ppApdu)	\
    ( (This)->lpVtbl -> GetApdu(This,ppApdu) ) 

#define ISCardCmd_PutReplyStatus(This,Status)	\
    ( (This)->lpVtbl -> PutReplyStatus(This,Status) ) 

#define ISCardCmd_PutApdu(This,pApdu)	\
    ( (This)->lpVtbl -> PutApdu(This,pApdu) ) 

#define ISCardCmd_PutInstructionId(This,byIns)	\
    ( (This)->lpVtbl -> PutInstructionId(This,byIns) ) 

#define ISCardCmd_PutP1(This,byP1)	\
    ( (This)->lpVtbl -> PutP1(This,byP1) ) 

#define ISCardCmd_PutP2(This,byP2)	\
    ( (This)->lpVtbl -> PutP2(This,byP2) ) 

#define ISCardCmd_ReturnData(This,ppData)	\
    ( (This)->lpVtbl -> ReturnData(This,ppData) ) 

#define ISCardCmd_ReturnApduReply(This,ppReplyApdu)	\
    ( (This)->lpVtbl -> ReturnApduReply(This,ppReplyApdu) ) 

#define ISCardCmd_BuildCmd2(This,byClassId,byInsId,byP1,byP2,pByteString,pLe)	\
    ( (This)->lpVtbl -> BuildCmd2(This,byClassId,byInsId,byP1,byP2,pByteString,pLe) ) 

#define ISCardCmd_PutData2(This,pByteStringData)	\
    ( (This)->lpVtbl -> PutData2(This,pByteStringData) ) 

#define ISCardCmd_GetData2(This,ppByteStringData)	\
    ( (This)->lpVtbl -> GetData2(This,ppByteStringData) ) 

#define ISCardCmd_PutApduReply2(This,pByteStringReplyApdu)	\
    ( (This)->lpVtbl -> PutApduReply2(This,pByteStringReplyApdu) ) 

#define ISCardCmd_GetApduReply2(This,ppByteStringReplyApdu)	\
    ( (This)->lpVtbl -> GetApduReply2(This,ppByteStringReplyApdu) ) 

#define ISCardCmd_GetDescriptionXML(This,pbstrDescriptionXML)	\
    ( (This)->lpVtbl -> GetDescriptionXML(This,pbstrDescriptionXML) ) 

#define ISCardCmd_PutDescriptionXML(This,bstrDescriptionXML)	\
    ( (This)->lpVtbl -> PutDescriptionXML(This,bstrDescriptionXML) ) 

#define ISCardCmd_GetApduReplyData2(This,ppByteStringReplyData)	\
    ( (This)->lpVtbl -> GetApduReplyData2(This,ppByteStringReplyData) ) 

#define ISCardCmd_GetApdu2(This,ppByteStringData)	\
    ( (This)->lpVtbl -> GetApdu2(This,ppByteStringData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISCardCmd_INTERFACE_DEFINED__ */


#ifndef __ISCardCmd2_INTERFACE_DEFINED__
#define __ISCardCmd2_INTERFACE_DEFINED__

/* interface ISCardCmd2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISCardCmd2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B0B8988-6E95-4515-AE65-67C14933D67F")
    ISCardCmd2 : public ISCardCmd
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BuildCmd3( 
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ LPBYTEBUFFER pbyData,
            /* [in] */ LONG *pLe,
            /* [in] */ BOOL bLeNull) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCardCmd2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISCardCmd2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISCardCmd2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISCardCmd2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISCardCmd2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISCardCmd2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISCardCmd2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISCardCmd2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BuildCmd )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ LPBYTEBUFFER pbyData,
            /* [in] */ LONG *pLe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClassId )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutClassId )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutAlternateClassId )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAlternateClassId )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyClass);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInstructionId )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyIns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP1 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyP1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyP2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP3 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbyP3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLe )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutData )( 
            ISCardCmd2 * This,
            /* [in] */ LPBYTEBUFFER pData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISCardCmd2 * This,
            /* [out] */ LPBYTEBUFFER *ppData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApduReply )( 
            ISCardCmd2 * This,
            /* [in] */ LPBYTEBUFFER pReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReplyLength )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReply )( 
            ISCardCmd2 * This,
            /* [out] */ LPBYTEBUFFER *ppReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatus )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LPWORD pwStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatusSW1 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbySW1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReplyStatusSW2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BYTE *pbySW2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduLength )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LONG *plSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApdu )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LPBYTEBUFFER *ppApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutReplyStatus )( 
            ISCardCmd2 * This,
            /* [in] */ WORD Status);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApdu )( 
            ISCardCmd2 * This,
            /* [in] */ LPBYTEBUFFER pApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutInstructionId )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byIns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutP1 )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byP1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutP2 )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byP2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnData )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LPBYTEBUFFER *ppData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnApduReply )( 
            ISCardCmd2 * This,
            /* [retval][out] */ LPBYTEBUFFER *ppReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BuildCmd2 )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ IDispatch *pByteString,
            /* [in] */ LONG pLe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutData2 )( 
            ISCardCmd2 * This,
            /* [in] */ IDispatch *pByteStringData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ IDispatch **ppByteStringData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutApduReply2 )( 
            ISCardCmd2 * This,
            /* [in] */ IDispatch *pByteStringReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReply2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ IDispatch **ppByteStringReplyApdu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDescriptionXML )( 
            ISCardCmd2 * This,
            /* [retval][out] */ BSTR *pbstrDescriptionXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutDescriptionXML )( 
            ISCardCmd2 * This,
            /* [in] */ BSTR bstrDescriptionXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApduReplyData2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ IDispatch **ppByteStringReplyData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetApdu2 )( 
            ISCardCmd2 * This,
            /* [retval][out] */ IDispatch **ppByteStringData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BuildCmd3 )( 
            ISCardCmd2 * This,
            /* [in] */ BYTE byClassId,
            /* [in] */ BYTE byInsId,
            /* [in] */ BYTE byP1,
            /* [in] */ BYTE byP2,
            /* [in] */ LPBYTEBUFFER pbyData,
            /* [in] */ LONG *pLe,
            /* [in] */ BOOL bLeNull);
        
        END_INTERFACE
    } ISCardCmd2Vtbl;

    interface ISCardCmd2
    {
        CONST_VTBL struct ISCardCmd2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCardCmd2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISCardCmd2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISCardCmd2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISCardCmd2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISCardCmd2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISCardCmd2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISCardCmd2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISCardCmd2_BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,pLe)	\
    ( (This)->lpVtbl -> BuildCmd(This,byClassId,byInsId,byP1,byP2,pbyData,pLe) ) 

#define ISCardCmd2_GetClassId(This,pbyClass)	\
    ( (This)->lpVtbl -> GetClassId(This,pbyClass) ) 

#define ISCardCmd2_PutClassId(This,byClass)	\
    ( (This)->lpVtbl -> PutClassId(This,byClass) ) 

#define ISCardCmd2_PutAlternateClassId(This,byClass)	\
    ( (This)->lpVtbl -> PutAlternateClassId(This,byClass) ) 

#define ISCardCmd2_GetAlternateClassId(This,pbyClass)	\
    ( (This)->lpVtbl -> GetAlternateClassId(This,pbyClass) ) 

#define ISCardCmd2_GetInstructionId(This,pbyIns)	\
    ( (This)->lpVtbl -> GetInstructionId(This,pbyIns) ) 

#define ISCardCmd2_GetP1(This,pbyP1)	\
    ( (This)->lpVtbl -> GetP1(This,pbyP1) ) 

#define ISCardCmd2_GetP2(This,pbyP2)	\
    ( (This)->lpVtbl -> GetP2(This,pbyP2) ) 

#define ISCardCmd2_GetP3(This,pbyP3)	\
    ( (This)->lpVtbl -> GetP3(This,pbyP3) ) 

#define ISCardCmd2_GetLe(This,plSize)	\
    ( (This)->lpVtbl -> GetLe(This,plSize) ) 

#define ISCardCmd2_PutData(This,pData)	\
    ( (This)->lpVtbl -> PutData(This,pData) ) 

#define ISCardCmd2_GetData(This,ppData)	\
    ( (This)->lpVtbl -> GetData(This,ppData) ) 

#define ISCardCmd2_PutApduReply(This,pReplyApdu)	\
    ( (This)->lpVtbl -> PutApduReply(This,pReplyApdu) ) 

#define ISCardCmd2_GetApduReplyLength(This,plSize)	\
    ( (This)->lpVtbl -> GetApduReplyLength(This,plSize) ) 

#define ISCardCmd2_GetApduReply(This,ppReplyApdu)	\
    ( (This)->lpVtbl -> GetApduReply(This,ppReplyApdu) ) 

#define ISCardCmd2_GetReplyStatus(This,pwStatus)	\
    ( (This)->lpVtbl -> GetReplyStatus(This,pwStatus) ) 

#define ISCardCmd2_GetReplyStatusSW1(This,pbySW1)	\
    ( (This)->lpVtbl -> GetReplyStatusSW1(This,pbySW1) ) 

#define ISCardCmd2_GetReplyStatusSW2(This,pbySW2)	\
    ( (This)->lpVtbl -> GetReplyStatusSW2(This,pbySW2) ) 

#define ISCardCmd2_GetApduLength(This,plSize)	\
    ( (This)->lpVtbl -> GetApduLength(This,plSize) ) 

#define ISCardCmd2_GetApdu(This,ppApdu)	\
    ( (This)->lpVtbl -> GetApdu(This,ppApdu) ) 

#define ISCardCmd2_PutReplyStatus(This,Status)	\
    ( (This)->lpVtbl -> PutReplyStatus(This,Status) ) 

#define ISCardCmd2_PutApdu(This,pApdu)	\
    ( (This)->lpVtbl -> PutApdu(This,pApdu) ) 

#define ISCardCmd2_PutInstructionId(This,byIns)	\
    ( (This)->lpVtbl -> PutInstructionId(This,byIns) ) 

#define ISCardCmd2_PutP1(This,byP1)	\
    ( (This)->lpVtbl -> PutP1(This,byP1) ) 

#define ISCardCmd2_PutP2(This,byP2)	\
    ( (This)->lpVtbl -> PutP2(This,byP2) ) 

#define ISCardCmd2_ReturnData(This,ppData)	\
    ( (This)->lpVtbl -> ReturnData(This,ppData) ) 

#define ISCardCmd2_ReturnApduReply(This,ppReplyApdu)	\
    ( (This)->lpVtbl -> ReturnApduReply(This,ppReplyApdu) ) 

#define ISCardCmd2_BuildCmd2(This,byClassId,byInsId,byP1,byP2,pByteString,pLe)	\
    ( (This)->lpVtbl -> BuildCmd2(This,byClassId,byInsId,byP1,byP2,pByteString,pLe) ) 

#define ISCardCmd2_PutData2(This,pByteStringData)	\
    ( (This)->lpVtbl -> PutData2(This,pByteStringData) ) 

#define ISCardCmd2_GetData2(This,ppByteStringData)	\
    ( (This)->lpVtbl -> GetData2(This,ppByteStringData) ) 

#define ISCardCmd2_PutApduReply2(This,pByteStringReplyApdu)	\
    ( (This)->lpVtbl -> PutApduReply2(This,pByteStringReplyApdu) ) 

#define ISCardCmd2_GetApduReply2(This,ppByteStringReplyApdu)	\
    ( (This)->lpVtbl -> GetApduReply2(This,ppByteStringReplyApdu) ) 

#define ISCardCmd2_GetDescriptionXML(This,pbstrDescriptionXML)	\
    ( (This)->lpVtbl -> GetDescriptionXML(This,pbstrDescriptionXML) ) 

#define ISCardCmd2_PutDescriptionXML(This,bstrDescriptionXML)	\
    ( (This)->lpVtbl -> PutDescriptionXML(This,bstrDescriptionXML) ) 

#define ISCardCmd2_GetApduReplyData2(This,ppByteStringReplyData)	\
    ( (This)->lpVtbl -> GetApduReplyData2(This,ppByteStringReplyData) ) 

#define ISCardCmd2_GetApdu2(This,ppByteStringData)	\
    ( (This)->lpVtbl -> GetApdu2(This,ppByteStringData) ) 


#define ISCardCmd2_BuildCmd3(This,byClassId,byInsId,byP1,byP2,pbyData,pLe,bLeNull)	\
    ( (This)->lpVtbl -> BuildCmd3(This,byClassId,byInsId,byP1,byP2,pbyData,pLe,bLeNull) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISCardCmd2_INTERFACE_DEFINED__ */


#ifndef __ISCard_INTERFACE_DEFINED__
#define __ISCard_INTERFACE_DEFINED__

/* interface ISCard */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [public] */ ULONG_PTR HSCARD;


EXTERN_C const IID IID_ISCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31D700C5-104E-4632-8042-B23B7F01764A")
    ISCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachByReader( 
            /* [in] */ BSTR bstrReaderName,
            /* [in] */ SCARD_SHARE_MODES ShareMode,
            /* [in] */ SCARD_PROTOCOLS PrefProtocol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Transaction( 
            /* [out][in] */ LPSCARDCMD *ppCmd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockSCard( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReAttach( 
            /* [in] */ SCARD_SHARE_MODES ShareMode,
            /* [in] */ SCARD_DISPOSITIONS InitState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockSCard( 
            /* [in] */ SCARD_DISPOSITIONS Disposition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachByHandle( 
            /* [in] */ HSCARD hCard) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISCard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISCard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachByReader )( 
            ISCard * This,
            /* [in] */ BSTR bstrReaderName,
            /* [in] */ SCARD_SHARE_MODES ShareMode,
            /* [in] */ SCARD_PROTOCOLS PrefProtocol);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Transaction )( 
            ISCard * This,
            /* [out][in] */ LPSCARDCMD *ppCmd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockSCard )( 
            ISCard * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReAttach )( 
            ISCard * This,
            /* [in] */ SCARD_SHARE_MODES ShareMode,
            /* [in] */ SCARD_DISPOSITIONS InitState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockSCard )( 
            ISCard * This,
            /* [in] */ SCARD_DISPOSITIONS Disposition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachByHandle )( 
            ISCard * This,
            /* [in] */ HSCARD hCard);
        
        END_INTERFACE
    } ISCardVtbl;

    interface ISCard
    {
        CONST_VTBL struct ISCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISCard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISCard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISCard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISCard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISCard_AttachByReader(This,bstrReaderName,ShareMode,PrefProtocol)	\
    ( (This)->lpVtbl -> AttachByReader(This,bstrReaderName,ShareMode,PrefProtocol) ) 

#define ISCard_Transaction(This,ppCmd)	\
    ( (This)->lpVtbl -> Transaction(This,ppCmd) ) 

#define ISCard_LockSCard(This)	\
    ( (This)->lpVtbl -> LockSCard(This) ) 

#define ISCard_ReAttach(This,ShareMode,InitState)	\
    ( (This)->lpVtbl -> ReAttach(This,ShareMode,InitState) ) 

#define ISCard_UnlockSCard(This,Disposition)	\
    ( (This)->lpVtbl -> UnlockSCard(This,Disposition) ) 

#define ISCard_AttachByHandle(This,hCard)	\
    ( (This)->lpVtbl -> AttachByHandle(This,hCard) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISCard_INTERFACE_DEFINED__ */



#ifndef __ESCARDCOMLib_LIBRARY_DEFINED__
#define __ESCARDCOMLib_LIBRARY_DEFINED__

/* library ESCARDCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ESCARDCOMLib;

EXTERN_C const CLSID CLSID_ByteBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("8E444EC7-5935-49f8-B386-1343C1BFD4CF")
ByteBuffer;
#endif

EXTERN_C const CLSID CLSID_SCardCmd;

#ifdef __cplusplus

class DECLSPEC_UUID("D7083CF0-B6F1-4653-B98C-9397457BC49D")
SCardCmd;
#endif

EXTERN_C const CLSID CLSID_SCard;

#ifdef __cplusplus

class DECLSPEC_UUID("D2759D85-9FD0-4bcd-933C-4FFA203EE6C6")
SCard;
#endif
#endif /* __ESCARDCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


