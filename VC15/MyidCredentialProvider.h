

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for MyidCredentialProvider.idl:
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

#ifndef __MyidCredentialProvider_h__
#define __MyidCredentialProvider_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVscProvider_FWD_DEFINED__
#define __IVscProvider_FWD_DEFINED__
typedef interface IVscProvider IVscProvider;

#endif 	/* __IVscProvider_FWD_DEFINED__ */


#ifndef __VscProvider_FWD_DEFINED__
#define __VscProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class VscProvider VscProvider;
#else
typedef struct VscProvider VscProvider;
#endif /* __cplusplus */

#endif 	/* __VscProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IVscProvider_INTERFACE_DEFINED__
#define __IVscProvider_INTERFACE_DEFINED__

/* interface IVscProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVscProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C632CE6-8DB6-4D12-9E4D-A08C83B6D93E")
    IVscProvider : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IVscProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVscProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVscProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVscProvider * This);
        
        END_INTERFACE
    } IVscProviderVtbl;

    interface IVscProvider
    {
        CONST_VTBL struct IVscProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVscProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVscProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVscProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVscProvider_INTERFACE_DEFINED__ */



#ifndef __MyidCredentialProviderLib_LIBRARY_DEFINED__
#define __MyidCredentialProviderLib_LIBRARY_DEFINED__

/* library MyidCredentialProviderLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MyidCredentialProviderLib;

EXTERN_C const CLSID CLSID_VscProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("1CC50896-EBD5-4A38-8EAA-5FA3AD853599")
VscProvider;
#endif
#endif /* __MyidCredentialProviderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


