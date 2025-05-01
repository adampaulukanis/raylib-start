#include "raylib.h"

#define SQUARE_SIZE      31
#define SNAKE_LENGTH    256

typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

static const int screenWidth = 800;
static const int screenHeight = 450;

static Vector2 offset = { 0 };
static Snake snake[SNAKE_LENGTH] = { 0 };
static int counterTail = 0;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Draw a grid");
    SetTargetFPS(60);

    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    counterTail = 1;
    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        snake[i].color = BLUE;
    }

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++) {
            DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
        }
        for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++) {
            DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
        }

        for (int i = 0; i < counterTail; i++) {
            DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
