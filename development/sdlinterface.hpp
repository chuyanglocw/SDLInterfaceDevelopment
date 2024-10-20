/*
作者：chuyangLOCW

作用：省略main函数代码的感官影响
*/
#ifndef _SDL_INTERFACE_H
#define _SDL_INTERFACE_H
#include <SDL2/SDL.h>
#undef main
//定义过程函数
void init();
void render();
bool handler(SDL_Event);
void eventloop();
void dispolse();

#endif