#include "Device.hpp"

Device::Device(SDL_Renderer *renderer) : renderer(renderer) {
    
}

SDL_Window* Device::createWindow() {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        SDL_Log("Warning: Linear texture filtering not enabled!");
    }
    
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
    
    Uint32 flags = SDL_WINDOW_SHOWN |
                   SDL_WINDOW_ALLOW_HIGHDPI;
    
    return SDL_CreateWindow(GAME_NAME,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            0,
                            0,
                            flags);
}

SDL_Rect Device::getScreenRect() {
    int w = 0;
    int h = 0;
    
    if (SDL_GetRendererOutputSize(renderer, &w, &h) == 0) {
        bool isPortrait = false;
        
        if (h > w) {
            isPortrait = true;
            SDL_Log("Portrait mode %d x %d", w, h);
            return {0, 0, h, w};

        }
        else {
            SDL_Log("Landscape mode %d x %d", w, h);
            return {0, 0, w, h};
        }
    }
    
    return {0, 0, w, h};
}

int Device::getWindowMultiplier() {
    return 1;
}
