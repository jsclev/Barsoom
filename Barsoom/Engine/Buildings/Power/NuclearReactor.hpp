#ifndef NUCLEAR_REACTOR_H
#define NUCLEAR_REACTOR_H

#include <SDL2/SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class NuclearReactor: public Building {
public:
    NuclearReactor(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
