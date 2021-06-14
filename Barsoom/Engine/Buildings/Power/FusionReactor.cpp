#include "FusionReactor.hpp"

FusionReactor::FusionReactor(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        0,
        0,
        300,
        250
    };
        
    this->level = 0;
}

void FusionReactor::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void FusionReactor::setLevel(int level) {
    this->level = level;
    clip.x = level * 300;
}
