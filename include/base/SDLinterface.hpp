#ifndef SDLINTERFACE_HPP
#define SDLINTERFACE_HPP
//头文件
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>

class Game{
public:
    static int WIDTH;
    static int HEIGHT;
    static void init();
    static void render();
    static void eventloop();
    static bool handle(SDL_Event&);
    static void dispose();
};

void init();
void eventloop();
void dispose();

#endif