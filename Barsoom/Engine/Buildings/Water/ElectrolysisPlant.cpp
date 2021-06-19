#include "ElectrolysisPlant.hpp"

ElectrolysisPlant::ElectrolysisPlant(SDL_Renderer *renderer, Texture *texture, int level) :
                                     Building(renderer, texture, "Electrolysis Plant", level) {
     if (level == 0) {
         spriteClip.x = 45;
         spriteClip.y = 1224;
         spriteClip.w = 166;
         spriteClip.h = 188;
     }
     else if (level == 1) {
         spriteClip.x = 295;
         spriteClip.y = 1224;
         spriteClip.w = 247;
         spriteClip.h = 213;
     }
     else if (level == 2) {
         spriteClip.x = 604;
         spriteClip.y = 1232;
         spriteClip.w = 248;
         spriteClip.h = 212;
     }
     else if (level == 3) {
         spriteClip.x = 904;
         spriteClip.y = 1234;
         spriteClip.w = 255;
         spriteClip.h = 214;
     }
     else if (level == 4) {
         spriteClip.x = 1214;
         spriteClip.y = 1235;
         spriteClip.w = 256;
         spriteClip.h = 214;
     }
}
