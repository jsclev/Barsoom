#include "FusionReactor.hpp"

FusionReactor::FusionReactor(SDL_Renderer *renderer, Texture *texture, int level) :
                             Building(renderer, texture, level) {
     clip = {
         0,
         0,
         300,
         250
     };
}

void FusionReactor::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}
