#ifndef C_SNAKE_GAME_UPDATER_H
#define C_SNAKE_GAME_UPDATER_H

#include "updater/updater_defs.h"

struct updater;

struct updater_vtable {
    int (*init)(struct updater *self);
    int (*update)(struct updater *self, struct point_2d p, enum cell_type new_type);
    int (*shutdown)(struct updater *self);
};

#endif // C_SNAKE_GAME_UPDATER_H
