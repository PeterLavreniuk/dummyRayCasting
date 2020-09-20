//
// Created by lavreniuk on 18.09.2020.
//

#include <unordered_map>
#include <iostream>
#include "RcRenderer.h"

RcRenderer::RcRenderer(GameMap *map, DummyTrooper *player) {
    this->map = map;
    this->player = player;
}

void RcRenderer::render(SDL_Renderer *renderer) {
    auto walls = this->map->getWalls();

    SDL_Rect skyRect = {
            0,0,
            640,
            480/2
    };

    SDL_Rect floorRect = {
            0,
            480 / 2,
            640,
            480 / 2
    };

    SDL_RenderCopy(renderer, gSkyTexture, nullptr, &skyRect);
    SDL_RenderCopy(renderer, gGrassTexture, nullptr, &floorRect);

    auto visibleWalls = rayCast(walls);

    auto i = 0;
    for(auto &wall : visibleWalls){
        auto wallHeight = (480 / wall->getDistance()) * 32;
        auto skyHeight = (480.0f/2.0f) - wallHeight /2;
        auto floorHeight = (480.0f/2.0f) - wallHeight /2;

        SDL_Rect wallRect = {
                wall->getOrder() * (640/trooperRaysCount),
                (int)skyHeight,
                640/trooperRaysCount,
                (int)wallHeight
        };

        auto distance = wall->getDistance();
        if(distance <= 100){
            SDL_SetTextureColorMod( gWallTexture, 255, 255, 255 );
        }

        if(distance >= 150){
            SDL_SetTextureColorMod( gWallTexture, 128, 128, 128 );
        }

        if(distance >= 300){
            SDL_SetTextureColorMod( gWallTexture, 64, 64, 64 );
        }

        SDL_RenderCopy(renderer, gWallTexture, nullptr, &wallRect);
    }
}

SDL_Texture *RcRenderer::loadTexture(SDL_Renderer *renderer, std::string path) {
    auto img = SDL_LoadBMP(path.c_str());

    auto texture = SDL_CreateTextureFromSurface(renderer, img);

    if(img != nullptr){
        SDL_FreeSurface(img);
    }

    return texture;
}

bool RcRenderer::initialize(SDL_Renderer *renderer) {
    gGrassTexture = loadTexture(renderer, "grass.bmp");
    gSkyTexture = loadTexture(renderer, "sky.bmp");
    gWallTexture = loadTexture(renderer, "wall.bmp");
    if(gGrassTexture == nullptr || gSkyTexture == nullptr || gWallTexture == nullptr){
        return false;
    }

    return true;
}

void RcRenderer::renderDebug(SDL_Renderer *renderer) {
    auto walls = this->map->getWalls();
    float angle = player->getAngle() + ((trooperRaysCount/2) * -this->rayAngleStep);

    for(auto i = 0; i < trooperRaysCount; ++i){
        angle += rayAngleStep;
        auto _x = player->getX();
        auto _y = player->getY();
        auto _angleRadian = angle * M_PI / 180.0f;
        auto _hitWall = false;
        for(auto depth = 0.0f; depth < maxDepth; depth += rayStep){
            if(_hitWall)
                continue;
            _x += sinf(_angleRadian) * rayStep;
            _y += cosf(_angleRadian) * rayStep;

            for(auto &wall : walls){
                if(_x > wall->getX() && _x < wall->getX() + wall->getW() &&
                   _y > wall->getY() && _y < wall->getY() + wall->getH()) {
                    _hitWall = true;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x32);
        SDL_RenderDrawLine(renderer,
                           player->getX(),
                           player->getY(),
                           _x,
                           _y);
    }
}

std::vector<VisibleWall*> RcRenderer::rayCast(std::vector<SolidObject *> walls) {
    auto result = std::vector<VisibleWall*>();
    auto visibleWalls = new std::unordered_map<int,std::pair<float, int>>();

    float angle = player->getAngle() + ((trooperRaysCount/2) * -this->rayAngleStep);

    for(auto i = 0; i < trooperRaysCount; ++i){
        auto _maxDistance = 9999.0f;
        SolidObject* lastWall = nullptr;

        angle += rayAngleStep;
        auto _x = player->getX();
        auto _y = player->getY();
        auto _angleRadian = angle * M_PI / 180.0f;
        for(auto depth = 0.0f; depth < maxDepth; depth += rayStep){
            _x += sinf(_angleRadian) * rayStep;
            _y += cosf(_angleRadian) * rayStep;

            for(auto &wall : walls){
                if(_x > wall->getX() && _x < wall->getX() + wall->getW() &&
                   _y > wall->getY() && _y < wall->getY() + wall->getH()) {
                    if(lastWall == nullptr){
                        lastWall = wall;
                        _maxDistance = depth;
                    }
                    else{
                        if(_maxDistance > depth){
                            _maxDistance = depth;
                            lastWall = wall;
                        }
                    }
                }
            }
        }

        if(lastWall != nullptr){
            auto visibleWall = new VisibleWall(lastWall, _maxDistance, trooperRaysCount - (i+1));
            result.push_back(visibleWall);
            //visibleWalls->insert({lastWall->getId(), {_maxDistance, i + 1}});
        }
    }

/*    for(auto &wall : walls){
        auto pair = visibleWalls->find(wall->getId());
        if(pair == visibleWalls->end()){
            wall->isVisible = false;
        }
        else{
            auto visibleWall = new VisibleWall(wall, pair->second.first, pair->second.second);
            wall->isVisible = true;

            result.push_back(visibleWall);
        }
    }*/

    return result;
}
