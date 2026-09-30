#include "renderer/renderer_tui.h"
#include "base/base_defs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char CELL_MAP[CELL_COUNT] = {
    [CELL_EMPTY] = ' ',
    [CELL_SNAKE_HEAD] = 'O',
    [CELL_SNAKE_BODY] = 'o',
    [CELL_FOOD] = '*',
    [CELL_WALL] = '#',
};

typedef struct {
    CellType grid[TUI_HEIGHT][TUI_WIDTH];
} TuiData;

static TuiData s_tui_data;

static int tui_init(Renderer *self)
{
    if (!self) {
        return -1;
    }

    if (self->impl) {
        return 0;
    }

    self->impl = &s_tui_data;

    // Clean grid and terminal
    self->ops->clear(self);
    fputs("\033[2J\033[H", stdout);

    return 0;
}

static int tui_draw_cell(Renderer *self, u32 x, u32 y, u8 cell_type)
{
    TuiData *data = (TuiData *)self->impl;

    if (x >= GRID_WIDTH || y >= GRID_HEIGHT) {
        return -1;
    }

    data->grid[y][x * 3] = (CellType)CELL_EMPTY;
    data->grid[y][(x * 3) + 1] = (CellType)cell_type;
    data->grid[y][(x * 3) + 2] = (CellType)CELL_EMPTY;

    return 0;
}

static int tui_render(Renderer *self)
{
    if (!self || !self->impl)
        return -1;

    TuiData *data = (TuiData *)self->impl;

    fputs("\033[H", stdout);

    for (u32 y = 0; y < TUI_HEIGHT; ++y) {
        for (u32 x = 0; x < TUI_WIDTH; ++x) {
            putchar(CELL_MAP[data->grid[y][x]]);
        }
        putchar('\n');
    }

    fflush(stdout);

    return 0;
}

static int tui_clear(Renderer *self)
{
    if (!self || !self->impl)
        return -1;

    TuiData *data = (TuiData *)self->impl;

    memset(data->grid, CELL_EMPTY, sizeof(data->grid));

    return 0;
}

static int tui_shutdown(Renderer *self)
{
    if (!self) {
        return -1;
    }

    if (!self->impl) {
        return 0;
    }

    self->impl = NULL;

    return 0;
}

static const RendererOps TUI_OPS = {
    .init = tui_init,
    .draw_cell = tui_draw_cell,
    .render = tui_render,
    .clear = tui_clear,
    .shutdown = tui_shutdown,
};

int renderer_tui_create(Renderer *r)
{
    memset(r, 0, sizeof(Renderer));
    r->ops = &TUI_OPS;

    return 0;
}