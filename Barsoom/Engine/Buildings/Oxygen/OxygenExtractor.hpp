#ifndef OXYGEN_EXTRACTOR_H
#define OXYGEN_EXTRACTOR_H

#include <SDL.h>
#include "Texture.hpp"

class OxygenExtractor {
public:
    OxygenExtractor(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
