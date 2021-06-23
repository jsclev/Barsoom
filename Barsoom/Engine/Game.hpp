#ifndef GAME_H
#define GAME_H

#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "constants.hpp"
#include "Base.hpp"
#include "Views/BaseMap.hpp"
#include "Building.hpp"
#include "Button.hpp"
#include "ElectrolysisPlant.hpp"
#include "FusionReactor.hpp"
#include "Habitat.hpp"
#include "HydroponicGreenhouse.hpp"
#include "MetalExtractor.hpp"
#include "NuclearReactor.hpp"
#include "OxygenExtractor.hpp"
#include "Refinery.hpp"
#include "ScreenManager.hpp"
#include "SolarFarm.hpp"
#include "Texture.hpp"
#include "Tile.hpp"
#include "Timer.hpp"
#include "WaterRecycler.hpp"

using namespace std;

class Game {
public:
    Game();
    
    bool loadAssets();

    bool init();
    
    void initMap();
    
    int run();
    
    void quit();

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    Texture spritesTexture;
    TTF_Font *gFont = nullptr;
    SDL_Rect gTileClips[32];
    SDL_Rect gIconClips[1];
    Texture gFPSTextTexture;
};

#endif
