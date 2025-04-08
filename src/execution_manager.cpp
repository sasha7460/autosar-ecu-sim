//File: src/execution_manager.cpp
#include"../include/execution_manager.hpp"
#include "../include/sensor_swc.hpp"
#include "../include/controller_swc.hpp"
#include <nlohmann/json.hpp>
#include<fstream>
#include<thread>

using json=nlohmann::json;

void runExecutionManager(){
    std::ifstream configFile("config.json");
    if(!configFile.is_open()){
        std::cerr<<"Failed to open config.json"<<std::endl;
        return;
    }
    json config;
    configFile>>config;

    float startTemp= config["sensor"]["startTemp"];
    float tempStep= config["sensor"]["tempStep"];
    float warningThreshold= config["controller"]["warningThreshold"];
    int sensorPeriod= config["sensor"]["periodMs"];
    int controllerPeriod= config["controller"]["periodMs"];
    
    SharedMemory shm;

    std::thread sensorThread(sensorApp, std::ref(shm), startTemp, tempStep, sensorPeriod);
    std::thread controllerThread(controllerApp, std::ref(shm), warningThreshold, controllerPeriod);

    sensorThread.join();
    controllerThread.join();
}