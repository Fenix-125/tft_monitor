//
// Created by fenix on 3/16/20.
//

#include "display/display_print.h"

void print_measure(Adafruit_ILI9341 tft, const measure_t &conf) {
    if (conf.has_backgr) {
        tft.fillRect(conf.back_conf.pos.x, conf.back_conf.pos.y,
                     conf.back_conf.w, conf.back_conf.h,
                     conf.back_conf.filing.color
        );
    }

    tft.setCursor(conf.pos.x, conf.pos.y);
    tft.setTextColor(colors.white);
    tft.setTextSize(conf.txt_size);
    tft.print(conf.label);
    tft.setTextColor(conf.color);

    if (conf.num >= 10) {
        tft.print(" ");
    } else if (conf.num >= 0) {
        tft.print("  ");
    } else if (conf.num >= -10) {
        tft.print(" ");
    }
    tft.print(conf.num);
}


void draw_back_image(Adafruit_ILI9341 tft, background_t background) {
    tft.drawRGBBitmap(0, 0,
                      background.filing.bit_map,
//                      (uint16_t *) dragonBitmap,
                      background.h, background.w);
}
