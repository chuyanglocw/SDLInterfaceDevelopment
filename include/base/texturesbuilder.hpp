#ifndef TEXTURES_BUILDER_HPP
#define TEXTURES_BUILDER_HPP

#include <base/SDLinterface.hpp>

class Texture{
public:
    int w;
    int h;
    SDL_Texture *texture;
    Texture(int,int,SDL_Texture*);
    //Texture(Texture&);
    ~Texture();
};

Texture *loadBMPt(SDL_Renderer *,const char *);
Texture *loadPNGt(SDL_Renderer *,const char *);
Texture *loadJPGt(SDL_Renderer *,const char *);

#endif