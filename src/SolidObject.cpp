//
// Created by lavreniuk on 19.09.2020.
//

#include "SolidObject.h"

SolidObject::SolidObject(float x, float y, float h, float w, int id) {
    this->x = x;
    this->y = y;
    this->h = h;
    this->w = w;
    this->id = id;
    this->isVisible = false;
}
