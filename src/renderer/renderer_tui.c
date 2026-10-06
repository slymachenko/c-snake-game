#include "renderer/renderer_tui.h"
#include "base/base_defs.h"
#include "renderer/renderer.h"

#include <stdio.h>
#include <string.h>

static const char CELL_MAP[CELL_COUNT] = {
    [CELL_EMPTY] = ' ',
    [CELL_SNAKE_HEAD] = 'O',
    [CELL_SNAKE_BODY] = 'o',
    [CELL_FOOD] = '*',
    [CELL_WALL] = '#',
};

static struct tui_impl {
    enum cell_type grid[TUI_HEIGHT][TUI_WIDTH];
} s_tui_impl;

static const struct renderer_vtable TUI_RENDERER_VTABLE;

static int tui_init(struct renderer *self)
{
    // Assign implementation
    if (self->impl)
        return 0;

    self->impl = &s_tui_impl;

    // Clear grid and terminal
    self->vtable->clear(self);
    if (fputs("\033[2J\033[H", stdout) == EOF)
        return -1;

    return 0;
}

static int tui_set_cell(struct renderer *self, struct point_2d p, enum cell_type new_type)
{
    struct tui_impl *data = (struct tui_impl *)self->impl;

    if (p.x >= GRID_WIDTH || p.y >= GRID_HEIGHT)
        return -1;

    size_t x_offset = (size_t)p.x * 3;
    size_t y_offset = (size_t)p.y;

    data->grid[y_offset][x_offset] = (enum cell_type)CELL_EMPTY;
    data->grid[y_offset][x_offset + 1] = (enum cell_type)new_type;
    data->grid[y_offset][x_offset + 2] = (enum cell_type)CELL_EMPTY;

    return 0;
}

static int tui_render(struct renderer *self)
{
    if (!self || !self->impl)
        return -1;

    struct tui_impl *data = (struct tui_impl *)self->impl;

    if (fputs("\033[H", stdout) == EOF)
        return -1;

    for (u32 y = 0; y < TUI_HEIGHT; ++y) {
        for (u32 x = 0; x < TUI_WIDTH; ++x)
            putchar(CELL_MAP[data->grid[y][x]]);
        putchar('\n');
    }

    if (fflush(stdout) != 0)
        return -1;

    return 0;
}

static int tui_clear(struct renderer *self)
{
    if (!self || !self->impl)
        return -1;

    struct tui_impl *data = (struct tui_impl *)self->impl;

    memset(data->grid, 0, sizeof(data->grid));

    return 0;
}

static int tui_shutdown(struct renderer *self)
{
    if (!self)
        return -1;

    if (!self->impl)
        return 0;

    self->impl = NULL;

    return 0;
}

static const struct renderer_vtable TUI_RENDERER_VTABLE = {
    .init = tui_init,
    .set_cell = tui_set_cell,
    .render = tui_render,
    .clear = tui_clear,
    .shutdown = tui_shutdown,
};

int tui_renderer_create(struct renderer *self)
{
    memset(self, 0, sizeof(struct renderer));

    self->vtable = &TUI_RENDERER_VTABLE;
    return 0;
}
