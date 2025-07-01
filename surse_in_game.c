#include "base.h"
void UpdateSnake(void);
void UpdateAI(void);

void select_speed()
{
    system("cls");
    printf("=== Select Snake Game Speed ===\n");
    printf("1. Slow   (Easy)\n");
    printf("2. Normal (Medium)\n");
    printf("3. Fast   (Hard)\n");
    printf("Choose a speed (1-3): ");

    int input = 0;
    while (input < 1 || input > 3)
    {
        input = _getch() - '0';
    }

    switch (input)
    {
    case 1: delay_ms = 200; break;
    case 2: delay_ms = 120; break;
    case 3: delay_ms = 60; break;
    }

    system("cls");
}

void GetKeyInput()
{
    if (_kbhit())
    {
        char key = _getch();

        // 방향 변경을 위해 임시 값 사용
        int new_dx = dx;
        int new_dy = dy;

        switch (key)
        {
        case 'w':
        case 'W':
        case 72:  // 위쪽 화살표
            new_dx = 0;
            new_dy = -1;
            break;
        case 's':
        case 'S':
        case 80:  // 아래쪽 화살표
            new_dx = 0;
            new_dy = 1;
            break;
        case 'a':
        case 'A':
        case 75:  // 왼쪽 화살표
            new_dx = -1;
            new_dy = 0;
            break;
        case 'd':
        case 'D':
        case 77:  // 오른쪽 화살표
            new_dx = 1;
            new_dy = 0;
            break;
        default:
            return;  // 다른 키는 무시
        }

        // 몸통이 2 이상일 때만 반대 방향 막기
        if (snake_length >= 2)
        {
            // 현재 방향의 정반대인지 검사
            if (new_dx == -dx && new_dy == -dy)
            {
                return;  // 반대 방향은 무시
            }
        }

        // 정상적인 방향이면 적용
        dx = new_dx;
        dy = new_dy;
    }
}

bool IsCollisionPlayer()
{
    int x = snake_body[0][0];
    int y = snake_body[0][1];
    if (x <= 0 || x >= MAX_X - 1 || y <= 0 || y >= MAX_Y - 1) return true;

    for (int i = 1; i < snake_length; i++)
        if (snake_body[i][0] == x && snake_body[i][1] == y) return true;

    for (int i = 0; i < ai_length; i++)
        if (ai_body[i][0] == x && ai_body[i][1] == y) return true;

    return false;
}

bool IsCollisionAI()
{
    int x = ai_body[0][0];
    int y = ai_body[0][1];
    if (x <= 0 || x >= MAX_X - 1 || y <= 0 || y >= MAX_Y - 1) return true;

    for (int i = 1; i < ai_length; i++)
        if (ai_body[i][0] == x && ai_body[i][1] == y) return true;

    for (int i = 0; i < snake_length; i++)
        if (snake_body[i][0] == x && snake_body[i][1] == y) return true;

    return false;
}

void GenerateFood()
{
    while (1)
    {
        food_x = rand() % (MAX_X - 2) + 1;
        food_y = rand() % (MAX_Y - 2) + 1;

        bool overlap = false;
        for (int i = 0; i < snake_length; i++)
            if (snake_body[i][0] == food_x && snake_body[i][1] == food_y)
                overlap = true;

        for (int i = 0; i < ai_length; i++)
            if (ai_body[i][0] == food_x && ai_body[i][1] == food_y)
                overlap = true;

        if (!overlap) break;
    }
}