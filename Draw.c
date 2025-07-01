#include "base.h"
#include "consol.h"
void DrawMap()
{
    for (int y = 0; y < MAX_Y; y++)
    {
        for (int x = 0; x < MAX_X; x++)
        {
            if (y == 0 || y == MAX_Y - 1 || x == 0 || x == MAX_X - 1)
            {
                MoveXY(x, y);
                printf("#");
            }
        }
    }
}

void DrawSnake()
{
    for (int i = 0; i < snake_length; i++)
    {
        MoveXY(snake_body[i][0], snake_body[i][1]);
        if (i == 0) printf("@");
        else printf("o");
    }
}

void DrawAISnake()
{
    for (int i = 0; i < ai_length; i++)
    {
        MoveXY(ai_body[i][0], ai_body[i][1]);
        if (i == 0) printf("X");
        else printf("x");
    }
}

void UpdateSnake() {
    for (int i = snake_length; i > 0; i--) {
        snake_body[i][0] = snake_body[i - 1][0];
        snake_body[i][1] = snake_body[i - 1][1];
    }
    snake_body[0][0] += dx;
    snake_body[0][1] += dy;
}

void UpdateAI() {
    int head_x = ai_body[0][0];
    int head_y = ai_body[0][1];

    if (food_x < head_x) { ai_dx = -1; ai_dy = 0; }
    else if (food_x > head_x) { ai_dx = 1; ai_dy = 0; }
    else if (food_y < head_y) { ai_dx = 0; ai_dy = -1; }
    else if (food_y > head_y) { ai_dx = 0; ai_dy = 1; }

    for (int i = ai_length; i > 0; i--) {
        ai_body[i][0] = ai_body[i - 1][0];
        ai_body[i][1] = ai_body[i - 1][1];
    }

    ai_body[0][0] += ai_dx;
    ai_body[0][1] += ai_dy;
}


void DrawFood()
{
    MoveXY(food_x, food_y);
    printf("*");
}