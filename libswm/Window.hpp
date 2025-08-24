#ifndef LIBSWM_WINDOW_HPP
#define LIBSWM_WINDOW_HPP

#include <memory>

class Window
{
public:
    Window();
    explicit Window(std::string_view name);
    ~Window();
    
    std::string_view GetWindowName();
    
    void SetWindowName(const std::string_view& name);
    
private:
    class Impl;
    std::unique_ptr<Impl> _impl;
};

#endif
