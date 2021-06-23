#ifndef BG_MAP_H
#define BG_MAP_H

#include <math.h>
#include <SDL2/SDL.h>

#include "constants.hpp"
#include "ScreenManager.hpp"

class BgMap
{
public:
    BgMap(int mapWidth, int mapHeight, int screenWidth, int screenHeight);
    
    ~BgMap();
    
    bool isPanStopping();
    
    SDL_Rect* getClip();

    void startPan(SDL_Point position);
    
    void pan(SDL_Point position, SDL_Point prevPosition);
    
    void stopPan(SDL_Point position);
    
    void updatePosition();

private:
    int mapWidth = 0;
    int mapHeight = 0;
    SDL_Rect *clip = nullptr;
    SDL_Point startPanPos = {-1, -1};
    SDL_Point lastPanPos = {-1, -1};
    float panAngle = 0.0f;
    float panVelocity = 0.0f;
    bool panStopping = false;
    SDL_Point startClipPos = {-1, -1};
};

#endif
