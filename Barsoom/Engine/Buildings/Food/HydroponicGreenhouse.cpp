#include "HydroponicGreenhouse.hpp"

HydroponicGreenhouse::HydroponicGreenhouse(SDL_Renderer *renderer, Texture *texture, int level) :
                                           Building(renderer, texture, level) {
    clip = {
        level * 329,
        530,
        329,
        220
    };
}

void HydroponicGreenhouse::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}
