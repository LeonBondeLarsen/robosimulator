#include "shape.hpp"

Shape::Shape()
{
    this->center = Vector3{0.0 , 0.0 , 0.0};

}

Shape::~Shape()
{
}

void Shape::set_center(float x, float y, float z)
{
    this->center = Vector3{x, y, z};
}

void Shape::set_center(Vector3 center)
{
    this->center = center;
}

void Shape::set_color(Color color)
{
    this->color = color;
}
