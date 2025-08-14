#include "unity.h"
#include "rk_netd.h"

TEST_CASE("netd start", "[netd]")
{
    TEST_ASSERT_EQUAL(ESP_OK, rk_netd_start());
}
