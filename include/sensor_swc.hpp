// File: include/sensor_swc.hpp
#pragma once
#include "message_queue.hpp"
#include "sensor_types.hpp"
void sensorApp(MessageQueue<SensorData>& queue,float startTemp, float tempStep, int periodMs);
