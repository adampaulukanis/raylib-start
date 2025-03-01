#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    InitWindow(800, 450, "Play 1");
    SetTargetFPS(60);

    if (!IsWindowReady()) {
        printf("Error: window is not ready\n");
        exit(1);
    }
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello there!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
