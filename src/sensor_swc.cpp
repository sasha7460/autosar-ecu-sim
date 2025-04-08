// File: src/sensor_swc.cpp
#include "../include/sensor_swc.hpp"
#include <iostream>
#include<fstream>
#include <thread>
#include <chrono>

void sensorApp(MessageQueue<SensorData>& queue, float startTemp, float tempStep, int periodMs) {
    int i = 0;
    while(true){
        SensorData data;
        data.temperature = startTemp + i * tempStep;
        data.pressure = 1.0f + (i * 0.1f);
        queue.send(data);

        std::ofstream logfile("sensor_log.txt", std::ios::app);
        std::cout<<"[Sensor] Temp = "<<data.temperature<<", Pressure = "<<data.pressure << std::endl;
        if(logfile.is_open()){
            logfile<<"Temp = "<<data.temperature<<", Pressure = "<<data.pressure<<std::endl;  
        }     
        ++i;
        std::this_thread::sleep_for(std::chrono::milliseconds(periodMs));
    }
}

