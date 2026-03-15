#include "renderer/renderer_tui.h"

int main(void)
{
    Renderer r;
    renderer_tui_create(&r);

    if (r.ops->init(&r) == 0)
    {
        r.ops->print(&r);
        r.ops->shutdown(&r);
    }

    return 0;
}