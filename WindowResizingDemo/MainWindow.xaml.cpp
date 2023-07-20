// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <dwmapi.h>
#include "Utils.h"
#pragma comment(lib, "dwmapi.lib")


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WindowResizingDemo::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();


    }
}


void winrt::WindowResizingDemo::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    //Contents().Visibility(winrt::Microsoft::UI::Xaml::Visibility::Collapsed);

}


void winrt::WindowResizingDemo::implementation::MainWindow::Window_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowSizeChangedEventArgs const& args)
{
    if (m_timer)
    {
        m_timer.Cancel();
    }
    else
    {
        OutputDebugString(L"Called\n");
        SystemBackdrop(winrt::Microsoft::UI::Xaml::Media::DesktopAcrylicBackdrop{});
        ResizingAnimation().Begin();
    }
    m_timer = winrt::Windows::System::Threading::ThreadPoolTimer::CreateTimer(
        [this](auto...)
        {
            DispatcherQueue().TryEnqueue([this] {
                ResizeFinishAnimation().Begin();
                m_timer = nullptr;
                });

        }, std::chrono::milliseconds{100}
    );

    //lastResize = std::chrono::system_clock::now();
    //if (!isResizing)
    //{
    //    isResizing = true;
    //    ResizingAnimation().Begin();
    //    return;
    //}

    //if ((std::chrono::system_clock::now() - lastResize) < std::chrono::milliseconds{200})
    //{

    //    return;
    //}
    //isResizing = false;
    //ResizeFinishAnimation().Begin();
    //ResizeFinishAnimation().
}
