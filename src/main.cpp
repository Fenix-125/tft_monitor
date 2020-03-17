//
// Created by fenix on 3/16/20.
//

#include "Arduino.h"
#include <Adafruit_ILI9341.h>
#include <display/back_image.h>
#include "display/display_t.h"
#include "display/display_print.h"
// Fonts list: https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts
#include <Fonts/FreeSans24pt7b.h>
#include "uart/UARTRoutine.h"


static Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
static UARTRoutine uart_routine{UART_RX_PIN, UART_TX_PIN};

// Configure the layout
static measure_t measure{
        "",
        -12.34,
        coord_t{80, 171},
        colors.white,
        1,

        true,
        background_t{
                coord_t{78, 139},
                146,
                46,
                fill_out{colors.black}
        }
};


void setup() {
    tft.begin();
    draw_back_image(tft, BACKGROUND_IMAGE);
    tft.setRotation(1); // 0 -> 3
    tft.setFont(&FreeSans24pt7b);

    uart_routine.init();
}


void loop() {
//    static float dx = 1.3;
//    if ((measure.num > 12.23 && dx > 0) || (measure.num < -12.23 && dx < 0)) {
//        dx = -dx;
//    }
//    measure.num += dx;

    uart_routine.process();
    if (uart_routine.available()) {
        measure.num = uart_routine.get_data();
    }

    print_measure(tft, measure);
    delay(1000);
}