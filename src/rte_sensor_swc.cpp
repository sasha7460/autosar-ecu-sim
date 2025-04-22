#include "rte_sensor_swc.hpp"
#include <iostream>

static SensorData latestSensorData = {20.0f, 1.0f};

void Rte_Read_SensorInput(SensorData* data) {
    *data = latestSensorData;
}

void Rte_Write_SensorOutput(const SensorData* data) {
    latestSensorData = *data;
    std::cout << "[RTE] Sensor Output - Temp: " << data->temperature << ", Pressure: " << data->pressure << std::endl;
}
