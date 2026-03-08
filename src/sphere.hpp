#include "shape.hpp"

class Sphere : public Shape
{
private:
    float radius;
public:
    Sphere(Vector3, float, Color);
    ~Sphere();


    void draw() override;
    void set_radius(float);



};