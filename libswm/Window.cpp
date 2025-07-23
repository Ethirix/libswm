#include <iostream>
#include "Window.hpp"

class Window::Impl
{
public:
    void test()
    {
        std::cout << "Test!" << '\n';
    }
private:
};

Window::Window() = default;
Window::~Window() = default;

void Window::test()
{
    _impl->test();
}