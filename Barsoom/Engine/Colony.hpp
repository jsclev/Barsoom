#ifndef BARSOOM_DEVICE_H
#define BARSOOM_DEVICE_H

#include <SDL.h>
#include "Device.hpp"
#include "Tile.hpp"

class Colony {
public:
    Colony(SDL_Renderer *renderer,
           Texture *texture,
           int x,
           int y,
           SDL_Rect clip);

    void handleEvent(SDL_Event *e, std::vector<Tile> *tiles, SDL_Rect tileClips[]);

    void renderBg();

private:
    SDL_Point position;
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
};

#endif
