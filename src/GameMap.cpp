//
// Created by lavreniuk on 18.09.2020.
//

#include "GameMap.h"

GameMap::GameMap() {

}

void GameMap::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x7D);
    for(int i = 0; i < 16; ++i){
        for(int j = 0; j < 16; ++j){
            if(field[i][j] == '.')
                continue;
            auto x = i * 32;
            auto y = j * 32;
            SDL_Rect fillRect = {x, y, 32, 32};
            SDL_RenderFillRect(renderer, &fillRect);
        }
    }
}