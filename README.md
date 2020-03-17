## platformio workflow

### Board specification
 - [DOIT ESP32 DEVKIT V1](https://docs.platformio.org/en/latest/boards/espressif32/esp32doit-devkit-v1.html#board-espressif32-esp32doit-devkit-v1)

```ini
  
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1

```

Used project init command (from [quick start](https://docs.platformio.org/en/latest/core/quickstart.html#core-quickstart))

```bash

platformio project init --board esp32doit-devkit-v1 --ide clion
platformio run

```

