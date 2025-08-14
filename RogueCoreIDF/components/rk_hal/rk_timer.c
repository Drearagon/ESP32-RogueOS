/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_hal.h"

esp_err_t rk_timer_init(timer_group_t group, timer_idx_t idx, uint64_t alarm_us)
{
    timer_config_t config = {
        .divider = 80,
        .counter_dir = TIMER_COUNT_UP,
        .counter_en = TIMER_PAUSE,
        .alarm_en = TIMER_ALARM_EN,
        .auto_reload = true
    };
    esp_err_t err = timer_init(group, idx, &config);
    if (err != ESP_OK) return err;
    err = timer_set_alarm_value(group, idx, alarm_us);
    if (err != ESP_OK) return err;
    err = timer_enable_intr(group, idx);
    if (err != ESP_OK) return err;
    return timer_start(group, idx);
}
