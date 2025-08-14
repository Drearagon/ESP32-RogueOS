idf_component_register(
    SRCS "rk_uart.c" "rk_gpio.c" "rk_i2c.c" "rk_spi.c" "rk_timer.c"
    INCLUDE_DIRS "include"
    REQUIRES driver
)
