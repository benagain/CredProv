#pragma once

#include ".\abstractkey.h"
#include ".\P11LoaderBase.h"
#include ".\SoftwareKeyFactory.h"

namespace AbstractKeys
{

/** Encapsulate a Pkcs11 session, implementing an AbstractKeyFactory
expected to be used in conjunction with a (global) P11LoaderBase object.
i.e. 
CP11LoaderBase p11Driver("pkcs11.dll"); //declared globally
P11SessionKeyFactory p11Session(p11Driver);
p11Session.SetSlot(strHSMSerialNumber);
p11Session.Login(L"1254");
// now use p11Session as KeyFactory to create
*/
class P11SessionKeyFactory : public AbstractKeyFactory
{
public:
	P11SessionKeyFactory(CP11LoaderBase &loader);
	virtual ~P11SessionKeyFactory(void);

	static P11SessionKeyFactory *GetP11Session(AbstractKeyFactory *pFactory);

	// slot selection functions
	void SetSlot(const std::string &strSerialNumber = "");
	void SetSlot(const CK_ULONG slot);
	CK_ULONG GetSlot();

	// access to P11 driver
	const CK_FUNCTION_LIST_PTR operator -> () const;
	const CK_FUNCTION_LIST_PTR Driver() const;

	// session management functions
	virtual void OpenSession();
	virtual void CloseSession();
	virtual void PutSession(const CK_SESSION_HANDLE hSession);
	CK_SESSION_HANDLE GetSession() const;
	void SetSupportForImportParityCorrection(const bool bImportParityCorrectionSupported);

	virtual void Login(const std::string &strPIN);

	virtual CK_BBOOL CKA_Private(KeyParametersPtr pKey) const;

	// KeyFactory
	virtual AbstractKeyPtr Create(const KeyFamily &family);

	SoftwareKeyFactory &GetSoftwareFactory() {return m_softFactory;}	

	virtual bool AreExportableKeysAvailable() { return true; };

protected:
	CK_SESSION_HANDLE m_hSession;
	CP11LoaderBase &m_p11Loader;
	bool m_bImportParityCorrectionSupported;

	//slot selection parameters
	CK_ULONG m_slotID;
	std::string m_strSlotSerialNumber;

	SoftwareKeyFactory m_softFactory;
};



}
