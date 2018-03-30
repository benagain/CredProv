#pragma once

#include "CertHandle.h"
#include "Utilities\EdeficeCommon\TimeCommon.h"
#include "Utilities\EdeficeCommon\VectorOfByte.h"
#include <list>

namespace CertStore
{

//------------------------------------------------------------------------------------------------------------------
// Stores

/// Physical store data
class Phy
{
public:
	std::wstring	store;				///< system store it belongs to
	std::wstring	name;				///< physical store name
	std::string		provider;			///< store provider
	DWORD			dwFlags;			///< flags
};
typedef std::list<Phy> PhyList;

/// System store data
class Sys
{
public:
	std::wstring	store;				///< store name
	DWORD			dwFlags;			///< flags
	PhyList			physical;			///< list of associated physical stores
};
typedef std::list<Sys> SysList;

/// Store location data
class Loc
{
public:
	std::wstring	location;			///< location name
	DWORD			dwFlags;			///< flags
	SysList			sys;				///< list of associated system stores
};
typedef std::list<Loc> LocList;

/// Store list management
class StoreList
{
public:
	const LocList& EnumStoreLocation(void);
	const Loc* locate(_In_ const std::wstring& location) const;
	const Sys* locate(_In_ const std::wstring& location, _In_ const std::wstring& store) const;
	const Phy* locate(_In_ const std::wstring& location, _In_ const std::wstring& store, _In_ const std::wstring& phys) const;

private:
	LocList			m_store;			///< list of store locations
};

//------------------------------------------------------------------------------------------------------------------
// Store contents

/// Basic certificate data
class CertData
{
public:
	CertData();
	explicit CertData(_In_ const CertData& rhs);
	~CertData();

	void Load(_In_ PCCERT_CONTEXT certContext, _In_ int pos = -1);
	void clear(void);
	bool Delete(void);

	int				pos;					///< store item number
	std::wstring	subject;				///< certificate subject
	std::wstring	issuer;					///< certificate issuer
	myid::Time		notBefore;				///< when certificate expires
	myid::Time		notAfter;				///< when certificate expires
	VectorOfByte	sn;						///< certificate serial number
	VectorOfByte	data;					///< certificate ASN1 data
	CertContext		certContext;			///< context
	std::wstring	providerName;			///< where the private key is stored, blank for none
	DWORD			providerType;			///< CSP provider type, 0 for CNG
	std::wstring	containerName;			///< where the private key is stored, blank for none
	DWORD			keySpec;				///< legacy key spec (AT_KEYEXCHANGE or AT_SIGNATURE)
	DWORD			flags;					///< open key flags

};
typedef std::list<CertData> CertDataList;

/// Basic CRL data
class CrlData
{
public:
	/// One revoked certificate
	class CrlItem
	{
	public:
		VectorOfByte	sn;					///< certificate serial number
		myid::Time		revocationDate;		///< date of revocation
	};
	typedef std::list<CrlItem> CrlItemList;

	CrlData();
	explicit CrlData(_In_ const CrlData& rhs);
	~CrlData();

	void Load(_In_ PCCRL_CONTEXT crlContext, _In_ int pos = -1);
	void clear(void);

	int				pos;					///< store item number
	std::wstring	issuer;					///< CRL issuer
	myid::Time		thisUpdate;				///< when issued
	myid::Time		nextUpdate;				///< next update time
	CrlItemList		listCrl;				///< list of CRL items
	VectorOfByte	data;					///< CRL ASN1 data
	CrlContext		crlContext;				///< context
};
typedef std::list<CrlData> CrlDataList;

/// Basic CTL data
class CtlData
{
public:
	CtlData();
	explicit CtlData(_In_ const CtlData& rhs);
	~CtlData();

	void Load(_In_ PCCTL_CONTEXT ctlContext, _In_ int pos = -1);
	void clear(void);

	int				pos;					///< store item number
	myid::Time		thisUpdate;				///< when issued
	myid::Time		nextUpdate;				///< next update time
	VectorOfByte	data;					///< CTL ASN1 data
	CtlContext		ctlContext;				///< context
};
typedef std::list<CtlData> CtlDataList;

/// Certificate store data
class StoreData
{
public:
	StoreData();
	~StoreData();

	bool Open(_In_z_ LPCSTR lpszStoreProvider, _In_ DWORD dwFlags, _In_ const std::wstring& store);
	bool Open(_In_ const StoreHandle& store);
	bool Enumerate(void);
	void Close();
	void Select(_In_ int pos);

	StoreHandle		hStore;					///< certificate store
	CertDataList	certData;				///< certificates
	CrlDataList		crlData;				///< CRLs
	CtlDataList		ctlData;				///< CTLs

	const CertData*	cert;					///< selected item
	const CrlData*	crl;					///< selected item
	const CtlData*	ctl;					///< selected item
};

} // namespace CertStore
