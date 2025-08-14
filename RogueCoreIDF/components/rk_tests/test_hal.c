#include "unity.h"
#include "rk_hal.h"

TEST_CASE("uart init", "[hal]")
{
    TEST_ASSERT_EQUAL(ESP_OK, rk_uart_init(0, CONFIG_ESP_CONSOLE_UART_TX_GPIO, CONFIG_ESP_CONSOLE_UART_RX_GPIO, 115200));
}
