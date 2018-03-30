

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for ..\..\EdeficeSmartCard\EdeficeSmartCard.idl:
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

#ifndef __EdeficeSmartCard_h__
#define __EdeficeSmartCard_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISmartCard_FWD_DEFINED__
#define __ISmartCard_FWD_DEFINED__
typedef interface ISmartCard ISmartCard;

#endif 	/* __ISmartCard_FWD_DEFINED__ */


#ifndef __ISmartCard2_FWD_DEFINED__
#define __ISmartCard2_FWD_DEFINED__
typedef interface ISmartCard2 ISmartCard2;

#endif 	/* __ISmartCard2_FWD_DEFINED__ */


#ifndef __SmartCard_FWD_DEFINED__
#define __SmartCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class SmartCard SmartCard;
#else
typedef struct SmartCard SmartCard;
#endif /* __cplusplus */

#endif 	/* __SmartCard_FWD_DEFINED__ */


#ifndef __Win32APDUCard_FWD_DEFINED__
#define __Win32APDUCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class Win32APDUCard Win32APDUCard;
#else
typedef struct Win32APDUCard Win32APDUCard;
#endif /* __cplusplus */

#endif 	/* __Win32APDUCard_FWD_DEFINED__ */


#ifndef __DK_APDUCard_FWD_DEFINED__
#define __DK_APDUCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class DK_APDUCard DK_APDUCard;
#else
typedef struct DK_APDUCard DK_APDUCard;
#endif /* __cplusplus */

#endif 	/* __DK_APDUCard_FWD_DEFINED__ */


#ifndef __PivApduCard_FWD_DEFINED__
#define __PivApduCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class PivApduCard PivApduCard;
#else
typedef struct PivApduCard PivApduCard;
#endif /* __cplusplus */

#endif 	/* __PivApduCard_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "Envelope COM.h"
#include "APDUCard.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_EdeficeSmartCard_0000_0000 */
/* [local] */ 

typedef 
enum tagDATAWRITE
    {
        DATAWRITE_PUBLIC	= 1,
        DATAWRITE_PRIVATE	= 0,
        DATAWRITE_MIXED	= 3
    } 	DATAWRITE;



extern RPC_IF_HANDLE __MIDL_itf_EdeficeSmartCard_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_EdeficeSmartCard_0000_0000_v0_0_s_ifspec;

#ifndef __ISmartCard_INTERFACE_DEFINED__
#define __ISmartCard_INTERFACE_DEFINED__

/* interface ISmartCard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISmartCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E914131-FDCE-4A7B-B4EC-A90C551EB8D3")
    ISmartCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Enumerate( 
            /* [retval][out] */ BSTR *bstrXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCardDetails( 
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Login( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPIN,
            /* [in] */ VARIANT_BOOL PINExpiry) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangePIN( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldPIN,
            /* [in] */ BSTR bstrNewPIN) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logout( 
            /* [in] */ BSTR bstrSN) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLoggedIn( 
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ VARIANT_BOOL *LoggedIn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialise( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrUnlockCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockCard( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode,
            /* [in] */ BSTR bstrNewPIN) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DataWrite( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [in] */ BSTR bstrData,
            /* [in] */ short Public) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DataRead( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [retval][out] */ BSTR *bstrData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DataDelete( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DataRename( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldDataName,
            /* [in] */ BSTR bstrOldChunkName,
            /* [in] */ BSTR bstrNewDataName,
            /* [in] */ BSTR bstrNewChunkName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateRandomString( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ int nSize,
            /* [in] */ BSTR bstrSeed,
            /* [retval][out] */ BSTR *bstrRandomString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreatePKCS10( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [retval][out] */ BSTR *bstrPKCS10) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AcceptPKCS7( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNewEncryptKeyPair( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicEncryptKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateNewSignKeyPair( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicSignKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateKeyPair( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveServerPublicEncryptKey( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicEncryptKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveServerPublicSignKey( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicSignKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SHA1( 
            /* [in] */ BSTR bstrDataIn,
            /* [retval][out] */ BSTR *bstrDataOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitialiseEx( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ BSTR bstrExInitialisationData,
            /* [in] */ BSTR bstrExInitialisationData2,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrDeviceInitialisationData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetCard( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteCertificates( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeleteContainersXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreatePKCS10Ex( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrPKCS10) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialisation( 
            /* [in] */ BSTR InitXML,
            /* [retval][out] */ BSTR *ReturnXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockCardEx( 
            /* [in] */ BSTR UnlockXML,
            /* [retval][out] */ BSTR *ReturnXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AcceptPKCS7Ex( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUnlockChallenge( 
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockCard( 
            /* [in] */ BSTR bstrXML,
            /* [retval][out] */ BSTR *bstrXMLout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PINStatusInfoRequest( 
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *ReturnXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessAPDU( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrApduScript,
            /* [retval][out] */ BSTR *pbstrApduScript) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumerateCSPs( 
            /* [in] */ BSTR CSPType,
            /* [retval][out] */ BSTR *XMLReturn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CardInfoRequest( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportKey( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AcceptPKCS7Ex2( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ValidateCertificate( 
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnumerateCertificates( 
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateKeyFile( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLKeyFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeSOPIN( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLSOPINData,
            /* [retval][out] */ BSTR *bstrSOPINOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FinalIssuance( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Instantiate( 
            /* [in] */ BSTR InstanceXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostInitialisation( 
            /* [in] */ BSTR parametersXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteSoftwareToken( 
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveSoftwareToken( 
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSimulator( 
            /* [in] */ IUnknown *pSimulator) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportKeyEx( 
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [in] */ IUnknown *pAltDecryptProv,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangePINEx( 
            /* [in] */ const BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowMessage( 
            /* [in] */ BSTR MessageXML) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearMessage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndCardTransactions( 
            /* [in] */ BSTR bstrParameters) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISmartCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISmartCard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISmartCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISmartCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISmartCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISmartCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISmartCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISmartCard * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enumerate )( 
            ISmartCard * This,
            /* [retval][out] */ BSTR *bstrXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCardDetails )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Login )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPIN,
            /* [in] */ VARIANT_BOOL PINExpiry);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangePIN )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldPIN,
            /* [in] */ BSTR bstrNewPIN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Logout )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLoggedIn )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ VARIANT_BOOL *LoggedIn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialise )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrUnlockCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockCard )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode,
            /* [in] */ BSTR bstrNewPIN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataWrite )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [in] */ BSTR bstrData,
            /* [in] */ short Public);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataRead )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [retval][out] */ BSTR *bstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataDelete )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataRename )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldDataName,
            /* [in] */ BSTR bstrOldChunkName,
            /* [in] */ BSTR bstrNewDataName,
            /* [in] */ BSTR bstrNewChunkName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateRandomString )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ int nSize,
            /* [in] */ BSTR bstrSeed,
            /* [retval][out] */ BSTR *bstrRandomString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePKCS10 )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [retval][out] */ BSTR *bstrPKCS10);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7 )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNewEncryptKeyPair )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicEncryptKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNewSignKeyPair )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicSignKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateKeyPair )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveServerPublicEncryptKey )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicEncryptKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveServerPublicSignKey )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicSignKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SHA1 )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrDataIn,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitialiseEx )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ BSTR bstrExInitialisationData,
            /* [in] */ BSTR bstrExInitialisationData2,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrDeviceInitialisationData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetCard )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteCertificates )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeleteContainersXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePKCS10Ex )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrPKCS10);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialisation )( 
            ISmartCard * This,
            /* [in] */ BSTR InitXML,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockCardEx )( 
            ISmartCard * This,
            /* [in] */ BSTR UnlockXML,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7Ex )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUnlockChallenge )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockCard )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrXML,
            /* [retval][out] */ BSTR *bstrXMLout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PINStatusInfoRequest )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessAPDU )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrApduScript,
            /* [retval][out] */ BSTR *pbstrApduScript);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateCSPs )( 
            ISmartCard * This,
            /* [in] */ BSTR CSPType,
            /* [retval][out] */ BSTR *XMLReturn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CardInfoRequest )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ISmartCard * This,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportKey )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7Ex2 )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ValidateCertificate )( 
            ISmartCard * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateCertificates )( 
            ISmartCard * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateKeyFile )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLKeyFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeSOPIN )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLSOPINData,
            /* [retval][out] */ BSTR *bstrSOPINOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FinalIssuance )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Instantiate )( 
            ISmartCard * This,
            /* [in] */ BSTR InstanceXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PostInitialisation )( 
            ISmartCard * This,
            /* [in] */ BSTR parametersXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteSoftwareToken )( 
            ISmartCard * This,
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveSoftwareToken )( 
            ISmartCard * This,
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSimulator )( 
            ISmartCard * This,
            /* [in] */ IUnknown *pSimulator);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportKeyEx )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [in] */ IUnknown *pAltDecryptProv,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangePINEx )( 
            ISmartCard * This,
            /* [in] */ const BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowMessage )( 
            ISmartCard * This,
            /* [in] */ BSTR MessageXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearMessage )( 
            ISmartCard * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndCardTransactions )( 
            ISmartCard * This,
            /* [in] */ BSTR bstrParameters);
        
        END_INTERFACE
    } ISmartCardVtbl;

    interface ISmartCard
    {
        CONST_VTBL struct ISmartCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartCard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISmartCard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISmartCard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISmartCard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISmartCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISmartCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISmartCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISmartCard_Enumerate(This,bstrXML)	\
    ( (This)->lpVtbl -> Enumerate(This,bstrXML) ) 

#define ISmartCard_GetCardDetails(This,bstrSN,bstrXML)	\
    ( (This)->lpVtbl -> GetCardDetails(This,bstrSN,bstrXML) ) 

#define ISmartCard_Login(This,bstrSN,bstrPIN,PINExpiry)	\
    ( (This)->lpVtbl -> Login(This,bstrSN,bstrPIN,PINExpiry) ) 

#define ISmartCard_ChangePIN(This,bstrSN,bstrOldPIN,bstrNewPIN)	\
    ( (This)->lpVtbl -> ChangePIN(This,bstrSN,bstrOldPIN,bstrNewPIN) ) 

#define ISmartCard_Logout(This,bstrSN)	\
    ( (This)->lpVtbl -> Logout(This,bstrSN) ) 

#define ISmartCard_IsLoggedIn(This,bstrSN,LoggedIn)	\
    ( (This)->lpVtbl -> IsLoggedIn(This,bstrSN,LoggedIn) ) 

#define ISmartCard_Initialise(This,bstrSN,bstrNewPIN,PINExpiry,PINHistory,bstrUnlockCode)	\
    ( (This)->lpVtbl -> Initialise(This,bstrSN,bstrNewPIN,PINExpiry,PINHistory,bstrUnlockCode) ) 

#define ISmartCard_UnlockCard(This,bstrSN,bstrUnlockCode,bstrNewPIN)	\
    ( (This)->lpVtbl -> UnlockCard(This,bstrSN,bstrUnlockCode,bstrNewPIN) ) 

#define ISmartCard_DataWrite(This,bstrSN,bstrDataName,bstrChunkName,bstrData,Public)	\
    ( (This)->lpVtbl -> DataWrite(This,bstrSN,bstrDataName,bstrChunkName,bstrData,Public) ) 

#define ISmartCard_DataRead(This,bstrSN,bstrDataName,bstrChunkName,bstrData)	\
    ( (This)->lpVtbl -> DataRead(This,bstrSN,bstrDataName,bstrChunkName,bstrData) ) 

#define ISmartCard_DataDelete(This,bstrSN,bstrDataName,bstrChunkName)	\
    ( (This)->lpVtbl -> DataDelete(This,bstrSN,bstrDataName,bstrChunkName) ) 

#define ISmartCard_DataRename(This,bstrSN,bstrOldDataName,bstrOldChunkName,bstrNewDataName,bstrNewChunkName)	\
    ( (This)->lpVtbl -> DataRename(This,bstrSN,bstrOldDataName,bstrOldChunkName,bstrNewDataName,bstrNewChunkName) ) 

#define ISmartCard_GenerateRandomString(This,bstrSN,nSize,bstrSeed,bstrRandomString)	\
    ( (This)->lpVtbl -> GenerateRandomString(This,bstrSN,nSize,bstrSeed,bstrRandomString) ) 

#define ISmartCard_CreatePKCS10(This,bstrSN,bstrDNName,bstrUsage,bstrPKCS10)	\
    ( (This)->lpVtbl -> CreatePKCS10(This,bstrSN,bstrDNName,bstrUsage,bstrPKCS10) ) 

#define ISmartCard_AcceptPKCS7(This,bstrSN,bstrPKCS7)	\
    ( (This)->lpVtbl -> AcceptPKCS7(This,bstrSN,bstrPKCS7) ) 

#define ISmartCard_CreateNewEncryptKeyPair(This,bstrSN,keyLength,bstrPublicEncryptKey)	\
    ( (This)->lpVtbl -> CreateNewEncryptKeyPair(This,bstrSN,keyLength,bstrPublicEncryptKey) ) 

#define ISmartCard_CreateNewSignKeyPair(This,bstrSN,keyLength,bstrPublicSignKey)	\
    ( (This)->lpVtbl -> CreateNewSignKeyPair(This,bstrSN,keyLength,bstrPublicSignKey) ) 

#define ISmartCard_GenerateKeyPair(This,bstrSN,bstrKeyName,keyLength,bstrPublicKey)	\
    ( (This)->lpVtbl -> GenerateKeyPair(This,bstrSN,bstrKeyName,keyLength,bstrPublicKey) ) 

#define ISmartCard_SaveServerPublicEncryptKey(This,bstrSN,bstrServerPublicEncryptKey)	\
    ( (This)->lpVtbl -> SaveServerPublicEncryptKey(This,bstrSN,bstrServerPublicEncryptKey) ) 

#define ISmartCard_SaveServerPublicSignKey(This,bstrSN,bstrServerPublicSignKey)	\
    ( (This)->lpVtbl -> SaveServerPublicSignKey(This,bstrSN,bstrServerPublicSignKey) ) 

#define ISmartCard_SHA1(This,bstrDataIn,bstrDataOut)	\
    ( (This)->lpVtbl -> SHA1(This,bstrDataIn,bstrDataOut) ) 

#define ISmartCard_InitialiseEx(This,bstrSN,bstrNewPIN,bstrExInitialisationData,bstrExInitialisationData2,PINExpiry,PINHistory,bstrDeviceInitialisationData)	\
    ( (This)->lpVtbl -> InitialiseEx(This,bstrSN,bstrNewPIN,bstrExInitialisationData,bstrExInitialisationData2,PINExpiry,PINHistory,bstrDeviceInitialisationData) ) 

#define ISmartCard_ResetCard(This,bstrSN,bstrUnlockCode)	\
    ( (This)->lpVtbl -> ResetCard(This,bstrSN,bstrUnlockCode) ) 

#define ISmartCard_DeleteCertificates(This,bstrSN,bstrDeleteContainersXML)	\
    ( (This)->lpVtbl -> DeleteCertificates(This,bstrSN,bstrDeleteContainersXML) ) 

#define ISmartCard_CreatePKCS10Ex(This,bstrSN,bstrDNName,bstrUsage,vExtraXML,bstrPKCS10)	\
    ( (This)->lpVtbl -> CreatePKCS10Ex(This,bstrSN,bstrDNName,bstrUsage,vExtraXML,bstrPKCS10) ) 

#define ISmartCard_Initialisation(This,InitXML,ReturnXML)	\
    ( (This)->lpVtbl -> Initialisation(This,InitXML,ReturnXML) ) 

#define ISmartCard_UnlockCardEx(This,UnlockXML,ReturnXML)	\
    ( (This)->lpVtbl -> UnlockCardEx(This,UnlockXML,ReturnXML) ) 

#define ISmartCard_AcceptPKCS7Ex(This,bstrSN,bstrPKCS7,vExtraXML)	\
    ( (This)->lpVtbl -> AcceptPKCS7Ex(This,bstrSN,bstrPKCS7,vExtraXML) ) 

#define ISmartCard_GetUnlockChallenge(This,bstrXMLin,bstrXMLOut)	\
    ( (This)->lpVtbl -> GetUnlockChallenge(This,bstrXMLin,bstrXMLOut) ) 

#define ISmartCard_LockCard(This,bstrXML,bstrXMLout)	\
    ( (This)->lpVtbl -> LockCard(This,bstrXML,bstrXMLout) ) 

#define ISmartCard_PINStatusInfoRequest(This,bstrXMLin,ReturnXML)	\
    ( (This)->lpVtbl -> PINStatusInfoRequest(This,bstrXMLin,ReturnXML) ) 

#define ISmartCard_ProcessAPDU(This,bstrSN,bstrApduScript,pbstrApduScript)	\
    ( (This)->lpVtbl -> ProcessAPDU(This,bstrSN,bstrApduScript,pbstrApduScript) ) 

#define ISmartCard_EnumerateCSPs(This,CSPType,XMLReturn)	\
    ( (This)->lpVtbl -> EnumerateCSPs(This,CSPType,XMLReturn) ) 

#define ISmartCard_CardInfoRequest(This,bstrSN,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> CardInfoRequest(This,bstrSN,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard_GetVersion(This,xmlOut)	\
    ( (This)->lpVtbl -> GetVersion(This,xmlOut) ) 

#define ISmartCard_ImportKey(This,bstrSN,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> ImportKey(This,bstrSN,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard_AcceptPKCS7Ex2(This,bstrSN,bstrPKCS7,vExtraXML,bstrXMLOut)	\
    ( (This)->lpVtbl -> AcceptPKCS7Ex2(This,bstrSN,bstrPKCS7,vExtraXML,bstrXMLOut) ) 

#define ISmartCard_ValidateCertificate(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> ValidateCertificate(This,xmlIn,xmlOut) ) 

#define ISmartCard_EnumerateCertificates(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> EnumerateCertificates(This,xmlIn,xmlOut) ) 

#define ISmartCard_CreateKeyFile(This,bstrSN,bstrXMLKeyFile)	\
    ( (This)->lpVtbl -> CreateKeyFile(This,bstrSN,bstrXMLKeyFile) ) 

#define ISmartCard_ChangeSOPIN(This,bstrSN,bstrXMLSOPINData,bstrSOPINOut)	\
    ( (This)->lpVtbl -> ChangeSOPIN(This,bstrSN,bstrXMLSOPINData,bstrSOPINOut) ) 

#define ISmartCard_FinalIssuance(This,bstrSN,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> FinalIssuance(This,bstrSN,xmlIn,xmlOut) ) 

#define ISmartCard_Instantiate(This,InstanceXML)	\
    ( (This)->lpVtbl -> Instantiate(This,InstanceXML) ) 

#define ISmartCard_PostInitialisation(This,parametersXml)	\
    ( (This)->lpVtbl -> PostInitialisation(This,parametersXml) ) 

#define ISmartCard_WriteSoftwareToken(This,SerialNumber,SoftwareTokenXML)	\
    ( (This)->lpVtbl -> WriteSoftwareToken(This,SerialNumber,SoftwareTokenXML) ) 

#define ISmartCard_RemoveSoftwareToken(This,SerialNumber,SoftwareTokenXML)	\
    ( (This)->lpVtbl -> RemoveSoftwareToken(This,SerialNumber,SoftwareTokenXML) ) 

#define ISmartCard_SetSimulator(This,pSimulator)	\
    ( (This)->lpVtbl -> SetSimulator(This,pSimulator) ) 

#define ISmartCard_ImportKeyEx(This,bstrSN,bstrXMLIn,pAltDecryptProv,bstrXMLOut)	\
    ( (This)->lpVtbl -> ImportKeyEx(This,bstrSN,bstrXMLIn,pAltDecryptProv,bstrXMLOut) ) 

#define ISmartCard_ChangePINEx(This,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> ChangePINEx(This,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard_ShowMessage(This,MessageXML)	\
    ( (This)->lpVtbl -> ShowMessage(This,MessageXML) ) 

#define ISmartCard_ClearMessage(This)	\
    ( (This)->lpVtbl -> ClearMessage(This) ) 

#define ISmartCard_EndCardTransactions(This,bstrParameters)	\
    ( (This)->lpVtbl -> EndCardTransactions(This,bstrParameters) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISmartCard_INTERFACE_DEFINED__ */


#ifndef __ISmartCard2_INTERFACE_DEFINED__
#define __ISmartCard2_INTERFACE_DEFINED__

/* interface ISmartCard2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISmartCard2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1629370-8C57-47AE-B465-3C3E3E98DA6C")
    ISmartCard2 : public ISmartCard
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateClientUnlockKey( 
            /* [in] */ const BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteVSC( 
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrDeleteResponseXMLOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCryptoProvider( 
            /* [in] */ IUnknown *pUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCryptoProviderCapabilityLevel( 
            /* [retval][out] */ long *plCryptoProviderCapabilityLevel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISmartCard2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISmartCard2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISmartCard2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISmartCard2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISmartCard2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISmartCard2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISmartCard2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISmartCard2 * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Enumerate )( 
            ISmartCard2 * This,
            /* [retval][out] */ BSTR *bstrXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCardDetails )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ BSTR *bstrXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Login )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPIN,
            /* [in] */ VARIANT_BOOL PINExpiry);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangePIN )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldPIN,
            /* [in] */ BSTR bstrNewPIN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Logout )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLoggedIn )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [retval][out] */ VARIANT_BOOL *LoggedIn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialise )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrUnlockCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockCard )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode,
            /* [in] */ BSTR bstrNewPIN);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataWrite )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [in] */ BSTR bstrData,
            /* [in] */ short Public);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataRead )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName,
            /* [retval][out] */ BSTR *bstrData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataDelete )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDataName,
            /* [in] */ BSTR bstrChunkName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DataRename )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrOldDataName,
            /* [in] */ BSTR bstrOldChunkName,
            /* [in] */ BSTR bstrNewDataName,
            /* [in] */ BSTR bstrNewChunkName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateRandomString )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ int nSize,
            /* [in] */ BSTR bstrSeed,
            /* [retval][out] */ BSTR *bstrRandomString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePKCS10 )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [retval][out] */ BSTR *bstrPKCS10);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7 )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNewEncryptKeyPair )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicEncryptKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateNewSignKeyPair )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicSignKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateKeyPair )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrKeyName,
            /* [in] */ long keyLength,
            /* [retval][out] */ BSTR *bstrPublicKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveServerPublicEncryptKey )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicEncryptKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveServerPublicSignKey )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrServerPublicSignKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SHA1 )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrDataIn,
            /* [retval][out] */ BSTR *bstrDataOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitialiseEx )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrNewPIN,
            /* [in] */ BSTR bstrExInitialisationData,
            /* [in] */ BSTR bstrExInitialisationData2,
            /* [in] */ long PINExpiry,
            /* [in] */ long PINHistory,
            /* [retval][out] */ BSTR *bstrDeviceInitialisationData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetCard )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrUnlockCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteCertificates )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDeleteContainersXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePKCS10Ex )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrDNName,
            /* [in] */ BSTR bstrUsage,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrPKCS10);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialisation )( 
            ISmartCard2 * This,
            /* [in] */ BSTR InitXML,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockCardEx )( 
            ISmartCard2 * This,
            /* [in] */ BSTR UnlockXML,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7Ex )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUnlockChallenge )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockCard )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrXML,
            /* [retval][out] */ BSTR *bstrXMLout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PINStatusInfoRequest )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrXMLin,
            /* [retval][out] */ BSTR *ReturnXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessAPDU )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrApduScript,
            /* [retval][out] */ BSTR *pbstrApduScript);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateCSPs )( 
            ISmartCard2 * This,
            /* [in] */ BSTR CSPType,
            /* [retval][out] */ BSTR *XMLReturn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CardInfoRequest )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ISmartCard2 * This,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportKey )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptPKCS7Ex2 )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrPKCS7,
            /* [optional][in] */ VARIANT vExtraXML,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ValidateCertificate )( 
            ISmartCard2 * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnumerateCertificates )( 
            ISmartCard2 * This,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateKeyFile )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLKeyFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeSOPIN )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLSOPINData,
            /* [retval][out] */ BSTR *bstrSOPINOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FinalIssuance )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Instantiate )( 
            ISmartCard2 * This,
            /* [in] */ BSTR InstanceXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PostInitialisation )( 
            ISmartCard2 * This,
            /* [in] */ BSTR parametersXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteSoftwareToken )( 
            ISmartCard2 * This,
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveSoftwareToken )( 
            ISmartCard2 * This,
            /* [in] */ BSTR SerialNumber,
            /* [in] */ BSTR SoftwareTokenXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSimulator )( 
            ISmartCard2 * This,
            /* [in] */ IUnknown *pSimulator);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportKeyEx )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrSN,
            /* [in] */ BSTR bstrXMLIn,
            /* [in] */ IUnknown *pAltDecryptProv,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangePINEx )( 
            ISmartCard2 * This,
            /* [in] */ const BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowMessage )( 
            ISmartCard2 * This,
            /* [in] */ BSTR MessageXML);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearMessage )( 
            ISmartCard2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndCardTransactions )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrParameters);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateClientUnlockKey )( 
            ISmartCard2 * This,
            /* [in] */ const BSTR xmlIn,
            /* [retval][out] */ BSTR *xmlOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteVSC )( 
            ISmartCard2 * This,
            /* [in] */ BSTR bstrXMLIn,
            /* [retval][out] */ BSTR *bstrDeleteResponseXMLOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCryptoProvider )( 
            ISmartCard2 * This,
            /* [in] */ IUnknown *pUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCryptoProviderCapabilityLevel )( 
            ISmartCard2 * This,
            /* [retval][out] */ long *plCryptoProviderCapabilityLevel);
        
        END_INTERFACE
    } ISmartCard2Vtbl;

    interface ISmartCard2
    {
        CONST_VTBL struct ISmartCard2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartCard2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISmartCard2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISmartCard2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISmartCard2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISmartCard2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISmartCard2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISmartCard2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISmartCard2_Enumerate(This,bstrXML)	\
    ( (This)->lpVtbl -> Enumerate(This,bstrXML) ) 

#define ISmartCard2_GetCardDetails(This,bstrSN,bstrXML)	\
    ( (This)->lpVtbl -> GetCardDetails(This,bstrSN,bstrXML) ) 

#define ISmartCard2_Login(This,bstrSN,bstrPIN,PINExpiry)	\
    ( (This)->lpVtbl -> Login(This,bstrSN,bstrPIN,PINExpiry) ) 

#define ISmartCard2_ChangePIN(This,bstrSN,bstrOldPIN,bstrNewPIN)	\
    ( (This)->lpVtbl -> ChangePIN(This,bstrSN,bstrOldPIN,bstrNewPIN) ) 

#define ISmartCard2_Logout(This,bstrSN)	\
    ( (This)->lpVtbl -> Logout(This,bstrSN) ) 

#define ISmartCard2_IsLoggedIn(This,bstrSN,LoggedIn)	\
    ( (This)->lpVtbl -> IsLoggedIn(This,bstrSN,LoggedIn) ) 

#define ISmartCard2_Initialise(This,bstrSN,bstrNewPIN,PINExpiry,PINHistory,bstrUnlockCode)	\
    ( (This)->lpVtbl -> Initialise(This,bstrSN,bstrNewPIN,PINExpiry,PINHistory,bstrUnlockCode) ) 

#define ISmartCard2_UnlockCard(This,bstrSN,bstrUnlockCode,bstrNewPIN)	\
    ( (This)->lpVtbl -> UnlockCard(This,bstrSN,bstrUnlockCode,bstrNewPIN) ) 

#define ISmartCard2_DataWrite(This,bstrSN,bstrDataName,bstrChunkName,bstrData,Public)	\
    ( (This)->lpVtbl -> DataWrite(This,bstrSN,bstrDataName,bstrChunkName,bstrData,Public) ) 

#define ISmartCard2_DataRead(This,bstrSN,bstrDataName,bstrChunkName,bstrData)	\
    ( (This)->lpVtbl -> DataRead(This,bstrSN,bstrDataName,bstrChunkName,bstrData) ) 

#define ISmartCard2_DataDelete(This,bstrSN,bstrDataName,bstrChunkName)	\
    ( (This)->lpVtbl -> DataDelete(This,bstrSN,bstrDataName,bstrChunkName) ) 

#define ISmartCard2_DataRename(This,bstrSN,bstrOldDataName,bstrOldChunkName,bstrNewDataName,bstrNewChunkName)	\
    ( (This)->lpVtbl -> DataRename(This,bstrSN,bstrOldDataName,bstrOldChunkName,bstrNewDataName,bstrNewChunkName) ) 

#define ISmartCard2_GenerateRandomString(This,bstrSN,nSize,bstrSeed,bstrRandomString)	\
    ( (This)->lpVtbl -> GenerateRandomString(This,bstrSN,nSize,bstrSeed,bstrRandomString) ) 

#define ISmartCard2_CreatePKCS10(This,bstrSN,bstrDNName,bstrUsage,bstrPKCS10)	\
    ( (This)->lpVtbl -> CreatePKCS10(This,bstrSN,bstrDNName,bstrUsage,bstrPKCS10) ) 

#define ISmartCard2_AcceptPKCS7(This,bstrSN,bstrPKCS7)	\
    ( (This)->lpVtbl -> AcceptPKCS7(This,bstrSN,bstrPKCS7) ) 

#define ISmartCard2_CreateNewEncryptKeyPair(This,bstrSN,keyLength,bstrPublicEncryptKey)	\
    ( (This)->lpVtbl -> CreateNewEncryptKeyPair(This,bstrSN,keyLength,bstrPublicEncryptKey) ) 

#define ISmartCard2_CreateNewSignKeyPair(This,bstrSN,keyLength,bstrPublicSignKey)	\
    ( (This)->lpVtbl -> CreateNewSignKeyPair(This,bstrSN,keyLength,bstrPublicSignKey) ) 

#define ISmartCard2_GenerateKeyPair(This,bstrSN,bstrKeyName,keyLength,bstrPublicKey)	\
    ( (This)->lpVtbl -> GenerateKeyPair(This,bstrSN,bstrKeyName,keyLength,bstrPublicKey) ) 

#define ISmartCard2_SaveServerPublicEncryptKey(This,bstrSN,bstrServerPublicEncryptKey)	\
    ( (This)->lpVtbl -> SaveServerPublicEncryptKey(This,bstrSN,bstrServerPublicEncryptKey) ) 

#define ISmartCard2_SaveServerPublicSignKey(This,bstrSN,bstrServerPublicSignKey)	\
    ( (This)->lpVtbl -> SaveServerPublicSignKey(This,bstrSN,bstrServerPublicSignKey) ) 

#define ISmartCard2_SHA1(This,bstrDataIn,bstrDataOut)	\
    ( (This)->lpVtbl -> SHA1(This,bstrDataIn,bstrDataOut) ) 

#define ISmartCard2_InitialiseEx(This,bstrSN,bstrNewPIN,bstrExInitialisationData,bstrExInitialisationData2,PINExpiry,PINHistory,bstrDeviceInitialisationData)	\
    ( (This)->lpVtbl -> InitialiseEx(This,bstrSN,bstrNewPIN,bstrExInitialisationData,bstrExInitialisationData2,PINExpiry,PINHistory,bstrDeviceInitialisationData) ) 

#define ISmartCard2_ResetCard(This,bstrSN,bstrUnlockCode)	\
    ( (This)->lpVtbl -> ResetCard(This,bstrSN,bstrUnlockCode) ) 

#define ISmartCard2_DeleteCertificates(This,bstrSN,bstrDeleteContainersXML)	\
    ( (This)->lpVtbl -> DeleteCertificates(This,bstrSN,bstrDeleteContainersXML) ) 

#define ISmartCard2_CreatePKCS10Ex(This,bstrSN,bstrDNName,bstrUsage,vExtraXML,bstrPKCS10)	\
    ( (This)->lpVtbl -> CreatePKCS10Ex(This,bstrSN,bstrDNName,bstrUsage,vExtraXML,bstrPKCS10) ) 

#define ISmartCard2_Initialisation(This,InitXML,ReturnXML)	\
    ( (This)->lpVtbl -> Initialisation(This,InitXML,ReturnXML) ) 

#define ISmartCard2_UnlockCardEx(This,UnlockXML,ReturnXML)	\
    ( (This)->lpVtbl -> UnlockCardEx(This,UnlockXML,ReturnXML) ) 

#define ISmartCard2_AcceptPKCS7Ex(This,bstrSN,bstrPKCS7,vExtraXML)	\
    ( (This)->lpVtbl -> AcceptPKCS7Ex(This,bstrSN,bstrPKCS7,vExtraXML) ) 

#define ISmartCard2_GetUnlockChallenge(This,bstrXMLin,bstrXMLOut)	\
    ( (This)->lpVtbl -> GetUnlockChallenge(This,bstrXMLin,bstrXMLOut) ) 

#define ISmartCard2_LockCard(This,bstrXML,bstrXMLout)	\
    ( (This)->lpVtbl -> LockCard(This,bstrXML,bstrXMLout) ) 

#define ISmartCard2_PINStatusInfoRequest(This,bstrXMLin,ReturnXML)	\
    ( (This)->lpVtbl -> PINStatusInfoRequest(This,bstrXMLin,ReturnXML) ) 

#define ISmartCard2_ProcessAPDU(This,bstrSN,bstrApduScript,pbstrApduScript)	\
    ( (This)->lpVtbl -> ProcessAPDU(This,bstrSN,bstrApduScript,pbstrApduScript) ) 

#define ISmartCard2_EnumerateCSPs(This,CSPType,XMLReturn)	\
    ( (This)->lpVtbl -> EnumerateCSPs(This,CSPType,XMLReturn) ) 

#define ISmartCard2_CardInfoRequest(This,bstrSN,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> CardInfoRequest(This,bstrSN,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard2_GetVersion(This,xmlOut)	\
    ( (This)->lpVtbl -> GetVersion(This,xmlOut) ) 

#define ISmartCard2_ImportKey(This,bstrSN,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> ImportKey(This,bstrSN,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard2_AcceptPKCS7Ex2(This,bstrSN,bstrPKCS7,vExtraXML,bstrXMLOut)	\
    ( (This)->lpVtbl -> AcceptPKCS7Ex2(This,bstrSN,bstrPKCS7,vExtraXML,bstrXMLOut) ) 

#define ISmartCard2_ValidateCertificate(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> ValidateCertificate(This,xmlIn,xmlOut) ) 

#define ISmartCard2_EnumerateCertificates(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> EnumerateCertificates(This,xmlIn,xmlOut) ) 

#define ISmartCard2_CreateKeyFile(This,bstrSN,bstrXMLKeyFile)	\
    ( (This)->lpVtbl -> CreateKeyFile(This,bstrSN,bstrXMLKeyFile) ) 

#define ISmartCard2_ChangeSOPIN(This,bstrSN,bstrXMLSOPINData,bstrSOPINOut)	\
    ( (This)->lpVtbl -> ChangeSOPIN(This,bstrSN,bstrXMLSOPINData,bstrSOPINOut) ) 

#define ISmartCard2_FinalIssuance(This,bstrSN,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> FinalIssuance(This,bstrSN,xmlIn,xmlOut) ) 

#define ISmartCard2_Instantiate(This,InstanceXML)	\
    ( (This)->lpVtbl -> Instantiate(This,InstanceXML) ) 

#define ISmartCard2_PostInitialisation(This,parametersXml)	\
    ( (This)->lpVtbl -> PostInitialisation(This,parametersXml) ) 

#define ISmartCard2_WriteSoftwareToken(This,SerialNumber,SoftwareTokenXML)	\
    ( (This)->lpVtbl -> WriteSoftwareToken(This,SerialNumber,SoftwareTokenXML) ) 

#define ISmartCard2_RemoveSoftwareToken(This,SerialNumber,SoftwareTokenXML)	\
    ( (This)->lpVtbl -> RemoveSoftwareToken(This,SerialNumber,SoftwareTokenXML) ) 

#define ISmartCard2_SetSimulator(This,pSimulator)	\
    ( (This)->lpVtbl -> SetSimulator(This,pSimulator) ) 

#define ISmartCard2_ImportKeyEx(This,bstrSN,bstrXMLIn,pAltDecryptProv,bstrXMLOut)	\
    ( (This)->lpVtbl -> ImportKeyEx(This,bstrSN,bstrXMLIn,pAltDecryptProv,bstrXMLOut) ) 

#define ISmartCard2_ChangePINEx(This,bstrXMLIn,bstrXMLOut)	\
    ( (This)->lpVtbl -> ChangePINEx(This,bstrXMLIn,bstrXMLOut) ) 

#define ISmartCard2_ShowMessage(This,MessageXML)	\
    ( (This)->lpVtbl -> ShowMessage(This,MessageXML) ) 

#define ISmartCard2_ClearMessage(This)	\
    ( (This)->lpVtbl -> ClearMessage(This) ) 

#define ISmartCard2_EndCardTransactions(This,bstrParameters)	\
    ( (This)->lpVtbl -> EndCardTransactions(This,bstrParameters) ) 


#define ISmartCard2_UpdateClientUnlockKey(This,xmlIn,xmlOut)	\
    ( (This)->lpVtbl -> UpdateClientUnlockKey(This,xmlIn,xmlOut) ) 

#define ISmartCard2_DeleteVSC(This,bstrXMLIn,bstrDeleteResponseXMLOut)	\
    ( (This)->lpVtbl -> DeleteVSC(This,bstrXMLIn,bstrDeleteResponseXMLOut) ) 

#define ISmartCard2_SetCryptoProvider(This,pUnk)	\
    ( (This)->lpVtbl -> SetCryptoProvider(This,pUnk) ) 

#define ISmartCard2_GetCryptoProviderCapabilityLevel(This,plCryptoProviderCapabilityLevel)	\
    ( (This)->lpVtbl -> GetCryptoProviderCapabilityLevel(This,plCryptoProviderCapabilityLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISmartCard2_INTERFACE_DEFINED__ */



#ifndef __EDEFICESMARTCARDLib_LIBRARY_DEFINED__
#define __EDEFICESMARTCARDLib_LIBRARY_DEFINED__

/* library EDEFICESMARTCARDLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_EDEFICESMARTCARDLib;

EXTERN_C const CLSID CLSID_SmartCard;

#ifdef __cplusplus

class DECLSPEC_UUID("D8842B37-7EBB-466B-A56F-D99536739155")
SmartCard;
#endif

EXTERN_C const CLSID CLSID_Win32APDUCard;

#ifdef __cplusplus

class DECLSPEC_UUID("FE3BBDCD-D5CD-4b80-A180-952FA5D7D9FE")
Win32APDUCard;
#endif

EXTERN_C const CLSID CLSID_DK_APDUCard;

#ifdef __cplusplus

class DECLSPEC_UUID("E4A32E9A-DDA7-434c-AF2A-B2E5A9901E18")
DK_APDUCard;
#endif

EXTERN_C const CLSID CLSID_PivApduCard;

#ifdef __cplusplus

class DECLSPEC_UUID("D0D112E3-8709-4BFF-9F7F-CA5A496C92ED")
PivApduCard;
#endif
#endif /* __EDEFICESMARTCARDLib_LIBRARY_DEFINED__ */

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


