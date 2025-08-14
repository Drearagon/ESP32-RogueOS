#include "rk_netd.h"
#include "rk_cfgd.h"
#include "rk_cfg_schema.h"
#include "esp_sntp.h"
#include <string.h>

void rk_netd_sntp_start(void)
{
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    char server[64] = "pool.ntp.org";
    rk_cfg_get_str(RK_CFG_KEY_TIME_NTP, server, sizeof(server));
    sntp_setservername(0, server);
    sntp_init();
}
