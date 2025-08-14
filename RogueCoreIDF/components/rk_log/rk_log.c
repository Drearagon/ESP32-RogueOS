#include "rk_log.h"
#include <stdio.h>
#include <string.h>

static rk_log_level_t s_level = RK_LOG_LEVEL_INFO;
static char s_ring[1024];
static size_t s_ring_pos;

void rk_log_init(void)
{
    s_ring_pos = 0;
}

void rk_log_set_level(rk_log_level_t level)
{
    s_level = level;
}

void rk_logf(rk_log_level_t level, const char *fmt, ...)
{
    if (level > s_level) return;
    va_list ap;
    va_start(ap, fmt);
    int len = vsnprintf(s_ring + s_ring_pos, sizeof(s_ring) - s_ring_pos, fmt, ap);
    if (len > 0) {
        s_ring_pos = (s_ring_pos + len) % sizeof(s_ring);
    }
    vprintf(fmt, ap);
    va_end(ap);
    printf("\n");
}
