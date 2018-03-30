

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\CSP COM\CSP COM.idl:
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

#ifndef __CSP_COM_h__
#define __CSP_COM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICSPSmartCard_FWD_DEFINED__
#define __ICSPSmartCard_FWD_DEFINED__
typedef interface ICSPSmartCard ICSPSmartCard;

#endif 	/* __ICSPSmartCard_FWD_DEFINED__ */


#ifndef __ICSPUtils_FWD_DEFINED__
#define __ICSPUtils_FWD_DEFINED__
typedef interface ICSPUtils ICSPUtils;

#endif 	/* __ICSPUtils_FWD_DEFINED__ */


#ifndef __CSPSmartCard_FWD_DEFINED__
#define __CSPSmartCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSPSmartCard CSPSmartCard;
#else
typedef struct CSPSmartCard CSPSmartCard;
#endif /* __cplusplus */

#endif 	/* __CSPSmartCard_FWD_DEFINED__ */


#ifndef __CSPUtils_FWD_DEFINED__
#define __CSPUtils_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSPUtils CSPUtils;
#else
typedef struct CSPUtils CSPUtils;
#endif /* __cplusplus */

#endif 	/* __CSPUtils_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICSPSmartCard_INTERFACE_DEFINED__
#define __ICSPSmartCard_INTERFACE_DEFINED__

/* interface ICSPSmartCard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICSPSmartCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81BAF9DC-59A5-4F6C-9D67-4A492D6750E1")
    ICSPSmartCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumerateSmartCardCertificates( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CSPContainerDetails( 
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICSPSmartCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICSPSmartCard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICSPSmartCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICSPSmartCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICSPSmartCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICSPSmartCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICSPSmartCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICSPSmartCard * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateSmartCardCertificates )( 
            ICSPSmartCard * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CSPContainerDetails )( 
            ICSPSmartCard * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        END_INTERFACE
    } ICSPSmartCardVtbl;

    interface ICSPSmartCard
    {
        CONST_VTBL struct ICSPSmartCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICSPSmartCard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICSPSmartCard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICSPSmartCard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICSPSmartCard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICSPSmartCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICSPSmartCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICSPSmartCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICSPSmartCard_EnumerateSmartCardCertificates(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> EnumerateSmartCardCertificates(This,xmlInput,xmlOutput) ) 

#define ICSPSmartCard_CSPContainerDetails(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> CSPContainerDetails(This,xmlIn,xmlOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICSPSmartCard_INTERFACE_DEFINED__ */


#ifndef __ICSPUtils_INTERFACE_DEFINED__
#define __ICSPUtils_INTERFACE_DEFINED__

/* interface ICSPUtils */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICSPUtils;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF937333-847F-4557-ABAC-894710E09C9F")
    ICSPUtils : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeASNCertificates( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeASNCertificatesSerialNumbers( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifyRevocationStatusASNCertificates( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Decrypt( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifyASNCertificate( 
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SilentCSPLogin( 
            /* [in] */ BSTR xmlInput,
            /* [out] */ unsigned long *hCSP,
            /* [out] */ BSTR *bstrContainerName,
            /* [retval][out] */ long *lErrorCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SilentCSPLogin64( 
            /* [in] */ BSTR xmlInput,
            /* [out] */ ULONG_PTR *hCSP,
            /* [out] */ BSTR *bstrContainerName,
            /* [retval][out] */ long *lErrorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICSPUtilsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICSPUtils * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICSPUtils * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICSPUtils * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICSPUtils * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICSPUtils * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICSPUtils * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICSPUtils * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeASNCertificates )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeASNCertificatesSerialNumbers )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifyRevocationStatusASNCertificates )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Decrypt )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Verify )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifyASNCertificate )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [retval][out] */ BSTR *xmlOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SilentCSPLogin )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [out] */ unsigned long *hCSP,
            /* [out] */ BSTR *bstrContainerName,
            /* [retval][out] */ long *lErrorCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SilentCSPLogin64 )( 
            ICSPUtils * This,
            /* [in] */ BSTR xmlInput,
            /* [out] */ ULONG_PTR *hCSP,
            /* [out] */ BSTR *bstrContainerName,
            /* [retval][out] */ long *lErrorCode);
        
        END_INTERFACE
    } ICSPUtilsVtbl;

    interface ICSPUtils
    {
        CONST_VTBL struct ICSPUtilsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICSPUtils_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICSPUtils_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICSPUtils_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICSPUtils_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICSPUtils_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICSPUtils_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICSPUtils_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICSPUtils_DecodeASNCertificates(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> DecodeASNCertificates(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_DecodeASNCertificatesSerialNumbers(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> DecodeASNCertificatesSerialNumbers(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_VerifyRevocationStatusASNCertificates(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> VerifyRevocationStatusASNCertificates(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_Decrypt(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> Decrypt(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_Encrypt(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> Encrypt(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_Sign(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> Sign(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_Verify(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> Verify(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_VerifyASNCertificate(This,xmlInput,xmlOutput)	\
    ( (This)->lpVtbl -> VerifyASNCertificate(This,xmlInput,xmlOutput) ) 

#define ICSPUtils_SilentCSPLogin(This,xmlInput,hCSP,bstrContainerName,lErrorCode)	\
    ( (This)->lpVtbl -> SilentCSPLogin(This,xmlInput,hCSP,bstrContainerName,lErrorCode) ) 

#define ICSPUtils_SilentCSPLogin64(This,xmlInput,hCSP,bstrContainerName,lErrorCode)	\
    ( (This)->lpVtbl -> SilentCSPLogin64(This,xmlInput,hCSP,bstrContainerName,lErrorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICSPUtils_INTERFACE_DEFINED__ */



#ifndef __CSPCOMLib_LIBRARY_DEFINED__
#define __CSPCOMLib_LIBRARY_DEFINED__

/* library CSPCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CSPCOMLib;

EXTERN_C const CLSID CLSID_CSPSmartCard;

#ifdef __cplusplus

class DECLSPEC_UUID("B649E09F-E0DC-4859-BF80-517E16875BDF")
CSPSmartCard;
#endif

EXTERN_C const CLSID CLSID_CSPUtils;

#ifdef __cplusplus

class DECLSPEC_UUID("6F9FD81E-85CC-4FD6-B97F-855A3C023E60")
CSPUtils;
#endif
#endif /* __CSPCOMLib_LIBRARY_DEFINED__ */

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


