#ifndef BRYTECCAN_H
#define BRYTECCAN_H

#include <stdint.h>
#include <QCanBusFrame>

struct PinStatusBroadcast {

    enum StatusFlags : uint8_t {
        DISABLED,
        NORMAL,
        TRIPPED
    };

    StatusFlags statusFlags = StatusFlags::DISABLED; // 4 bits
    uint8_t moduleAddress = 0;
    uint16_t nodeGroupIndex = 0;
    float current = 0.0f; // 2 decimal places
    float voltage = 0.0f; // 2 decimal places
    float value = 0.0f;

    PinStatusBroadcast() = default;
    PinStatusBroadcast(const QCanBusFrame& frame);
    bool isBroadcast(const QCanBusFrame& frame);
    QCanBusFrame getFrame();
};

#endif // BRYTECCAN_H
