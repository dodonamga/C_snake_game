#include "base.h"
#include "Draw.h"
#include "consol.h"
#include "surse_in_game.h"

void start_game()
{
    while (1)
    {
        select_speed();
        srand((unsigned)time(NULL));
        ConsoleView();
        HideCursor();

        snake_length = 1;
        ai_length = 1;

        snake_body[0][0] = 5;
        snake_body[0][1] = 5;
        ai_body[0][0] = 15;
        ai_body[0][1] = 15;
        GenerateFood();

        // 방향 초기화
        dx = 1;
        dy = 0;

        while (1)
        {
            GetKeyInput();
            UpdateSnake();
            UpdateAI();

            if (IsCollisionPlayer())
            {
                MoveXY(3, 10);
                printf("Game Over! You Lost.");
                MoveXY(2, 12);
                system("pause");
                break;
            }

            if (IsCollisionAI())
            {
                MoveXY(3, 10);
                printf("You Win! AI Crashed.");
                MoveXY(2, 12);
                system("pause");
                break;
            }

            if (snake_body[0][0] == food_x && snake_body[0][1] == food_y)
            {
                if (snake_length < MAX_LENGTH)
                    snake_length++;
                GenerateFood();
            }
            else if (ai_body[0][0] == food_x && ai_body[0][1] == food_y)
            {
                if (ai_length < MAX_LENGTH)
                    ai_length++;
                GenerateFood();
            }

            system("cls");
            DrawMap();
            DrawFood();
            DrawSnake();
            DrawAISnake();

            Sleep(delay_ms);
        }

        char choice = 0;
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            MoveXY(2, 14);
            printf("Do you want to play again? (Y/N): ");
            choice = _getch();
        }

        if (choice == 'N' || choice == 'n')
        {
            break; // 게임 종료
        }
        system("cls");
    }
    return;
}