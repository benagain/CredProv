// This tell CATCH to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_RUNNER

#if (_MSC_VER >= 1600)
	#define CATCH_CONFIG_CPP11_NULLPTR
#endif

#pragma warning( push )
#pragma warning( disable: 4244 4702 28251 )
#include "catch.hpp"
#pragma warning( pop )

// create an instance of this at the start of main()
class AutoCom
{
public:
#ifdef WIN32
#pragma warning(suppress: 6031)
	AutoCom() { CoInitialize(NULL); }
	AutoCom(_In_ DWORD dwCoInit) { CoInitializeEx(NULL, dwCoInit); }
	~AutoCom() { CoUninitialize(); }
#endif
};
