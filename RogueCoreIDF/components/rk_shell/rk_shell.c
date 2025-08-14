/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_shell.h"
#include "rk_hal.h"
#include "rk_kernel.h"
#include "driver/uart.h"
#include <string.h>

#ifndef CONFIG_ESP_CONSOLE_UART_NUM
#define CONFIG_ESP_CONSOLE_UART_NUM 0
#endif

static void shell_task(void *arg)
{
    char buf[128];
    while (1) {
        int len = uart_read_bytes(CONFIG_ESP_CONSOLE_UART_NUM, (uint8_t*)buf, sizeof(buf)-1, portMAX_DELAY);
        if (len > 0) {
            buf[len] = 0;
            rk_shell_process(buf);
        }
    }
}

void rk_shell_start(void)
{
    rk_uart_init(CONFIG_ESP_CONSOLE_UART_NUM, CONFIG_ESP_CONSOLE_UART_TX_GPIO, CONFIG_ESP_CONSOLE_UART_RX_GPIO, 115200);
    rk_task_spawn("rcsh", shell_task, NULL, 4096, 5, tskNO_AFFINITY);
}
