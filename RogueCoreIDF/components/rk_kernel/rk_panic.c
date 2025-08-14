/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

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
