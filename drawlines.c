#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Draw a line or two");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(256, 256, 123, GREEN);
        DrawLine(0, 0, GetMouseX(), GetMouseY(), RED);
        DrawLine(GetScreenWidth(), 0, GetMouseX(), GetMouseY(), GREEN);
        DrawLine(GetScreenWidth(), GetScreenHeight(), GetMouseX(), GetMouseY(), BLUE);
        DrawLine(0, GetScreenHeight(), GetMouseX(), GetMouseY(), BLACK);
        DrawFPS(10, 10);
        DrawPixel(10, 256, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
