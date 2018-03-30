#pragma once
#include "ThreadPoolTask.h"

#pragma warning(push)
#pragma warning(disable: 4913)	// Suppress spurious "warning as error" generated by boost
#pragma warning(disable: 4100) // Unreferenced formal parameter
#include <boost/thread.hpp>
#pragma warning(pop)

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		/*!
		* Wrapper for a boost::thread which stores additional state information used by the thread
		* pool and the lock for this thread
		*/
		class ThreadPoolThread
		{
		public:
			explicit ThreadPoolThread(class ThreadPool* threadPool);

			virtual ~ThreadPoolThread();

			/*!
			* Check if this thread is currently busy. It is recommended to lock around this call if
			* the intention is to subsequently call ExecuteTask to ensure another thread doesn't
			* steal this object for its own task
			*/
			bool IsBusy();

			/*! Locks this object, blocking until the lock is successful */
			boost::recursive_mutex::scoped_lock Lock();

			/*!
			* Try to lock this object, use the boolean operator of the scoped_lock to check whether
			* the lock was successfully acquired
			*/
			boost::recursive_mutex::scoped_lock TryLock();

			/*!
			* Execute the provided task within the execution thread. The caller should lock around
			* this call and check IsBusy() to avoid throwing an exception if the execution thread is
			* busy
			*
			* \throws myid::LocalisedException if this thread is busy
			*/
			void ExecuteTask(ThreadPoolTaskPtr task);

		protected:
			/*! Entry point and logical loop for the execution thread */
			void ThreadMain();

		private:
			ThreadPool* m_threadPool;						//!< The thread pool that owns this object
			boost::thread m_thread;							//!< Execution thread
			ThreadPoolTaskPtr m_task;						//!< Current task being executed
			boost::recursive_mutex m_taskMutex;				//!< Mutex protecting m_task
			boost::condition_variable_any m_taskSignal;		//!< Condition for the execution thread to wait upon
			bool m_shouldStop;								//!< Stop signal for the execution thread
		};

		typedef std::shared_ptr<ThreadPoolThread> ThreadPoolThreadPtr;
	}	// End of namespace Threading
}	// End of namespace myid