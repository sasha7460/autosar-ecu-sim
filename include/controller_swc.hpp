// File: include/controller_swc.hpp
#pragma once
#include "message_queue.hpp"
#include "sensor_swc.hpp"
void controllerApp(MessageQueue<SensorData>& queue, float warningThreshold, int periodMs);
