#ifndef C_SNAKE_GAME_RENDERER_TUI_H
#define C_SNAKE_GAME_RENDERER_TUI_H

#include "renderer/renderer.h"
#include "updater/updater_defs.h"

#define TUI_WIDTH (GRID_WIDTH * 3)
#define TUI_HEIGHT (GRID_HEIGHT)

int renderer_tui_create(Renderer *r);

#endif // C_SNAKE_GAME_RENDERER_TUI_H