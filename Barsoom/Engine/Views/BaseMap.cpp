#include <SDL.h>

#include "BaseMap.hpp"

BaseMap::BaseMap(SDL_Renderer *renderer, ScreenManager screenManager) {
    this->renderer = renderer;
    
    if (!texture.loadFromFile(renderer, "mars_terrain.png")) {
        SDL_Log("Failed to load map image!\n");
    }
    
    bgMap = new BgMap(texture.getWidth(), texture.getHeight(), screenManager);
}

BaseMap::~BaseMap() {
    free(bgMap);
}

bool BaseMap::isPanStopping() {
    return bgMap->isPanStopping();
}

void BaseMap::startPan(SDL_Point startPos) {
    bgMap->stopPan(startPos);
}

void BaseMap::pan(SDL_Point newPosition, SDL_Point prevPosition) {
    bgMap->pan(newPosition, prevPosition);
}

void BaseMap::stopPan(SDL_Point position) {
    bgMap->stopPan(position);
}

void BaseMap::render() {
    bgMap->updatePosition();
    
    // We want the base map to always fill the entire available
    // window, no matter what device we are on.  So we'll want the
    // destination clip to be at the upper left corner of the renderer's window,
    // point (0, 0)
    texture.render(renderer, 0, 0, bgMap->getClip());
}
