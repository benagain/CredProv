#include "../OID.h"

namespace ASN1
{
using namespace Tags;

namespace Decoder
{

/// Get a date from the value data
ATL::COleDateTime ASNTag::ToDate(_In_ int tag)
const
{
	ATL::COleDateTime dt;
	dt.SetStatus(ATL::COleDateTime::DateTimeStatus::null);

	int year, month, day;
	int hour, min, sec;

	switch (tag)
	{
	case ASN_UTCTIME:
		if (m_ValueLength < 12)
			return dt;
		year = 2000 + conv2(&m_Value[0]);
		if (year >= 2050)
			year -= 100;
		month = conv2(&m_Value[2]);
		day = conv2(&m_Value[4]);
		hour = conv2(&m_Value[6]);
		min = conv2(&m_Value[8]);
		sec = conv2(&m_Value[10]);
		break;
	case ASN_GENERALTIME:
		if (m_ValueLength < 14)
			return dt;
		year = conv2(&m_Value[0]) * 100 + conv2(&m_Value[2]);
		month = conv2(&m_Value[4]);
		day = conv2(&m_Value[6]);
		hour = conv2(&m_Value[8]);
		min = conv2(&m_Value[10]);
		sec = conv2(&m_Value[12]);
		break;
	default:
		return dt;
	}

	dt.SetDateTime(year, month, day, hour, min, sec);

	return dt;
}

}// namespace Decoder
}// namespace ASN1
