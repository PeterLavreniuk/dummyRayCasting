//
// Created by lavreniuk on 18.09.2020.
//

#include "DummyTrooper.h"

DummyTrooper::DummyTrooper(float x, float y) {
    this->x = x;
    this->y = y;
}

//todo refactor
void DummyTrooper::render(SDL_Renderer *renderer) {
    auto angleRadian = angle * M_PI / 180.0f;

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, this->x,
                       this->y,
                       this->x + (sinf(angleRadian) * 10.0f),
                       this->y + (cosf(angleRadian) * 10.0f));

    for (int w = 0; w < collisionRadius * 2; w++)
    {
        for (int h = 0; h < collisionRadius * 2; h++)
        {
            int dx = collisionRadius - w;
            int dy = collisionRadius - h;
            if ((pow(dx,2) + pow(dy,2)) <= pow(collisionRadius, 2))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void DummyTrooper::rotate(float angle) {
    this->angle -= angle;
}

void DummyTrooper::move(float position) {
    auto angleRadian = angle * M_PI / 180.0f;
    this->x += sinf(angleRadian) * position;
    this->y += cosf(angleRadian) * position;
}
