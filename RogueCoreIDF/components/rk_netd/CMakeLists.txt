idf_component_register(
    SRCS "rk_wifi.c" "rk_sntp.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_wifi esp_event esp_netif rk_cfgd esp_sntp
)
