#ifndef C_SNAKE_GAME_UPDATER_DEFS_H
#define C_SNAKE_GAME_UPDATER_DEFS_H

#include "base/base_defs.h"

#define GRID_WIDTH 20
#define GRID_HEIGHT 20
#define START_SNAKE_LENGTH 4

enum cell_type {
    CELL_EMPTY = 0, // 0 is used for renderer's clear and create functions
    CELL_SNAKE_HEAD,
    CELL_SNAKE_BODY,
    CELL_FOOD,
    CELL_WALL,
    CELL_COUNT // Bounds check
};

struct point_2d {
    u32 x;
    u32 y;
};

#endif // C_SNAKE_GAME_UPDATER_DEFS_H
