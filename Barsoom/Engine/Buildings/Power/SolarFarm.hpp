#ifndef SOLAR_FARM_H
#define SOLAR_FARM_H

#include <SDL.h>
#include "Texture.hpp"

class SolarFarm {
public:
    SolarFarm(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
