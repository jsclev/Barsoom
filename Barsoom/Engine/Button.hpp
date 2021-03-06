#ifndef BARSOOM_BUTTON_H
#define BARSOOM_BUTTON_H

#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "Tile.hpp"

class Button {
public:
    Button(SDL_Renderer *renderer,
           Texture *texture,
           int x,
           int y,
           SDL_Rect clip);

    void handleEvent(SDL_Event *e, std::vector<Tile> *tiles, SDL_Rect tileClips[]);

    void render();

private:
    SDL_Point position;
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
};

#endif
