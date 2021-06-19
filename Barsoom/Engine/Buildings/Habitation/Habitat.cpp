#include "Habitat.hpp"

Habitat::Habitat(SDL_Renderer *renderer, Texture *texture, int level) :
                 Building(renderer, texture, "Habitat", level) {
    spriteClip = {
        329 * level,
        250,
        319,
        300
    };
}
