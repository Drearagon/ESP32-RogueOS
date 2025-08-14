#include "rk_otad.h"
#include "esp_https_ota.h"
#include "esp_log.h"
#include "esp_system.h"

esp_err_t rk_otad_http(const char *url)
{
    esp_http_client_config_t config = {
        .url = url,
    };
    esp_err_t err = esp_https_ota(&config);
    if (err == ESP_OK) {
        esp_restart();
    }
    return err;
}
