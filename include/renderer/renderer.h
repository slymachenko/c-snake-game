#ifndef C_SNAKE_GAME_RENDERER_H
#define C_SNAKE_GAME_RENDERER_H

#include "base/base_defs.h"
#include "updater/updater_defs.h"

typedef struct Renderer Renderer;

typedef struct RendererOps {
    int (*init)(Renderer *self);
    int (*draw_cell)(Renderer *self, u32 x, u32 y, u8 cell_type);
    int (*render)(Renderer *self);
    int (*clear)(Renderer *self);
    int (*shutdown)(Renderer *self);
} RendererOps;

struct Renderer {
    const RendererOps *ops;
    void *impl;
};

static inline int renderer_init(Renderer *r)
{
    return (r && r->ops && r->ops->init) ? r->ops->init(r) : -1;
}

static inline int renderer_draw_cell(Renderer *r, u32 x, u32 y, u8 cell_type)
{
    return (r && r->ops && r->ops->draw_cell)
               ? r->ops->draw_cell(r, x, y, cell_type)
               : -1;
}

static inline int renderer_render(Renderer *r)
{
    return (r && r->ops && r->ops->render) ? r->ops->render(r) : -1;
}

static inline int renderer_clear(Renderer *r)
{
    return (r && r->ops && r->ops->clear) ? r->ops->clear(r) : -1;
}

static inline int renderer_shutdown(Renderer *r)
{
    return (r && r->ops && r->ops->shutdown) ? r->ops->shutdown(r) : -1;
}

#endif // C_SNAKE_GAME_RENDERER_H