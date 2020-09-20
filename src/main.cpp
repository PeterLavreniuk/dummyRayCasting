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
    auto map = new GameMap();
    map->loadMap();
    auto trooper = new DummyTrooper(128, 128);

    auto rcRenderer = new RcRenderer(map, trooper);
    if(!rcRenderer->initialize(gRenderer)){
        std::cout << "init failed" << std::endl;
        clear();
        return 0;
    }

    auto quit = false;
    SDL_Event e;

    auto sleep = 0;
    Uint32 next_game_tick = SDL_GetTicks();

    const Uint8* state = SDL_GetKeyboardState(NULL);

    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    SDL_Rect debugViewPort = {
            0,
            0,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT /2
    };

    SDL_Rect gameViewPort = {
            SCREEN_WIDTH / 2,
            0,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT
    };

    while(!quit){
        if(state[SDL_SCANCODE_ESCAPE]){
            quit = true;
        }

        if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
            trooper->move(5.0f);
        }
        if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
            trooper->rotate(-2.0f);
        }
        if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
            trooper->rotate(2.0f);
        }

        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        //debug viewport
        SDL_RenderSetViewport(gRenderer, &debugViewPort);
        rcRenderer->renderDebug(gRenderer);
        map->render(gRenderer);
        trooper->render(gRenderer);
        //end of debug viewport

        //game viewport
        SDL_RenderSetViewport(gRenderer, &gameViewPort);
        rcRenderer->render(gRenderer);
        //end of game viewport

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
