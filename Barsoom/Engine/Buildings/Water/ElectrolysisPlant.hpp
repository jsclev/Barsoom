#ifndef ELECTROLYSIS_PLANT_H
#define ELECTROLYSIS_PLANT_H

#include <SDL.h>
#include "Texture.hpp"

class ElectrolysisPlant {
public:
    ElectrolysisPlant(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
