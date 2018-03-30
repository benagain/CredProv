#pragma once

#include "ResourcePoolResource.h"

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		// Forward declarations
		class ResourcePool;

		// -----------------------------------------------------------------------------------------

		class ResourcePoolResourceLock
		{
		public:

			ResourcePoolResourceLock(ResourcePool* pool, ResourcePoolResourcePtr const & resource);

			virtual ~ResourcePoolResourceLock();

			/*!
			* Get the resource locked by this object
			*/
			ResourcePoolResourcePtr GetResource()
			{
				return m_resource;
			}

			/*!
			* Return the resource to the pool. This will automatically be called by the destructor
			* once the lock goes out of scope, however it can manually be called if desired. Note
			* that the caller must not continue using the resource after calling this method.
			*
			* \post
			*   The resource will be returned to the pool and the GetResource() method will return a
			*   nullptr if called in future
			*/
			void Unlock();

		private:
			ResourcePool* m_pool;								//!< Pointer to the pool which owns the resource
			ResourcePoolResourcePtr m_resource;					//!< The resource which has been locked
		};

		typedef std::shared_ptr<ResourcePoolResourceLock> ResourcePoolResourceLockPtr;
	}	// End of namespace Threading
}	// End of namespace myid