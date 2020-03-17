//
// Created by fenix on 3/16/20.
//

#ifndef TFT_MONITOR_DISPLAY_CONST_H
#define TFT_MONITOR_DISPLAY_CONST_H

#include <cstdint>
#include <Adafruit_ILI9341.h>


// pins for ESP32 DOIT Dev Kit v1 (30 pins)
#define TFT_CLK 26
#define TFT_MISO 25
#define TFT_MOSI 27
#define TFT_DC 14
#define TFT_CS 13
#define TFT_RST 12
// #define TFT_LED V3.3


// uint16_t <-> RGB565
// #define ILI9341_BLACK 0x0000       ///<   0,   0,   0
struct {
    uint16_t green = ILI9341_GREEN;
    uint16_t black = ILI9341_BLACK;
    uint16_t navy = ILI9341_NAVY;
    uint16_t darkgreen = ILI9341_DARKGREEN;
    uint16_t darkcyan = ILI9341_DARKCYAN;
    uint16_t maroon = ILI9341_MAROON;
    uint16_t purple = ILI9341_PURPLE;
    uint16_t olive = ILI9341_OLIVE;
    uint16_t lightgrey = ILI9341_LIGHTGREY;
    uint16_t darkgrey = ILI9341_DARKGREY;
    uint16_t blue = ILI9341_BLUE;
    uint16_t cyan = ILI9341_CYAN;
    uint16_t red = ILI9341_RED;
    uint16_t magenta = ILI9341_MAGENTA;
    uint16_t yellow = ILI9341_YELLOW;
    uint16_t white = ILI9341_WHITE;
    uint16_t orange = ILI9341_ORANGE;
    uint16_t greenyellow = ILI9341_GREENYELLOW;
    uint16_t pink = ILI9341_PINK;
} colors;


#endif //TFT_MONITOR_DISPLAY_CONST_H
