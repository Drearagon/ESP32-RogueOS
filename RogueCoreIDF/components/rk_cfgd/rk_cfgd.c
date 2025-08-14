/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_cfgd.h"
#include "rk_cfg_schema.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "cJSON.h"
#include <string.h>
#include <stdlib.h>

static nvs_handle_t s_nvs;

esp_err_t rk_cfgd_init(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    if (err != ESP_OK) return err;
    return nvs_open("rcfg", NVS_READWRITE, &s_nvs);
}

esp_err_t rk_cfg_get_str(const char *key, char *out, size_t len)
{
    size_t req = len;
    esp_err_t err = nvs_get_str(s_nvs, key, out, &req);
    return err;
}

esp_err_t rk_cfg_put_str(const char *key, const char *val)
{
    esp_err_t err = nvs_set_str(s_nvs, key, val);
    if (err == ESP_OK) err = nvs_commit(s_nvs);
    return err;
}

esp_err_t rk_cfg_export_json(char *out, size_t len)
{
    cJSON *root = cJSON_CreateObject();
    char buf[64];
    if (rk_cfg_get_str(RK_CFG_KEY_WIFI_SSID, buf, sizeof(buf)) == ESP_OK)
        cJSON_AddStringToObject(root, RK_CFG_KEY_WIFI_SSID, buf);
    if (rk_cfg_get_str(RK_CFG_KEY_WIFI_PSK, buf, sizeof(buf)) == ESP_OK)
        cJSON_AddStringToObject(root, RK_CFG_KEY_WIFI_PSK, buf);
    if (rk_cfg_get_str(RK_CFG_KEY_NET_HOSTNAME, buf, sizeof(buf)) == ESP_OK)
        cJSON_AddStringToObject(root, RK_CFG_KEY_NET_HOSTNAME, buf);
    if (rk_cfg_get_str(RK_CFG_KEY_TIME_NTP, buf, sizeof(buf)) == ESP_OK)
        cJSON_AddStringToObject(root, RK_CFG_KEY_TIME_NTP, buf);
    if (rk_cfg_get_str(RK_CFG_KEY_SYS_LOG_LEVEL, buf, sizeof(buf)) == ESP_OK)
        cJSON_AddStringToObject(root, RK_CFG_KEY_SYS_LOG_LEVEL, buf);
    char *js = cJSON_PrintUnformatted(root);
    if (!js) {
        cJSON_Delete(root);
        return ESP_FAIL;
    }
    strncpy(out, js, len);
    free(js);
    cJSON_Delete(root);
    return ESP_OK;
}

esp_err_t rk_cfg_import_json(const char *json)
{
    cJSON *root = cJSON_Parse(json);
    if (!root) return ESP_FAIL;
    cJSON *it = NULL;
    cJSON_ArrayForEach(it, root) {
        if (cJSON_IsString(it)) {
            rk_cfg_put_str(it->string, it->valuestring);
        }
    }
    cJSON_Delete(root);
    return ESP_OK;
}
