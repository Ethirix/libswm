#pragma once

#include <windows.h>

class Window
{
public:

	LRESULT CALLBACK WndProc(const HWND hwnd, const UINT message, const WPARAM wParam, const LPARAM lParam);

};
