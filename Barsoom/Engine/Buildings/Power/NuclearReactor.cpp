#include "NuclearReactor.hpp"

NuclearReactor::NuclearReactor(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        0,
        725,
        300,
        300
    };
        
    this->level = 0;
}

void NuclearReactor::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void NuclearReactor::setLevel(int level) {
    this->level = level;
    clip.x = level * 300;
}
