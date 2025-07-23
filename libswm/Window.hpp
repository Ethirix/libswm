#ifndef LIBSWM_WINDOW_HPP
#define LIBSWM_WINDOW_HPP

#include <memory>

class Window
{
public:
    Window();
    ~Window();
    
    void test();
    
private:
    class Impl;
    std::unique_ptr<Impl> _impl;
};

#endif
