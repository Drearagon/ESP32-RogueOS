#include "rk_hal.h"

esp_err_t rk_uart_init(int port, int tx_pin, int rx_pin, int baud)
{
    const uart_config_t cfg = {
        .baud_rate = baud,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    esp_err_t err = uart_param_config(port, &cfg);
    if (err != ESP_OK) return err;
    err = uart_set_pin(port, tx_pin, rx_pin, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    if (err != ESP_OK) return err;
    return uart_driver_install(port, 2048, 0, 0, NULL, 0);
}

int rk_uart_write(int port, const uint8_t *data, size_t len)
{
    return uart_write_bytes(port, (const char *)data, len);
}
