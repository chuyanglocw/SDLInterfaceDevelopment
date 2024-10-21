#include "sdlinterface.hpp"

#define FPS 60
#define DELTATIME (1000 / FPS)



bool mouseMoveEvent(SDL_Event&);
bool mouseButtonEvent(SDL_Event&,int,bool);
bool keyboardEvent(SDL_Event&,bool);
SDL_Surface *loadPng(const char*);
void showTextxy(const char*,int,int);
//TODO
void audioCallback(void*,Uint8*,int);
char* resourcePath(const char*);


SDL_Window *window;
SDL_Renderer *renderer;

SDL_Point mousePosition;

SDL_Color fontColor = {0,0,0,255};
char fontPath[1000] = "assets/fonts/simhei.ttf";


//初始化
void init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("新的窗口",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,SDL_WINDOW_SHOWN); //名字 位置 大小 显示方式
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

//渲染 记得用 SDL_RenderPresent(renderer) 刷新
void render(){

}

//鼠标移动事件
bool mouseMoveEvent(SDL_Event &event){
    mousePosition.x = event.motion.x;
    mousePosition.y = event.motion.y;


    return true;
}

//鼠标点击事件
bool mouseButtonEvent(SDL_Event &event,int button,bool isDown){
    mousePosition.x = event.button.x;
    mousePosition.y = event.button.y;
    if (button == SDL_BUTTON_LEFT){
        if (isDown){
            //鼠标左键按下
        }else{
            //鼠标左键抬起
        }
    }else if (button == SDL_BUTTON_RIGHT){
        if (isDown){
            //鼠标右键按下
        }else{
            //鼠标右键抬起
        }
    }else if (button == SDL_BUTTON_MIDDLE){
        if (isDown){
            //鼠标滚轮按下
        }else{
            //鼠标滚轮抬起
        }
    }
    return true;
}

//键盘事件
bool keyboardEvent(SDL_Event &event, bool isDown){
    switch (event.key.keysym.sym){
        case SDLK_ESCAPE:{
            if (isDown)
            {
                return false;
            }
            break;
        }
    }
    return true;
}



//处理
bool handler(SDL_Event &event){
    switch (event.type)
    {
        case SDL_QUIT:{
            return false;
            break;
        }
        case SDL_MOUSEMOTION:{
            return mouseMoveEvent(event);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:{
            return mouseButtonEvent(event,event.button.button,true);
            break;
        }
        case SDL_MOUSEBUTTONUP:{
            return mouseButtonEvent(event,event.button.button,false);
            break;
        }case SDL_KEYDOWN:{
            return keyboardEvent(event,true);
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

SDL_Surface *loadPng(const char* path){
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *surface = IMG_Load(path);
    IMG_Quit();
    return surface;
}
void showTextxy(const char* text,int x,int y,int size){
    TTF_Init();
    TTF_Font *font = TTF_OpenFont(fontPath,size);
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font,text,fontColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Rect rect = {x,y,surface->w,surface->h};
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    TTF_Quit();
}