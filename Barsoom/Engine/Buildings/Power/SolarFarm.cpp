#include "SolarFarm.hpp"

SolarFarm::SolarFarm(SDL_Renderer *renderer, Texture *texture, int level) :
                     Building(renderer, texture, level) {
     clip = {
         1670,
         0,
         345,
         250
     };
}

void SolarFarm::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 330, gridPositionY * 300, &clip);
}
