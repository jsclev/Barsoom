#ifndef BASE_H
#define BASE_H

#include <SDL2/SDL.h>

#include "Tile.hpp"

class Base {
public:
    Base(SDL_Renderer *renderer,
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
