#include "rte_controller_swc.hpp"
#include "shared_types.hpp"
#include <iostream>

void runControllerSWC() {
    SensorData data;
    Rte_Read_ControllerInput(&data);

    if (data.temperature > 50.0f) {
        std::cout << "[Controller] High temperature detected!" << std::endl;
    }
}