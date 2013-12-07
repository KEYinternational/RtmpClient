#pragma once
#include "pch.h"

namespace Mntone { namespace Rtmp {

	extern void ConvertBigEndian( const void *const from, void *const to, const size_t size );
	extern void ConvertLittleEndian( const void *const from, void *const to, const size_t size );

	extern uint64 WindowsTimeToUnixTime( const int64 windowsTime );
	extern int64 UnixTimeToWindowsTime( const uint64 unixTime );

	extern Windows::Foundation::DateTime GetDateTime();
	extern int64 GetWindowsTime();

	extern uint32 HundredNanoToMilli( int64 hundredNano );

} }