#pragma once
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <microsoft.ui.xaml.window.h>
#include <Windows.h>

HWND GetHwnd(winrt::Microsoft::UI::Xaml::Window window)
{
    HWND hwnd{};
    window.as<IWindowNative>()->get_WindowHandle(&hwnd);
    return hwnd;
}