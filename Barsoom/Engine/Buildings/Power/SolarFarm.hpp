#ifndef SOLAR_FARM_H
#define SOLAR_FARM_H

#include <SDL2/SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class SolarFarm: public Building {
public:
    SolarFarm(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
