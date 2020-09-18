//
// Created by lavreniuk on 18.09.2020.
//

#ifndef DUMMYRAYCASTING_DUMMYVECTOR_H
#define DUMMYRAYCASTING_DUMMYVECTOR_H


class DummyVector {
private:
    float x;
    float y;
public:
    DummyVector();
    DummyVector(float x, float y);
    void rotate(float angle);
    void multiply(float value);
    void divide(float value);
    float magnitude();
    float getX() const {return this->x;}
    float getY() const {return this->y;}
};


#endif //DUMMYRAYCASTING_DUMMYVECTOR_H
