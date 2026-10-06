#ifndef C_SNAKE_GAME_RENDERER_H
#define C_SNAKE_GAME_RENDERER_H

#include "updater/updater_defs.h"

struct renderer;

struct renderer_vtable {
    int (*init)(struct renderer *self);
    int (*set_cell)(struct renderer *self, struct point_2d p, enum cell_type new_type);
    int (*render)(struct renderer *self);
    int (*clear)(struct renderer *self);
    int (*shutdown)(struct renderer *self);
};

struct renderer {
    const struct renderer_vtable *vtable;
    void *impl; // Implementation-specific struct
};

// To be called once before the game loop starts
static inline int renderer_init(struct renderer *r)
{
    return (r && r->vtable && r->vtable->init) ? r->vtable->init(r) : -1;
}

// Update the internal buffer for a single cell
static inline int renderer_set_cell(struct renderer *r, struct point_2d p, enum cell_type new_type)
{
    return (r && r->vtable && r->vtable->set_cell) ? r->vtable->set_cell(r, p, new_type) : -1;
}

// Visualize current state
static inline int renderer_render(struct renderer *r)
{
    return (r && r->vtable && r->vtable->render) ? r->vtable->render(r) : -1;
}

// Reset visualization
static inline int renderer_clear(struct renderer *r)
{
    return (r && r->vtable && r->vtable->clear) ? r->vtable->clear(r) : -1;
}

/// To be called once before the exit
static inline int renderer_shutdown(struct renderer *r)
{
    return (r && r->vtable && r->vtable->shutdown) ? r->vtable->shutdown(r) : -1;
}

#endif // C_SNAKE_GAME_RENDERER_H
