#include "raylib.h"

// TODO: slow down my snake!

#define SQUARE_SIZE      31
#define SNAKE_LENGTH    256
#define SPEED            10

typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

static const int screenWidth = 800;
static const int screenHeight = 450;

static int frameCounter = 0;
static bool gameOver = false;
static bool pause = false;

static Snake snake[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;

// Declarations
void InitGame(void);
void DrawMyGrids(void);
void DrawSnake(void);
void UpdateGame(void);
void DrawGame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Draw a grid");
    InitGame();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
        DrawFPS(10, 10);
    }

    CloseWindow();

    return 0;
}

void InitGame(void)
{
    frameCounter = 0;
    gameOver = false;
    pause = false;
    counterTail = 1;
    allowMove = false;
    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        //snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        snake[i].color = BLUE;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snakePosition[i] = (Vector2){ 0.0f, 0.0f };
    }
}

void DrawMyGrids(void)
{
    for (int i = 0; i < screenWidth/SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){SQUARE_SIZE*i + offset.x/2, offset.y/2}, (Vector2){SQUARE_SIZE*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }
    for (int i = 0; i < screenHeight/SQUARE_SIZE + 1; i++) {
        DrawLineV((Vector2){offset.x/2, SQUARE_SIZE*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, SQUARE_SIZE*i + offset.y/2}, LIGHTGRAY);
    }
}

void DrawSnake(void)
{
    for (int i = 0; i < counterTail; i++) {
        DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);
    }
}

void UpdateGame(void)
{
    if (!gameOver) {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause) {
            //snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
            if (IsKeyPressed(KEY_LEFT)) snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
            if (IsKeyPressed(KEY_RIGHT)) snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
            if (IsKeyPressed(KEY_UP)) snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
            if (IsKeyPressed(KEY_DOWN)) snake[0].speed = (Vector2){ 0, SQUARE_SIZE };

            //{ Snake movement
            if (frameCounter%SPEED == 0) {
                for (int i = 0; i < counterTail; i++) snakePosition[i] = snake[i].position;

                for (int i = 0; i < counterTail; i++) {
                    if (i == 0) {
                        snake[0].position.x += snake[0].speed.x;
                        snake[0].position.y += snake[0].speed.y;
                        allowMove = true;
                    } else {
                        snake[i].position = snakePosition[i-1];
                    }
                }
            }
            //}
            //{ Walls
            if ((snake[0].position.x > screenWidth - offset.x) ||
               (snake[0].position.x < 0) ||
               (snake[0].position.y > screenHeight - offset.y) ||
               (snake[0].position.y < 0))
            {
                snake[0].color = YELLOW;
                snake[0].position.x = offset.x/2;
                snake[0].position.y = offset.y/2;
            } else
                snake[0].color = GREEN;
            //}
            //{ Grow
            if (IsKeyPressed(KEY_G))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
            }
            //}

            frameCounter++;
        }
    }
}

void DrawGame(void)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (!gameOver)
    {
        DrawMyGrids();
        DrawSnake();
    }

    EndDrawing();
}
