//
// Created by fenix on 3/16/20.
//

#ifndef TFT_MONITOR_DISPLAY_PRINT_H
#define TFT_MONITOR_DISPLAY_PRINT_H

#include "display_t.h"
#include <Adafruit_ILI9341.h>

void print_measure(Adafruit_ILI9341 tft, const measure_t &conf);


void draw_back_image(Adafruit_ILI9341 tft, background_t background);

#endif //TFT_MONITOR_DISPLAY_PRINT_H
