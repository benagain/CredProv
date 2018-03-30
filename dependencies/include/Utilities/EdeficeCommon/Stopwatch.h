#pragma once
#include <stdint.h>

namespace myid
{
namespace Utilities
{
/*!
* A simple class to provide high resolution timing of events using the Windows performance
* counter to get sub-millisecond accuracy. It can be used to time a single event or multiple
* intervals, providing useful statistics such as the fastest and slowest intervals and the
* mean average of all intervals.
*/
class Stopwatch
{
public:
	/*!
	* \param[in] startTiming
	*   Set to true to implicitly call Start() upon construction
	*/
	explicit Stopwatch(_In_ bool startTiming = false);

	virtual ~Stopwatch();

	/*!
	* Start timing an event. If timing had already begun this will reset the timer and
	* begin counting from zero again
	*/
	void Start();

	/*!
	* Stop the internal timer and records a new interval with the elapsed time since the
	* last call to Start(). If Start() had not previously been called (or had not been
	* called since the last call to Stop()) the results of calling this are undefined.
	*
	* \return
	*   The duration of the interval, in milliseconds
	*/
	int64_t Stop();

	/*!
	* Stops the internal timer, records a new interval and restarts the timer. Similar to
	* calling Stop() followed by Start() but avoids a small gap in timing which would be
	* present in calling the two functions separately.
	*
	* \return
	*   The duration of the completed interval, in milliseconds
	*/
	int64_t Restart();

	/*!
	* Get the time taken to complete the most recently timed interval, in milliseconds
	*
	* \pre
	*   Start() and Stop() have previously been called, in that order, at least once
	*/
	int64_t GetTime();

	/*!
	* Get the total time of all intervals since the most recent call to ClearIntervals(),
	* in milliseconds
	*
	* \pre
	*   Start() and Stop() have previously been called, in that order, at least once
	*/
	int64_t GetTotalTime();

	/*!
	* Get the total number of intervals that have been completed
	*/
	int64_t GetNumberOfIntervals() { return m_numIntervals; }

	/*!
	* Get the mean time of all intervals since the most recent call to ClearIntervals(),
	* in milliseconds
	*
	* \pre
	*   Start() and Stop() have previously been called, in that order, at least once
	*/
	int64_t GetMeanIntervalTime();

	/*!
	* Get the slowest time of all intervals since the most recent call to ClearIntervals(),
	* in milliseconds
	*
	* \pre
	*   Start() and Stop() have previously been called, in that order, at least once
	*/
	int64_t GetSlowestIntervalTime();

	/*!
	* Get the fastest time of all intervals since the most recent call to ClearIntervals(),
	* in milliseconds
	*
	* \pre
	*   Start() and Stop() have previously been called, in that order, at least once
	*/
	int64_t GetFastestIntervalTime();

	/*!
	* Clear all data from previously recorded intervals and reset all statistics
	*/
	void ClearIntervals();

private:
	/*!
	* Internal method to update the interval data with a new interval
	*/
	void RecordInterval(_In_ int64_t interval);

	int64_t m_perfCountsPerMs;	//!< System performance counter counts per millisecond
	int64_t m_startTime;		//!< Performance counter count at the most recent call to Start()
	int64_t m_time;				//!< Duration of the most recent interval in performance counter counts

	// Interval data
	int64_t m_numIntervals;		//!< Total number of intervals
	int64_t m_totalTime;		//!< Total time for all intervals in performance counter counts
	int64_t m_shortestTime;		//!< Shortest intervals time in performance counter counts
	int64_t m_longestTime;		//!< Longest intervals time in performance counter counts
};

typedef std::shared_ptr<Stopwatch> StopwatchPtr;
}
}
