//
// Created by fenix on 3/17/20.
//

#ifndef TFT_MONITOR_UARTROUTINE_H
#define TFT_MONITOR_UARTROUTINE_H

#include "uart/uart_const.h"
#include "protocol.h"
#include <SoftwareSerial.h>
#include <cstdint>
#include <cstdlib>


enum class ProtocolState {
    WAIT,
    RECEIVE_DATA,
    PROCESS_DATA
};

class UARTRoutine {
public:
    UARTRoutine(int rx = UART_RX_PIN, int tx = UART_TX_PIN)
            : uart_serial(SoftwareSerial(rx, tx)) {}

    void init();

    void process();

    // is there new data available
    bool available();

    float get_data();

private:
    SoftwareSerial uart_serial;
    float current_data = 0.0;
    bool new_data = false;
    ProtocolState state = ProtocolState::WAIT;

    uint8_t buffer[PROTOCOL_CHECKED_MASSAGE]{};
    size_t buffer_cursor = 0;

    void update_data(float val);

    // ############ BUFFER WORKFLOW ############
    bool is_full_buffer();

    // preserve buffer overflow (do not add if full)
    void push_byte(uint8_t byte);

    void flash_buffer();
};


#endif //TFT_MONITOR_UARTROUTINE_H
