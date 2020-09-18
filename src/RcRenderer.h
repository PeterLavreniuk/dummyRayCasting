//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_RCRENDERER_H
#define DUMMYRAYCASTING_RCRENDERER_H


#include "GameMap.h"
#include "DummyTrooper.h"

class RcRenderer {
private:
    GameMap* map;
    DummyTrooper* player;
    DummyVector* createRays();

    const int trooperRaysCount = 32;

    void renderTrooperRays(DummyVector* rays, SDL_Renderer *renderer);
public:
    RcRenderer(GameMap* map, DummyTrooper* player);
    void render(SDL_Renderer* renderer);
};


#endif //DUMMYRAYCASTING_RCRENDERER_H
