

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\BiometricConnector\Eft\EftEdit\EftEdit.idl:
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

#ifndef __EftEdit_h__
#define __EftEdit_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEftEditor_FWD_DEFINED__
#define __IEftEditor_FWD_DEFINED__
typedef interface IEftEditor IEftEditor;

#endif 	/* __IEftEditor_FWD_DEFINED__ */


#ifndef __EftEditor_FWD_DEFINED__
#define __EftEditor_FWD_DEFINED__

#ifdef __cplusplus
typedef class EftEditor EftEditor;
#else
typedef struct EftEditor EftEditor;
#endif /* __cplusplus */

#endif 	/* __EftEditor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IEftEditor_INTERFACE_DEFINED__
#define __IEftEditor_INTERFACE_DEFINED__

/* interface IEftEditor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEftEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("80096457-EDF4-43AE-8B05-6E7E4E113FB0")
    IEftEditor : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TransformXml( 
            /* [in] */ BSTR eftBase64,
            /* [in] */ BSTR userData,
            /* [retval][out] */ BSTR *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MakeBinary( 
            /* [in] */ BSTR eftNistXml,
            /* [retval][out] */ BSTR *base64) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEftEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEftEditor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEftEditor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEftEditor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEftEditor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEftEditor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEftEditor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEftEditor * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TransformXml )( 
            IEftEditor * This,
            /* [in] */ BSTR eftBase64,
            /* [in] */ BSTR userData,
            /* [retval][out] */ BSTR *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MakeBinary )( 
            IEftEditor * This,
            /* [in] */ BSTR eftNistXml,
            /* [retval][out] */ BSTR *base64);
        
        END_INTERFACE
    } IEftEditorVtbl;

    interface IEftEditor
    {
        CONST_VTBL struct IEftEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEftEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEftEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEftEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEftEditor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEftEditor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEftEditor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEftEditor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEftEditor_TransformXml(This,eftBase64,userData,result)	\
    ( (This)->lpVtbl -> TransformXml(This,eftBase64,userData,result) ) 

#define IEftEditor_MakeBinary(This,eftNistXml,base64)	\
    ( (This)->lpVtbl -> MakeBinary(This,eftNistXml,base64) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEftEditor_INTERFACE_DEFINED__ */



#ifndef __EftEditLib_LIBRARY_DEFINED__
#define __EftEditLib_LIBRARY_DEFINED__

/* library EftEditLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_EftEditLib;

EXTERN_C const CLSID CLSID_EftEditor;

#ifdef __cplusplus

class DECLSPEC_UUID("B780C068-3DC4-4CC9-83CA-2DDD9F5EAD17")
EftEditor;
#endif
#endif /* __EftEditLib_LIBRARY_DEFINED__ */

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


