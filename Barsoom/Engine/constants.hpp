#ifndef BARSOOM_CONSTANTS_H
#define BARSOOM_CONSTANTS_H

const char GAME_NAME[] = "Barsoom";
const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

const int TILE_WIDTH = 256;
const int TILE_HEIGHT = 384;
const int TILE_SIZE = 256;
const int NUM_ROWS = 7;
const int NUM_COLS = 9;
const int NUM_TILES = NUM_ROWS * NUM_COLS;
const int NUM_ICONS = NUM_TILES;

const int BUTTON_WIDTH = 670;
const int BUTTON_HEIGHT = 162;
const int TOTAL_BUTTONS = 4;

const int ICON_WIDTH = 72;
const int ICON_HEIGHT = 78;
const int PRODUCTION_ICON = 3;
const int FOOD_ICON = 0;

const int MAIN_BUTTON = 0;

#endif
