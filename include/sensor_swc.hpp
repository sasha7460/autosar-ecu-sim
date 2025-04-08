// File: include/sensor_swc.hpp
#pragma once
#include "message_queue.hpp"
struct SensorData {
    float temperature;
    float pressure;
};
void sensorApp(MessageQueue<SensorData>& queue,float startTemp, float tempStep, int periodMs);
