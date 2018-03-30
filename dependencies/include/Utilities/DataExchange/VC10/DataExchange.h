

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:00:57 2018
 */
/* Compiler settings for ..\..\DataExchange\DataExchange.idl:
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

#ifndef __DataExchange_h__
#define __DataExchange_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDataBuffer_FWD_DEFINED__
#define __IDataBuffer_FWD_DEFINED__
typedef interface IDataBuffer IDataBuffer;
#endif 	/* __IDataBuffer_FWD_DEFINED__ */


#ifndef __IDataXBuffer_FWD_DEFINED__
#define __IDataXBuffer_FWD_DEFINED__
typedef interface IDataXBuffer IDataXBuffer;
#endif 	/* __IDataXBuffer_FWD_DEFINED__ */


#ifndef __ICreateGuid_FWD_DEFINED__
#define __ICreateGuid_FWD_DEFINED__
typedef interface ICreateGuid ICreateGuid;
#endif 	/* __ICreateGuid_FWD_DEFINED__ */


#ifndef __DataBuffer_FWD_DEFINED__
#define __DataBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataBuffer DataBuffer;
#else
typedef struct DataBuffer DataBuffer;
#endif /* __cplusplus */

#endif 	/* __DataBuffer_FWD_DEFINED__ */


#ifndef __DataXBuffer_FWD_DEFINED__
#define __DataXBuffer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataXBuffer DataXBuffer;
#else
typedef struct DataXBuffer DataXBuffer;
#endif /* __cplusplus */

#endif 	/* __DataXBuffer_FWD_DEFINED__ */


#ifndef __CreateGuid_FWD_DEFINED__
#define __CreateGuid_FWD_DEFINED__

#ifdef __cplusplus
typedef class CreateGuid CreateGuid;
#else
typedef struct CreateGuid CreateGuid;
#endif /* __cplusplus */

#endif 	/* __CreateGuid_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "eSCardCOM.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_DataExchange_0000_0000 */
/* [local] */ 

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("01529A4D-380B-4a46-91A0-006E3F722961") 
enum EDataFormat
    {	Empty	= 0,
	Raw	= 1,
	Base64	= 2,
	Hex	= 3,
	Base64Hex	= 4
    } 	EDataFormat;



extern RPC_IF_HANDLE __MIDL_itf_DataExchange_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DataExchange_0000_0000_v0_0_s_ifspec;

#ifndef __IDataBuffer_INTERFACE_DEFINED__
#define __IDataBuffer_INTERFACE_DEFINED__

/* interface IDataBuffer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C310001-DE04-4D6B-9736-03FC087B4CF5")
    IDataBuffer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteHex( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadHex( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBase64( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBase64( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBase64Hex( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBase64Hex( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteData( 
            /* [in] */ long lLengthOfData,
            /* [size_is][in] */ byte *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadData( 
            /* [in] */ long lLengthOfData,
            /* [size_is][out][in] */ byte *data) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataLength( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Empty( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteAPDU( 
            /* [in] */ LPSCARDCMD ptrSCardCmd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadAPDU( 
            /* [retval][out] */ ISCardCmd **ptrSCardCmd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataBuffer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataBuffer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataBuffer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataBuffer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataBuffer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteHex )( 
            IDataBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadHex )( 
            IDataBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBase64 )( 
            IDataBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBase64 )( 
            IDataBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBase64Hex )( 
            IDataBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBase64Hex )( 
            IDataBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteData )( 
            IDataBuffer * This,
            /* [in] */ long lLengthOfData,
            /* [size_is][in] */ byte *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadData )( 
            IDataBuffer * This,
            /* [in] */ long lLengthOfData,
            /* [size_is][out][in] */ byte *data);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataLength )( 
            IDataBuffer * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Empty )( 
            IDataBuffer * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IDataBuffer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteAPDU )( 
            IDataBuffer * This,
            /* [in] */ LPSCARDCMD ptrSCardCmd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadAPDU )( 
            IDataBuffer * This,
            /* [retval][out] */ ISCardCmd **ptrSCardCmd);
        
        END_INTERFACE
    } IDataBufferVtbl;

    interface IDataBuffer
    {
        CONST_VTBL struct IDataBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataBuffer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDataBuffer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDataBuffer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDataBuffer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDataBuffer_WriteHex(This,data)	\
    ( (This)->lpVtbl -> WriteHex(This,data) ) 

#define IDataBuffer_ReadHex(This,data)	\
    ( (This)->lpVtbl -> ReadHex(This,data) ) 

#define IDataBuffer_WriteBase64(This,data)	\
    ( (This)->lpVtbl -> WriteBase64(This,data) ) 

#define IDataBuffer_ReadBase64(This,data)	\
    ( (This)->lpVtbl -> ReadBase64(This,data) ) 

#define IDataBuffer_WriteBase64Hex(This,data)	\
    ( (This)->lpVtbl -> WriteBase64Hex(This,data) ) 

#define IDataBuffer_ReadBase64Hex(This,data)	\
    ( (This)->lpVtbl -> ReadBase64Hex(This,data) ) 

#define IDataBuffer_WriteData(This,lLengthOfData,data)	\
    ( (This)->lpVtbl -> WriteData(This,lLengthOfData,data) ) 

#define IDataBuffer_ReadData(This,lLengthOfData,data)	\
    ( (This)->lpVtbl -> ReadData(This,lLengthOfData,data) ) 

#define IDataBuffer_get_DataLength(This,pVal)	\
    ( (This)->lpVtbl -> get_DataLength(This,pVal) ) 

#define IDataBuffer_get_Empty(This,pVal)	\
    ( (This)->lpVtbl -> get_Empty(This,pVal) ) 

#define IDataBuffer_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IDataBuffer_WriteAPDU(This,ptrSCardCmd)	\
    ( (This)->lpVtbl -> WriteAPDU(This,ptrSCardCmd) ) 

#define IDataBuffer_ReadAPDU(This,ptrSCardCmd)	\
    ( (This)->lpVtbl -> ReadAPDU(This,ptrSCardCmd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataBuffer_INTERFACE_DEFINED__ */


#ifndef __IDataXBuffer_INTERFACE_DEFINED__
#define __IDataXBuffer_INTERFACE_DEFINED__

/* interface IDataXBuffer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataXBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A77DAC04-B682-4097-A50E-16AA6DDCDF94")
    IDataXBuffer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteHex( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadHex( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBase64( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBase64( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBase64Hex( 
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBase64Hex( 
            /* [retval][out] */ BSTR *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteData( 
            /* [in] */ long lLengthOfData,
            /* [size_is][in] */ byte *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadData( 
            /* [in] */ long lLengthOfData,
            /* [size_is][out][in] */ byte *data) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataLength( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Empty( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataXBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataXBuffer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataXBuffer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataXBuffer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataXBuffer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataXBuffer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataXBuffer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataXBuffer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteHex )( 
            IDataXBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadHex )( 
            IDataXBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBase64 )( 
            IDataXBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBase64 )( 
            IDataXBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBase64Hex )( 
            IDataXBuffer * This,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBase64Hex )( 
            IDataXBuffer * This,
            /* [retval][out] */ BSTR *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteData )( 
            IDataXBuffer * This,
            /* [in] */ long lLengthOfData,
            /* [size_is][in] */ byte *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadData )( 
            IDataXBuffer * This,
            /* [in] */ long lLengthOfData,
            /* [size_is][out][in] */ byte *data);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataLength )( 
            IDataXBuffer * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Empty )( 
            IDataXBuffer * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IDataXBuffer * This);
        
        END_INTERFACE
    } IDataXBufferVtbl;

    interface IDataXBuffer
    {
        CONST_VTBL struct IDataXBufferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataXBuffer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDataXBuffer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDataXBuffer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDataXBuffer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDataXBuffer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDataXBuffer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDataXBuffer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDataXBuffer_WriteHex(This,data)	\
    ( (This)->lpVtbl -> WriteHex(This,data) ) 

#define IDataXBuffer_ReadHex(This,data)	\
    ( (This)->lpVtbl -> ReadHex(This,data) ) 

#define IDataXBuffer_WriteBase64(This,data)	\
    ( (This)->lpVtbl -> WriteBase64(This,data) ) 

#define IDataXBuffer_ReadBase64(This,data)	\
    ( (This)->lpVtbl -> ReadBase64(This,data) ) 

#define IDataXBuffer_WriteBase64Hex(This,data)	\
    ( (This)->lpVtbl -> WriteBase64Hex(This,data) ) 

#define IDataXBuffer_ReadBase64Hex(This,data)	\
    ( (This)->lpVtbl -> ReadBase64Hex(This,data) ) 

#define IDataXBuffer_WriteData(This,lLengthOfData,data)	\
    ( (This)->lpVtbl -> WriteData(This,lLengthOfData,data) ) 

#define IDataXBuffer_ReadData(This,lLengthOfData,data)	\
    ( (This)->lpVtbl -> ReadData(This,lLengthOfData,data) ) 

#define IDataXBuffer_get_DataLength(This,pVal)	\
    ( (This)->lpVtbl -> get_DataLength(This,pVal) ) 

#define IDataXBuffer_get_Empty(This,pVal)	\
    ( (This)->lpVtbl -> get_Empty(This,pVal) ) 

#define IDataXBuffer_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDataXBuffer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_DataExchange_0000_0002 */
/* [local] */ 

typedef /* [helpstring][uuid] */  DECLSPEC_UUID("93E7DA88-5DDE-4f08-85F5-AF3819091C64") 
enum EGuidFormat
    {	GuidFormatStandard	= 0
    } 	EGuidFormat;



extern RPC_IF_HANDLE __MIDL_itf_DataExchange_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_DataExchange_0000_0002_v0_0_s_ifspec;

#ifndef __ICreateGuid_INTERFACE_DEFINED__
#define __ICreateGuid_INTERFACE_DEFINED__

/* interface ICreateGuid */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICreateGuid;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19A14D1D-6266-422C-8559-35AAB53D0B0D")
    ICreateGuid : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ EGuidFormat Format,
            /* [retval][out] */ BSTR *bstrGuid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateGuidVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICreateGuid * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICreateGuid * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICreateGuid * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICreateGuid * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICreateGuid * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICreateGuid * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICreateGuid * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            ICreateGuid * This,
            /* [in] */ EGuidFormat Format,
            /* [retval][out] */ BSTR *bstrGuid);
        
        END_INTERFACE
    } ICreateGuidVtbl;

    interface ICreateGuid
    {
        CONST_VTBL struct ICreateGuidVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateGuid_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICreateGuid_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICreateGuid_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICreateGuid_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICreateGuid_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICreateGuid_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICreateGuid_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICreateGuid_Create(This,Format,bstrGuid)	\
    ( (This)->lpVtbl -> Create(This,Format,bstrGuid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICreateGuid_INTERFACE_DEFINED__ */



#ifndef __DATAEXCHANGELib_LIBRARY_DEFINED__
#define __DATAEXCHANGELib_LIBRARY_DEFINED__

/* library DATAEXCHANGELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DATAEXCHANGELib;

EXTERN_C const CLSID CLSID_DataBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("07F9AB62-0C50-419C-B24E-66F9E5FDCE1E")
DataBuffer;
#endif

EXTERN_C const CLSID CLSID_DataXBuffer;

#ifdef __cplusplus

class DECLSPEC_UUID("09997331-906E-4732-95C2-06A811017C04")
DataXBuffer;
#endif

EXTERN_C const CLSID CLSID_CreateGuid;

#ifdef __cplusplus

class DECLSPEC_UUID("C3586479-E0B2-4CD9-A37F-A8E0FC1C3F85")
CreateGuid;
#endif
#endif /* __DATAEXCHANGELib_LIBRARY_DEFINED__ */

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


