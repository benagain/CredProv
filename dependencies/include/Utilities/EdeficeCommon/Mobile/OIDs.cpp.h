#if defined(ANDROID)
#include "jni/JNIResource.h"
#endif

namespace ASN1
{
#if defined(ANDROID)
namespace OIDListData		/// Placeholder for OIDList data
{
	bool LoadAndroidResCSV(void)
	{
		std::wstring oidData = JniResource::LoadAndroidResFile(OIDfilename);
		std::wistringstream buf(oidData);

		wchar_t l[1000];
		while (!buf.eof()) {
			buf.getline(l, 1000);
			ProcessLine(l);
		}

		return true;
	}
} // namespace OIDListData
#endif

// Load the OID data
void OIDList::Load(void)
{
	using namespace OIDListData;

	if (!OIDLoaded)
	{
#if defined(ANDROID)
		OIDValid = LoadAndroidResCSV();
#else
		OIDValid = LoadFileCSV();
#endif

		OIDLoaded = true;
	}
}

}// namespace ASN1
