// dllmain.h : Declaration of module class.

class CMyidCredentialProviderModule : public ATL::CAtlDllModuleT< CMyidCredentialProviderModule >
{
public :
	DECLARE_LIBID(LIBID_MyidCredentialProviderLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYIDCREDENTIALPROVIDER, "{04c4bc80-2d31-4619-9a6d-6cd608a61258}")
};

extern class CMyidCredentialProviderModule _AtlModule;
