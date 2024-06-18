#include "elements.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
    int centerX;
    int centerY;
    float radius;
} Circle;

void DrawCircleCircle(Circle circle, Color color){
    DrawCircle(circle.centerX, circle.centerY, circle.radius, color);
}

int every(int* arr){
    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        if(arr[i] == 1) return 0;
    }
    return 1;
}

static bool ranges[100] = {0};

void InputRange(double *state, int posX, int posY, double width, int min, int max, int id){
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

    double newState = (GetMouseX() - posX + 1) / width * (max - min) + min;

    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
        if(CheckCollisionPointRec(GetMousePosition(), 
            (Rectangle){ 
                .width = rect.width, 
                .height = rect.height + offset, 
                .x = rect.x, 
                .y = rect.y - offset / 2
            }) && every(ranges))
        {
            ranges[id] = 1;
        }
    } else {
        ranges[id] = 0;
    }

    DrawRectangleRec(rect, BLACK);
    if(ranges[id]){
        DrawRectangleRec(rect, (Color){100, 100, 100, 255});
        if (newState < min) *state = min;
        else if (newState > max) *state = max;
        else *state = newState;
    }
    DrawCircleCircle(circle, LIGHTGRAY);
}