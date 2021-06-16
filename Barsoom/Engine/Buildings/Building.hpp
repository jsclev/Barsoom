#ifndef BARSOOM_BUILDING_H
#define BARSOOM_BUILDING_H

#include <SDL.h>
#include "Texture.hpp"

class Building {
public:
    Building(SDL_Renderer *renderer, Texture *texture, int level);

    virtual void render(int gridPositionX, int gridPositionY) = 0;

protected:
    SDL_Renderer *renderer;
    Texture *texture;
    int level = 0;
    SDL_Rect clip = {0, 0, 0, 0};
};

#endif
