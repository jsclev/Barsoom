#ifndef BARSOOM_DEVICE_H
#define BARSOOM_DEVICE_H

#include <SDL.h>
#include "constants.hpp"

class Device
{
public:
    Device(SDL_Renderer *renderer);

    SDL_Window* createWindow();
    
    SDL_Rect getScreenRect();
    
    int getWindowMultiplier();
    
private:
    SDL_Renderer *renderer;
};

#endif
