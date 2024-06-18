#include "elements.h"

#define FACTOR 90 
#define WIDTH FACTOR*16
#define HEIGHT FACTOR*9

int main()
{
    int screenWidth = WIDTH;
    int screenHeight = HEIGHT;
    FilePathList files;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(screenWidth, screenHeight, "hello world");

    Image img;
    Texture2D tex;

    SetTargetFPS(120);

    double rotate = 120;
    double scale = 100.f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            rlPushMatrix();
                rlTranslatef(screenWidth/2, screenHeight/2, 0);
                rlRotatef(rotate, 0, 0, 1);
                rlScalef((scale/100), (scale/100), 1);

                DrawRectangle(-25, -25, 50, 50, RED);

                DrawTexture(tex, -tex.width/2, -tex.height/2, WHITE);

                DrawRectangle(0, 0, 2, 200, GREEN);
            rlPopMatrix();
            DrawCircle(GetMouseX(), GetMouseY(), 20, MAROON);

            {
                DrawText("Rotate Degrees: ", 10, 10, 20, BLACK);
                DrawText(TextFormat("%d", (int)rotate), 190, 10, 20, BLACK);
                InputRange(&rotate, 10, 50, 300, 0, 360, 0);
            }

            {
                DrawText("Scale: ", 10, 100, 20, BLACK);
                DrawText(TextFormat("%3.f", scale), 70, 100, 20, BLACK);
                InputRange(&scale, 10, 120, 300, 0, 300, 1);
            }
        EndDrawing();


        if (IsFileDropped()){
            files = LoadDroppedFiles();
            if (files.count > 0){
                for (size_t i = 0; i < files.count; i++)
                {
                    // DrawText(files.paths[i], 10, screenHeight/2 + 20*i, 20, BLACK);
                    printf("File dropped: %d\n", files.count);
                    img = LoadImage(files.paths[i]);
                    tex = LoadTextureFromImage(img);
                    UnloadImage(img);
                }
            }
            UnloadDroppedFiles(files);
        }

        // if (IsKeyPressed(KEY_Q)){
        //     UnloadTexture(tex);
        // }

        if(IsWindowResized()){
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }
    }
    
    UnloadTexture(tex);
    CloseWindow();
    return 0;
}
