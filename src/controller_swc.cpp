
// File: src/controller_swc.cpp
#include "../include/controller_swc.hpp"
#include <iostream>
#include<fstream>

void runControllerSWC(SharedMemory& shm, float lastTemperature, float warningThreshold) {
    SensorData data = shm.readData();

    if (data.temperature != lastTemperature) {
        std::ofstream logfile("controller_log.txt", std::ios::app);
        std::cout << "Controller SWC (Event Triggered): Temp = " << data.temperature << ", Pressure = " << data.pressure;
        if (logfile.is_open()) {
            logfile << "Temp = " << data.temperature << ", Pressure = " << data.pressure;
        }

        if (data.temperature > warningThreshold) {
            std::cout << " [WARNING: High Temp!]";
            if (logfile.is_open()) {
                logfile << " [WARNING: High Temp!]";
            }
        }
        std::cout << std::endl;
        if (logfile.is_open()) {
            logfile << std::endl;
        }
    }
}

