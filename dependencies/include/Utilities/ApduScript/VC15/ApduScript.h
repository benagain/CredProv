

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\ApduScript\ApduScript.idl:
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

#ifndef __ApduScript_h__
#define __ApduScript_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IApduScripter_FWD_DEFINED__
#define __IApduScripter_FWD_DEFINED__
typedef interface IApduScripter IApduScripter;

#endif 	/* __IApduScripter_FWD_DEFINED__ */


#ifndef __ApduScripter_FWD_DEFINED__
#define __ApduScripter_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApduScripter ApduScripter;
#else
typedef struct ApduScripter ApduScripter;
#endif /* __cplusplus */

#endif 	/* __ApduScripter_FWD_DEFINED__ */


#ifndef __APDUScriptProcessor_FWD_DEFINED__
#define __APDUScriptProcessor_FWD_DEFINED__

#ifdef __cplusplus
typedef class APDUScriptProcessor APDUScriptProcessor;
#else
typedef struct APDUScriptProcessor APDUScriptProcessor;
#endif /* __cplusplus */

#endif 	/* __APDUScriptProcessor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "APDUCard.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IApduScripter_INTERFACE_DEFINED__
#define __IApduScripter_INTERFACE_DEFINED__

/* interface IApduScripter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IApduScripter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42F54340-85AC-4E89-BBA5-3F6A5A224595")
    IApduScripter : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Script( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Script( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AppendCommand( 
            /* [in] */ ISCardCmd *pCommand) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNextCommand( 
            /* [in] */ ISCardCmd *pResultsOfPreviousCommand,
            /* [out] */ ISCardCmd **ppNextCommand,
            /* [retval][out] */ short *MoreCommandsInScript) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IApduScripterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApduScripter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApduScripter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApduScripter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApduScripter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApduScripter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApduScripter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApduScripter * This,
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
            IApduScripter * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Script )( 
            IApduScripter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Script )( 
            IApduScripter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AppendCommand )( 
            IApduScripter * This,
            /* [in] */ ISCardCmd *pCommand);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNextCommand )( 
            IApduScripter * This,
            /* [in] */ ISCardCmd *pResultsOfPreviousCommand,
            /* [out] */ ISCardCmd **ppNextCommand,
            /* [retval][out] */ short *MoreCommandsInScript);
        
        END_INTERFACE
    } IApduScripterVtbl;

    interface IApduScripter
    {
        CONST_VTBL struct IApduScripterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApduScripter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApduScripter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApduScripter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApduScripter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApduScripter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApduScripter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApduScripter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApduScripter_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IApduScripter_get_Script(This,pVal)	\
    ( (This)->lpVtbl -> get_Script(This,pVal) ) 

#define IApduScripter_put_Script(This,newVal)	\
    ( (This)->lpVtbl -> put_Script(This,newVal) ) 

#define IApduScripter_AppendCommand(This,pCommand)	\
    ( (This)->lpVtbl -> AppendCommand(This,pCommand) ) 

#define IApduScripter_GetNextCommand(This,pResultsOfPreviousCommand,ppNextCommand,MoreCommandsInScript)	\
    ( (This)->lpVtbl -> GetNextCommand(This,pResultsOfPreviousCommand,ppNextCommand,MoreCommandsInScript) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApduScripter_INTERFACE_DEFINED__ */



#ifndef __APDUSCRIPTLib_LIBRARY_DEFINED__
#define __APDUSCRIPTLib_LIBRARY_DEFINED__

/* library APDUSCRIPTLib */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_APDUSCRIPTLib;

EXTERN_C const CLSID CLSID_ApduScripter;

#ifdef __cplusplus

class DECLSPEC_UUID("68E878A7-8AF0-433A-A5FF-3AC9D2A2E602")
ApduScripter;
#endif

EXTERN_C const CLSID CLSID_APDUScriptProcessor;

#ifdef __cplusplus

class DECLSPEC_UUID("BC574BBC-CB65-4ede-999F-51A4DF4B4B4D")
APDUScriptProcessor;
#endif
#endif /* __APDUSCRIPTLib_LIBRARY_DEFINED__ */

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


