#include <iostream>

using namespace std;

#include "Button.hpp"
#include "constants.hpp"
#include "Tile.hpp"

Button::Button(SDL_Renderer *renderer,
               Texture *texture,
               int x,
               int y,
               SDL_Rect clip) :
        renderer(renderer),
        texture(texture),
        clip(clip) {
    position.x = x;
    position.y = y;
}

void Button::handleEvent(SDL_Event *e, std::vector<Tile> *tiles, SDL_Rect tileClips[]) {
    SDL_Rect iconClip;
    iconClip.x = 2302; //7 + TILE_WIDTH * 8 + ICON_WIDTH * 0;
    iconClip.y = 2; //ICON_HEIGHT * 0;
    iconClip.w = ICON_WIDTH;
    iconClip.h = ICON_HEIGHT;

    tiles->clear();
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            int randClip = rand() % 32; // NOLINT(cert-msc30-c, cert-msc50-cpp)
            Tile tile = Tile(renderer,
                             texture,
                             col * TILE_WIDTH,
                             row * TILE_SIZE - TILE_SIZE / 2,
                             tileClips[randClip]);
            TileLayer resourceLayer = TileLayer(renderer,
                                                texture,
                                                col * TILE_WIDTH,
                                                row * TILE_SIZE - TILE_SIZE / 2,
                                                iconClip,
                                                0);
            resourceLayer.setFood(5.0f);
            tile.addLayer(resourceLayer);

            tiles->emplace_back(tile);
        }
    }

    for (auto t : *tiles) {
        cout << t.getFood() << endl;
    }
}

void Button::render() {
    texture->render(renderer, position.x, position.y, &clip);
}
