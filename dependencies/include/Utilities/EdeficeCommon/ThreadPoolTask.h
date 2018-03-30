#pragma once

// -------------------------------------------------------------------------------------------------

namespace myid
{
	namespace Threading
	{
		class ThreadPoolTask
		{
		public:
			/*!
			* \param[in] isExclusive
			*   Optional, if set to true this task will be executed in exclusive mode. See the notes
			*   on IsExclusive() for the ramifications of this.
			*/
			explicit ThreadPoolTask(bool isExclusive = false)
				: m_isExclusive(isExclusive)
			{}

			virtual ~ThreadPoolTask() {}

			/*!
			* Returns whether this task must be executed in exclusive mode, which requires that the
			* thread pool waits for all executing tasks to complete, won't dispatch any other tasks
			* and then executes only this task. Other tasks will only be dispatched once this task
			* completes.
			*
			* Exclusive mode should be used sparingly if at all and any such tasks should complete
			* quickly to allow the pool to resume operation
			*/
			virtual bool IsExclusive() { return m_isExclusive; }

			/*!
			* This pure virtual method is the entry point for task execution
			*/
			virtual void Execute() = 0;

		private:
			bool m_isExclusive;
		};

		class ThreadPoolTaskFunction : public ThreadPoolTask
		{
		public:
			/*!
			* \param[in] func
			*	The function to execute as this task.
			* \param[in] isExclusive
			*   Optional, if set to true this task will be executed in exclusive mode. See the notes
			*   on IsExclusive() for the ramifications of this.
			*/
			ThreadPoolTaskFunction(std::function<void(void)> const & func, bool isExclusive = false)
				: ThreadPoolTask(isExclusive), m_function(func)
			{}

			virtual ~ThreadPoolTaskFunction() {}

			virtual void Execute()
			{
				m_function();
			}

		private:
			std::function<void(void)> m_function;
		};

		typedef std::shared_ptr<ThreadPoolTask> ThreadPoolTaskPtr;
	}	// End of namespace Threading
}	// End of namespace myid