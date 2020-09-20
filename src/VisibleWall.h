//
// Created by lavreniuk on 20.09.2020.
//

#ifndef DUMMYRAYCASTING_VISIBLEWALL_H
#define DUMMYRAYCASTING_VISIBLEWALL_H


#include "SolidObject.h"

class VisibleWall {
private:
    float distance;
    int order;
    SolidObject* wall;
public:
    VisibleWall(SolidObject* wall, float distance, int order);
    float getDistance() const {return this->distance;}
    int getOrder() const {return this->order;}
    SolidObject* getWall() const{return this->wall;}
};


#endif //DUMMYRAYCASTING_VISIBLEWALL_H
