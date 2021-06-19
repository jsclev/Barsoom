#include "NuclearReactor.hpp"

NuclearReactor::NuclearReactor(SDL_Renderer *renderer, Texture *texture, int level) :
                               Building(renderer, texture, "Nuclear Reactor", level) {
    spriteClip = {
       level * 320,
       745,
       300,
       250
    };
}
