#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "NetConnection.h"
#include "NetStream.h"
#include "SimpleVideoClientStartedEventArgs.h"
#include "SimpleVideoClientStoppedEventArgs.h"

namespace Mntone { namespace Rtmp { namespace Client {

	[Windows::Foundation::Metadata::DualApiPartition( version = NTDDI_WINBLUE )]
	[Windows::Foundation::Metadata::MarshalingBehavior( Windows::Foundation::Metadata::MarshalingType::Agile )]
	[Windows::Foundation::Metadata::Threading( Windows::Foundation::Metadata::ThreadingModel::STA )]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SimpleVideoClient sealed
	{
	public:
		SimpleVideoClient();
		virtual ~SimpleVideoClient();

		void Connect( Windows::Foundation::Uri^ uri );
		[Windows::Foundation::Metadata::DefaultOverload] void Connect( RtmpUri^ uri );

	private:
		void __Close();

		// NetConnection
		void OnNetConnectionStatusUpdated( Platform::Object^ sender, NetStatusUpdatedEventArgs^ args );

		// NetStream
		void OnAttached( NetStream^ sender, NetStreamAttachedEventArgs^ args );
		void OnNetStreamStatusUpdated( Platform::Object^ sender, NetStatusUpdatedEventArgs^ args );
		void OnAudioStarted( NetStream^ sender, NetStreamAudioStartedEventArgs^ args );
		void OnAudioReceived( NetStream^ sender, NetStreamAudioReceivedEventArgs^ args );
		void OnVideoStarted( NetStream^ sender, NetStreamVideoStartedEventArgs^ args );
		void OnVideoReceived( NetStream^ sender, NetStreamVideoReceivedEventArgs^ args );

		// MediaStreamSource
		void OnStarting( Windows::Media::Core::MediaStreamSource^ sender, Windows::Media::Core::MediaStreamSourceStartingEventArgs^ args );
		void OnSampleRequested( Windows::Media::Core::MediaStreamSource^ sender, Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs^ args );

	public:
		event Windows::Foundation::EventHandler<SimpleVideoClientStartedEventArgs^>^ Started;
		event Windows::Foundation::TypedEventHandler<SimpleVideoClient^, SimpleVideoClientStoppedEventArgs^>^ Stopped;

	private:
		Windows::UI::Core::CoreDispatcher^ dispatcher_;

		NetConnection^ connection_;
		NetStream^ stream_;
		Windows::Media::Core::MediaStreamSource^ mediaStreamSource_;

		// Buffer
		mutable std::mutex audioMutex_, videoMutex_;
		std::condition_variable audioConditionVariable_, videoConditionVariable_;
		std::queue<NetStreamAudioReceivedEventArgs^> audioBuffer_;
		std::queue<NetStreamVideoReceivedEventArgs^> videoBuffer_;
	};

} } }