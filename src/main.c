#include "renderer/renderer_tui.h"

int main(void)
{
    Renderer r;

    renderer_tui_create(&r);

    if (renderer_init(&r) == 0) {
        renderer_render(&r);
        renderer_shutdown(&r);
    }

    return 0;
}