
// File: src/controller_swc.cpp
#include "../include/controller_swc.hpp"
#include <iostream>
#include<fstream>
#include<thread>
#include <chrono>

void controllerApp(MessageQueue<SensorData>& queue, float warningThreshold, int periodMs) {
    float lastTemp =-1.0f;
    while(true){
        SensorData data = queue.receive();

        if (data.temperature != lastTemp) {
            std::ofstream logfile("controller_log.txt", std::ios::app);
            std::cout << "[Controller] Temp = " << data.temperature << ", Pressure = " << data.pressure;
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
        lastTemp = data.temperature;
        std::this_thread::sleep_for(std::chrono::milliseconds(periodMs));
    }
}

