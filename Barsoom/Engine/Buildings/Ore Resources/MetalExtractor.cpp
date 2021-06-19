#include "MetalExtractor.hpp"

MetalExtractor::MetalExtractor(SDL_Renderer *renderer, Texture *texture, int level) :
                               Building(renderer, texture, "Metal Extractor", level) {
    spriteClip = {
        1650 + 329 * level,
        250,
        319,
        360
    };
}
