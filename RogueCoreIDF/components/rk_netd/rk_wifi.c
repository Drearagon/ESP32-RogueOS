#include "rk_netd.h"
#include "rk_cfgd.h"
#include "rk_log.h"
#include "rk_cfg_schema.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include <string.h>

static bool s_started;

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        esp_wifi_connect();
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        rk_netd_sntp_start();
    }
}

esp_err_t rk_netd_start(void)
{
    if (s_started) return ESP_OK;
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
    s_started = true;
    return ESP_OK;
}

esp_err_t rk_netd_connect(const char *ssid)
{
    if (!s_started) rk_netd_start();
    wifi_config_t wcfg = {0};
    strncpy((char*)wcfg.sta.ssid, ssid, sizeof(wcfg.sta.ssid));
    char psk[64] = {0};
    rk_cfg_get_str(RK_CFG_KEY_WIFI_PSK, psk, sizeof(psk));
    strncpy((char*)wcfg.sta.password, psk, sizeof(wcfg.sta.password));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wcfg));
    return esp_wifi_start();
}

esp_err_t rk_netd_wifi_status(void)
{
    wifi_ap_record_t info;
    if (esp_wifi_sta_get_ap_info(&info) == ESP_OK) {
        printf("Connected to %s\n", (char*)info.ssid);
        return ESP_OK;
    }
    printf("Wi-Fi not connected\n");
    return ESP_FAIL;
}
