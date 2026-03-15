#ifndef RENDERER_H
#define RENDERER_H

typedef struct Renderer Renderer;

typedef struct RendererOps
{
    int (*init)(Renderer *self);
    int (*print)(Renderer *self);
    int (*shutdown)(Renderer *self);
} RendererOps;

struct Renderer
{
    const RendererOps *ops;
    void *impl;
};

#endif // RENDERER_H