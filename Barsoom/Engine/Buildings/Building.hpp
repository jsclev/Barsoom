#ifndef BARSOOM_BUILDING_H
#define BARSOOM_BUILDING_H

#include <SDL.h>
#include "Texture.hpp"

using namespace std;

class Building {
public:
    Building(SDL_Renderer *renderer, Texture *texture, string name, int level);
    
    string getName();
    
    void startPan(SDL_Point startPos);
    
    void log();

    void pan(SDL_Point position);
    
    void render(int gridPositionX, int gridPositionY);

protected:
    SDL_Renderer *renderer;
    Texture *texture;
    string name;
    int level = 0;
    SDL_Rect spriteClip = {0, 0, 0, 0};
    SDL_Rect screenClip = {0, 0, 0, 0};
    SDL_Point startPanPos;
    SDL_Point startClipPos;
};

#endif
