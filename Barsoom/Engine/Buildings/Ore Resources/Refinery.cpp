#include "Refinery.hpp"

Refinery::Refinery(SDL_Renderer *renderer, Texture *texture, int level) :
                   Building(renderer, texture, "Refinery", level) {
    spriteClip = {
        1650 + 329 * level,
        700,
        319,
        300
    };
}
