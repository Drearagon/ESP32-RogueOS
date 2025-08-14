/* Copyright (c) 2024 Donavin Rediron.
 * All rights reserved. Usage without written permission is prohibited. */

#include "rk_shell.h"
#include "rk_cfgd.h"
#include "rk_cfg_schema.h"
#include "rk_fsd.h"
#include "rk_netd.h"
#include "rk_otad.h"
#include "rk_log.h"
#include "esp_system.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void rk_shell_process(char *line)
{
    char *cmd = strtok(line, " \r\n");
    if (!cmd) return;
    if (!strcmp(cmd, "help")) {
        printf("Commands: help version reboot log cfg wifi fs time ota\n");
    } else if (!strcmp(cmd, "version")) {
        printf("RogueCoreIDF\n");
    } else if (!strcmp(cmd, "reboot")) {
        esp_restart();
    } else if (!strcmp(cmd, "log")) {
        char *sub = strtok(NULL, " \r\n");
        if (sub && !strcmp(sub, "level")) {
            char *lvl = strtok(NULL, " \r\n");
            if (lvl) {
                if (!strcmp(lvl, "DBG")) rk_log_set_level(RK_LOG_LEVEL_DBG);
                else if (!strcmp(lvl, "INFO")) rk_log_set_level(RK_LOG_LEVEL_INFO);
                else if (!strcmp(lvl, "WARN")) rk_log_set_level(RK_LOG_LEVEL_WARN);
                else rk_log_set_level(RK_LOG_LEVEL_ERR);
            }
        }
    } else if (!strcmp(cmd, "cfg")) {
        char *op = strtok(NULL, " \r\n");
        if (op && !strcmp(op, "get")) {
            char *key = strtok(NULL, " \r\n");
            char val[64];
            if (key && rk_cfg_get_str(key, val, sizeof(val)) == ESP_OK)
                printf("%s=%s\n", key, val);
        } else if (op && !strcmp(op, "set")) {
            char *key = strtok(NULL, " \r\n");
            char *val = strtok(NULL, "\r\n");
            if (key && val) rk_cfg_put_str(key, val);
        } else if (op && !strcmp(op, "export")) {
            char buf[256];
            rk_cfg_export_json(buf, sizeof(buf));
            printf("%s\n", buf);
        } else if (op && !strcmp(op, "import")) {
            char *json = strtok(NULL, "\r\n");
            if (json) rk_cfg_import_json(json);
        }
    } else if (!strcmp(cmd, "wifi")) {
        char *sub = strtok(NULL, " \r\n");
        if (sub && !strcmp(sub, "status")) {
            rk_netd_wifi_status();
        } else if (sub && !strcmp(sub, "connect")) {
            char ssid[32];
            if (rk_cfg_get_str(RK_CFG_KEY_WIFI_SSID, ssid, sizeof(ssid)) == ESP_OK)
                rk_netd_connect(ssid);
            else
                printf("SSID not set\n");
        }
    } else if (!strcmp(cmd, "fs")) {
        char *sub = strtok(NULL, " \r\n");
        if (sub && !strcmp(sub, "ls")) {
            char *path = strtok(NULL, " \r\n");
            if (!path) path = "/";
            rk_fs_list(path);
        } else if (sub && !strcmp(sub, "cat")) {
            char *file = strtok(NULL, " \r\n");
            char buf[128];
            if (file && rk_fs_read(file, buf, sizeof(buf)) == ESP_OK)
                printf("%s\n", buf);
        } else if (sub && !strcmp(sub, "write")) {
            char *file = strtok(NULL, " \r\n");
            char *data = strtok(NULL, "\r\n");
            if (file && data) rk_fs_write(file, data, strlen(data));
        } else if (sub && !strcmp(sub, "rm")) {
            char *file = strtok(NULL, " \r\n");
            if (file) rk_fs_unlink(file);
        }
    } else if (!strcmp(cmd, "time")) {
        char *sub = strtok(NULL, " \r\n");
        if (sub && !strcmp(sub, "now")) {
            time_t now = time(NULL);
            printf("%ld\n", now);
        }
    } else if (!strcmp(cmd, "ota")) {
        char *url = strtok(NULL, " \r\n");
        if (url) rk_otad_http(url);
    } else {
        printf("unknown command\n");
    }
}
