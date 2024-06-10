#include "elements.h"

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