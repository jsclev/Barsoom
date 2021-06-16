#include "constants.hpp"
#include "Base.hpp"

Base::Base(SDL_Renderer *renderer,
           Texture *texture,
           int x,
           int y,
           SDL_Rect clip) :
        renderer(renderer),
        texture(texture),
        clip(clip) {
//            std::vector<Tile> tiles;
////            Tile* icons = (Tile*)malloc(sizeof(Tile) * NUM_ICONS);
//
//            for (int row = 0; row < NUM_ROWS; row++) {
//                for (int col = 0; col < NUM_COLS; col++) {
////                    int index = row * NUM_COLS + col;
//                    int randClip = rand() % 32;
//                    tiles.emplace_back(renderer,
//                                        &gSpritesTexture,
//                                        col * TILE_WIDTH,
//                                        row * TILE_SIZE - TILE_SIZE / 2,
//                                        gTileClips[randClip]);
//                }
//            }
}

void Base::renderBg() {
    std::vector<Tile> tiles;
//            Tile* icons = (Tile*)malloc(sizeof(Tile) * NUM_ICONS);

//    for (int row = 0; row < NUM_ROWS; row++) {
//        for (int col = 0; col < NUM_COLS; col++) {
////                    int index = row * NUM_COLS + col;
//            int randClip = rand() % 32;
//            tiles.emplace_back(gRenderer,
//                                &gSpritesTexture,
//                                col * TILE_WIDTH,
//                                row * TILE_SIZE - TILE_SIZE / 2,
//                                gTileClips[randClip]);
////                    icons[index] = Tile(gRenderer,
////                                    &gSpritesTexture,
////                                    col * TILE_WIDTH,
////                                    row * TILE_SIZE - TILE_SIZE / 2,
////                                    gIconClips[FOOD_ICON]);
//        }
//    }
}
