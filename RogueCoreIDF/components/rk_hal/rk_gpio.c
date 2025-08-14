#include "rk_hal.h"

esp_err_t rk_gpio_init(gpio_num_t pin, gpio_mode_t mode)
{
    gpio_config_t cfg = {
        .pin_bit_mask = 1ULL << pin,
        .mode = mode,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    return gpio_config(&cfg);
}

esp_err_t rk_gpio_set_level(gpio_num_t pin, uint32_t level)
{
    return gpio_set_level(pin, level);
}
