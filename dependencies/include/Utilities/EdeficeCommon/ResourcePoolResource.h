#pragma once

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		class ResourcePoolResource
		{
		public:
			/*!
			*/
			ResourcePoolResource()
				: m_isAvailable(true)
			{}

			virtual ~ResourcePoolResource() {}

			/*!
			* Returns whether this resource is available or not
			*/
			bool IsAvailable() { return m_isAvailable; }

		private:
			friend class ResourcePool;

			/*!
			* Set whether this resource is available or not
			*/
			void SetIsAvailable(bool isAvailable) { m_isAvailable = isAvailable; }

			bool m_isAvailable;
		};

		typedef std::shared_ptr<ResourcePoolResource> ResourcePoolResourcePtr;
	}	// End of namespace Threading
}	// End of namespace myid