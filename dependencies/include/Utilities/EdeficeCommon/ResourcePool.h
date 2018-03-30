#pragma once

#include "ResourcePoolResource.h"
#include "ResourcePoolResourceLock.h"

#include <deque>

#pragma warning(push)
#pragma warning(disable: 4913)	// Suppress spurious "warning as error" generated by boost
#pragma warning(disable: 4100)
#include <boost/thread.hpp> // (For scoped_lock)
#pragma warning(pop)

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		class ResourcePool
		{
		public:
			enum State
			{
				STATE_NOT_CREATED,			//!< Resources not yet created
				STATE_AVAILABLE,			//!< Operating in basic mode
				STATE_EXCLUSIVE_PENDING,	//!< Switching to exclusive mode
				STATE_EXCLUSIVE_EXECUTING,	//!< Operating in exclusive mode
				STATE_DESTROYING,			//!< Destroying resources
			};

			/*!
			* Create the resource pool with the specified number of resources, blocks until the pool
			* has been created
			*
			* \param[in] numResources
			*   The number of resources to create inside this pool
			* \param[in] lockTimeout
			*   How long internal lock and signal waits will block before failing, in milliseconds.
			*   Set to zero to block indefinitely until the lock or signal is available.
			*
			* \throw
			*   myid::LocalisedException if the pool is being destroyed or is already created
			*/
			ResourcePool(int numResources, int lockTimeout = 0);

			/*!
			* Destroys down the resource pool, blocks until all the resources have been released
			*
			* \throw
			*   myid::LocalisedException if the pool has not been created
			*/
			virtual ~ResourcePool();

			/*!
			* Obtain a resource from the resource pool
			*
			* \param[in] requestExclusiveMode
			*   Set to true to require exclusive access to the resource pool. Use this sparingly
			*   as it will block all other access to resources until the exclusive resource is
			*   returned to the pool
			* \param[in] isPriorityRequest
			*   Set to true to make a priority request, which causes this function to behave in
			*   the same way as ObtainPriorityResource(). It is generally preferable to call that
			*   method directly if priority mode is required since it produces more readable code
			* \param[in] specificResource
			*   resource
			*
			* \return
			*   A smart pointer to a scoped lock around the obtained resource
			*
			* \throw
			*   myid::LocalisedException if the pool has not been created or the pool is destroyed
			*   whilst waiting for the resouce
			*/
			ResourcePoolResourceLockPtr ObtainResource(bool requestExclusiveMode = false, bool isPriorityRequest = false, ResourcePoolResourcePtr specificResource = nullptr);

			/*!
			* Obtain the next available resource from the resource pool, entering the queue ahead
			* of any other threads which are already waiting for the resource
			*
			* \param[in] requestExclusiveMode
			*   Set to true to require exclusive access to the resource pool. Use this sparingly
			*   as it will block all other access to resources until the exclusive resource is
			*   returned to the pool
			*
			* \return
			*   A smart pointer to a scoped lock around the obtained resource
			*
			* \note
			*   The queue does not store a priority state and thus multiple threads calling this
			*   method will cause each new call to take precedence over the previous. Use this
			*   method sparingly!
			*
			* \throw
			*   myid::LocalisedException if the pool has not been created or the pool is destroyed
			*   whilst waiting for the resouce
			*/
			ResourcePoolResourceLockPtr ObtainPriorityResource(bool requestExclusiveMode = false);

			/*!
			* Called by a scoped lock around a resource pool resource once it has been released back
			* to the pool
			*/
			void ResourceReturned(ResourcePoolResourcePtr resource);

			/*!
			* Get the number of resources in the pool
			*/
			int GetNumberOfResources();

			/*!
			* Get the number of resources which are currently being used
			*/
			int GetNumberOfConsumedResources();

			/*!
			* Get the number of resources which are currently available
			*/
			int GetNumberOfFreeResources();

		protected:
			/*!
			* Try to obtain a lock on m_mutex
			*
			* \throw
			*   myid::LocalisedException if the lock timeout expires whilst waiting
			*/
			boost::recursive_mutex::scoped_lock Lock();

			/*!
			* Creates the resource pool on demand if it does not already exist
			*
			* \pre
			*   The caller holds the state lock
			*/
			void CreatePoolOnDemand();

			/*!
			* Check whether the resource pool is shutting down
			*/
			bool IsShuttingDown();

			/*!
			* Method to be implemented by derived classes to create resource objects
			*/
			virtual ResourcePoolResourcePtr CreateResource() = 0;

			/*!
			* Called by ObtainResource or ObtainPriorityResource when there is no resource available
			* immediately, this method will wait on the provided condition variable in a loop until
			* it obtains a resource
			*/
			ResourcePoolResourceLockPtr WaitForResource(bool bExclusive, boost::recursive_mutex::scoped_lock& lock, boost::condition_variable_any& wait, ResourcePoolResourcePtr specificResource = nullptr);

			/*!
			* Called by WaitForResource when waiting to collect the entire set of resources to enter
			* exclusive mode
			*/
			ResourcePoolResourceLockPtr WaitForExclusiveResource(boost::recursive_mutex::scoped_lock& lock);

			/*!
			* Try to obtain a resource to be used by a thread
			*
			* \param[in] specificResource
			*   Try and obtain a specific resource.
			*
			* \return
			*   A smart pointer to a scoped lock around the obtained resource or nullptr if there
			*   are no resources available
			*
			* \pre
			*   The caller holds the state lock and m_state == STATE_AVAILABLE
			*/
			ResourcePoolResourcePtr TryObtainResource(ResourcePoolResourcePtr specificResource = nullptr);

			/*!
			* Get the set of all resources which exist in this pool
			*
			* \warning
			*   This method does not enforce any locking or exclusive access, this should be
			*   handled appropriately by the caller if required.
			*/
			std::vector<ResourcePoolResourcePtr> GetResources()
			{
				return m_resources;
			}

			/*!
			* Wait for a condition variable to become signalled
			*
			* \throw
			*   myid::LocalisedException if the lock timeout expires whilst waiting
			*/
			void WaitForSignal(boost::recursive_mutex::scoped_lock& lock, boost::condition_variable_any& condition);

		private:
			int m_resourceCount;								//!< Number of resources required
			int m_lockTimeout;									//!< Timeout for locking mutexes

			State m_state;										//!< Current pool state
			std::vector<ResourcePoolResourcePtr> m_resources;	//!< Pool of resources
			std::deque<boost::condition_variable_any*> m_queue;	//!< Queue of wait conditions from threads waiting for resources

			boost::recursive_mutex m_mutex;						//!< Mutex to protect against multithreaded access to member variables
			boost::condition_variable_any m_threadSignal;		//!< A condition which is triggered each time a task completes
		};
	}	// End of namespace Threading
}	// End of namespace myid