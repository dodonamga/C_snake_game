#include "base.h"

// 전역 변수 실제 정의
int snake_body[MAX_LENGTH][2];
int snake_length = 1;
int dx = 1, dy = 0;

int ai_body[MAX_LENGTH][2];
int ai_length = 1;
int ai_dx = 0, ai_dy = 1;

int food_x, food_y;

int delay_ms = 160;