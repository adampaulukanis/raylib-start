#include <stdio.h>
#include "raylib.h"

int main(void)
{
    printf("Hello...\n");
    InitWindow(800, 460, "Hello basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You are *jesiotr*", 400, 230, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
