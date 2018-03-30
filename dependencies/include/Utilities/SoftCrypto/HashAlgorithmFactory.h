#pragma once

#include <map>
#include <string>
#include "HashAlgorithm.h"

namespace myid
{
	class HashAlgorithmFactoryRegistrar;

	/*!
	* A static factory class for creating HashAlgorithm instances
	*/
	class HashAlgorithmFactory
	{
	public:
		/*!
		* Gets the singleton instance of the factory
		*/
		static HashAlgorithmFactory& Instance()
		{
			
			return instance;
		}

		/*!
		* Gets a stateless instance of the named hash algorithm, this static method is a wrapper
		* around Instance().GetAlgorithmByName(pwszAlgorithm) for the sake of code readability
		*
		* \param[in] pwszAlgorithm
		*   The null terminated name of the algorithm to get an instance of
		*
		* \return
		*   A hash algorithm instance or NULL if no such algorithm exists
		*/
		static HashAlgorithmPtr GetAlgorithm(const wchar_t* pwszAlgorithm)
		{
			return Instance().GetAlgorithmByName(pwszAlgorithm);
		}

		/*!
		* Gets a stateless instance of the named hash algorithm, this static method is a wrapper
		* around Instance().GetAlgorithmByName(pwszAlgorithm) for the sake of code readability
		*
		* \param[in] wstrAlgorithm
		*   The name of the algorithm to get an instance of
		*
		* \return
		*   A hash algorithm instance or NULL if no such algorithm exists
		*/
		static HashAlgorithmPtr GetAlgorithm(const std::wstring& wstrAlgorithm)
		{
			return GetAlgorithm(wstrAlgorithm.c_str());
		}

		/*!
		* Gets a stateless instance of the named hash algorithm
		*
		* \param[in] pwszAlgorithm
		*   The null terminated name of the algorithm to get an instance of
		*
		* \return
		*   A hash algorithm instance or NULL if no such algorithm exists
		*/
		HashAlgorithmPtr GetAlgorithmByName(const wchar_t* pwszAlgorithm);

		/*!
		* Registers a new hash algorithm with the factory
		*/
		void Register(const wchar_t* pwszAlgorithm, HashAlgorithmFactoryRegistrar* registrar);

	private:
		static HashAlgorithmFactory instance;

		std::map<std::wstring, HashAlgorithmFactoryRegistrar*> algorithms;
	};

	// ---------------------------------------------------------------------------------------------

	/*!
	* Registrar class for the hash algorithm factory
	*/
	class HashAlgorithmFactoryRegistrar
	{
	public:
		explicit HashAlgorithmFactoryRegistrar(const wchar_t* pwszAlgorithm)
		{
			HashAlgorithmFactory::Instance().Register(pwszAlgorithm, this);
		}

		virtual HashAlgorithmPtr GetInstance() = 0;
	};

	// ---------------------------------------------------------------------------------------------

	/*!
	* Registrant for a specific hash algorithm. For efficiency this stores a single static instance
	* of the hash algorithm class rather than creating a new one for each request... if in future we
	* create a non-reusable hash algorithm we could create a HashAlgorithmDynamicRegistrant.
	*/
	template <class H> class HashAlgorithmRegistrant : public HashAlgorithmFactoryRegistrar
	{
	public:
		explicit HashAlgorithmRegistrant(const wchar_t* pwszAlgorithm)
			: HashAlgorithmFactoryRegistrar(pwszAlgorithm),
			instance(new H())
		{}

		HashAlgorithmPtr GetInstance()
		{
			return instance;
		}
		
	private:
		HashAlgorithmPtr instance;
	};
}