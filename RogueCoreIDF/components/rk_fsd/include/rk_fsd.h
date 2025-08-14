#pragma once
#include <stddef.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t rk_fsd_mount(void);
esp_err_t rk_fs_read(const char *path, char *out, size_t max);
esp_err_t rk_fs_write(const char *path, const char *data, size_t len);
esp_err_t rk_fs_list(const char *path);
esp_err_t rk_fs_mkdir(const char *path);
esp_err_t rk_fs_unlink(const char *path);

#ifdef __cplusplus
}
#endif
