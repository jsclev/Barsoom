#include <SDL2/SDL_image.h>

#include "Texture.hpp"

Texture::Texture() {
    texture = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(SDL_Renderer *renderer, const char *path) {
    free();

    SDL_Texture *tempTexture = nullptr;
    SDL_Surface *tempSurface = IMG_Load(path);
    
    if (tempSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    }
    else {
        SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0, 0xFF, 0xFF));
        tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        
        if (tempTexture == nullptr) {
            printf("Cannot load texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }
        else {
            width = tempSurface->w;
            height = tempSurface->h;
        }

        SDL_FreeSurface(tempSurface);
    }

    texture = tempTexture;
    return texture != nullptr;
}

#if defined(SDL_TTF_MAJOR_VERSION)

bool Texture::loadFromRenderedText(SDL_Renderer *renderer,
                                   TTF_Font *gFont,
                                   std::string textureText,
                                   SDL_Color textColor) {
    free();

    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (texture == nullptr) {
            printf("Cannot create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            width = textSurface->w;
            height = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    } else {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }

    return texture != nullptr;
}

#endif

void Texture::free() {
    //Free texture if it exists
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip) {
    SDL_Rect destinationRect = {x, y, width, height};

    // We do not want to stretch the clip when we render to the
    // destination, so we make sure to set the source and destination
    // width and height to be equal.
    if (clip != nullptr) {
        destinationRect.w = clip->w;
        destinationRect.h = clip->h;
    }

    SDL_RenderCopy(renderer, texture, clip, &destinationRect);
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}
