#include "raylib.h"
#include "raymath.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Simple 3D Robot - raylib");
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = Vector3{ 6.0f, 6.0f, 10.0f };
    camera.target   = Vector3{ 0.0f, 2.0f, 0.0f };
    camera.up       = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Robot dimensions
    const float baseRadius   = 0.8f;
    const float rod1Length   = 2.5f;
    const float rod2Length   = 2.0f;
    const float rod3Length   = 1.0f;
    const float rodRadius    = 0.15f;
    const float jointRadius  = 0.35f;
    const float smallRodRadius = 0.10f;

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_PERSPECTIVE);

        // --- Robot layout in world space ---
        // Base centered at origin
        Vector3 baseCenter = { 0.0f, baseRadius, 0.0f };

        // First rod goes upward from top of base
        Vector3 rod1Start = { 0.0f, baseCenter.y + baseRadius, 0.0f };
        Vector3 rod1End   = { 0.0f, rod1Start.y + rod1Length, 0.0f };

        // Joint 1 at end of rod 1
        Vector3 joint1Center = rod1End;

        // Second rod angled in +X and +Y direction
        Vector3 rod2Dir = Vector3Normalize(Vector3{ 1.0f, 0.7f, 0.0f });
        Vector3 rod2End = Vector3Add(joint1Center, Vector3Scale(rod2Dir, rod2Length));

        // Joint 2 at end of rod 2
        Vector3 joint2Center = rod2End;

        // Final short rod angled further
        Vector3 rod3Dir = Vector3Normalize(Vector3{ 0.7f, 0.5f, 0.4f });
        Vector3 rod3End = Vector3Add(joint2Center, Vector3Scale(rod3Dir, rod3Length));

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        // Base sphere
        DrawSphere(baseCenter, baseRadius, DARKGRAY);

        // Rod 1 (vertical cylinder)
        DrawCylinderEx(rod1Start, rod1End, rodRadius, rodRadius, 16, BLUE);

        // Joint 1
        DrawSphere(joint1Center, jointRadius, RED);

        // Rod 2
        DrawCylinderEx(joint1Center, rod2End, rodRadius, rodRadius, 16, GREEN);

        // Joint 2
        DrawSphere(joint2Center, jointRadius, ORANGE);

        // Rod 3
        DrawCylinderEx(joint2Center, rod3End, smallRodRadius, smallRodRadius, 16, PURPLE);

        EndMode3D();

        DrawText("Simple 3D robot arm", 20, 20, 24, BLACK);
        DrawText("Mouse drag / orbital camera enabled", 20, 50, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}