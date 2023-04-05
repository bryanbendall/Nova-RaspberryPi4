#include "bryteccan.h"


PinStatusBroadcast::PinStatusBroadcast(const QCanBusFrame& frame)
{
    // Not a broadcast
    if (!isBroadcast(frame))
        return;

    statusFlags = (StatusFlags)((frame.frameId() >> 24) & 0b1111);
    moduleAddress = (frame.frameId() >> 16);
    nodeGroupIndex = frame.frameId();

    uint64_t* data = (uint64_t*)frame.payload().data();
    uint16_t tempCurrent = ((*data) >> 48);
    current = (float)tempCurrent / 100.0f;
    uint16_t tempVoltage = (uint16_t)((*data) >> 32);
    voltage = (float)tempVoltage / 100.0f;
    value = *((float*)data);
}

bool PinStatusBroadcast::isBroadcast(const QCanBusFrame& frame)
{
    return (frame.frameId() & ((uint32_t)1 << 28));
}


QCanBusFrame PinStatusBroadcast::getFrame()
{
    QCanBusFrame frame;

    quint32 id = 0;
    id |= ((uint32_t)1 << 28); // Broadcast Flag
    id |= ((uint32_t)(statusFlags & 0b1111) << 24);
    id |= ((uint32_t)moduleAddress << 16);
    id |= nodeGroupIndex;
    frame.setFrameId(id);

    uint64_t* data = (uint64_t*)frame.payload().data();
    *data = 0;

    uint16_t tempCurrent = (uint16_t)(current * 100.0f);
    *data |= (uint64_t)tempCurrent << 48;

    uint16_t tempVoltage = (uint16_t)(voltage * 100.0f);
    *data |= (uint64_t)tempVoltage << 32;

    uint32_t* tempValue = (uint32_t*)&value;
    *data |= *tempValue;

    return frame;
}
