#include "renderer/renderer.h"
#include "renderer/renderer_tui.h"

int main(void)
{
    struct renderer r;

    tui_renderer_create(&r);

    if (renderer_init(&r) == 0) {
        renderer_render(&r);
        renderer_shutdown(&r);
    }

    return 0;
}
