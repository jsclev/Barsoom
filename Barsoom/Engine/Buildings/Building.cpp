#include <stdio.h>

#include "Building.hpp"

Building::Building(SDL_Renderer *renderer, Texture *texture, string name, int level) :
                   renderer(renderer), texture(texture), name(name), level(level) {
    
}

string Building::getName() {
    return name;
}

void Building::startPan(SDL_Point startPos) {
    startPanPos = startPos;
    startClipPos = {spriteClip.x, spriteClip.y};
}

//void Building::handleTouch(int touchX, int touchY) {
//    if (touchX >= screenClip.x && touchX <= screenClip.x + screenClip.w &&
//        touchY >= screenClip.y && touchY <= screenClip.y + screenClip.h) {
//        SDL_Log("x %i, y %i", touchX, touchY);
//        log();
//    }
//}

void Building::log() {
    SDL_Log("%s, level %i", getName().c_str(), level);
}

void Building::pan(SDL_Point position) {
    if (startClipPos.x - (position.x - startPanPos.x) < 0) {
        screenClip.x = 0;
    }
    else if (startClipPos.x - (position.x - startPanPos.x) > texture->getWidth() - screenClip.w) {
        screenClip.x = texture->getWidth() - screenClip.w;
    }
    else {
        screenClip.x = startClipPos.x - (position.x - startPanPos.x);
    }
    
    if (startClipPos.y - (position.y - startPanPos.y) < 0) {
        screenClip.y = 0;
    }
    else if (startClipPos.y - (position.y - startPanPos.y) > texture->getHeight() - screenClip.h) {
        screenClip.y = texture->getHeight() - screenClip.h;
    }
    else {
        screenClip.y = startClipPos.y - (position.y - startPanPos.y);
    }
    
//    SDL_Log("New clip is at (%i, %i) and is (%i, %i)", screenClip.x, screenClip.y, screenClip.w, screenClip.h);
}

void Building::render(int gridPositionX, int gridPositionY) {
    screenClip = {screenClip.x + 25 + gridPositionX * 300, screenClip.y + 25 + gridPositionY * 300, spriteClip.w, spriteClip.h};
    texture->render(renderer, screenClip.x, screenClip.y, &spriteClip);
}
