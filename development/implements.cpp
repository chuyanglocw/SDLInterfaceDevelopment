#include "sdlinterface.hpp"

#define FPS 60
#define DELTATIME (1000 / FPS)

SDL_Window *window;
SDL_Renderer *renderer;


//初始化
void init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("新的窗口",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

//渲染
void render(){
}

//处理
bool handler(SDL_Event event){
    switch (event.type)
    {
        case SDL_QUIT:{
            return false;
            break;
        }
    }
    return true;
}

//每次程序循环的处理
void eventloop(){
    
    SDL_Event event;
    Uint64 start, end, delta;
    bool isRunning = true;
    while (isRunning)
    {
        start = SDL_GetTicks64();
        if(SDL_PollEvent(&event)){
            isRunning = handler(event);
        }
        render();
        end = SDL_GetTicks64();
        delta = end - start;
        if (delta < DELTATIME){
            SDL_Delay(DELTATIME - delta);
        }
    }

}

//程序消除
void dispolse(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}