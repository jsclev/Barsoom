#ifndef HYDROPONIC_GREENHOUSE_H
#define HYDROPONIC_GREENHOUSE_H

#include <SDL.h>

#include "Building.hpp"
#include "Texture.hpp"

class HydroponicGreenhouse: public Building {
public:
    HydroponicGreenhouse(SDL_Renderer *renderer, Texture *texture, int level);
};

#endif
