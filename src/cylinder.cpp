#include "cylinder.hpp"

Cylinder::Cylinder(Matrix rotation, Vector3 translation, float length, float radius, Color color)
{
    this->rotation = rotation;
    this->translation = translation;
    this->length = length;
    this->radius = radius;
    this->color = color;
}

Cylinder::~Cylinder()
{
}

void Cylinder::draw()
{
    float z_1 = this->rotation.m6;
    float z_2 = this->rotation.m7;
    float z_3 = this->rotation.m8;
    Vector3 z = {z_1, z_2, z_3};
    Vector3 z_norm = Vector3Normalize(z);
    Vector3 start = translation;
    Vector3 z_scaled = Vector3Scale(z_norm, this->length);
    Vector3 end = Vector3Add(start, z_scaled);
    DrawCylinderEx(start, end, this->radius, this->radius, 16, this->color);
}
