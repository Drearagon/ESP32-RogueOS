/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "unity.h"
#include "rk_fsd.h"

TEST_CASE("fs write/read", "[fsd]")
{
    rk_fsd_mount();
    TEST_ASSERT_EQUAL(ESP_OK, rk_fs_write("/test.txt", "hi", 2));
    char buf[8];
    TEST_ASSERT_EQUAL(ESP_OK, rk_fs_read("/test.txt", buf, sizeof(buf)));
    TEST_ASSERT_EQUAL_STRING("hi", buf);
}
