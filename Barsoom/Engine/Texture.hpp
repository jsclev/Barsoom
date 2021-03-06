#ifndef BARSOOM_TEXTURE_H
#define BARSOOM_TEXTURE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Texture {
public:
    Texture();

    ~Texture();

    bool loadFromFile(SDL_Renderer *renderer, const char *path);

#if defined(SDL_TTF_MAJOR_VERSION)

    bool loadFromRenderedText(SDL_Renderer *renderer,
                              TTF_Font *gFont,
                              std::string textureText,
                              SDL_Color textColor);

#endif

    void free();

    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    void setBlendMode(SDL_BlendMode blending);

    void setAlpha(Uint8 alpha);

    void render(SDL_Renderer *renderer,
                int x,
                int y,
                SDL_Rect *clip = nullptr);

    int getWidth();

    int getHeight();

private:
    SDL_Texture *texture;
    int width;
    int height;
};

#endif
