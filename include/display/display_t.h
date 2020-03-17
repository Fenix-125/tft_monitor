//
// Created by fenix on 3/16/20.
//

#ifndef TFT_MONITOR_DISPLAY_T_H
#define TFT_MONITOR_DISPLAY_T_H

#include <cstdint>
#include "display_const.h"


union fill_out {
    fill_out(uint16_t icolor) : color(icolor) {}

    fill_out(const uint16_t *ibit_map) : bit_map(ibit_map) {}

    uint16_t color;
    const uint16_t *bit_map;
};

struct coord_t {
    coord_t(int16_t ix = 0, int16_t iy = 0) : x(ix), y(iy) {}

    int16_t x;
    int16_t y;
};


struct background_t {
    background_t(coord_t ipos = coord_t{}, int16_t iw = 0, int16_t ih = 0, fill_out ibit_map = fill_out{colors.black}) :
            pos(ipos), w(iw), h(ih), filing(ibit_map) {}

    coord_t pos{};
    int16_t w, h;
    fill_out filing;
};


struct measure_t {
    measure_t(
            const char *ilabel,
            float inum,
            coord_t ipos,
            uint16_t icolor,
            uint8_t itxt_size,
            bool ibackground = false,
            background_t iback_conf = background_t{}
    ) :
            label(ilabel), num(inum), pos(ipos), color(icolor),
            txt_size(itxt_size), has_backgr(ibackground),
            back_conf(iback_conf) {}

    const char *label;
    float num;
    coord_t pos;
    uint16_t color;
    uint8_t txt_size;
    bool has_backgr;
    background_t back_conf;
};


#endif //TFT_MONITOR_DISPLAY_T_H
