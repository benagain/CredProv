
/// AddParameter
/// Adds the specified parameter name and value to the trace stream.
/// If this is defined as sensitive data, the value is replaced by ***
void DebugParameter::AddParameter(
	_In_z_ const wchar_t* Name,		///< The parameter name.
	_In_ const BSTR Value,			///< The parameter value.
	_In_ bool Sensitive)			///< True if the parameter value is sensitive information, otherwise false.
{
	if (operator bool() && Name)
	{
		if ((Value == NULL) || (*Value == 0))
		{
			GetWStream() << L"Input: " << Name << L" - " << std::endl;
			return;
		}

		std::wstring InsensitiveValue(Value);
		if (Sensitive)
		{
			ScrubSensitiveData(L"", L"", InsensitiveValue);
		}

		GetWStream() << L"Input: " << Name << L" - " << InsensitiveValue << std::endl;
	}
}

/// AddParameter
/// Adds the specified boolean parameter name and value to the trace stream.
void DebugParameter::AddParameter(
	_In_z_ const wchar_t* Name,			///< The parameter name.
	_In_ const VARIANT_BOOL& Value)		///< The parameter value.
{
	if (operator bool() && Name)
	{
		if (Value)
		{
			GetWStream() << L"Input: " << Name << L" - TRUE" << std::endl;
		}
		else
		{
			GetWStream() << L"Input: " << Name << L" - FALSE" << std::endl;
		}
	}
}

/// AddParameterXML
/// Replaces the data in any node names listed in SensitiveNodes with ***,
/// then adds the XML as a parameter.
void DebugParameter::AddParameterXML(
	_In_z_ const wchar_t* Name,				///< The parameter name.
	_In_ const BSTR Value,					///< The parameter value as a valid XML document.
	_In_ const StringList& SensitiveNodes)	///< A vector of node names that are to be treated as sensitive data.
{
	if (operator bool() && Name)
	{
		if ((Value == NULL) || (*Value == 0))
		{
			// add the XML as a parameter
			AddParameter(Name, Value);
			return;
		}

		std::wstring InsensitiveXML(Value);

		RemoveSensitiveNodes(InsensitiveXML, SensitiveNodes);

		// add the XML as a parameter
		AddParameter(Name, InsensitiveXML);
	}
}

/// AddOutput
/// Adds the specified output parameter name and value to the trace stream.
/// If this is defined as sensitive data, the value is replaced by ***
void DebugParameter::AddOutput(
	_In_z_ const wchar_t* Name,		///< The name of the output parameter.
	_In_ const BSTR Value,			///< The value of the output parameter.
	_In_ bool Sensitive)			///< True if the output parameter is sensitive data, otherwise false.
{
	if (operator bool() && Name)
	{
		if ((Value == NULL) || (*Value == 0))
		{
			GetWStream() << L"Output: " << Name << L" - " << std::endl;
			return;
		}

		std::wstring InsensitiveValue(Value);
		if (Sensitive)
		{
			ScrubSensitiveData(L"", L"", InsensitiveValue);
		}

		GetWStream() << L"Output: " << Name << L" - " << InsensitiveValue << std::endl;
	}
}

/// AddOutput
/// Adds the specified boolean output parameter name and value to the trace stream.
void DebugParameter::AddOutput(
	_In_z_ const wchar_t* Name,			///< The name of the output parameter.
	_In_ const VARIANT_BOOL& Value)		///< The value of the output parameter.
{
	if (operator bool() && Name)
	{
		if (Value)
		{
			GetWStream() << L"Output: " << Name << L" - TRUE" << std::endl;
		}
		else
		{
			GetWStream() << L"Output: " << Name << L" - FALSE" << std::endl;
		}
	}
}

/// AddOutputXML
/// Replaces the data in any node names listed in SensitiveNodes with ***,
/// then adds the XML as an output parameter.
void DebugParameter::AddOutputXML(
	_In_z_ const wchar_t* Name,					///< The name of the output parameter.
	_In_ const BSTR Value,						///< The output parameter as a valid XML document.
	_In_ const StringList& SensitiveNodes)		///< A vector of node names that are to be treated as sensitive data.
{
	if (operator bool() && Name)
	{
		if ((Value == NULL) || (*Value == 0))
		{
			// add the XML as a parameter
			AddOutput(Name, Value);
			return;
		}

		std::wstring InsensitiveXML(Value);

		RemoveSensitiveNodes(InsensitiveXML, SensitiveNodes);

		// add the XML as a parameter
		AddOutput(Name, InsensitiveXML);
	}
}

