#include <stdio.h>
#include "rk_kernel.h"
#include "esp_system.h"

void rk_panic(const char *msg)
{
    if (msg) {
        printf("PANIC: %s\n", msg);
    }
    fflush(stdout);
    esp_restart();
}
