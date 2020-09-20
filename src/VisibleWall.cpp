//
// Created by lavreniuk on 20.09.2020.
//

#include "VisibleWall.h"

VisibleWall::VisibleWall(SolidObject *wall, float distance, int order) {
    this->distance = distance;
    this->wall = wall;
    this->order = order;
}
