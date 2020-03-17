//
// Created by fenix on 3/17/20.
//

#ifndef TFT_MONITOR_PROTOCOL_H
#define TFT_MONITOR_PROTOCOL_H

#include <cstdint>

#define PROTOCOL_START_BYTES 1      // SHOULD BE ONE
static_assert(PROTOCOL_START_BYTES == 1, "PROTOCOL_START_BYTES SHOULD BE ONE;"
                                         "dependencies: is_protocol_init");

#define PROTOCOL_MASSAGE_SIZE 4     // SHOULD BE GREATER EQUAL THEN 3
static_assert(PROTOCOL_MASSAGE_SIZE >= 3, "SHOULD BE GREATER EQUAL THEN 3;"
                                          "dependencies: extract_float2_protocol");

#define PROTOCOL_CHECK_SUM_BYTES 1 // DO NOT CHANGE - uint16_t used to store the actual value
static_assert(PROTOCOL_CHECK_SUM_BYTES == 1, "SHOULD BE 1 - uint8_t used to store the actual value;"
                                             "dependencies: is_valid_data");

#define PROTOCOL_CHECKED_MASSAGE PROTOCOL_MASSAGE_SIZE + PROTOCOL_CHECK_SUM_BYTES
//                                     dependencies: is_valid_data

#define PROTOCOL_PACKET_SIZE PROTOCOL_START_BYTES + PROTOCOL_CHECKED_MASSAGE

// check for init byte
bool is_protocol_init(uint8_t byte);

// check if the sum of bytes is as the check sum in the back of the massage
bool is_valid_data(uint8_t data[PROTOCOL_CHECKED_MASSAGE]);

// from last two bytes form an integer it is davidde by 100; third byte from the back is responsible for the sign
// ...* ***[1/0] [**** ****]
// any |  sign  | 4
float extract_float2_protocol(const uint8_t data[PROTOCOL_MASSAGE_SIZE]);


#endif //TFT_MONITOR_PROTOCOL_H
