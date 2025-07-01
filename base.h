#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#define MAX_LENGTH 100
#define MAX_X 22
#define MAX_Y 22

// 전역 변수들 — 선언만 (extern)
extern int snake_body[MAX_LENGTH][2];
extern int snake_length;
extern int dx, dy;
extern int delay_ms;

extern int ai_body[MAX_LENGTH][2];
extern int ai_length;
extern int ai_dx, ai_dy;

extern int food_x, food_y;

#endif