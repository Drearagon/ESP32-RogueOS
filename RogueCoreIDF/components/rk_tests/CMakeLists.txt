idf_component_register(
    SRCS "test_hal.c" "test_cfgd.c" "test_fsd.c" "test_netd.c"
    INCLUDE_DIRS "."
    REQUIRES unity rk_hal rk_cfgd rk_fsd rk_netd
)
