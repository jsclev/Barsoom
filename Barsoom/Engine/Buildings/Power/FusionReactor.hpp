#ifndef FUSION_REACTOR_H
#define FUSION_REACTOR_H

#include <SDL.h>
#include "Texture.hpp"

class FusionReactor {
public:
    FusionReactor(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
