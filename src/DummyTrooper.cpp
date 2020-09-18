//
// Created by lavreniuk on 18.09.2020.
//

#include "DummyTrooper.h"

DummyTrooper::DummyTrooper(float x, float y) {
    this->x = x;
    this->y = y;
    this->direction = new DummyVector(1,1);
}

void DummyTrooper::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, direction->getX() + x, direction->getY() + y,
                       (direction->getX() * 100) + x,(direction->getY() * 100) + y);

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
    direction->rotate(angle);
}

void DummyTrooper::move(float position) {
    x += direction->getX();
    y += direction->getY();
}
