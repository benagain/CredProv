namespace eXML
{

/// Extract the output string
xmlwriter::operator _bstr_t()
{
	CloseAllNode();
	return m_str.str().c_str();
}

/// Extract the output string
xmlwriter::operator ATL::CComBSTR()
{
	CloseAllNode();
	return m_str.str().c_str();
}

/// Extract the output string
xmlwriter::operator _variant_t()
{
	CloseAllNode();
	return m_str.str().c_str();
}

/// Extract as a detached BSTR
BSTR xmlwriter::ToBSTR(void)
{
	CloseAllNode();
	return _bstr_t(m_str.str().c_str()).Detach();
}

} // namespace
