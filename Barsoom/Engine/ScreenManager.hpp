#ifndef BARSOOM_SCREEN_MANAGER_H
#define BARSOOM_SCREEN_MANAGER_H

#include <SDL.h>
#include "constants.hpp"

class ScreenManager
{
public:
    ScreenManager(SDL_Renderer *renderer);

    SDL_Window* createWindow();
    
    SDL_Rect getScreenRect();
    
    int getWindowMultiplier();
    
private:
    SDL_Renderer *renderer;
};

#endif
