#define MAKE_STRING(x) # x

#if defined(TLB_NAME)
	#if defined(TLB_LOCAL)
		#define TLB_LOCATION(ver, name) MAKE_STRING( ver ## / ## name ## .tlb )
		#define TLBNAME TLB_LOCATION( VSVER, TLB_NAME )
	#else
		#define TLB_LOCATION(base, ver, name) MAKE_STRING( base ## /Interfaces/ ## name ## / ## ver ## / ## name ## .tlb )
		#define TLBNAME TLB_LOCATION( LOCAL_BASE, VSVER, TLB_NAME )
	#endif
	#define TLB_PATH TLBNAME

	#if !defined(DLL_NAME) && !defined(EXE_NAME)
		#define DLL_NAME TLB_NAME
	#endif
#endif

#if defined(EXE_NAME)
	#define ORIGINALFILENAME_STRINGX(name) MAKE_STRING( name ## .exe )
	#define ORIGINALFILENAME_STRING ORIGINALFILENAME_STRINGX( EXE_NAME )
	#define MODULE_NAME EXE_NAME
#elif defined(DLL_NAME)
	#define ORIGINALFILENAME_STRINGX(name) MAKE_STRING( name ## .dll )
	#define ORIGINALFILENAME_STRING ORIGINALFILENAME_STRINGX( DLL_NAME )
	#define MODULE_NAME DLL_NAME
#else
	#define ORIGINALFILENAME_STRING ""
#endif

#if !defined(FILEDESCRIPTION_STRING)
	#define FILEDESCRIPTION_STRINGX( name ) MAKE_STRING( name ) " Module"
	#define FILEDESCRIPTION_STRING FILEDESCRIPTION_STRINGX(MODULE_NAME)
#endif

#if !defined(INTERNALNAME_STRING)
	#define INTERNALNAME_STRINGX(name) MAKE_STRING(name)
	#define INTERNALNAME_STRING INTERNALNAME_STRINGX(MODULE_NAME)
#endif

#if !defined(PRODUCTNAME_STRING)
	#if !defined(PRODUCT_NAME)
		#define PRODUCTNAME_STRINGX( name ) MAKE_STRING( name ) " Module"
	#else
		#define PRODUCTNAME_STRINGX( name ) MAKE_STRING( name ) " - " PRODUCT_NAME " Module"
	#endif
	#define PRODUCTNAME_STRING PRODUCTNAME_STRINGX(MODULE_NAME)
#endif
