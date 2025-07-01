#include "base.h"

void ConsoleView()
{
    system("mode con:cols=50 lines=25");
    system("title Snake vs AI");
}

void MoveXY(int x, int y)
{
    COORD pos;
    pos.X = 2 * x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo); // 현재 커서 정보 가져오기
    cursorInfo.bVisible = FALSE;                 // 커서 표시 안 함
    SetConsoleCursorInfo(hConsole, &cursorInfo); // 변경된 설정 적용
}