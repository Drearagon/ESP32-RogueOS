#pragma once
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef TaskHandle_t rk_task_t;
typedef QueueHandle_t rk_msgq_t;
typedef EventGroupHandle_t rk_event_t;

rk_task_t rk_task_spawn(const char *name, TaskFunction_t entry, void *arg,
                        uint32_t stack, UBaseType_t prio, BaseType_t core);

rk_msgq_t rk_msgq_create(size_t capacity, size_t msg_size);
esp_err_t rk_msgq_send(rk_msgq_t q, const void *msg, uint32_t timeout_ms);
esp_err_t rk_msgq_recv(rk_msgq_t q, void *msg, uint32_t timeout_ms);

rk_event_t rk_event_create(void);
EventBits_t rk_event_wait(rk_event_t ev, EventBits_t bits, bool clear, uint32_t timeout_ms);
esp_err_t rk_event_set(rk_event_t ev, EventBits_t bits);
esp_err_t rk_event_clear(rk_event_t ev, EventBits_t bits);

void rk_panic(const char *msg);

#ifdef __cplusplus
}
#endif
