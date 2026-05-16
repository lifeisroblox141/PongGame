#include <raylib.h>

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480

#define WALL_WIDTH 15
#define WALL_HEIGHT 15
#define WALL_OFFSET 10

#define N_WALL 4
#define WALL_TOP 0
#define WALL_BOTTOM 1
#define WALL_LEFT 2
#define WALL_RIGHT 3

extern const Rectangle wall[N_WALL];

#endif
