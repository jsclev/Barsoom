#ifndef OXYGEN_EXTRACTOR_H
#define OXYGEN_EXTRACTOR_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class OxygenExtractor: public Building {
public:
    OxygenExtractor(SDL_Renderer *renderer, Texture *texture, int level);

    void render(int gridPositionX, int gridPositionY) override;
};

#endif
