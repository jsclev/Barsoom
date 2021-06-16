#ifndef GAME_H
#define GAME_H

using namespace std;

#include <CoreFoundation/CFBundle.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "constants.hpp"
#include "Base.hpp"
#include "BaseMap.hpp"
#include "Building.hpp"
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
    
    void initMap();
    
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
