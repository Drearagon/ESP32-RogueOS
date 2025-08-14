#include "unity.h"
#include "rk_cfgd.h"

TEST_CASE("cfg set/get", "[cfgd]")
{
    rk_cfgd_init();
    TEST_ASSERT_EQUAL(ESP_OK, rk_cfg_put_str("test", "1"));
    char buf[8];
    TEST_ASSERT_EQUAL(ESP_OK, rk_cfg_get_str("test", buf, sizeof(buf)));
    TEST_ASSERT_EQUAL_STRING("1", buf);
}
