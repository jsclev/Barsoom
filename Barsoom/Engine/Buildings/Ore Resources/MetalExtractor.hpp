#ifndef METAL_EXTRACTOR_H
#define METAL_EXTRACTOR_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class MetalExtractor: public Building {
public:
    MetalExtractor(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
