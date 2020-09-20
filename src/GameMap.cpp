//
// Created by lavreniuk on 18.09.2020.
//

#include <iostream>
#include "GameMap.h"

GameMap::GameMap() {

}

void GameMap::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x7D);

    for(size_t i = 0; i < walls.size(); ++i){
        SolidObject* wall = walls[i];
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, wall->isVisible ? 0x7D : 0x32);
        DummyLane sLane = {wall->getX(),
                           wall->getY(),
                           wall->getW(),
                           wall->getH()};

        SDL_Rect fillRect = {(int)sLane.fx,
                              (int)sLane.fy,
                              sLane.lx == 0 ? 1 : (int)sLane.lx,
                              sLane.ly == 0 ? 1 : (int)sLane.ly};

        SDL_RenderFillRect(renderer, &fillRect);
    }
}

void GameMap::loadMap() {
    auto id = 1;
    for(int i = 0; i < 16; ++i){
        for(int j = 0; j < 16; ++j){
            if(field[i][j] == '.')
                continue;
            auto h = 32.0f;
            auto w = 32.0f;
            auto x = j * 32;
            auto y = i * 32;

            SolidObject* wall = new SolidObject(x, y, h, w, id);
            ++id;
            walls.push_back(wall);
        }
    }
}
