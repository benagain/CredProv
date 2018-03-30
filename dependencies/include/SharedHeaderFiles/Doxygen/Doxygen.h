#if defined(DOXYGEN)
#define _WIN32
#define __cplusplus
#define _MANAGED
#define NULL 0
#define WINAPI
#define STDAPI
#define BOOL bool
#define _MSC_VER 1500
#define _MSC_FULL_VER 13010000
#define ATL_NO_VTABLE
#define CONST_VTBL const
#define EXTERN_C
#define __declspec(a)
#define DECLSPEC_UUID(a)
#define interface class
#define MIDL_INTERFACE(x) struct
#define STDMETHODCALLTYPE
#define STDMETHODIMP HRESULT
#define STDMETHOD(method) virtual HRESULT method
#define STDMETHOD_(type,method) virtual type method
#define DECLARE_INTERFACE(name) class name
#define PURE = 0
#define THIS_
#define THIS
#define DECLARE_HANDLE(name) typedef HANDLE name
#define DECLARE_REGISTRY_RESOURCEID(a)
#define DECLARE_PROTECT_FINAL_CONSTRUCT()
#define DECLARE_AGGREGATABLE(a)
#define DECLARE_MESSAGE_MAP()
#define BEGIN_MESSAGE_MAP(a,b)
#define END_MESSAGE_MAP()
#define BEGIN_COM_MAP(a)
#define END_COM_MAP()
#define COM_INTERFACE_ENTRY(a)
#define BEGIN_PROP_MAP(a)
#define END_PROP_MAP()
#define PROP_DATA_ENTRY(a,b,c)
#define BEGIN_MSG_MAP(a)
#define END_MSG_MAP()
#define CHAIN_MSG_MAP(a)
#define DEFAULT_REFLECTION_HANDLER()
#define BEGIN_OBJECT_MAP(a)
#define END_OBJECT_MAP()
#define OBJECT_ENTRY(a,b)
#define BEGIN_CONNECTION_POINT_MAP(a)
#define END_CONNECTION_POINT_MAP()
#define DECLARE_VIEW_STATUS(a)
#define DECLARE_OLEMISC_STATUS(a)
#define BEGIN_DISPATCH_MAP(a,b)
#define END_DISPATCH_MAP()
#define INTERFACE_PART(a,b,c)
#define DISP_FUNCTION(a,b,c,d,e)
#define BEGIN_INTERFACE_MAP(a,b)
#define END_INTERFACE_MAP()
#define DECLARE_DYNAMIC(a)
#define IMPLEMENT_DYNAMIC(a,b)
#define DECLARE_DYNCREATE(a)
#define IMPLEMENT_DYNCREATE(a,b)
#define IMPLEMENT_OLECREATE2(class,name,id1,id2,id3,id4,id5,id6,id7,id8,id9,id10,id11)
#define IMPLEMENT_SERIAL(a,b,c)
#define IMPLEMENT_REGISTER(a,b,c,d,e)
#define DECLARE_OLECREATE(a)
#define ON_EN_CHANGE(a,b)
#define ON_COMMAND(a,b)
#define TRY try CATCH_ALL(e)=catch(...)
#define END_CATCH_ALL
#define THROW_LAST() throw
#define RUNTIME_CLASS(class) class
#define MAKEINTRESOURCE(nId) nId
#define ASSERT(x) assert(x)
#define ASSERT_VALID(x) assert(x)
#define TRACE0(x) printf(x)
#define OS_ERR(A,B)={ #A, B }
#endif