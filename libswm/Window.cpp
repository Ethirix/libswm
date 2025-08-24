#include "Window.hpp"

#include <iostream>
#include <windows.h>

class Window::Impl
{
public:
    Impl()
    {
        WNDCLASSEXA wndClass {};
        wndClass.style = 0;
        wndClass.lpfnWndProc = WndProc;
        wndClass.lpszClassName = "Untitled Window";

        RegisterClassExA(&wndClass);
        
        _hwnd = CreateWindowExA()
    }

    Impl(std::string_view name)
    {
        _hwnd = CreateWindowExA()
    }
    
    
    void SetWindowName(const std::string_view& name)
    {
        SetWindowText(_hwnd, name.data());
    }
    

private:

    static LRESULT CALLBACK WndProc(HWND hwnd, const UINT message, const WPARAM wParam, const LPARAM lParam)
    {
        Impl* window = reinterpret_cast<Impl*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        switch (message)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        default:
            return DefWindowProc(hwnd, message, wParam, lParam);    
        }

        return 0;
    }
    
    HWND _hwnd = nullptr;
};

Window::Window() = default;

Window::Window(std::string_view name)
{
    _impl = std::make_unique<Impl>(name);
}

Window::~Window() = default;

void Window::SetWindowName(const std::string_view& name)
{
    
}