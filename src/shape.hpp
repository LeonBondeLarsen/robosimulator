#ifndef SHAPE_H
#define SHAPE_H
#include <raylib.h>
#include <raymath.h>

class Shape
{
protected:
    Vector3 center;
    Color color;
public:
    Shape();
    ~Shape();

    virtual void draw() = 0;
    void set_center(float, float, float);
    void set_center(Vector3);
    void set_color(Color);



};

#endif
