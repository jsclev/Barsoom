#include "ElectrolysisPlant.hpp"

ElectrolysisPlant::ElectrolysisPlant(
    SDL_Renderer *renderer,
    Texture *texture) :
    renderer(renderer),
    texture(texture) {
    clip = {
        0,
        1214,
        214,
        256
    };
        
    this->level = 0;
}

void ElectrolysisPlant::render(int gridPositionX, int gridPositionY) {
    texture->render(renderer, gridPositionX * 300, gridPositionY * 300, &clip);
}

void ElectrolysisPlant::setLevel(int level) {
    this->level = level;
    
    if (level == 0) {
        clip.x = 45;
        clip.y = 1224;
        clip.w = 166;
        clip.h = 188;
    }
    else if (level == 1) {
        clip.x = 295;
        clip.y = 1224;
        clip.w = 247;
        clip.h = 213;
    }
    else if (level == 2) {
        clip.x = 604;
        clip.y = 1232;
        clip.w = 248;
        clip.h = 212;
    }
    else if (level == 3) {
        clip.x = 904;
        clip.y = 1234;
        clip.w = 255;
        clip.h = 214;
    }
    else if (level == 4) {
        clip.x = 1214;
        clip.y = 1235;
        clip.w = 256;
        clip.h = 214;
    }
}
