#include <base/SDLinterface.hpp>
#include <base/texturesbuilder.hpp>

SDL_Window *window;
SDL_Renderer *renderer;

int Game::WIDTH = 1000;
int Game::HEIGHT = 800;

Texture *t1;

SDL_Point mouse_position;

void Game::init(){
    window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Game::WIDTH,Game::HEIGHT,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    t1 = loadPNGt(renderer,"assets/textures/cloud.png");

    mouse_position = {0, 0};
}

void Game::render(){
    SDL_RenderClear(renderer);

    SDL_Rect recta = {mouse_position.x,mouse_position.y,t1->w,t1->h};
    SDL_RenderCopy(renderer,t1->texture,NULL,&recta);
    SDL_RenderPresent(renderer);
}

void Game::eventloop(){
    SDL_Event event;
    bool isRunning = true;
    while (isRunning)
    {
        if(SDL_PollEvent(&event)){
            isRunning = handle(event);
        }
        Game::render();
        SDL_Delay(10);
    }
}

bool Game::handle(SDL_Event &event){
    switch (event.type){
        case SDL_QUIT:{
            return false;
            break;
        }case SDL_MOUSEMOTION:{
            mouse_position.x = event.motion.x;
            mouse_position.y = event.motion.y;
            break;
        }
    }
    return true;
}

void Game::dispose(){
    delete t1;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}