#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "player_big");
    Texture2D player_big = LoadTexture("assets/player_big.png");
    int frameWidth = player_big.width/10;
    int frameHeight = player_big.height;
    Rectangle destRec = { frameWidth, frameHeight, frameWidth*1.0f, frameHeight*1.0f };
    Vector2 origin = { (float)frameWidth, (float)frameHeight };

    int rotation = 0;
    int dir = 1;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //{ Update
        if (IsKeyDown(KEY_UP)) rotation++;
        if (IsKeyDown(KEY_DOWN)) rotation--;
        if (rotation > 10) rotation = 0;
        if (rotation < 0) rotation = 10;

        if (IsKeyDown(KEY_RIGHT)) dir = 1;
        if (IsKeyDown(KEY_LEFT)) dir = -1;
        //}
        //{ Draw
        Rectangle sourceRec = { rotation*(float)frameWidth, 0.0f, dir*(float)frameWidth, (float)frameHeight };
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexturePro(player_big, sourceRec, destRec, origin, 0, WHITE);

        /*
        DrawLine((int)destRec.x, 0, (int)destRec.x, screenHeight, GRAY);
        DrawLine(0, (int)destRec.y, screenWidth, (int)destRec.y, GRAY);
        */

        DrawText("Hello there!", screenWidth - 200, screenHeight - 20, 10, LIGHTGRAY);

        EndDrawing();
        //}
    }

    UnloadTexture(player_big);

    CloseWindow();

    return 0;
}
