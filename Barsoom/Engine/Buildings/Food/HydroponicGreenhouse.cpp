#include "HydroponicGreenhouse.hpp"

HydroponicGreenhouse::HydroponicGreenhouse(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        0,
        535,
        300,
        210
    };
        
    this->level = 0;
}

void HydroponicGreenhouse::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void HydroponicGreenhouse::setLevel(int level) {
    this->level = level;
    clip.x = 300 * level;
}
