#include "ScreenManager.hpp"

ScreenManager::ScreenManager(SDL_Renderer *renderer) : renderer(renderer) {
    
}

SDL_Window* ScreenManager::createWindow() {
//    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    
    Uint32 flags = SDL_WINDOW_SHOWN |
                   SDL_WINDOW_FULLSCREEN |
                   SDL_WINDOW_ALLOW_HIGHDPI;
    
    // TODO Need to implement an error handler here
    return SDL_CreateWindow(GAME_NAME,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            0,
                            0,
                            flags);
}

SDL_Rect ScreenManager::getScreenRect() {
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
    return {0, 0, w, h};
}

int ScreenManager::getWindowMultiplier() {
    return 1;
}
