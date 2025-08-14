/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_kernel.h"

rk_msgq_t rk_msgq_create(size_t capacity, size_t msg_size)
{
    return xQueueCreate(capacity, msg_size);
}

esp_err_t rk_msgq_send(rk_msgq_t q, const void *msg, uint32_t timeout_ms)
{
    return xQueueSend(q, msg, pdMS_TO_TICKS(timeout_ms)) == pdPASS ? ESP_OK : ESP_FAIL;
}

esp_err_t rk_msgq_recv(rk_msgq_t q, void *msg, uint32_t timeout_ms)
{
    return xQueueReceive(q, msg, pdMS_TO_TICKS(timeout_ms)) == pdPASS ? ESP_OK : ESP_FAIL;
}
