idf_component_register(
    SRCS "app_main.c" "rc_init.c"
    INCLUDE_DIRS "."
    REQUIRES rk_log rk_kernel rk_hal rk_cfgd rk_fsd rk_netd rk_otad rk_shell
)
