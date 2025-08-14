/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#pragma once
#include <stddef.h>
#include "esp_err.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"
#include "driver/timer.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t rk_uart_init(int port, int tx_pin, int rx_pin, int baud);
int rk_uart_write(int port, const uint8_t *data, size_t len);

esp_err_t rk_gpio_init(gpio_num_t pin, gpio_mode_t mode);
esp_err_t rk_gpio_set_level(gpio_num_t pin, uint32_t level);

esp_err_t rk_i2c_init(i2c_port_t port);

esp_err_t rk_spi_init(spi_host_device_t host);

esp_err_t rk_timer_init(timer_group_t group, timer_idx_t idx, uint64_t alarm_us);

#ifdef __cplusplus
}
#endif
