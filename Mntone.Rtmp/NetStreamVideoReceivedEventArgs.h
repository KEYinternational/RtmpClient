#pragma once
#include "VideoFormat.h"

namespace Mntone { namespace Rtmp {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NetStreamVideoReceivedEventArgs sealed
	{
	internal:
		NetStreamVideoReceivedEventArgs( void );

		void SetDecodeTimestamp( uint64 decodeTimestamp );
		void SetPresentationTimestamp( uint64 presentationTimestamp );
		void SetData( std::vector<uint8> data, const size_t offset = 0 );

	public:
		property bool IsKeyframe
		{
			bool get( void ) { return _IsKeyframe; }
		internal:
			void set( bool value ) { _IsKeyframe = value; }
		}
		property Windows::Foundation::TimeSpan DecodeTimestamp
		{
			Windows::Foundation::TimeSpan get() { return _DecodeTimestamp; }
		}
		property Windows::Foundation::TimeSpan PresentationTimestamp
		{
			Windows::Foundation::TimeSpan get() { return _PresentationTimestamp; }
		}
		property VideoFormat Format
		{
			VideoFormat get() { return _Format; }
		internal:
			void set( VideoFormat value ) { _Format = value; }
		}
		property Windows::Storage::Streams::IBuffer^ Data
		{
			Windows::Storage::Streams::IBuffer^ get() { return _Data; }
		}

	private:
		bool _IsKeyframe;
		Windows::Foundation::TimeSpan _DecodeTimestamp, _PresentationTimestamp;
		VideoFormat _Format;
		Windows::Storage::Streams::IBuffer^ _Data;
	};

} }