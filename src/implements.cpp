#include <base/SDLinterface.hpp>


void init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    Game::init();
}

void eventloop(){
    Game::eventloop();
}


void dispose(){
    Game::dispose();
    SDL_Quit();
}

//启动
int main(){
    init();
    eventloop();
    dispose();
    return 0;
}