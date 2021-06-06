#ifndef BARSOOM_WINDOW_MANAGER_H
#define BARSOOM_WINDOW_MANAGER_H

#include <SDL.h>
#include "constants.hpp"

class WindowManager
{
public:
    WindowManager();

    SDL_Window* createWindow();
    
    SDL_Rect getScreenRect();
    
    int getWindowMultiplier();
};

#endif
