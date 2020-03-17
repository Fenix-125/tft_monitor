# TFT Monitor

**TFT Monitor project** is aimed to receive **float value** (rotation speed), over **UART** with validation protocol visualize the, on a custom background image, using **TFT 2.8 SPI 240x320 v1.2** display and **DOIT ESP32 DevKit v1** board.

## Pin Layout
```
// pins for ESP32 DOIT Dev Kit v1 (30 pins)
#define TFT_CLK 26
#define TFT_MISO 25
#define TFT_MOSI 27
#define TFT_DC 14
#define TFT_CS 13
#define TFT_RST 12
// #define TFT_LED V3.3
```
![photo_2020-03-18_00-29-11](https://user-images.githubusercontent.com/44115554/76907745-af6dde00-68af-11ea-9141-98c9ea1899ea.jpg)

## Installation
<!-- TODO: Describe all required CLTs (command line tools) and software -->

The project is configured with **PlatformIO** for development in **CLion**.

Process (build) all environments specified in “platformio.ini” (Project Configuration File)
```bash
platformio run  
```

Build project and upload firmware to the all devices specified in “platformio.ini” (Project Configuration File)
```bash
platformio run --target upload. 
```

## Usage Linux

To **update the background image** use **python 3.8** script from its directory.
The picture should be in **8-bit RGB** color format and recommended to use the **png** image format.<br>

The script was tested only for this case, but should also work for other image formats with 8-bit RGB.

```bash
$ source venv/bin/activate
$ cd scripts
$ python update_backround_img.py --help
usage: update_background_img.py [options]

Update the background image of the monitor interface.

positional arguments:
  input_image           image to source as the background image for the monitor interface

optional arguments:
  -h, --help            show this help message and exit
  --width WIDTH, -W WIDTH
                        width of the image. If it is smaller then the actual width, image will
                        be cropped form the left. Else it is set to the image width
  --height HEIGHT, -H HEIGHT
                        height of the image. If it is smaller then the actual height, image will
                        be cropped form the bottom. Else it is set to the image height
$ python update_backround_img.py ../data/background.png
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## For contributors

#### PlatformIO workflow

#### Board specification
 - [DOIT ESP32 DEVKIT V1](https://docs.platformio.org/en/latest/boards/espressif32/esp32doit-devkit-v1.html#board-espressif32-esp32doit-devkit-v1)

Used project init command (from [quick start](https://docs.platformio.org/en/latest/core/quickstart.html#core-quickstart))

```bash
platformio project init --board esp32doit-devkit-v1 --ide clion
platformio run
```

## Author
Yuriy Pasichnyk - [Fenix](https://github.com/Fenix-125)

## License
[MIT](https://choosealicense.com/licenses/mit/)
