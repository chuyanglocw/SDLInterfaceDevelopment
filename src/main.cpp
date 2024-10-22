#include <base/SDLinterface.hpp>

SDL_Window *window;

int Game::WIDTH = 1000;
int Game::HEIGHT = 800;

void Game::init(){
    window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Game::WIDTH,Game::HEIGHT,SDL_WINDOW_SHOWN);
}

void Game::eventloop(){
    SDL_Event event;
    while (true)
    {
        if(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                break;
            }
        }
    }
}

void Game::dispose(){
    SDL_DestroyWindow(window);
}