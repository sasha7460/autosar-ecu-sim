// File: src/sensor_swc.cpp
#include "../include/sensor_swc.hpp"
#include <iostream>
#include<fstream>
//#include <thread>
// #include <chrono>

void runSensorSWC(SharedMemory& shm, float startTemp, float tempStep) {
    static int i = 0;
    SensorData data;
    data.temperature = startTemp + i * tempStep;
    data.pressure = 1.0f + (i * 0.1f);
    shm.writeData(data);

    std::ofstream logfile("sensor_log.txt", std::ios::app);
    std::cout << "Sensor SWC: Temp = " << data.temperature << ", Pressure = " << data.pressure << std::endl;
    if (logfile.is_open()) {
        logfile << "Temp = " << data.temperature << ", Pressure = " << data.pressure << std::endl;
    }
    ++i;
}

