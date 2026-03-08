#include <raylib.h>
#include <raymath.h>
#include "sphere.hpp"
#include "box.hpp"
#include "cylinder.hpp"

int main(void){
    InitWindow(800,600,"robosim");

    Camera3D camera = { 0 };
    camera.position = Vector3{ 3.0f, 3.0f, 3.0f };
    camera.target   = Vector3{ 0.0f, 0.0f, 0.0f };
    camera.up       = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 blue_point = {-0.55, 0, 0.1};
    Vector3 red_point = {-0.65, 0.1, 0.15};
    Vector3 green_point = {-0.55, 0.2, 0.1};
    Sphere blue(blue_point, 0.02, BLUE);
    Sphere red(red_point, 0.02, RED);
    Sphere green(green_point, 0.02, GREEN);

    // Vector3 rotations = {1, 2, 3};
    // Matrix rotation = MatrixRotateXYZ(rotations);
    // Vector3 translation = {1, 2, 3};
    // Cylinder cyl(rotation, translation, 3, 2, PURPLE);

    Mesh table_mesh = GenMeshCube(0.2, 0.3, 0.02);
    Material table_material = LoadMaterialDefault();
    table_material.maps[MATERIAL_MAP_DIFFUSE].color = RED;
    Matrix table_translation = MatrixTranslate(0.55, 0.0 ,0.1);
    Matrix table_rotation = MatrixRotateXYZ((Vector3){PI/2, 0, 0});
    Matrix table_transform = MatrixMultiply(table_rotation, table_translation);

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        blue.draw();
        red.draw();
        green.draw();

        DrawMesh(table_mesh, table_material, table_transform);

        EndMode3D();
        DrawText("Is This a robot?", 300, 100, 12, RED);
        EndDrawing();

    }

    UnloadMaterial(table_material);
    UnloadMesh(table_mesh);
    CloseWindow();

    return 0;

}