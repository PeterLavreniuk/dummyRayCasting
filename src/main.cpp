#include <iostream>
#include <SDL2/SDL.h>
#include "GameMap.h"
#include "DummyTrooper.h"
#include "RcRenderer.h"

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

int SCREEN_WIDTH = 1240;
int SCREEN_HEIGHT= 1024;

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << SDL_GetError();
        return false;
    }

    gWindow = SDL_CreateWindow("Dummy RayCasting",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(gWindow == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(gRenderer == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void clear(){
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main() {
    if(!init()){
        std::cout << "init failed" << std::endl;
        clear();
        return 0;
    }

    auto quit = false;
    SDL_Event e;

    auto sleep = 0;
    Uint32 next_game_tick = SDL_GetTicks();

    const Uint8* state = SDL_GetKeyboardState(NULL);

    auto map = new GameMap();
    auto trooper = new DummyTrooper(128, 128);
    auto rcRenderer = new RcRenderer(map, trooper);
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    while(!quit){
        if(state[SDL_SCANCODE_ESCAPE]){
            quit = true;
        }

        if (state[SDL_SCANCODE_UP]) {
            trooper->move(1.0f);
        }
        if (state[SDL_SCANCODE_LEFT]) {
            trooper->rotate(-4.0f);
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            trooper->rotate(4.0f);
        }

        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        map->render(gRenderer);
        trooper->render(gRenderer);
        rcRenderer->render(gRenderer);

        SDL_RenderPresent(gRenderer);

        next_game_tick += 1000 / 60;
        sleep = next_game_tick - SDL_GetTicks();

        if( sleep >= 0 ) {
            SDL_Delay(sleep);
        }
    }

    clear();

    return 0;
}
