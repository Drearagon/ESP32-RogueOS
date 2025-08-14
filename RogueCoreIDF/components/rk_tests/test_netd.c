/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "unity.h"
#include "rk_netd.h"

TEST_CASE("netd start", "[netd]")
{
    TEST_ASSERT_EQUAL(ESP_OK, rk_netd_start());
}
