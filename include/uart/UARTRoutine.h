//
// Created by fenix on 3/17/20.
//

#ifndef TFT_MONITOR_UARTROUTINE_H
#define TFT_MONITOR_UARTROUTINE_H

#include "uart/uart_const.h"
#include "protocol.h"
#include <cstdint>
#include <cstdlib>
#include <HardwareSerial.h>


enum class ProtocolState {
    WAIT,
    RECEIVE_DATA
};

class UARTRoutine {
public:
    UARTRoutine(int i_rx = UART_RX_PIN, int i_tx = UART_TX_PIN) : rx(i_rx), tx(i_tx) {}

    void init();

    void process();

    // is there new data available
    bool available();

    float get_data();

private:
    int rx, tx;
    HardwareSerial &uart_serial = Serial2;
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
