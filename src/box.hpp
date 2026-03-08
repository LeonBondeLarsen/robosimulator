#include "shape.hpp"

class Box : public Shape
{
    private:
    float x_dimension;
    float y_dimension;
    float z_dimension;


    public:
    Box(Vector3, float, float, float, Color);
    ~Box();
    void set_dimensions(float, float, float);
    void draw() override;


};