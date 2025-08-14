/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#pragma once
#include <stddef.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t rk_cfgd_init(void);
esp_err_t rk_cfg_get_str(const char *key, char *out, size_t len);
esp_err_t rk_cfg_put_str(const char *key, const char *val);
esp_err_t rk_cfg_export_json(char *out, size_t len);
esp_err_t rk_cfg_import_json(const char *json);

#ifdef __cplusplus
}
#endif
