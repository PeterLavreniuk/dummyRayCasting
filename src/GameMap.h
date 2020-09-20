//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_GAMEMAP_H
#define DUMMYRAYCASTING_GAMEMAP_H

#include <SDL2/SDL_render.h>
#include <vector>
#include "SolidObject.h"

class GameMap {
private:
    struct DummyLane{
        float fx, fy, lx, ly;
    };

    char field[16][16] = {
            {'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','B','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','B','B','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','B','.','.','B','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','B','.','.','B','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','B','.','.','B','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','B','.','B','B','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','B','.','B','.','.','.','.','.','.','.','B'},
            {'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'}
    };

    std::vector<SolidObject*> walls;
public:
    GameMap();
    //todo pass map array in the future
    void loadMap();
    void render(SDL_Renderer* renderer);
    std::vector<SolidObject*> getWalls() { return this->walls; };
};


#endif //DUMMYRAYCASTING_GAMEMAP_H
