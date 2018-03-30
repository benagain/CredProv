#pragma once

#include "VectorOfByte.h"

#include <wbemidl.h>

_COM_SMARTPTR_TYPEDEF(IWbemContext, __uuidof(IWbemContext));
_COM_SMARTPTR_TYPEDEF(IWbemLocator, __uuidof(IWbemLocator));
_COM_SMARTPTR_TYPEDEF(IWbemServices, __uuidof(IWbemServices));
_COM_SMARTPTR_TYPEDEF(IWbemClassObject, __uuidof(IWbemClassObject));
_COM_SMARTPTR_TYPEDEF(IWbemStatusCodeText, __uuidof(IWbemStatusCodeText));

namespace WMI
{

	/// Service class to manage interface to WMI
	class Wmi
	{
	public:
		explicit Wmi(const std::wstring& machineName);
		bool Connect(const std::wstring& service);
		bool Connected(void) const;

		bool Exec(const _bstr_t& path, const wchar_t* method, IWbemClassObject* paramIn, IWbemClassObject** paramOut) const;
		void GetInputDef(const IWbemClassObjectPtr& object, const wchar_t* method, IWbemClassObject** paramIn) const;
		void GetReturnValue(const IWbemClassObjectPtr& object) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, _variant_t& value) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, bool& value) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, long& value) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, unsigned long& value) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, std::wstring& value) const;
		void Get(const IWbemClassObjectPtr& object, const wchar_t* param, VectorOfByte& value) const;
		void Put(const IWbemClassObjectPtr& object, const wchar_t* param, const _variant_t& value) const;
		void Put(const IWbemClassObjectPtr& object, const wchar_t* param, const std::wstring& value) const;

		bool Success(void) const;
		std::wstring Message(void) const;
		long ErrNumber(void) const;

	protected:
		void ClearError(void);
		void Error(void);

		bool				m_tested;		///< has connected been tested
		bool				m_connected;	///< has connection been made
		std::wstring		m_machine;		///< machine to connect to
		IWbemLocatorPtr		m_loc;			///< WMI locator
		IWbemServicesPtr	m_svc;			///< WMI service
		std::wstring		m_message;		///< result message
		long				m_errNum;		///< error number
		mutable HRESULT		m_hr;			///< result code
	};

	class WmiClass : public Wmi
	{
		typedef Wmi inherited;

	public:
		explicit WmiClass(const std::wstring& machineName);

		void Path(const wchar_t* path);
		bool Exec(const wchar_t* method, IWbemClassObject* paramIn, IWbemClassObject** paramOut) const;
		void GetInputDef(const wchar_t* method, IWbemClassObject** paramIn) const;
		void Property(const wchar_t* param, bool& value) const;
		void Property(const wchar_t* param, long& value) const;
		void Property(const wchar_t* param, unsigned long& value) const;
		void Property(const wchar_t* param, std::wstring& value) const;

	protected:
		_bstr_t			m_path;				///< class path for object
		_bstr_t			m_exec;				///< class path for exec
		IWbemClassObjectPtr m_pathObj;		///< class object
		IWbemClassObjectPtr m_execObj;		///< class object
	};

} // namespace WMI
