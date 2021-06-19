#include "OxygenExtractor.hpp"

OxygenExtractor::OxygenExtractor(SDL_Renderer *renderer, Texture *texture, int level) :
                                 Building(renderer, texture, "Oxygen Extractor", level) {
     spriteClip = {
         329 * level,
         0,
         329,
         250
     };
}
