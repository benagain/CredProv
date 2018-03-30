#pragma once

#include "Conversions/StringUtils.h"
#include "Exceptions/LocalisedException.h"


template<class T>
std::wstring TypeName()
{
	return myid::ToWstr(&typeid(T).name()[6]);
}

template<class TCastTo, class TCastFrom> TCastTo& CheckedDynamicCast(TCastFrom *pIn)
{
	TCastTo *pParam(NULL);
	try
	{
		pParam = dynamic_cast<TCastTo*>(pIn);
	}
	catch(std::bad_cast&)
	{
		std::wstring message = L"Invalid ";
		message += TypeName<TCastTo>();
		throw myid::LocalisedException(LOCALISE_FN_STATIC, message);
	}

	if(!pParam)
	{
		std::wstring message = TypeName<TCastTo>();
		message += L" not set";
		throw myid::LocalisedException(LOCALISE_FN_STATIC, message);
	}

	return *pParam;
}
