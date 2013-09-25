﻿#pragma once
#include "MainPage.g.h"
#include <queue>
#include <mutex>
#include <condition_variable>

namespace Mntone { namespace Rtmp { namespace DemoApp {

	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void OnButtonClicked( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnStarted( Platform::Object^ sender, Mntone::Rtmp::Client::SimpleVideoClientStartedEventArgs^ args );

	private:
		Mntone::Rtmp::Client::SimpleVideoClient^ _client;
	};

} } }