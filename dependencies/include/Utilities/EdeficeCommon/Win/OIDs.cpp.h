#include "../OID.h"

namespace ASN1
{

namespace OIDListData					/// Placeholder for OIDList data
{
bool LoadResCSV(void);

bool LoadResCSV(void)
{
	bool valid = false;

	// do resource load
	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_OID), RT_RCDATA);
	if (hRes)
	{
		HGLOBAL hGlob = LoadResource(NULL, hRes);
		if (hGlob)
		{
			LPVOID pRes = LockResource(hGlob);
			if (pRes)
			{
				const char* x = (const char*)pRes;
				DWORD size = SizeofResource(NULL, hRes);
				std::string str(x, size);

				std::istringstream buf(str);
				char l[1000];
				while (!buf.eof())
				{
					buf.getline(l, 1000);
					ProcessLine(myid::ToWstr(l));
				}

				valid = true;
			}
		}
	}

	return valid;
}

} // namespace OIDListData

// Load the OID data
void OIDList::Load(void)
{
	using namespace OIDListData;

	if (!OIDLoaded)
	{
		OIDValid = LoadResCSV();
		OIDValid |= LoadFileCSV();

		OIDLoaded = true;
	}
}

}// namespace ASN1
