#ifndef REFINERY_H
#define REFINERY_H

#include <SDL2/SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class Refinery: public Building {
public:
    Refinery(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
