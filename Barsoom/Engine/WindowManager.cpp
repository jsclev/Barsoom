#include "WindowManager.hpp"

WindowManager::WindowManager() {
    
}

SDL_Window* WindowManager::createWindow() {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        SDL_Log("Warning: Linear texture filtering not enabled!");
    }
    
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    
    Uint32 flags = SDL_WINDOW_SHOWN |
                   SDL_WINDOW_FULLSCREEN |
                   SDL_WINDOW_ALLOW_HIGHDPI;
    
    return SDL_CreateWindow(GAME_NAME,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            0,
                            0,
                            flags);
}

SDL_Rect WindowManager::getScreenRect() {
    SDL_DisplayMode displayMode;
    
    if (SDL_GetDesktopDisplayMode(0, &displayMode) == 0) {
        return {0, 0, displayMode.w, displayMode.h};
    }
    
    return {0, 0, 0, 0};
}

int WindowManager::getWindowMultiplier() {
    return 1;
}
