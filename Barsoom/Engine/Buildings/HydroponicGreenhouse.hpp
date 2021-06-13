#ifndef HYDROPONIC_GREENHOUSE_H
#define HYDROPONIC_GREENHOUSE_H

#include <SDL.h>
#include "Texture.hpp"

class HydroponicGreenhouse {
public:
    HydroponicGreenhouse(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
