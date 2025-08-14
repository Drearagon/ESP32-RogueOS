/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#pragma once
#include <stdarg.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RK_LOG_LEVEL_ERR = 0,
    RK_LOG_LEVEL_WARN,
    RK_LOG_LEVEL_INFO,
    RK_LOG_LEVEL_DBG,
} rk_log_level_t;

void rk_log_init(void);
void rk_log_set_level(rk_log_level_t level);
void rk_logf(rk_log_level_t level, const char *fmt, ...);

#ifdef __cplusplus
}
#endif
