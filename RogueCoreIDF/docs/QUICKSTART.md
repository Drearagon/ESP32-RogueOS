# Quick Start

1. Install [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)
   and export the environment.
2. Clone this repository and change into it:
   ```bash
   git clone https://example.com/RogueCoreIDF.git
   cd RogueCoreIDF
   ```
3. Select your target and build:
   ```bash
   idf.py set-target esp32c3  # or esp32s3
   idf.py build
   ```
4. Flash and monitor:
   ```bash
   idf.py -p /dev/ttyUSB0 flash monitor
   ```
5. Use the UART shell to configure Wi-Fi credentials:
   ```
   rcsh> cfg set wifi.ssid MySSID
   rcsh> cfg set wifi.psk MyPass
   rcsh> wifi connect
   ```
