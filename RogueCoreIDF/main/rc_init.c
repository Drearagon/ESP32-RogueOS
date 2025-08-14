#include "rc_init.h"
#include "rk_log.h"
#include "rk_cfgd.h"
#include "rk_fsd.h"
#include "rk_netd.h"
#include "rk_otad.h"
#include "rk_shell.h"

void rc_init(void)
{
    rk_log_init();
    rk_cfgd_init();
    rk_fsd_mount();
    rk_netd_start();
    rk_shell_start();
}
