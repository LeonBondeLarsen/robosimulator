#include "sphere.hpp"

Sphere::Sphere(Vector3 center, float radius, Color color)
{
    this->set_center(center);
    this->set_color(color);
    this->set_radius(radius);
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
    DrawSphere(this->center, this->radius, this->color);
}

void Sphere::set_radius(float radius)
{
    this->radius = radius;
}
