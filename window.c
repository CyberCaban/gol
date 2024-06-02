#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#define WIDTH 640
#define HEIGHT 480

int main()
{
    InitWindow(WIDTH, HEIGHT, "hello world");

    Camera2D camera = {0, .zoom = 1.0f};
    SetTargetFPS(120);
     

    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        DrawCircle(GetMouseX(), GetMouseY(), 40, MAROON);
        rlPushMatrix();
        Rectangle rec = {100, 100, 100, 100};
        rlRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        DrawRectangle(rec.x, rec.y, rec.width, rec.height, BLUE);
        // rlTranslatef(GetScreenWidth()/2, GetScreenHeight()/2, 0.0f);
        rlPopMatrix();

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
