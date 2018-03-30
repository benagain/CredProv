#pragma once

#include "ThreadPoolTask.h"
#include "ThreadPoolThread.h"
#include <deque>

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		class ThreadPool
		{
		public:
			enum State
			{
				STATE_NOT_STARTED,			//!< Threads not yet created
				STATE_RUNNING,				//!< Operating in basic mode
				STATE_EXCLUSIVE_PENDING,	//!< Switching to exclusive mode
				STATE_EXCLUSIVE_RUNNING,	//!< Operating in exclusive mode
				STATE_STOPPING,				//!< Shutting down tasks and threads
				STATE_STOPPED				//!< Threads have stopped
			};

			ThreadPool();

			virtual ~ThreadPool();

			/*!
			* Start the thread pool with the specified number of threads, blocks until the pool
			* has started
			*
			* \throw
			*   myid::LocalisedException if the pool is shutting down
			*/
			void Start(int numThreads);

			/*!
			* Shut down the thread pool, blocks until the pool has stopped
			*
			* \throw
			*   myid::LocalisedException if the pool is not running
			*/
			void Stop();

			/*!
			* Check whether the thread pool is currently running and ready to receieve tasks
			*/
			bool IsRunning();

			/*!
			* Enqueue an item of work for the pool to complete
			*
			* \throw
			*   myid::LocalisedException if the pool is not running
			*/
			void EnqueueTask(ThreadPoolTaskPtr task);

			/*!
			* Inject a priority task at the head of the queue for execution as soon as the next
			* thread becomes available.
			*
			* \note
			*   The queue does not store a priority state for tasks and thus adding multiple
			*   tasks in this way will cause each new tasks to take precedence over previously
			*   added priority tasks. Use this method sparingly!
			*
			* \throw
			*   myid::LocalisedException if the pool is not running
			*/
			void EnqueuePriorityTask(ThreadPoolTaskPtr task);

			/*!
			* Called by a thread object once it has completed its current task to allow the pool
			* to allocate it a new task, if one is available. Note that this runs inside the worker
			* thread so should not block unnecessaraily
			*/
			void NotifyTaskCompleted(ThreadPoolThread* thread, ThreadPoolTaskPtr const & task);

			/*!
			* Get the number of threads in the pool
			*/
			int GetNumberOfThreads();

			/*!
			* Get the number of threads which are currently executing a task
			*/
			int GetNumberOfActiveThreads();

			/*!
			* Get the number of threads which are currently idle
			*/
			int GetNumberOfIdleThreads();

		protected:
			boost::recursive_mutex::scoped_lock Lock();

			/*!
			* Tries to find an available executor for a task to execute it immediately, returns
			* true if the task was started, false otherwise (in which case it will get queued)
			*
			* \pre
			*   The state lock is held by the caller and m_state == STATE_RUNNING
			*/
			bool TryExecuteTask(ThreadPoolTaskPtr task);

			/*!
			* Checks if the conditions are met for executing an exclusive task and, if so, picks
			* a thread to execute it and returns true. Otherwise returns false.
			*
			* \pre
			*   The state lock is held by the caller and m_state == STATE_EXCLUSIVE_PENDING
			*
			* \post
			*   If successful m_state will be set to STATE_EXCLUSIVE_RUNNING
			*/
			bool TryExecuteExclusiveTask(ThreadPoolTaskPtr task);

			/*!
			* Attempts to find work for a thread to do, returning true if a task was assigned to
			* the thread and false otherwise.
			*
			* \note
			*   If the next task in the queue requires exclusive mode the state variable will be
			*   set to STATE_EXCLUSIVE_PENDING and it will return false
			*
			* \pre
			*   The state lock is held by the caller and m_state == STATE_RUNNING
			*/
			bool FindWorkForThread(ThreadPoolThreadPtr thread);

		private:
			State m_state;									//!< Current pool state
			std::vector<ThreadPoolThreadPtr> m_threads;		//!< Pool of execution threads
			std::deque<ThreadPoolTaskPtr> m_taskQueue;		//!< Queue of pending tasks

			boost::recursive_mutex m_mutex;					//!< Mutex to protect against multithreaded access to member variables
			boost::condition_variable_any m_threadSignal;	//!< A condition which is triggered each time a task completes
		};
	}	// End of namespace Threading
}	// End of namespace myid