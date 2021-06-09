#ifndef BARSOOM_BASE_MAP_H
#define BARSOOM_BASE_MAP_H

#include <SDL.h>
#include "constants.hpp"
#include "Texture.hpp"

class BaseMap
{
public:
    BaseMap(SDL_Renderer *renderer);

    void setScreenRect(SDL_Rect screenRect);
    
    void render();

private:
    SDL_Renderer *renderer;
    Texture mapTexture;
    SDL_Rect mapClip;
    const int BG_WIDTH = 4096;
    const int BG_HEIGHT = 4096;
};

#endif
