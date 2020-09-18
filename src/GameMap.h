//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_GAMEMAP_H
#define DUMMYRAYCASTING_GAMEMAP_H

#include <SDL2/SDL_render.h>

class GameMap {
private:
    char field[16][16] = {
            {'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','.','.','.','.','.','.','.','.','.','.','.','.','.','.','B'},
            {'B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B'}
    };
public:
    GameMap();
    void render(SDL_Renderer* renderer);
};


#endif //DUMMYRAYCASTING_GAMEMAP_H