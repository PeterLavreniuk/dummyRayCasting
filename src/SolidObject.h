//
// Created by lavreniuk on 19.09.2020.
//

#ifndef DUMMYRAYCASTING_SOLIDOBJECT_H
#define DUMMYRAYCASTING_SOLIDOBJECT_H


class SolidObject {
private:
    float x,y,h,w;
    int id;
public:
    SolidObject(float x, float y, float h, float w, int id);
    bool isVisible;
    float getX() const {return this->x;}
    float getY() const {return this->y;}
    float getH() const {return this->h;}
    float getW() const {return this->w;}
    int getId() const {return this->id;}
};


#endif //DUMMYRAYCASTING_SOLIDOBJECT_H
