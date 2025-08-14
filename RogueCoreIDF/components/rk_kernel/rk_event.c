#include "rk_kernel.h"

rk_event_t rk_event_create(void)
{
    return xEventGroupCreate();
}

EventBits_t rk_event_wait(rk_event_t ev, EventBits_t bits, bool clear, uint32_t timeout_ms)
{
    return xEventGroupWaitBits(ev, bits, clear, false, pdMS_TO_TICKS(timeout_ms));
}

esp_err_t rk_event_set(rk_event_t ev, EventBits_t bits)
{
    return xEventGroupSetBits(ev, bits) ? ESP_OK : ESP_FAIL;
}

esp_err_t rk_event_clear(rk_event_t ev, EventBits_t bits)
{
    return xEventGroupClearBits(ev, bits) ? ESP_OK : ESP_FAIL;
}
