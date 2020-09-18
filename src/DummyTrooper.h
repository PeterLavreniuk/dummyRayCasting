//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_DUMMYTROOPER_H
#define DUMMYRAYCASTING_DUMMYTROOPER_H


#include <SDL2/SDL_render.h>
#include "DummyVector.h"

class DummyTrooper {
private:
    float x, y;
    float collisionRadius = 5.0f;
    DummyVector* direction;
public:
    DummyTrooper(float x, float y);
    float getX() const {return this->x;}
    float getY() const {return this->y;}
    DummyVector* getMovementDirection() const { return this->direction; };
    void render(SDL_Renderer* renderer);
    void rotate(float angle);
    void move(float position);
};


#endif //DUMMYRAYCASTING_DUMMYTROOPER_H
