#include "HydroponicGreenhouse.hpp"

HydroponicGreenhouse::HydroponicGreenhouse(SDL_Renderer *renderer, Texture *texture, int level) :
                                           Building(renderer, texture, "Hydroponic Greenhouse", level) {
    spriteClip = {
        level * 329,
        530,
        329,
        220
    };
}
