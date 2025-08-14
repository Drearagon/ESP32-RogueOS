# RogueCoreIDF

RogueCoreIDF is a minimal micro-OS layer for ESP32-C3 and ESP32-S3 based on
ESP-IDF and FreeRTOS.  It provides a small kernel wrapper, hardware abstraction
layer, system services, and a UART shell for managing configuration, storage
and connectivity.

## Features
- Targets ESP32-C3 (RISC-V) and ESP32-S3 (Xtensa)
- Runs on top of FreeRTOS using ESP-IDF's CMake build system
- Microkernel style API for tasks, message queues, timers and events
- Drivers for UART, GPIO, I2C, SPI, timers and NVS
- LittleFS filesystem mounted at `/`
- Wi-Fi station mode with SNTP time synchronisation
- OTA updates over HTTP(S)
- UART shell (`rcsh`) to manage config, Wi-Fi, files, system info and OTA
- Unit tests using Unity

## Building
```bash
idf.py set-target esp32c3  # or esp32s3
idf.py build
```

## Flashing
```bash
idf.py -p <PORT> flash monitor
```

See `docs/QUICKSTART.md` for detailed steps.
