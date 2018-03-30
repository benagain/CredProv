// P11Loader.h: interface for the CP11Loader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P11LOADER_H__193EB088_A83C_42D3_B6EA_AA511BEA6E08__INCLUDED_)
#define AFX_P11LOADER_H__193EB088_A83C_42D3_B6EA_AA511BEA6E08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

#include ".\P11Key.h" // pulls in Pkcs11 headers


/** wrap a P11 DLL to dynamically load and initialise
note that we always want to dynamically load our p11 drivers, so if the DLL is 
not present when we decide to regsvr32, we can still register successfully 
Base class to be overriden as required by individual projects*/
class CP11LoaderBase
{
public:
	CP11LoaderBase(const char *pszP11DLLName);
	virtual ~CP11LoaderBase();

	/*!
	* Get the function pointer list from the HSM P11 driver
	*
	* \pre
	*   Load() has been called successfully
	*
	* \warning
	*   It is the responsibility of the caller to ensure that Unload() is not called between getting
	*   the function pointer list and the point at which it is used.
	*/
	const CK_FUNCTION_LIST_PTR Get() const;

	/*!
	* Access the function pointer list from the HSM P11 driver
	*
	* \pre
	*   Load() has been called successfully
	*
	* \warning
	*   It is the responsibility of the caller to ensure that Unload() is not called between getting
	*   the function pointer list and the point at which it is used.
	*/
	const CK_FUNCTION_LIST_PTR operator -> () const;

	virtual void Load();
	void Unload();

	/*!
	* Resets the P11 driver by calling C_Finalize followed by C_Initialize
	*/
	void Reset();

	/*!
	* Close all sessions associated with a specified slot ID
	*/
	void CloseAllSessions(int slotId);

	virtual CK_ULONG GetSlotFromSN(const std::string &strSerialNumber);
	std::string GetString(const CK_CHAR *pszText, int nSize) const;

	virtual std::wstring EnumerateSlots();

private:
	void Initialize();
	void Finalize();

	/*! \name Callback methods for P11 driver to use */
	/*! @{ */
	static CK_RV P11CreateMutex(CK_VOID_PTR_PTR ppMutex);
	static CK_RV P11DestroyMutex(CK_VOID_PTR pMutex);
	static CK_RV P11LockMutex(CK_VOID_PTR pMutex);
	static CK_RV P11UnlockMutex(CK_VOID_PTR pMutex);
	/*! @} */

protected:
	std::string m_strP11DriverDLLName;
	volatile bool m_bLoaded;
	HMODULE m_hModule;
	CK_FUNCTION_LIST_PTR m_pDllFunctions;

	ATL::CComAutoCriticalSection m_criticalSection;
};

#endif // !defined(AFX_P11LOADER_H__193EB088_A83C_42D3_B6EA_AA511BEA6E08__INCLUDED_)
