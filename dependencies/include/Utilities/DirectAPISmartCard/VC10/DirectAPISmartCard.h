

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Mar 30 06:00:58 2018
 */
/* Compiler settings for ..\..\DirectAPISmartCard\DirectAPISmartCard.idl:
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

#ifndef __DirectAPISmartCard_h__
#define __DirectAPISmartCard_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDirectAPISmartCard_FWD_DEFINED__
#define __IDirectAPISmartCard_FWD_DEFINED__
typedef interface IDirectAPISmartCard IDirectAPISmartCard;
#endif 	/* __IDirectAPISmartCard_FWD_DEFINED__ */


#ifndef __DirectAPISmartCard_FWD_DEFINED__
#define __DirectAPISmartCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class DirectAPISmartCard DirectAPISmartCard;
#else
typedef struct DirectAPISmartCard DirectAPISmartCard;
#endif /* __cplusplus */

#endif 	/* __DirectAPISmartCard_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDirectAPISmartCard_INTERFACE_DEFINED__
#define __IDirectAPISmartCard_INTERFACE_DEFINED__

/* interface IDirectAPISmartCard */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDirectAPISmartCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0075D009-D1BB-4E14-9C1C-11CF0783753C")
    IDirectAPISmartCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateClientUnlockKey( 
            /* [in] */ BSTR xmlIn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDirectAPISmartCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDirectAPISmartCard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDirectAPISmartCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDirectAPISmartCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDirectAPISmartCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDirectAPISmartCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDirectAPISmartCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDirectAPISmartCard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateClientUnlockKey )( 
            IDirectAPISmartCard * This,
            /* [in] */ BSTR xmlIn);
        
        END_INTERFACE
    } IDirectAPISmartCardVtbl;

    interface IDirectAPISmartCard
    {
        CONST_VTBL struct IDirectAPISmartCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDirectAPISmartCard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDirectAPISmartCard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDirectAPISmartCard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDirectAPISmartCard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDirectAPISmartCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDirectAPISmartCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDirectAPISmartCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDirectAPISmartCard_UpdateClientUnlockKey(This,xmlIn)	\
    ( (This)->lpVtbl -> UpdateClientUnlockKey(This,xmlIn) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDirectAPISmartCard_INTERFACE_DEFINED__ */



#ifndef __DirectAPISmartCardLib_LIBRARY_DEFINED__
#define __DirectAPISmartCardLib_LIBRARY_DEFINED__

/* library DirectAPISmartCardLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DirectAPISmartCardLib;

EXTERN_C const CLSID CLSID_DirectAPISmartCard;

#ifdef __cplusplus

class DECLSPEC_UUID("6BCECBD1-A108-4ED7-AAE4-A957591A9CFF")
DirectAPISmartCard;
#endif
#endif /* __DirectAPISmartCardLib_LIBRARY_DEFINED__ */

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


