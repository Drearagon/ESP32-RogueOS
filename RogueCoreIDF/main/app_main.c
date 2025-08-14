#include "rc_init.h"
#include "rk_cfgd.h"
#include "rk_log.h"
#include "rk_netd.h"

void app_main(void)
{
    rc_init();
    char ssid[32];
    if (rk_cfg_get_str("wifi.ssid", ssid, sizeof(ssid)) != ESP_OK) {
        rk_logf(RK_LOG_LEVEL_WARN, "Wi-Fi SSID not set. Use rcsh to configure.");
    } else {
        rk_netd_connect(ssid);
    }
}
