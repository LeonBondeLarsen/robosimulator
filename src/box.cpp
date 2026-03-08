#include "box.hpp"


Box::Box(Vector3 center, float x, float y, float z, Color color)
{
    this->set_center(center);
    this->set_dimensions(x, y, z);
    this->set_color(color);
}

Box::~Box()
{
}

void Box::set_dimensions(float x, float y, float z)
{
    this->x_dimension = x;
    this->y_dimension = y;
    this->z_dimension = z;
}

void Box::draw()
{
    DrawCube(this->center, this->x_dimension, this->y_dimension, this->z_dimension, this->color);
}
