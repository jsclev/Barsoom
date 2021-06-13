#include <SDL.h>

#include "BaseMap.hpp"
#include "ScreenManager.hpp"

BaseMap::BaseMap(SDL_Renderer *renderer) : renderer(renderer) {
    if (!mapTexture.loadFromFile(renderer, "mars_terrain.png")) {
        SDL_Log("Failed to load map image!\n");
    }
}

void BaseMap::setScreenRect(SDL_Rect screenRect) {
    int x = (MAP_IMAGE_WIDTH / 2) - (screenRect.w / 2);
    int y = (MAP_IMAGE_HEIGHT / 2) - (screenRect.h / 2);
    
    this->mapClip = {x, y, screenRect.w, screenRect.h};
}

void BaseMap::render() {
    mapTexture.render(renderer, 0, 0, &mapClip);
}
