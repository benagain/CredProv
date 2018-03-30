#pragma once

// This needs to be valid for C style

/// Reader responses
enum ReaderStatus
{
	READER_SUCCESS				= 0,	///< OK
	READER_SMALL_REPLY			= 1,	///< reply buffer too small
	READER_ADJUST_REPLY			= 2,	///< adjust reply suffer
	READER_NOT_CONNECTED		= 3,	///< reader not connected
	READER_NO_CARD				= 4,	///< reader has no card
	READER_SIMPLEX				= 5,	///< try again in simplex (T0) mode
	READER_LOST_CONNECTION		= 6,	///< reader or card removed
	READER_INVALID_PROTOCOL		= 7,	///< protocol problem
	READER_LOCKED				= 8,	///< card locked
	READER_TIMEOUT				= 9,	///< lock or connection timeout
	READER_REOPEN				= 10,	///< reopen connection or library
	READER_UNKNOWN				= 11,	///< unknown error
};

/// What to do on card reset
enum CardDisposition
{
	LEAVE_CARD		= 0,	///< do nothing
	RESET_CARD		= 1,	///< reset
	UNPOWER_CARD	= 2,	///< power down
	EJECT_CARD		= 3		///< eject
};

