#ifndef ELECTROLYSIS_PLANT_H
#define ELECTROLYSIS_PLANT_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class ElectrolysisPlant: public Building {
public:
    ElectrolysisPlant(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
