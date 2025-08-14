#pragma once
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t rk_netd_start(void);
esp_err_t rk_netd_connect(const char *ssid);
esp_err_t rk_netd_wifi_status(void);
void rk_netd_sntp_start(void);

#ifdef __cplusplus
}
#endif
