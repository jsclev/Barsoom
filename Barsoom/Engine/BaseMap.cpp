#include <SDL.h>

#include "BaseMap.hpp"
#include "ScreenManager.hpp"

BaseMap::BaseMap(SDL_Renderer *renderer, ScreenManager screenManager) : renderer(renderer) {
    if (!texture.loadFromFile(renderer, "mars_terrain.png")) {
        SDL_Log("Failed to load map image!\n");
    }
    
    // We'll initialize the visible clip of the map to be the size
    // of the window we are on (we run the game at full screen), and
    // at the center of the map image.  We choose the center clip of
    // the map image so that the user can pan around without hitting
    // the blank edges of the image when the game first loads.
    SDL_Rect screenRect = screenManager.getScreenRect();
    
    clip = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    clip->x = (texture.getWidth() / 2) - (screenRect.w / 2);
    clip->y = (texture.getHeight() / 2) - (screenRect.h / 2);
    clip->w = screenRect.w;
    clip->h = screenRect.h;
}

BaseMap::~BaseMap() {
    free(clip);
}

void BaseMap::startPan(SDL_Point startPos) {
    startPanPos = startPos;
    startClipPos = {clip->x, clip->y};
    
    SDL_Log("Start clip position is %i, %i", startClipPos.x, startClipPos.y);
}

void BaseMap::pan(SDL_Point position) {
    if (startClipPos.x - (position.x - startPanPos.x) < 0) {
        clip->x = 0;
    }
    else if (startClipPos.x - (position.x - startPanPos.x) > texture.getWidth() - clip->w) {
        clip->x = texture.getWidth() - clip->w;
    }
    else {
        clip->x = startClipPos.x - (position.x - startPanPos.x);
    }
    
    if (startClipPos.y - (position.y - startPanPos.y) < 0) {
        clip->y = 0;
    }
    else if (startClipPos.y - (position.y - startPanPos.y) > texture.getHeight() - clip->h) {
        clip->y = texture.getHeight() - clip->h;
    }
    else {
        clip->y = startClipPos.y - (position.y - startPanPos.y);
    }
    
    SDL_Log("New clip is at (%i, %i) and is (%i, %i)", clip->x, clip->y, clip->w, clip->h);
}

void BaseMap::render() {
    // We want the base map to always fill the entire available
    // window, no matter what device we are on.  So we'll want the
    // destination clip to be at the upper left corner of the renderer's window,
    // point (0, 0)
    texture.render(renderer, 0, 0, clip);
}
