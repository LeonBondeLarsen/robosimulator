#include "shape.hpp"

class Cylinder : public Shape{

    private:
    Matrix rotation;
    Vector3 translation;
    float length;
    float radius;

    public:
    Cylinder(Matrix, Vector3, float, float, Color);
    ~Cylinder();
    void draw() override;
    



};