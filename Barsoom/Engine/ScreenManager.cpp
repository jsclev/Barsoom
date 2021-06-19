#include "ScreenManager.hpp"

ScreenManager::ScreenManager(SDL_Renderer *renderer) : renderer(renderer) {
    reset();
}

SDL_Rect ScreenManager::getScreenRect() {
    return screenRect;
}

void ScreenManager::reset() {
    int w = 0;
    int h = 0;
    
    if (SDL_GetRendererOutputSize(renderer, &w, &h) == 0) {
        if (h > w) {
            SDL_Log("Portrait mode: %d px by %d px", w, h);

        }
        else {
            SDL_Log("Landscape mode: %d px by %d px", w, h);
        }
    }
    
    // TODO Need to implement an error handler here
    screenRect = {0, 0, w, h};
}

int ScreenManager::getWindowMultiplier() {
    return 1;
}
