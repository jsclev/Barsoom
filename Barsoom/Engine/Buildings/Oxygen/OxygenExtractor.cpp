#include "OxygenExtractor.hpp"

OxygenExtractor::OxygenExtractor(
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

void OxygenExtractor::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void OxygenExtractor::setLevel(int level) {
    this->level = level;
    clip.x = level * 300;
}
