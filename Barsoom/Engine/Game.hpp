#ifndef GAME_H
#define GAME_H

#include <CoreFoundation/CFBundle.h>
#include <cstdio>
#include <string>
#include <sstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "constants.hpp"
#include "BaseMap.hpp"
#include "Button.hpp"
#include "ElectrolysisPlant.hpp"
#include "FusionReactor.hpp"
#include "Habitat.hpp"
#include "HydroponicGreenhouse.hpp"
#include "NuclearReactor.hpp"
#include "OxygenExtractor.hpp"
#include "Texture.hpp"
#include "Tile.hpp"
#include "Timer.hpp"
#include "ScreenManager.hpp"
#include "SolarFarm.hpp"

class Game {
public:
    Game();
    
    bool loadAssets();

    bool init();
    
    void run();
    
    void quit();

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    TTF_Font *gFont = nullptr;
    SDL_Rect gTileClips[32];
    SDL_Rect gIconClips[1];
    SDL_Rect gButtonClips[1];
    SDL_Rect gScreenRect = {0, 0, 0, 0};
    Texture spritesTexture;
    Texture gFPSTextTexture;
};

#endif
