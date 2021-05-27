#ifndef BARSOOM_GAME_H
#define BARSOOM_GAME_H

#include <SDL.h>
#include "Device.hpp"
#include "Tile.hpp"

class Game {
public:
    Game();
    
    bool loadAssets();

    bool init();
    
    void run();
    
    void quit();

private:
    SDL_Window *gWindow = nullptr;
    SDL_Renderer *gRenderer = nullptr;
    TTF_Font *gFont = nullptr;
    SDL_Rect gTileClips[32];
    SDL_Rect gIconClips[1];
    SDL_Rect gButtonClips[1];
    SDL_Rect gScreenRect = {0, 0, 0, 0};
    Texture gSpritesTexture;
    Texture gFPSTextTexture;
};

#endif
