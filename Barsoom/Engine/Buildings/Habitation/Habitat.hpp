#ifndef HABITAT_H
#define HABITAT_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class Habitat: public Building {
public:
    Habitat(SDL_Renderer *renderer, Texture *texture, int level);

    void render(int gridPositionX, int gridPositionY) override;
};

#endif
