//
// Created by fenix on 3/17/20.
//

#include <cstddef>
#include "uart/protocol.h"
#define PROTOCOL_START_BYTE 0xE7

bool is_protocol_init(uint8_t byte) {
    return byte == PROTOCOL_START_BYTE;
}

bool is_valid_data(const uint8_t data[PROTOCOL_CHECKED_MASSAGE]) {
    uint8_t check_sum = data[PROTOCOL_CHECKED_MASSAGE - 1];
    uint16_t sum = 0;
    for (size_t i = 0; i < PROTOCOL_CHECKED_MASSAGE - 1;
         ++i) {
        sum += data[i];
    }
    return (uint8_t) sum == check_sum;
}

// from last two bytes form an integer it is davidde by 100; third byte from the back is responsible for the sign
// ...* *******[1/0] [******** ********]
// any  |  sign     |       4
float extract_float2_protocol(const uint8_t data[PROTOCOL_MASSAGE_SIZE]) {
    float res = 0;
    for (size_t i = 2; i > 0; --i) {
        res += (float) (data[PROTOCOL_MASSAGE_SIZE - i] << (i - 1) * 8);
    }

    if (data[PROTOCOL_MASSAGE_SIZE - 3] & 0b00000001) {
        res *= -1;
    }
    return res / 100;
}
