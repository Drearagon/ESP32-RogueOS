#include "rk_fsd.h"
#include "esp_littlefs.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

esp_err_t rk_fsd_mount(void)
{
    esp_vfs_littlefs_conf_t conf = {
        .base_path = "/",
        .partition_label = "littlefs",
        .format_if_mount_failed = true,
        .read_only = false
    };
    return esp_vfs_littlefs_register(&conf);
}

esp_err_t rk_fs_read(const char *path, char *out, size_t max)
{
    FILE *f = fopen(path, "r");
    if (!f) return ESP_FAIL;
    size_t r = fread(out, 1, max - 1, f);
    out[r] = 0;
    fclose(f);
    return ESP_OK;
}

esp_err_t rk_fs_write(const char *path, const char *data, size_t len)
{
    FILE *f = fopen(path, "w");
    if (!f) return ESP_FAIL;
    fwrite(data, 1, len, f);
    fclose(f);
    return ESP_OK;
}

esp_err_t rk_fs_list(const char *path)
{
    DIR *d = opendir(path);
    if (!d) return ESP_FAIL;
    struct dirent *e;
    while ((e = readdir(d))) {
        printf("%s\n", e->d_name);
    }
    closedir(d);
    return ESP_OK;
}

esp_err_t rk_fs_mkdir(const char *path)
{
    return mkdir(path, 0755) == 0 ? ESP_OK : ESP_FAIL;
}

esp_err_t rk_fs_unlink(const char *path)
{
    return unlink(path) == 0 ? ESP_OK : ESP_FAIL;
}
