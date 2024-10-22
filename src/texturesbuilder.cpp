#include <base/texturesbuilder.hpp>

Texture::Texture(int w, int h, SDL_Texture *texture){
    this->w = w;
    this->h = h;
    this->texture = texture;
}

// Texture::Texture(Texture &texture){
//     w = texture.w;
//     h = texture.h;
//     this->texture = texture.texture;
// }

Texture::~Texture(){
    SDL_DestroyTexture(texture);
}

Texture *loadBMPt(SDL_Renderer *renderer,const char * path){
    SDL_Surface *surface = SDL_LoadBMP(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    Texture *t = new Texture(surface->w, surface->h, texture);
    SDL_FreeSurface(surface);
    return t;
}

Texture *loadPNGt(SDL_Renderer *renderer,const char * path){
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    Texture *t = new Texture(surface->w, surface->h, texture);
    SDL_FreeSurface(surface);
    IMG_Quit();
    return t;
}

Texture *loadJPGt(SDL_Renderer *renderer,const char * path){
    IMG_Init(IMG_INIT_JPG);
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    Texture *t = new Texture(surface->w, surface->h, texture);
    SDL_FreeSurface(surface);
    IMG_Quit();
    return t;
}