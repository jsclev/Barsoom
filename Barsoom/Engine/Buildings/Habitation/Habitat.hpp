#ifndef HABITAT_H
#define HABITAT_H

#include <SDL2/SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class Habitat: public Building {
public:
    Habitat(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
