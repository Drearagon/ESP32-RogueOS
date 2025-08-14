/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#pragma once
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t rk_otad_http(const char *url);

#ifdef __cplusplus
}
#endif
