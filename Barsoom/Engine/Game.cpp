#include <CoreFoundation/CFBundle.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstdio>
#include <string>
#include <sstream>

#include "Texture.hpp"
#include "Timer.hpp"
#include "Tile.hpp"
#include "constants.hpp"
#include "Button.hpp"
#include "Game.hpp"

Game::Game() {
    
}

bool Game::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! %s\n", SDL_GetError());
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            SDL_Log("Warning: Linear texture filtering not enabled!");
        }
        
        SDL_DisplayMode displayMode;

        if (SDL_GetDesktopDisplayMode(0, &displayMode) == 0) {
            this->gScreenRect.w = displayMode.w;
            this->gScreenRect.h = displayMode.h;
        }
        
        SDL_Log("Device resolution: %d x %d\n", gScreenRect.w, gScreenRect.h);

//        Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
        gWindow = SDL_CreateWindow("SDL Tutorial",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   0,
                                   0,
                                   SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
        if (gWindow == NULL) {
            SDL_Log( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        
        if (gWindow == nullptr) {
            SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
//            SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == nullptr) {
                SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    SDL_Log("SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }

                if (TTF_Init() == -1) {
                    SDL_Log("SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool Game::loadAssets() {
    bool success = true;

//    gFont = TTF_OpenFont("Georgia.ttf", 64);
//    if (gFont == nullptr) {
//        SDL_Log("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//        success = false;
//    }
    
    if (!gSpritesTexture.loadFromFile(
            gRenderer,
            "bg2.png")) {
        SDL_Log("Failed to load sprite sheet texture!\n");

        success = false;
    }

    // Grass tiles
    gTileClips[GRASS1_TILE].x = TILE_WIDTH * 0;
    gTileClips[GRASS1_TILE].y = 0;
    gTileClips[GRASS1_TILE].w = TILE_WIDTH;
    gTileClips[GRASS1_TILE].h = TILE_HEIGHT;

    gTileClips[GRASS2_TILE].x = TILE_WIDTH * 1;
    gTileClips[GRASS2_TILE].y = 0;
    gTileClips[GRASS2_TILE].w = TILE_WIDTH;
    gTileClips[GRASS2_TILE].h = TILE_HEIGHT;

    gTileClips[GRASS3_TILE].x = TILE_WIDTH * 2;
    gTileClips[GRASS3_TILE].y = 0;
    gTileClips[GRASS3_TILE].w = TILE_WIDTH;
    gTileClips[GRASS3_TILE].h = TILE_HEIGHT;

    gTileClips[GRASS4_TILE].x = TILE_WIDTH * 3;
    gTileClips[GRASS4_TILE].y = 0;
    gTileClips[GRASS4_TILE].w = TILE_WIDTH;
    gTileClips[GRASS4_TILE].h = TILE_HEIGHT;

    // Water tiles
    gTileClips[WATER1_TILE].x = TILE_WIDTH * 4;
    gTileClips[WATER1_TILE].y = 0;
    gTileClips[WATER1_TILE].w = TILE_WIDTH;
    gTileClips[WATER1_TILE].h = TILE_HEIGHT;

    gTileClips[WATER2_TILE].x = TILE_WIDTH * 5;
    gTileClips[WATER2_TILE].y = 0;
    gTileClips[WATER2_TILE].w = TILE_WIDTH;
    gTileClips[WATER2_TILE].h = TILE_HEIGHT;

    gTileClips[WATER3_TILE].x = TILE_WIDTH * 6;
    gTileClips[WATER3_TILE].y = 0;
    gTileClips[WATER3_TILE].w = TILE_WIDTH;
    gTileClips[WATER3_TILE].h = TILE_HEIGHT;

    gTileClips[WATER4_TILE].x = TILE_WIDTH * 7;
    gTileClips[WATER4_TILE].y = 0;
    gTileClips[WATER4_TILE].w = TILE_WIDTH;
    gTileClips[WATER4_TILE].h = TILE_HEIGHT;

    // Mountain tiles
    gTileClips[MOUNTAIN1_TILE].x = TILE_WIDTH * 0;
    gTileClips[MOUNTAIN1_TILE].y = TILE_HEIGHT;
    gTileClips[MOUNTAIN1_TILE].w = TILE_WIDTH;
    gTileClips[MOUNTAIN1_TILE].h = TILE_HEIGHT;

    gTileClips[MOUNTAIN2_TILE].x = TILE_WIDTH * 1;
    gTileClips[MOUNTAIN2_TILE].y = TILE_HEIGHT;
    gTileClips[MOUNTAIN2_TILE].w = TILE_WIDTH;
    gTileClips[MOUNTAIN2_TILE].h = TILE_HEIGHT;

    gTileClips[MOUNTAIN3_TILE].x = TILE_WIDTH * 2;
    gTileClips[MOUNTAIN3_TILE].y = TILE_HEIGHT;
    gTileClips[MOUNTAIN3_TILE].w = TILE_WIDTH;
    gTileClips[MOUNTAIN3_TILE].h = TILE_HEIGHT;

    gTileClips[MOUNTAIN4_TILE].x = TILE_WIDTH * 3;
    gTileClips[MOUNTAIN4_TILE].y = TILE_HEIGHT;
    gTileClips[MOUNTAIN4_TILE].w = TILE_WIDTH;
    gTileClips[MOUNTAIN4_TILE].h = TILE_HEIGHT;

    gTileClips[DESERT1_TILE].x = TILE_WIDTH * 4;
    gTileClips[DESERT1_TILE].y = TILE_HEIGHT;
    gTileClips[DESERT1_TILE].w = TILE_WIDTH;
    gTileClips[DESERT1_TILE].h = TILE_HEIGHT;

    gTileClips[DESERT2_TILE].x = TILE_WIDTH * 5;
    gTileClips[DESERT2_TILE].y = TILE_HEIGHT;
    gTileClips[DESERT2_TILE].w = TILE_WIDTH;
    gTileClips[DESERT2_TILE].h = TILE_HEIGHT;

    gTileClips[DESERT3_TILE].x = TILE_WIDTH * 6;
    gTileClips[DESERT3_TILE].y = TILE_HEIGHT;
    gTileClips[DESERT3_TILE].w = TILE_WIDTH;
    gTileClips[DESERT3_TILE].h = TILE_HEIGHT;

    gTileClips[DESERT4_TILE].x = TILE_WIDTH * 7;
    gTileClips[DESERT4_TILE].y = TILE_HEIGHT;
    gTileClips[DESERT4_TILE].w = TILE_WIDTH;
    gTileClips[DESERT4_TILE].h = TILE_HEIGHT;

    gTileClips[FOREST1_TILE].x = TILE_WIDTH * 0;
    gTileClips[FOREST1_TILE].y = TILE_HEIGHT * 2;
    gTileClips[FOREST1_TILE].w = TILE_WIDTH;
    gTileClips[FOREST1_TILE].h = TILE_HEIGHT;

    gTileClips[FOREST2_TILE].x = TILE_WIDTH * 1;
    gTileClips[FOREST2_TILE].y = TILE_HEIGHT * 2;
    gTileClips[FOREST2_TILE].w = TILE_WIDTH;
    gTileClips[FOREST2_TILE].h = TILE_HEIGHT;

    gTileClips[FOREST3_TILE].x = TILE_WIDTH * 2;
    gTileClips[FOREST3_TILE].y = TILE_HEIGHT * 2;
    gTileClips[FOREST3_TILE].w = TILE_WIDTH;
    gTileClips[FOREST3_TILE].h = TILE_HEIGHT;

    gTileClips[FOREST4_TILE].x = TILE_WIDTH * 3;
    gTileClips[FOREST4_TILE].y = TILE_HEIGHT * 2;
    gTileClips[FOREST4_TILE].w = TILE_WIDTH;
    gTileClips[FOREST4_TILE].h = TILE_HEIGHT;

    gTileClips[DIRT1_TILE].x = TILE_WIDTH * 0;
    gTileClips[DIRT1_TILE].y = TILE_HEIGHT * 3;
    gTileClips[DIRT1_TILE].w = TILE_WIDTH;
    gTileClips[DIRT1_TILE].h = TILE_HEIGHT;

    gTileClips[DIRT2_TILE].x = TILE_WIDTH * 1;
    gTileClips[DIRT2_TILE].y = TILE_HEIGHT * 3;
    gTileClips[DIRT2_TILE].w = TILE_WIDTH;
    gTileClips[DIRT2_TILE].h = TILE_HEIGHT;

    gTileClips[DIRT3_TILE].x = TILE_WIDTH * 2;
    gTileClips[DIRT3_TILE].y = TILE_HEIGHT * 3;
    gTileClips[DIRT3_TILE].w = TILE_WIDTH;
    gTileClips[DIRT3_TILE].h = TILE_HEIGHT;

    gTileClips[DIRT4_TILE].x = TILE_WIDTH * 3;
    gTileClips[DIRT4_TILE].y = TILE_HEIGHT * 3;
    gTileClips[DIRT4_TILE].w = TILE_WIDTH;
    gTileClips[DIRT4_TILE].h = TILE_HEIGHT;

    gTileClips[MARSH1_TILE].x = TILE_WIDTH * 4;
    gTileClips[MARSH1_TILE].y = TILE_HEIGHT * 2;
    gTileClips[MARSH1_TILE].w = TILE_WIDTH;
    gTileClips[MARSH1_TILE].h = TILE_HEIGHT;

    gTileClips[MARSH2_TILE].x = TILE_WIDTH * 5;
    gTileClips[MARSH2_TILE].y = TILE_HEIGHT * 2;
    gTileClips[MARSH2_TILE].w = TILE_WIDTH;
    gTileClips[MARSH2_TILE].h = TILE_HEIGHT;

    gTileClips[MARSH3_TILE].x = TILE_WIDTH * 6;
    gTileClips[MARSH3_TILE].y = TILE_HEIGHT * 2;
    gTileClips[MARSH3_TILE].w = TILE_WIDTH;
    gTileClips[MARSH3_TILE].h = TILE_HEIGHT;

    gTileClips[MARSH4_TILE].x = TILE_WIDTH * 7;
    gTileClips[MARSH4_TILE].y = TILE_HEIGHT * 2;
    gTileClips[MARSH4_TILE].w = TILE_WIDTH;
    gTileClips[MARSH4_TILE].h = TILE_HEIGHT;

    gTileClips[HILLS1_TILE].x = TILE_WIDTH * 0;
    gTileClips[HILLS1_TILE].y = TILE_HEIGHT * 4;
    gTileClips[HILLS1_TILE].w = TILE_WIDTH;
    gTileClips[HILLS1_TILE].h = TILE_HEIGHT;

    gTileClips[HILLS2_TILE].x = TILE_WIDTH * 1;
    gTileClips[HILLS2_TILE].y = TILE_HEIGHT * 4;
    gTileClips[HILLS2_TILE].w = TILE_WIDTH;
    gTileClips[HILLS2_TILE].h = TILE_HEIGHT;

    gTileClips[HILLS3_TILE].x = TILE_WIDTH * 2;
    gTileClips[HILLS3_TILE].y = TILE_HEIGHT * 4;
    gTileClips[HILLS3_TILE].w = TILE_WIDTH;
    gTileClips[HILLS3_TILE].h = TILE_HEIGHT;

    gTileClips[HILLS4_TILE].x = TILE_WIDTH * 3;
    gTileClips[HILLS4_TILE].y = TILE_HEIGHT * 4;
    gTileClips[HILLS4_TILE].w = TILE_WIDTH;
    gTileClips[HILLS4_TILE].h = TILE_HEIGHT;

    gIconClips[FOOD_ICON].x = 7 + TILE_WIDTH * 8 + ICON_WIDTH * 0;
    gIconClips[FOOD_ICON].y = ICON_HEIGHT * 0;
    gIconClips[FOOD_ICON].w = ICON_WIDTH;
    gIconClips[FOOD_ICON].h = ICON_HEIGHT;

    gButtonClips[MAIN_BUTTON].x = TILE_WIDTH * 8;
    gButtonClips[MAIN_BUTTON].y = TILE_HEIGHT / 3;
    gButtonClips[MAIN_BUTTON].w = BUTTON_WIDTH;
    gButtonClips[MAIN_BUTTON].h = BUTTON_HEIGHT;

    return success;
}

void Game::run() {
    if (!init()) {
        SDL_Log("Failed to initialize!\n");
    } else {
        if (!loadAssets()) {
            SDL_Log("Failed to load media!\n");
        } else {
            bool quit = false;
            std::vector<TileLayer> v;
            std::vector<Tile> tiles;

            Button button = Button(gRenderer,
                                   &gSpritesTexture,
                                   50,
                                   50,
                                   gButtonClips[MAIN_BUTTON]);

            srand((unsigned) time(0));


//            Tile* icons = (Tile*)malloc(sizeof(Tile) * NUM_ICONS);
//            icons[0] = Tile(gRenderer,
//                            &gSpritesTexture,
//                            500,
//                            500,
//                            gIconClips[FOOD_ICON]);

            SDL_Event e;
//            SDL_Color textColor = {71, 26, 13, 255};
            SDL_Point touchLocation = { gScreenRect.w / 2, gScreenRect.h / 2 };

            Timer fpsTimer;
            Timer capTimer;
            std::stringstream timeText;
            int countedFrames = 0;
            fpsTimer.start();

            while (!quit) {
                capTimer.start();

                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (e.type == SDL_FINGERDOWN) {
                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                    }
                    else if (e.type == SDL_FINGERMOTION) {
                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                    }
                    else if (e.type == SDL_FINGERUP) {
                        touchLocation.x = e.tfinger.x * gScreenRect.w;
                        touchLocation.y = e.tfinger.y * gScreenRect.h;
                        
                        button.handleEvent(&e, &tiles, gTileClips);
                    }
                }

                float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
                if (avgFPS > 2000000) {
                    avgFPS = 0;
                }

                timeText.str("Regenerate Map");

                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderClear(gRenderer);

                for (auto tile: tiles) {
                    tile.render();
                }

//                for (int i = 0; i < NUM_ICONS; i++) {
//                    icons[i].render();
//                }

                button.render();
                gFPSTextTexture.render(gRenderer, 118, 86);
                SDL_RenderPresent(gRenderer);
                ++countedFrames;

                int frameTicks = capTimer.getTicks();
                if (frameTicks < SCREEN_TICK_PER_FRAME) {
                    SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
                }
            }
        }
    }

    quit();
}

void Game::quit() {
    gFPSTextTexture.free();

    TTF_CloseFont(gFont);
    gFont = nullptr;

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
