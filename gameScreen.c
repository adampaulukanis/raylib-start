#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define TWOSECONDS 120

typedef enum GameScreen {
    LOGO = 0,
    TITLE,
    GAMEPLAY,
    ENDING
} GameScreen;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Hello");
    GameScreen currentScreen = LOGO;
    size_t framesCounter = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update
        framesCounter++;
        size_t s = framesCounter / 60;
        printf("%ld, s=%ld\n", framesCounter, s);
        switch(currentScreen) {
            case LOGO:
            {
                if (framesCounter > TWOSECONDS) {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
            }
            default: break;
        }
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch(currentScreen) {
            case LOGO:
            {
                DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
            } break;
            case TITLE:
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                DrawText("TITLe SCREEN", 290, 220, 20, GRAY);
            } break;
            default: break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
