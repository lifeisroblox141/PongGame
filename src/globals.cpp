#include "./globals.hpp"

const Rectangle wall[] = {
    {0.0f, -WALL_OFFSET, SCREEN_WIDTH, WALL_HEIGHT},
    {0.0f, SCREEN_HEIGHT - WALL_HEIGHT + WALL_OFFSET, SCREEN_WIDTH,
     WALL_HEIGHT},
    {-WALL_OFFSET, 0.0f, WALL_WIDTH, SCREEN_HEIGHT},
    {SCREEN_WIDTH - WALL_OFFSET / 2.0f, 0.0f, WALL_WIDTH, SCREEN_HEIGHT}};

const std::string application_dir = GetApplicationDirectory();
bool game_resetted = false;
int plr1_score = 0;
int plr2_score = 0;
