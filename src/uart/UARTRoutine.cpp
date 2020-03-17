//
// Created by fenix on 3/17/20.
//

#include <cmath>
#include "uart/UARTRoutine.h"

void UARTRoutine::init() {
    uart_serial.begin(9600, SERIAL_8N1, rx, tx);
    while (!uart_serial) {}
}

void UARTRoutine::process() {
    if (!uart_serial.available()) {
        return;
    }

    int tmp_byte;
    while ((tmp_byte = uart_serial.read()) != -1) {
        switch (state) {
            case ProtocolState::WAIT:
                if (is_protocol_init((uint8_t) tmp_byte)) {
                    state = ProtocolState::RECEIVE_DATA;
                }
                break;

            case ProtocolState::RECEIVE_DATA:
                push_byte(tmp_byte);
                if (is_full_buffer()) {
                    if (is_valid_data(buffer)) {
                        update_data(extract_float2_protocol(buffer));
                    }
                    flash_buffer();
                    state = ProtocolState::WAIT;
                    return;
                }
                break;
        }
    }
}

// is there new data available
bool UARTRoutine::available() {
    return new_data;
}

float UARTRoutine::get_data() {
    new_data = false;
    return current_data;
}

void UARTRoutine::update_data(float new_val) {
    if (std::fabs(new_val - current_data) >= 0.01) {
        current_data = new_val;
        new_data = true;
    }
}

// ############ BUFFER WORKFLOW ############
bool UARTRoutine::is_full_buffer() {
    return buffer_cursor >= PROTOCOL_CHECKED_MASSAGE;
}

// preserve buffer overflow (do not add if full)
void UARTRoutine::push_byte(uint8_t byte) {
    if (is_full_buffer()) {
        return;
    }
    buffer[buffer_cursor] = byte;
    buffer_cursor += 1;
}

void UARTRoutine::flash_buffer() {
    buffer_cursor = 0;
}
