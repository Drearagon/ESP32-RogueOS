idf_component_register(
    SRCS "rk_shell.c" "rk_shell_cmds.c"
    INCLUDE_DIRS "include"
    REQUIRES rk_hal rk_kernel rk_cfgd rk_fsd rk_netd rk_otad rk_log driver
)
