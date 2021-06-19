#ifndef FUSION_REACTOR_H
#define FUSION_REACTOR_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class FusionReactor: public Building {
public:
    FusionReactor(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
