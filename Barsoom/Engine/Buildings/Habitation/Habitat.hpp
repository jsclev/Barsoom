#ifndef HABITAT_H
#define HABITAT_H

#include <SDL.h>
#include "Texture.hpp"

class Habitat {
public:
    Habitat(SDL_Renderer *renderer, Texture *texture);

    void render(int gridPositionX, int gridPositionY);
    
    void setLevel(int level);

private:
    SDL_Renderer *renderer;
    Texture *texture;
    SDL_Rect clip;
    int level;
};

#endif
