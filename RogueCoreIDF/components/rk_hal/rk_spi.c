/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_hal.h"

esp_err_t rk_spi_init(spi_host_device_t host)
{
    spi_bus_config_t bus = {
        .mosi_io_num = GPIO_NUM_10,
        .miso_io_num = GPIO_NUM_11,
        .sclk_io_num = GPIO_NUM_12,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096
    };
    return spi_bus_initialize(host, &bus, SPI_DMA_CH_AUTO);
}
