#include <stdio.h>
#include "raylib.h"

// TODO: slow down my snake!

#define SQUARE_SIZE      51
#define SNAKE_LENGTH    256

typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

static const int screenWidth = 800;
static const int screenHeight = 450;

static int frameCounter = 0;
static bool gameOver = false;
static bool pause = false;
static double speed = 13;

static Snake snake[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;
static Food fruit = { 0 };

// Declarations
void InitGame(void);
void DrawMyGrids(void);
void DrawFruit(void);
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
    }

    CloseWindow();

    printf("speed = %.02f", speed);

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
        // Start position
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        //snake[i].position = (Vector2){ SQUARE_SIZE + offset.x/2, SQUARE_SIZE + offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        //snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };
        if (i == 0) snake[i].color = BLACK;
        else if (i%2 == 0) snake[i].color = BLUE;
        else snake[i].color = GREEN;
    }

    for (int i = 0; i < SNAKE_LENGTH; i++) {
        snakePosition[i] = (Vector2){ -100.0f, -100.0f };
    }

    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = YELLOW;
    fruit.active = false;
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
    DrawText(TextFormat("%d", counterTail), snake[0].position.x, snake[0].position.y, 25, RED);
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
            //{ Grow
            if (IsKeyPressed(KEY_G))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
            }
            //}
            //{ Snake movement
            if ((frameCounter%((int)speed)) == 0) {
                for (int i = 0; i < counterTail; i++)
                    snakePosition[i] = snake[i].position;

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
                snake[0].position.x = 3 * SQUARE_SIZE + offset.x/2;
                snake[0].position.y = 7 * SQUARE_SIZE + offset.y/2;
            } else
                snake[0].color = BLACK;
            //}
            //{ Fruit position calculations
            if (!fruit.active)
            {
                fruit.active = true;
                fruit.position = (Vector2){
                    GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2,
                    GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2
                };

                for (int i = 0; i < counterTail; i++)
                {
                    while ((fruit.position.x == snake[i].position.x) && (fruit.position.y == snake[i].position.y))
                    {
                        fruit.position = (Vector2){
                            GetRandomValue(0, (screenWidth/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.x/2,
                            GetRandomValue(0, (screenHeight/SQUARE_SIZE) - 1)*SQUARE_SIZE + offset.y/2
                        };
                    }
                }
            }
            //}
            //{ Collision
            if ((snake[0].position.x < (fruit.position.x + fruit.size.x) && (snake[0].position.x + snake[0].size.x) > fruit.position.x) &&
                    (snake[0].position.y < (fruit.position.y + fruit.size.y) && (snake[0].position.y + snake[0].size.y) > fruit.position.y))
            {
                snake[counterTail].position = snakePosition[counterTail - 1];
                counterTail += 1;
                fruit.active = false;
                speed -= 0.25;
                if (speed <= 1) speed = 1;
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
        DrawFruit();
        DrawSnake();

        // Display PAUSED in the centre of the screen
        if (pause) DrawText("PAUSED", screenWidth/2 - MeasureText("PAUSED", 40)/2, screenHeight/2 - 40, 40, PINK);
    }
    DrawFPS(10, 10);

    EndDrawing();
}

void DrawFruit(void)
{
    DrawRectangleV(fruit.position, fruit.size, fruit.color);
    DrawCircle(fruit.position.x + SQUARE_SIZE/2, fruit.position.y + SQUARE_SIZE/2, SQUARE_SIZE/4, GREEN);
}
