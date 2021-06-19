#ifndef BARSOOM_BASE_MAP_H
#define BARSOOM_BASE_MAP_H

#include <SDL.h>
#include "constants.hpp"
#include "ScreenManager.hpp"
#include "Texture.hpp"

class BaseMap
{
public:
    BaseMap(SDL_Renderer *renderer, ScreenManager screenManager);
    
    ~BaseMap();

    void startPan(SDL_Point startPos);
    
    void pan(SDL_Point position);
    
    void render();

private:
    SDL_Renderer *renderer;
    Texture texture;
    SDL_Rect *clip;
    SDL_Point startPanPos;
    SDL_Point startClipPos;
};

#endif
