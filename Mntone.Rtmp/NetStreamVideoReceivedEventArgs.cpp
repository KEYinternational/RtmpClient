#include "pch.h"
#include "NetStreamVideoReceivedEventArgs.h"

namespace Mntone { namespace Rtmp {

	NetStreamVideoReceivedEventArgs::NetStreamVideoReceivedEventArgs( void )
	{ }

	void NetStreamVideoReceivedEventArgs::SetDecodeTimestamp( uint64 decodeTimestamp )
	{
		_DecodeTimestamp.Duration = decodeTimestamp * 10000l;
	}

	void NetStreamVideoReceivedEventArgs::SetPresentationTimestamp( uint64 presentationTimestamp )
	{
		_PresentationTimestamp.Duration = presentationTimestamp * 10000l;
	}

	void NetStreamVideoReceivedEventArgs::SetData( std::vector<uint8> data, const size_t offset )
	{
		auto buf = ref new Windows::Storage::Streams::DataWriter();
		buf->WriteBytes( Platform::ArrayReference<uint8>( data.data() + offset, static_cast<uint32>( data.size() - offset ) ) );
		_Data = buf->DetachBuffer();
	}

} }