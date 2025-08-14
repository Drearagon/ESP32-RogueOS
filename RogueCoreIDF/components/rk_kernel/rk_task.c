/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_kernel.h"

rk_task_t rk_task_spawn(const char *name, TaskFunction_t entry, void *arg,
                        uint32_t stack, UBaseType_t prio, BaseType_t core)
{
    rk_task_t handle = NULL;
    if (xTaskCreatePinnedToCore(entry, name, stack, arg, prio, &handle, core) != pdPASS) {
        return NULL;
    }
    return handle;
}
