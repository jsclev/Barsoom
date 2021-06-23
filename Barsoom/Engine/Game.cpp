#include "Game.hpp"

Game::Game() {
    
}

bool Game::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! %s\n", SDL_GetError());
        success = false;
    } else {
        // SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");
        Uint32 flags = SDL_WINDOW_SHOWN |
                       SDL_WINDOW_FULLSCREEN |
                       SDL_WINDOW_ALLOW_HIGHDPI;
        
        // TODO Need to implement an error handler here
        window = SDL_CreateWindow(GAME_NAME,
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                0,
                                0,
                                flags);
        
        if (window == NULL) {
            SDL_Log( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        
        if (window == nullptr) {
            SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
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
    
    if (!spritesTexture.loadFromFile(renderer, "buildings_spritesheet.png")) {
        SDL_Log("Failed to load sprite sheet texture!\n");
        success = false;
    }

    return success;
}

int Game::run() {
    if (!init()) {
        SDL_Log("Failed to initialize!\n");
        return 1;
    } else {
        if (!loadAssets()) {
            SDL_Log("Failed to load media!\n");
            return 1;
        } else {
            bool quit = false;
            std::vector<TileLayer> v;
            std::vector<Tile> tiles;
            ScreenManager screenMgr(renderer);
            BaseMap baseMap(renderer, screenMgr);
            
            ElectrolysisPlant electrolysisPlant0(renderer, &spritesTexture, 0);
            ElectrolysisPlant electrolysisPlant1(renderer, &spritesTexture, 1);
            ElectrolysisPlant electrolysisPlant2(renderer, &spritesTexture, 2);
            ElectrolysisPlant electrolysisPlant3(renderer, &spritesTexture, 3);
            ElectrolysisPlant electrolysisPlant4(renderer, &spritesTexture, 4);
            
            FusionReactor fusionReactor0(renderer, &spritesTexture, 0);
            FusionReactor fusionReactor1(renderer, &spritesTexture, 1);
            FusionReactor fusionReactor2(renderer, &spritesTexture, 2);
            FusionReactor fusionReactor3(renderer, &spritesTexture, 3);
            FusionReactor fusionReactor4(renderer, &spritesTexture, 4);

            Habitat habitat0(renderer, &spritesTexture, 0);
            Habitat habitat1(renderer, &spritesTexture, 1);
            Habitat habitat2(renderer, &spritesTexture, 2);
            Habitat habitat3(renderer, &spritesTexture, 3);
            Habitat habitat4(renderer, &spritesTexture, 4);

            HydroponicGreenhouse hydroponicGreenhouse0(renderer, &spritesTexture, 0);
            HydroponicGreenhouse hydroponicGreenhouse1(renderer, &spritesTexture, 1);
            HydroponicGreenhouse hydroponicGreenhouse2(renderer, &spritesTexture, 2);
            HydroponicGreenhouse hydroponicGreenhouse3(renderer, &spritesTexture, 3);
            HydroponicGreenhouse hydroponicGreenhouse4(renderer, &spritesTexture, 4);

            MetalExtractor metalExtractor0(renderer, &spritesTexture, 0);
            MetalExtractor metalExtractor1(renderer, &spritesTexture, 1);
            MetalExtractor metalExtractor2(renderer, &spritesTexture, 2);
            MetalExtractor metalExtractor3(renderer, &spritesTexture, 3);
            MetalExtractor metalExtractor4(renderer, &spritesTexture, 4);
            
            NuclearReactor nuclearReactor0(renderer, &spritesTexture, 0);
            NuclearReactor nuclearReactor1(renderer, &spritesTexture, 1);
            NuclearReactor nuclearReactor2(renderer, &spritesTexture, 2);
            NuclearReactor nuclearReactor3(renderer, &spritesTexture, 3);
            NuclearReactor nuclearReactor4(renderer, &spritesTexture, 4);

            OxygenExtractor oxygenExtractor0(renderer, &spritesTexture, 0);
            OxygenExtractor oxygenExtractor1(renderer, &spritesTexture, 1);
            OxygenExtractor oxygenExtractor2(renderer, &spritesTexture, 2);
            OxygenExtractor oxygenExtractor3(renderer, &spritesTexture, 3);
            OxygenExtractor oxygenExtractor4(renderer, &spritesTexture, 4);

            Refinery refinery0(renderer, &spritesTexture, 0);
            Refinery refinery1(renderer, &spritesTexture, 1);
            Refinery refinery2(renderer, &spritesTexture, 2);
            Refinery refinery3(renderer, &spritesTexture, 3);
            Refinery refinery4(renderer, &spritesTexture, 4);
            
            SolarFarm solarFarm0(renderer, &spritesTexture, 0);
            SolarFarm solarFarm1(renderer, &spritesTexture, 1);
            SolarFarm solarFarm2(renderer, &spritesTexture, 2);
            SolarFarm solarFarm3(renderer, &spritesTexture, 3);
            SolarFarm solarFarm4(renderer, &spritesTexture, 4);
            
            WaterRecycler waterRecycler0(renderer, &spritesTexture, 0);
            WaterRecycler waterRecycler1(renderer, &spritesTexture, 1);
            WaterRecycler waterRecycler2(renderer, &spritesTexture, 2);
            WaterRecycler waterRecycler3(renderer, &spritesTexture, 3);
            WaterRecycler waterRecycler4(renderer, &spritesTexture, 4);
            
            Building* buildings[50] = {
                &electrolysisPlant0,
                &electrolysisPlant1,
                &electrolysisPlant2,
                &electrolysisPlant3,
                &electrolysisPlant4,
                &fusionReactor0,
                &fusionReactor1,
                &fusionReactor2,
                &fusionReactor3,
                &fusionReactor4,
                &habitat0,
                &habitat1,
                &habitat2,
                &habitat3,
                &habitat4,
                &hydroponicGreenhouse0,
                &hydroponicGreenhouse1,
                &hydroponicGreenhouse2,
                &hydroponicGreenhouse3,
                &hydroponicGreenhouse4,
                &metalExtractor0,
                &metalExtractor1,
                &metalExtractor2,
                &metalExtractor3,
                &metalExtractor4,
                &nuclearReactor0,
                &nuclearReactor1,
                &nuclearReactor2,
                &nuclearReactor3,
                &nuclearReactor4,
                &oxygenExtractor0,
                &oxygenExtractor1,
                &oxygenExtractor2,
                &oxygenExtractor3,
                &oxygenExtractor4,
                &refinery0,
                &refinery1,
                &refinery2,
                &refinery3,
                &refinery4,
                &solarFarm0,
                &solarFarm1,
                &solarFarm2,
                &solarFarm3,
                &solarFarm4,
                &waterRecycler0,
                &waterRecycler1,
                &waterRecycler2,
                &waterRecycler3,
                &waterRecycler4
            };

            srand((unsigned) time(0));

            SDL_Event e;
            SDL_Point prevTouchPos = {-1, -1};
            SDL_Point touchPos = {-1, -1};
            SDL_Rect screenRect = screenMgr.getScreenRect();

            Timer fpsTimer;
            Timer capTimer;
            std::stringstream timeText;
            int countedFrames = 0;
            fpsTimer.start();
            
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            
            while (!quit) {
                capTimer.start();
                
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (e.type == SDL_FINGERDOWN) {
                        touchPos.x = e.tfinger.x * screenRect.w;
                        touchPos.y = e.tfinger.y * screenRect.h;
                        
                        baseMap.startPan(touchPos);
                        
                        for (int i = 0; i < 50; i++) {
                            buildings[i]->startPan(touchPos);
                        }
                    }
                    else if (e.type == SDL_FINGERMOTION) {
                        touchPos.x = e.tfinger.x * screenRect.w;
                        touchPos.y = e.tfinger.y * screenRect.h;
//                        SDL_Log("Touch location is %i, %i", touchPos.x, touchPos.y);

                        baseMap.pan(touchPos, prevTouchPos);
                        
                        for (int i = 0; i < 50; i++) {
                            buildings[i]->pan(touchPos);
                        }
                        
                        prevTouchPos.x = touchPos.x;
                        prevTouchPos.y = touchPos.y;
                    }
                    else if (e.type == SDL_FINGERUP) {
                        touchPos.x = e.tfinger.x * screenRect.w;
                        touchPos.y = e.tfinger.y * screenRect.h;
                        
                        baseMap.stopPan(touchPos);
//                            for (int i = 0; i < 50; i++) {
//                                buildings[i]->handleTouch(touchPos.x, touchPos.y);
//                            }
                    }
                    else if (e.type == SDL_WINDOWEVENT) {
                        if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
//                            screenMgr.reset();
//                            screenRect = screenMgr.getScreenRect();
//                            baseMap.setClip({offsetX, offsetY, screenRect.w, screenRect.h});
//                            SDL_Log("Reset the screen.");
                        }
                    }
                }

                float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
                if (avgFPS > 2000000) {
                    avgFPS = 0;
                }

                SDL_RenderClear(renderer);
                
                baseMap.render();
                
//                for (int i = 0; i < 50; i++) {
//                    int row = i % 9;
//                    int col = i / 9;
//
//                    buildings[i]->render(row, col);
//                }

                SDL_RenderPresent(renderer);
                
                ++countedFrames;

                int frameTicks = capTimer.getTicks();
                if (frameTicks < SCREEN_TICK_PER_FRAME) {
                    SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
                }
            }
        }
    }

    quit();
    
    return 0;
}

void Game::quit() {
    gFPSTextTexture.free();

    TTF_CloseFont(gFont);
    gFont = nullptr;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
