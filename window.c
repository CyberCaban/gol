#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#define WIDTH 1280
#define HEIGHT 720

typedef struct {
    int centerX;
    int centerY;
    float radius;
} Circle;

void DrawCircleCircle(Circle circle, Color color){
    DrawCircle(circle.centerX, circle.centerY, circle.radius, color);
}

void InputRange(double *state, int posX, int posY, double width, int min, int max){
    static int focus = 0;
    const double height = 5;
    const double offset = 30;
    double circlePosX;

    if(*state < min) 
        circlePosX = posX + 1;
    else if(*state > max) 
        circlePosX = posX + width - 1;
    else 
        circlePosX = (*state - min) / (max - min) * width - 1 + posX;
        
    Rectangle rect = {posX, posY, width, height};
    Circle circle = {circlePosX, posY + height / 2, height * 2};

    DrawRectangleRec(rect, BLACK);
    DrawCircleCircle(circle, LIGHTGRAY);

    double newState = (GetMouseX() - posX + 1) / width * (max - min) + min;

    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
        if(CheckCollisionPointRec(GetMousePosition(), 
            (Rectangle){ 
                .width = rect.width, 
                .height = rect.height + offset, 
                .x = rect.x, 
                .y = rect.y - offset / 2
            }))
        {
            focus = 1;
        }
    } else {
        focus = 0;
    }

    if(focus){
        if (newState < min) *state = min;
        else if (newState > max) *state = max;
        else *state = newState;
    }
}

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(WIDTH, HEIGHT, "hello world");

    Camera2D camera = {0, .zoom = 1.0f};
    SetTargetFPS(120);

    double state = 120;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(RAYWHITE);
                DrawCircle(GetMouseX(), GetMouseY(), 40, MAROON);
                DrawText("state: ", 10, 10, 20, BLACK);
                DrawText(TextFormat("%d", (int)state), 80, 10, 20, BLACK);
                InputRange(&state, 10, 50, 150, -10, 27);
                
            EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
