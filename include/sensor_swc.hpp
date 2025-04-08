// File: include/sensor_swc.hpp
#pragma once
#include "shared_memory.hpp"
void sensorApp(SharedMemory& shm, float startTemp, float tempStep, int periodMs);
