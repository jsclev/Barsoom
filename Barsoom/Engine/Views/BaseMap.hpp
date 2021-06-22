#ifndef BARSOOM_BASE_MAP_H
#define BARSOOM_BASE_MAP_H

#include <math.h>
#include <SDL.h>

#include "BgMap.hpp"
#include "constants.hpp"
#include "ScreenManager.hpp"
#include "Texture.hpp"

class BaseMap
{
public:
    BaseMap(SDL_Renderer *renderer, ScreenManager screenManager);
    
    ~BaseMap();
    
    bool isPanStopping();

    void startPan(SDL_Point position);
    
    void pan(SDL_Point position, SDL_Point prevPosition);
    
    void stopPan(SDL_Point position);
    
    void render();

private:
    SDL_Renderer *renderer;
    Texture texture;
    BgMap *bgMap;
};

#endif
