#include <iostream>
#include <Windows.h>
#include "wtypes.h"

void GetDesktopResolution(int& horizontal, int& vertical);
void LeftClick();

int main() {
    int horizontal = 0;
    int vertical = 0;
    GetDesktopResolution(horizontal, vertical);
    vertical -= 30;
    std::cout << horizontal << std::endl;
    std::cout << vertical<< std::endl;
    std::cout << 0 << std::endl;
    SetCursorPos(417, 14);
    LeftClick();
    int c=0,h=40;
//    while (c < 10){
//        vertical -= 50;
//        h += 40;
//        SetCursorPos(h, vertical);
//        Sleep(500);
//        c =c+1;
//    }
//    while (c > 0){
//        vertical += 50;
//        h -= 40;
//        SetCursorPos(h, vertical);
//        Sleep(500);
//        c =c-1;
//    }
    return 0;
}


void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    horizontal = desktop.right;
    vertical = desktop.bottom;
}
void LeftClick()
{
    INPUT    Input={0};													// Create our input.

    Input.type        = INPUT_MOUSE;									// Let input know we are using the mouse.
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							// We are setting left mouse button down.
    SendInput( 1, &Input, sizeof(INPUT) );								// Send the input.

    ZeroMemory(&Input,sizeof(INPUT));									// Fills a block of memory with zeros.
    Input.type        = INPUT_MOUSE;									// Let input know we are using the mouse.
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								// We are setting left mouse button up.
    SendInput( 1, &Input, sizeof(INPUT) );								// Send the input.
}

