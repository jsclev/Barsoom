#include <stdio.h>

#include "Building.hpp"

Building::Building(SDL_Renderer *renderer, Texture *texture, string name, int level) :
                   renderer(renderer), texture(texture), name(name), level(level) {
    
}

string Building::getName() {
    return name;
}

void Building::handleTouch(int touchX, int touchY) {
    if (touchX >= screenClip.x && touchX <= screenClip.x + screenClip.w &&
        touchY >= screenClip.y && touchY <= screenClip.y + screenClip.h) {
        SDL_Log("x %i, y %i", touchX, touchY);
        log();
    }
}

void Building::log() {
    SDL_Log("%s, level %i", getName().c_str(), level);
}

void Building::pan(SDL_Point point) {
    
}

void Building::render(int gridPositionX, int gridPositionY) {
    screenClip = {25 + gridPositionX * 300, 25 + gridPositionY * 300, spriteClip.w, spriteClip.h};
    texture->render(renderer, screenClip.x, screenClip.y, &spriteClip);
}
