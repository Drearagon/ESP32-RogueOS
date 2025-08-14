idf_component_register(
    SRCS "rk_ipc.c" "rk_task.c" "rk_event.c" "rk_panic.c"
    INCLUDE_DIRS "include"
    REQUIRES freertos
)
