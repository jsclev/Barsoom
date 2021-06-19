#include "WaterRecycler.hpp"

WaterRecycler::WaterRecycler(SDL_Renderer *renderer, Texture *texture, int level) :
                             Building(renderer, texture, "Water Recycler", level) {
     spriteClip = {
         320 * level,
         1750,
         325,
         260
     };
}
