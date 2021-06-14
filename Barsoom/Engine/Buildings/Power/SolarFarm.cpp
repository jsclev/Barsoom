#include "SolarFarm.hpp"

SolarFarm::SolarFarm(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        1670,
        0,
        345,
        250
    };
        
    this->level = 0;
}

void SolarFarm::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 330, gridPositionY * 300, &clip);
}

void SolarFarm::setLevel(int level) {
    this->level = level;
}
