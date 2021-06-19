#include "SolarFarm.hpp"

SolarFarm::SolarFarm(SDL_Renderer *renderer, Texture *texture, int level) :
                     Building(renderer, texture, "Solar Farm", level) {
     spriteClip = {
         1670,
         0,
         345,
         250
     };
}
