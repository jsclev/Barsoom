#include "NuclearReactor.hpp"

NuclearReactor::NuclearReactor(SDL_Renderer *renderer, Texture *texture, int level) :
                               Building(renderer, texture, level) {
    clip = {
       0,
       725,
       300,
       300
    };
}

void NuclearReactor::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}
