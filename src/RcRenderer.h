//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_RCRENDERER_H
#define DUMMYRAYCASTING_RCRENDERER_H


#include <string>
#include "GameMap.h"
#include "DummyTrooper.h"
#include "VisibleWall.h"

class RcRenderer {
private:
    GameMap* map;
    DummyTrooper* player;

    SDL_Texture* gGrassTexture = nullptr;
    SDL_Texture* gSkyTexture = nullptr;
    SDL_Texture* gWallTexture = nullptr;

    const int trooperRaysCount = 65;
    const float rayAngleStep = 1.0f;
    const float rayStep = 1.0f;
    const float maxDepth = 512.0f;
    SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
    std::vector<VisibleWall*> rayCast(std::vector<SolidObject*> walls);
public:
    RcRenderer(GameMap* map, DummyTrooper* player);
    void render(SDL_Renderer* renderer);
    void renderDebug(SDL_Renderer* renderer);
    bool initialize(SDL_Renderer* renderer);
};


#endif //DUMMYRAYCASTING_RCRENDERER_H
