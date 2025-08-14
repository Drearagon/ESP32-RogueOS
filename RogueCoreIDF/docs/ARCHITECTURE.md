# Architecture

```
+------------------+
|   rk_shell       |
+------------------+
| rk_netd rk_fsd   |
| rk_cfgd rk_otad  |
+------------------+
|    rk_kernel     |
+------------------+
|   FreeRTOS/IDF   |
```

## Boot Order
1. `app_main` calls `rc_init()` which initialises logging, NVS and filesystem.
2. Configuration is loaded from NVS via `rk_cfgd`.
3. `rk_netd` attempts to connect to Wi-Fi and starts SNTP.
4. The shell task is spawned, providing interactive access.

## IPC Model
`rk_kernel` wraps FreeRTOS tasks, message queues and event groups. Components
communicate through these primitives; for example network events are posted to a
message queue consumed by the shell.
