#ifndef C_SNAKE_GAME_UPDATER_H
#define C_SNAKE_GAME_UPDATER_H

#include "base/base_defs.h"
#include "updater/updater_defs.h"

typedef struct Updater Updater;

typedef struct UpdaterOps {
    int (*init)(Updater *self);
    int (*update)(Updater *self, u32 x, u32 y, u8 cell_type);
    int (*shutdown)(Updater *self);
} UpdaterOps;

#endif // C_SNAKE_GAME_UPDATER_H