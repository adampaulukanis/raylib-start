#include "raylib.h"
#include <stdio.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "x1");
    Texture2D player_big = LoadTexture("assets/player_big.png");
    int frameWidth = player_big.width/10;
    int frameHeight = player_big.height;

    SetTargetFPS(60);

    int counter = 0;

    while (!WindowShouldClose())
    {
        //{ Update
        printf("counter=%d\n", counter++);
        //}
        //{ Draw
        if (counter < 10) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTexture(player_big, (counter*frameWidth)/screenWidth, (counter*frameHeight)/screenHeight, RED);
            DrawTexture(player_big, frameWidth, frameHeight, GREEN);

            /*
               DrawLine((int)destRec.x, 0, (int)destRec.x, screenHeight, GRAY);
               DrawLine(0, (int)destRec.y, screenWidth, (int)destRec.y, GRAY);
               */

            DrawText("Hello there!", screenWidth - 200, screenHeight - 20, 10, LIGHTGRAY);

            EndDrawing();
        }
        //}
    }

    UnloadTexture(player_big);

    CloseWindow();

    return 0;
}
