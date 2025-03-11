#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "texture");
    Texture2D scarfy = LoadTexture("assets/scarfy.png");
    int frameWidth = scarfy.width/6;
    int frameHeight = scarfy.height;
    Rectangle sourceRec = { 3*(float)frameWidth, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, frameWidth*1.0f, frameHeight*1.0f };
    Vector2 origin = { (float)frameWidth, (float)frameHeight };

    int rotation = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //{ Update
        rotation++;
        //}
        //{ Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexturePro(scarfy, sourceRec, destRec, origin, (float)rotation, WHITE);

        /*
        DrawLine((int)destRec.x, 0, (int)destRec.x, screenHeight, GRAY);
        DrawLine(0, (int)destRec.y, screenWidth, (int)destRec.y, GRAY);
        */

        DrawText("Hello there!", screenWidth - 200, screenHeight - 20, 10, LIGHTGRAY);

        EndDrawing();
        //}
    }

    UnloadTexture(scarfy);

    CloseWindow();

    return 0;
}
