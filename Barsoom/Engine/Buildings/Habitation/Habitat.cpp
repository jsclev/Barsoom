#include "Habitat.hpp"

Habitat::Habitat(SDL_Renderer *renderer, Texture *texture, int level) :
                 Building(renderer, texture, level) {
    clip = {
        0,
        250,
        300,
        300
    };
}

void Habitat::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}
