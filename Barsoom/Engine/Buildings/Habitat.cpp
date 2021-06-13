#include "Habitat.hpp"

Habitat::Habitat(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        0,
        250,
        300,
        300
    };
        
    this->level = 0;
}

void Habitat::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void Habitat::setLevel(int level) {
    this->level = level;
    clip.x = level * 300;
}
