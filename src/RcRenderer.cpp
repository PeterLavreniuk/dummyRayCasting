//
// Created by lavreniuk on 18.09.2020.
//

#include "RcRenderer.h"

RcRenderer::RcRenderer(GameMap *map, DummyTrooper *player) {
    this->map = map;
    this->player = player;
}

void RcRenderer::render(SDL_Renderer *renderer) {
    auto rays = createRays();
    renderTrooperRays(rays, renderer);

}

DummyVector* RcRenderer::createRays() {
    auto trooperDir = new DummyVector(player->getMovementDirection()->getX(), player->getMovementDirection()->getY());
    DummyVector* rays = new DummyVector[trooperRaysCount];

    auto angle = 0.0f;
    for(int i = 0; i < trooperRaysCount / 2; ++i){
        angle -= 3.0f;
        auto ray = new DummyVector(trooperDir->getX(), trooperDir->getY());
        ray->rotate(angle);
        rays[i] = *ray;
    }

    angle = 0.0f;
    for(int i = trooperRaysCount / 2; i < trooperRaysCount; ++i){
        angle += 3.0f;
        auto ray = new DummyVector(trooperDir->getX(), trooperDir->getY());
        ray->rotate(angle);
        rays[i] = *ray;
    }

    return rays;
}

void RcRenderer::renderTrooperRays(DummyVector *rays, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x13, 0x6d, 0x15, 0x7D);
    for(auto i = 0; i < trooperRaysCount; ++i){
        SDL_RenderDrawLine(renderer, rays[i].getX() + player->getX(), rays[i].getY() + player->getY(),
                           (rays[i].getX() * 200) + player->getX(), (rays[i].getY() * 200) + player->getY());
    }
}

/*
void RcRenderer::renderTrooperRays(DummyVector *rays) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, direction->getX() + x, direction->getY() + y,
                       (direction->getX() * 100) + x,(direction->getY() * 100) + y);
}
*/
