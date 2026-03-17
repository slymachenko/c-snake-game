#include "renderer/renderer.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *text;
} TuiData;

static int tui_init(Renderer *self)
{
    TuiData *data = NULL;

    if (!self)
    {
        return -1;
    }

    if (self->impl)
    {
        return 0;
    }

    data = (TuiData *)malloc(sizeof(TuiData));
    data->text = "Hello from TUI!";
    self->impl = data;

    return 0;
}

static int tui_print(Renderer *self)
{
    TuiData *data = NULL;

    if (!self || !self->impl)
    {
        return -1;
    }

    data = (TuiData *)self->impl;
    printf("%s\n", data->text);

    return 0;
}

static int tui_shutdown(Renderer *self)
{
    if (!self)
    {
        return -1;
    }

    if (!self->impl)
    {
        return 0;
    }

    free(self->impl);
    self->impl = NULL;

    return 0;
}

static const RendererOps TUI_OPS = {
    .init = tui_init,
    .print = tui_print,
    .shutdown = tui_shutdown,
};

int renderer_tui_create(Renderer *r)
{
    if (!r)
    {
        return -1;
    }

    r->ops = &TUI_OPS;
    r->impl = 0;

    return 0;
}