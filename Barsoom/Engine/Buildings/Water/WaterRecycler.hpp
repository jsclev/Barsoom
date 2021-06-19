#ifndef WATER_RECYCLER_H
#define WATER_RECYCLER_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class WaterRecycler: public Building {
public:
    WaterRecycler(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
