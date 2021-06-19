#include "FusionReactor.hpp"

FusionReactor::FusionReactor(SDL_Renderer *renderer, Texture *texture, int level) :
                             Building(renderer, texture, "Fusion Reactor", level) {
    spriteClip = {
         290 * level,
         1470,
         290,
         260
     };
}
