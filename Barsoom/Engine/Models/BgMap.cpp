#include "BgMap.hpp"

BgMap::BgMap(int mapWidth,
             int mapHeight,
             int screenWidth,
             int screenHeight):
             mapWidth(mapWidth),
             mapHeight(mapHeight) {
    // We'll initialize the visible clip of the map to be the size
    // of the window we are on (we run the game at full screen), and
    // at the center of the map image.  We choose the center clip of
    // the map image so that the user can pan around without hitting
    // the blank edges of the image when the game first loads.
                 
    clip = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    clip->x = (mapWidth / 2) - (screenWidth / 2);
    clip->y = (mapHeight / 2) - (screenHeight / 2);
    clip->w = screenWidth;
    clip->h = screenHeight;
    
//    SDL_Log("Screen size is (%i, %i)", screenWidth, screenHeight);
//    SDL_Log("Background clip is at (%i, %i) size (%i, %i)", clip->x, clip->y, clip->w, clip->h);
}

BgMap::~BgMap() {
    free(clip);
}

bool BgMap::isPanStopping() {
    return panStopping;
}

SDL_Rect* BgMap::getClip() {
    return clip;
}

void BgMap::startPan(SDL_Point startPos) {
    startPanPos = startPos;
    startClipPos = {clip->x, clip->y};
    panStopping = false;
    
//    SDL_Log("Start clip position is %i, %i", startClipPos.x, startClipPos.y);
}

void BgMap::pan(SDL_Point position, SDL_Point prevPosition) {
    if (position.x >= 0 && position.y >= 0 &&
        prevPosition.x >= 0 && prevPosition.y >= 0) {
        panVelocity = (float)sqrt(pow(position.x - prevPosition.x, 2) + pow(position.y - prevPosition.y, 2));
        panAngle = atan2(prevPosition.y - position.y, prevPosition.x - position.x);

//        SDL_Log("Pan velocity is %f and angle is %f.", panVelocity, panAngle);
    }
    
    if (startClipPos.x - (position.x - startPanPos.x) < 0) {
        clip->x = 0;
    }
    else if (startClipPos.x - (position.x - startPanPos.x) > mapWidth - clip->w) {
        clip->x =  - clip->w;
    }
    else {
        clip->x = startClipPos.x - (position.x - startPanPos.x);
    }
    
    if (startClipPos.y - (position.y - startPanPos.y) < 0) {
        clip->y = 0;
    }
    else if (startClipPos.y - (position.y - startPanPos.y) > mapHeight - clip->h) {
        clip->y = mapHeight - clip->h;
    }
    else {
        clip->y = startClipPos.y - (position.y - startPanPos.y);
    }
    
    panStopping = false;
//    SDL_Log("New clip is at (%i, %i) and is (%i, %i)", clip->x, clip->y, clip->w, clip->h);
}

void BgMap::stopPan(SDL_Point position) {
    if (position.x >= 0 && position.y >= 0) {
        panStopping = true;
        lastPanPos.x = position.x;
        lastPanPos.y = position.y;
    }
    
//    SDL_Log("Stopped pan at (%i, %i)", position.x, position.y);
}

void BgMap::updatePosition() {
    if (panStopping) {
        if (panVelocity > 1.0) {
            // Panning is still in the process of stopping
            float deltaY = panVelocity * cos(panAngle);
            float deltaX = panVelocity * sin(panAngle);

//            SDL_Log("Pan velocity %f, deltaX %f, deltaY %f", panVelocity, deltaX, deltaY);

            // Add that to the existing position
            clip->x -= deltaX;
            clip->y -= deltaY;

            if (clip->x <= 0) {
                clip->x = 0;
            }

            if (clip->x >= mapWidth - clip->w) {
                clip->x = mapWidth - clip->w;
            }

            if (clip->y <= 0) {
                clip->y = 0;
            }

            if (clip->y >= mapHeight - clip->h) {
                clip->y = mapHeight - clip->h;
            }

            panVelocity *= .9;
        }
        else {
            panStopping = false;

        }
    }
}
