#include "elements.h"

#define WIDTH 1280
#define HEIGHT 720

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
