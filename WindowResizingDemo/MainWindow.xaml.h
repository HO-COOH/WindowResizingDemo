// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"
#include <winrt/Windows.System.Threading.h>

namespace winrt::WindowResizingDemo::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Window_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowSizeChangedEventArgs const& args);

        winrt::Windows::System::Threading::ThreadPoolTimer m_timer{nullptr};
        //std::chrono::system_clock::time_point lastResize{};
        //bool isResizing = false;
    };
}

namespace winrt::WindowResizingDemo::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
