#ifndef SDLINTERFACE_HPP
#define SDLINTERFACE_HPP
//头文件
#include <SDL2/SDL.h>

//避免main重复错误
#undef main

class Game{
public:
    static int WIDTH;
    static int HEIGHT;
    static void init();
    static void eventloop();
    static void dispose();
};

void init();
void eventloop();
void dispose();

#endif