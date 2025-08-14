#include "rk_hal.h"

esp_err_t rk_i2c_init(i2c_port_t port)
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = GPIO_NUM_8,
        .scl_io_num = GPIO_NUM_9,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000
    };
    esp_err_t err = i2c_param_config(port, &conf);
    if (err != ESP_OK) return err;
    return i2c_driver_install(port, conf.mode, 0, 0, 0);
}
